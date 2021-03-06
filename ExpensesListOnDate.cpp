//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "DataModule.h"
#include "ExpensesListOnDate.h"
#include "SomeFunctions.h"
#include "Main.h"
#include "DifferentFunctions.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "FIBDataSet"
#pragma link "frxClass"
#pragma link "frxDBSet"
#pragma link "frxExportXLS"
#pragma link "pFIBDataSet"
#pragma link "Placemnt"
#pragma link "SmrtPanel"
#pragma link "ToolEdit"
#pragma link "RzButton"
#pragma link "RzPrgres"
#pragma link "CGAUGES"
#pragma resource "*.dfm"
//TExpensesListOnDateForm *ExpensesListOnDateForm;
//---------------------------------------------------------------------------
__fastcall TExpensesListOnDateForm::TExpensesListOnDateForm(TComponent* Owner)
        : TForm(Owner)
{
TIniFile* ini;

  workDir=ExtractFilePath(Application->ExeName);
  FormStorage->IniFileName=workDir+"AccountGSM.ini";
  FormStorage->IniSection="ExpensesListOnDateForm";

  ini=new TIniFile(workDir+"AccountGSM.ini");
  Date1Edit->Date=ini->ReadDate("ExpensesListOnDateForm","expDate",Date());
  Edit1->Text="";
  Edit2->Text="";
  Edit4->Text="";
  Edit5->Text="";
  Edit6->Text="";
  Edit7->Text="";
  Edit8->Text="";
  Edit9->Text="";
  Edit10->Text="";
  Edit11->Text="";
  Edit12->Text="";
  delete ini;

}
//---------------------------------------------------------------------------
void __fastcall TExpensesListOnDateForm::FormDestroy(TObject *Sender)
{
TIniFile* ini;

  MainForm->LoadWorkDS(MainForm->getSD_ID(),MainForm->getID());
  ini=new TIniFile(workDir+"AccountGSM.ini");
  ini->WriteDate("ExpensesListOnDateForm","expDate",Date1Edit->Date);
  delete ini;
}
//---------------------------------------------------------------------------
void __fastcall TExpensesListOnDateForm::FormShow(TObject *Sender)
{
AnsiString sql,s;
unsigned short y,m,d1;
unsigned short ym,mm,dm;

Indicator->Visible = false;

    sql="";
    DS->Close();
    DS->SQLs->SelectSQL->Clear();
    sql="select ";
    sql+="min( expenses_table.exp_date ) min_of_date ";
    sql+="from expenses_table ";
    sql+="left outer join oper_table on (expenses_table.gsm_id = oper_table.id) ";
    sql+="where ";
    sql+=" oper_table.file_id = 48";
    sql+=" and oper_table.visible = 1";
    DS->SQLs->SelectSQL->Add(sql);
    try
    {
      DS->Open();
      datemin=DS->FieldByName("MIN_OF_DATE")->AsDateTime;
      datemin.DecodeDate(&ym,&mm,&dm);
      s=AnsiString().sprintf("%02d-%02d-%d",dm,mm,ym);
      Edit3->Text=s.c_str();
    }
    catch (Exception &exc)
    {
      MessageDlg("?????? - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      return;
    }


    sql="";
    DS->Close();
    DS->SQLs->SelectSQL->Clear();
    sql="select ";
    sql+="max( expenses_table.exp_date ) max_of_date ";
    sql+="from expenses_table ";
    sql+="left outer join oper_table on (expenses_table.gsm_id = oper_table.id) ";
    sql+="where ";
    sql+=" oper_table.file_id = 48";
    sql+=" and oper_table.visible = 1";
    sql+=" and expenses_table.exp_date < '"+Date1Edit->Date.DateString()+" ' ";
    DS->SQLs->SelectSQL->Add(sql);
    try
    {
      DS->Open();
      date=DS->FieldByName("MAX_OF_DATE")->AsDateTime;
      date.DecodeDate(&y,&m,&d1);
      s=AnsiString().sprintf("%02d-%02d-%d",d1,m,y);
      Edit1->Text=s.c_str();
      Edit4->Text=Date1Edit->Date.DateString();
    }
    catch (Exception &exc)
    {
      MessageDlg("?????? - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      return;
    }


    sql="";
    DS->Close();
    DS->SQLs->SelectSQL->Clear();
    sql="select ";
    sql+="sum(expenses_table.expense) sum_of_exp ";
    sql+="from expenses_table ";
    sql+="left outer join oper_table on (expenses_table.gsm_id = oper_table.id) ";
    sql+="where ";
    sql+=" oper_table.file_id = 48";
    sql+=" and oper_table.visible = 1";
    sql+=" and expenses_table.exp_date = '"+date.DateString()+" ' ";

    DS->SQLs->SelectSQL->Add(sql);
    try
    {
      DS->Open();
      s=AnsiString().sprintf("%.02lf",DS->FieldByName("SUM_OF_EXP")->AsFloat);
      ost1=DS->FieldByName("SUM_OF_EXP")->AsFloat;
      Edit2->Text=s.c_str();
    }
    catch (Exception &exc)
    {
      MessageDlg("?????? - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      return;
    }

    sql="";
    DS->Close();
    DS->SQLs->SelectSQL->Clear();
    sql="select ";
    sql+="sum(expenses_table.expense) sum_of_exp ";
    sql+="from expenses_table ";
    sql+="left outer join oper_table on (expenses_table.gsm_id = oper_table.id) ";
    sql+="where ";
    sql+=" oper_table.id = 60";
    sql+=" and oper_table.visible = 1";
    sql+=" and expenses_table.exp_date = '"+date.DateString()+" ' ";

    DS->SQLs->SelectSQL->Add(sql);
    try
    {
      DS->Open();
      s=AnsiString().sprintf("%.02lf",DS->FieldByName("SUM_OF_EXP")->AsFloat);
      ost2=DS->FieldByName("SUM_OF_EXP")->AsFloat;
      Edit5->Text=s.c_str();
    }
    catch (Exception &exc)
    {
      MessageDlg("?????? - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      return;
    }

    sql="";
    DS->Close();
    DS->SQLs->SelectSQL->Clear();
    sql="select ";
    sql+="sum(expenses_table.expense) sum_of_exp ";
    sql+="from expenses_table ";
    sql+="left outer join oper_table on (expenses_table.gsm_id = oper_table.id) ";
    sql+="where ";
    sql+=" oper_table.id IN (59,63)";
    sql+=" and oper_table.visible = 1";
    sql+=" and expenses_table.exp_date = '"+date.DateString()+" ' ";

    DS->SQLs->SelectSQL->Add(sql);
    try
    {
      DS->Open();
      s=AnsiString().sprintf("%.02lf",DS->FieldByName("SUM_OF_EXP")->AsFloat);
      ost3=DS->FieldByName("SUM_OF_EXP")->AsFloat;
      Edit6->Text=s.c_str();
    }
    catch (Exception &exc)
    {
      MessageDlg("?????? - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      return;
    }

    sql="";
    DS->Close();
    DS->SQLs->SelectSQL->Clear();
    sql="select ";
    sql+="sum(expenses_table.expense) sum_of_exp ";
    sql+="from expenses_table ";
    sql+="left outer join oper_table on (expenses_table.gsm_id = oper_table.id) ";
    sql+="where ";
    sql+=" oper_table.id IN (64)";
    sql+=" and oper_table.visible = 1";
    sql+=" and expenses_table.exp_date = '"+date.DateString()+" ' ";

    DS->SQLs->SelectSQL->Add(sql);
    try
    {
      DS->Open();
      s=AnsiString().sprintf("%.02lf",DS->FieldByName("SUM_OF_EXP")->AsFloat);
      ost7=DS->FieldByName("SUM_OF_EXP")->AsFloat;
      Edit7->Text=s.c_str();
    }
    catch (Exception &exc)
    {
      MessageDlg("?????? - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      return;
    }

    sql="";
    DS->Close();
    DS->SQLs->SelectSQL->Clear();
    sql="select ";
    sql+="sum(expenses_table.expense) sum_of_exp ";
    sql+="from expenses_table ";
    sql+="left outer join oper_table on (expenses_table.gsm_id = oper_table.id) ";
    sql+="where ";
    sql+=" oper_table.id = 81";
    sql+=" and oper_table.visible = 1";
    sql+=" and expenses_table.exp_date = '"+date.DateString()+" ' ";

    DS->SQLs->SelectSQL->Add(sql);
    try
    {
      DS->Open();
      s=AnsiString().sprintf("%.02lf",DS->FieldByName("SUM_OF_EXP")->AsFloat);
      ost5=DS->FieldByName("SUM_OF_EXP")->AsFloat;
      Edit8->Text=s.c_str();
    }
    catch (Exception &exc)
    {
      MessageDlg("?????? - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      return;
    }

    sql="";
    DS->Close();
    DS->SQLs->SelectSQL->Clear();
    sql="select ";
    sql+="sum(expenses_table.expense) sum_of_exp ";
    sql+="from expenses_table ";
    sql+="left outer join oper_table on (expenses_table.gsm_id = oper_table.id) ";
    sql+="where ";
    sql+=" oper_table.id = 90";
    sql+=" and oper_table.visible = 1";
    sql+=" and expenses_table.exp_date = '"+date.DateString()+" ' ";

    DS->SQLs->SelectSQL->Add(sql);
    try
    {
      DS->Open();
      s=AnsiString().sprintf("%.02lf",DS->FieldByName("SUM_OF_EXP")->AsFloat);
      ost8=DS->FieldByName("SUM_OF_EXP")->AsFloat;
      Edit9->Text=s.c_str();
    }
    catch (Exception &exc)
    {
      MessageDlg("?????? - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      return;
    }

    sql="";
    DS->Close();
    DS->SQLs->SelectSQL->Clear();
    sql="select ";
    sql+="sum(expenses_table.expense) sum_of_exp ";
    sql+="from expenses_table ";
    sql+="left outer join oper_table on (expenses_table.gsm_id = oper_table.id) ";
    sql+="where ";
    sql+=" oper_table.id = 95";
    sql+=" and oper_table.visible = 1";
    sql+=" and expenses_table.exp_date = '"+date.DateString()+" ' ";

    DS->SQLs->SelectSQL->Add(sql);
    try
    {
      DS->Open();
      s=AnsiString().sprintf("%.02lf",DS->FieldByName("SUM_OF_EXP")->AsFloat);
      ost9=DS->FieldByName("SUM_OF_EXP")->AsFloat;
      Edit10->Text=s.c_str();
    }
    catch (Exception &exc)
    {
      MessageDlg("?????? - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      return;
    }

    sql="";
    DS->Close();
    DS->SQLs->SelectSQL->Clear();
    sql="select ";
    sql+="sum(expenses_table.expense) sum_of_exp ";
    sql+="from expenses_table ";
    sql+="left outer join oper_table on (expenses_table.gsm_id = oper_table.id) ";
    sql+="where ";
    sql+=" oper_table.id = 102";
    sql+=" and oper_table.visible = 1";
    sql+=" and expenses_table.exp_date = '"+date.DateString()+" ' ";

    DS->SQLs->SelectSQL->Add(sql);
    try
    {
      DS->Open();
      s=AnsiString().sprintf("%.02lf",DS->FieldByName("SUM_OF_EXP")->AsFloat);
      ost10=DS->FieldByName("SUM_OF_EXP")->AsFloat;
      Edit11->Text=s.c_str();
    }
    catch (Exception &exc)
    {
      MessageDlg("?????? - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      return;
    }
// ???????????

    sql="";
    DS->Close();
    DS->SQLs->SelectSQL->Clear();
    sql="select ";
    sql+="sum(expenses_table.expense) sum_of_exp ";
    sql+="from expenses_table ";
    sql+="left outer join oper_table on (expenses_table.gsm_id = oper_table.id) ";
    sql+="where ";
    sql+=" oper_table.id = 107";
    sql+=" and oper_table.visible = 1";
    sql+=" and expenses_table.exp_date = '"+date.DateString()+" ' ";

    DS->SQLs->SelectSQL->Add(sql);
    try
    {
      DS->Open();
      s=AnsiString().sprintf("%.02lf",DS->FieldByName("SUM_OF_EXP")->AsFloat);
      ost11=DS->FieldByName("SUM_OF_EXP")->AsFloat;
      Edit12->Text=s.c_str();
    }
    catch (Exception &exc)
    {
      MessageDlg("?????? - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      return;
    }


  Date1Edit->SetFocus();
}
//---------------------------------------------------------------------------
//???????????? ????? 130

void __fastcall TExpensesListOnDateForm::ReClick(TObject *Sender)
{
AnsiString sql,fo;
AnsiString Folder=getWorkDir()+"OUT\\";
double ostmedv,ostpens,ostpogr,ostredv,osttown,ostperev,ostgood,ostpodp,ostloto,oststrah;
val1=0.0;
val2=0.0;
val3=0.0;
val4=0.0;
val5=0.0;
val6=0.0;
val7=0.0;
val8=0.0;
val9=0.0;
val10=0.0;
val11=0.0;
val12=0.0;
val13=0.0;
val14=0.0;
val15=0.0;
val16=0.0;
val17=0.0;
val18=0.0;
val19=0.0;
val20=0.0;
val21=0.0;
val22=0.0;
val23=0.0;
val24=0.0;
val25=0.0;
val26=0.0;
val27=0.0;
val28=0.0;
val31=0.0;
val33=0.0;
ost6=0.0;
val34=0.0;
val36=0.0;
val37=0.0;
val38=0.0;
val39=0.0;
val40=0.0;
val41=0.0;
val42=0.0;
val43=0.0;
AnsiString fileIn,s,k,itogsum;
AnsiString fileOut;
unsigned short y,m,d1;
AnsiString fout;
TIniFile* ini;
AnsiString workDir;
AnsiString iniFileName;

double podkrpogr=0.0;
double podkrredv=0.0;
double podkrtown=0.0;
double podkrperev=0.0;
double limpogr=0.0;
double limredv=0.0;
double limperev=0.0;
double ostend=0.0;
ostgood=0.0;
ostloto=0.0;
oststrah=0.0;

TpFIBQuery *Q=GSM_DM->WQ;
int id=0;


    sql="";
    DS->Close();
    DS->SQLs->SelectSQL->Clear();
    sql="select count(expenses_table.id) as id_count ";
    sql+="from expenses_table ";
    sql+="where ";
    sql+=" expenses_table.exp_date = '"+Date1Edit->Date.DateString()+" ' ";
    sql+=" and expenses_table.editable = 0 ";
    sql+=" and expenses_table.gsm_id not in (77,75,74,73)";

    DS->SQLs->SelectSQL->Add(sql);
    try
    {
      DS->Open();
      int countrec=DS->FieldByName("ID_COUNT")->AsInteger;
      if ( countrec>0 )
      {
    Q->Close();
    Q->SQL->Clear();
    sql="update EXPENSES_TABLE set";
    sql+=" EDITABLE = 0";
    sql+=" where expenses_table.exp_date = '"+Date1Edit->Date.DateString()+" ' ";
    sql+=" and expenses_table.gsm_id in (77,75,74,73)";
    Q->SQL->Add(sql);
    Q->Transaction->StartTransaction();
    try
    {
      Q->ExecQuery();
    }
    catch (Exception &exc)
    {
      MessageDlg("?????? - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      Q->Transaction->Rollback();
      return;
    }
    Q->Transaction->Commit();
    MainForm->LoadWorkDS(MainForm->getSD_ID(),MainForm->getID());
      }

    }
    catch (Exception &exc)
    {
      MessageDlg("?????? - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      return;
    }

  fileOut=getWorkDir()+"OUT\\";
  Date1Edit->Date.DecodeDate(&y,&m,&d1);
  s=AnsiString().sprintf("%02d-%02d-%d",d1,m,y);
  fileOut+="f130of";
  fout+="f130of";
  fileOut+=s+".xlsx";
  fout+=s+".xlsx";
  SetCurrentDir(Folder);
  if(FileExists(fileOut)) DeleteFile(fileOut);


    fo=createF130File(Date1Edit->Date,ost1,ost2,ost3,ost7,ost5,ost8,ost9,ost10,ost11);
// 2.12.1

    sql="";
    val31=0.0;
    DS->Close();
    DS->SQLs->SelectSQL->Clear();
    sql="select ";
    sql+="sum(expenses_table.expense) sum_of_exp ";
    sql+="from expenses_table ";
    sql+="left outer join oper_table on (expenses_table.gsm_id = oper_table.id) ";
    sql+="where ";
    sql+=" oper_table.id in (92)";
    sql+=" and oper_table.visible = 1";
    sql+=" and expenses_table.exp_date = '"+Date1Edit->Date.DateString()+" ' ";

    DS->SQLs->SelectSQL->Add(sql);
    try
    {
      DS->Open();
      if (!DS->FieldByName("SUM_OF_EXP")->IsNull) val31=DS->FieldByName("SUM_OF_EXP")->AsFloat;
    }
    catch (Exception &exc)
    {
      MessageDlg("?????? - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      return;
    }

// 3.23.1.3

    sql="";
    val1=0.0;
    DS->Close();
    DS->SQLs->SelectSQL->Clear();
    sql="select ";
    sql+="sum(expenses_table.expense) sum_of_exp ";
    sql+="from expenses_table ";
    sql+="left outer join oper_table on (expenses_table.gsm_id = oper_table.id) ";
    sql+="where ";
    sql+=" oper_table.id = 98";
    sql+=" and oper_table.visible = 1";
    sql+=" and expenses_table.exp_date = '"+Date1Edit->Date.DateString()+" ' ";

    DS->SQLs->SelectSQL->Add(sql);
    try
    {
      DS->Open();
      if (!DS->FieldByName("SUM_OF_EXP")->IsNull) val1=DS->FieldByName("SUM_OF_EXP")->AsFloat;
    }
    catch (Exception &exc)
    {
      MessageDlg("?????? - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      return;
    }

    sql="";
    DS->Close();
    DS->SQLs->SelectSQL->Clear();
    sql="select ";
    sql+="sum(expenses_table.expense) sum_of_exp ";
    sql+="from expenses_table ";
    sql+="left outer join oper_table on (expenses_table.gsm_id = oper_table.id) ";
    sql+="where ";
    sql+=" oper_table.id = 58";
    sql+=" and oper_table.visible = 1";
    sql+=" and expenses_table.d = 1";
    sql+=" and expenses_table.exp_date = '"+Date1Edit->Date.DateString()+" ' ";

    DS->SQLs->SelectSQL->Add(sql);
    try
    {
      DS->Open();
      if (!DS->FieldByName("SUM_OF_EXP")->IsNull) val36=DS->FieldByName("SUM_OF_EXP")->AsFloat;
    }
    catch (Exception &exc)
    {
      MessageDlg("?????? - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      return;
    }
    val1=val1+val36;

// 3.2.1.1

    sql="";
    val2=0.0;
    DS->Close();
    DS->SQLs->SelectSQL->Clear();
    sql="select ";
    sql+="sum(expenses_table.expense) sum_of_exp ";
    sql+="from expenses_table ";
    sql+="left outer join oper_table on (expenses_table.gsm_id = oper_table.id) ";
    sql+="where ";
    sql+=" oper_table.id = 55";
    sql+=" and oper_table.visible = 1";
    sql+=" and expenses_table.exp_date = '"+Date1Edit->Date.DateString()+" ' ";

    DS->SQLs->SelectSQL->Add(sql);
    try
    {
      DS->Open();
      if (!DS->FieldByName("SUM_OF_EXP")->IsNull) val2=DS->FieldByName("SUM_OF_EXP")->AsFloat;
    }
    catch (Exception &exc)
    {
      MessageDlg("?????? - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      return;
    }


// 3.1.1.1

    sql="";
    val3=0.0;
    DS->Close();
    DS->SQLs->SelectSQL->Clear();
    sql="select ";
    sql+="sum(expenses_table.expense) sum_of_exp ";
    sql+="from expenses_table ";
    sql+="left outer join oper_table on (expenses_table.gsm_id = oper_table.id) ";
    sql+="where ";
    sql+=" oper_table.id = 57 ";
    sql+=" and oper_table.visible = 1";
    sql+=" and expenses_table.exp_date = '"+Date1Edit->Date.DateString()+" ' ";

    DS->SQLs->SelectSQL->Add(sql);
    try
    {
      DS->Open();
      if (!DS->FieldByName("SUM_OF_EXP")->IsNull) val3=DS->FieldByName("SUM_OF_EXP")->AsFloat;
    }
    catch (Exception &exc)
    {
      MessageDlg("?????? - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      return;
    }

// ???????????? ???????????
    sql="";
    val41=0.0;
    DS->Close();
    DS->SQLs->SelectSQL->Clear();
    sql="select ";
    sql+="sum(expenses_table.expense) sum_of_exp ";
    sql+="from expenses_table ";
    sql+="left outer join oper_table on (expenses_table.gsm_id = oper_table.id) ";
    sql+="where ";
    sql+=" oper_table.id = 105 ";
    sql+=" and oper_table.visible = 1";
    sql+=" and expenses_table.exp_date = '"+Date1Edit->Date.DateString()+" ' ";

    DS->SQLs->SelectSQL->Add(sql);
    try
    {
      DS->Open();
      if (!DS->FieldByName("SUM_OF_EXP")->IsNull) val41=DS->FieldByName("SUM_OF_EXP")->AsFloat;
    }
    catch (Exception &exc)
    {
      MessageDlg("?????? - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      return;
    }


// 4.5.1.1

    sql="";
    val5=0.0;
    DS->Close();
    DS->SQLs->SelectSQL->Clear();
    sql="select ";
    sql+="sum(expenses_table.expense) sum_of_exp ";
    sql+="from expenses_table ";
    sql+="left outer join oper_table on (expenses_table.gsm_id = oper_table.id) ";
    sql+="where ";
    sql+=" oper_table.id IN (35,39) ";
    sql+=" and oper_table.visible = 1";
    sql+=" and expenses_table.exp_date = '"+Date1Edit->Date.DateString()+" ' ";

    DS->SQLs->SelectSQL->Add(sql);
    try
    {
      DS->Open();
      if (!DS->FieldByName("SUM_OF_EXP")->IsNull) val5=DS->FieldByName("SUM_OF_EXP")->AsFloat;
    }
    catch (Exception &exc)
    {
      MessageDlg("?????? - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      return;
    }

    val6=0.0;

// 4.6.1.17  ???

    sql="";
    val7=0.0;
    DS->Close();
    DS->SQLs->SelectSQL->Clear();
    sql="select ";
    sql+="sum(expenses_table.expense) sum_of_exp ";
    sql+="from expenses_table ";
    sql+="left outer join oper_table on (expenses_table.gsm_id = oper_table.id) ";
    sql+="where ";
    sql+=" oper_table.id IN (36,37)";
    sql+=" and oper_table.visible = 1";
    sql+=" and expenses_table.exp_date = '"+Date1Edit->Date.DateString()+" ' ";

    DS->SQLs->SelectSQL->Add(sql);
    try
    {
      DS->Open();
      if (!DS->FieldByName("SUM_OF_EXP")->IsNull) val7=DS->FieldByName("SUM_OF_EXP")->AsFloat;
    }
    catch (Exception &exc)
    {
      MessageDlg("?????? - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      return;
    }

// 4.6.1.5.1 ???

    val8=0.0;

// 4.22.1

    sql="";
    val16=0.0;
    DS->Close();
    DS->SQLs->SelectSQL->Clear();
    sql="select ";
    sql+="sum(expenses_table.expense) sum_of_exp ";
    sql+="from expenses_table ";
    sql+="left outer join oper_table on (expenses_table.gsm_id = oper_table.id) ";
    sql+="where ";
    sql+=" oper_table.file_id IN (46) ";
    sql+=" and oper_table.visible = 1";
    sql+=" and expenses_table.exp_date = '"+Date1Edit->Date.DateString()+" ' ";

    DS->SQLs->SelectSQL->Add(sql);
    try
    {
      DS->Open();
      if (!DS->FieldByName("SUM_OF_EXP")->IsNull) val16=DS->FieldByName("SUM_OF_EXP")->AsFloat;
    }
    catch (Exception &exc)
    {
      MessageDlg("?????? - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      return;
    }

// 4.34.1.1.1

    sql="";
    val17=0.0;
    DS->Close();
    DS->SQLs->SelectSQL->Clear();
    sql="select ";
    sql+="sum(expenses_table.expense) sum_of_exp ";
    sql+="from expenses_table ";
    sql+="left outer join oper_table on (expenses_table.gsm_id = oper_table.id) ";
    sql+="where ";
    sql+=" oper_table.id IN (53) ";
    sql+=" and oper_table.visible = 1";
    sql+=" and expenses_table.exp_date = '"+Date1Edit->Date.DateString()+" ' ";

    DS->SQLs->SelectSQL->Add(sql);
    try
    {
      DS->Open();
      if (!DS->FieldByName("SUM_OF_EXP")->IsNull) val17=DS->FieldByName("SUM_OF_EXP")->AsFloat;
    }
    catch (Exception &exc)
    {
      MessageDlg("?????? - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      return;
    }

// ??????????? ??????????

    sql="";
    val42=0.0;
    DS->Close();
    DS->SQLs->SelectSQL->Clear();
    sql="select ";
    sql+="sum(expenses_table.expense) sum_of_exp ";
    sql+="from expenses_table ";
    sql+="left outer join oper_table on (expenses_table.gsm_id = oper_table.id) ";
    sql+="where ";
    sql+=" oper_table.id = 106 ";
    sql+=" and oper_table.visible = 1";
    sql+=" and expenses_table.exp_date = '"+Date1Edit->Date.DateString()+" ' ";

    DS->SQLs->SelectSQL->Add(sql);
    try
    {
      DS->Open();
      if (!DS->FieldByName("SUM_OF_EXP")->IsNull) val42=DS->FieldByName("SUM_OF_EXP")->AsFloat;
    }
    catch (Exception &exc)
    {
      MessageDlg("?????? - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      return;
    }

// 4.36.1.1

    sql="";
    val18=0.0;
    DS->Close();
    DS->SQLs->SelectSQL->Clear();
    sql="select ";
    sql+="sum(expenses_table.expense) sum_of_exp ";
    sql+="from expenses_table ";
    sql+="left outer join oper_table on (expenses_table.gsm_id = oper_table.id) ";
    sql+="where ";
    sql+=" oper_table.id IN (50) ";
    sql+=" and oper_table.visible = 1";
    sql+=" and expenses_table.exp_date = '"+Date1Edit->Date.DateString()+" ' ";

    DS->SQLs->SelectSQL->Add(sql);
    try
    {
      DS->Open();
      if (!DS->FieldByName("SUM_OF_EXP")->IsNull) val18=DS->FieldByName("SUM_OF_EXP")->AsFloat;
    }
    catch (Exception &exc)
    {
      MessageDlg("?????? - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      return;
    }

// 4.34.1.1

    sql="";
    val19=0.0;
    DS->Close();
    DS->SQLs->SelectSQL->Clear();
    sql="select ";
    sql+="sum(expenses_table.expense) sum_of_exp ";
    sql+="from expenses_table ";
    sql+="left outer join oper_table on (expenses_table.gsm_id = oper_table.id) ";
    sql+="where ";
    sql+=" oper_table.id IN (52) ";
    sql+=" and oper_table.visible = 1";
    sql+=" and expenses_table.exp_date = '"+Date1Edit->Date.DateString()+" ' ";

    DS->SQLs->SelectSQL->Add(sql);
    try
    {
      DS->Open();
      if (!DS->FieldByName("SUM_OF_EXP")->IsNull) val19=DS->FieldByName("SUM_OF_EXP")->AsFloat;
    }
    catch (Exception &exc)
    {
      MessageDlg("?????? - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      return;
    }

// ???????????? ????????

    sql="";
    val25=0.0;
    DS->Close();
    DS->SQLs->SelectSQL->Clear();
    sql="select ";
    sql+="sum(expenses_table.expense) sum_of_exp ";
    sql+="from expenses_table ";
    sql+="left outer join oper_table on (expenses_table.gsm_id = oper_table.id) ";
    sql+="where ";
    sql+=" oper_table.id = 79 ";
    sql+=" and oper_table.visible = 1";
    sql+=" and expenses_table.exp_date = '"+Date1Edit->Date.DateString()+" ' ";

    DS->SQLs->SelectSQL->Add(sql);
    try
    {
      DS->Open();
      if (!DS->FieldByName("SUM_OF_EXP")->IsNull) val25=DS->FieldByName("SUM_OF_EXP")->AsFloat;
    }
    catch (Exception &exc)
    {
      MessageDlg("?????? - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      return;
    }

// ?????????? ????????

    sql="";
    val29=0.0;
    DS->Close();
    DS->SQLs->SelectSQL->Clear();
    sql="select ";
    sql+="sum(expenses_table.expense) sum_of_exp ";
    sql+="from expenses_table ";
    sql+="left outer join oper_table on (expenses_table.gsm_id = oper_table.id) ";
    sql+="where ";
    sql+=" oper_table.id = 80 ";
    sql+=" and oper_table.visible = 1";
    sql+=" and expenses_table.exp_date = '"+Date1Edit->Date.DateString()+" ' ";

    DS->SQLs->SelectSQL->Add(sql);
    try
    {
      DS->Open();
      if (!DS->FieldByName("SUM_OF_EXP")->IsNull) val29=DS->FieldByName("SUM_OF_EXP")->AsFloat;
    }
    catch (Exception &exc)
    {
      MessageDlg("?????? - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      return;
    }

// ?????????? ??????? ???????

    sql="";
    val33=0.0;
    DS->Close();
    DS->SQLs->SelectSQL->Clear();
    sql="select ";
    sql+="sum(expenses_table.expense) sum_of_exp ";
    sql+="from expenses_table ";
    sql+="left outer join oper_table on (expenses_table.gsm_id = oper_table.id) ";
    sql+="where ";
    sql+=" oper_table.id = 91 ";
    sql+=" and oper_table.visible = 1";
    sql+=" and expenses_table.exp_date = '"+Date1Edit->Date.DateString()+" ' ";

    DS->SQLs->SelectSQL->Add(sql);
    try
    {
      DS->Open();
      if (!DS->FieldByName("SUM_OF_EXP")->IsNull) val33=DS->FieldByName("SUM_OF_EXP")->AsFloat;
    }
    catch (Exception &exc)
    {
      MessageDlg("?????? - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      return;
    }

// ?????????? ????????

    sql="";
    val35=0.0;
    DS->Close();
    DS->SQLs->SelectSQL->Clear();
    sql="select ";
    sql+="sum(expenses_table.expense) sum_of_exp ";
    sql+="from expenses_table ";
    sql+="left outer join oper_table on (expenses_table.gsm_id = oper_table.id) ";
    sql+="where ";
    sql+=" oper_table.id = 94 ";
    sql+=" and oper_table.visible = 1";
    sql+=" and expenses_table.exp_date = '"+Date1Edit->Date.DateString()+" ' ";

    DS->SQLs->SelectSQL->Add(sql);
    try
    {
      DS->Open();
      if (!DS->FieldByName("SUM_OF_EXP")->IsNull) val35=DS->FieldByName("SUM_OF_EXP")->AsFloat;
    }
    catch (Exception &exc)
    {
      MessageDlg("?????? - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      return;
    }


// ?????????? ???????

    sql="";
    val38=0.0;
    DS->Close();
    DS->SQLs->SelectSQL->Clear();
    sql="select ";
    sql+="sum(expenses_table.expense) sum_of_exp ";
    sql+="from expenses_table ";
    sql+="left outer join oper_table on (expenses_table.gsm_id = oper_table.id) ";
    sql+="where ";
    sql+=" oper_table.id = 100 ";
    sql+=" and oper_table.visible = 1";
    sql+=" and expenses_table.exp_date = '"+Date1Edit->Date.DateString()+" ' ";

    DS->SQLs->SelectSQL->Add(sql);
    try
    {
      DS->Open();
      if (!DS->FieldByName("SUM_OF_EXP")->IsNull) val38=DS->FieldByName("SUM_OF_EXP")->AsFloat;
    }
    catch (Exception &exc)
    {
      MessageDlg("?????? - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      return;
    }


// ??????????? ?????-????

    sql="";
    val26=0.0;
    DS->Close();
    DS->SQLs->SelectSQL->Clear();
    sql="select ";
    sql+="sum(expenses_table.expense) sum_of_exp ";
    sql+="from expenses_table ";
    sql+="left outer join oper_table on (expenses_table.gsm_id = oper_table.id) ";
    sql+="where ";
    sql+=" oper_table.id = 97 ";
    sql+=" and oper_table.visible = 1";
    sql+=" and expenses_table.exp_date = '"+Date1Edit->Date.DateString()+" ' ";

    DS->SQLs->SelectSQL->Add(sql);
    try
    {
      DS->Open();
      if (!DS->FieldByName("SUM_OF_EXP")->IsNull) val26=DS->FieldByName("SUM_OF_EXP")->AsFloat;
    }
    catch (Exception &exc)
    {
      MessageDlg("?????? - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      return;
    }

// ????????

    sql="";
    val27=0.0;
    DS->Close();
    DS->SQLs->SelectSQL->Clear();
    sql="select ";
    sql+="sum(expenses_table.expense) sum_of_exp ";
    sql+="from expenses_table ";
    sql+="left outer join oper_table on (expenses_table.gsm_id = oper_table.id) ";
    sql+="where ";
    sql+=" oper_table.id in (93) ";
    sql+=" and oper_table.visible = 1";
    sql+=" and expenses_table.exp_date = '"+Date1Edit->Date.DateString()+" ' ";

    DS->SQLs->SelectSQL->Add(sql);
    try
    {
      DS->Open();
      if (!DS->FieldByName("SUM_OF_EXP")->IsNull) val27=DS->FieldByName("SUM_OF_EXP")->AsFloat;
    }
    catch (Exception &exc)
    {
      MessageDlg("?????? - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      return;
    }

// ???????

    sql="";
    val37=0.0;
    DS->Close();
    DS->SQLs->SelectSQL->Clear();
    sql="select ";
    sql+="sum(expenses_table.expense) sum_of_exp ";
    sql+="from expenses_table ";
    sql+="left outer join oper_table on (expenses_table.gsm_id = oper_table.id) ";
    sql+="where ";
    sql+=" oper_table.id in (99) ";
    sql+=" and oper_table.visible = 1";
    sql+=" and expenses_table.exp_date = '"+Date1Edit->Date.DateString()+" ' ";

    DS->SQLs->SelectSQL->Add(sql);
    try
    {
      DS->Open();
      if (!DS->FieldByName("SUM_OF_EXP")->IsNull) val37=DS->FieldByName("SUM_OF_EXP")->AsFloat;
    }
    catch (Exception &exc)
    {
      MessageDlg("?????? - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      return;
    }

// ??????? ????????

    sql="";
    val28=0.0;
    DS->Close();
    DS->SQLs->SelectSQL->Clear();
    sql="select ";
    sql+="sum(expenses_table.expense) sum_of_exp ";
    sql+="from expenses_table ";
    sql+="left outer join oper_table on (expenses_table.gsm_id = oper_table.id) ";
    sql+="where ";
    sql+=" oper_table.id = 96 ";
    sql+=" and oper_table.visible = 1";
    sql+=" and expenses_table.exp_date = '"+Date1Edit->Date.DateString()+" ' ";

    DS->SQLs->SelectSQL->Add(sql);
    try
    {
      DS->Open();
      if (!DS->FieldByName("SUM_OF_EXP")->IsNull) val28=DS->FieldByName("SUM_OF_EXP")->AsFloat;
    }
    catch (Exception &exc)
    {
      MessageDlg("?????? - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      return;
    }


// ??????? ???????

    sql="";
    val40=0.0;
    DS->Close();
    DS->SQLs->SelectSQL->Clear();
    sql="select ";
    sql+="sum(expenses_table.expense) sum_of_exp ";
    sql+="from expenses_table ";
    sql+="left outer join oper_table on (expenses_table.gsm_id = oper_table.id) ";
    sql+="where ";
    sql+=" oper_table.id = 103 ";
    sql+=" and oper_table.visible = 1";
    sql+=" and expenses_table.exp_date = '"+Date1Edit->Date.DateString()+" ' ";

    DS->SQLs->SelectSQL->Add(sql);
    try
    {
      DS->Open();
      if (!DS->FieldByName("SUM_OF_EXP")->IsNull) val40=DS->FieldByName("SUM_OF_EXP")->AsFloat;
    }
    catch (Exception &exc)
    {
      MessageDlg("?????? - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      return;
    }


// ????? ????? ????????? ??????????? ???????? ?? ????? ??? ? ????????? ?? ? ??

ostmedv=0.0;
ostpens=ost2+val2-val5-val18;
ostperev=ost5+val26+val25-val28-val29;
ostpogr=0.0;
ostredv=ost3+val3-val7-val19;
osttown=ost7+val1-val17;
ostgood=ost8+val31-val33;
ostpodp=ost9+val27-val35;
ostloto=ost10+val37-val38-val40;
oststrah=ost11+val41-val42;


ostend=ostmedv+ostpens+ostredv+osttown+ostperev+ostgood+ostpodp+ostloto+oststrah;

val21=ostpens;
val22=ostend;
val23=ostmedv+ostredv;
val24=osttown;
val30=ostperev;
val32=ostgood;
val34=ostpodp;
val39=ostloto;
val43=oststrah;


// ??????? ??????? ?? ????? ??? ? ??

// ??? ????????
    sql="";
    DS->Close();
    DS->SQLs->SelectSQL->Clear();
    sql="select ";
    sql+="expenses_table.id exp_id ";
    sql+="from expenses_table ";
    sql+="where ";
    sql+=" expenses_table.gsm_id = 81";
    sql+=" and expenses_table.exp_date = '"+Date1Edit->Date.DateString()+" ' ";
    DS->SQLs->SelectSQL->Add(sql);
    try
    {
    DS->Open();
    if (DS->FieldByName("EXP_ID")->IsNull)
    {
      // ????????? ????? ???????
    Q->Close();
    Q->SQL->Clear();
    sql="select GEN_ID(GEN_EXPENSES_TABLE_ID,1) as ID from RDB$DATABASE";
    Q->SQL->Add(sql);
    Q->Transaction->StartTransaction();
    try
    {
      Q->ExecQuery();
    }
    catch (Exception &exc)
    { MessageDlg("?????? - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      Q->Transaction->Rollback();
      return;
    }
    if(Q->RecordCount==0)
    {
      MessageDlg("?????? ????????? ???????? ID ??????? EXPENSES_TABLE",mtError,TMsgDlgButtons() << mbOK,0);
      Q->Transaction->Rollback();
      return;
    }
    id=Q->FieldByName("ID")->AsInteger;

    Q->Close();
    Q->SQL->Clear();
    sql="insert into EXPENSES_TABLE(ID,EXP_DATE,SD_ID,DRIVER_ID,GSM_ID,KOL,EXPENSE,FLAG,EDITABLE,U_ID) values(";
    sql+=IntToStr(id)+",";
    sql+="'"+Date1Edit->Date.DateString()+"',";
    sql+=IntToStr(0)+",";
    sql+=IntToStr(0)+",";
    sql+=IntToStr(81)+",";
    sql+=IntToStr(0)+",";
    sql+=FloatToStr(ostperev)+",0,0,";
    sql+=IntToStr(GSM_DM->UserID)+")";
    Q->SQL->Add(sql);
    try
    {
      Q->ExecQuery();
    }
    catch (Exception &exc)
    {
      MessageDlg("?????? - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      Q->Transaction->Rollback();
      return;
    }
    Q->Transaction->Commit();
    }else
    { // ??????????? ?????? ???????
    Q->Close();
    Q->SQL->Clear();
    sql="update EXPENSES_TABLE set";
    sql+=" EXPENSE="+FloatToStr(ostperev);
    sql+=" where ID="+IntToStr(DS->FieldByName("EXP_ID")->AsInteger);
    Q->SQL->Add(sql);
    Q->Transaction->StartTransaction();
    try
    {
      Q->ExecQuery();
    }
    catch (Exception &exc)
    {
      MessageDlg("?????? - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      Q->Transaction->Rollback();
      return;
    }
    Q->Transaction->Commit();
    }
    }
    catch (Exception &exc)
    {
      MessageDlg("?????? - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      return;
    }

// ??? ??????

    sql="";
    DS->Close();
    DS->SQLs->SelectSQL->Clear();
    sql="select ";
    sql+="expenses_table.id exp_id ";
    sql+="from expenses_table ";
    sql+="where ";
    sql+=" expenses_table.gsm_id = 60";
    sql+=" and expenses_table.exp_date = '"+Date1Edit->Date.DateString()+" ' ";
    DS->SQLs->SelectSQL->Add(sql);
    try
    {
    DS->Open();
    if (DS->FieldByName("EXP_ID")->IsNull)
    {
      // ????????? ????? ???????
    Q->Close();
    Q->SQL->Clear();
    sql="select GEN_ID(GEN_EXPENSES_TABLE_ID,1) as ID from RDB$DATABASE";
    Q->SQL->Add(sql);
    Q->Transaction->StartTransaction();
    try
    {
      Q->ExecQuery();
    }
    catch (Exception &exc)
    { MessageDlg("?????? - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      Q->Transaction->Rollback();
      return;
    }
    if(Q->RecordCount==0)
    {
      MessageDlg("?????? ????????? ???????? ID ??????? EXPENSES_TABLE",mtError,TMsgDlgButtons() << mbOK,0);
      Q->Transaction->Rollback();
      return;
    }
    id=Q->FieldByName("ID")->AsInteger;

    Q->Close();
    Q->SQL->Clear();
    sql="insert into EXPENSES_TABLE(ID,EXP_DATE,SD_ID,DRIVER_ID,GSM_ID,KOL,EXPENSE,FLAG,EDITABLE,U_ID) values(";
    sql+=IntToStr(id)+",";
    sql+="'"+Date1Edit->Date.DateString()+"',";
    sql+=IntToStr(0)+",";
    sql+=IntToStr(0)+",";
    sql+=IntToStr(60)+",";
    sql+=IntToStr(0)+",";
    sql+=FloatToStr(ostpens)+",0,0,";
    sql+=IntToStr(GSM_DM->UserID)+")";
    Q->SQL->Add(sql);
    try
    {
      Q->ExecQuery();
    }
    catch (Exception &exc)
    {
      MessageDlg("?????? - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      Q->Transaction->Rollback();
      return;
    }
    Q->Transaction->Commit();
    }else
    { // ??????????? ?????? ???????
    Q->Close();
    Q->SQL->Clear();
    sql="update EXPENSES_TABLE set";
    sql+=" EXPENSE="+FloatToStr(ostpens);
    sql+=" where ID="+IntToStr(DS->FieldByName("EXP_ID")->AsInteger);
    Q->SQL->Add(sql);
    Q->Transaction->StartTransaction();
    try
    {
      Q->ExecQuery();
    }
    catch (Exception &exc)
    {
      MessageDlg("?????? - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      Q->Transaction->Rollback();
      return;
    }
    Q->Transaction->Commit();
    }
    }
    catch (Exception &exc)
    {
      MessageDlg("?????? - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      return;
    }

// ?????? ???

    sql="";
    DS->Close();
    DS->SQLs->SelectSQL->Clear();
    sql="select ";
    sql+="expenses_table.id exp_id ";
    sql+="from expenses_table ";
    sql+="where ";
    sql+=" expenses_table.gsm_id = 63";
    sql+=" and expenses_table.exp_date = '"+Date1Edit->Date.DateString()+" ' ";
    DS->SQLs->SelectSQL->Add(sql);
    try
    {
    DS->Open();
    if (DS->FieldByName("EXP_ID")->IsNull)
    {
      // ????????? ????? ???????
    Q->Close();
    Q->SQL->Clear();
    sql="select GEN_ID(GEN_EXPENSES_TABLE_ID,1) as ID from RDB$DATABASE";
    Q->SQL->Add(sql);
    Q->Transaction->StartTransaction();
    try
    {
      Q->ExecQuery();
    }
    catch (Exception &exc)
    { MessageDlg("?????? - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      Q->Transaction->Rollback();
      return;
    }
    if(Q->RecordCount==0)
    {
      MessageDlg("?????? ????????? ???????? ID ??????? EXPENSES_TABLE",mtError,TMsgDlgButtons() << mbOK,0);
      Q->Transaction->Rollback();
      return;
    }
    id=Q->FieldByName("ID")->AsInteger;

    Q->Close();
    Q->SQL->Clear();
    sql="insert into EXPENSES_TABLE(ID,EXP_DATE,SD_ID,DRIVER_ID,GSM_ID,KOL,EXPENSE,FLAG,EDITABLE,U_ID) values(";
    sql+=IntToStr(id)+",";
    sql+="'"+Date1Edit->Date.DateString()+"',";
    sql+=IntToStr(0)+",";
    sql+=IntToStr(0)+",";
    sql+=IntToStr(63)+",";
    sql+=IntToStr(0)+",";
    sql+=FloatToStr(ostredv)+",0,0,";
    sql+=IntToStr(GSM_DM->UserID)+")";
    Q->SQL->Add(sql);
    try
    {
      Q->ExecQuery();
    }
    catch (Exception &exc)
    {
      MessageDlg("?????? - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      Q->Transaction->Rollback();
      return;
    }
    Q->Transaction->Commit();
    }else
    { // ??????????? ?????? ???????
    Q->Close();
    Q->SQL->Clear();
    sql="update EXPENSES_TABLE set";
    sql+=" EXPENSE="+FloatToStr(ostredv);
    sql+=" where ID="+IntToStr(DS->FieldByName("EXP_ID")->AsInteger);
    Q->SQL->Add(sql);
    Q->Transaction->StartTransaction();
    try
    {
      Q->ExecQuery();
    }
    catch (Exception &exc)
    {
      MessageDlg("?????? - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      Q->Transaction->Rollback();
      return;
    }
    Q->Transaction->Commit();
    }
    }
    catch (Exception &exc)
    {
      MessageDlg("?????? - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      return;
    }

// ??????? ?????

    sql="";
    DS->Close();
    DS->SQLs->SelectSQL->Clear();
    sql="select ";
    sql+="expenses_table.id exp_id ";
    sql+="from expenses_table ";
    sql+="where ";
    sql+=" expenses_table.gsm_id = 64";
    sql+=" and expenses_table.exp_date = '"+Date1Edit->Date.DateString()+" ' ";
    DS->SQLs->SelectSQL->Add(sql);
    try
    {
    DS->Open();
    if (DS->FieldByName("EXP_ID")->IsNull)
    {
      // ????????? ????? ???????
    Q->Close();
    Q->SQL->Clear();
    sql="select GEN_ID(GEN_EXPENSES_TABLE_ID,1) as ID from RDB$DATABASE";
    Q->SQL->Add(sql);
    Q->Transaction->StartTransaction();
    try
    {
      Q->ExecQuery();
    }
    catch (Exception &exc)
    { MessageDlg("?????? - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      Q->Transaction->Rollback();
      return;
    }
    if(Q->RecordCount==0)
    {
      MessageDlg("?????? ????????? ???????? ID ??????? EXPENSES_TABLE",mtError,TMsgDlgButtons() << mbOK,0);
      Q->Transaction->Rollback();
      return;
    }
    id=Q->FieldByName("ID")->AsInteger;

    Q->Close();
    Q->SQL->Clear();
    sql="insert into EXPENSES_TABLE(ID,EXP_DATE,SD_ID,DRIVER_ID,GSM_ID,KOL,EXPENSE,FLAG,EDITABLE,U_ID) values(";
    sql+=IntToStr(id)+",";
    sql+="'"+Date1Edit->Date.DateString()+"',";
    sql+=IntToStr(0)+",";
    sql+=IntToStr(0)+",";
    sql+=IntToStr(64)+",";
    sql+=IntToStr(0)+",";
    sql+=FloatToStr(osttown)+",0,0,";
    sql+=IntToStr(GSM_DM->UserID)+")";
    Q->SQL->Add(sql);
    try
    {
      Q->ExecQuery();
    }
    catch (Exception &exc)
    {
      MessageDlg("?????? - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      Q->Transaction->Rollback();
      return;
    }
    Q->Transaction->Commit();
    }else
    { // ??????????? ?????? ???????
    Q->Close();
    Q->SQL->Clear();
    sql="update EXPENSES_TABLE set";
    sql+=" EXPENSE="+FloatToStr(osttown);
    sql+=" where ID="+IntToStr(DS->FieldByName("EXP_ID")->AsInteger);
    Q->SQL->Add(sql);
    Q->Transaction->StartTransaction();
    try
    {
      Q->ExecQuery();
    }
    catch (Exception &exc)
    {
      MessageDlg("?????? - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      Q->Transaction->Rollback();
      return;
    }
    Q->Transaction->Commit();
    }
    }
    catch (Exception &exc)
    {
      MessageDlg("?????? - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      return;
    }


// ??????? ??????? ???????

    sql="";
    DS->Close();
    DS->SQLs->SelectSQL->Clear();
    sql="select ";
    sql+="expenses_table.id exp_id ";
    sql+="from expenses_table ";
    sql+="where ";
    sql+=" expenses_table.gsm_id = 90";
    sql+=" and expenses_table.exp_date = '"+Date1Edit->Date.DateString()+" ' ";
    DS->SQLs->SelectSQL->Add(sql);
    try
    {
    DS->Open();
    if (DS->FieldByName("EXP_ID")->IsNull)
    {
      // ????????? ????? ???????
    Q->Close();
    Q->SQL->Clear();
    sql="select GEN_ID(GEN_EXPENSES_TABLE_ID,1) as ID from RDB$DATABASE";
    Q->SQL->Add(sql);
    Q->Transaction->StartTransaction();
    try
    {
      Q->ExecQuery();
    }
    catch (Exception &exc)
    { MessageDlg("?????? - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      Q->Transaction->Rollback();
      return;
    }
    if(Q->RecordCount==0)
    {
      MessageDlg("?????? ????????? ???????? ID ??????? EXPENSES_TABLE",mtError,TMsgDlgButtons() << mbOK,0);
      Q->Transaction->Rollback();
      return;
    }
    id=Q->FieldByName("ID")->AsInteger;

    Q->Close();
    Q->SQL->Clear();
    sql="insert into EXPENSES_TABLE(ID,EXP_DATE,SD_ID,DRIVER_ID,GSM_ID,KOL,EXPENSE,FLAG,EDITABLE,U_ID) values(";
    sql+=IntToStr(id)+",";
    sql+="'"+Date1Edit->Date.DateString()+"',";
    sql+=IntToStr(0)+",";
    sql+=IntToStr(0)+",";
    sql+=IntToStr(90)+",";
    sql+=IntToStr(0)+",";
    sql+=FloatToStr(ostgood)+",0,0,";
    sql+=IntToStr(GSM_DM->UserID)+")";
    Q->SQL->Add(sql);
    try
    {
      Q->ExecQuery();
    }
    catch (Exception &exc)
    {
      MessageDlg("?????? - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      Q->Transaction->Rollback();
      return;
    }
    Q->Transaction->Commit();
    }else
    { // ??????????? ?????? ???????
    Q->Close();
    Q->SQL->Clear();
    sql="update EXPENSES_TABLE set";
    sql+=" EXPENSE="+FloatToStr(ostgood);
    sql+=" where ID="+IntToStr(DS->FieldByName("EXP_ID")->AsInteger);
    Q->SQL->Add(sql);
    Q->Transaction->StartTransaction();
    try
    {
      Q->ExecQuery();
    }
    catch (Exception &exc)
    {
      MessageDlg("?????? - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      Q->Transaction->Rollback();
      return;
    }
    Q->Transaction->Commit();
    }
    }
    catch (Exception &exc)
    {
      MessageDlg("?????? - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      return;
    }

// ??????? ????????

    sql="";
    DS->Close();
    DS->SQLs->SelectSQL->Clear();
    sql="select ";
    sql+="expenses_table.id exp_id ";
    sql+="from expenses_table ";
    sql+="where ";
    sql+=" expenses_table.gsm_id = 95";
    sql+=" and expenses_table.exp_date = '"+Date1Edit->Date.DateString()+" ' ";
    DS->SQLs->SelectSQL->Add(sql);
    try
    {
    DS->Open();
    if (DS->FieldByName("EXP_ID")->IsNull)
    {
      // ????????? ????? ???????
    Q->Close();
    Q->SQL->Clear();
    sql="select GEN_ID(GEN_EXPENSES_TABLE_ID,1) as ID from RDB$DATABASE";
    Q->SQL->Add(sql);
    Q->Transaction->StartTransaction();
    try
    {
      Q->ExecQuery();
    }
    catch (Exception &exc)
    { MessageDlg("?????? - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      Q->Transaction->Rollback();
      return;
    }
    if(Q->RecordCount==0)
    {
      MessageDlg("?????? ????????? ???????? ID ??????? EXPENSES_TABLE",mtError,TMsgDlgButtons() << mbOK,0);
      Q->Transaction->Rollback();
      return;
    }
    id=Q->FieldByName("ID")->AsInteger;

    Q->Close();
    Q->SQL->Clear();
    sql="insert into EXPENSES_TABLE(ID,EXP_DATE,SD_ID,DRIVER_ID,GSM_ID,KOL,EXPENSE,FLAG,EDITABLE,U_ID) values(";
    sql+=IntToStr(id)+",";
    sql+="'"+Date1Edit->Date.DateString()+"',";
    sql+=IntToStr(0)+",";
    sql+=IntToStr(0)+",";
    sql+=IntToStr(95)+",";
    sql+=IntToStr(0)+",";
    sql+=FloatToStr(ostpodp)+",0,0,";
    sql+=IntToStr(GSM_DM->UserID)+")";
    Q->SQL->Add(sql);
    try
    {
      Q->ExecQuery();
    }
    catch (Exception &exc)
    {
      MessageDlg("?????? - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      Q->Transaction->Rollback();
      return;
    }
    Q->Transaction->Commit();
    }else
    { // ??????????? ?????? ???????
    Q->Close();
    Q->SQL->Clear();
    sql="update EXPENSES_TABLE set";
    sql+=" EXPENSE="+FloatToStr(ostpodp);
    sql+=" where ID="+IntToStr(DS->FieldByName("EXP_ID")->AsInteger);
    Q->SQL->Add(sql);
    Q->Transaction->StartTransaction();
    try
    {
      Q->ExecQuery();
    }
    catch (Exception &exc)
    {
      MessageDlg("?????? - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      Q->Transaction->Rollback();
      return;
    }
    Q->Transaction->Commit();
    }
    }
    catch (Exception &exc)
    {
      MessageDlg("?????? - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      return;
    }

    Q->Close();
    Q->SQL->Clear();
    sql="update EXPENSES_TABLE set";
    sql+=" EDITABLE = 0";
    sql+=" where expenses_table.exp_date = '"+Date1Edit->Date.DateString()+" ' ";
    Q->SQL->Add(sql);
    Q->Transaction->StartTransaction();
    try
    {
      Q->ExecQuery();
    }
    catch (Exception &exc)
    {
      MessageDlg("?????? - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      Q->Transaction->Rollback();
      return;
    }
    Q->Transaction->Commit();
    Q->Close();

DS->Close();


// ??????? ???????

    sql="";
    DS->Close();
    DS->SQLs->SelectSQL->Clear();
    sql="select ";
    sql+="expenses_table.id exp_id ";
    sql+="from expenses_table ";
    sql+="where ";
    sql+=" expenses_table.gsm_id = 102";
    sql+=" and expenses_table.exp_date = '"+Date1Edit->Date.DateString()+" ' ";
    DS->SQLs->SelectSQL->Add(sql);
    try
    {
    DS->Open();
    if (DS->FieldByName("EXP_ID")->IsNull)
    {
      // ????????? ????? ???????
    Q->Close();
    Q->SQL->Clear();
    sql="select GEN_ID(GEN_EXPENSES_TABLE_ID,1) as ID from RDB$DATABASE";
    Q->SQL->Add(sql);
    Q->Transaction->StartTransaction();
    try
    {
      Q->ExecQuery();
    }
    catch (Exception &exc)
    { MessageDlg("?????? - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      Q->Transaction->Rollback();
      return;
    }
    if(Q->RecordCount==0)
    {
      MessageDlg("?????? ????????? ???????? ID ??????? EXPENSES_TABLE",mtError,TMsgDlgButtons() << mbOK,0);
      Q->Transaction->Rollback();
      return;
    }
    id=Q->FieldByName("ID")->AsInteger;

    Q->Close();
    Q->SQL->Clear();
    sql="insert into EXPENSES_TABLE(ID,EXP_DATE,SD_ID,DRIVER_ID,GSM_ID,KOL,EXPENSE,FLAG,EDITABLE,U_ID) values(";
    sql+=IntToStr(id)+",";
    sql+="'"+Date1Edit->Date.DateString()+"',";
    sql+=IntToStr(0)+",";
    sql+=IntToStr(0)+",";
    sql+=IntToStr(102)+",";
    sql+=IntToStr(0)+",";
    sql+=FloatToStr(ostloto)+",0,0,";
    sql+=IntToStr(GSM_DM->UserID)+")";
    Q->SQL->Add(sql);
    try
    {
      Q->ExecQuery();
    }
    catch (Exception &exc)
    {
      MessageDlg("?????? - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      Q->Transaction->Rollback();
      return;
    }
    Q->Transaction->Commit();
    }else
    { // ??????????? ?????? ???????
    Q->Close();
    Q->SQL->Clear();
    sql="update EXPENSES_TABLE set";
    sql+=" EXPENSE="+FloatToStr(ostloto);
    sql+=" where ID="+IntToStr(DS->FieldByName("EXP_ID")->AsInteger);
    Q->SQL->Add(sql);
    Q->Transaction->StartTransaction();
    try
    {
      Q->ExecQuery();
    }
    catch (Exception &exc)
    {
      MessageDlg("?????? - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      Q->Transaction->Rollback();
      return;
    }
    Q->Transaction->Commit();
    }
    }
    catch (Exception &exc)
    {
      MessageDlg("?????? - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      return;
    }

    Q->Close();
    Q->SQL->Clear();
    sql="update EXPENSES_TABLE set";
    sql+=" EDITABLE = 0";
    sql+=" where expenses_table.exp_date = '"+Date1Edit->Date.DateString()+" ' ";
    Q->SQL->Add(sql);
    Q->Transaction->StartTransaction();
    try
    {
      Q->ExecQuery();
    }
    catch (Exception &exc)
    {
      MessageDlg("?????? - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      Q->Transaction->Rollback();
      return;
    }
    Q->Transaction->Commit();
    Q->Close();

// ??????? ???????????

    sql="";
    DS->Close();
    DS->SQLs->SelectSQL->Clear();
    sql="select ";
    sql+="expenses_table.id exp_id ";
    sql+="from expenses_table ";
    sql+="where ";
    sql+=" expenses_table.gsm_id = 107";
    sql+=" and expenses_table.exp_date = '"+Date1Edit->Date.DateString()+" ' ";
    DS->SQLs->SelectSQL->Add(sql);
    try
    {
    DS->Open();
    if (DS->FieldByName("EXP_ID")->IsNull)
    {
      // ????????? ????? ???????
    Q->Close();
    Q->SQL->Clear();
    sql="select GEN_ID(GEN_EXPENSES_TABLE_ID,1) as ID from RDB$DATABASE";
    Q->SQL->Add(sql);
    Q->Transaction->StartTransaction();
    try
    {
      Q->ExecQuery();
    }
    catch (Exception &exc)
    { MessageDlg("?????? - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      Q->Transaction->Rollback();
      return;
    }
    if(Q->RecordCount==0)
    {
      MessageDlg("?????? ????????? ???????? ID ??????? EXPENSES_TABLE",mtError,TMsgDlgButtons() << mbOK,0);
      Q->Transaction->Rollback();
      return;
    }
    id=Q->FieldByName("ID")->AsInteger;

    Q->Close();
    Q->SQL->Clear();
    sql="insert into EXPENSES_TABLE(ID,EXP_DATE,SD_ID,DRIVER_ID,GSM_ID,KOL,EXPENSE,FLAG,EDITABLE,U_ID) values(";
    sql+=IntToStr(id)+",";
    sql+="'"+Date1Edit->Date.DateString()+"',";
    sql+=IntToStr(0)+",";
    sql+=IntToStr(0)+",";
    sql+=IntToStr(107)+",";
    sql+=IntToStr(0)+",";
    sql+=FloatToStr(oststrah)+",0,0,";
    sql+=IntToStr(GSM_DM->UserID)+")";
    Q->SQL->Add(sql);
    try
    {
      Q->ExecQuery();
    }
    catch (Exception &exc)
    {
      MessageDlg("?????? - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      Q->Transaction->Rollback();
      return;
    }
    Q->Transaction->Commit();
    }else
    { // ??????????? ?????? ???????
    Q->Close();
    Q->SQL->Clear();
    sql="update EXPENSES_TABLE set";
    sql+=" EXPENSE="+FloatToStr(oststrah);
    sql+=" where ID="+IntToStr(DS->FieldByName("EXP_ID")->AsInteger);
    Q->SQL->Add(sql);
    Q->Transaction->StartTransaction();
    try
    {
      Q->ExecQuery();
    }
    catch (Exception &exc)
    {
      MessageDlg("?????? - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      Q->Transaction->Rollback();
      return;
    }
    Q->Transaction->Commit();
    }
    }
    catch (Exception &exc)
    {
      MessageDlg("?????? - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      return;
    }

    Q->Close();
    Q->SQL->Clear();
    sql="update EXPENSES_TABLE set";
    sql+=" EDITABLE = 0";
    sql+=" where expenses_table.exp_date = '"+Date1Edit->Date.DateString()+" ' ";
    Q->SQL->Add(sql);
    Q->Transaction->StartTransaction();
    try
    {
      Q->ExecQuery();
    }
    catch (Exception &exc)
    {
      MessageDlg("?????? - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      Q->Transaction->Rollback();
      return;
    }
    Q->Transaction->Commit();
    Q->Close();


DS->Close();

if (fo.Trim()!="F"){
editF130File(val1,val2,val3,val4,val5,val6,val7,val8,val9,val10,val11,val12,val13,val14,val15,val16,val17,val18,val19,val20,val21,val22,val23,val24,val25,val26,val27,val28,val29,val30,val31,val32,val33,val34,val35,val37,val38,val39,val40,val41,val42,val43,fo);
ShellExecute(Handle,"open",fo.c_str(),NULL,Folder.c_str(),SW_RESTORE);
}

}
//---------------------------------------------------------------------------

void __fastcall TExpensesListOnDateForm::Date1EditChange(TObject *Sender)
{

AnsiString sql,s;
unsigned short y,m,dv,ym,mm,dm;
int m1,m2,d1,d2,y1,y2;

m1=nummonthOfDate(Date());
m2=nummonthOfDate(Date1Edit->Date);
d1=dayOfDate(Date());
d2=dayOfDate(Date1Edit->Date);
y1=yearOfDate(Date());
y2=yearOfDate(Date1Edit->Date);

    sql="";
    DS->Close();
    DS->SQLs->SelectSQL->Clear();
    sql="select ";
    sql+="min( expenses_table.exp_date ) min_of_date ";
    sql+="from expenses_table ";
    sql+="left outer join oper_table on (expenses_table.gsm_id = oper_table.id) ";
    sql+="where ";
    sql+=" oper_table.file_id = 48";
    sql+=" and oper_table.visible = 1";
    DS->SQLs->SelectSQL->Add(sql);
    try
    {
      DS->Open();
      datemin=DS->FieldByName("MIN_OF_DATE")->AsDateTime;
      datemin.DecodeDate(&ym,&mm,&dm);
      s=AnsiString().sprintf("%02d-%02d-%d",dm,mm,ym);
      Edit3->Text=s.c_str();
    }
    catch (Exception &exc)
    {
      MessageDlg("?????? - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      return;
    }


if (Date1Edit->Date > Date() || Date1Edit->Date <= datemin)
{
//    MessageDlg("?? ????? ??????? ???? !!! ??? ???????? ?????? ??? ??????????? !!!",mtWarning,TMsgDlgButtons() << mbOK,0);
    Date1Edit->Date=Date();
//    Date1Edit->SetFocus();
    return;
}else
{

    sql="";
    DS->Close();
    DS->SQLs->SelectSQL->Clear();
    sql="select ";
    sql+="max( expenses_table.exp_date ) max_of_date ";
    sql+="from expenses_table ";
    sql+="left outer join oper_table on (expenses_table.gsm_id = oper_table.id) ";
    sql+="where ";
    sql+=" oper_table.file_id = 48";
    sql+=" and oper_table.visible = 1";
    sql+=" and expenses_table.exp_date < '"+Date1Edit->Date.DateString()+" ' ";
    DS->SQLs->SelectSQL->Add(sql);
    try
    {
      DS->Open();
      date=DS->FieldByName("MAX_OF_DATE")->AsDateTime;
      date.DecodeDate(&y,&m,&dv);
      s=AnsiString().sprintf("%02d-%02d-%d",dv,m,y);
      Edit1->Text=s.c_str();
      Edit4->Text=Date1Edit->Date.DateString();
    }
    catch (Exception &exc)
    {
      MessageDlg("?????? - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      return;
    }


    sql="";
    DS->Close();
    DS->SQLs->SelectSQL->Clear();
    sql="select ";
    sql+="sum(expenses_table.expense) sum_of_exp ";
    sql+="from expenses_table ";
    sql+="left outer join oper_table on (expenses_table.gsm_id = oper_table.id) ";
    sql+="where ";
    sql+=" oper_table.file_id = 48";
    sql+=" and oper_table.visible = 1";
    sql+=" and expenses_table.exp_date = '"+date.DateString()+" ' ";

    DS->SQLs->SelectSQL->Add(sql);
    try
    {
      DS->Open();
      s=AnsiString().sprintf("%.02lf",DS->FieldByName("SUM_OF_EXP")->AsFloat);
      ost1=DS->FieldByName("SUM_OF_EXP")->AsFloat;
      Edit2->Text=s.c_str();
    }
    catch (Exception &exc)
    {
      MessageDlg("?????? - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      return;
    }

    sql="";
    DS->Close();
    DS->SQLs->SelectSQL->Clear();
    sql="select ";
    sql+="sum(expenses_table.expense) sum_of_exp ";
    sql+="from expenses_table ";
    sql+="left outer join oper_table on (expenses_table.gsm_id = oper_table.id) ";
    sql+="where ";
    sql+=" oper_table.id = 60";
    sql+=" and oper_table.visible = 1";
    sql+=" and expenses_table.exp_date = '"+date.DateString()+" ' ";

    DS->SQLs->SelectSQL->Add(sql);
    try
    {
      DS->Open();
      s=AnsiString().sprintf("%.02lf",DS->FieldByName("SUM_OF_EXP")->AsFloat);
      ost2=DS->FieldByName("SUM_OF_EXP")->AsFloat;
      Edit5->Text=s.c_str();
    }
    catch (Exception &exc)
    {
      MessageDlg("?????? - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      return;
    }

    sql="";
    DS->Close();
    DS->SQLs->SelectSQL->Clear();
    sql="select ";
    sql+="sum(expenses_table.expense) sum_of_exp ";
    sql+="from expenses_table ";
    sql+="left outer join oper_table on (expenses_table.gsm_id = oper_table.id) ";
    sql+="where ";
    sql+=" oper_table.id IN (59,63)";
    sql+=" and oper_table.visible = 1";
    sql+=" and expenses_table.exp_date = '"+date.DateString()+" ' ";

    DS->SQLs->SelectSQL->Add(sql);
    try
    {
      DS->Open();
      s=AnsiString().sprintf("%.02lf",DS->FieldByName("SUM_OF_EXP")->AsFloat);
      ost3=DS->FieldByName("SUM_OF_EXP")->AsFloat;
      Edit6->Text=s.c_str();
    }
    catch (Exception &exc)
    {
      MessageDlg("?????? - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      return;
    }

    sql="";
    DS->Close();
    DS->SQLs->SelectSQL->Clear();
    sql="select ";
    sql+="sum(expenses_table.expense) sum_of_exp ";
    sql+="from expenses_table ";
    sql+="left outer join oper_table on (expenses_table.gsm_id = oper_table.id) ";
    sql+="where ";
    sql+=" oper_table.id IN (64)";
    sql+=" and oper_table.visible = 1";
    sql+=" and expenses_table.exp_date = '"+date.DateString()+" ' ";

    DS->SQLs->SelectSQL->Add(sql);
    try
    {
      DS->Open();
      s=AnsiString().sprintf("%.02lf",DS->FieldByName("SUM_OF_EXP")->AsFloat);
      ost7=DS->FieldByName("SUM_OF_EXP")->AsFloat;
      Edit7->Text=s.c_str();
    }
    catch (Exception &exc)
    {
      MessageDlg("?????? - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      return;
    }

    sql="";
    DS->Close();
    DS->SQLs->SelectSQL->Clear();
    sql="select ";
    sql+="sum(expenses_table.expense) sum_of_exp ";
    sql+="from expenses_table ";
    sql+="left outer join oper_table on (expenses_table.gsm_id = oper_table.id) ";
    sql+="where ";
    sql+=" oper_table.id =81";
    sql+=" and oper_table.visible = 1";
    sql+=" and expenses_table.exp_date = '"+date.DateString()+" ' ";

    DS->SQLs->SelectSQL->Add(sql);
    try
    {
      DS->Open();
      s=AnsiString().sprintf("%.02lf",DS->FieldByName("SUM_OF_EXP")->AsFloat);
      ost5=DS->FieldByName("SUM_OF_EXP")->AsFloat;
      Edit8->Text=s.c_str();
    }
    catch (Exception &exc)
    {
      MessageDlg("?????? - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      return;
    }

    sql="";
    DS->Close();
    DS->SQLs->SelectSQL->Clear();
    sql="select ";
    sql+="sum(expenses_table.expense) sum_of_exp ";
    sql+="from expenses_table ";
    sql+="left outer join oper_table on (expenses_table.gsm_id = oper_table.id) ";
    sql+="where ";
    sql+=" oper_table.id = 90";
    sql+=" and oper_table.visible = 1";
    sql+=" and expenses_table.exp_date = '"+date.DateString()+" ' ";

    DS->SQLs->SelectSQL->Add(sql);
    try
    {
      DS->Open();
      s=AnsiString().sprintf("%.02lf",DS->FieldByName("SUM_OF_EXP")->AsFloat);
      ost8=DS->FieldByName("SUM_OF_EXP")->AsFloat;
      Edit9->Text=s.c_str();
    }
    catch (Exception &exc)
    {
      MessageDlg("?????? - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      return;
    }

    sql="";
    DS->Close();
    DS->SQLs->SelectSQL->Clear();
    sql="select ";
    sql+="sum(expenses_table.expense) sum_of_exp ";
    sql+="from expenses_table ";
    sql+="left outer join oper_table on (expenses_table.gsm_id = oper_table.id) ";
    sql+="where ";
    sql+=" oper_table.id = 95";
    sql+=" and oper_table.visible = 1";
    sql+=" and expenses_table.exp_date = '"+date.DateString()+" ' ";

    DS->SQLs->SelectSQL->Add(sql);
    try
    {
      DS->Open();
      s=AnsiString().sprintf("%.02lf",DS->FieldByName("SUM_OF_EXP")->AsFloat);
      ost9=DS->FieldByName("SUM_OF_EXP")->AsFloat;
      Edit10->Text=s.c_str();
    }
    catch (Exception &exc)
    {
      MessageDlg("?????? - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      return;
    }


    sql="";
    DS->Close();
    DS->SQLs->SelectSQL->Clear();
    sql="select ";
    sql+="sum(expenses_table.expense) sum_of_exp ";
    sql+="from expenses_table ";
    sql+="left outer join oper_table on (expenses_table.gsm_id = oper_table.id) ";
    sql+="where ";
    sql+=" oper_table.id = 102";
    sql+=" and oper_table.visible = 1";
    sql+=" and expenses_table.exp_date = '"+date.DateString()+" ' ";

    DS->SQLs->SelectSQL->Add(sql);
    try
    {
      DS->Open();
      s=AnsiString().sprintf("%.02lf",DS->FieldByName("SUM_OF_EXP")->AsFloat);
      ost10=DS->FieldByName("SUM_OF_EXP")->AsFloat;
      Edit11->Text=s.c_str();
    }
    catch (Exception &exc)
    {
      MessageDlg("?????? - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      return;
    }


    sql="";
    DS->Close();
    DS->SQLs->SelectSQL->Clear();
    sql="select ";
    sql+="sum(expenses_table.expense) sum_of_exp ";
    sql+="from expenses_table ";
    sql+="left outer join oper_table on (expenses_table.gsm_id = oper_table.id) ";
    sql+="where ";
    sql+=" oper_table.id = 107";
    sql+=" and oper_table.visible = 1";
    sql+=" and expenses_table.exp_date = '"+date.DateString()+" ' ";

    DS->SQLs->SelectSQL->Add(sql);
    try
    {
      DS->Open();
      s=AnsiString().sprintf("%.02lf",DS->FieldByName("SUM_OF_EXP")->AsFloat);
      ost11=DS->FieldByName("SUM_OF_EXP")->AsFloat;
      Edit12->Text=s.c_str();
    }
    catch (Exception &exc)
    {
      MessageDlg("?????? - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      return;
    }


  Edit4->Text=Date1Edit->Date.DateString();
//  Date1Edit->SetFocus();
}
}
//---------------------------------------------------------------------------



void __fastcall TExpensesListOnDateForm::RzBitBtn1Click(TObject *Sender)
{
/*
AnsiString sql,s;
TDate curdate,lastdate,firstdate,datecur;
int maxcicle =0;
int k;

curdate=Date();

    sql="";
    DS->Close();
    DS->SQLs->SelectSQL->Clear();
    sql="select ";
    sql+="max( expenses_table.exp_date ) max_of_date ";
    sql+="from expenses_table ";
    sql+="left outer join oper_table on (expenses_table.gsm_id = oper_table.id) ";
    sql+="where ";
    sql+=" oper_table.file_id = 48";
    sql+=" and oper_table.visible = 1";
    sql+=" and expenses_table.exp_date <= '"+curdate.DateString()+" ' ";
    DS->SQLs->SelectSQL->Add(sql);
    try
    {
      DS->Open();
      lastdate=DS->FieldByName("MAX_OF_DATE")->AsDateTime;
    }
    catch (Exception &exc)
    {
      MessageDlg("?????? - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      return;
    }

    sql="";
    DS->Close();
    DS->SQLs->SelectSQL->Clear();
    sql="select ";
    sql+="max( expenses_table.exp_date ) max_of_date ";
    sql+="from expenses_table ";
    sql+="left outer join oper_table on (expenses_table.gsm_id = oper_table.id) ";
    sql+="where ";
    sql+=" oper_table.file_id = 48";
    sql+=" and oper_table.visible = 1";
    sql+=" and expenses_table.exp_date <= '"+Date1Edit->Date.DateString()+" ' ";
    DS->SQLs->SelectSQL->Add(sql);
    try
    {
      DS->Open();
      firstdate=DS->FieldByName("MAX_OF_DATE")->AsDateTime;
    }
    catch (Exception &exc)
    {
      MessageDlg("?????? - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      return;
    }

maxcicle=diffOfDays(lastdate,Date1Edit->Date);

if (maxcicle > 0)
{
Indicator->Visible = true;
Indicator->MinValue=1;
Indicator->MaxValue=maxcicle;
k=1;
datecur=Date1Edit->Date;
for (int i=1;i<maxcicle+2;i++)
{
// ????? ?????? ?????????? ?? ????
int prov = dayOfDate(datecur);
RashetF130(datecur);
k++;
datecur++;
Indicator->Progress = k;
}
Indicator->Visible = false;
}
else
{
    MessageDlg("?????????? ?? ????? !!! ",mtWarning,TMsgDlgButtons() << mbOK,0);
    return;
}
*/
}
//---------------------------------------------------------------------------

void __fastcall TExpensesListOnDateForm::RashetF130(TDate date)
{
}



