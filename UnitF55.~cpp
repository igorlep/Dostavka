//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UnitF55.h"
#include "DataModule.h"
#include "SomeFunctions.h"
#include "Main.h"
#include "DirectWorkExcel.h"
#include "DifferentFunctions.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "RzPanel"
#pragma link "RzRadGrp"
#pragma link "ToolEdit"
#pragma link "FIBDataSet"
#pragma link "pFIBDataSet"
#pragma link "Placemnt"
#pragma link "CGAUGES"
#pragma resource "*.dfm"
TFormF55 *FormF55;
//---------------------------------------------------------------------------
__fastcall TFormF55::TFormF55(TComponent* Owner)
        : TForm(Owner)
{
TIniFile* ini;

  workDir=ExtractFilePath(Application->ExeName);
  FormStorage->IniFileName=workDir+"AccountGSM.ini";
  FormStorage->IniSection="ExpensesListOnAutoForm55";

  ini=new TIniFile(workDir+"AccountGSM.ini");
  Date1Edit->Date=ini->ReadDate("ExpensesListOnAutoForm55","Date1",Date());
  delete ini;

}
//---------------------------------------------------------------------------
void __fastcall TFormF55::FormDestroy(TObject *Sender)
{
TIniFile* ini;

  ini=new TIniFile(workDir+"AccountGSM.ini");
  ini->WriteDate("ExpensesListOnAutoForm55","Date1",Date1Edit->Date);
  delete ini;
}
//---------------------------------------------------------------------------
void __fastcall TFormF55::SaveButtonClick(TObject *Sender)
{
AnsiString sql,fo,fio,fileIn,s;
AnsiString Folder=getWorkDir()+"OUT\\";
int k=0;
AnsiString Value[50];
AnsiString IndVyb="'";
AnsiString fileOut;
unsigned short y,m,d1;
DirectWorkExcel *de;
AnsiString fout;
int numrow;
double IValueS;
int IValueK;
int nn=5;
TDateTime date;


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
  date=Date1Edit->Date;
  fileIn=getWorkDir()+"Template\\f55_ved.xlsx";
  fileOut=getWorkDir()+"OUT\\";
  date.DecodeDate(&y,&m,&d1);
  s=AnsiString().sprintf("%02d-%02d-%d",d1,m,y);
  fileOut+="f55vedfor";
  fout+="f55vedfor";
  fileOut+=s+".xlsx";
  fout+=s+".xlsx";
  if(FileExists(fileOut)) DeleteFile(fileOut);
  //Копируем шаблон
  if(templateCopy(fileIn,fileOut)== false)
  {
    MessageDlg("Ошибка копирования!!! ",mtWarning,TMsgDlgButtons() << mbOK,0);
    return;
  }

sql="";
    DS1->Close();
    DS1->SQLs->SelectSQL->Clear();
    sql="select sum(e.EXPENSE) as EXP_SUM,sum(e.KOL) as KOL_SUM ";
    sql+=" from EXPENSES_TABLE e";
    sql+=" left outer join OPS_TABLE d on d.ID=e.DRIVER_ID";
    sql+=" left outer join OPS_TABLE sd on sd.ID=e.SD_ID";
    sql+=" left outer join OPER_TABLE m on m.ID=e.GSM_ID";
    sql+=" where e.EXP_DATE = '"+Date1Edit->Date.DateString()+"'";
    sql+=" and m.FILE_ID= 33";
    sql+=" and m.ID IN (3,6,17)";
    sql+=" and m.VISIBLE=1";
    if (CheckBox1->Checked) sql+=" and e.d= 1";
    if (CheckBox3->Checked)  sql+=" and d.DESCRIPTION IN ("+IndVyb.Trim()+ ")";
    if (GSM_DM->UserRole!="администратор" && GSM_DM->UserRole!="руководитель")
    {
     if (!CheckBox2->Checked) sql+=" and e.u_id="+IntToStr(GSM_DM->UserID);
    }
    sql+=" and sd.VISIBLE=1";
    sql+=" and e.FLAG=1";
    DS1->SQLs->SelectSQL->Add(sql);
    try
    {
      DS1->Open();
      IValueS=DS1->FieldByName("EXP_SUM")->AsFloat;
      IValueK=DS1->FieldByName("KOL_SUM")->AsInteger;
      if(IValueK==0)
       {
        MessageDlg("Нет данных для формирования формы 55. Формирования отчетов прервано!!! ",mtWarning,TMsgDlgButtons() << mbOK,0);
        return;
       }
    }
        catch (Exception &exc)
    {
      MessageDlg("Ошибка - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      return;
    }


sql="";

    DS1->Close();
    DS1->SQLs->SelectSQL->Clear();
    sql="select distinct ops_table.id as idp , ops_table.description as fio from ops_table where  ops_table.file_id=1 and ops_table.rec_type=0 and ops_table.id <>8 ";
    DS1->SQLs->SelectSQL->Add(sql);
    try
    {
      DS1->Open();
    }
        catch (Exception &exc)
    {
      MessageDlg("Ошибка - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      return;
    }

    Indicator->Visible = true;
    Indicator->MinValue=0;
    DS1->Last();
    Indicator->MaxValue=DS1->RecordCount;
    Label1->Caption="";
    int iw=0;

    // ОПС
DS1->First();
while (!DS1->Eof)
{
    fio=DS1->FieldByName("fio")->AsString;
    Label1->Caption="Сбор информаций по почтальону " + fio.Trim();
    Label1->Refresh();


    DS->Close();
    DS->SQLs->SelectSQL->Clear();
    sql="select sum(e.EXPENSE) as EXP_SUM,sum(e.KOL) as KOL_SUM";
    sql+=" from EXPENSES_TABLE e";
    sql+=" left outer join OPS_TABLE d on d.ID=e.DRIVER_ID";
    sql+=" left outer join OPS_TABLE sd on sd.ID=e.SD_ID";
    sql+=" left outer join OPER_TABLE m on m.ID=e.GSM_ID";
    sql+=" where e.EXP_DATE = '"+Date1Edit->Date.DateString()+"'";
    sql+=" and e.SD_ID="+IntToStr(DS1->FieldByName("IDP")->AsInteger);
    sql+=" and m.FILE_ID= 33";
    sql+=" and m.ID IN (3,6,17)";
    sql+=" and m.VISIBLE=1";
    if (CheckBox1->Checked) sql+=" and e.d= 1";
    if (CheckBox3->Checked)  sql+=" and d.DESCRIPTION IN ("+IndVyb.Trim()+ ")";
    if (GSM_DM->UserRole!="администратор" && GSM_DM->UserRole!="руководитель")
    {
     if (!CheckBox2->Checked) sql+=" and e.u_id="+IntToStr(GSM_DM->UserID);
    }
    sql+=" and sd.VISIBLE=1";
    sql+=" and e.FLAG=1";
    DS->SQLs->SelectSQL->Add(sql);
    try
    {
      DS->Open();
      numrow=createF55vedFile(DS,Date1Edit->Date,fileOut,fio,nn);
      nn=numrow;
    }
        catch (Exception &exc)
    { MessageDlg("Ошибка - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      return;
    }
  Indicator->Progress = iw;
  iw++;
  DS1->Next();
}

Indicator->Visible = false;
Label1->Caption="";

  //Создаем Excel файл
  try
  {
    de=new DirectWorkExcel(fileOut,1);
  }
  catch(const Exception &exc)
  { MessageDlg("Ошибка создания объекта DirectWorkExcel\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
    return;
  }
  if(de->openFile(false)==false)
  {
    MessageDlg("Ошибка открытия Excel файла",mtWarning,TMsgDlgButtons() << mbOK,0);
    if(de!=NULL) delete de;
    return;
  }

  de->setSheetNumber(1);

  AnsiString ITOGOPropis1="Всего " + IntToStr(IValueK) + " поручений  на сумму " + f_to_str(floor(IValueS*100+0.5)/100);
  AnsiString ITOGOPropis2="Всего " + IntToStr(IValueK) + " поручений  на сумму " + AnsiString().sprintf("%.02lf",IValueS) + " руб. ";;

  de->setCellValue(763,"B",ITOGOPropis1.Trim());
  de->setCellValue(762,"B",ITOGOPropis2.Trim());
  de->deleteRange(IntToStr(nn),IntToStr(761));

 //Закрываем файл
  de->closeFile();
  delete de;
  DS->Close();
  DS1->Close();

ShellExecute(Handle,"open",fileOut.c_str(),NULL,Folder.c_str(),SW_RESTORE);

}
//---------------------------------------------------------------------------

void __fastcall TFormF55::p(void)
{
AnsiString sql;
TpFIBDataSet *rDS=GSM_DM->RDS;
int i;

  rDS->Close();
  rDS->SQLs->SelectSQL->Clear();
    sql="select count(e.ID) as C_ID";
    sql+=" from EXPENSES_TABLE e";
//    sql+=" left outer join OPS_TABLE sd on sd.ID=e.SD_ID";
//    sql+=" left outer join OPS_TABLE d on d.ID=e.DRIVER_ID";
    sql+=" left outer join OPER_TABLE m on m.ID=e.GSM_ID";
    sql+=" where e.EXP_DATE = '"+Date1Edit->Date.DateString()+"'";
//    sql+=" and e.SD_ID="+autoID->Strings[index];
    if (GSM_DM->UserRole!="администратор" && GSM_DM->UserRole!="руководитель")
    {
     sql+=" and e.u_id="+IntToStr(GSM_DM->UserID);
    }
    sql+=" and e.d= 1";
    sql+=" and m.FILE_ID= 33";
    sql+=" and m.VISIBLE=1";
//    sql+=" and sd.VISIBLE=1";
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
  CheckBox1->Visible=true;
  }else
  {
  Label4->Visible=false;
  CheckBox1->Visible=false;
  }
  rDS->Close();
  CheckBox3->Visible=true;
  this->ClientHeight=145;
}

void __fastcall TFormF55::Date1EditChange(TObject *Sender)
{
AnsiString sql;
TpFIBDataSet *rDS=GSM_DM->RDS;
int i;

  // формирование списка ОПС
  CheckGroup2->Items->Clear();
  rDS->Close();
  rDS->SQLs->SelectSQL->Clear();
  sql="";
  sql="select distinct DESCRIPTION as SD_NAME from OPS_TABLE where REC_TYPE=1 and VISIBLE = 1 ";
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
  SaveButton->Enabled=true;
  if (CheckBox3->Checked){
  CheckGroup2->Visible=true;
  this->ClientHeight=670;
  }else{
  CheckGroup2->Visible=false;
  this->ClientHeight=245;
  }
  p();
}
//---------------------------------------------------------------------------

void __fastcall TFormF55::CheckBox3Click(TObject *Sender)
{
if (CheckBox3->Checked){
CheckGroup2->Visible=true;
this->ClientHeight=670;
}else{
CheckGroup2->Visible=false;
this->ClientHeight=245;
}
}
//---------------------------------------------------------------------------

void __fastcall TFormF55::FormShow(TObject *Sender)
{
CheckBox3->Visible=true;
CheckBox2->Visible=true;
CheckGroup2->Visible=false;
this->ClientHeight=245;
}
//---------------------------------------------------------------------------


