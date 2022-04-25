//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "DataModule.h"
#include "DirectWorkExcel.h"
#include "UniversalReferenceBook.h"
#include "Main.h"
#include "LoadDataFromExcelFile.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "Placemnt"
#pragma link "JvComponent"
#pragma link "JvExControls"
#pragma link "JvExMask"
#pragma link "JvToolEdit"
#pragma link "JvXPButtons"
#pragma link "JvXPCore"
#pragma resource "*.dfm"
//TLoadDataFromExcelFileForm *LoadDataFromExcelFileForm;
//---------------------------------------------------------------------------
__fastcall TLoadDataFromExcelFileForm::TLoadDataFromExcelFileForm(TComponent* Owner,AnsiString iniFN)
        : TForm(Owner),iniFileName(iniFN)
{
  workDir=ExtractFilePath(iniFileName);
  FormStorage->IniFileName=iniFileName;
  FormStorage->IniSection="LoadDataFromExcelFileForm";
  dwe=NULL;
  sd_id="";
  filenameEdit->Text="";
  memo->Clear();
}
//---------------------------------------------------------------------------
__fastcall TLoadDataFromExcelFileForm::~TLoadDataFromExcelFileForm(void)
{
  if(dwe!=NULL){ delete dwe; dwe=NULL; }
}
//---------------------------------------------------------------------------
void __fastcall TLoadDataFromExcelFileForm::filenameEditAfterDialog(
      TObject *Sender, AnsiString &Name, bool &Action)
{
  Action=true;
  loadButton->Enabled=false;
  //������� ������ ��� ������ � Excel ������
  if(dwe!=NULL){ delete dwe; dwe=NULL; }
  try
  {
    dwe=new DirectWorkExcel(Name,1);
  }
  catch (Exception &exc)
  { MessageDlg("������ �������� ������� DirectWorkExcel\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
    return;
  }
  //��������� Excel ����
  if(dwe->openFile(true)==false) return;
  memo->Clear();
  //������ ������������ ������
  //������
  AnsiString s=dwe->getCellValue(5,"B");
  TDateTime fromDate=TDateTime(s.SubString(3,s.Pos(" �� ")-3));
  TDateTime toDate=TDateTime(s.SubString(s.Pos(" �� ")+4,s.Length()));
  s="���� �������� ������ �� ������ � "+fromDate.DateString()+" �� "+toDate.DateString();
  memo->Lines->Add(s);
  fromDateEdit->Date=fromDate;
  toDateEdit->Date=toDate;
  //�������������
  s=dwe->getCellValue(8,"B");
  TpFIBQuery *RQ=GSM_DM->RQ;
  cod_m=s.SubString(14,2);
  AnsiString sql;
  sql="select ID as SD_ID,DESCRIPTION as SD_NAME from SUBDIVISIONS_TABLE where COD_M="+cod_m;
  RQ->Close();
  RQ->SQL->Clear();
  RQ->SQL->Add(sql);
  try
  {
    RQ->ExecQuery();
  }
  catch (Exception &exc)
  { MessageDlg("������ - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
    return;
  }
  sd_id=RQ->FieldByName("SD_ID")->AsString;
  sd_name=RQ->FieldByName("SD_NAME")->AsString;
  s="������������� - "+sd_name;
  RQ->Close();
  memo->Lines->Add(s);
  if(sd_id.IsEmpty()) return;
  //������������ ���������� ����
  cardNumberBox->Clear();
  cardNumberBox->Items->Add("��� �����");
  int rn=9,rc=0;
  s=dwe->getCellValue(rn,"B");
  while(s.Pos("����� �� ������ ����:")==0 && rn<65535)
  { if(s.Pos("�����: ")>0)
    { cardNumberBox->Items->Add((s.SubString(7,s.Length())).Trim());
      rc++;
    }
    rn++;
    s=dwe->getCellValue(rn,"B");
  }
  s="���������� ���� - "+IntToStr(rc);
  memo->Lines->Add(s);
  cardNumberBox->ItemIndex=0;
  if(rc==0) return;
  loadButton->Enabled=true;
}
//---------------------------------------------------------------------------
//�������� ������
void __fastcall TLoadDataFromExcelFileForm::loadButtonClick(
      TObject *Sender)
{
AnsiString sql,s;
TpFIBQuery *RQ=GSM_DM->RQ;
TpFIBTransaction *WT=GSM_DM->writeTransaction;
TDateTime dt1=fromDateEdit->Date;
TDateTime dt2=toDateEdit->Date;
AnsiString cardNumber="";
AnsiString card_id="";

  if(cardNumberBox->ItemIndex > 0)
  { cardNumber=cardNumberBox->Text;
    RQ->Close();
    RQ->SQL->Clear();
    sql="select ID as CARD_ID from ELECTRONIC_CARDS_TABLE where";
    sql+=" DESCRIPTION='"+cardNumber+"'";
    RQ->SQL->Add(sql);
    try
    {
      RQ->ExecQuery();
    }
    catch (Exception &exc)
    { MessageDlg("������ - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      return;
    }
    card_id=RQ->FieldByName("CARD_ID")->AsString;
  }
  //��������� ������� �� � ������� �������� ������ �� �������������
  //�� ��������� ������ ��� ��������� �����
  RQ->Close();
  RQ->SQL->Clear();
  sql="select count(ID) as COUNT_ID from EXPENSES_TABLE where";
  sql+=" SD_ID="+sd_id;
  sql+=" and EXP_DATE>='"+dt1.DateString()+"'";
  sql+=" and EXP_DATE<='"+dt2.DateString()+"'";
  if(!card_id.IsEmpty()) sql+=" and EC_ID="+card_id;
  RQ->SQL->Add(sql);
  try
  {
    RQ->ExecQuery();
  }
  catch (Exception &exc)
  { MessageDlg("������ - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
    return;
  }
  AnsiString count_id=RQ->FieldByName("COUNT_ID")->AsInteger;
  if(count_id > 0)
  { s="��������!!! ��� ������ � ������� �������� ��� �� ";
    if(dt1==dt2) s+=dt1.DateString();
    else s+="������ � "+dt1.DateString()+" �� "+dt2.DateString();
    s+=" ��� ������������� - "+sd_name;
    if(!cardNumber.IsEmpty()) s+=" �� ����� - "+cardNumber;
    s+=" ����� ������� � �� �� ����� ����� ��������� ������ �� ���������� �����.\n���������� ��������?";
    if(MessageDlg(s,mtConfirmation,TMsgDlgButtons() << mbOK << mbCancel,0)==mrCancel)
    { RQ->Close();
      return;
    }
  }
  RQ->Close();

  memo->Lines->Add(" ");
  memo->Lines->Add("�������� �������� ������ �� �����:");
  errFLG=false;
  WQ=GSM_DM->WQ;
  //�������� ����������
  WT->StartTransaction();

  if(count_id > 0)
  { //������� ������ �� ������� EXPENSES_TABLE �� ��������� ������
    s=" - ������� ������ �� ������� �������� ��� �� ";
    if(dt1==dt2) s+=dt1.DateString();
    else s+="������ � "+dt1.DateString()+" �� "+dt2.DateString();
    s+=" ��� ������������� - "+sd_name;
    if(!cardNumber.IsEmpty()) s+=" �� ����� - "+cardNumber;
    memo->Lines->Add(s);

    WQ->Close();
    WQ->SQL->Clear();
    sql="delete from EXPENSES_TABLE where";
    sql+=" SD_ID="+sd_id;
    sql+=" and EXP_DATE>='"+dt1.DateString()+"'";
    sql+=" and EXP_DATE<='"+dt2.DateString()+"'";
    if(!card_id.IsEmpty()) sql+=" and EC_ID="+card_id;
    WQ->SQL->Add(sql);
    try
    {
      WQ->ExecQuery();
    }
    catch (Exception &exc)
    { MessageDlg("������ - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      WT->Rollback();
      memo->Lines->Add("!������ �������� ������");
      return;
    }
  }

  allRecords=0;
  allSumma=0.0;
  //������ ������ �� �����
  int rn=9;
  s=dwe->getCellValue(rn,"B");
  if(cardNumber.IsEmpty())
  { do
    { if(s.Pos("�����: ") > 0)
      { AnsiString cardNum=(s.SubString(7,s.Length())).Trim();
        memo->Lines->Add(" - ���������� ������ �� ����� - "+cardNum);
        rn=loadDataForCard(rn);
      }
      rn++;
      s=dwe->getCellValue(rn,"B");
    }while(s.Pos("����� �� ������ ����:")==0 && rn<65535);
  }
  else
  { do
    { if(s.Pos("�����: ") > 0)
      { AnsiString cardNum=(s.SubString(7,s.Length())).Trim();
        if(cardNum==cardNumber)
        { memo->Lines->Add(" - ���������� ������ �� ����� - "+cardNum);
          rn=loadDataForCard(rn);
          break;
        }
      }
      rn++;
      s=dwe->getCellValue(rn,"B");
    }while(s.Pos("����� �� ������ ����:")==0 && rn<65535);
  }
  memo->Lines->Add("����� ���������:");
  memo->Lines->Add(" - �������: "+IntToStr(allRecords));
  memo->Lines->Add(" - ������ ���: "+AnsiString().sprintf("%.2lf",allSumma));
  memo->Repaint();
  if(errFLG==false)
  { WT->Commit();
    MessageDlg("�������� ������� ���������",mtInformation,TMsgDlgButtons() << mbOK,0);
  }
  else
  { WT->Rollback();
    MessageDlg("�������� ��������� � ��������. ������ �� ��������� � ����.",mtInformation,TMsgDlgButtons() << mbOK,0);
  }
  MainForm->reloadButton->Click();
}
//---------------------------------------------------------------------------
int __fastcall TLoadDataFromExcelFileForm::loadDataForCard(int rn)
{
AnsiString sql,s;
AnsiString cardNum="",autoNum="";
AnsiString card_id="",auto_id="";
int recQuantity=0;
double sum=0.0;

  //���� ������ � ������� AUTO_TABLE
  s=dwe->getCellValue(rn,"G");
  if(s.Pos("���������:") == 0)
    memo->Lines->Add("�� ������� ������ \"���������:\"");
  else
  { autoNum=(s.SubString(11,s.Length())).Trim();
    if(autoNum.IsEmpty()) memo->Lines->Add("������ ������ ����������");
    else auto_id=getAutoID(autoNum);
  }

  //���� ������ � ������� ELECTRONIC_CARDS_TABLE
  s=dwe->getCellValue(rn,"B");
  if(s.Pos("�����:") == 0)
  { memo->Lines->Add("�� ������� ������ \"�����:\"");
    errFLG=true;
    return rn;
  }
  cardNum=(s.SubString(7,s.Length())).Trim();
  if(cardNum.IsEmpty())
  { memo->Lines->Add("������ ������ �����");
    errFLG=true;
    return rn;
  }
  card_id=getElectronicCardID(cardNum,auto_id);
  if(card_id.IsEmpty())
  { errFLG=true;
    return rn;
  }
  rn++;
  s=dwe->getCellValue(rn,"B");
  //������� ������
  while(s.Pos("����� �� �����:") == 0)
  { s=dwe->getCellValue(rn,"E");
    if(!s.IsEmpty())
    { AnsiString gsm_id="";
      AnsiString gsmName=(s.SubString(1,s.Pos("(")-1)).Trim();
      gsm_id=getGSM_ID(gsmName);
      if(!auto_id.IsEmpty() && !gsm_id.IsEmpty()) testAutoForGSM_ID(auto_id,gsm_id);

      TDateTime exp_date=0;
      s=dwe->getCellValue(rn,"G");
      if(!s.IsEmpty())
      try
      {
        exp_date=TDateTime(s);
      }
      catch (Exception &exc)
      {
        memo->Lines->Add("������ - exp_date\n"+exc.Message);
      }

      double expense=0;
      s=dwe->getCellValue(rn,"I");
      if(!s.IsEmpty())
      try
      {
        expense=-StrToFloat(s);
      }
      catch (Exception &exc)
      {
        memo->Lines->Add("������ - expense\n"+exc.Message);
      }
      //������� ������ � ������� �������� ��� - EXPENSES_TABLE
      WQ->Close();
      WQ->SQL->Clear();
      sql="insert into EXPENSES_TABLE(ID,EXP_DATE,SD_ID,EC_ID,AUTO_ID,GSM_ID,EXPENSE) values(";
      sql+="GEN_ID(GEN_EXPENSES_TABLE_ID,1),";
      sql+="'"+exp_date.DateString()+"',";
      sql+=sd_id+",";
      sql+=card_id+",";
      sql+=auto_id+",";
      sql+=gsm_id+",";
      sql+=FloatToStr(expense)+")";
      WQ->SQL->Add(sql);
      try
      {
        WQ->ExecQuery();
        sum+=expense;
        recQuantity++;
      }
      catch (Exception &exc)
      {
        memo->Lines->Add("������ - "+sql+"\n"+exc.Message);
      }
    }
    rn++;
    s=dwe->getCellValue(rn,"B");
  }
  memo->Lines->Add(" - ������ �� ����� - "+cardNum+" ���������. �������: "+IntToStr(recQuantity)+", ������ ���: "+AnsiString().sprintf("%.2lf",sum));
  allRecords+=recQuantity;
  allSumma+=sum;
  return rn;
}
//---------------------------------------------------------------------------
AnsiString __fastcall TLoadDataFromExcelFileForm::getAutoID(AnsiString autoNum)
{
AnsiString sql;
AnsiString auto_id="";

  WQ->Close();
  WQ->SQL->Clear();
  sql="select ID as AUTO_ID from AUTO_TABLE where";
  sql+=" DESCRIPTION like '"+autoNum+"'";
  WQ->SQL->Add(sql);
  try
  {
    WQ->ExecQuery();
  }
  catch (Exception &exc)
  { memo->Lines->Add("������ - "+sql+" - "+exc.Message);
    return auto_id;
  }
  auto_id=WQ->FieldByName("AUTO_ID")->AsString;
  if(auto_id.IsEmpty()) //������� ����� ������ � ������� AUTO_TABLE
  { TURB *Auto_RB=MainForm->getAuto_RB(sd_name);
    if(Auto_RB==NULL)
    { memo->Lines->Add("������ �������� ����������� �����������");
      return auto_id;
    }
    AnsiString id=Auto_RB->getNewRB_KeyValue();
    AnsiString folder_id=Auto_RB->getFolderIDByName(sd_name);
    delete Auto_RB; Auto_RB=NULL;
    if(!id.IsEmpty() && !folder_id.IsEmpty())
    { AnsiString distination_id="";
      AnsiString distination="�������� ������������";
      //���� ������ � ������� �����������
      WQ->Close();
      WQ->SQL->Clear();
      sql="select ID from DISTINATIONS_TABLE where DESCRIPTION like '%"+distination+"%'";
      WQ->SQL->Add(sql);
      try
      {
        WQ->ExecQuery();
        distination_id=WQ->FieldByName("ID")->AsString;
      }
      catch (Exception &exc)
      {
        memo->Lines->Add("������ - "+sql+" - "+exc.Message);
      }
      WQ->Close();
      WQ->SQL->Clear();
      sql="insert into AUTO_TABLE(ID,FILE_ID,REC_TYPE,DESCRIPTION,SD_ID,DISTINATION) values(";
      sql+=id+",";
      sql+=folder_id+",1,";
      sql+="'"+autoNum+"',";
      sql+=sd_id+",";
      if(!distination_id.IsEmpty()) sql+=distination_id+")";
      else sql+="NULL)";
      WQ->SQL->Add(sql);
      try
      {
       WQ->ExecQuery();
       auto_id=id;
      }
      catch(Exception &exc)
      {
        memo->Lines->Add("������ - "+sql+" - "+exc.Message);
      }
    }
  }
  return auto_id;
}
//---------------------------------------------------------------------------
void __fastcall TLoadDataFromExcelFileForm::testAutoForGSM_ID(AnsiString auto_id,AnsiString id_gsm)
{
AnsiString sql;

  WQ->Close();
  WQ->SQL->Clear();
  sql="select GSM_ID from AUTO_TABLE where ID="+auto_id;
  WQ->SQL->Add(sql);
  try
  {
    WQ->ExecQuery();
  }
  catch (Exception &exc)
  {
    return;
  }
  AnsiString gsm_id=WQ->FieldByName("GSM_ID")->AsString;
  if(gsm_id.IsEmpty())
  { WQ->Close();
    WQ->SQL->Clear();
    sql="update AUTO_TABLE set GSM_ID="+id_gsm+" where ID="+auto_id;
    WQ->SQL->Add(sql);
    try
    {
     WQ->ExecQuery();
    }
    catch(...){}
  }
}
//---------------------------------------------------------------------------
AnsiString __fastcall TLoadDataFromExcelFileForm::getElectronicCardID(AnsiString cardNum,AnsiString auto_id)
{
AnsiString sql;
AnsiString card_id="";

  WQ->Close();
  WQ->SQL->Clear();
  sql="select ID as CARD_ID from ELECTRONIC_CARDS_TABLE where";
  sql+=" DESCRIPTION='"+cardNum+"'";
  WQ->SQL->Add(sql);
  try
  {
    WQ->ExecQuery();
  }
  catch (Exception &exc)
  { memo->Lines->Add("������ - "+sql+" - "+exc.Message);
    return card_id;
  }
  card_id=WQ->FieldByName("CARD_ID")->AsString;
  if(card_id.IsEmpty()) //������� ����� ������
  { TURB *EC_RB=MainForm->getElectronicCards_RB(sd_name);
    if(EC_RB==NULL)
    { memo->Lines->Add("������ �������� ����������� ����������� ����");
      return card_id;
    }
    AnsiString id=EC_RB->getNewRB_KeyValue();
    AnsiString folder_id=EC_RB->getFolderIDByName(sd_name);
    delete EC_RB; EC_RB=NULL;
    if(!id.IsEmpty() && !folder_id.IsEmpty())
    { WQ->Close();
      WQ->SQL->Clear();
      sql="insert into ELECTRONIC_CARDS_TABLE(ID,FILE_ID,REC_TYPE,DESCRIPTION,SD_ID,AUTO_ID) values(";
      sql+=id+",";
      sql+=folder_id+",1,";
      sql+="'"+cardNum+"',";
      sql+=sd_id+",";
      if(!auto_id.IsEmpty()) sql+=auto_id+")";
      else sql+="NULL)";
      WQ->SQL->Add(sql);
      try
      {
        WQ->ExecQuery();
        card_id=id;
      }
      catch (Exception &exc)
      {
        memo->Lines->Add("������ - "+sql+"\n"+exc.Message);
      }
    }
  }
  return card_id;
}
//---------------------------------------------------------------------------
AnsiString __fastcall TLoadDataFromExcelFileForm::getGSM_ID(AnsiString gsmName)
{
AnsiString sql;
AnsiString gsm_id="";

  WQ->Close();
  WQ->SQL->Clear();
  sql="select ID as GSM_ID from GSM_TABLE where";
  sql+=" DESCRIPTION='"+gsmName+"'";
  WQ->SQL->Add(sql);
  try
  {
    WQ->ExecQuery();
  }
  catch (Exception &exc)
  { memo->Lines->Add("������ - "+sql+" - "+exc.Message);
    return gsm_id;
  }
  gsm_id=WQ->FieldByName("GSM_ID")->AsString;
  if(gsm_id.IsEmpty()) //������� ����� ������
  { TURB *GSM_RB=MainForm->getGSM_RB();
    if(GSM_RB==NULL)
    { memo->Lines->Add("������ �������� ����������� ���");
      return gsm_id;
    }
    AnsiString id=GSM_RB->getNewRB_KeyValue();
    AnsiString root_id=GSM_RB->getRootSectionID();
    delete GSM_RB; GSM_RB=NULL;
    if(!id.IsEmpty() && !root_id.IsEmpty())
    { WQ->Close();
      WQ->SQL->Clear();
      sql="insert into GSM_TABLE(ID,FILE_ID,REC_TYPE,DESCRIPTION) values(";
      sql+=id+",";
      sql+=root_id+",1,";
      sql+="'"+gsmName+"')";
      WQ->SQL->Add(sql);
      try
      {
        WQ->ExecQuery();
        gsm_id=id;
      }
      catch (Exception &exc)
      {
        memo->Lines->Add("������ - "+sql+"\n"+exc.Message);
      }
    }
  }
  return gsm_id;
}
//---------------------------------------------------------------------------

