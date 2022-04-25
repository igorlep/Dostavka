//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "ReestrSum.h"
#include "DataModule.h"
#include "SomeFunctions.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "FIBDataSet"
#pragma link "pFIBDataSet"
#pragma link "Placemnt"
#pragma link "ToolEdit"
#pragma resource "*.dfm"
TExpensesListOnAutoForm5 *ExpensesListOnAutoForm5;
//---------------------------------------------------------------------------
__fastcall TExpensesListOnAutoForm5::TExpensesListOnAutoForm5(TComponent* Owner)
        : TForm(Owner)
{
TIniFile* ini;
AnsiString sql;

  workDir=ExtractFilePath(Application->ExeName);
  FormStorage->IniFileName=workDir+"AccountGSM.ini";
  FormStorage->IniSection="ExpensesListOnAutoForm5";

  ini=new TIniFile(workDir+"AccountGSM.ini");
  Date1Edit->Date=ini->ReadDate("ExpensesListOnAutoForm2","Date1",Date());
  delete ini;
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

  TpFIBDataSet *rDS=GSM_DM->RDS;
  rDS->Close();
  rDS->SQLs->SelectSQL->Clear();
  if (GSM_DM->UserRole=="администратор" || GSM_DM->UserRole=="руководитель"){
  sql="select ID,DESCRIPTION as SD_NAME from KASSA_TABLE where REC_TYPE=0 and VISIBLE = 1 and FILE_ID <> 8 and ID <> 8";
  rDS->SQLs->SelectSQL->Add(sql);
  try
  {
    rDS->Open();
  }
  catch (Exception &exc)
  { MessageDlg("Ошибка - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
    return;
  }
  }
  else
  {
  sql="select ID,NAME_KASSA as SD_NAME from NK_PROC("+IntToStr(GSM_DM->UserID)+")";
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
  }
  rDS->First();
  int i=1;
  while(!rDS->Eof)
  { if(i>50) break;
    AnsiString sdName=rDS->FieldByName("SD_NAME")->AsString;
    autoNumberEdit->Items->Add(sdName);
    autoID->Add(rDS->FieldByName("ID")->AsString);
    rDS->Next();
    i++;
  }
  rDS->Close();
  autoNumberEdit->ItemIndex=0;
}
//---------------------------------------------------------------------------
void __fastcall TExpensesListOnAutoForm5::FormDestroy(TObject *Sender)
{
TIniFile* ini;

  ini=new TIniFile(workDir+"AccountGSM.ini");
  ini->WriteDate("ExpensesListOnAutoForm5","Date1",Date1Edit->Date);
  delete ini;
  if(autoID!=NULL) delete autoID;

}
//---------------------------------------------------------------------------
void __fastcall TExpensesListOnAutoForm5::FormShow(TObject *Sender)
{
  autoNumberEdit->SetFocus();
}

//---------------------------------------------------------------------------
void __fastcall TExpensesListOnAutoForm5::SaveButtonClick(TObject *Sender)
{
AnsiString sql,fo;
AnsiString Folder=getWorkDir()+"OUT\\";
int nspost=14;
int index = autoNumberEdit->ItemIndex;

sql="";

DS->Close();
DS->SQLs->SelectSQL->Clear();
sql="select distinct ";
sql+="expenses_table.sd_id as kp, expenses_table.driver_id as indexops ";
sql+="from kassa_table ";
sql+="left outer join expenses_table on (kassa_table.id = expenses_table.sd_id) ";
sql+="left outer join oper_table on (expenses_table.gsm_id = oper_table.id) ";
sql+="where ( ";
sql+="kassa_table.id = " +autoID->Strings[index];
sql+=" and kassa_table.visible = 1";
sql+=" and oper_table.visible = 1";
sql+=" and expenses_table.flag = 0";
sql+=" and expenses_table.exp_date = '"+Date1Edit->Date.DateString()+" ') ";
DS->SQLs->SelectSQL->Add(sql);
try
{
DS->Open();
}
catch (Exception &exc)
{
MessageDlg("Ошибка - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
return;
}
DS->Last();
if (DS->RecordCount == 0)
{
MessageDlg("Нет данных!!!. Формирования отчетов прервано!!! ",mtWarning,TMsgDlgButtons() << mbOK,0);
return;
}else
{
    fo=createreestrFile(autoNumberEdit->Text,Date1Edit->Date);
    // ОПС
    DS->First();
    while (!DS->Eof)
    {
    // Пенсия
    sql="";
    DS1->Close();
    DS1->SQLs->SelectSQL->Clear();
    sql="select distinct ";
    sql+="sum (expenses_table.kol) as kol_sum, sum(expenses_table.expense) as exp_sum, kassa_table.description ";
    sql+="from kassa_table ";
    sql+="left outer join expenses_table on (kassa_table.id = expenses_table.driver_id) ";
    sql+="left outer join oper_table on (expenses_table.gsm_id = oper_table.id) ";
    sql+="where ( ";
    sql+="kassa_table.id = " + IntToStr(DS->FieldByName("indexops")->AsInteger);
    sql+=" and kassa_table.visible = 1";
    sql+=" and oper_table.visible = 1";
    sql+=" and oper_table.id = 35"; //6
    sql+=" and expenses_table.flag = 0";
    sql+=" and expenses_table.exp_date = '"+Date1Edit->Date.DateString()+" ') ";
    sql+=" group by kassa_table.description";
    DS1->SQLs->SelectSQL->Add(sql);
    try
    {
      DS1->Open();
    }
    catch (Exception &exc)
    { MessageDlg("Ошибка - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      return;
    }
    // рег едв
    sql="";
    DS2->Close();
    DS2->SQLs->SelectSQL->Clear();
    sql="select distinct ";
    sql+="sum (expenses_table.kol) as kol_sum, sum(expenses_table.expense) as exp_sum, kassa_table.description ";
    sql+="from kassa_table ";
    sql+="left outer join expenses_table on (kassa_table.id = expenses_table.driver_id) ";
    sql+="left outer join oper_table on (expenses_table.gsm_id = oper_table.id) ";
    sql+="where ( ";
    sql+="kassa_table.id = " + IntToStr(DS->FieldByName("indexops")->AsInteger);
    sql+=" and kassa_table.visible = 1";
    sql+=" and oper_table.visible = 1";
    sql+=" and oper_table.id = 36"; //17
    sql+=" and expenses_table.flag = 0";
    sql+=" and expenses_table.exp_date = '"+Date1Edit->Date.DateString()+" ') ";
    sql+=" group by kassa_table.description";
    DS2->SQLs->SelectSQL->Add(sql);
    try
    {
      DS2->Open();
    }
    catch (Exception &exc)
    { MessageDlg("Ошибка - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      return;
    }
    // мун едв
    sql="";
    DS3->Close();
    DS3->SQLs->SelectSQL->Clear();
    sql="select distinct ";
    sql+="sum (expenses_table.kol) as kol_sum, sum(expenses_table.expense) as exp_sum, kassa_table.description ";
    sql+="from kassa_table ";
    sql+="left outer join expenses_table on (kassa_table.id = expenses_table.driver_id) ";
    sql+="left outer join oper_table on (expenses_table.gsm_id = oper_table.id) ";
    sql+="where ( ";
    sql+="kassa_table.id = " + IntToStr(DS->FieldByName("indexops")->AsInteger);
    sql+=" and kassa_table.visible = 1";
    sql+=" and oper_table.visible = 1";
    sql+=" and oper_table.id = 37"; //3
    sql+=" and expenses_table.flag = 0";
    sql+=" and expenses_table.exp_date = '"+Date1Edit->Date.DateString()+" ') ";
    sql+=" group by kassa_table.description";
    DS3->SQLs->SelectSQL->Add(sql);
    try
    {
      DS3->Open();
    }
    catch (Exception &exc)
    { MessageDlg("Ошибка - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      return;
    }


    // погребения
    sql="";
    DS5->Close();
    DS5->SQLs->SelectSQL->Clear();
    sql="select distinct ";
    sql+="sum (expenses_table.kol) as kol_sum, sum(expenses_table.expense) as exp_sum, kassa_table.description ";
    sql+="from kassa_table ";
    sql+="left outer join expenses_table on (kassa_table.id = expenses_table.driver_id) ";
    sql+="left outer join oper_table on (expenses_table.gsm_id = oper_table.id) ";
    sql+="where ( ";
    sql+="kassa_table.id = " + IntToStr(DS->FieldByName("indexops")->AsInteger);
    sql+=" and kassa_table.visible = 1";
    sql+=" and oper_table.visible = 1";
    sql+=" and oper_table.id = 39"; //42
    sql+=" and expenses_table.flag = 0";
    sql+=" and expenses_table.exp_date = '"+Date1Edit->Date.DateString()+" ') ";
    sql+=" group by kassa_table.description";
    DS5->SQLs->SelectSQL->Add(sql);
    try
    {
      DS5->Open();
    }
    catch (Exception &exc)
    { MessageDlg("Ошибка - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      return;
    }

    // город
    sql="";
    DS6->Close();
    DS6->SQLs->SelectSQL->Clear();
    sql="select distinct ";
    sql+="sum (expenses_table.kol) as kol_sum, sum(expenses_table.expense) as exp_sum, kassa_table.description ";
    sql+="from kassa_table ";
    sql+="left outer join expenses_table on (kassa_table.id = expenses_table.driver_id) ";
    sql+="left outer join oper_table on (expenses_table.gsm_id = oper_table.id) ";
    sql+="where ( ";
    sql+="kassa_table.id = " + IntToStr(DS->FieldByName("indexops")->AsInteger);
    sql+=" and kassa_table.visible = 1";
    sql+=" and oper_table.visible = 1";
    sql+=" and oper_table.id = 44"; //43
    sql+=" and expenses_table.flag = 0";
    sql+=" and expenses_table.exp_date = '"+Date1Edit->Date.DateString()+" ') ";
    sql+=" group by kassa_table.description";
    DS6->SQLs->SelectSQL->Add(sql);
    try
    {
      DS6->Open();
    }
    catch (Exception &exc)
    { MessageDlg("Ошибка - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      return;
    }

    editreestrFile(DS1,DS2,DS3,DS5,DS6,fo,nspost);
    nspost++;
    DS->Next();
    }

nspost=nspost+1;
sql="";
// оплата всего
DS->Close();
DS->SQLs->SelectSQL->Clear();
sql="select distinct ";
sql+="sum (expenses_table.kol) as kol_sum, sum(expenses_table.expense) as exp_sum ";
sql+="from kassa_table ";
sql+="left outer join expenses_table on (kassa_table.id = expenses_table.sd_id) ";
sql+="left outer join oper_table on (expenses_table.gsm_id = oper_table.id) ";
sql+="where ( ";
sql+="kassa_table.id = " +autoID->Strings[index];
sql+=" and kassa_table.visible = 1";
sql+=" and oper_table.visible = 1";
sql+=" and oper_table.file_id = 34";
sql+=" and expenses_table.flag = 0";
sql+=" and expenses_table.exp_date = '"+Date1Edit->Date.DateString()+" ') ";
DS->SQLs->SelectSQL->Add(sql);
try
{
DS->Open();
}
catch (Exception &exc)
{
MessageDlg("Ошибка - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
return;
}

// подкрепления всего

DS4->Close();
DS4->SQLs->SelectSQL->Clear();
sql="select distinct ";
sql+="sum (expenses_table.kol) as kol_sum, sum(expenses_table.expense) as exp_sum ";
sql+="from expenses_table ";
sql+="left outer join oper_table on (expenses_table.gsm_id = oper_table.id) ";
sql+="where ( ";
sql+=" oper_table.visible = 1";
sql+=" and oper_table.id = 70";
sql+=" and expenses_table.flag = 0";
sql+=" and expenses_table.exp_date = '"+Date1Edit->Date.DateString()+" ') ";
DS4->SQLs->SelectSQL->Add(sql);
try
{
DS4->Open();
}
catch (Exception &exc)
{
MessageDlg("Ошибка - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
return;
}

deletereestrFile(fo,nspost,DS->FieldByName("EXP_SUM")->AsFloat,DS4->FieldByName("EXP_SUM")->AsFloat);

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
}
//---------------------------------------------------------------------------

