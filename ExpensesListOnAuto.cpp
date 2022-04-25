//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "DataModule.h"
#include "Main.h"
#include "UniversalReferenceBook.h"
#include "ExpensesListOnAuto.h"
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
__fastcall TExpensesListOnAutoForm::TExpensesListOnAutoForm(TComponent* Owner)
        : TForm(Owner)
{
TIniFile* ini;


  workDir=ExtractFilePath(Application->ExeName);
  FormStorage->IniFileName=workDir+"AccountGSM.ini";
  FormStorage->IniSection="ExpensesListOnAutoForm";

  ini=new TIniFile(workDir+"AccountGSM.ini");
  Date1Edit->Date=ini->ReadDate("ExpensesListOnAutoForm","Date1",Date());


}
//---------------------------------------------------------------------------
void __fastcall TExpensesListOnAutoForm::FormDestroy(TObject *Sender)
{
TIniFile* ini;

  ini=new TIniFile(workDir+"AccountGSM.ini");
  ini->WriteDate("ExpensesListOnAutoForm","Date1",Date1Edit->Date);
  delete ini;
  if(autoID!=NULL) delete autoID;
}
//---------------------------------------------------------------------------
void __fastcall TExpensesListOnAutoForm::FormShow(TObject *Sender)
{
Label3->Visible = false;
autoNumberEdit1->Visible=false;
Label1->Visible = false;
autoNumberEdit->Visible=false;
Date1Edit->SetFocus();
Label4->Visible=false;
CheckBox2->Visible=false;
CheckBox3->Visible=false;
CheckGroup2->Visible=false;
this->ClientHeight=287;
}
//---------------------------------------------------------------------------
void __fastcall TExpensesListOnAutoForm::SaveButtonClick(TObject *Sender)
{
AnsiString sql,fo;
AnsiString Folder=getWorkDir()+"OUT\\";
int k=0;
AnsiString Value[50];
AnsiString IndVyb="'";


if (!CheckGroup->ItemChecked[0] && !CheckGroup->ItemChecked[1])
{
    MessageDlg("Выберите хотя бы один нужный Вам отчет из списка !!! ",mtWarning,TMsgDlgButtons() << mbOK,0);
    return;
}else
{
// форма 55
if (CheckGroup->ItemChecked[0])
{
sql="";
int index = autoNumberEdit->ItemIndex;
int index1 = autoNumberEdit1->ItemIndex;
p();

if (CheckBox3->Checked)
{

for (int i=0;i<50;i++)
{
Value[i]="";
}

int cl=CheckGroup2->Items->Count;

for (int i=0;i<cl;i++)
{
if (CheckGroup2->ItemChecked[i])
{
Value[k]=CheckGroup2->Items->Strings[i];
k++;
}
}

if (k==0)
{
    MessageDlg("Выберите хотя бы один нужный Вам ОПС из списка !!! ",mtWarning,TMsgDlgButtons() << mbOK,0);
    return;
}else
{

if (k==1)
{
IndVyb=IndVyb+Value[0].Trim()+"'";
}
else
{
for (int i=0;i<k;i++)
{
if(i==k-1)
{
IndVyb=IndVyb+Value[i].Trim()+"'";
break;
}
IndVyb=IndVyb+Value[i].Trim()+"','";
}
}
}
}

    DS->Close();
    DS->SQLs->SelectSQL->Clear();
    sql="select sum(e.EXPENSE) as EXP_SUM,sum(e.KOL) as KOL_SUM";
    sql+=" from EXPENSES_TABLE e";
    sql+=" left outer join OPS_TABLE sd on sd.ID=e.SD_ID";
    sql+=" left outer join OPS_TABLE d on d.ID=e.DRIVER_ID";
    sql+=" left outer join OPER_TABLE m on m.ID=e.GSM_ID";
    sql+=" where e.EXP_DATE = '"+Date1Edit->Date.DateString()+"'";
    sql+=" and e.SD_ID="+autoID->Strings[index];
    if (GSM_DM->UserRole!="администратор" && GSM_DM->UserRole!="руководитель")
    {
     if (!CheckBox1->Checked) sql+=" and e.u_id="+IntToStr(GSM_DM->UserID);
    }
    if (CheckBox2->Checked) sql+=" and e.d= 1";
    if (CheckBox3->Checked)  sql+=" and d.DESCRIPTION IN ("+IndVyb.Trim()+ ")";
    sql+=" and m.FILE_ID= 33";
    sql+=" and m.ID IN (3,6,17)";
    sql+=" and m.VISIBLE=1";
    sql+=" and sd.VISIBLE=1";
    sql+=" and d.VISIBLE=1";
    sql+=" and e.FLAG=1";
    DS->SQLs->SelectSQL->Add(sql);
    try
    {
      DS->Open();
    }
        catch (Exception &exc)
    { MessageDlg("Ошибка - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      return;
    }

    DS1->Close();
    DS1->SQLs->SelectSQL->Clear();
    sql="";
    sql="select sum(e.EXPENSE) as EXP_SUM,sum(e.KOL) as KOL_SUM";
    sql+=" from EXPENSES_TABLE e";
    sql+=" left outer join OPS_TABLE sd on sd.ID=e.SD_ID";
    sql+=" left outer join OPS_TABLE d on d.ID=e.DRIVER_ID";
    sql+=" left outer join OPER_TABLE m on m.ID=e.GSM_ID";
    sql+=" where e.EXP_DATE = '"+Date1Edit->Date.DateString()+"'";
    sql+=" and e.SD_ID="+autoID->Strings[index];
    if (GSM_DM->UserRole!="администратор" && GSM_DM->UserRole!="руководитель")
    {
     if (!CheckBox1->Checked) sql+=" and e.u_id="+IntToStr(GSM_DM->UserID);
    }
    if (CheckBox3->Checked)  sql+=" and d.DESCRIPTION IN ("+IndVyb.Trim()+ ")";
    sql+=" and m.FILE_ID= 34";
    sql+=" and m.VISIBLE=1";
    sql+=" and sd.VISIBLE=1";
    sql+=" and d.VISIBLE=1";
    sql+=" and e.FLAG=1";
    DS1->SQLs->SelectSQL->Add(sql);
    try
    {
      DS1->Open();
      fo=createF55File(DS,DS1,autoNumberEdit->Text,Date1Edit->Date);
    }
        catch (Exception &exc)
    { MessageDlg("Ошибка - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      return;
    }


if (fo.Trim()!="F"){
//ShellExecute(Handle,"explore",Folder.c_str(),NULL,NULL,SW_RESTORE);
ShellExecute(Handle,"open",fo.c_str(),NULL,Folder.c_str(),SW_RESTORE);
}

}

// форма 42
if (CheckGroup->ItemChecked[1])
{
sql="";
int index = autoNumberEdit->ItemIndex;
int index1 = autoNumberEdit1->ItemIndex;

    DS->Close();
    DS->SQLs->SelectSQL->Clear();
    sql="select sum(e.EXPENSE) as EXP,sum(e.KOL) as KOL,m.NUMBERROW as NR";
    sql+=" from EXPENSES_TABLE e";
    sql+=" left outer join OPS_TABLE sd on sd.ID=e.SD_ID";
    sql+=" left outer join OPS_TABLE d on d.ID=e.DRIVER_ID";
    sql+=" left outer join OPER_TABLE m on m.ID=e.GSM_ID";
    sql+=" where e.EXP_DATE = '"+Date1Edit->Date.DateString()+"'";
    sql+=" and e.SD_ID="+autoID->Strings[index];
    if (GSM_DM->UserRole!="администратор" && GSM_DM->UserRole!="руководитель") sql+=" and e.u_id="+IntToStr(GSM_DM->UserID);
    sql+=" and d.DESCRIPTION = '"+autoID1->Strings[index1]+"'";
    sql+=" and m.FILE_ID= 33";
    if (AnsiPos(GSM_DM->Index,autoID1->Strings[index1].Trim())>0){
    sql+=" and m.ID IN (92,93,98,99)";
    }else
    {
    sql+=" and m.ID IN (3,6,17)";
    }
    sql+=" and m.VISIBLE=1";
    sql+=" and sd.VISIBLE=1";
    sql+=" and d.VISIBLE=1";
    sql+=" and e.FLAG=1";
    sql+=" group by m.numberrow";
    DS->SQLs->SelectSQL->Add(sql);
    try
    {
      DS->Open();
    }
        catch (Exception &exc)
    { MessageDlg("Ошибка - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      return;
    }

    sql="";
    DS1->Close();
    DS1->SQLs->SelectSQL->Clear();
    sql="select sum(e.EXPENSE) as EXP,sum(e.KOL) as KOL,m.NUMBERROW as NR";
    sql+=" from EXPENSES_TABLE e";
    sql+=" left outer join OPS_TABLE sd on sd.ID=e.SD_ID";
    sql+=" left outer join OPS_TABLE d on d.ID=e.DRIVER_ID";
    sql+=" left outer join OPER_TABLE m on m.ID=e.GSM_ID";
    sql+=" where e.EXP_DATE = '"+Date1Edit->Date.DateString()+"'";
    sql+=" and e.SD_ID="+autoID->Strings[index];
    if (GSM_DM->UserRole!="администратор" && GSM_DM->UserRole!="руководитель") sql+=" and e.u_id="+IntToStr(GSM_DM->UserID);
    sql+=" and d.DESCRIPTION = '"+autoID1->Strings[index1]+"'";
    sql+=" and m.FILE_ID= 34";
    sql+=" and m.VISIBLE=1";
    sql+=" and sd.VISIBLE=1";
    sql+=" and d.VISIBLE=1";
    sql+=" and e.FLAG=1";
    sql+=" group by m.numberrow";
    DS1->SQLs->SelectSQL->Add(sql);
    try
    {
      DS1->Open();
    }
        catch (Exception &exc)
    { MessageDlg("Ошибка - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      return;
    }

    sql="";
    DS2->Close();
    DS2->SQLs->SelectSQL->Clear();
    sql="select sum(e.EXPENSE) as EXP_SUM,sum(e.KOL) as KOL_SUM";
    sql+=" from EXPENSES_TABLE e";
    sql+=" left outer join OPS_TABLE sd on sd.ID=e.SD_ID";
    sql+=" left outer join OPS_TABLE d on d.ID=e.DRIVER_ID";
    sql+=" left outer join OPER_TABLE m on m.ID=e.GSM_ID";
    sql+=" where e.EXP_DATE = '"+Date1Edit->Date.DateString()+"'";
    sql+=" and e.SD_ID="+autoID->Strings[index];
    if (GSM_DM->UserRole!="администратор" && GSM_DM->UserRole!="руководитель") sql+=" and e.u_id="+IntToStr(GSM_DM->UserID);
    sql+=" and d.DESCRIPTION = '"+autoID1->Strings[index1]+"'";
    sql+=" and m.FILE_ID= 33";
    if (AnsiPos(GSM_DM->Index,autoID1->Strings[index1].Trim())>0){
    sql+=" and m.ID IN (92,93,99)";
    }else
    {
    sql+=" and m.ID IN (3,6,17)";
    }
    sql+=" and m.VISIBLE=1";
    sql+=" and sd.VISIBLE=1";
    sql+=" and d.VISIBLE=1";
    sql+=" and e.FLAG=1";
    DS2->SQLs->SelectSQL->Add(sql);
    try
    {
      DS2->Open();
      if (AnsiPos(GSM_DM->Index,autoID1->Strings[index1].Trim())>0){
        fo=createF42dFile(DS,autoNumberEdit->Text,autoNumberEdit1->Text,Date1Edit->Date);
      }
      else
      {
        fo=createF42File(DS,DS1,DS2,autoNumberEdit->Text,autoNumberEdit1->Text,Date1Edit->Date);
      }
    }
    catch (Exception &exc)
    {
      MessageDlg("Ошибка - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      return;
    }


if (fo.Trim()!="F"){
ShellExecute(Handle,"open",fo.c_str(),NULL,Folder.c_str(),SW_RESTORE);
}
}

}
}
//---------------------------------------------------------------------------
AnsiString __fastcall TExpensesListOnAutoForm::getFIO(void)
{
return autoNumberEdit->Text;
}



void __fastcall TExpensesListOnAutoForm::CheckGroupChange(TObject *Sender,
      int Index, TCheckBoxState NewState)
{


if (CheckGroup->ItemChecked[0] && CheckGroup->ItemChecked[1])
{
Label1->Visible = true;
autoNumberEdit->Visible=true;
Label3->Visible = true;
autoNumberEdit1->Visible=true;
CheckBox3->Visible=true;
if (CheckBox3->Checked){
CheckGroup2->Visible=true;
this->ClientHeight=587;
}else{
CheckGroup2->Visible=false;
this->ClientHeight=287;
}
if (GSM_DM->UserRole!="администратор" && GSM_DM->UserRole!="руководитель")
{
CheckBox1->Visible=true;
}else
{
CheckBox1->Visible=false;
}
autoNumberEdit->SetFocus();
p();
}
else{
if (CheckGroup->ItemChecked[0])
{
Label1->Visible = true;
autoNumberEdit->Visible=true;
CheckBox3->Visible=true;
if (CheckBox3->Checked){
CheckGroup2->Visible=true;
this->ClientHeight=587;
}else{
CheckGroup2->Visible=false;
this->ClientHeight=287;
}
if (GSM_DM->UserRole!="администратор" && GSM_DM->UserRole!="руководитель")
{
CheckBox1->Visible=true;
}else
{
CheckBox1->Visible=false;
}
Label3->Visible = false;
autoNumberEdit1->Visible=false;
Date1Edit->SetFocus();
p();
}

if (CheckGroup->ItemChecked[1])
{
CheckBox1->Visible=false;
CheckBox2->Visible=false;
Label3->Visible = true;
Label4->Visible = false;
autoNumberEdit1->Visible=true;
Label1->Visible = true;
autoNumberEdit->Visible=true;
CheckBox3->Visible=false;
CheckGroup2->Visible=false;
this->ClientHeight=287;
autoNumberEdit->SetFocus();
}

if (!CheckGroup->ItemChecked[0] && !CheckGroup->ItemChecked[1])
{
Label3->Visible = false;
Label4->Visible = false;
CheckBox1->Visible=false;
CheckBox2->Visible=false;
autoNumberEdit1->Visible=false;
Label1->Visible = false;
autoNumberEdit->Visible=false;
CheckBox3->Visible=false;
CheckGroup2->Visible=false;
this->ClientHeight=287;
Date1Edit->SetFocus();
}
}
}
//---------------------------------------------------------------------------

void __fastcall TExpensesListOnAutoForm::autoNumberEditChange(
      TObject *Sender)
{
AnsiString sql;
TpFIBDataSet *rDS=GSM_DM->RDS;
int i;
autoID1=NULL;

  try
  {
    autoID1=new TStringList();
  }
  catch (Exception &exc)
  {
    MessageDlg("Ошибка создания объекта TStringList\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
    autoID1=NULL;
    return;
  }

  int index = autoNumberEdit->ItemIndex;
  autoNumberEdit1->Items->Clear();
  CheckGroup2->Items->Clear();
  rDS->Close();
  rDS->SQLs->SelectSQL->Clear();
  if (GSM_DM->UserRole=="администратор" || GSM_DM->UserRole=="руководитель"){
  sql="select distinct DESCRIPTION as SD_NAME from OPS_TABLE where REC_TYPE=1 and VISIBLE = 1 UNION select distinct DESCRIPTION as SD_NAME from KASSA_TABLE where REC_TYPE=1 and VISIBLE = 1 ";
  }
  else
  {
  sql="select ID,NAME_POST as SD_NAME from NP_PROC1("+autoID->Strings[index]+ ",'" + Date1Edit->Date.DateString()+"'," +IntToStr(GSM_DM->UserID)+")";
  }
  rDS->SQLs->SelectSQL->Add(sql);
  try
  {
    rDS->Open();
  }
  catch (Exception &exc)
  { MessageDlg("Ошибка - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
    return;
  }
  rDS->First();
  i=1;
  while(!rDS->Eof)
  { if(i>50) break;
    AnsiString sdName=rDS->FieldByName("SD_NAME")->AsString;
    CheckGroup2->Items->Add(sdName);
    autoNumberEdit1->Items->Add(sdName);
    autoID1->Add(sdName);
    rDS->Next();
    i++;
  }
  rDS->Close();
  int cls=CheckGroup2->Items->Count;
  for (int i=0;i<cls;i++)
  {
  CheckGroup2->ItemChecked[i]=false;
  }
  CheckBox3->Checked=false;
  autoNumberEdit1->ItemIndex=0;
  CheckBox2->Checked=false;
  p();
}
//---------------------------------------------------------------------------

void __fastcall TExpensesListOnAutoForm::Date1EditChange(TObject *Sender)
{
AnsiString sql;
TpFIBDataSet *rDS=GSM_DM->RDS;
autoID=NULL;
autoID1=NULL;

  try
  {
    autoID=new TStringList();
  }
  catch (Exception &exc)
  {
    MessageDlg("Ошибка создания объекта TStringList\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
    autoID=NULL;
    return;
  }
  autoNumberEdit->Items->Clear();

  rDS->Close();
  rDS->SQLs->SelectSQL->Clear();
  if (GSM_DM->UserRole=="администратор" || GSM_DM->UserRole=="руководитель"){
  sql="select ID,DESCRIPTION as SD_NAME from OPS_TABLE where REC_TYPE=0 and VISIBLE = 1 and ID <> 8 and FILE_ID is not null";
  }
  else
  {
  sql="select ID,NAME_POST as SD_NAME from NP_PROC("+IntToStr(GSM_DM->UserID)+ ",'" + Date1Edit->Date.DateString()+"')";
  }
  rDS->Close();
  rDS->SQLs->SelectSQL->Clear();
  rDS->SQLs->SelectSQL->Add(sql);
  try
  {
    rDS->Open();
  }
  catch (Exception &exc)
  {
  MessageDlg("Ошибка - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
  }
  rDS->First();
  int i=1;
  if (rDS->RecordCount <=0)
  {
  MessageDlg("Нет данных для формирования отчетов !!! Выберите другую дату!!!",mtWarning,TMsgDlgButtons() << mbOK,0);
  autoNumberEdit->Items->Clear();
  autoNumberEdit1->Items->Clear();
  Label3->Visible = false;
  Label4->Visible = false;
  autoNumberEdit1->Visible=false;
  Label1->Visible = false;
  autoNumberEdit->Visible=false;
  SaveButton->Enabled=false;
  return;
  }
  while(!rDS->Eof)
  {
    if(i>50) break;
    AnsiString sdName=rDS->FieldByName("SD_NAME")->AsString;
    autoNumberEdit->Items->Add(sdName);
    autoID->Add(rDS->FieldByName("ID")->AsString);
    rDS->Next();
    i++;
  }
  rDS->Close();

  autoNumberEdit->ItemIndex=0;

  // формирование списка ОПС
  try
  {
    autoID1=new TStringList();
  }
  catch (Exception &exc)
  {
    MessageDlg("Ошибка создания объекта TStringList\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
    autoID1=NULL;
    return;
  }
  int index = autoNumberEdit->ItemIndex;
  autoNumberEdit1->Items->Clear();
  CheckGroup2->Items->Clear();
  rDS->Close();
  rDS->SQLs->SelectSQL->Clear();
  sql="";
  if (GSM_DM->UserRole=="администратор" || GSM_DM->UserRole=="руководитель"){
  sql="select distinct DESCRIPTION as SD_NAME from OPS_TABLE where REC_TYPE=1 and VISIBLE = 1 UNION select distinct DESCRIPTION as SD_NAME from KASSA_TABLE where REC_TYPE=1 and VISIBLE = 1 ";
  }
  else
  {
  sql="select ID,NAME_POST as SD_NAME from NP_PROC1("+autoID->Strings[index]+ ",'" + Date1Edit->Date.DateString()+"'," +IntToStr(GSM_DM->UserID)+")";
  }
  rDS->SQLs->SelectSQL->Add(sql);
  try
  {
    rDS->Open();
  }
  catch (Exception &exc)
  { MessageDlg("Ошибка - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
    return;
  }
  rDS->First();
  i=1;
  while(!rDS->Eof)
  { if(i>50) break;
    AnsiString sdName=rDS->FieldByName("SD_NAME")->AsString;
    CheckGroup2->Items->Add(sdName);
    autoNumberEdit1->Items->Add(sdName);
    autoID1->Add(sdName);
    rDS->Next();
    i++;
  }
  rDS->Close();
  int cls=CheckGroup2->Items->Count;
  for (int i=0;i<cls;i++)
  {
  CheckGroup2->ItemChecked[i]=false;
  }
  CheckBox3->Checked=false;
  autoNumberEdit1->ItemIndex=0;
  SaveButton->Enabled=true;
  if (CheckGroup->ItemChecked[0]) p();

}
//---------------------------------------------------------------------------

void __fastcall TExpensesListOnAutoForm::p(void)
{
AnsiString sql;
TpFIBDataSet *rDS=GSM_DM->RDS;
int i;

  int index = autoNumberEdit->ItemIndex;

  rDS->Close();
  rDS->SQLs->SelectSQL->Clear();
    sql="select count(e.ID) as C_ID";
    sql+=" from EXPENSES_TABLE e";
    sql+=" left outer join OPS_TABLE sd on sd.ID=e.SD_ID";
//    sql+=" left outer join OPS_TABLE d on d.ID=e.DRIVER_ID";
    sql+=" left outer join OPER_TABLE m on m.ID=e.GSM_ID";
    sql+=" where e.EXP_DATE = '"+Date1Edit->Date.DateString()+"'";
    sql+=" and e.SD_ID="+autoID->Strings[index];
    if (GSM_DM->UserRole!="администратор" && GSM_DM->UserRole!="руководитель")
    {
     if (!CheckBox1->Checked) sql+=" and e.u_id="+IntToStr(GSM_DM->UserID);
    }
    sql+=" and e.d= 1";
    sql+=" and m.FILE_ID= 33";
    sql+=" and m.VISIBLE=1";
    sql+=" and sd.VISIBLE=1";
//    sql+=" and d.VISIBLE=1";
    sql+=" and e.FLAG=1";
  rDS->SQLs->SelectSQL->Add(sql);
  try
  {
    rDS->Open();
  }
  catch (Exception &exc)
  { MessageDlg("Ошибка - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
    return;
  }
  rDS->First();
  i=rDS->FieldByName("C_ID")->AsInteger;
  if(i>0)
  {
  Label4->Visible=true;
  CheckBox2->Visible=true;
  }else
  {
  Label4->Visible=false;
  CheckBox2->Visible=false;
  }
  rDS->Close();
  autoNumberEdit1->ItemIndex=0;

}

void __fastcall TExpensesListOnAutoForm::CheckBox2Click(TObject *Sender)
{
//if (CheckBox2->Checked) CheckBox1->Checked=false;
}
//---------------------------------------------------------------------------

void __fastcall TExpensesListOnAutoForm::CheckBox1Click(TObject *Sender)
{
//if (CheckBox1->Checked) CheckBox2->Checked=false;
}
//---------------------------------------------------------------------------

void __fastcall TExpensesListOnAutoForm::CheckBox3Click(TObject *Sender)
{
if (CheckBox3->Checked){
CheckGroup2->Visible=true;
this->ClientHeight=587;
}else{
CheckGroup2->Visible=false;
this->ClientHeight=287;
}
}
//---------------------------------------------------------------------------

