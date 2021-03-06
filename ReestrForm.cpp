//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "DataModule.h"
#include "Main.h"
#include "UniversalReferenceBook.h"
#include "ReestrForm.h"
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
__fastcall TExpensesListOnAutoForm2::TExpensesListOnAutoForm2(TComponent* Owner)
        : TForm(Owner)
{
TIniFile* ini;
AnsiString sql;

  workDir=ExtractFilePath(Application->ExeName);
  FormStorage->IniFileName=workDir+"AccountGSM.ini";
  FormStorage->IniSection="ExpensesListOnAutoForm2";

  ini=new TIniFile(workDir+"AccountGSM.ini");
  Date1Edit->Date=ini->ReadDate("ExpensesListOnAutoForm2","Date1",Date());
  delete ini;
  try
  {
    autoID=new TStringList();
  }
  catch (Exception &exc)
  {
    MessageDlg("?????? ???????? ??????? TStringList\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
    autoID=NULL;
    return;
  }
  autoNumberEdit->Items->Clear();

  TpFIBDataSet *rDS=GSM_DM->RDS;
  rDS->Close();
  rDS->SQLs->SelectSQL->Clear();
  if (GSM_DM->UserRole=="?????????????" || GSM_DM->UserRole=="????????????"){
  sql="select ID,DESCRIPTION as SD_NAME from KASSA_TABLE where REC_TYPE=0 and VISIBLE = 1 and FILE_ID <> 8 and ID <> 8";
  rDS->SQLs->SelectSQL->Add(sql);
  try
  {
    rDS->Open();
  }
  catch (Exception &exc)
  { MessageDlg("?????? - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
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
  MessageDlg("?????? - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
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
void __fastcall TExpensesListOnAutoForm2::FormDestroy(TObject *Sender)
{
TIniFile* ini;

  ini=new TIniFile(workDir+"AccountGSM.ini");
  ini->WriteDate("ExpensesListOnAutoForm2","Date1",Date1Edit->Date);
  delete ini;
  if(autoID!=NULL) delete autoID;
}
//---------------------------------------------------------------------------
void __fastcall TExpensesListOnAutoForm2::FormShow(TObject *Sender)
{

  autoNumberEdit->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TExpensesListOnAutoForm2::SaveButtonClick(TObject *Sender)
{
AnsiString sql,fo;
AnsiString Folder=getWorkDir()+"OUT\\";
sql="";
int index = autoNumberEdit->ItemIndex;


// ????? 42
sql="";

    DS->Close();
    DS->SQLs->SelectSQL->Clear();
    sql="select e.EXPENSE as EXP,e.KOL as KOL";
    sql+=" from EXPENSES_TABLE e";
    sql+=" left outer join OPER_TABLE m on m.ID=e.GSM_ID";
    sql+=" where e.EXP_DATE = '"+Date1Edit->Date.DateString()+"'";
    sql+=" and m.ID= 70";
    sql+=" and m.VISIBLE=1";
    DS->SQLs->SelectSQL->Add(sql);
    try
    {
      DS->Open();
    }
        catch (Exception &exc)
    { MessageDlg("?????? - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      return;
    }


    DS1->Close();
    DS1->SQLs->SelectSQL->Clear();
    sql="select distinct";
    sql+=" sum(expenses_table.kol) as kol,sum(expenses_table.expense) as exp,oper_table.numberrow as nr";
    sql+=" from kassa_table ";
    sql+=" left outer join expenses_table on (kassa_table.id = expenses_table.sd_id)";
    sql+=" left outer join oper_table on (expenses_table.gsm_id = oper_table.id)";
    sql+=" where (";
    sql+=" expenses_table.exp_date = '"+Date1Edit->Date.DateString()+"'";
    sql+=" and oper_table.file_id in (33,34)";
    if (!CheckBox1->Checked) sql+=" and kassa_table.id="+autoID->Strings[index];
    sql+=" and oper_table.visible=1";
    sql+=" and kassa_table.visible=1";
    sql+=" and expenses_table.flag=0)";
    sql+=" group by oper_table.numberrow";
    DS1->SQLs->SelectSQL->Add(sql);
    try
    {
      DS1->Open();
      fo=createF42KFile(DS,DS1,autoNumberEdit->Text,Date1Edit->Date);
    }
        catch (Exception &exc)
    { MessageDlg("?????? - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      return;
    }


if (fo.Trim()!="F"){
//ShellExecute(Handle,"explore",Folder.c_str(),NULL,NULL,SW_RESTORE);
ShellExecute(Handle,"open",fo.c_str(),NULL,Folder.c_str(),SW_RESTORE);
}

}
//---------------------------------------------------------------------------

