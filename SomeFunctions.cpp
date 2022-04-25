//Набор специальных фукций для работы с программой
//---------------------------------------------------------------------------
#include <math.h>
#include <vcl.h>
//#include <Controls.hpp>
#pragma hdrstop
#include "DirectWorkExcel.h"
#include "Main.h"
#include "DifferentFunctions.h"
#include "SomeFunctions.h"
#include "ExpensesListOnAuto.h"
#include <ShellAPI.h>
#include "Propis.h"
#include <stdio.h>
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include "DataModule.h"


//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "DBGridEh"
//---------------------------------------------------------------------------
AnsiString __fastcall getWorkDir(void)
{
AnsiString wd=ExtractFilePath(Application->ExeName);
return wd;
}
//---------------------------------------------------------------------------

//Функция копирования шаблона
bool __fastcall templateCopy(AnsiString fileIn, AnsiString fileOut)
{
int fin, fout;

  if(FileExists(fileOut)) return false;
  fin=FileOpen(fileIn,fmOpenRead);
  if(fin < 0)
  { MessageDlg("Ошибка открытия файла - "+fileIn,mtError,TMsgDlgButtons() << mbOK,0);
    return false;
  }
  fout=FileCreate(fileOut);
  if(fout < 0)
  { MessageDlg("Ошибка копирования шаблона файла "+fileOut,mtError,TMsgDlgButtons() << mbOK,0);
    FileClose(fin);
    return false;
  }
  int len=FileSeek(fin,0,2);
  FileSeek(fin,0,0);
  char *buf;
  buf=new char[len+1];
  int readLen=FileRead(fin,buf,len);
  FileClose(fin);
  FileWrite(fout,buf,readLen);
  FileClose(fout);
  delete []buf;
  int attrs=FileGetAttr(fileOut);
  if(attrs & faReadOnly)
  FileSetAttr(fileOut, attrs & !faReadOnly);
  return true;
}
//---------------------------------------------------------------------------

//Функция формирования файла с формой Ф55
AnsiString __fastcall createF55File(TDataSet *DS,TDataSet *DS1,AnsiString FIO,TDate date)
{
AnsiString fileIn,s,k,itogsum;
Double ValueS,RasS,NeoplS;
int ValueK,RasK,NeoplK;
AnsiString fileOut;
unsigned short y,m,d1;
DirectWorkExcel *de;
AnsiString fout;
int i=1;
int ns=9;
Double P1,P2;
AnsiString fiokass;
TIniFile* ini;
AnsiString workDir;
AnsiString iniFileName;


  workDir=ExtractFilePath(Application->ExeName);
  iniFileName=workDir+"AccountGSM.ini";
  ini=new TIniFile(iniFileName);
  fiokass = ini->ReadString("Parametr","tel","");
  delete ini;


  P1=950000.00;
  P2=900000.00;
  fileIn=getWorkDir()+"Template\\f55.xlsx";
  ValueS=DS->FieldByName("EXP_SUM")->AsFloat;
  ValueK=DS->FieldByName("KOL_SUM")->AsInteger;
  RasS=DS1->FieldByName("EXP_SUM")->AsFloat;
  RasK=DS1->FieldByName("KOL_SUM")->AsInteger;
  NeoplS=ValueS-RasS;
  NeoplK=ValueK-RasK;
  if (ValueK==0)
  {
  MessageDlg("Нет данных для формирования формы 55. Формирования отчетов прервано!!! ",mtWarning,TMsgDlgButtons() << mbOK,0);
  return "F";
  }

  fileOut=getWorkDir()+"OUT\\";
  date.DecodeDate(&y,&m,&d1);
  s=AnsiString().sprintf("%02d-%02d-%d",d1,m,y);
  fileOut+="f55for";
  fout+="f55for";
  fileOut+=FIO;
  fout+=FIO;
  fileOut+=s+".xlsx";
  fout+=s+".xlsx";
  if(FileExists(fileOut)) DeleteFile(fileOut);
  //Копируем шаблон
  if(templateCopy(fileIn,fileOut)== false) return "F";

  //Создаем Excel файл
  try
  {
    de=new DirectWorkExcel(fileOut,1);
  }
  catch(const Exception &exc)
  { MessageDlg("Ошибка создания объекта DirectWorkExcel\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
    return "";
  }
  if(de->openFile(false)==false)
  {
    MessageDlg("Ошибка открытия Excel файла",mtWarning,TMsgDlgButtons() << mbOK,0);
    if(de!=NULL) delete de;
    return "F";
  }

  de->setSheetNumber(1);
  de->setCellValue(2,"B",FIO.Trim());
  de->setCellValue(85,"B",AnsiString().sprintf("%.02lf",ValueS));
  de->setCellValue(86,"A",f_to_str(ValueS));
//  de->setCellValue(90,"D",fiokass.Trim());
  de->setCellValue(90,"D",GSM_DM->UserLogin.Trim());

  if (ValueS<=950000.00)
  {
     P1=ValueS;
     de->setCellValue(ns,"B",FIO.Trim());
     de->setCellValue(ns,"A",date.DateString());
     AnsiString KolPropis=i_to_str(ValueK) + " поручений ";
     de->setCellValue(10,"D",KolPropis);
     k=IntToStr(DS->FieldByName("KOL_SUM")->AsInteger)+ " поручений ";
     de->setCellValue(10,"B",k);
     de->setCellValue(12,"B",AnsiString().sprintf("%.02lf",P1));
     de->setCellValue(12,"D",f_to_str(floor(P1*100+0.5)/100));
     ValueS=ValueS-950000.00;
  }else{
  while (ValueS>900000.00)
  {
    if (i==1)
    {
     de->setCellValue(ns,"B",FIO.Trim());
     de->setCellValue(ns,"A",date.DateString());
     AnsiString KolPropis=i_to_str(ValueK) + " поручений ";
     de->setCellValue(10,"D",KolPropis);
     k=IntToStr(DS->FieldByName("KOL_SUM")->AsInteger)+ " поручений ";
     de->setCellValue(10,"B",k);
     de->setCellValue(12,"B",AnsiString().sprintf("%.02lf",P1));
     de->setCellValue(12,"D",f_to_str(P1));
     ValueS=ValueS-950000.00;
    }else
    {
     de->setCellValue(ns,"A",date.DateString());
     de->setCellValue(ns,"B",AnsiString().sprintf("%.02lf",P2));
     de->setCellValue(ns+1,"D",f_to_str(P2));
     ValueS=ValueS-900000.00;
    }
   i++;
   ns=ns+11;
  }
  }
  if (ValueS>0){
   de->setCellValue(ns,"A",date.DateString());
   de->setCellValue(ns,"B",AnsiString().sprintf("%.02lf",ValueS));
//  de->setCellValue(ns+7,"A",f_to_str(floor(summa*100+0.5)/100));
   de->setCellValue(ns+1,"D",f_to_str(floor(ValueS*100+0.5)/100));
  }
  ns=ns+11;
  de->deleteRange(IntToStr(ns),IntToStr(84));

  de->setSheetNumber(2);
  de->setCellValue(10,"C",AnsiString().sprintf("%.02lf",RasS));
  de->setCellValue(10,"B",RasK);
  de->setCellValue(10,"E",NeoplK);
  de->setCellValue(10,"G",AnsiString().sprintf("%.02lf",NeoplS));
  de->setCellValue(11,"G",f_to_str(floor(NeoplS*100+0.5)/100));
  de->setCellValue(15,"I",fiokass.Trim());

 //Закрываем файл
  de->closeFile();
  delete de;
  DS->Close();
  return fout.Trim();
}


//Функция формирования файла с формой Ф42
AnsiString __fastcall createF42File(TDataSet *DS,TDataSet *DS1,TDataSet *DS2,AnsiString FIO,AnsiString OS,TDate date)
{
AnsiString fileIn,s,k,itogsum;
Double ValueS;
int ValueK;
AnsiString fileOut;
unsigned short y,m,d1;
DirectWorkExcel *de;
AnsiString fout;
Double P1,P2;
int i=1;
int ns=7;
AnsiString odpp,fio;
TIniFile* ini;
AnsiString workDir;
AnsiString iniFileName;
AnsiString fiokass,Zag;


  workDir=ExtractFilePath(Application->ExeName);
  iniFileName=workDir+"AccountGSM.ini";
  ini=new TIniFile(iniFileName);
  odpp = ini->ReadString("Parametr","odpp","");
  fio = ini->ReadString("Parametr","fio","");
  fiokass = ini->ReadString("Parametr","email","");
  Zag=odpp.Trim()+","+OS.Trim();
  delete ini;



  fileIn=getWorkDir()+"Template\\f42.xlsx";

//  if (DS->RecordCount==0 && DS1->RecordCount==0)
//  {
//  MessageDlg("Нет данных для формы 42. Формирования отчетов прервано!!! ",mtWarning,TMsgDlgButtons() << mbOK,0);
//  return "F";
//  }

  fileOut=getWorkDir()+"OUT\\";
  date.DecodeDate(&y,&m,&d1);
  s=AnsiString().sprintf("%02d-%02d-%d",d1,m,y);
  fileOut+="f42for";
  fout+="f42for";
  fileOut+=FIO;
  fout+=FIO;
  fileOut+=s+".xlsx";
  fout+=s+".xlsx";
  if(FileExists(fileOut)) DeleteFile(fileOut);
  //Копируем шаблон
  if(templateCopy(fileIn,fileOut)== false) return "F";

  //Создаем Excel файл
  try
  {
    de=new DirectWorkExcel(fileOut,1);
  }
  catch(const Exception &exc)
  { MessageDlg("Ошибка создания объекта DirectWorkExcel\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
    return "";
  }
  if(de->openFile(false)==false)
  {
    MessageDlg("Ошибка открытия Excel файла",mtWarning,TMsgDlgButtons() << mbOK,0);
    if(de!=NULL) delete de;
    return "F";
  }

  de->setSheetNumber(1);
  de->setCellValue(4,"C",FIO.Trim());
  de->setCellValue(1,"B",Zag.Trim());
  de->setCellValue(5,"C",date.DateString());

  DS->First();
  while (!DS->Eof)
  {
  ValueS=DS->FieldByName("EXP")->AsFloat;
  ValueK=DS->FieldByName("KOL")->AsInteger;

  de->setCellValue(DS->FieldByName("NR")->AsInteger,"D",AnsiString().sprintf("%.02lf",ValueS));
  de->setCellValue(DS->FieldByName("NR")->AsInteger,"F",ValueK);
  DS->Next();
  }

  de->setSheetNumber(2);

  DS1->First();
  while (!DS1->Eof)
  {
  ValueS=DS1->FieldByName("EXP")->AsFloat;
  ValueK=DS1->FieldByName("KOL")->AsInteger;

  de->setCellValue(DS1->FieldByName("NR")->AsInteger,"D",AnsiString().sprintf("%.02lf",ValueS));
  de->setCellValue(DS1->FieldByName("NR")->AsInteger,"E",ValueK);
  DS1->Next();
  }

  P1=950000.00;
  P2=900000.00;
  ValueS=DS2->FieldByName("EXP_SUM")->AsFloat;
  ValueK=DS2->FieldByName("KOL_SUM")->AsInteger;
  if (ValueS<=950000.00)
  {
     P1=ValueS;
     de->setCellValue(7,"C",AnsiString().sprintf("%.02lf",P1));
     ValueS=ValueS-950000.00;
  }else{
  while (ValueS>900000.00)
  {
    if (i==1)
    {
     de->setCellValue(7,"C",AnsiString().sprintf("%.02lf",P1));
     ValueS=ValueS-950000.00;
    }else
    {
     de->setCellValue(ns,"C",AnsiString().sprintf("%.02lf",P2));
     ValueS=ValueS-900000.00;
    }
   i++;
   ns=ns+1;
  }
  }
  if (ValueS>0){
   de->setCellValue(ns,"C",AnsiString().sprintf("%.02lf",ValueS));
  }
  ns=ns+1;
  de->deleteRange(IntToStr(ns),IntToStr(16));


 //Закрываем файл
  de->closeFile();
  delete de;
  DS->Close();
  DS1->Close();
  return fout.Trim();
}


//Функция формирования файла с формой Ф42 дополнительная!!! завтра сделать!!!

AnsiString __fastcall createF42dFile(TDataSet *DS,AnsiString FIO,AnsiString OS,TDate date)
{
AnsiString fileIn,s,k,itogsum;
Double ValueS,Itogo;
int ValueK;
AnsiString fileOut;
unsigned short y,m,d1;
DirectWorkExcel *de;
AnsiString fout;
Double P1,P2;
int i=1;
int ns=7;
AnsiString odpp,fio;
TIniFile* ini;
AnsiString workDir;
AnsiString iniFileName;
AnsiString fiokass,Zag;


  workDir=ExtractFilePath(Application->ExeName);
  iniFileName=workDir+"AccountGSM.ini";
  ini=new TIniFile(iniFileName);
  odpp = ini->ReadString("Parametr","odpp","");
  fio = ini->ReadString("Parametr","fio","");
  fiokass = ini->ReadString("Parametr","email","");
  Zag=odpp.Trim()+","+OS.Trim();
  delete ini;



  fileIn=getWorkDir()+"Template\\f42d.xlsx";


  fileOut=getWorkDir()+"OUT\\";
  date.DecodeDate(&y,&m,&d1);
  s=AnsiString().sprintf("%02d-%02d-%d",d1,m,y);
  fileOut+="f42dfor";
  fout+="f42dfor";
  fileOut+=FIO;
  fout+=FIO;
  fileOut+=s+".xlsx";
  fout+=s+".xlsx";
  if(FileExists(fileOut)) DeleteFile(fileOut);
  //Копируем шаблон
  if(templateCopy(fileIn,fileOut)== false) return "F";

  //Создаем Excel файл
  try
  {
    de=new DirectWorkExcel(fileOut,1);
  }
  catch(const Exception &exc)
  { MessageDlg("Ошибка создания объекта DirectWorkExcel\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
    return "";
  }
  if(de->openFile(false)==false)
  {
    MessageDlg("Ошибка открытия Excel файла",mtWarning,TMsgDlgButtons() << mbOK,0);
    if(de!=NULL) delete de;
    return "F";
  }

  de->setSheetNumber(1);
  de->setCellValue(4,"C",FIO.Trim());
  de->setCellValue(1,"B",Zag.Trim());
  de->setCellValue(5,"C",date.DateString());

  ValueS=0.00;
  Itogo=0.00;

  DS->First();
  while (!DS->Eof)
  {
  ValueS=DS->FieldByName("EXP")->AsFloat;
  ValueK=DS->FieldByName("KOL")->AsInteger;
  Itogo=Itogo+ValueS;
  de->setCellValue(DS->FieldByName("NR")->AsInteger,"D",AnsiString().sprintf("%.02lf",ValueS));
  de->setCellValue(DS->FieldByName("NR")->AsInteger,"F",ValueK);
  DS->Next();
  }

  de->setSheetNumber(2);

  if (ValueS>0){
   de->setCellValue(ns,"C",AnsiString().sprintf("%.02lf",Itogo));
  }

 //Закрываем файл
  de->closeFile();
  delete de;
  DS->Close();
  return fout.Trim();
}


//Функция формирования файла с распиской
AnsiString __fastcall createraspisFile(TDataSet *DS,TDataSet *DS1,AnsiString FIO,TDate date)
{
AnsiString fileIn,s,k,itogsum;
Double ValueS;
int ValueK;
AnsiString fileOut;
unsigned short y,m,d1;
DirectWorkExcel *de;
AnsiString fout;


  fileIn=getWorkDir()+"Template\\raspiska.xlsx";

  if (DS->FieldByName("KOL_SUM")->AsInteger ==0 && DS1->FieldByName("KOL_SUM")->AsInteger==0)
  {
  MessageDlg("Нет данных . Формирования отчетов прервано!!! ",mtWarning,TMsgDlgButtons() << mbOK,0);
  return "F";
  }

  fileOut=getWorkDir()+"OUT\\";
  date.DecodeDate(&y,&m,&d1);
  s=AnsiString().sprintf("%02d-%02d-%d",d1,m,y);
  fileOut+="raspfor";
  fout+="raspfor";
  fileOut+=FIO;
  fout+=FIO;
  fileOut+=s+".xlsx";
  fout+=s+".xlsx";
  if(FileExists(fileOut)) DeleteFile(fileOut);
  //Копируем шаблон
  if(templateCopy(fileIn,fileOut)== false) return "F";

  //Создаем Excel файл
  try
  {
    de=new DirectWorkExcel(fileOut,1);
  }
  catch(const Exception &exc)
  { MessageDlg("Ошибка создания объекта DirectWorkExcel\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
    return "";
  }
  if(de->openFile(false)==false)
  {
    MessageDlg("Ошибка открытия Excel файла",mtWarning,TMsgDlgButtons() << mbOK,0);
    if(de!=NULL) delete de;
    return "F";
  }

  de->setSheetNumber(1);
  de->setCellValue(2,"D",FIO.Trim());
  de->setCellValue(18,"I",FIO.Trim());
  de->setCellValue(15,"G",GSM_DM->UserLogin.Trim());
  de->setCellValue(1,"B",date.DateString());
  de->setCellValue(20,"G",date.DateString());

  ValueS=DS->FieldByName("EXP_SUM")->AsFloat-DS1->FieldByName("EXP_SUM")->AsFloat;
  ValueK=DS->FieldByName("KOL_SUM")->AsInteger-DS1->FieldByName("KOL_SUM")->AsInteger;


  de->setCellValue(10,"C",AnsiString().sprintf("%.02lf",DS1->FieldByName("EXP_SUM")->AsFloat));
  de->setCellValue(10,"B",DS1->FieldByName("KOL_SUM")->AsInteger);

  de->setCellValue(10,"G",AnsiString().sprintf("%.02lf",ValueS));
  de->setCellValue(10,"E",ValueK);
  de->setCellValue(11,"G",f_to_str(ValueS));


 //Закрываем файл
  de->closeFile();
  delete de;
  DS->Close();
  DS1->Close();
  return fout.Trim();
}

//Функция формирования файла с формой статистики
AnsiString __fastcall createstatFile(AnsiString OS,TDate date,TDate date1)
{
AnsiString fileIn,s,k,itogsum;
AnsiString fileOut;
unsigned short y,m,d1;
DirectWorkExcel *de;
AnsiString fout;


  fileIn=getWorkDir()+"Template\\stat.xlsx";

  fileOut=getWorkDir()+"OUT\\";
  date.DecodeDate(&y,&m,&d1);
  s=AnsiString().sprintf("%02d-%02d-%d",d1,m,y);
  fileOut+="statfor";
  fout+="statfor";
  fileOut+=OS;
  fout+=OS;
  fileOut+=s+".xlsx";
  fout+=s+".xlsx";
  if(FileExists(fileOut)) DeleteFile(fileOut);
  //Копируем шаблон
  if(templateCopy(fileIn,fileOut)== false) return "F";

  //Создаем Excel файл
  try
  {
    de=new DirectWorkExcel(fileOut,1);
  }
  catch(const Exception &exc)
  {
    MessageDlg("Ошибка создания объекта DirectWorkExcel\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
    return "F";
  }
  if(de->openFile(false)==false)
  {
    MessageDlg("Ошибка открытия Excel файла",mtWarning,TMsgDlgButtons() << mbOK,0);
    if(de!=NULL) delete de;
    return "F";
  }

  de->setSheetNumber(1);
  de->setCellValue(2,"E",OS.Trim());
  de->setCellValue(38,"F",GSM_DM->UserLogin.Trim());
  de->setCellValue(4,"C",date.DateString()+"-"+date1.DateString());

 //Закрываем файл
  de->closeFile();
  delete de;
  return fout.Trim();
}

void __fastcall editstatFile(TDataSet *DS2,TDataSet *DS3,TDataSet *DS4,TDataSet *DS5,TDataSet *DS6,TDataSet *DS7,AnsiString namefile,int ns)
{
DirectWorkExcel *de;
AnsiString fileOut;

fileOut=getWorkDir()+"OUT\\"+namefile;

//Создаем Excel файл
try
{
de=new DirectWorkExcel(fileOut,1);
}
catch(const Exception &exc)
{
MessageDlg("Ошибка создания объекта DirectWorkExcel\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
return;
}
if(de->openFile(false)==false)
{
MessageDlg("Ошибка открытия Excel файла",mtWarning,TMsgDlgButtons() << mbOK,0);
if(de!=NULL) delete de;
return;
}

de->setSheetNumber(1);
if(DS2->RecordCount > 0){
de->setCellValue(ns,"A",DS2->FieldByName("DESCRIPTION")->AsString.Trim());
de->setCellValue(ns,"C",AnsiString().sprintf("%.02lf",DS2->FieldByName("EXP_SUM")->AsFloat));
de->setCellValue(ns,"B",DS2->FieldByName("KOL_SUM")->AsInteger);
}
if(DS3->RecordCount > 0){
de->setCellValue(ns,"A",DS3->FieldByName("DESCRIPTION")->AsString.Trim());
de->setCellValue(ns,"E",AnsiString().sprintf("%.02lf",DS3->FieldByName("EXP_SUM")->AsFloat));
de->setCellValue(ns,"D",DS3->FieldByName("KOL_SUM")->AsInteger);
}
if(DS4->RecordCount > 0){
de->setCellValue(ns,"A",DS4->FieldByName("DESCRIPTION")->AsString.Trim());
de->setCellValue(ns,"G",AnsiString().sprintf("%.02lf",DS4->FieldByName("EXP_SUM")->AsFloat));
de->setCellValue(ns,"F",DS4->FieldByName("KOL_SUM")->AsInteger);
}
if(DS5->RecordCount > 0)
{
de->setCellValue(ns,"A",DS5->FieldByName("DESCRIPTION")->AsString.Trim());
de->setCellValue(ns,"M",AnsiString().sprintf("%.02lf",DS5->FieldByName("EXP_SUM")->AsFloat));
}
if(DS6->RecordCount > 0){
de->setCellValue(ns,"A",DS6->FieldByName("DESCRIPTION")->AsString.Trim());
de->setCellValue(ns,"I",AnsiString().sprintf("%.02lf",DS6->FieldByName("EXP_SUM")->AsFloat));
de->setCellValue(ns,"H",DS6->FieldByName("KOL_SUM")->AsInteger);
}
if(DS7->RecordCount > 0){
de->setCellValue(ns,"A",DS7->FieldByName("DESCRIPTION")->AsString.Trim());
de->setCellValue(ns,"J",AnsiString().sprintf("%.02lf",DS7->FieldByName("EXP_SUM")->AsFloat));
de->setCellValue(ns,"K",DS7->FieldByName("KOL_SUM")->AsInteger);
}
 //Закрываем файл
de->closeFile();
delete de;
return;
}


void __fastcall deletestatFile(AnsiString namefile,int ns1,int ns2)
{
DirectWorkExcel *de;
AnsiString fileOut;
int razn;

fileOut=getWorkDir()+"OUT\\"+namefile;

//Создаем Excel файл
try
{
de=new DirectWorkExcel(fileOut,1);
}
catch(const Exception &exc)
{
MessageDlg("Ошибка создания объекта DirectWorkExcel\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
return;
}
if(de->openFile(false)==false)
{
MessageDlg("Ошибка открытия Excel файла",mtWarning,TMsgDlgButtons() << mbOK,0);
if(de!=NULL) delete de;
return;
}
de->setSheetNumber(1);
razn=22-ns1+1;
de->deleteRange(IntToStr(ns1),IntToStr(19));
de->deleteRange(IntToStr(ns2-razn),IntToStr(29-razn));
 //Закрываем файл
de->closeFile();
delete de;
return;
}

//---------------------------------------------------------------------------
//Функция формирования файла с формой реестра
AnsiString __fastcall createreestrFile(AnsiString OS,TDate date)
{
AnsiString fileIn,s,k,itogsum;
AnsiString fileOut;
unsigned short y,m,d1;
DirectWorkExcel *de;
AnsiString fout;
AnsiString odpp,fio;
TIniFile* ini;
AnsiString workDir;
AnsiString iniFileName;
AnsiString fiokass;


  workDir=ExtractFilePath(Application->ExeName);
  iniFileName=workDir+"AccountGSM.ini";
  ini=new TIniFile(iniFileName);
  odpp = ini->ReadString("Parametr","odpp","");
  fio = ini->ReadString("Parametr","fio","");
  fiokass = ini->ReadString("Parametr","email","");

  delete ini;

  fileIn=getWorkDir()+"Template\\reestr.xlsx";
  fileOut=getWorkDir()+"OUT\\";
  date.DecodeDate(&y,&m,&d1);
  s=AnsiString().sprintf("%02d-%02d-%d",d1,m,y);
  fileOut+="reestrfor";
  fout+="reestrfor";
  fileOut+=OS;
  fout+=OS;
  fileOut+=s+".xlsx";
  fout+=s+".xlsx";
  if(FileExists(fileOut)) DeleteFile(fileOut);
  //Копируем шаблон
  if(templateCopy(fileIn,fileOut)== false) return "F";

  //Создаем Excel файл
  try
  {
    de=new DirectWorkExcel(fileOut,1);
  }
  catch(const Exception &exc)
  {
    MessageDlg("Ошибка создания объекта DirectWorkExcel\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
    return "F";
  }
  if(de->openFile(false)==false)
  {
    MessageDlg("Ошибка открытия Excel файла",mtWarning,TMsgDlgButtons() << mbOK,0);
    if(de!=NULL) delete de;
    return "F";
  }

  de->setSheetNumber(1);
  de->setCellValue(5,"A",OS.Trim());
  de->setCellValue(4,"A",odpp.Trim());
  de->setCellValue(37,"D",fiokass.Trim());
  de->setCellValue(9,"E",date.DateString());
  de->setCellValue(37,"I",fio.Trim());

 //Закрываем файл
  de->closeFile();
  delete de;
  return fout.Trim();
}

void __fastcall editreestrFile(TDataSet *DS1,TDataSet *DS2,TDataSet *DS3,TDataSet *DS5,TDataSet *DS6,AnsiString namefile,int ns)
{
DirectWorkExcel *de;
AnsiString fileOut;

fileOut=getWorkDir()+"OUT\\"+namefile;

//Создаем Excel файл
try
{
de=new DirectWorkExcel(fileOut,1);
}
catch(const Exception &exc)
{
MessageDlg("Ошибка создания объекта DirectWorkExcel\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
return;
}
if(de->openFile(false)==false)
{
MessageDlg("Ошибка открытия Excel файла",mtWarning,TMsgDlgButtons() << mbOK,0);
if(de!=NULL) delete de;
return;
}

de->setSheetNumber(1);
if(DS1->RecordCount > 0){
de->setCellValue(ns,"A",DS1->FieldByName("DESCRIPTION")->AsString.Trim());
de->setCellValue(ns,"C",AnsiString().sprintf("%.02lf",DS1->FieldByName("EXP_SUM")->AsFloat));
de->setCellValue(ns,"B",DS1->FieldByName("KOL_SUM")->AsInteger);
}
if(DS2->RecordCount > 0){
de->setCellValue(ns,"A",DS2->FieldByName("DESCRIPTION")->AsString.Trim());
de->setCellValue(ns,"E",AnsiString().sprintf("%.02lf",DS2->FieldByName("EXP_SUM")->AsFloat));
de->setCellValue(ns,"D",DS2->FieldByName("KOL_SUM")->AsInteger);
}
if(DS3->RecordCount > 0){
de->setCellValue(ns,"A",DS3->FieldByName("DESCRIPTION")->AsString.Trim());
de->setCellValue(ns,"G",AnsiString().sprintf("%.02lf",DS3->FieldByName("EXP_SUM")->AsFloat));
de->setCellValue(ns,"F",DS3->FieldByName("KOL_SUM")->AsInteger);
}
if(DS5->RecordCount > 0){
de->setCellValue(ns,"A",DS5->FieldByName("DESCRIPTION")->AsString.Trim());
de->setCellValue(ns,"I",AnsiString().sprintf("%.02lf",DS5->FieldByName("EXP_SUM")->AsFloat));
de->setCellValue(ns,"H",DS5->FieldByName("KOL_SUM")->AsInteger);
}
if(DS6->RecordCount > 0){
de->setCellValue(ns,"A",DS6->FieldByName("DESCRIPTION")->AsString.Trim());
de->setCellValue(ns,"K",AnsiString().sprintf("%.02lf",DS6->FieldByName("EXP_SUM")->AsFloat));
de->setCellValue(ns,"J",DS6->FieldByName("KOL_SUM")->AsInteger);
}
 //Закрываем файл
de->closeFile();
delete de;
return;
}

void __fastcall deletereestrFile(AnsiString namefile,int ns1,double ns2,double ns3)
{
DirectWorkExcel *de;
AnsiString fileOut;
int razn;
double ns4;

fileOut=getWorkDir()+"OUT\\"+namefile;

//Создаем Excel файл
try
{
de=new DirectWorkExcel(fileOut,1);
}
catch(const Exception &exc)
{
MessageDlg("Ошибка создания объекта DirectWorkExcel\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
return;
}
if(de->openFile(false)==false)
{
MessageDlg("Ошибка открытия Excel файла",mtWarning,TMsgDlgButtons() << mbOK,0);
if(de!=NULL) delete de;
return;
}
de->setSheetNumber(1);
de->setCellValue(14,"M",AnsiString().sprintf("%.02lf",ns3));
ns4=ns3-ns2;
de->setCellValue(34,"A",f_to_str(ns4));
de->deleteRange(IntToStr(ns1),IntToStr(32));
 //Закрываем файл
de->closeFile();
delete de;
return;
}

void __fastcall editF130File(double val1,double val2,double val3,double val4,double val5,double val6,double val7,double val8,double val9,double val10,double val11,double val12,double val13,double val14,double val15,double val16,double val17,double val18,double val19,double val20,double val21,double val22,double val23,double val24,double val25,double val26,double val27,double val28,double val29,double val30,double val31,double val32,double val33,double val34,double val35,double val37,double val38,double val39,double val40,double val41,double val42,double val43,AnsiString namefile)
{
DirectWorkExcel *de;
AnsiString fileOut;

fileOut=getWorkDir()+"OUT\\"+namefile;

//Создаем Excel файл
try
{
de=new DirectWorkExcel(fileOut,1);
}
catch(const Exception &exc)
{
MessageDlg("Ошибка создания объекта DirectWorkExcel\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
return;
}
if(de->openFile(false)==false)
{
MessageDlg("Ошибка открытия Excel файла",mtWarning,TMsgDlgButtons() << mbOK,0);
if(de!=NULL) delete de;
return;
}

de->setSheetNumber(1);
if(val1 != 0) de->setCellValue(35,"H",AnsiString().sprintf("%.02lf",val1));
if(val2 != 0) de->setCellValue(29,"H",AnsiString().sprintf("%.02lf",val2));
if(val3 != 0) de->setCellValue(27,"H",AnsiString().sprintf("%.02lf",val3));
if(val25 != 0) de->setCellValue(31,"H",AnsiString().sprintf("%.02lf",val25));
if(val5 !=0) de->setCellValue(46,"H",AnsiString().sprintf("%.02lf",val5));
if(val7 != 0) de->setCellValue(50,"H",AnsiString().sprintf("%.02lf",val7));
if(val25 != 0) de->setCellValue(31,"H",AnsiString().sprintf("%.02lf",val25));
if(val26 != 0) de->setCellValue(33,"H",AnsiString().sprintf("%.02lf",val26));
if(val27 != 0) de->setCellValue(41,"H",AnsiString().sprintf("%.02lf",val27));
if(val28 != 0) de->setCellValue(52,"H",AnsiString().sprintf("%.02lf",val28));
if(val16 != 0) de->setCellValue(58,"H",AnsiString().sprintf("%.02lf",val16));
if(val17 != 0) de->setCellValue(61,"H",AnsiString().sprintf("%.02lf",val17));
if(val18 != 0) de->setCellValue(67,"H",AnsiString().sprintf("%.02lf",val18));
if(val19 != 0) de->setCellValue(70,"H",AnsiString().sprintf("%.02lf",val19));
if(val29 != 0) de->setCellValue(73,"H",AnsiString().sprintf("%.02lf",val29));
if(val21 != 0) de->setCellValue(84,"H",AnsiString().sprintf("%.02lf",val21));
if(val22 != 0) de->setCellValue(83,"H",AnsiString().sprintf("%.02lf",val22));
if(val23 != 0) de->setCellValue(85,"H",AnsiString().sprintf("%.02lf",val23));
if(val24 != 0) de->setCellValue(86,"H",AnsiString().sprintf("%.02lf",val24));
if(val30 != 0) de->setCellValue(87,"H",AnsiString().sprintf("%.02lf",val30));
if(val31 != 0) de->setCellValue(22,"H",AnsiString().sprintf("%.02lf",val31));
if(val32 != 0) de->setCellValue(88,"H",AnsiString().sprintf("%.02lf",val32));
if(val34 != 0) de->setCellValue(89,"H",AnsiString().sprintf("%.02lf",val34));
if(val39 != 0) de->setCellValue(90,"H",AnsiString().sprintf("%.02lf",val39));
if(val33 != 0) de->setCellValue(76,"H",AnsiString().sprintf("%.02lf",val33));
if(val35 != 0) de->setCellValue(77,"H",AnsiString().sprintf("%.02lf",val35));
if(val37 != 0) de->setCellValue(39,"H",AnsiString().sprintf("%.02lf",val37));
if(val38 != 0) de->setCellValue(78,"H",AnsiString().sprintf("%.02lf",val38));
if(val40 != 0) de->setCellValue(54,"H",AnsiString().sprintf("%.02lf",val40));
if(val41 != 0) de->setCellValue(37,"H",AnsiString().sprintf("%.02lf",val41));
if(val42 != 0) de->setCellValue(64,"H",AnsiString().sprintf("%.02lf",val42));
if(val43 != 0) de->setCellValue(91,"H",AnsiString().sprintf("%.02lf",val43));
 //Закрываем файл
de->closeFile();
delete de;
return;
}

//Функция формирования файла с формой 130
AnsiString __fastcall createF130File(TDate date,double ost1,double ost2,double ost3,double ost7,double ost5,double ost8,double ost9,double ost10,double ost11)
{
AnsiString fileIn,s,k,itogsum;
AnsiString fileOut;
unsigned short y,m,d1;
DirectWorkExcel *de;
AnsiString fout;
AnsiString odpp,fio;
TIniFile* ini;
AnsiString workDir;
AnsiString iniFileName;


  workDir=ExtractFilePath(Application->ExeName);
  iniFileName=workDir+"AccountGSM.ini";
  ini=new TIniFile(iniFileName);
  odpp = ini->ReadString("Parametr","odpp","");
  fio = ini->ReadString("Parametr","fio","");
  delete ini;


  fileIn=getWorkDir()+"Template\\f130.xlsx";

  fileOut=getWorkDir()+"OUT\\";
  date.DecodeDate(&y,&m,&d1);
  s=AnsiString().sprintf("%02d-%02d-%d",d1,m,y);
  fileOut+="f130of";
  fout+="f130of";
  fileOut+=s+".xlsx";
  fout+=s+".xlsx";
  if(FileExists(fileOut)) DeleteFile(fileOut);
  //Копируем шаблон
  if(templateCopy(fileIn,fileOut)== false) return "F";

  //Создаем Excel файл
  try
  {
    de=new DirectWorkExcel(fileOut,1);
  }
  catch(const Exception &exc)
  {
    MessageDlg("Ошибка создания объекта DirectWorkExcel\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
    return "F";
  }
  if(de->openFile(false)==false)
  {
    MessageDlg("Ошибка открытия Excel файла",mtWarning,TMsgDlgButtons() << mbOK,0);
    if(de!=NULL) delete de;
    return "F";
  }

  de->setSheetNumber(1);
  de->setCellValue(93,"B",odpp.Trim());
  de->setCellValue(4,"G",odpp.Trim());
  de->setCellValue(93,"G",fio.Trim());
  de->setCellValue(6,"B",date.DateString());
  de->setCellValue(11,"H",AnsiString().sprintf("%.02lf",ost1));
  de->setCellValue(12,"H",AnsiString().sprintf("%.02lf",ost2));
  de->setCellValue(13,"H",AnsiString().sprintf("%.02lf",ost3));
  de->setCellValue(14,"H",AnsiString().sprintf("%.02lf",ost7));
  de->setCellValue(15,"H",AnsiString().sprintf("%.02lf",ost5));
  de->setCellValue(16,"H",AnsiString().sprintf("%.02lf",ost8));
  de->setCellValue(17,"H",AnsiString().sprintf("%.02lf",ost9));
  de->setCellValue(18,"H",AnsiString().sprintf("%.02lf",ost10));
  de->setCellValue(19,"H",AnsiString().sprintf("%.02lf",ost11));


 //Закрываем файл
  de->closeFile();
  delete de;
  return fout.Trim();
}

//Функция формирования файла с формой Ф42 для кассира расход
AnsiString __fastcall createF42KFile(TDataSet *DS,TDataSet *DS1,AnsiString OS,TDate date)
{
AnsiString fileIn;
Double ValueS;
int ValueK,ns;
AnsiString fileOut,s;
unsigned short y,m,d1;
DirectWorkExcel *de;
AnsiString fout;
TIniFile* ini;
AnsiString workDir;
AnsiString iniFileName,fio;
AnsiString odpp;
AnsiString fiokass,Zag;


  workDir=ExtractFilePath(Application->ExeName);
  iniFileName=workDir+"AccountGSM.ini";
  ini=new TIniFile(iniFileName);
  odpp = ini->ReadString("Parametr","odpp","");
  fio = ini->ReadString("Parametr","fio","");
  fiokass = ini->ReadString("Parametr","email","");
  Zag=odpp.Trim()+","+OS.Trim();
  delete ini;

  fileIn=getWorkDir()+"Template\\f42k.xlsx";

  if (DS->RecordCount==0 && DS1->RecordCount==0)
  {
  MessageDlg("Нет данных для формы 42. Формирования отчетов прервано!!! ",mtWarning,TMsgDlgButtons() << mbOK,0);
  return "F";
  }

  fileOut=getWorkDir()+"OUT\\";
  date.DecodeDate(&y,&m,&d1);
  s=AnsiString().sprintf("%02d-%02d-%d",d1,m,y);
  fileOut+="f42kfor";
  fout+="f42kfor";
  fileOut+=OS;
  fout+=OS;
  fileOut+=s+".xlsx";
  fout+=s+".xlsx";
  if(FileExists(fileOut)) DeleteFile(fileOut);

  //Копируем шаблон
  if(templateCopy(fileIn,fileOut)== false) return "F";

  //Создаем Excel файл
  try
  {
    de=new DirectWorkExcel(fileOut,1);
  }
  catch(const Exception &exc)
  {
    MessageDlg("Ошибка создания объекта DirectWorkExcel\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
    return "";
  }
  if(de->openFile(false)==false)
  {
    MessageDlg("Ошибка открытия Excel файла",mtWarning,TMsgDlgButtons() << mbOK,0);
    if(de!=NULL) delete de;
    return "F";
  }

  de->setSheetNumber(1);
  de->setCellValue(4,"C",fiokass.Trim());
  de->setCellValue(1,"B",Zag.Trim());
  de->setCellValue(5,"C",date.DateString());
  DS1->First();
  while (!DS1->Eof)
  {
  ValueS=DS1->FieldByName("EXP")->AsFloat;
  ValueK=DS1->FieldByName("KOL")->AsInteger;
  ns=DS1->FieldByName("NR")->AsInteger;
  if (ns>=23) de->setCellValue(ns,"D",AnsiString().sprintf("%.02lf",ValueS)); else de->setCellValue(ns,"E",AnsiString().sprintf("%.02lf",ValueS));
  de->setCellValue(ns,"F",ValueK);
  DS1->Next();
  }

  de->setSheetNumber(2);
  ns=7;
  DS->First();
  while (!DS->Eof)
  {
  ValueS=DS->FieldByName("EXP")->AsFloat;
  ValueK=DS->FieldByName("KOL")->AsInteger;

  de->setCellValue(ns,"C",AnsiString().sprintf("%.02lf",ValueS));
  ns++;
  DS->Next();
  }

 //Закрываем файл
  de->closeFile();
  delete de;
  DS->Close();
  DS1->Close();
  return fout.Trim();
}

//Функция формирования файла с формой Ф42 для кассира расход
AnsiString __fastcall createF42KdFile(TDataSet *DS1,AnsiString OS,TDate date)
{
AnsiString fileIn;
Double ValueS,Itogo;
int ValueK,ns;
AnsiString fileOut,s;
unsigned short y,m,d1;
DirectWorkExcel *de;
AnsiString fout;
TIniFile* ini;
AnsiString workDir;
AnsiString iniFileName,fio;
AnsiString odpp;
AnsiString fiokass,Zag;


  workDir=ExtractFilePath(Application->ExeName);
  iniFileName=workDir+"AccountGSM.ini";
  ini=new TIniFile(iniFileName);
  odpp = ini->ReadString("Parametr","odpp","");
  fio = ini->ReadString("Parametr","fio","");
  fiokass = ini->ReadString("Parametr","email","");
  Zag=odpp.Trim()+","+OS.Trim();
  delete ini;

  fileIn=getWorkDir()+"Template\\f42kd.xlsx";

  if (DS1->RecordCount==0)
  {
  MessageDlg("Нет данных для формы 42. Формирования отчетов прервано!!! ",mtWarning,TMsgDlgButtons() << mbOK,0);
  return "F";
  }

  fileOut=getWorkDir()+"OUT\\";
  date.DecodeDate(&y,&m,&d1);
  s=AnsiString().sprintf("%02d-%02d-%d",d1,m,y);
  fileOut+="f42kdfor";
  fout+="f42kdfor";
  fileOut+=OS;
  fout+=OS;
  fileOut+=s+".xlsx";
  fout+=s+".xlsx";
  if(FileExists(fileOut)) DeleteFile(fileOut);

  //Копируем шаблон
  if(templateCopy(fileIn,fileOut)== false) return "F";

  //Создаем Excel файл
  try
  {
    de=new DirectWorkExcel(fileOut,1);
  }
  catch(const Exception &exc)
  {
    MessageDlg("Ошибка создания объекта DirectWorkExcel\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
    return "";
  }
  if(de->openFile(false)==false)
  {
    MessageDlg("Ошибка открытия Excel файла",mtWarning,TMsgDlgButtons() << mbOK,0);
    if(de!=NULL) delete de;
    return "F";
  }

  de->setSheetNumber(1);
  de->setCellValue(4,"C",fiokass.Trim());
  de->setCellValue(1,"B",Zag.Trim());
  de->setCellValue(5,"C",date.DateString());
  ValueS=0.00;
  Itogo=0.00;
  DS1->First();
  while (!DS1->Eof)
  {
  ValueS=DS1->FieldByName("EXP")->AsFloat;
  ValueK=DS1->FieldByName("KOL")->AsInteger;
  Itogo=Itogo+ValueS;
  ns=DS1->FieldByName("NR")->AsInteger;
  de->setCellValue(ns,"D",AnsiString().sprintf("%.02lf",ValueS));
  de->setCellValue(ns,"F",ValueK);
  DS1->Next();
  }

  de->setSheetNumber(2);
  ns=7;

  de->setCellValue(ns,"C",AnsiString().sprintf("%.02lf",Itogo));

 //Закрываем файл
  de->closeFile();
  delete de;
  DS1->Close();
  return fout.Trim();
}


//---------------------------------------------------------------------------
//Функция формирования файла с формой ведомости по выплатам
AnsiString __fastcall createVedVyplFile(TDate date1,TDate date2)
{
AnsiString fileIn,s,s1;
AnsiString fileOut;
unsigned short y,m,d1,d2,m2,y2;
DirectWorkExcel *de;
AnsiString fout;
AnsiString odpp,fio;
TIniFile* ini;
AnsiString workDir;
AnsiString iniFileName;


  workDir=ExtractFilePath(Application->ExeName);
  iniFileName=workDir+"AccountGSM.ini";
  ini=new TIniFile(iniFileName);
  odpp = ini->ReadString("Parametr","odpp","");
  fio = ini->ReadString("Parametr","fio","");

  delete ini;

  fileIn=getWorkDir()+"Template\\vedofvyp.xlsx";
  fileOut=getWorkDir()+"OUT\\";
  date1.DecodeDate(&y,&m,&d1);
  date2.DecodeDate(&y2,&m2,&d2);
  s=AnsiString().sprintf("%02d-%02d-%d",d1,m,y)+"-";
  s1=AnsiString().sprintf("%02d-%02d-%d",d2,m2,y2);
  fileOut+="vedofvypfor";
  fout+="vedofvypfor";
  fileOut+=s;
  fout+=s;
  fileOut+=s1+".xlsx";
  fout+=s1+".xlsx";
  if(FileExists(fileOut)) DeleteFile(fileOut);
  //Копируем шаблон
  if(templateCopy(fileIn,fileOut)== false) return "F";

  //Создаем Excel файл
  try
  {
    de=new DirectWorkExcel(fileOut,1);
  }
  catch(const Exception &exc)
  {
    MessageDlg("Ошибка создания объекта DirectWorkExcel\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
    return "F";
  }
  if(de->openFile(false)==false)
  {
    MessageDlg("Ошибка открытия Excel файла",mtWarning,TMsgDlgButtons() << mbOK,0);
    if(de!=NULL) delete de;
    return "F";
  }

  de->setSheetNumber(1);
  de->setCellValue(3,"D",odpp.Trim());
  de->setCellValue(30,"D",odpp.Trim());
  de->setCellValue(30,"L",fio.Trim());
  de->setCellValue(4,"H",date1.DateString());
  de->setCellValue(4,"L",date2.DateString());

 //Закрываем файл
  de->closeFile();
  delete de;
  return fout.Trim();
}

int __fastcall editvedvyplFile(TDataSet *DS,TDataSet *DS1,TDataSet *DS2,TDataSet *DS3,AnsiString ops,AnsiString namefile,int ns,int nl)
{
DirectWorkExcel *de;
AnsiString fileOut;
int count=0;

fileOut=getWorkDir()+"OUT\\"+namefile;

//Создаем Excel файл
try
{
de=new DirectWorkExcel(fileOut,1);
}
catch(const Exception &exc)
{
MessageDlg("Ошибка создания объекта DirectWorkExcel\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
return count;
}
if(de->openFile(false)==false)
{
MessageDlg("Ошибка открытия Excel файла",mtWarning,TMsgDlgButtons() << mbOK,0);
if(de!=NULL) delete de;
return count;
}

de->setSheetNumber(nl);

if(DS->RecordCount > 0){
de->setCellValue(ns,"A",ops.Trim());
de->setCellValue(ns,"B",AnsiString().sprintf("%.02lf",DS->FieldByName("EXP_SUM")->AsFloat));
de->setCellValue(ns,"C",DS->FieldByName("KOL_SUM")->AsInteger);
count++;
}else
{
de->setCellValue(ns,"A",ops.Trim());
de->setCellValue(ns,"B",AnsiString().sprintf("%.02lf",0.00));
de->setCellValue(ns,"C",0);
}
if(DS1->RecordCount > 0){
de->setCellValue(ns,"A",ops.Trim());
de->setCellValue(ns,"D",AnsiString().sprintf("%.02lf",DS1->FieldByName("EXP_SUM")->AsFloat));
de->setCellValue(ns,"E",DS1->FieldByName("KOL_SUM")->AsInteger);
count++;
}else
{
de->setCellValue(ns,"A",ops.Trim());
de->setCellValue(ns,"D",AnsiString().sprintf("%.02lf",0.00));
de->setCellValue(ns,"E",0);
}

if(DS2->RecordCount > 0){
de->setCellValue(ns,"A",ops.Trim());
de->setCellValue(ns,"H",AnsiString().sprintf("%.02lf",DS2->FieldByName("EXP_SUM")->AsFloat));
de->setCellValue(ns,"I",DS2->FieldByName("KOL_SUM")->AsInteger);
count++;
}else
{
de->setCellValue(ns,"A",ops.Trim());
de->setCellValue(ns,"H",AnsiString().sprintf("%.02lf",0.00));
de->setCellValue(ns,"I",0);
}

if (nl==1){
if(DS3->RecordCount > 0)
{
de->setCellValue(ns,"A",ops.Trim());
de->setCellValue(ns,"L",AnsiString().sprintf("%.02lf",DS3->FieldByName("EXP_SUM")->AsFloat));
de->setCellValue(ns,"M",DS3->FieldByName("KOL_SUM")->AsInteger);
count++;
}else
{
de->setCellValue(ns,"A",ops.Trim());
de->setCellValue(ns,"L",AnsiString().sprintf("%.02lf",0.00));
de->setCellValue(ns,"M",0);
}
}

 //Закрываем файл
de->closeFile();
delete de;
return count;
}

void __fastcall rashet(ExpensesData *ed)
{
TpFIBQuery *Q=GSM_DM->WQ;
TpFIBQuery *QR=GSM_DM->RQ;
AnsiString sql;
int flag;
int fkassa;


    // определить неоплату
AnsiString typeoper;
int idexp=0;
flag=0;
fkassa=0;

if(MainForm->PC->ActivePageIndex == 0 || MainForm->PC->ActivePageIndex == 1) flag=1;
if(MainForm->PC->ActivePageIndex == 2) flag=2;
if(MainForm->PC->ActivePageIndex == 0 ) fkassa=1;
if(MainForm->PC->ActivePageIndex == 1 || MainForm->PC->ActivePageIndex == 2) fkassa=0;


    switch (ed->getGSMID()) {
      case 17: case 36: { typeoper="73"; break; }
      case 3:  case 37: { typeoper="74"; break; }
      case 6:  case 35: { typeoper="75"; break; }
      case 42: case 39: { typeoper="77"; break; }
      case 43: case 44: { typeoper="78"; break; }
      default: typeoper="0";
    }
    sql=" select ID as IDEXP from EXPENSES_TABLE ";
    sql+=" where EXP_DATE = '"+ed->getExpDate().DateString()+"'";
    sql+=" and SD_ID="+IntToStr(ed->getSD_ID());
    sql+=" and DRIVER_ID="+IntToStr(ed->getDriverID());
    sql+=" and GSM_ID="+typeoper.Trim();
    sql+=" and U_ID="+IntToStr(GSM_DM->UserID);

    QR->Close();
    QR->SQL->Clear();
    QR->SQL->Add(sql);
    try
    {
    QR->ExecQuery();
    }
    catch(const Exception &exc)
    {
    MessageDlg("Ошибка "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
    }
    idexp=QR->FieldByName("IDEXP")->AsInteger;
if(idexp == 0)
{
    int id=0;
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
    { MessageDlg("Ошибка - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      Q->Transaction->Rollback();
      return;
    }
    if(Q->RecordCount==0)
    {
      MessageDlg("Ошибка получения значения ID таблицы EXPENSES_TABLE",mtError,TMsgDlgButtons() << mbOK,0);
      Q->Transaction->Rollback();
      return;
    }
    id=Q->FieldByName("ID")->AsInteger;
    sql="";
    Q->Close();
    Q->SQL->Clear();
    sql="insert into EXPENSES_TABLE(ID,EXP_DATE,SD_ID,DRIVER_ID,GSM_ID,KOL,EXPENSE,FLAG,EDITABLE,U_ID) values(";
    sql+=IntToStr(id)+",";
    sql+="'"+ed->getExpDate().DateString()+"',";
    sql+=IntToStr(ed->getSD_ID())+",";
    sql+=IntToStr(ed->getDriverID())+",";
    sql+=typeoper.Trim()+",";
    sql+=IntToStr(ed->getKol())+",";
    sql+=FloatToStr(ed->getExpense())+",";
    sql+=IntToStr(fkassa)+",0,";
    sql+=IntToStr(GSM_DM->UserID)+")";
    Q->SQL->Add(sql);
    try
    {
      Q->ExecQuery();
    }
    catch (Exception &exc)
    { MessageDlg("Ошибка - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      Q->Transaction->Rollback();
      return;
    }
    Q->Transaction->Commit();
    fr(id,typeoper.Trim(),ed->getExpDate(),ed->getSD_ID(),ed->getDriverID());
}
else
{
    fr(idexp,typeoper.Trim(),ed->getExpDate(),ed->getSD_ID(),ed->getDriverID());
}
}

void __fastcall fr(int idrec, AnsiString toper,TDateTime Dater,int sd_id,int id_ops)
{
TpFIBQuery *Q=GSM_DM->WQ;
TpFIBQuery *QR=GSM_DM->RQ;
AnsiString sql;
AnsiString strras,strpr;
double sumexppr,sumexpras,itexp;
int    sumkolpr,sumkolras,itkol;

sumexppr=0.0;
sumexpras=0.0;
itexp=0.0;
sumkolpr=0;
sumkolras=0;
itkol=0;

    switch (StrToInt(toper.Trim())) {
      case 73: { strras="36"; strpr="17"; break; }
      case 74: { strras="37"; strpr="3";  break; }
      case 75: { strras="35"; strpr="6";  break; }
      case 77: { strras="39"; strpr="42"; break; }
      case 78: { strras="44"; strpr="43"; break; }
      default: strras="0"; strpr="0";
    }

    sql=" select sum (EXPENSE) as sum_exppr , sum (KOL) as sum_kolpr from EXPENSES_TABLE ";
    sql+=" where EXP_DATE = '"+Dater.DateString()+"'";
    sql+=" and SD_ID="+IntToStr(sd_id);
    sql+=" and DRIVER_ID="+IntToStr(id_ops);
    sql+=" and GSM_ID="+strpr.Trim();
    if (GSM_DM->UserRole!="администратор" && GSM_DM->UserRole!="руководитель") sql+=" and U_ID="+IntToStr(GSM_DM->UserID);

    QR->Close();
    QR->SQL->Clear();
    QR->SQL->Add(sql);
    try
    {
    QR->ExecQuery();
    }
    catch(const Exception &exc)
    {
    MessageDlg("Ошибка "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
    }

    sumexppr=QR->FieldByName("SUM_EXPPR")->AsFloat;
    sumkolpr=QR->FieldByName("SUM_KOLPR")->AsInteger;

    sql=" select sum (EXPENSE) as sum_expras , sum (KOL) as sum_kolras from EXPENSES_TABLE ";
    sql+=" where EXP_DATE = '"+Dater.DateString()+"'";
    sql+=" and SD_ID="+IntToStr(sd_id);
    sql+=" and DRIVER_ID="+IntToStr(id_ops);
    sql+=" and GSM_ID="+strras.Trim();
    if (GSM_DM->UserRole!="администратор" && GSM_DM->UserRole!="руководитель") sql+=" and U_ID="+IntToStr(GSM_DM->UserID);

    QR->Close();
    QR->SQL->Clear();
    QR->SQL->Add(sql);
    try
    {
    QR->ExecQuery();
    }
    catch(const Exception &exc)
    {
    MessageDlg("Ошибка "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
    }

    sumexpras=QR->FieldByName("SUM_EXPRAS")->AsFloat;
    sumkolras=QR->FieldByName("SUM_KOLRAS")->AsInteger;

    itexp=sumexppr-sumexpras;
    itkol=sumkolpr-sumkolras;

    Q->Close();
    Q->SQL->Clear();
    sql="update EXPENSES_TABLE set";
    sql+=" EXPENSE="+FloatToStr(itexp);
    sql+=" , KOL="+IntToStr(itkol);
    sql+=" where ID="+IntToStr(idrec);
    Q->SQL->Add(sql);
    Q->Transaction->StartTransaction();
    try
    {
      Q->ExecQuery();
    }
    catch (Exception &exc)
    {
      MessageDlg("Ошибка - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      Q->Transaction->Rollback();
      return;
    }
    Q->Transaction->Commit();
}

//Функция формирования файла с формой ведомости по количесву выплат
AnsiString __fastcall createvedofkolFile(TDate date,TDate date1)
{
AnsiString fileIn,s,s1,k,itogsum;
AnsiString fileOut;
unsigned short y1,m1,d1;
unsigned short y2,m2,d2;
DirectWorkExcel *de;
AnsiString fout;
AnsiString odpp,fio;
TIniFile* ini;
AnsiString workDir;
AnsiString iniFileName;
AnsiString fiokass;


  workDir=ExtractFilePath(Application->ExeName);
  iniFileName=workDir+"AccountGSM.ini";
  ini=new TIniFile(iniFileName);
  odpp = ini->ReadString("Parametr","odpp","");
  fio = ini->ReadString("Parametr","fio","");
  fiokass = ini->ReadString("Parametr","tel","");

  delete ini;

  fileIn=getWorkDir()+"Template\\vedofpor.xlsx";
  fileOut=getWorkDir()+"OUT\\";
  date.DecodeDate(&y1,&m1,&d1);
  date1.DecodeDate(&y2,&m2,&d2);
  s=AnsiString().sprintf("%02d-%02d-%d",d1,m1,y1);
  s1=AnsiString().sprintf("%02d-%02d-%d",d2,m2,y2);
  fileOut+="vedofkolfor";
  fout+="vedofkolfor";
  fileOut+=s;
  fout+=s;
  fileOut+=s1+".xlsx";
  fout+=s1+".xlsx";
  if(FileExists(fileOut)) DeleteFile(fileOut);
  //Копируем шаблон
  if(templateCopy(fileIn,fileOut)== false) return "F";

  //Создаем Excel файл
  try
  {
    de=new DirectWorkExcel(fileOut,1);
  }
  catch(const Exception &exc)
  {
    MessageDlg("Ошибка создания объекта DirectWorkExcel\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
    return "F";
  }
  if(de->openFile(false)==false)
  {
    MessageDlg("Ошибка открытия Excel файла",mtWarning,TMsgDlgButtons() << mbOK,0);
    if(de!=NULL) delete de;
    return "F";
  }

  de->setSheetNumber(1);
  de->setCellValue(2,"A",odpp.Trim());
  de->setCellValue(3,"D",date.DateString());
  de->setCellValue(3,"J",date1.DateString());
  de->setCellValue(31,"K",fio.Trim());

 //Закрываем файл
  de->closeFile();
  delete de;
  return fout.Trim();
}

void __fastcall editvedofkolFile(TDataSet *DS1,TDataSet *DS2,TDataSet *DS3,TDataSet *DS4,TDataSet *DS5,TDataSet *DS6,TDataSet *DS7,TDataSet *DS8,AnsiString namefile,AnsiString fio,int ns)
{
DirectWorkExcel *de;
AnsiString fileOut;

fileOut=getWorkDir()+"OUT\\"+namefile;

//Создаем Excel файл
try
{
de=new DirectWorkExcel(fileOut,1);
}
catch(const Exception &exc)
{
MessageDlg("Ошибка создания объекта DirectWorkExcel\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
return;
}
if(de->openFile(false)==false)
{
MessageDlg("Ошибка открытия Excel файла",mtWarning,TMsgDlgButtons() << mbOK,0);
if(de!=NULL) delete de;
return;
}

de->setSheetNumber(1);

if(DS1->FieldByName("KOL")->AsInteger > 0){
de->setCellValue(ns,"B",fio.Trim());
de->setCellValue(ns,"C",DS1->FieldByName("KOL")->AsInteger);
de->setCellValue(ns,"D",AnsiString().sprintf("%.02lf",DS1->FieldByName("EXP")->AsFloat));
}

if(DS2->FieldByName("KOL")->AsInteger > 0){
de->setCellValue(ns,"B",fio.Trim());
de->setCellValue(ns,"E",DS2->FieldByName("KOL")->AsInteger);
de->setCellValue(ns,"F",AnsiString().sprintf("%.02lf",DS2->FieldByName("EXP")->AsFloat));
}

if(DS3->FieldByName("KOL")->AsInteger > 0){
de->setCellValue(ns,"B",fio.Trim());
de->setCellValue(ns,"G",DS3->FieldByName("KOL")->AsInteger);
de->setCellValue(ns,"H",AnsiString().sprintf("%.02lf",DS3->FieldByName("EXP")->AsFloat));

}

if(DS4->FieldByName("KOL")->AsInteger > 0){
de->setCellValue(ns,"B",fio.Trim());
de->setCellValue(ns,"I",DS4->FieldByName("KOL")->AsInteger);
de->setCellValue(ns,"J",AnsiString().sprintf("%.02lf",DS4->FieldByName("EXP")->AsFloat));
}

if(DS5->FieldByName("KOL")->AsInteger > 0){
de->setCellValue(ns,"B",fio.Trim());
de->setCellValue(ns,"K",DS5->FieldByName("KOL")->AsInteger);
de->setCellValue(ns,"L",AnsiString().sprintf("%.02lf",DS5->FieldByName("EXP")->AsFloat));
}

if(DS6->FieldByName("EXP")->AsFloat > 0){
de->setCellValue(ns,"B",fio.Trim());
de->setCellValue(ns,"R",AnsiString().sprintf("%.02lf",DS6->FieldByName("EXP")->AsFloat));
}

if(DS7->FieldByName("KOL")->AsInteger > 0){
de->setCellValue(ns,"B",fio.Trim());
de->setCellValue(ns,"Q",AnsiString().sprintf("%.02lf",DS7->FieldByName("EXP")->AsFloat));
}

if(DS8->FieldByName("EXP")->AsFloat > 0){
de->setCellValue(ns,"B",fio.Trim());
de->setCellValue(ns,"S",AnsiString().sprintf("%.02lf",DS8->FieldByName("EXP")->AsFloat));
}

 //Закрываем файл
de->closeFile();
delete de;
return;
}

void __fastcall deletevedofkolFile(AnsiString namefile,int ns1)
{
DirectWorkExcel *de;
AnsiString fileOut;
int razn;

fileOut=getWorkDir()+"OUT\\"+namefile;

//Создаем Excel файл
try
{
de=new DirectWorkExcel(fileOut,1);
}
catch(const Exception &exc)
{
MessageDlg("Ошибка создания объекта DirectWorkExcel\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
return;
}
if(de->openFile(false)==false)
{
MessageDlg("Ошибка открытия Excel файла",mtWarning,TMsgDlgButtons() << mbOK,0);
if(de!=NULL) delete de;
return;
}
de->setSheetNumber(1);
de->deleteRange(IntToStr(ns1),IntToStr(27));
 //Закрываем файл
de->closeFile();
delete de;
return;
}

//Функция формирования файла с формой кассовой книги
AnsiString __fastcall createkassaglFile(TDate date,TDate date1,TDataSet *DS1,TDataSet *DS2,TDataSet *DS3,TDataSet *DS4,TDataSet *DS5,TDataSet *DS6,TDataSet *DS7,TDataSet *DS8)
{
AnsiString fileIn,s,s1,k,itogsum;
AnsiString fileOut;
unsigned short y1,m1,d1;
unsigned short y2,m2,d2;
DirectWorkExcel *de;
AnsiString fout;
AnsiString odpp,fio;
TIniFile* ini;
AnsiString workDir;
AnsiString iniFileName;
AnsiString fiokass;


  workDir=ExtractFilePath(Application->ExeName);
  iniFileName=workDir+"AccountGSM.ini";
  ini=new TIniFile(iniFileName);
  odpp = ini->ReadString("Parametr","odpp","");
  fio = ini->ReadString("Parametr","fio","");
  fiokass = ini->ReadString("Parametr","tel","");

  delete ini;

  fileIn=getWorkDir()+"Template\\kassagl.xlsx";
  fileOut=getWorkDir()+"OUT\\";
  date.DecodeDate(&y1,&m1,&d1);
  date1.DecodeDate(&y2,&m2,&d2);
  s=AnsiString().sprintf("%02d-%d",m1,y1);
  fileOut+="kassaglfor";
  fout+="kassaglfor";
  fileOut+=s;
  fout+=s;
  fileOut+=+".xlsx";
  fout+=+".xlsx";
  if(FileExists(fileOut)) DeleteFile(fileOut);
  //Копируем шаблон
  if(templateCopy(fileIn,fileOut)== false) return "F";

  //Создаем Excel файл
  try
  {
    de=new DirectWorkExcel(fileOut,1);
  }
  catch(const Exception &exc)
  {
    MessageDlg("Ошибка создания объекта DirectWorkExcel\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
    return "F";
  }
  if(de->openFile(false)==false)
  {
    MessageDlg("Ошибка открытия Excel файла",mtWarning,TMsgDlgButtons() << mbOK,0);
    if(de!=NULL) delete de;
    return "F";
  }

  de->setSheetNumber(1);

  if(DS1->FieldByName("SUM_EXP")->AsFloat != 0){
  de->setCellValue(6,"AA",AnsiString().sprintf("%.02lf",DS1->FieldByName("SUM_EXP")->AsFloat));
  }

  if(DS2->FieldByName("SUM_EXP")->AsFloat != 0){
  de->setCellValue(6,"AB",AnsiString().sprintf("%.02lf",DS2->FieldByName("SUM_EXP")->AsFloat));
  }

  if(DS3->FieldByName("SUM_EXP")->AsFloat != 0){
  de->setCellValue(6,"AC",AnsiString().sprintf("%.02lf",DS3->FieldByName("SUM_EXP")->AsFloat));
  }

  if(DS4->FieldByName("SUM_EXP")->AsFloat != 0){
  de->setCellValue(6,"AD",AnsiString().sprintf("%.02lf",DS4->FieldByName("SUM_EXP")->AsFloat));
  }

  if(DS5->FieldByName("SUM_EXP")->AsFloat != 0){
  de->setCellValue(6,"AF",AnsiString().sprintf("%.02lf",DS5->FieldByName("SUM_EXP")->AsFloat));
  }

  if(DS6->FieldByName("SUM_EXP")->AsFloat != 0){
  de->setCellValue(6,"AE",AnsiString().sprintf("%.02lf",DS6->FieldByName("SUM_EXP")->AsFloat));
  }

  if(DS7->FieldByName("SUM_EXP")->AsFloat != 0){
  de->setCellValue(6,"AG",AnsiString().sprintf("%.02lf",DS7->FieldByName("SUM_EXP")->AsFloat));
  }

  if(DS8->FieldByName("SUM_EXP")->AsFloat != 0){
  de->setCellValue(6,"AH",AnsiString().sprintf("%.02lf",DS8->FieldByName("SUM_EXP")->AsFloat));
  }

  de->setCellValue(1,"A",odpp.Trim());
  de->setCellValue(2,"A",date.DateString());
  de->setCellValue(40,"C",odpp.Trim());
  de->setCellValue(40,"H",fio.Trim());

 //Закрываем файл
  de->closeFile();
  delete de;
  return fout.Trim();
}

void __fastcall editkassaglFile(TDataSet *DS1,TDataSet *DS2,TDataSet *DS3,TDataSet *DS4,TDataSet *DS5,TDataSet *DS6,TDataSet *DS7,TDataSet *DS8,TDataSet *DS9,TDataSet *DS10,TDataSet *DS11,TDataSet *DS12,TDataSet *DS13,TDataSet *DS14,TDataSet *DS15,TDataSet *DS16,TDataSet *DS17,TDataSet *DS18,TDataSet *DS19,TDataSet *DS20,TDataSet *DS21,TDataSet *DS22, AnsiString namefile,int ns)
{
DirectWorkExcel *de;
AnsiString fileOut;
int numrow=6;

fileOut=getWorkDir()+"OUT\\"+namefile;

//Создаем Excel файл
try
{
de=new DirectWorkExcel(fileOut,1);
}
catch(const Exception &exc)
{
MessageDlg("Ошибка создания объекта DirectWorkExcel\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
return;
}
if(de->openFile(false)==false)
{
MessageDlg("Ошибка открытия Excel файла",mtWarning,TMsgDlgButtons() << mbOK,0);
if(de!=NULL) delete de;
return;
}

de->setSheetNumber(1);

if(DS1->FieldByName("SUM_EXP")->AsFloat != 0){
de->setCellValue(numrow+ns,"B",AnsiString().sprintf("%.02lf",DS1->FieldByName("SUM_EXP")->AsFloat));
de->setCellValue(numrow+ns,"A",ns);
}

if(DS2->FieldByName("SUM_EXP")->AsFloat != 0){
de->setCellValue(numrow+ns,"C",AnsiString().sprintf("%.02lf",DS2->FieldByName("SUM_EXP")->AsFloat));
de->setCellValue(numrow+ns,"A",ns);
}

if(DS3->FieldByName("SUM_EXP")->AsFloat != 0){
de->setCellValue(numrow+ns,"F",AnsiString().sprintf("%.02lf",DS3->FieldByName("SUM_EXP")->AsFloat));
de->setCellValue(numrow+ns,"A",ns);
}

if(DS4->FieldByName("SUM_EXP")->AsFloat != 0){
de->setCellValue(numrow+ns,"L",AnsiString().sprintf("%.02lf",DS4->FieldByName("SUM_EXP")->AsFloat));
de->setCellValue(numrow+ns,"A",ns);
}

if(DS5->FieldByName("SUM_EXP")->AsFloat != 0){
de->setCellValue(numrow+ns,"M",AnsiString().sprintf("%.02lf",DS5->FieldByName("SUM_EXP")->AsFloat));
de->setCellValue(numrow+ns,"A",ns);
}

if(DS7->FieldByName("SUM_EXP")->AsFloat != 0){
de->setCellValue(numrow+ns,"R",AnsiString().sprintf("%.02lf",DS7->FieldByName("SUM_EXP")->AsFloat));
de->setCellValue(numrow+ns,"A",ns);
}

if(DS8->FieldByName("SUM_EXP")->AsFloat != 0){
de->setCellValue(numrow+ns,"S",AnsiString().sprintf("%.02lf",DS8->FieldByName("SUM_EXP")->AsFloat));
de->setCellValue(numrow+ns,"A",ns);
}

if(DS9->FieldByName("SUM_EXP")->AsFloat != 0){
de->setCellValue(numrow+ns,"T",AnsiString().sprintf("%.02lf",DS9->FieldByName("SUM_EXP")->AsFloat));
de->setCellValue(numrow+ns,"A",ns);
}

if(DS10->FieldByName("SUM_EXP")->AsFloat != 0){
de->setCellValue(numrow+ns,"D",AnsiString().sprintf("%.02lf",DS10->FieldByName("SUM_EXP")->AsFloat));
de->setCellValue(numrow+ns,"A",ns);
}

if(DS11->FieldByName("SUM_EXP")->AsFloat != 0){
de->setCellValue(numrow+ns,"E",AnsiString().sprintf("%.02lf",DS11->FieldByName("SUM_EXP")->AsFloat));
de->setCellValue(numrow+ns,"A",ns);
}

if(DS12->FieldByName("SUM_EXP")->AsFloat != 0){
de->setCellValue(numrow+ns,"O",AnsiString().sprintf("%.02lf",DS12->FieldByName("SUM_EXP")->AsFloat));
de->setCellValue(numrow+ns,"A",ns);
}

if(DS13->FieldByName("SUM_EXP")->AsFloat != 0){
de->setCellValue(numrow+ns,"U",AnsiString().sprintf("%.02lf",DS13->FieldByName("SUM_EXP")->AsFloat));
de->setCellValue(numrow+ns,"A",ns);
}

if(DS14->FieldByName("SUM_EXP")->AsFloat != 0){
de->setCellValue(numrow+ns,"H",AnsiString().sprintf("%.02lf",DS14->FieldByName("SUM_EXP")->AsFloat));
de->setCellValue(numrow+ns,"A",ns);
}

if(DS15->FieldByName("SUM_EXP")->AsFloat != 0){
de->setCellValue(numrow+ns,"W",AnsiString().sprintf("%.02lf",DS15->FieldByName("SUM_EXP")->AsFloat));
de->setCellValue(numrow+ns,"A",ns);
}

if(DS16->FieldByName("SUM_EXP")->AsFloat != 0){
de->setCellValue(numrow+ns,"G",AnsiString().sprintf("%.02lf",DS16->FieldByName("SUM_EXP")->AsFloat));
de->setCellValue(numrow+ns,"A",ns);
}

if(DS17->FieldByName("SUM_EXP")->AsFloat != 0){
de->setCellValue(numrow+ns,"V",AnsiString().sprintf("%.02lf",DS17->FieldByName("SUM_EXP")->AsFloat));
de->setCellValue(numrow+ns,"A",ns);
}

if(DS18->FieldByName("SUM_EXP")->AsFloat != 0){
de->setCellValue(numrow+ns,"I",AnsiString().sprintf("%.02lf",DS18->FieldByName("SUM_EXP")->AsFloat));
de->setCellValue(numrow+ns,"A",ns);
}

if(DS19->FieldByName("SUM_EXP")->AsFloat != 0){
de->setCellValue(numrow+ns,"X",AnsiString().sprintf("%.02lf",DS19->FieldByName("SUM_EXP")->AsFloat));
de->setCellValue(numrow+ns,"A",ns);
}

if(DS20->FieldByName("SUM_EXP")->AsFloat != 0){
de->setCellValue(numrow+ns,"P",AnsiString().sprintf("%.02lf",DS20->FieldByName("SUM_EXP")->AsFloat));
de->setCellValue(numrow+ns,"A",ns);
}

if(DS21->FieldByName("SUM_EXP")->AsFloat != 0){
de->setCellValue(numrow+ns,"J",AnsiString().sprintf("%.02lf",DS21->FieldByName("SUM_EXP")->AsFloat));
de->setCellValue(numrow+ns,"A",ns);
}

if(DS22->FieldByName("SUM_EXP")->AsFloat != 0){
de->setCellValue(numrow+ns,"Y",AnsiString().sprintf("%.02lf",DS22->FieldByName("SUM_EXP")->AsFloat));
de->setCellValue(numrow+ns,"A",ns);
}

 //Закрываем файл
de->closeFile();
delete de;
return;
}

//Функция формирования файла с формой Ф55 ведомость
int __fastcall createF55vedFile(TDataSet *DS,TDate date,AnsiString namefile,AnsiString fio,int nr)
{
AnsiString fileIn,s,k,itogsum;
Double ValueS,RasS,NeoplS;
int ValueK,RasK,NeoplK,KItog;
AnsiString fileOut;
unsigned short y,m,d1;
DirectWorkExcel *de;
AnsiString fout;
int i=1;
int ns;
Double P1,P2,PItog;
AnsiString fiokass;
TIniFile* ini;
AnsiString workDir;
AnsiString iniFileName;
AnsiString FIO,FIOPropis;
ns=nr;

  workDir=ExtractFilePath(Application->ExeName);
  iniFileName=workDir+"AccountGSM.ini";
  ini=new TIniFile(iniFileName);
  fiokass = ini->ReadString("Parametr","tel","");
  delete ini;


  P1=950000.00;
  P2=900000.00;
  DS->First();
  ValueS=DS->FieldByName("EXP_SUM")->AsFloat;
  ValueK=DS->FieldByName("KOL_SUM")->AsInteger;
  if (ValueK==0)
  {
//  MessageDlg("Нет данных для формирования формы 55. Формирования отчетов прервано!!! ",mtWarning,TMsgDlgButtons() << mbOK,0);
  return ns;
  }


  //Создаем Excel файл
  try
  {
    de=new DirectWorkExcel(namefile,1);
  }
  catch(const Exception &exc)
  { MessageDlg("Ошибка создания объекта DirectWorkExcel\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
    return ns;
  }
  if(de->openFile(false)==false)
  {
    MessageDlg("Ошибка открытия Excel файла",mtWarning,TMsgDlgButtons() << mbOK,0);
    if(de!=NULL) delete de;
    return ns;
  }

  de->setSheetNumber(1);
  DS->First();
  PItog=0.00;
  KItog=0;
 while(!DS->Eof)
 {
  i=1;
  ValueS=DS->FieldByName("EXP_SUM")->AsFloat;
  ValueK=DS->FieldByName("KOL_SUM")->AsInteger;
  P1=950000.00;
  P2=900000.00;
  PItog=PItog+ValueS;
  KItog=KItog+ValueK;
  if (ValueS<=950000.00)
  {
     P1=ValueS;
     AnsiString FIOPropis=fio.Trim() + " " + IntToStr(ValueK) + " поручений  на сумму " + AnsiString().sprintf("%.02lf",P1) + " руб. ";
     de->setCellValue(ns,"B",FIOPropis.Trim());
     de->setCellValue(ns,"A",date.DateString());
     AnsiString KolPropis=IntToStr(ValueK) + " поручений  и наличные деньги в сумме " + f_to_str(floor(P1*100+0.5)/100) + " принял почтальон ";
     de->setCellValue(ns,"C",KolPropis);
     ValueS=ValueS-950000.00;
     ns=ns+6;
     de->setCellValue(ns,"A",date.DateString());
     FIOPropis=FIO.Trim() + " ИТОГО: ";
     de->setCellValue(ns,"B",FIOPropis.Trim());
     ns=ns+5;
     AnsiString Pol=" получил кассир ";
     de->setCellValue(ns,"G",Pol.Trim());
     AnsiString Sd=" сдал почтальон ";
     de->setCellValue(ns,"I",Sd.Trim());
     ns++;
  }else{
  while (ValueS>900000.00)
  {
    if (i==1)
    {
     AnsiString FIOPropis=fio.Trim() + " " + IntToStr(ValueK) + " поручений  на сумму " + AnsiString().sprintf("%.02lf",P1) + " руб. ";
     de->setCellValue(ns,"B",FIOPropis.Trim());
     de->setCellValue(ns,"A",date.DateString());
     AnsiString KolPropis=IntToStr(ValueK) + " поручений  и наличные деньги в сумме " + f_to_str(P1)+ " принял почтальон ";
     de->setCellValue(ns,"C",KolPropis);
     ValueS=ValueS-950000.00;
//     ns=ns+6;
  }else
    {
     AnsiString FIOPropis=fio.Trim() + " 0 " +  " поручений  на сумму " + AnsiString().sprintf("%.02lf",P2) + " руб. ";
     de->setCellValue(ns,"B",FIOPropis.Trim());
     de->setCellValue(ns,"A",date.DateString());
     AnsiString KolPropis="0 поручений  и наличные деньги в сумме " + f_to_str(P2)+ " принял почтальон ";
     de->setCellValue(ns,"C",KolPropis);
     ValueS=ValueS-900000.00;
//     ns=ns+6;
    }
   i++;
   ns=ns+6;
  }
  }
  if (ValueS>0){
   AnsiString FIOPropis=fio.Trim() + " 0 " +  " поручений  на сумму " + AnsiString().sprintf("%.02lf",ValueS) + " руб. ";
   de->setCellValue(ns,"B",FIOPropis.Trim());
   de->setCellValue(ns,"A",date.DateString());
//   de->setCellValue(ns+1,"D",f_to_str(floor(ValueS*100+0.5)/100));

   AnsiString KolPropis="0 поручений  и наличные деньги в сумме " + f_to_str(floor(ValueS*100+0.5)/100) + " принял почтальон ";
   de->setCellValue(ns,"C",KolPropis);
   de->setCellValue(ns,"A",date.DateString());
   ns=ns+6;
   FIOPropis=FIO.Trim() + " ИТОГО: ";
   de->setCellValue(ns,"B",FIOPropis.Trim());
   ns=ns+5;
   AnsiString Pol=" получил кассир ";
   de->setCellValue(ns,"G",Pol.Trim());
   AnsiString Sd=" сдал почтальон ";
   de->setCellValue(ns,"I",Sd.Trim());
   ns++;
  }
 DS->Next();
 }

 //Закрываем файл
  de->closeFile();
  delete de;
  DS->Close();
  return ns;
}

void __fastcall newost(TDateTime DateInp)
{
double ost1,ost2,val1,val2,val4,val5,val6,val7,val8,val9,val10,val11,val12,val13,val14,val15,val16,val17,val18,val19,val20,val21,val22,val23,val24,val3,ost3,ost4,ost5,ost6,ost7,ost8,val25,val26,val27,val28,val29,val30,val31,val32,val33,ost9,val34,val35,val36,val37,val38,val39,val40,ost10;
TDate date,datemin;
TpFIBQuery *Q=GSM_DM->WQ;
TpFIBQuery *QR=GSM_DM->RQ;
AnsiString sql;
unsigned short y,m,d1;
unsigned short ym,mm,dm;
double ostmedv,ostpens,ostpogr,ostredv,osttown,ostperev,ostgood,ostpodp,ostloto;
int codchef;



    sql="";
    QR->Close();
    QR->SQL->Clear();
    sql="select ";
    sql+="min( expenses_table.exp_date ) min_of_date ";
    sql+="from expenses_table ";
    sql+="left outer join oper_table on (expenses_table.gsm_id = oper_table.id) ";
    sql+="where ";
    sql+=" oper_table.file_id = 48";
    sql+=" and oper_table.visible = 1";
    QR->SQL->Add(sql);
    try
    {
      QR->ExecQuery();
      datemin=QR->FieldByName("MIN_OF_DATE")->AsDateTime;
      datemin.DecodeDate(&ym,&mm,&dm);
    }
    catch (Exception &exc)
    {
      MessageDlg("Ошибка - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      return;
    }


    sql="";
    QR->Close();
    QR->SQL->Clear();
    sql="select ";
    sql+="max( expenses_table.exp_date ) max_of_date ";
    sql+="from expenses_table ";
    sql+="left outer join oper_table on (expenses_table.gsm_id = oper_table.id) ";
    sql+="where ";
    sql+=" oper_table.file_id = 48";
    sql+=" and oper_table.visible = 1";
    sql+=" and expenses_table.exp_date < '"+DateInp.DateString()+" ' ";
    QR->SQL->Add(sql);
    try
    {
      QR->ExecQuery();
      date=QR->FieldByName("MAX_OF_DATE")->AsDateTime;
      date.DecodeDate(&y,&m,&d1);
    }
    catch (Exception &exc)
    {
      MessageDlg("Ошибка - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      return;
    }

// определяем код пользователя с ролью руководителя

    sql="";
    QR->Close();
    QR->SQL->Clear();
    sql="select users_table.u_id from users_table ";
    sql+="where ";
    sql+=" users_table.u_role = 'руководитель'";
    QR->SQL->Add(sql);
    try
    {
      QR->ExecQuery();
      codchef=QR->FieldByName("U_ID")->AsInteger;
    }
    catch (Exception &exc)
    {
      MessageDlg("Ошибка - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      return;
    }



    sql="";
    QR->Close();
    QR->SQL->Clear();
    sql="select ";
    sql+="sum(expenses_table.expense) sum_of_exp ";
    sql+="from expenses_table ";
    sql+="left outer join oper_table on (expenses_table.gsm_id = oper_table.id) ";
    sql+="where ";
    sql+=" oper_table.file_id = 48";
    sql+=" and oper_table.visible = 1";
    sql+=" and expenses_table.exp_date = '"+date.DateString()+" ' ";

    QR->SQL->Add(sql);
    try
    {
      QR->ExecQuery();
      ost1=QR->FieldByName("SUM_OF_EXP")->AsFloat;
    }
    catch (Exception &exc)
    {
      MessageDlg("Ошибка - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      return;
    }

    sql="";
    QR->Close();
    QR->SQL->Clear();
    sql="select ";
    sql+="sum(expenses_table.expense) sum_of_exp ";
    sql+="from expenses_table ";
    sql+="left outer join oper_table on (expenses_table.gsm_id = oper_table.id) ";
    sql+="where ";
    sql+=" oper_table.id = 60";
    sql+=" and oper_table.visible = 1";
    sql+=" and expenses_table.exp_date = '"+date.DateString()+" ' ";

    QR->SQL->Add(sql);
    try
    {
      QR->ExecQuery();
      ost2=QR->FieldByName("SUM_OF_EXP")->AsFloat;
    }
    catch (Exception &exc)
    {
      MessageDlg("Ошибка - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      return;
    }

    sql="";
    QR->Close();
    QR->SQL->Clear();
    sql="select ";
    sql+="sum(expenses_table.expense) sum_of_exp ";
    sql+="from expenses_table ";
    sql+="left outer join oper_table on (expenses_table.gsm_id = oper_table.id) ";
    sql+="where ";
    sql+=" oper_table.id IN (59,63)";
    sql+=" and oper_table.visible = 1";
    sql+=" and expenses_table.exp_date = '"+date.DateString()+" ' ";

    QR->SQL->Add(sql);
    try
    {
      QR->ExecQuery();
      ost3=QR->FieldByName("SUM_OF_EXP")->AsFloat;
    }
    catch (Exception &exc)
    {
      MessageDlg("Ошибка - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      return;
    }

    sql="";
    QR->Close();
    QR->SQL->Clear();
    sql="select ";
    sql+="sum(expenses_table.expense) sum_of_exp ";
    sql+="from expenses_table ";
    sql+="left outer join oper_table on (expenses_table.gsm_id = oper_table.id) ";
    sql+="where ";
    sql+=" oper_table.id IN (64)";
    sql+=" and oper_table.visible = 1";
    sql+=" and expenses_table.exp_date = '"+date.DateString()+" ' ";

    QR->SQL->Add(sql);
    try
    {
      QR->ExecQuery();
      ost7=QR->FieldByName("SUM_OF_EXP")->AsFloat;
    }
    catch (Exception &exc)
    {
      MessageDlg("Ошибка - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      return;
    }

    sql="";
    QR->Close();
    QR->SQL->Clear();
    sql="select ";
    sql+="sum(expenses_table.expense) sum_of_exp ";
    sql+="from expenses_table ";
    sql+="left outer join oper_table on (expenses_table.gsm_id = oper_table.id) ";
    sql+="where ";
    sql+=" oper_table.id = 81";
    sql+=" and oper_table.visible = 1";
    sql+=" and expenses_table.exp_date = '"+date.DateString()+" ' ";

    QR->SQL->Add(sql);
    try
    {
      QR->ExecQuery();
      ost5=QR->FieldByName("SUM_OF_EXP")->AsFloat;
    }
    catch (Exception &exc)
    {
      MessageDlg("Ошибка - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      return;
    }

    sql="";
    QR->Close();
    QR->SQL->Clear();
    sql="select ";
    sql+="sum(expenses_table.expense) sum_of_exp ";
    sql+="from expenses_table ";
    sql+="left outer join oper_table on (expenses_table.gsm_id = oper_table.id) ";
    sql+="where ";
    sql+=" oper_table.id = 90";
    sql+=" and oper_table.visible = 1";
    sql+=" and expenses_table.exp_date = '"+date.DateString()+" ' ";

    QR->SQL->Add(sql);
    try
    {
      QR->ExecQuery();
      ost8=QR->FieldByName("SUM_OF_EXP")->AsFloat;
    }
    catch (Exception &exc)
    {
      MessageDlg("Ошибка - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      return;
    }

    sql="";
    QR->Close();
    QR->SQL->Clear();
    sql="select ";
    sql+="sum(expenses_table.expense) sum_of_exp ";
    sql+="from expenses_table ";
    sql+="left outer join oper_table on (expenses_table.gsm_id = oper_table.id) ";
    sql+="where ";
    sql+=" oper_table.id = 95";
    sql+=" and oper_table.visible = 1";
    sql+=" and expenses_table.exp_date = '"+date.DateString()+" ' ";

    QR->SQL->Add(sql);
    try
    {
      QR->ExecQuery();
      ost9=QR->FieldByName("SUM_OF_EXP")->AsFloat;
    }
    catch (Exception &exc)
    {
      MessageDlg("Ошибка - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      return;
    }

    sql="";
    QR->Close();
    QR->SQL->Clear();
    sql="select ";
    sql+="sum(expenses_table.expense) sum_of_exp ";
    sql+="from expenses_table ";
    sql+="left outer join oper_table on (expenses_table.gsm_id = oper_table.id) ";
    sql+="where ";
    sql+=" oper_table.id = 102";
    sql+=" and oper_table.visible = 1";
    sql+=" and expenses_table.exp_date = '"+date.DateString()+" ' ";

    QR->SQL->Add(sql);
    try
    {
      QR->ExecQuery();
      ost10=QR->FieldByName("SUM_OF_EXP")->AsFloat;
    }
    catch (Exception &exc)
    {
      MessageDlg("Ошибка - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      return;
    }


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
val36=0.0;
ost6=0.0;
val34=0.0;
val37=0.0;
val38=0.0;
val39=0.0;
val40=0.0;

double podkrpogr=0.0;
double podkrredv=0.0;
double podkrtown=0.0;
double podkrperev=0.0;
double limpogr=0.0;
double limredv=0.0;
double limperev=0.0;
double ostend=0.0;
ostgood=0.0;
int id=0;


// 2.12.1

    sql="";
    val31=0.0;
    QR->Close();
    QR->SQL->Clear();
    sql="select ";
    sql+="sum(expenses_table.expense) sum_of_exp ";
    sql+="from expenses_table ";
    sql+="left outer join oper_table on (expenses_table.gsm_id = oper_table.id) ";
    sql+="where ";
    sql+=" oper_table.id in (92)";
    sql+=" and oper_table.visible = 1";
    sql+=" and expenses_table.exp_date = '"+DateInp.DateString()+" ' ";

    QR->SQL->Add(sql);
    try
    {
      QR->ExecQuery();
      if (!QR->FieldByName("SUM_OF_EXP")->IsNull) val31=QR->FieldByName("SUM_OF_EXP")->AsFloat;
    }
    catch (Exception &exc)
    {
      MessageDlg("Ошибка - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      return;
    }

// 3.23.1.3

    sql="";
    val1=0.0;
    QR->Close();
    QR->SQL->Clear();
    sql="select ";
    sql+="sum(expenses_table.expense) sum_of_exp ";
    sql+="from expenses_table ";
    sql+="left outer join oper_table on (expenses_table.gsm_id = oper_table.id) ";
    sql+="where ";
    sql+=" oper_table.id = 98";
    sql+=" and oper_table.visible = 1";
    sql+=" and expenses_table.exp_date = '"+DateInp.DateString()+" ' ";

    QR->SQL->Add(sql);
    try
    {
      QR->ExecQuery();
      if (!QR->FieldByName("SUM_OF_EXP")->IsNull) val1=QR->FieldByName("SUM_OF_EXP")->AsFloat;
    }
    catch (Exception &exc)
    {
      MessageDlg("Ошибка - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      return;
    }

    sql="";
    QR->Close();
    QR->SQL->Clear();
    sql="select ";
    sql+="sum(expenses_table.expense) sum_of_exp ";
    sql+="from expenses_table ";
    sql+="left outer join oper_table on (expenses_table.gsm_id = oper_table.id) ";
    sql+="where ";
    sql+=" oper_table.id = 58";
    sql+=" and oper_table.visible = 1";
    sql+=" and expenses_table.d = 1";
    sql+=" and expenses_table.exp_date = '"+DateInp.DateString()+" ' ";

    QR->SQL->Add(sql);
    try
    {
      QR->ExecQuery();
      if (!QR->FieldByName("SUM_OF_EXP")->IsNull) val36=QR->FieldByName("SUM_OF_EXP")->AsFloat;
    }
    catch (Exception &exc)
    {
      MessageDlg("Ошибка - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      return;
    }

// 3.2.1.1

    sql="";
    val2=0.0;
    QR->Close();
    QR->SQL->Clear();
    sql="select ";
    sql+="sum(expenses_table.expense) sum_of_exp ";
    sql+="from expenses_table ";
    sql+="left outer join oper_table on (expenses_table.gsm_id = oper_table.id) ";
    sql+="where ";
    sql+=" oper_table.id = 55";
    sql+=" and oper_table.visible = 1";
    sql+=" and expenses_table.exp_date = '"+DateInp.DateString()+" ' ";

    QR->SQL->Add(sql);
    try
    {
      QR->ExecQuery();
      if (!QR->FieldByName("SUM_OF_EXP")->IsNull) val2=QR->FieldByName("SUM_OF_EXP")->AsFloat;
    }
    catch (Exception &exc)
    {
      MessageDlg("Ошибка - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      return;
    }


// 3.1.1.1

    sql="";
    val3=0.0;
    QR->Close();
    QR->SQL->Clear();
    sql="select ";
    sql+="sum(expenses_table.expense) sum_of_exp ";
    sql+="from expenses_table ";
    sql+="left outer join oper_table on (expenses_table.gsm_id = oper_table.id) ";
    sql+="where ";
    sql+=" oper_table.id IN (57) ";
    sql+=" and oper_table.visible = 1";
    sql+=" and expenses_table.exp_date = '"+DateInp.DateString()+" ' ";

    QR->SQL->Add(sql);
    try
    {
      QR->ExecQuery();
      if (!QR->FieldByName("SUM_OF_EXP")->IsNull) val3=QR->FieldByName("SUM_OF_EXP")->AsFloat;
    }
    catch (Exception &exc)
    {
      MessageDlg("Ошибка - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      return;
    }

// 4.5.1.1

    sql="";
    val5=0.0;
    QR->Close();
    QR->SQL->Clear();
    sql="select ";
    sql+="sum(expenses_table.expense) sum_of_exp ";
    sql+="from expenses_table ";
    sql+="left outer join oper_table on (expenses_table.gsm_id = oper_table.id) ";
    sql+="where ";
    sql+=" oper_table.id IN (35,39) ";
    sql+=" and oper_table.visible = 1";
    sql+=" and expenses_table.exp_date = '"+DateInp.DateString()+" ' ";

    QR->SQL->Add(sql);
    try
    {
      QR->ExecQuery();
      if (!QR->FieldByName("SUM_OF_EXP")->IsNull) val5=QR->FieldByName("SUM_OF_EXP")->AsFloat;
    }
    catch (Exception &exc)
    {
      MessageDlg("Ошибка - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      return;
    }

    val6=0.0;

// 4.6.1.17  ЕДК

    sql="";
    val7=0.0;
    QR->Close();
    QR->SQL->Clear();
    sql="select ";
    sql+="sum(expenses_table.expense) sum_of_exp ";
    sql+="from expenses_table ";
    sql+="left outer join oper_table on (expenses_table.gsm_id = oper_table.id) ";
    sql+="where ";
    sql+=" oper_table.id IN (36,37)";
    sql+=" and oper_table.visible = 1";
    sql+=" and expenses_table.exp_date = '"+DateInp.DateString()+" ' ";

    QR->SQL->Add(sql);
    try
    {
      QR->ExecQuery();
      if (!QR->FieldByName("SUM_OF_EXP")->IsNull) val7=QR->FieldByName("SUM_OF_EXP")->AsFloat;
    }
    catch (Exception &exc)
    {
      MessageDlg("Ошибка - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      return;
    }

// 4.6.1.5.1 ЕДВ

    val8=0.0;

// 4.22.1

    sql="";
    val16=0.0;
    QR->Close();
    QR->SQL->Clear();
    sql="select ";
    sql+="sum(expenses_table.expense) sum_of_exp ";
    sql+="from expenses_table ";
    sql+="left outer join oper_table on (expenses_table.gsm_id = oper_table.id) ";
    sql+="where ";
    sql+=" oper_table.file_id IN (46) ";
    sql+=" and oper_table.visible = 1";
    sql+=" and expenses_table.exp_date = '"+DateInp.DateString()+" ' ";

    QR->SQL->Add(sql);
    try
    {
      QR->ExecQuery();
      if (!QR->FieldByName("SUM_OF_EXP")->IsNull) val16=QR->FieldByName("SUM_OF_EXP")->AsFloat;
    }
    catch (Exception &exc)
    {
      MessageDlg("Ошибка - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      return;
    }

// 4.34.1.1.1

    sql="";
    val17=0.0;
    QR->Close();
    QR->SQL->Clear();
    sql="select ";
    sql+="sum(expenses_table.expense) sum_of_exp ";
    sql+="from expenses_table ";
    sql+="left outer join oper_table on (expenses_table.gsm_id = oper_table.id) ";
    sql+="where ";
    sql+=" oper_table.id IN (53) ";
    sql+=" and oper_table.visible = 1";
    sql+=" and expenses_table.exp_date = '"+DateInp.DateString()+" ' ";

    QR->SQL->Add(sql);
    try
    {
      QR->ExecQuery();
      if (!QR->FieldByName("SUM_OF_EXP")->IsNull) val17=QR->FieldByName("SUM_OF_EXP")->AsFloat;
    }
    catch (Exception &exc)
    {
      MessageDlg("Ошибка - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      return;
    }

// 4.36.1.1

    sql="";
    val18=0.0;
    QR->Close();
    QR->SQL->Clear();
    sql="select ";
    sql+="sum(expenses_table.expense) sum_of_exp ";
    sql+="from expenses_table ";
    sql+="left outer join oper_table on (expenses_table.gsm_id = oper_table.id) ";
    sql+="where ";
    sql+=" oper_table.id IN (50) ";
    sql+=" and oper_table.visible = 1";
    sql+=" and expenses_table.exp_date = '"+DateInp.DateString()+" ' ";

    QR->SQL->Add(sql);
    try
    {
      QR->ExecQuery();
      if (!QR->FieldByName("SUM_OF_EXP")->IsNull) val18=QR->FieldByName("SUM_OF_EXP")->AsFloat;
    }
    catch (Exception &exc)
    {
      MessageDlg("Ошибка - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      return;
    }

// 4.34.1.1

    sql="";
    val19=0.0;
    QR->Close();
    QR->SQL->Clear();
    sql="select ";
    sql+="sum(expenses_table.expense) sum_of_exp ";
    sql+="from expenses_table ";
    sql+="left outer join oper_table on (expenses_table.gsm_id = oper_table.id) ";
    sql+="where ";
    sql+=" oper_table.id IN (52) ";
    sql+=" and oper_table.visible = 1";
    sql+=" and expenses_table.exp_date = '"+DateInp.DateString()+" ' ";

    QR->SQL->Add(sql);
    try
    {
      QR->ExecQuery();
      if (!QR->FieldByName("SUM_OF_EXP")->IsNull) val19=QR->FieldByName("SUM_OF_EXP")->AsFloat;
    }
    catch (Exception &exc)
    {
      MessageDlg("Ошибка - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      return;
    }

// подкрепления переводы

    sql="";
    val25=0.0;
    QR->Close();
    QR->SQL->Clear();
    sql="select ";
    sql+="sum(expenses_table.expense) sum_of_exp ";
    sql+="from expenses_table ";
    sql+="left outer join oper_table on (expenses_table.gsm_id = oper_table.id) ";
    sql+="where ";
    sql+=" oper_table.id = 79 ";
    sql+=" and oper_table.visible = 1";
    sql+=" and expenses_table.exp_date = '"+DateInp.DateString()+" ' ";

    QR->SQL->Add(sql);
    try
    {
      QR->ExecQuery();
      if (!QR->FieldByName("SUM_OF_EXP")->IsNull) val25=QR->FieldByName("SUM_OF_EXP")->AsFloat;
    }
    catch (Exception &exc)
    {
      MessageDlg("Ошибка - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      return;
    }

// сверхлимит переводы

    sql="";
    val29=0.0;
    QR->Close();
    QR->SQL->Clear();
    sql="select ";
    sql+="sum(expenses_table.expense) sum_of_exp ";
    sql+="from expenses_table ";
    sql+="left outer join oper_table on (expenses_table.gsm_id = oper_table.id) ";
    sql+="where ";
    sql+=" oper_table.id = 80 ";
    sql+=" and oper_table.visible = 1";
    sql+=" and expenses_table.exp_date = '"+DateInp.DateString()+" ' ";

    QR->SQL->Add(sql);
    try
    {
      QR->ExecQuery();
      if (!QR->FieldByName("SUM_OF_EXP")->IsNull) val29=QR->FieldByName("SUM_OF_EXP")->AsFloat;
    }
    catch (Exception &exc)
    {
      MessageDlg("Ошибка - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      return;
    }

// сверхлимит продажа товаров

    sql="";
    val33=0.0;
    QR->Close();
    QR->SQL->Clear();
    sql="select ";
    sql+="sum(expenses_table.expense) sum_of_exp ";
    sql+="from expenses_table ";
    sql+="left outer join oper_table on (expenses_table.gsm_id = oper_table.id) ";
    sql+="where ";
    sql+=" oper_table.id = 91 ";
    sql+=" and oper_table.visible = 1";
    sql+=" and expenses_table.exp_date = '"+DateInp.DateString()+" ' ";

    QR->SQL->Add(sql);
    try
    {
      QR->ExecQuery();
      if (!QR->FieldByName("SUM_OF_EXP")->IsNull) val33=QR->FieldByName("SUM_OF_EXP")->AsFloat;
    }
    catch (Exception &exc)
    {
      MessageDlg("Ошибка - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      return;
    }

// сверхлимит подписка

    sql="";
    val35=0.0;
    QR->Close();
    QR->SQL->Clear();
    sql="select ";
    sql+="sum(expenses_table.expense) sum_of_exp ";
    sql+="from expenses_table ";
    sql+="left outer join oper_table on (expenses_table.gsm_id = oper_table.id) ";
    sql+="where ";
    sql+=" oper_table.id = 94 ";
    sql+=" and oper_table.visible = 1";
    sql+=" and expenses_table.exp_date = '"+DateInp.DateString()+" ' ";

    QR->SQL->Add(sql);
    try
    {
      QR->ExecQuery();
      if (!QR->FieldByName("SUM_OF_EXP")->IsNull) val35=QR->FieldByName("SUM_OF_EXP")->AsFloat;
    }
    catch (Exception &exc)
    {
      MessageDlg("Ошибка - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      return;
    }


// сверхлимит лотерея

    sql="";
    val38=0.0;
    QR->Close();
    QR->SQL->Clear();
    sql="select ";
    sql+="sum(expenses_table.expense) sum_of_exp ";
    sql+="from expenses_table ";
    sql+="left outer join oper_table on (expenses_table.gsm_id = oper_table.id) ";
    sql+="where ";
    sql+=" oper_table.id = 100 ";
    sql+=" and oper_table.visible = 1";
    sql+=" and expenses_table.exp_date = '"+DateInp.DateString()+" ' ";

    QR->SQL->Add(sql);
    try
    {
      QR->ExecQuery();
      if (!QR->FieldByName("SUM_OF_EXP")->IsNull) val38=QR->FieldByName("SUM_OF_EXP")->AsFloat;
    }
    catch (Exception &exc)
    {
      MessageDlg("Ошибка - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      return;
    }

// поступления Почта-Банк

    sql="";
    val26=0.0;
    QR->Close();
    QR->SQL->Clear();
    sql="select ";
    sql+="sum(expenses_table.expense) sum_of_exp ";
    sql+="from expenses_table ";
    sql+="left outer join oper_table on (expenses_table.gsm_id = oper_table.id) ";
    sql+="where ";
    sql+=" oper_table.id = 97 ";
    sql+=" and oper_table.visible = 1";
    sql+=" and expenses_table.exp_date = '"+DateInp.DateString()+" ' ";

    QR->SQL->Add(sql);
    try
    {
      QR->ExecQuery();
      if (!QR->FieldByName("SUM_OF_EXP")->IsNull) val26=QR->FieldByName("SUM_OF_EXP")->AsFloat;
    }
    catch (Exception &exc)
    {
      MessageDlg("Ошибка - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      return;
    }

// подписка

    sql="";
    val27=0.0;
    QR->Close();
    QR->SQL->Clear();
    sql="select ";
    sql+="sum(expenses_table.expense) sum_of_exp ";
    sql+="from expenses_table ";
    sql+="left outer join oper_table on (expenses_table.gsm_id = oper_table.id) ";
    sql+="where ";
    sql+=" oper_table.id in (93) ";
    sql+=" and oper_table.visible = 1";
    sql+=" and expenses_table.exp_date = '"+DateInp.DateString()+" ' ";

    QR->SQL->Add(sql);
    try
    {
      QR->ExecQuery();
      if (!QR->FieldByName("SUM_OF_EXP")->IsNull) val27=QR->FieldByName("SUM_OF_EXP")->AsFloat;
    }
    catch (Exception &exc)
    {
      MessageDlg("Ошибка - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      return;
    }

// лотерея

    sql="";
    val37=0.0;
    QR->Close();
    QR->SQL->Clear();
    sql="select ";
    sql+="sum(expenses_table.expense) sum_of_exp ";
    sql+="from expenses_table ";
    sql+="left outer join oper_table on (expenses_table.gsm_id = oper_table.id) ";
    sql+="where ";
    sql+=" oper_table.id in (99) ";
    sql+=" and oper_table.visible = 1";
    sql+=" and expenses_table.exp_date = '"+DateInp.DateString()+" ' ";

    QR->SQL->Add(sql);
    try
    {
      QR->ExecQuery();
      if (!QR->FieldByName("SUM_OF_EXP")->IsNull) val37=QR->FieldByName("SUM_OF_EXP")->AsFloat;
    }
    catch (Exception &exc)
    {
      MessageDlg("Ошибка - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      return;
    }


// выплата переводы

    sql="";
    val28=0.0;
    QR->Close();
    QR->SQL->Clear();
    sql="select ";
    sql+="sum(expenses_table.expense) sum_of_exp ";
    sql+="from expenses_table ";
    sql+="left outer join oper_table on (expenses_table.gsm_id = oper_table.id) ";
    sql+="where ";
    sql+=" oper_table.id = 96 ";
    sql+=" and oper_table.visible = 1";
    sql+=" and expenses_table.exp_date = '"+DateInp.DateString()+" ' ";

    QR->SQL->Add(sql);
    try
    {
      QR->ExecQuery();
      if (!QR->FieldByName("SUM_OF_EXP")->IsNull) val28=QR->FieldByName("SUM_OF_EXP")->AsFloat;
    }
    catch (Exception &exc)
    {
      MessageDlg("Ошибка - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      return;
    }

// выплата лотерея

    sql="";
    val40=0.0;
    QR->Close();
    QR->SQL->Clear();
    sql="select ";
    sql+="sum(expenses_table.expense) sum_of_exp ";
    sql+="from expenses_table ";
    sql+="left outer join oper_table on (expenses_table.gsm_id = oper_table.id) ";
    sql+="where ";
    sql+=" oper_table.id = 103 ";
    sql+=" and oper_table.visible = 1";
    sql+=" and expenses_table.exp_date = '"+DateInp.DateString()+" ' ";

    QR->SQL->Add(sql);
    try
    {
      QR->ExecQuery();
      if (!QR->FieldByName("SUM_OF_EXP")->IsNull) val40=QR->FieldByName("SUM_OF_EXP")->AsFloat;
    }
    catch (Exception &exc)
    {
      MessageDlg("Ошибка - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      return;
    }



// здесь нужна процедура определения остатков на конец дня и занесения их в БД

ostmedv=0.0;
ostpens=ost2+val2-val5-val18;
ostperev=ost5+val26+val25-val28-val29;
ostpogr=0.0;
ostredv=ost3+val3-val7-val19;
osttown=ost7+val1+val36-val17;
ostgood=ost8+val31-val33;
ostpodp=ost9+val27-val35;
ostloto=ost10+val37-val38-val40;



ostend=ostmedv+ostpens+ostredv+osttown+ostperev+ostgood+ostpodp+ostloto;

val21=ostpens;
val22=ostend;
val23=ostmedv+ostredv;
val24=osttown;
val30=ostperev;
val32=ostgood;
val34=ostpodp;
val39=ostloto;


// заносим остаток на конец дня И другие показатели в БД

// Почта Банк выплачено
    sql="";
    QR->Close();
    QR->SQL->Clear();
    sql="select ";
    sql+="expenses_table.id exp_id ";
    sql+="from expenses_table ";
    sql+="where ";
    sql+=" expenses_table.gsm_id = 85";
    sql+=" and expenses_table.exp_date = '"+DateInp.DateString()+" ' ";
    QR->SQL->Add(sql);
    try
    {
    QR->ExecQuery();
    if (QR->FieldByName("EXP_ID")->IsNull)
    {
    if (val28!=0.00)
    {
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
    { MessageDlg("Ошибка - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      Q->Transaction->Rollback();
      return;
    }
    if(Q->RecordCount==0)
    {
      MessageDlg("Ошибка получения значения ID таблицы EXPENSES_TABLE",mtError,TMsgDlgButtons() << mbOK,0);
      Q->Transaction->Rollback();
      return;
    }
    id=Q->FieldByName("ID")->AsInteger;

    Q->Close();
    Q->SQL->Clear();
    sql="insert into EXPENSES_TABLE(ID,EXP_DATE,SD_ID,DRIVER_ID,GSM_ID,KOL,EXPENSE,FLAG,EDITABLE,U_ID) values(";
    sql+=IntToStr(id)+",";
    sql+="'"+DateInp.DateString()+"',";
    sql+=IntToStr(0)+",";
    sql+=IntToStr(0)+",";
    sql+=IntToStr(85)+",";
    sql+=IntToStr(0)+",";
    sql+=FloatToStr(val28)+",0,0,";
    sql+=IntToStr(codchef)+")";
    Q->SQL->Add(sql);
    try
    {
      Q->ExecQuery();
    }
    catch (Exception &exc)
    {
      MessageDlg("Ошибка - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      Q->Transaction->Rollback();
      return;
    }
    Q->Transaction->Commit();
    }
    }else
    {
    Q->Close();
    Q->SQL->Clear();
    if (val28!=0.00)
    {
    sql="update EXPENSES_TABLE set";
    sql+=" EXPENSE="+FloatToStr(val28);
    sql+=" where ID="+IntToStr(QR->FieldByName("EXP_ID")->AsInteger);
    }else
    {
    sql="delete from EXPENSES_TABLE ";
    sql+=" where ID="+IntToStr(QR->FieldByName("EXP_ID")->AsInteger);
    }
    Q->SQL->Add(sql);
    Q->Transaction->StartTransaction();
    try
    {
      Q->ExecQuery();
    }
    catch (Exception &exc)
    {
      MessageDlg("Ошибка - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      Q->Transaction->Rollback();
      return;
    }
    Q->Transaction->Commit();
    }
    }
    catch (Exception &exc)
    {
      MessageDlg("Ошибка - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      return;
    }

// Система город подкрепления

    sql="";
    QR->Close();
    QR->SQL->Clear();
    sql="select ";
    sql+="expenses_table.id exp_id ";
    sql+="from expenses_table ";
    sql+="where ";
    sql+=" expenses_table.gsm_id = 58";
    sql+=" and expenses_table.exp_date = '"+DateInp.DateString()+" ' ";
    sql+=" and expenses_table.d = 0 ";
    QR->SQL->Add(sql);
    try
    {
    QR->ExecQuery();
    if (QR->FieldByName("EXP_ID")->IsNull)
    {
    if (val1!=0.00)
    {
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
    { MessageDlg("Ошибка - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      Q->Transaction->Rollback();
      return;
    }
    if(Q->RecordCount==0)
    {
      MessageDlg("Ошибка получения значения ID таблицы EXPENSES_TABLE",mtError,TMsgDlgButtons() << mbOK,0);
      Q->Transaction->Rollback();
      return;
    }
    id=Q->FieldByName("ID")->AsInteger;

    Q->Close();
    Q->SQL->Clear();
    sql="insert into EXPENSES_TABLE(ID,EXP_DATE,SD_ID,DRIVER_ID,GSM_ID,KOL,EXPENSE,FLAG,EDITABLE,U_ID) values(";
    sql+=IntToStr(id)+",";
    sql+="'"+DateInp.DateString()+"',";
    sql+=IntToStr(0)+",";
    sql+=IntToStr(0)+",";
    sql+=IntToStr(58)+",";
    sql+=IntToStr(0)+",";
    sql+=FloatToStr(val1)+",0,0,";
    sql+=IntToStr(codchef)+")";
    Q->SQL->Add(sql);
    try
    {
      Q->ExecQuery();
    }
    catch (Exception &exc)
    {
      MessageDlg("Ошибка - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      Q->Transaction->Rollback();
      return;
    }
    Q->Transaction->Commit();
    }
    }else
    {
    Q->Close();
    Q->SQL->Clear();
    if (val1!=0.00)
    {
    sql="update EXPENSES_TABLE set";
    sql+=" EXPENSE="+FloatToStr(val1);
    sql+=" where ID="+IntToStr(QR->FieldByName("EXP_ID")->AsInteger);
    }
    else
    {
    sql="delete from EXPENSES_TABLE ";
    sql+=" where ID="+IntToStr(QR->FieldByName("EXP_ID")->AsInteger);
    }
    Q->SQL->Add(sql);
    Q->Transaction->StartTransaction();
    try
    {
      Q->ExecQuery();
    }
    catch (Exception &exc)
    {
      MessageDlg("Ошибка - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      Q->Transaction->Rollback();
      return;
    }
    Q->Transaction->Commit();
    }
    }
    catch (Exception &exc)
    {
      MessageDlg("Ошибка - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      return;
    }

// обслуживание карт почта банка

    sql="";
    QR->Close();
    QR->SQL->Clear();
    sql="select ";
    sql+="expenses_table.id exp_id ";
    sql+="from expenses_table ";
    sql+="where ";
    sql+=" expenses_table.gsm_id = 83";
    sql+=" and expenses_table.exp_date = '"+DateInp.DateString()+" ' ";
    QR->SQL->Add(sql);
    try
    {
    QR->ExecQuery();
    if (QR->FieldByName("EXP_ID")->IsNull)
    {
    if (val26!=0.00)
    {
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
    { MessageDlg("Ошибка - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      Q->Transaction->Rollback();
      return;
    }
    if(Q->RecordCount==0)
    {
      MessageDlg("Ошибка получения значения ID таблицы EXPENSES_TABLE",mtError,TMsgDlgButtons() << mbOK,0);
      Q->Transaction->Rollback();
      return;
    }
    id=Q->FieldByName("ID")->AsInteger;

    Q->Close();
    Q->SQL->Clear();
    sql="insert into EXPENSES_TABLE(ID,EXP_DATE,SD_ID,DRIVER_ID,GSM_ID,KOL,EXPENSE,FLAG,EDITABLE,U_ID) values(";
    sql+=IntToStr(id)+",";
    sql+="'"+DateInp.DateString()+"',";
    sql+=IntToStr(0)+",";
    sql+=IntToStr(0)+",";
    sql+=IntToStr(83)+",";
    sql+=IntToStr(0)+",";
    sql+=FloatToStr(val26)+",0,0,";
    sql+=IntToStr(codchef)+")";
    Q->SQL->Add(sql);
    try
    {
      Q->ExecQuery();
    }
    catch (Exception &exc)
    {
      MessageDlg("Ошибка - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      Q->Transaction->Rollback();
      return;
    }
    Q->Transaction->Commit();
    }
    }else
    {
    Q->Close();
    Q->SQL->Clear();
    if (val26!=0.00)
    {
    sql="update EXPENSES_TABLE set";
    sql+=" EXPENSE="+FloatToStr(val26);
    sql+=" where ID="+IntToStr(QR->FieldByName("EXP_ID")->AsInteger);
    }else
    {
    sql="delete from EXPENSES_TABLE ";
    sql+=" where ID="+IntToStr(QR->FieldByName("EXP_ID")->AsInteger);
    }
    Q->SQL->Add(sql);
    Q->Transaction->StartTransaction();
    try
    {
      Q->ExecQuery();
    }
    catch (Exception &exc)
    {
      MessageDlg("Ошибка - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      Q->Transaction->Rollback();
      return;
    }
    Q->Transaction->Commit();
    }
    }
    catch (Exception &exc)
    {
      MessageDlg("Ошибка - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      return;
    }

// Подписка подкрепления

    sql="";
    QR->Close();
    QR->SQL->Clear();
    sql="select ";
    sql+="expenses_table.id exp_id ";
    sql+="from expenses_table ";
    sql+="where ";
    sql+=" expenses_table.gsm_id = 84";
    sql+=" and expenses_table.exp_date = '"+DateInp.DateString()+" ' ";
    QR->SQL->Add(sql);
    try
    {
    QR->ExecQuery();
    if (QR->FieldByName("EXP_ID")->IsNull)
    {
    if (val27!=0.00)
    {
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
    { MessageDlg("Ошибка - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      Q->Transaction->Rollback();
      return;
    }
    if(Q->RecordCount==0)
    {
      MessageDlg("Ошибка получения значения ID таблицы EXPENSES_TABLE",mtError,TMsgDlgButtons() << mbOK,0);
      Q->Transaction->Rollback();
      return;
    }
    id=Q->FieldByName("ID")->AsInteger;

    Q->Close();
    Q->SQL->Clear();
    sql="insert into EXPENSES_TABLE(ID,EXP_DATE,SD_ID,DRIVER_ID,GSM_ID,KOL,EXPENSE,FLAG,EDITABLE,U_ID) values(";
    sql+=IntToStr(id)+",";
    sql+="'"+DateInp.DateString()+"',";
    sql+=IntToStr(0)+",";
    sql+=IntToStr(0)+",";
    sql+=IntToStr(84)+",";
    sql+=IntToStr(0)+",";
    sql+=FloatToStr(val27)+",0,0,";
    sql+=IntToStr(codchef)+")";
    Q->SQL->Add(sql);
    try
    {
      Q->ExecQuery();
    }
    catch (Exception &exc)
    {
      MessageDlg("Ошибка - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      Q->Transaction->Rollback();
      return;
    }
    Q->Transaction->Commit();
    }
    }else
    { // редактируем старый остаток
    Q->Close();
    Q->SQL->Clear();
    if (val27!=0.00)
    {
    sql="update EXPENSES_TABLE set";
    sql+=" EXPENSE="+FloatToStr(val27);
    sql+=" where ID="+IntToStr(QR->FieldByName("EXP_ID")->AsInteger);
    }else
    {
    sql="delete from EXPENSES_TABLE ";
    sql+=" where ID="+IntToStr(QR->FieldByName("EXP_ID")->AsInteger);
    }
    Q->SQL->Add(sql);
    Q->Transaction->StartTransaction();
    try
    {
      Q->ExecQuery();
    }
    catch (Exception &exc)
    {
      MessageDlg("Ошибка - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      Q->Transaction->Rollback();
      return;
    }
    Q->Transaction->Commit();
    }
    }
    catch (Exception &exc)
    {
      MessageDlg("Ошибка - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      return;
    }

// Продажа товаров подкрепление

    sql="";
    QR->Close();
    QR->SQL->Clear();
    sql="select ";
    sql+="expenses_table.id exp_id ";
    sql+="from expenses_table ";
    sql+="where ";
    sql+=" expenses_table.gsm_id = 89";
    sql+=" and expenses_table.exp_date = '"+DateInp.DateString()+" ' ";
    QR->SQL->Add(sql);
    try
    {
    QR->ExecQuery();
    if (QR->FieldByName("EXP_ID")->IsNull)
    {
    if (val31!=0.00)
    {
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
    { MessageDlg("Ошибка - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      Q->Transaction->Rollback();
      return;
    }
    if(Q->RecordCount==0)
    {
      MessageDlg("Ошибка получения значения ID таблицы EXPENSES_TABLE",mtError,TMsgDlgButtons() << mbOK,0);
      Q->Transaction->Rollback();
      return;
    }
    id=Q->FieldByName("ID")->AsInteger;

    Q->Close();
    Q->SQL->Clear();
    sql="insert into EXPENSES_TABLE(ID,EXP_DATE,SD_ID,DRIVER_ID,GSM_ID,KOL,EXPENSE,FLAG,EDITABLE,U_ID) values(";
    sql+=IntToStr(id)+",";
    sql+="'"+DateInp.DateString()+"',";
    sql+=IntToStr(0)+",";
    sql+=IntToStr(0)+",";
    sql+=IntToStr(89)+",";
    sql+=IntToStr(0)+",";
    sql+=FloatToStr(val31)+",0,0,";
    sql+=IntToStr(codchef)+")";
    Q->SQL->Add(sql);
    try
    {
      Q->ExecQuery();
    }
    catch (Exception &exc)
    {
      MessageDlg("Ошибка - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      Q->Transaction->Rollback();
      return;
    }
    Q->Transaction->Commit();
    }
    }else
    {
    Q->Close();
    Q->SQL->Clear();
    if (val31!=0.00)
    {
    sql="update EXPENSES_TABLE set";
    sql+=" EXPENSE="+FloatToStr(val31);
    sql+=" where ID="+IntToStr(QR->FieldByName("EXP_ID")->AsInteger);
    }
    else
    {
    sql="delete from EXPENSES_TABLE ";
    sql+=" where ID="+IntToStr(QR->FieldByName("EXP_ID")->AsInteger);
    }
    Q->SQL->Add(sql);
    Q->Transaction->StartTransaction();
    try
    {
      Q->ExecQuery();
    }
    catch (Exception &exc)
    {
      MessageDlg("Ошибка - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      Q->Transaction->Rollback();
      return;
    }
    Q->Transaction->Commit();
    }
    }
    catch (Exception &exc)
    {
      MessageDlg("Ошибка - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      return;
    }

// Лотерея подкрепления

    sql="";
    QR->Close();
    QR->SQL->Clear();
    sql="select ";
    sql+="expenses_table.id exp_id ";
    sql+="from expenses_table ";
    sql+="where ";
    sql+=" expenses_table.gsm_id = 101";
    sql+=" and expenses_table.exp_date = '"+DateInp.DateString()+" ' ";
    QR->SQL->Add(sql);
    try
    {
    QR->ExecQuery();
    if (QR->FieldByName("EXP_ID")->IsNull)
    {
    if (val37!=0.00)
    {
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
    { MessageDlg("Ошибка - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      Q->Transaction->Rollback();
      return;
    }
    if(Q->RecordCount==0)
    {
      MessageDlg("Ошибка получения значения ID таблицы EXPENSES_TABLE",mtError,TMsgDlgButtons() << mbOK,0);
      Q->Transaction->Rollback();
      return;
    }
    id=Q->FieldByName("ID")->AsInteger;

    Q->Close();
    Q->SQL->Clear();
    sql="insert into EXPENSES_TABLE(ID,EXP_DATE,SD_ID,DRIVER_ID,GSM_ID,KOL,EXPENSE,FLAG,EDITABLE,U_ID) values(";
    sql+=IntToStr(id)+",";
    sql+="'"+DateInp.DateString()+"',";
    sql+=IntToStr(0)+",";
    sql+=IntToStr(0)+",";
    sql+=IntToStr(101)+",";
    sql+=IntToStr(0)+",";
    sql+=FloatToStr(val37)+",0,0,";
    sql+=IntToStr(codchef)+")";
    Q->SQL->Add(sql);
    try
    {
      Q->ExecQuery();
    }
    catch (Exception &exc)
    {
      MessageDlg("Ошибка - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      Q->Transaction->Rollback();
      return;
    }
    Q->Transaction->Commit();
    }
    }else
    { // редактируем старый остаток
    Q->Close();
    Q->SQL->Clear();
    if (val37!=0.00)
    {
    sql="update EXPENSES_TABLE set";
    sql+=" EXPENSE="+FloatToStr(val37);
    sql+=" where ID="+IntToStr(QR->FieldByName("EXP_ID")->AsInteger);
    }else
    {
    sql="delete from EXPENSES_TABLE ";
    sql+=" where ID="+IntToStr(QR->FieldByName("EXP_ID")->AsInteger);
    }
    Q->SQL->Add(sql);
    Q->Transaction->StartTransaction();
    try
    {
      Q->ExecQuery();
    }
    catch (Exception &exc)
    {
      MessageDlg("Ошибка - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      Q->Transaction->Rollback();
      return;
    }
    Q->Transaction->Commit();
    }
    }
    catch (Exception &exc)
    {
      MessageDlg("Ошибка - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      return;
    }

// Лотерея выплачено

    sql="";
    QR->Close();
    QR->SQL->Clear();
    sql="select ";
    sql+="expenses_table.id exp_id ";
    sql+="from expenses_table ";
    sql+="where ";
    sql+=" expenses_table.gsm_id = 104";
    sql+=" and expenses_table.exp_date = '"+DateInp.DateString()+" ' ";
    QR->SQL->Add(sql);
    try
    {
    QR->ExecQuery();
    if (QR->FieldByName("EXP_ID")->IsNull)
    {
    if (val40!=0.00)
    {
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
    { MessageDlg("Ошибка - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      Q->Transaction->Rollback();
      return;
    }
    if(Q->RecordCount==0)
    {
      MessageDlg("Ошибка получения значения ID таблицы EXPENSES_TABLE",mtError,TMsgDlgButtons() << mbOK,0);
      Q->Transaction->Rollback();
      return;
    }
    id=Q->FieldByName("ID")->AsInteger;

    Q->Close();
    Q->SQL->Clear();
    sql="insert into EXPENSES_TABLE(ID,EXP_DATE,SD_ID,DRIVER_ID,GSM_ID,KOL,EXPENSE,FLAG,EDITABLE,U_ID) values(";
    sql+=IntToStr(id)+",";
    sql+="'"+DateInp.DateString()+"',";
    sql+=IntToStr(0)+",";
    sql+=IntToStr(0)+",";
    sql+=IntToStr(104)+",";
    sql+=IntToStr(0)+",";
    sql+=FloatToStr(val40)+",0,0,";
    sql+=IntToStr(codchef)+")";
    Q->SQL->Add(sql);
    try
    {
      Q->ExecQuery();
    }
    catch (Exception &exc)
    {
      MessageDlg("Ошибка - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      Q->Transaction->Rollback();
      return;
    }
    Q->Transaction->Commit();
    }
    }else
    { // редактируем старый остаток
    Q->Close();
    Q->SQL->Clear();
    if (val40!=0.00)
    {
    sql="update EXPENSES_TABLE set";
    sql+=" EXPENSE="+FloatToStr(val40);
    sql+=" where ID="+IntToStr(QR->FieldByName("EXP_ID")->AsInteger);
    }else
    {
    sql="delete from EXPENSES_TABLE ";
    sql+=" where ID="+IntToStr(QR->FieldByName("EXP_ID")->AsInteger);
    }
    Q->SQL->Add(sql);
    Q->Transaction->StartTransaction();
    try
    {
      Q->ExecQuery();
    }
    catch (Exception &exc)
    {
      MessageDlg("Ошибка - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      Q->Transaction->Rollback();
      return;
    }
    Q->Transaction->Commit();
    }
    }
    catch (Exception &exc)
    {
      MessageDlg("Ошибка - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      return;
    }


// ост переводы
    sql="";
    QR->Close();
    QR->SQL->Clear();
    sql="select ";
    sql+="expenses_table.id exp_id ";
    sql+="from expenses_table ";
    sql+="where ";
    sql+=" expenses_table.gsm_id = 81";
    sql+=" and expenses_table.exp_date = '"+DateInp.DateString()+" ' ";
    QR->SQL->Add(sql);
    try
    {
    QR->ExecQuery();
    if (QR->FieldByName("EXP_ID")->IsNull)
    {
      // добавляем новый остаток
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
    { MessageDlg("Ошибка - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      Q->Transaction->Rollback();
      return;
    }
    if(Q->RecordCount==0)
    {
      MessageDlg("Ошибка получения значения ID таблицы EXPENSES_TABLE",mtError,TMsgDlgButtons() << mbOK,0);
      Q->Transaction->Rollback();
      return;
    }
    id=Q->FieldByName("ID")->AsInteger;

    Q->Close();
    Q->SQL->Clear();
    sql="insert into EXPENSES_TABLE(ID,EXP_DATE,SD_ID,DRIVER_ID,GSM_ID,KOL,EXPENSE,FLAG,EDITABLE,U_ID) values(";
    sql+=IntToStr(id)+",";
    sql+="'"+DateInp.DateString()+"',";
    sql+=IntToStr(0)+",";
    sql+=IntToStr(0)+",";
    sql+=IntToStr(81)+",";
    sql+=IntToStr(0)+",";
    sql+=FloatToStr(ostperev)+",0,0,";
    sql+=IntToStr(codchef)+")";
    Q->SQL->Add(sql);
    try
    {
      Q->ExecQuery();
    }
    catch (Exception &exc)
    {
      MessageDlg("Ошибка - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      Q->Transaction->Rollback();
      return;
    }
    Q->Transaction->Commit();
    }else
    { // редактируем старый остаток
    Q->Close();
    Q->SQL->Clear();
    sql="update EXPENSES_TABLE set";
    sql+=" EXPENSE="+FloatToStr(ostperev);
    sql+=" where ID="+IntToStr(QR->FieldByName("EXP_ID")->AsInteger);
    Q->SQL->Add(sql);
    Q->Transaction->StartTransaction();
    try
    {
      Q->ExecQuery();
    }
    catch (Exception &exc)
    {
      MessageDlg("Ошибка - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      Q->Transaction->Rollback();
      return;
    }
    Q->Transaction->Commit();
    }
    }
    catch (Exception &exc)
    {
      MessageDlg("Ошибка - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      return;
    }

// ост пенсия

    sql="";
    QR->Close();
    QR->SQL->Clear();
    sql="select ";
    sql+="expenses_table.id exp_id ";
    sql+="from expenses_table ";
    sql+="where ";
    sql+=" expenses_table.gsm_id = 60";
    sql+=" and expenses_table.exp_date = '"+DateInp.DateString()+" ' ";
    QR->SQL->Add(sql);
    try
    {
    QR->ExecQuery();
    if (QR->FieldByName("EXP_ID")->IsNull)
    {
      // добавляем новый остаток
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
    { MessageDlg("Ошибка - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      Q->Transaction->Rollback();
      return;
    }
    if(Q->RecordCount==0)
    {
      MessageDlg("Ошибка получения значения ID таблицы EXPENSES_TABLE",mtError,TMsgDlgButtons() << mbOK,0);
      Q->Transaction->Rollback();
      return;
    }
    id=Q->FieldByName("ID")->AsInteger;

    Q->Close();
    Q->SQL->Clear();
    sql="insert into EXPENSES_TABLE(ID,EXP_DATE,SD_ID,DRIVER_ID,GSM_ID,KOL,EXPENSE,FLAG,EDITABLE,U_ID) values(";
    sql+=IntToStr(id)+",";
    sql+="'"+DateInp.DateString()+"',";
    sql+=IntToStr(0)+",";
    sql+=IntToStr(0)+",";
    sql+=IntToStr(60)+",";
    sql+=IntToStr(0)+",";
    sql+=FloatToStr(ostpens)+",0,0,";
    sql+=IntToStr(codchef)+")";
    Q->SQL->Add(sql);
    try
    {
      Q->ExecQuery();
    }
    catch (Exception &exc)
    {
      MessageDlg("Ошибка - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      Q->Transaction->Rollback();
      return;
    }
    Q->Transaction->Commit();
    }else
    { // редактируем старый остаток
    Q->Close();
    Q->SQL->Clear();
    sql="update EXPENSES_TABLE set";
    sql+=" EXPENSE="+FloatToStr(ostpens);
    sql+=" where ID="+IntToStr(QR->FieldByName("EXP_ID")->AsInteger);
    Q->SQL->Add(sql);
    Q->Transaction->StartTransaction();
    try
    {
      Q->ExecQuery();
    }
    catch (Exception &exc)
    {
      MessageDlg("Ошибка - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      Q->Transaction->Rollback();
      return;
    }
    Q->Transaction->Commit();
    }
    }
    catch (Exception &exc)
    {
      MessageDlg("Ошибка - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      return;
    }

// регион ЕДВ

    sql="";
    QR->Close();
    QR->SQL->Clear();
    sql="select ";
    sql+="expenses_table.id exp_id ";
    sql+="from expenses_table ";
    sql+="where ";
    sql+=" expenses_table.gsm_id = 63";
    sql+=" and expenses_table.exp_date = '"+DateInp.DateString()+" ' ";
    QR->SQL->Add(sql);
    try
    {
    QR->ExecQuery();
    if (QR->FieldByName("EXP_ID")->IsNull)
    {
      // добавляем новый остаток
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
    { MessageDlg("Ошибка - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      Q->Transaction->Rollback();
      return;
    }
    if(Q->RecordCount==0)
    {
      MessageDlg("Ошибка получения значения ID таблицы EXPENSES_TABLE",mtError,TMsgDlgButtons() << mbOK,0);
      Q->Transaction->Rollback();
      return;
    }
    id=Q->FieldByName("ID")->AsInteger;

    Q->Close();
    Q->SQL->Clear();
    sql="insert into EXPENSES_TABLE(ID,EXP_DATE,SD_ID,DRIVER_ID,GSM_ID,KOL,EXPENSE,FLAG,EDITABLE,U_ID) values(";
    sql+=IntToStr(id)+",";
    sql+="'"+DateInp.DateString()+"',";
    sql+=IntToStr(0)+",";
    sql+=IntToStr(0)+",";
    sql+=IntToStr(63)+",";
    sql+=IntToStr(0)+",";
    sql+=FloatToStr(ostredv)+",0,0,";
    sql+=IntToStr(codchef)+")";
    Q->SQL->Add(sql);
    try
    {
      Q->ExecQuery();
    }
    catch (Exception &exc)
    {
      MessageDlg("Ошибка - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      Q->Transaction->Rollback();
      return;
    }
    Q->Transaction->Commit();
    }else
    { // редактируем старый остаток
    Q->Close();
    Q->SQL->Clear();
    sql="update EXPENSES_TABLE set";
    sql+=" EXPENSE="+FloatToStr(ostredv);
    sql+=" where ID="+IntToStr(QR->FieldByName("EXP_ID")->AsInteger);
    Q->SQL->Add(sql);
    Q->Transaction->StartTransaction();
    try
    {
      Q->ExecQuery();
    }
    catch (Exception &exc)
    {
      MessageDlg("Ошибка - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      Q->Transaction->Rollback();
      return;
    }
    Q->Transaction->Commit();
    }
    }
    catch (Exception &exc)
    {
      MessageDlg("Ошибка - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      return;
    }

// остаток город

    sql="";
    QR->Close();
    QR->SQL->Clear();
    sql="select ";
    sql+="expenses_table.id exp_id ";
    sql+="from expenses_table ";
    sql+="where ";
    sql+=" expenses_table.gsm_id = 64";
    sql+=" and expenses_table.exp_date = '"+DateInp.DateString()+" ' ";
    QR->SQL->Add(sql);
    try
    {
    QR->ExecQuery();
    if (QR->FieldByName("EXP_ID")->IsNull)
    {
      // добавляем новый остаток
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
    { MessageDlg("Ошибка - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      Q->Transaction->Rollback();
      return;
    }
    if(Q->RecordCount==0)
    {
      MessageDlg("Ошибка получения значения ID таблицы EXPENSES_TABLE",mtError,TMsgDlgButtons() << mbOK,0);
      Q->Transaction->Rollback();
      return;
    }
    id=Q->FieldByName("ID")->AsInteger;

    Q->Close();
    Q->SQL->Clear();
    sql="insert into EXPENSES_TABLE(ID,EXP_DATE,SD_ID,DRIVER_ID,GSM_ID,KOL,EXPENSE,FLAG,EDITABLE,U_ID) values(";
    sql+=IntToStr(id)+",";
    sql+="'"+DateInp.DateString()+"',";
    sql+=IntToStr(0)+",";
    sql+=IntToStr(0)+",";
    sql+=IntToStr(64)+",";
    sql+=IntToStr(0)+",";
    sql+=FloatToStr(osttown)+",0,0,";
    sql+=IntToStr(codchef)+")";
    Q->SQL->Add(sql);
    try
    {
      Q->ExecQuery();
    }
    catch (Exception &exc)
    {
      MessageDlg("Ошибка - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      Q->Transaction->Rollback();
      return;
    }
    Q->Transaction->Commit();
    }else
    { // редактируем старый остаток
    Q->Close();
    Q->SQL->Clear();
    sql="update EXPENSES_TABLE set";
    sql+=" EXPENSE="+FloatToStr(osttown);
    sql+=" where ID="+IntToStr(QR->FieldByName("EXP_ID")->AsInteger);
    Q->SQL->Add(sql);
    Q->Transaction->StartTransaction();
    try
    {
      Q->ExecQuery();
    }
    catch (Exception &exc)
    {
      MessageDlg("Ошибка - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      Q->Transaction->Rollback();
      return;
    }
    Q->Transaction->Commit();
    }
    }
    catch (Exception &exc)
    {
      MessageDlg("Ошибка - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      return;
    }


// остаток продажа товаров

    sql="";
    QR->Close();
    QR->SQL->Clear();
    sql="select ";
    sql+="expenses_table.id exp_id ";
    sql+="from expenses_table ";
    sql+="where ";
    sql+=" expenses_table.gsm_id = 90";
    sql+=" and expenses_table.exp_date = '"+DateInp.DateString()+" ' ";
    QR->SQL->Add(sql);
    try
    {
    QR->ExecQuery();
    if (QR->FieldByName("EXP_ID")->IsNull)
    {
      // добавляем новый остаток
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
    { MessageDlg("Ошибка - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      Q->Transaction->Rollback();
      return;
    }
    if(Q->RecordCount==0)
    {
      MessageDlg("Ошибка получения значения ID таблицы EXPENSES_TABLE",mtError,TMsgDlgButtons() << mbOK,0);
      Q->Transaction->Rollback();
      return;
    }
    id=Q->FieldByName("ID")->AsInteger;

    Q->Close();
    Q->SQL->Clear();
    sql="insert into EXPENSES_TABLE(ID,EXP_DATE,SD_ID,DRIVER_ID,GSM_ID,KOL,EXPENSE,FLAG,EDITABLE,U_ID) values(";
    sql+=IntToStr(id)+",";
    sql+="'"+DateInp.DateString()+"',";
    sql+=IntToStr(0)+",";
    sql+=IntToStr(0)+",";
    sql+=IntToStr(90)+",";
    sql+=IntToStr(0)+",";
    sql+=FloatToStr(ostgood)+",0,0,";
    sql+=IntToStr(codchef)+")";
    Q->SQL->Add(sql);
    try
    {
      Q->ExecQuery();
    }
    catch (Exception &exc)
    {
      MessageDlg("Ошибка - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      Q->Transaction->Rollback();
      return;
    }
    Q->Transaction->Commit();
    }else
    { // редактируем старый остаток
    Q->Close();
    Q->SQL->Clear();
    sql="update EXPENSES_TABLE set";
    sql+=" EXPENSE="+FloatToStr(ostgood);
    sql+=" where ID="+IntToStr(QR->FieldByName("EXP_ID")->AsInteger);
    Q->SQL->Add(sql);
    Q->Transaction->StartTransaction();
    try
    {
      Q->ExecQuery();
    }
    catch (Exception &exc)
    {
      MessageDlg("Ошибка - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      Q->Transaction->Rollback();
      return;
    }
    Q->Transaction->Commit();
    }
    }
    catch (Exception &exc)
    {
      MessageDlg("Ошибка - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      return;
    }

// остаток подписка

    sql="";
    QR->Close();
    QR->SQL->Clear();
    sql="select ";
    sql+="expenses_table.id exp_id ";
    sql+="from expenses_table ";
    sql+="where ";
    sql+=" expenses_table.gsm_id = 95";
    sql+=" and expenses_table.exp_date = '"+DateInp.DateString()+" ' ";
    QR->SQL->Add(sql);
    try
    {
    QR->ExecQuery();
    if (QR->FieldByName("EXP_ID")->IsNull)
    {
      // добавляем новый остаток
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
    { MessageDlg("Ошибка - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      Q->Transaction->Rollback();
      return;
    }
    if(Q->RecordCount==0)
    {
      MessageDlg("Ошибка получения значения ID таблицы EXPENSES_TABLE",mtError,TMsgDlgButtons() << mbOK,0);
      Q->Transaction->Rollback();
      return;
    }
    id=Q->FieldByName("ID")->AsInteger;

    Q->Close();
    Q->SQL->Clear();
    sql="insert into EXPENSES_TABLE(ID,EXP_DATE,SD_ID,DRIVER_ID,GSM_ID,KOL,EXPENSE,FLAG,EDITABLE,U_ID) values(";
    sql+=IntToStr(id)+",";
    sql+="'"+DateInp.DateString()+"',";
    sql+=IntToStr(0)+",";
    sql+=IntToStr(0)+",";
    sql+=IntToStr(95)+",";
    sql+=IntToStr(0)+",";
    sql+=FloatToStr(ostpodp)+",0,0,";
    sql+=IntToStr(codchef)+")";
    Q->SQL->Add(sql);
    try
    {
      Q->ExecQuery();
    }
    catch (Exception &exc)
    {
      MessageDlg("Ошибка - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      Q->Transaction->Rollback();
      return;
    }
    Q->Transaction->Commit();
    }else
    { // редактируем старый остаток
    Q->Close();
    Q->SQL->Clear();
    sql="update EXPENSES_TABLE set";
    sql+=" EXPENSE="+FloatToStr(ostpodp);
    sql+=" where ID="+IntToStr(QR->FieldByName("EXP_ID")->AsInteger);
    Q->SQL->Add(sql);
    Q->Transaction->StartTransaction();
    try
    {
      Q->ExecQuery();
    }
    catch (Exception &exc)
    {
      MessageDlg("Ошибка - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      Q->Transaction->Rollback();
      return;
    }
    Q->Transaction->Commit();
    }
    }
    catch (Exception &exc)
    {
      MessageDlg("Ошибка - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      return;
    }


// остаток лотерея

    sql="";
    QR->Close();
    QR->SQL->Clear();
    sql="select ";
    sql+="expenses_table.id exp_id ";
    sql+="from expenses_table ";
    sql+="where ";
    sql+=" expenses_table.gsm_id = 102";
    sql+=" and expenses_table.exp_date = '"+DateInp.DateString()+" ' ";
    QR->SQL->Add(sql);
    try
    {
    QR->ExecQuery();
    if (QR->FieldByName("EXP_ID")->IsNull)
    {
      // добавляем новый остаток
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
    { MessageDlg("Ошибка - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      Q->Transaction->Rollback();
      return;
    }
    if(Q->RecordCount==0)
    {
      MessageDlg("Ошибка получения значения ID таблицы EXPENSES_TABLE",mtError,TMsgDlgButtons() << mbOK,0);
      Q->Transaction->Rollback();
      return;
    }
    id=Q->FieldByName("ID")->AsInteger;

    Q->Close();
    Q->SQL->Clear();
    sql="insert into EXPENSES_TABLE(ID,EXP_DATE,SD_ID,DRIVER_ID,GSM_ID,KOL,EXPENSE,FLAG,EDITABLE,U_ID) values(";
    sql+=IntToStr(id)+",";
    sql+="'"+DateInp.DateString()+"',";
    sql+=IntToStr(0)+",";
    sql+=IntToStr(0)+",";
    sql+=IntToStr(102)+",";
    sql+=IntToStr(0)+",";
    sql+=FloatToStr(ostloto)+",0,0,";
    sql+=IntToStr(codchef)+")";
    Q->SQL->Add(sql);
    try
    {
      Q->ExecQuery();
    }
    catch (Exception &exc)
    {
      MessageDlg("Ошибка - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      Q->Transaction->Rollback();
      return;
    }
    Q->Transaction->Commit();
    }else
    { // редактируем старый остаток
    Q->Close();
    Q->SQL->Clear();
    sql="update EXPENSES_TABLE set";
    sql+=" EXPENSE="+FloatToStr(ostloto);
    sql+=" where ID="+IntToStr(QR->FieldByName("EXP_ID")->AsInteger);
    Q->SQL->Add(sql);
    Q->Transaction->StartTransaction();
    try
    {
      Q->ExecQuery();
    }
    catch (Exception &exc)
    {
      MessageDlg("Ошибка - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      Q->Transaction->Rollback();
      return;
    }
    Q->Transaction->Commit();
    }
    }
    catch (Exception &exc)
    {
      MessageDlg("Ошибка - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      return;
    }


    Q->Close();
    Q->SQL->Clear();
    sql="update EXPENSES_TABLE set";
    sql+=" EDITABLE = 0";
    sql+=" where expenses_table.exp_date = '"+DateInp.DateString()+" ' ";
    sql+=" and expenses_table.gsm_id in (85,83,84,89,60,63,64,81,90,95,73,74,75,101,102,104)";
    Q->SQL->Add(sql);
    Q->Transaction->StartTransaction();
    try
    {
      Q->ExecQuery();
    }
    catch (Exception &exc)
    {
      MessageDlg("Ошибка - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      Q->Transaction->Rollback();
      return;
    }
    Q->Transaction->Commit();
    Q->Close();

    Q->Close();
    Q->SQL->Clear();
    sql="update EXPENSES_TABLE set";
    sql+=" EDITABLE = 0";
    sql+=" where expenses_table.exp_date = '"+DateInp.DateString()+" ' ";
    sql+=" and expenses_table.gsm_id in (58)";
    sql+=" and expenses_table.d=0";

    Q->SQL->Add(sql);
    Q->Transaction->StartTransaction();
    try
    {
      Q->ExecQuery();
    }
    catch (Exception &exc)
    {
      MessageDlg("Ошибка - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      Q->Transaction->Rollback();
      return;
    }
    Q->Transaction->Commit();


    Q->Close();
    Q->SQL->Clear();
    sql="delete from EXPENSES_TABLE ";
    sql+=" where GSM_ID= 0";
    Q->SQL->Add(sql);
    Q->Transaction->StartTransaction();
    try
    {
      Q->ExecQuery();
    }
    catch (Exception &exc)
    {
      MessageDlg("Ошибка - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      Q->Transaction->Rollback();
      return;
    }
    Q->Transaction->Commit();

QR->Close();
}
