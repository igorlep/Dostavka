//Набор специальных фукций для работы с программой "Розница ГЖП!
//---------------------------------------------------------------------------
#ifndef SomeFunctionsH
#define SomeFunctionsH
//---------------------------------------------------------------------------
#include <ComCtrls.hpp>
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>

//#include <Controls.hpp>
#include "ZipBuilder.h"
#include "DataModule.h"

//---------------------------------------------------------------------------

AnsiString __fastcall getWorkDir(void);
AnsiString __fastcall createF55File(TDataSet *DS,TDataSet *DS1,AnsiString FIO,TDate date);
int __fastcall createF55vedFile(TDataSet *DS,TDate date,AnsiString namefile,AnsiString fio,int nr);
AnsiString __fastcall createVedVyplFile(TDate date1,TDate date2);
AnsiString __fastcall createF42File(TDataSet *DS,TDataSet *DS1,TDataSet *DS2,AnsiString FIO,AnsiString OS,TDate date);
AnsiString __fastcall createF42dFile(TDataSet *DS,AnsiString FIO,AnsiString OS,TDate date);
AnsiString __fastcall createF42KFile(TDataSet *DS,TDataSet *DS1,AnsiString OS,TDate date);
AnsiString __fastcall createF42KdFile(TDataSet *DS1,AnsiString OS,TDate date);
AnsiString __fastcall createraspisFile(TDataSet *DS,TDataSet *DS1,AnsiString FIO,TDate date);
AnsiString __fastcall createstatFile(AnsiString OS,TDate date,TDate date1);
AnsiString __fastcall createreestrFile(AnsiString OS,TDate date);
AnsiString __fastcall createvedofkolFile(TDate date,TDate date1);
AnsiString __fastcall createkassaglFile(TDate date,TDate date1,TDataSet *DS1,TDataSet *DS2,TDataSet *DS3,TDataSet *DS4,TDataSet *DS5,TDataSet *DS6,TDataSet *DS7,TDataSet *DS8);
AnsiString __fastcall createF130File(TDate date,double ost1,double ost2,double ost3,double ost7,double ost5,double ost8,double ost9,double ost10,double ost11);
void __fastcall editstatFile(TDataSet *DS2,TDataSet *DS3,TDataSet *DS4,TDataSet *DS5,TDataSet *DS6,TDataSet *DS7,AnsiString namefile,int ns);
void __fastcall editF130File(double val1,double val2,double val3,double val4,double val5,double val6,double val7,double val8,double val9,double val10,double val11,double val12,double val13,double val14,double val15,double val16,double val17,double val18,double val19,double val20,double val21,double val22,double val23,double val24,double val25,double val26,double val27,double val28,double val29,double val30,double val31,double val32,double val33,double val34,double val35,double val37,double val38,double val39,double val40,double val41,double val42,double val43,AnsiString namefile);
void __fastcall editreestrFile(TDataSet *DS1,TDataSet *DS2,TDataSet *DS3,TDataSet *DS5,TDataSet *DS6,AnsiString namefile,int ns);
void __fastcall editvedofkolFile(TDataSet *DS1,TDataSet *DS2,TDataSet *DS3,TDataSet *DS4,TDataSet *DS5,TDataSet *DS6,TDataSet *DS7,TDataSet *DS8,AnsiString namefile,AnsiString fio,int ns);
void __fastcall editkassaglFile(TDataSet *DS1,TDataSet *DS2,TDataSet *DS3,TDataSet *DS4,TDataSet *DS5,TDataSet *DS6,TDataSet *DS7,TDataSet *DS8,TDataSet *DS9,TDataSet *DS10,TDataSet *DS11,TDataSet *DS12,TDataSet *DS13,TDataSet *DS14,TDataSet *DS15,TDataSet *DS16,TDataSet *DS17,TDataSet *DS18,TDataSet *DS19,TDataSet *DS20,TDataSet *DS21,TDataSet *DS22,AnsiString namefile,int ns);
int __fastcall editvedvyplFile(TDataSet *DS,TDataSet *DS1,TDataSet *DS2,TDataSet *DS3,AnsiString ops,AnsiString namefile,int ns,int nl);
void __fastcall deletestatFile(AnsiString namefile,int ns1,int ns2);
void __fastcall deletereestrFile(AnsiString namefile,int ns1,double ns2,double ns3);
void __fastcall deletevedofkolFile(AnsiString namefile,int ns1);
//Функция копирования шаблона
bool __fastcall templateCopy(AnsiString fin, AnsiString fout);
void __fastcall rashet(ExpensesData *ed);
void __fastcall fr(int idrec, AnsiString toper,TDateTime Dater,int sd_id,int id_ops);
void __fastcall newost(TDateTime DateInp);
#endif

