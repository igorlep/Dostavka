//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "DataModule.h"
#include "Main.h"
#include "UniversalReferenceBook.h"
#include "StatForm.h"
#include "SomeFunctions.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "SmrtPanel"
#pragma link "ToolEdit"
#pragma link "FIBDataSet"
#pragma link "frxClass"
#pragma link "frxDBSet"
#pragma link "frxExportXLS"
#pragma link "pFIBDataSet"
#pragma link "Placemnt"
#pragma link "RzPanel"
#pragma link "RzRadGrp"
#pragma resource "*.dfm"
//TExpensesListOnAutoForm *ExpensesListOnAutoForm;
//---------------------------------------------------------------------------
__fastcall TExpensesListOnAutoForm1::TExpensesListOnAutoForm1(TComponent* Owner)
        : TForm(Owner)
{
TIniFile* ini;
AnsiString sql;

  workDir=ExtractFilePath(Application->ExeName);
  FormStorage->IniFileName=workDir+"AccountGSM.ini";
  FormStorage->IniSection="ExpensesListOnAutoForm1";

  ini=new TIniFile(workDir+"AccountGSM.ini");
  Date1Edit->Date=ini->ReadDate("ExpensesListOnAutoForm1","Date1",Date());
  Date2Edit->Date=ini->ReadDate("ExpensesListOnAutoForm1","Date2",Date());
  delete ini;
  try
  {
    autoID=new TStringList();
  }
  catch (Exception &exc)
  { MessageDlg("?????? ???????? ??????? TStringList\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
    autoID=NULL;
    return;
  }
  autoNumberEdit->Items->Clear();
//  autoNumberEdit->Items->Add("?? ???? ???");
//  autoID->Add("0");
  TpFIBDataSet *rDS=GSM_DM->RDS;
  rDS->Close();
  rDS->SQLs->SelectSQL->Clear();
  if (GSM_DM->UserRole=="?????????????" || GSM_DM->UserRole=="????????????"){
  sql="select distinct DESCRIPTION as SD_NAME from OPS_TABLE where REC_TYPE=1 and VISIBLE = 1 UNION select distinct DESCRIPTION as SD_NAME from KASSA_TABLE where REC_TYPE=1 and VISIBLE = 1 ";
  }
  else
  {
  sql="select distinct DESCRIPTION as SD_NAME from OPS_TABLE where REC_TYPE=1 and VISIBLE = 1 and DESCRIPTION IN (" + MainForm->IndexOps +") UNION select distinct DESCRIPTION as SD_NAME from KASSA_TABLE where REC_TYPE=1 and VISIBLE = 1 and DESCRIPTION IN (" + MainForm->IndexOps +")";
  }
  rDS->SQLs->SelectSQL->Add(sql);
  try
  {
    rDS->Open();
  }
  catch (Exception &exc)
  { MessageDlg("?????? - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
    return;
  }
  rDS->First();
  while(!rDS->Eof)
  {
    AnsiString sdName=rDS->FieldByName("SD_NAME")->AsString;
    autoNumberEdit->Items->Add(sdName);
    autoID->Add(rDS->FieldByName("SD_NAME")->AsString);
    rDS->Next();
  }
  rDS->Close();
  autoNumberEdit->ItemIndex=0;
}
//---------------------------------------------------------------------------
void __fastcall TExpensesListOnAutoForm1::FormDestroy(TObject *Sender)
{
TIniFile* ini;

  ini=new TIniFile(workDir+"AccountGSM.ini");
  ini->WriteDate("ExpensesListOnAutoForm","Date1",Date1Edit->Date);
  ini->WriteDate("ExpensesListOnAutoForm","Date2",Date2Edit->Date);
  delete ini;
  if(autoID!=NULL) delete autoID;
}
//---------------------------------------------------------------------------
void __fastcall TExpensesListOnAutoForm1::FormShow(TObject *Sender)
{
  autoNumberEdit->SetFocus();
}

void __fastcall TExpensesListOnAutoForm1::SaveButtonClick(TObject *Sender)
{
AnsiString sql,fo;
AnsiString Folder=getWorkDir()+"OUT\\";
int nspost=10;
int nskassa=24;

if(Date1Edit->Date>Date2Edit->Date){
MessageDlg("??????? ??????? ???? ?????? ? ????? ???????. ?????? ???????????!!! ",mtWarning,TMsgDlgButtons() << mbOK,0);
return;
}

if(Date2Edit->Date<Date1Edit->Date){
MessageDlg("??????? ??????? ???? ?????? ? ????? ???????. ?????? ???????????!!! ",mtWarning,TMsgDlgButtons() << mbOK,0);
return;
}

sql="";
int index = autoNumberEdit->ItemIndex;

    DS->Close();
    DS->SQLs->SelectSQL->Clear();
    sql="select distinct ";
    sql+="expenses_table.sd_id as kp, expenses_table.driver_id as indexops, ops_table.description ";
    sql+="from ops_table ";
    sql+="left outer join expenses_table on (ops_table.id = expenses_table.driver_id) ";
    sql+="left outer join oper_table on (expenses_table.gsm_id = oper_table.id) ";
    sql+="where ( ";
    sql+="ops_table.description = '" +autoID->Strings[index] + " ' ";
    sql+=" and ops_table.visible = 1";
    sql+=" and oper_table.visible = 1";
    if (GSM_DM->UserRole!="?????????????" && GSM_DM->UserRole!="????????????") sql+=" and expenses_table.u_id="+IntToStr(GSM_DM->UserID);
    sql+=" and expenses_table.flag = 1";
    sql+=" and expenses_table.exp_date between '"+Date1Edit->Date.DateString()+"'";
    sql+=" and '"+Date2Edit->Date.DateString()+"')";
    DS->SQLs->SelectSQL->Add(sql);
    try
    {
      DS->Open();
    }
        catch (Exception &exc)
    { MessageDlg("?????? - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      return;
    }

sql="";

    DS1->Close();
    DS1->SQLs->SelectSQL->Clear();
    sql="select distinct ";
    sql+="expenses_table.sd_id as kp, expenses_table.driver_id as indexops, kassa_table.description ";
    sql+="from kassa_table ";
    sql+="left outer join expenses_table on (kassa_table.id = expenses_table.driver_id) ";
    sql+="left outer join oper_table on (expenses_table.gsm_id = oper_table.id) ";
    sql+="where ( ";
    sql+="kassa_table.description = '" +autoID->Strings[index] + " ' ";
    sql+=" and kassa_table.visible = 1";
    if (GSM_DM->UserRole!="?????????????" && GSM_DM->UserRole!="????????????" && GSM_DM->UserRole!="?????????") sql+=" and expenses_table.u_id="+IntToStr(GSM_DM->UserID);
    sql+=" and oper_table.visible = 1";
    sql+=" and expenses_table.flag = 0";
    sql+=" and expenses_table.exp_date between '"+Date1Edit->Date.DateString()+"'";
    sql+=" and '"+Date2Edit->Date.DateString()+"')";
    DS1->SQLs->SelectSQL->Add(sql);
    try
    {
      DS1->Open();
    }
        catch (Exception &exc)
    {
      MessageDlg("?????? - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      return;
    }

if (DS->RecordCount == 0 && DS1->RecordCount == 0)
{
MessageDlg("??? ??????. ???????????? ??????? ????????!!! ",mtWarning,TMsgDlgButtons() << mbOK,0);
return;
}else
{
    fo=createstatFile(autoNumberEdit->Text,Date1Edit->Date,Date2Edit->Date);
    // ??????????
    DS->First();
    while (!DS->Eof)
    {
    // ??????
    sql="";
    DS2->Close();
    DS2->SQLs->SelectSQL->Clear();
    sql="select distinct ";
    sql+="sum (expenses_table.kol) as kol_sum, sum(expenses_table.expense) as exp_sum, ops_table.description ";
    sql+="from ops_table ";
    sql+="left outer join expenses_table on (ops_table.id = expenses_table.sd_id) ";
    sql+="left outer join oper_table on (expenses_table.gsm_id = oper_table.id) ";
    sql+="where ( ";
    sql+="ops_table.id = " + IntToStr(DS->FieldByName("KP")->AsInteger);
    sql+=" and ops_table.visible = 1";
    sql+=" and oper_table.visible = 1";
    if (GSM_DM->UserRole!="?????????????" && GSM_DM->UserRole!="????????????") sql+=" and expenses_table.u_id="+IntToStr(GSM_DM->UserID);
    sql+=" and oper_table.id = 35";
    sql+=" and expenses_table.flag = 1";
    sql+=" and expenses_table.exp_date between '"+Date1Edit->Date.DateString()+"'";
    sql+=" and '"+Date2Edit->Date.DateString()+"')";
    sql+=" and expenses_table.driver_id = " +IntToStr(DS->FieldByName("INDEXOPS")->AsInteger);
    sql+=" group by ops_table.description";
    DS2->SQLs->SelectSQL->Add(sql);
    try
    {
      DS2->Open();
    }
    catch (Exception &exc)
    { MessageDlg("?????? - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      return;
    }
    // ??? ???
    sql="";
    DS3->Close();
    DS3->SQLs->SelectSQL->Clear();
    sql="select distinct ";
    sql+="sum (expenses_table.kol) as kol_sum, sum(expenses_table.expense) as exp_sum, ops_table.description ";
    sql+="from ops_table ";
    sql+="left outer join expenses_table on (ops_table.id = expenses_table.sd_id) ";
    sql+="left outer join oper_table on (expenses_table.gsm_id = oper_table.id) ";
    sql+="where ( ";
    sql+="ops_table.id = " + IntToStr(DS->FieldByName("KP")->AsInteger);
    sql+=" and ops_table.visible = 1";
    if (GSM_DM->UserRole!="?????????????" && GSM_DM->UserRole!="????????????") sql+=" and expenses_table.u_id="+IntToStr(GSM_DM->UserID);
    sql+=" and oper_table.visible = 1";
    sql+=" and oper_table.id = 36";
    sql+=" and expenses_table.flag = 1";
    sql+=" and expenses_table.exp_date between '"+Date1Edit->Date.DateString()+"'";
    sql+=" and '"+Date2Edit->Date.DateString()+"')";
    sql+=" and expenses_table.driver_id = " +IntToStr(DS->FieldByName("INDEXOPS")->AsInteger);
    sql+=" group by ops_table.description";
   DS3->SQLs->SelectSQL->Add(sql);
    try
    {
      DS3->Open();
    }
    catch (Exception &exc)
    { MessageDlg("?????? - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      return;
    }
    // ??? ???
    sql="";
    DS4->Close();
    DS4->SQLs->SelectSQL->Clear();
    sql="select distinct ";
    sql+="sum (expenses_table.kol) as kol_sum, sum(expenses_table.expense) as exp_sum, ops_table.description ";
    sql+="from ops_table ";
    sql+="left outer join expenses_table on (ops_table.id = expenses_table.sd_id) ";
    sql+="left outer join oper_table on (expenses_table.gsm_id = oper_table.id) ";
    sql+="where ( ";
    sql+="ops_table.id = " + IntToStr(DS->FieldByName("KP")->AsInteger);
    sql+=" and ops_table.visible = 1";
    sql+=" and oper_table.visible = 1";
    if (GSM_DM->UserRole!="?????????????" && GSM_DM->UserRole!="????????????") sql+=" and expenses_table.u_id="+IntToStr(GSM_DM->UserID);
    sql+=" and oper_table.id = 37";
    sql+=" and expenses_table.flag = 1";
    sql+=" and expenses_table.exp_date between '"+Date1Edit->Date.DateString()+"'";
    sql+=" and '"+Date2Edit->Date.DateString()+"')";
    sql+=" and expenses_table.driver_id = " +IntToStr(DS->FieldByName("INDEXOPS")->AsInteger);
    sql+=" group by ops_table.description";
    DS4->SQLs->SelectSQL->Add(sql);
    try
    {
      DS4->Open();
    }
    catch (Exception &exc)
    { MessageDlg("?????? - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      return;
    }

    // ??????
    sql="";
    DS5->Close();
    DS5->SQLs->SelectSQL->Clear();
    sql="select distinct ";
    sql+="sum (expenses_table.kol) as kol_sum, sum(expenses_table.expense) as exp_sum, ops_table.description ";
    sql+="from ops_table ";
    sql+="left outer join expenses_table on (ops_table.id = expenses_table.sd_id) ";
    sql+="left outer join oper_table on (expenses_table.gsm_id = oper_table.id) ";
    sql+="where ( ";
    sql+="ops_table.id = " + IntToStr(DS->FieldByName("KP")->AsInteger);
    sql+=" and ops_table.visible = 1";
    if (GSM_DM->UserRole!="?????????????" && GSM_DM->UserRole!="????????????") sql+=" and expenses_table.u_id="+IntToStr(GSM_DM->UserID);
    sql+=" and oper_table.visible = 1";
    sql+=" and oper_table.file_id = 33";
    sql+=" and expenses_table.flag = 1";
    sql+=" and expenses_table.exp_date between '"+Date1Edit->Date.DateString()+"'";
    sql+=" and '"+Date2Edit->Date.DateString()+"')";
    sql+=" and expenses_table.driver_id = " +IntToStr(DS->FieldByName("INDEXOPS")->AsInteger);
    sql+=" group by ops_table.description";
    DS5->SQLs->SelectSQL->Add(sql);
    try
    {
      DS5->Open();
    }
    catch (Exception &exc)
    { MessageDlg("?????? - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      return;
    }

    // ??????????
    sql="";
    DS6->Close();
    DS6->SQLs->SelectSQL->Clear();
    sql="select distinct ";
    sql+="sum (expenses_table.kol) as kol_sum, sum(expenses_table.expense) as exp_sum, ops_table.description ";
    sql+="from ops_table ";
    sql+="left outer join expenses_table on (ops_table.id = expenses_table.sd_id) ";
    sql+="left outer join oper_table on (expenses_table.gsm_id = oper_table.id) ";
    sql+="where ( ";
    sql+="ops_table.id = " + IntToStr(DS->FieldByName("KP")->AsInteger);
    sql+=" and ops_table.visible = 1";
    if (GSM_DM->UserRole!="?????????????" && GSM_DM->UserRole!="????????????") sql+=" and expenses_table.u_id="+IntToStr(GSM_DM->UserID);
    sql+=" and oper_table.visible = 1";
    sql+=" and oper_table.id = 39";
    sql+=" and expenses_table.flag = 1";
    sql+=" and expenses_table.exp_date between '"+Date1Edit->Date.DateString()+"'";
    sql+=" and '"+Date2Edit->Date.DateString()+"')";
    sql+=" and expenses_table.driver_id = " +IntToStr(DS->FieldByName("INDEXOPS")->AsInteger);
    sql+=" group by ops_table.description";
    DS6->SQLs->SelectSQL->Add(sql);
    try
    {
      DS6->Open();
    }
    catch (Exception &exc)
    { MessageDlg("?????? - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      return;
    }

    // c?????? ?????
    sql="";
    DS7->Close();
    DS7->SQLs->SelectSQL->Clear();
    sql="select distinct ";
    sql+="sum (expenses_table.kol) as kol_sum, sum(expenses_table.expense) as exp_sum, ops_table.description ";
    sql+="from ops_table ";
    sql+="left outer join expenses_table on (ops_table.id = expenses_table.sd_id) ";
    sql+="left outer join oper_table on (expenses_table.gsm_id = oper_table.id) ";
    sql+="where ( ";
    sql+="ops_table.id = " + IntToStr(DS->FieldByName("KP")->AsInteger);
    sql+=" and ops_table.visible = 1";
    if (GSM_DM->UserRole!="?????????????" && GSM_DM->UserRole!="????????????") sql+=" and expenses_table.u_id="+IntToStr(GSM_DM->UserID);
    sql+=" and oper_table.visible = 1";
    sql+=" and oper_table.id = 44";
    sql+=" and expenses_table.flag = 1";
    sql+=" and expenses_table.exp_date between '"+Date1Edit->Date.DateString()+"'";
    sql+=" and '"+Date2Edit->Date.DateString()+"')";
    sql+=" and expenses_table.driver_id = " +IntToStr(DS->FieldByName("INDEXOPS")->AsInteger);
    sql+=" group by ops_table.description";
    DS7->SQLs->SelectSQL->Add(sql);
    try
    {
      DS7->Open();
    }
    catch (Exception &exc)
    {
      MessageDlg("?????? - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      return;
    }


    editstatFile(DS2,DS3,DS4,DS5,DS6,DS7,fo,nspost);
    nspost++;
    DS->Next();
    }
    // ?????
    DS1->First();
    while (!DS1->Eof)
    {
    // ??????
    sql="";
    DS2->Close();
    DS2->SQLs->SelectSQL->Clear();
    sql="select distinct ";
    sql+="sum (expenses_table.kol) as kol_sum, sum(expenses_table.expense) as exp_sum, kassa_table.description ";
    sql+="from kassa_table ";
    sql+="left outer join expenses_table on (kassa_table.id = expenses_table.sd_id) ";
    sql+="left outer join oper_table on (expenses_table.gsm_id = oper_table.id) ";
    sql+="where ( ";
    sql+="kassa_table.id = " + IntToStr(DS1->FieldByName("KP")->AsInteger);
    sql+=" and kassa_table.visible = 1";
//    if (GSM_DM->UserRole!="?????????????" && GSM_DM->UserRole!="????????????") sql+=" and expenses_table.u_id="+IntToStr(GSM_DM->UserID);
    if (GSM_DM->UserRole!="?????????????" && GSM_DM->UserRole!="????????????" && GSM_DM->UserRole!="?????????") sql+=" and expenses_table.u_id="+IntToStr(GSM_DM->UserID);
    sql+=" and oper_table.visible = 1";
    sql+=" and oper_table.id = 35";
    sql+=" and expenses_table.flag = 0";
    sql+=" and expenses_table.exp_date between '"+Date1Edit->Date.DateString()+"'";
    sql+=" and '"+Date2Edit->Date.DateString()+"')";
    sql+=" and expenses_table.driver_id = " +IntToStr(DS1->FieldByName("INDEXOPS")->AsInteger);
    sql+=" group by kassa_table.description";
    DS2->SQLs->SelectSQL->Add(sql);
    try
    {
      DS2->Open();
    }
    catch (Exception &exc)
    { MessageDlg("?????? - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      return;
    }
    // ??? ???
    sql="";
    DS3->Close();
    DS3->SQLs->SelectSQL->Clear();
    sql="select distinct ";
    sql+="sum (expenses_table.kol) as kol_sum, sum(expenses_table.expense) as exp_sum, kassa_table.description ";
    sql+="from kassa_table ";
    sql+="left outer join expenses_table on (kassa_table.id = expenses_table.sd_id) ";
    sql+="left outer join oper_table on (expenses_table.gsm_id = oper_table.id) ";
    sql+="where ( ";
    sql+="kassa_table.id = " + IntToStr(DS1->FieldByName("KP")->AsInteger);
    sql+=" and kassa_table.visible = 1";
//    if (GSM_DM->UserRole!="?????????????" && GSM_DM->UserRole!="????????????") sql+=" and expenses_table.u_id="+IntToStr(GSM_DM->UserID);
    if (GSM_DM->UserRole!="?????????????" && GSM_DM->UserRole!="????????????" && GSM_DM->UserRole!="?????????") sql+=" and expenses_table.u_id="+IntToStr(GSM_DM->UserID);
    sql+=" and oper_table.visible = 1";
    sql+=" and oper_table.id = 36";
    sql+=" and expenses_table.flag = 0";
    sql+=" and expenses_table.exp_date between '"+Date1Edit->Date.DateString()+"'";
    sql+=" and '"+Date2Edit->Date.DateString()+"')";
    sql+=" and expenses_table.driver_id = " +IntToStr(DS1->FieldByName("INDEXOPS")->AsInteger);
    sql+=" group by kassa_table.description";
    DS3->SQLs->SelectSQL->Add(sql);
    try
    {
      DS3->Open();
    }
    catch (Exception &exc)
    { MessageDlg("?????? - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      return;
    }
    // ??? ???
    sql="";
    DS4->Close();
    DS4->SQLs->SelectSQL->Clear();
    sql="select distinct ";
    sql+="sum (expenses_table.kol) as kol_sum, sum(expenses_table.expense) as exp_sum, kassa_table.description ";
    sql+="from kassa_table ";
    sql+="left outer join expenses_table on (kassa_table.id = expenses_table.sd_id) ";
    sql+="left outer join oper_table on (expenses_table.gsm_id = oper_table.id) ";
    sql+="where ( ";
    sql+="kassa_table.id = " + IntToStr(DS1->FieldByName("KP")->AsInteger);
    sql+=" and kassa_table.visible = 1";
//    if (GSM_DM->UserRole!="?????????????" && GSM_DM->UserRole!="????????????") sql+=" and expenses_table.u_id="+IntToStr(GSM_DM->UserID);
    if (GSM_DM->UserRole!="?????????????" && GSM_DM->UserRole!="????????????" && GSM_DM->UserRole!="?????????") sql+=" and expenses_table.u_id="+IntToStr(GSM_DM->UserID);
    sql+=" and oper_table.visible = 1";
    sql+=" and oper_table.id = 37";
    sql+=" and expenses_table.flag = 0";
    sql+=" and expenses_table.exp_date between '"+Date1Edit->Date.DateString()+"'";
    sql+=" and '"+Date2Edit->Date.DateString()+"')";
    sql+=" and expenses_table.driver_id = " +IntToStr(DS1->FieldByName("INDEXOPS")->AsInteger);
    sql+=" group by kassa_table.description";
    DS4->SQLs->SelectSQL->Add(sql);
    try
    {
      DS4->Open();
    }
    catch (Exception &exc)
    { MessageDlg("?????? - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      return;
    }

    // ??????
    sql="";
    DS5->Close();
    DS5->SQLs->SelectSQL->Clear();
    sql="select distinct ";
    sql+="sum (expenses_table.kol) as kol_sum, sum(expenses_table.expense) as exp_sum, kassa_table.description ";
    sql+="from kassa_table ";
    sql+="left outer join expenses_table on (kassa_table.id = expenses_table.sd_id) ";
    sql+="left outer join oper_table on (expenses_table.gsm_id = oper_table.id) ";
    sql+="where ( ";
    sql+="kassa_table.id = " + IntToStr(DS1->FieldByName("KP")->AsInteger);
    sql+=" and kassa_table.visible = 1";
//    if (GSM_DM->UserRole!="?????????????" && GSM_DM->UserRole!="????????????") sql+=" and expenses_table.u_id="+IntToStr(GSM_DM->UserID);
    if (GSM_DM->UserRole!="?????????????" && GSM_DM->UserRole!="????????????" && GSM_DM->UserRole!="?????????") sql+=" and expenses_table.u_id="+IntToStr(GSM_DM->UserID);
    sql+=" and oper_table.visible = 1";
    sql+=" and oper_table.file_id = 33";
    sql+=" and expenses_table.flag = 0";
    sql+=" and expenses_table.exp_date between '"+Date1Edit->Date.DateString()+"'";
    sql+=" and '"+Date2Edit->Date.DateString()+"')";
    sql+=" and expenses_table.driver_id = " +IntToStr(DS1->FieldByName("INDEXOPS")->AsInteger);
    sql+=" group by kassa_table.description";
    DS5->SQLs->SelectSQL->Add(sql);
    try
    {
      DS5->Open();
    }
    catch (Exception &exc)
    { MessageDlg("?????? - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      return;
    }

    // ??????????
    sql="";
    DS6->Close();
    DS6->SQLs->SelectSQL->Clear();
    sql="select distinct ";
    sql+="sum (expenses_table.kol) as kol_sum, sum(expenses_table.expense) as exp_sum, kassa_table.description ";
    sql+="from kassa_table ";
    sql+="left outer join expenses_table on (kassa_table.id = expenses_table.sd_id) ";
    sql+="left outer join oper_table on (expenses_table.gsm_id = oper_table.id) ";
    sql+="where ( ";
    sql+="kassa_table.id = " + IntToStr(DS1->FieldByName("KP")->AsInteger);
    sql+=" and kassa_table.visible = 1";
//    if (GSM_DM->UserRole!="?????????????" && GSM_DM->UserRole!="????????????") sql+=" and expenses_table.u_id="+IntToStr(GSM_DM->UserID);
    if (GSM_DM->UserRole!="?????????????" && GSM_DM->UserRole!="????????????" && GSM_DM->UserRole!="?????????") sql+=" and expenses_table.u_id="+IntToStr(GSM_DM->UserID);
    sql+=" and oper_table.visible = 1";
    sql+=" and oper_table.id = 39";
    sql+=" and expenses_table.flag = 0";
    sql+=" and expenses_table.exp_date between '"+Date1Edit->Date.DateString()+"'";
    sql+=" and '"+Date2Edit->Date.DateString()+"')";
    sql+=" and expenses_table.driver_id = " +IntToStr(DS1->FieldByName("INDEXOPS")->AsInteger);
    sql+=" group by kassa_table.description";
    DS6->SQLs->SelectSQL->Add(sql);
    try
    {
      DS6->Open();
    }
    catch (Exception &exc)
    { MessageDlg("?????? - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      return;
    }

    // ??????? ?????
    sql="";
    DS7->Close();
    DS7->SQLs->SelectSQL->Clear();
    sql="select distinct ";
    sql+="sum (expenses_table.kol) as kol_sum, sum(expenses_table.expense) as exp_sum, kassa_table.description ";
    sql+="from kassa_table ";
    sql+="left outer join expenses_table on (kassa_table.id = expenses_table.sd_id) ";
    sql+="left outer join oper_table on (expenses_table.gsm_id = oper_table.id) ";
    sql+="where ( ";
    sql+="kassa_table.id = " + IntToStr(DS1->FieldByName("KP")->AsInteger);
    sql+=" and kassa_table.visible = 1";
//    if (GSM_DM->UserRole!="?????????????" && GSM_DM->UserRole!="????????????") sql+=" and expenses_table.u_id="+IntToStr(GSM_DM->UserID);
    if (GSM_DM->UserRole!="?????????????" && GSM_DM->UserRole!="????????????" && GSM_DM->UserRole!="?????????") sql+=" and expenses_table.u_id="+IntToStr(GSM_DM->UserID);
    sql+=" and oper_table.visible = 1";
    sql+=" and oper_table.id = 44";
    sql+=" and expenses_table.flag = 0";
    sql+=" and expenses_table.exp_date between '"+Date1Edit->Date.DateString()+"'";
    sql+=" and '"+Date2Edit->Date.DateString()+"')";
    sql+=" and expenses_table.driver_id = " +IntToStr(DS1->FieldByName("INDEXOPS")->AsInteger);
    sql+=" group by kassa_table.description";
    DS7->SQLs->SelectSQL->Add(sql);
    try
    {
      DS7->Open();
    }
    catch (Exception &exc)
    { MessageDlg("?????? - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      return;
    }


    editstatFile(DS2,DS3,DS4,DS5,DS6,DS7,fo,nskassa);
    nskassa++;
    DS1->Next();
    }

nspost=nspost+1;
nskassa=nskassa+1;
//deletestatFile(fo,nspost,nskassa);
if (fo.Trim()!="F"){
ShellExecute(Handle,"open",fo.c_str(),NULL,Folder.c_str(),SW_RESTORE);
}
}

DS->Close();
DS1->Close();
DS2->Close();
DS3->Close();
DS4->Close();
DS5->Close();
DS6->Close();
DS7->Close();
}
//---------------------------------------------------------------------------

