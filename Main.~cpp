//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "DataModule.h"
#include "SelectPeriod.h"
#include "UniversalReferenceBook.h"
#include "RBConfiguration.h"
#include "AddEditExpense.h"
#include "Users.h"
#include "BackUpBase.h"
#include "RestoreBase.h"
#include "ExpensesListOnDate.h"
#include "ExpensesListOnAuto.h"
#include "ConditionsChoice.h"
#include "Main.h"
#include "DifferentFunctions.h"
#include "StatForm.h"
#include "ReestrForm.h"
#include "FormNastrProg.h"
#include "Vedofvyp.h"
#include "Vedofkol.h"
#include "SomeFunctions.h"
#include "ReestrSum.h"
#include "UnitF55.h"
#include "BlockForm.h"
#include "FormScan.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "JvComponent"
#pragma link "JvExControls"
#pragma link "JvNavigationPane"
#pragma link "Placemnt"
#pragma link "DBGridEh"
#pragma link "FIBDataSet"
#pragma link "pFIBDataSet"
#pragma link "FIBDatabase"
#pragma link "pFIBDatabase"
#pragma link "frxClass"
#pragma link "frxDBSet"
#pragma link "frxExportXLS"
#pragma link "JvXPBar"
#pragma link "JvXPCore"
#pragma link "RzTabs"
#pragma link "FIBQuery"
#pragma link "pFIBQuery"
#pragma link "pFIBStoredProc"
#pragma link "JvImageList"
#pragma resource "*.dfm"
TMainForm *MainForm;
//---------------------------------------------------------------------------
__fastcall TMainForm::TMainForm(TComponent* Owner)
        : TForm(Owner)
{
TIniFile* ini;
int GridFontSize,GridFontSize1,GridFontSize4,GridFontSize5,GridFontSize2,GridFontSize3,GridFontSize6;
TRegistry *Reg;

  try
  {
    Reg=new TRegistry(KEY_WRITE);
  }
  catch (Exception &exc)
  { MessageDlg("Ошибка создания объекта TRegistry\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
    return;
  }
  try
  { Reg->RootKey = HKEY_CURRENT_USER;
    if (Reg->OpenKey("\\Control Panel\\International\\",true))
    { Reg->WriteString("sDecimal",".");
      Reg->CloseKey();
    }
  }
  __finally
  {
    delete Reg;
  }

  sortString=" order by e.EXP_DATE, e.GSM_ID , e.SD_ID , e.ID";
  sortString1=" order by e.EXP_DATE, e.GSM_ID , e.SD_ID , e.ID";
  sortString2=" order by e.EXP_DATE, e.GSM_ID , e.SD_ID , e.ID";
//  sortString1=" order by e.EXP_DATE, e.ID";
//  sortString2=" order by e.EXP_DATE, e.ID";
  selectString="";
  selectString1="";
  OD_ID=0; WR_ID=0;
  ActivTable=0;

  workDir=ExtractFilePath(Application->ExeName);
  iniFileName=workDir+"AccountGSM.ini";
  FormStorage->IniFileName=iniFileName;
  FormStorage->IniSection="MainForm";
  ini=new TIniFile(iniFileName);
//  Date1=ini->ReadDate("MainForm","Date1",Date());
//  Date2=ini->ReadDate("MainForm","Date2",Date());
  Date1=Date();
  Date2=Date();

  selectedSD=ini->ReadInteger("MainForm","selectedSD",0);
  workGrid->Columns->Items[0]->Width=ini->ReadInteger("MainForm","Col0_Width",50);
  workGrid->Columns->Items[1]->Width=ini->ReadInteger("MainForm","Col1_Width",72);
  workGrid->Columns->Items[2]->Width=ini->ReadInteger("MainForm","Col2_Width",90);
  workGrid->Columns->Items[3]->Width=ini->ReadInteger("MainForm","Col3_Width",90);
  workGrid->Columns->Items[4]->Width=ini->ReadInteger("MainForm","Col4_Width",140);
  workGrid->Columns->Items[5]->Width=ini->ReadInteger("MainForm","Col5_Width",70);
  workGrid->Columns->Items[6]->Width=ini->ReadInteger("MainForm","Col6_Width",70);
  workGrid->Columns->Items[7]->Width=ini->ReadInteger("MainForm","Col7_Width",100);

  workGrid4->Columns->Items[0]->Width=ini->ReadInteger("MainForm","Col0_Width3",50);
  workGrid4->Columns->Items[1]->Width=ini->ReadInteger("MainForm","Col1_Width3",72);
  workGrid4->Columns->Items[2]->Width=ini->ReadInteger("MainForm","Col2_Width3",90);
  workGrid4->Columns->Items[3]->Width=ini->ReadInteger("MainForm","Col3_Width3",90);
  workGrid4->Columns->Items[4]->Width=ini->ReadInteger("MainForm","Col4_Width3",140);
  workGrid4->Columns->Items[5]->Width=ini->ReadInteger("MainForm","Col5_Width3",70);
  workGrid4->Columns->Items[6]->Width=ini->ReadInteger("MainForm","Col6_Width3",70);
  workGrid4->Columns->Items[7]->Width=ini->ReadInteger("MainForm","Col7_Width3",100);

  workGrid5->Columns->Items[0]->Width=ini->ReadInteger("MainForm","Col0_Width4",50);
  workGrid5->Columns->Items[1]->Width=ini->ReadInteger("MainForm","Col1_Width4",72);
  workGrid5->Columns->Items[2]->Width=ini->ReadInteger("MainForm","Col2_Width4",90);
  workGrid5->Columns->Items[3]->Width=ini->ReadInteger("MainForm","Col3_Width4",90);
  workGrid5->Columns->Items[4]->Width=ini->ReadInteger("MainForm","Col4_Width4",140);
  workGrid5->Columns->Items[5]->Width=ini->ReadInteger("MainForm","Col5_Width4",70);
  workGrid5->Columns->Items[6]->Width=ini->ReadInteger("MainForm","Col6_Width4",70);
  workGrid5->Columns->Items[7]->Width=ini->ReadInteger("MainForm","Col7_Width4",100);

  selectedSD1=ini->ReadInteger("MainForm","selectedSD1",0);

  workGrid1->Columns->Items[0]->Width=ini->ReadInteger("MainForm","Col0_Width1",50);
  workGrid1->Columns->Items[1]->Width=ini->ReadInteger("MainForm","Col1_Width1",72);
  workGrid1->Columns->Items[2]->Width=ini->ReadInteger("MainForm","Col2_Width1",90);
  workGrid1->Columns->Items[3]->Width=ini->ReadInteger("MainForm","Col3_Width1",90);
  workGrid1->Columns->Items[4]->Width=ini->ReadInteger("MainForm","Col4_Width1",140);
  workGrid1->Columns->Items[5]->Width=ini->ReadInteger("MainForm","Col5_Width1",70);
  workGrid1->Columns->Items[6]->Width=ini->ReadInteger("MainForm","Col6_Width1",70);

  workGrid2->Columns->Items[0]->Width=ini->ReadInteger("MainForm","Col0_Width2",50);
  workGrid2->Columns->Items[1]->Width=ini->ReadInteger("MainForm","Col1_Width2",72);
  workGrid2->Columns->Items[2]->Width=ini->ReadInteger("MainForm","Col4_Width2",140);
  workGrid2->Columns->Items[3]->Width=ini->ReadInteger("MainForm","Col5_Width2",70);

  GridFontSize=ini->ReadInteger("MainForm","GridFontSize",workGrid->Font->Size);
  GridFontSize4=ini->ReadInteger("MainForm","GridFontSize4",workGrid4->Font->Size);
  GridFontSize5=ini->ReadInteger("MainForm","GridFontSize5",workGrid5->Font->Size);
  GridFontSize1=ini->ReadInteger("MainForm","GridFontSize1",workGrid1->Font->Size);
  GridFontSize2=ini->ReadInteger("MainForm","GridFontSize2",workGrid2->Font->Size);
  GridFontSize3=ini->ReadInteger("MainForm","GridFontSize3",selectSDBar->Font->Size);
  GridFontSize6=ini->ReadInteger("MainForm","GridFontSize3",selectSDBar1->Font->Size);

  workGrid->Font->Size=GridFontSize;
  workGrid->FooterFont->Size=GridFontSize;
  workGrid->TitleFont->Size=GridFontSize;

  workGrid4->Font->Size=GridFontSize4;
  workGrid4->FooterFont->Size=GridFontSize4;
  workGrid4->TitleFont->Size=GridFontSize4;

  workGrid5->Font->Size=GridFontSize5;
  workGrid5->FooterFont->Size=GridFontSize5;
  workGrid5->TitleFont->Size=GridFontSize5;

  workGrid1->Font->Size=GridFontSize1;
  workGrid1->FooterFont->Size=GridFontSize1;
  workGrid1->TitleFont->Size=GridFontSize1;

  workGrid2->Font->Size=GridFontSize2;
  workGrid2->FooterFont->Size=GridFontSize2;
  workGrid2->TitleFont->Size=GridFontSize2;
  selectSDBar->Font->Size=GridFontSize3;
  selectSDBar1->Font->Size=GridFontSize6;

  servername=ini->ReadString("MainForm","ServerName","");
  dbPath=ini->ReadString("MainForm","DBPathName","");
  uname=ini->ReadString("MainForm","UName","");
  pass=ini->ReadString("MainForm","p","");

  if(INS_DB->Connected==true) INS_DB->Connected=false;
  if(INS_DB!=NULL)
  {
    INS_DB->ConnectParams->UserName=uname;
    INS_DB->ConnectParams->Password=pass;
    INS_DB->ConnectParams->CharSet="WIN1251";
    INS_DB->SQLDialect=3;
    INS_DB->DBName=servername+":"+dbPath;
  }

  try
  {
    INS_DB->Connected=true;
  }
  catch(const Exception &exc)
  {
    MessageDlg("Ошибка подключения к серверу \"Инспектор\"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
    GSM_DM->connect_to_ins=false;
    return;
  }

  if(INS_DB->Connected==true) GSM_DM->connect_to_ins=true; else GSM_DM->connect_to_ins=false;
  delete ini;
  setMainHeader();
  SLabel->Left=ButtonsPanel->Width-SLabel->Width-5-SEdit->Width-4-FSButton->Width-4-BSButton->Width-5;
  SEdit->Left=SLabel->Left+SLabel->Width+5;
  FSButton->Left=SEdit->Left+SEdit->Width+4;
  BSButton->Left=FSButton->Left+FSButton->Width+4;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::FormDestroy(TObject *Sender)
{
TIniFile* ini;

  ini=new TIniFile(iniFileName);
  ini->WriteDate("MainForm","Date1",Date1);
  ini->WriteDate("MainForm","Date2",Date2);
  ini->WriteInteger("MainForm","selectedSD",selectedSD);
  ini->WriteInteger("MainForm","Col0_Width",workGrid->Columns->Items[0]->Width);
  ini->WriteInteger("MainForm","Col1_Width",workGrid->Columns->Items[1]->Width);
  ini->WriteInteger("MainForm","Col2_Width",workGrid->Columns->Items[2]->Width);
  ini->WriteInteger("MainForm","Col3_Width",workGrid->Columns->Items[3]->Width);
  ini->WriteInteger("MainForm","Col4_Width",workGrid->Columns->Items[4]->Width);
  ini->WriteInteger("MainForm","Col5_Width",workGrid->Columns->Items[5]->Width);
  ini->WriteInteger("MainForm","Col6_Width",workGrid->Columns->Items[6]->Width);
  ini->WriteInteger("MainForm","Col7_Width",workGrid->Columns->Items[7]->Width);

  ini->WriteInteger("MainForm","Col0_Width3",workGrid4->Columns->Items[0]->Width);
  ini->WriteInteger("MainForm","Col1_Width3",workGrid4->Columns->Items[1]->Width);
  ini->WriteInteger("MainForm","Col2_Width3",workGrid4->Columns->Items[2]->Width);
  ini->WriteInteger("MainForm","Col3_Width3",workGrid4->Columns->Items[3]->Width);
  ini->WriteInteger("MainForm","Col4_Width3",workGrid4->Columns->Items[4]->Width);
  ini->WriteInteger("MainForm","Col5_Width3",workGrid4->Columns->Items[5]->Width);
  ini->WriteInteger("MainForm","Col6_Width3",workGrid4->Columns->Items[6]->Width);
  ini->WriteInteger("MainForm","Col7_Width3",workGrid4->Columns->Items[7]->Width);

  ini->WriteInteger("MainForm","Col1_Width4",workGrid5->Columns->Items[1]->Width);
  ini->WriteInteger("MainForm","Col2_Width4",workGrid5->Columns->Items[2]->Width);
  ini->WriteInteger("MainForm","Col3_Width4",workGrid5->Columns->Items[3]->Width);
  ini->WriteInteger("MainForm","Col4_Width4",workGrid5->Columns->Items[4]->Width);
  ini->WriteInteger("MainForm","Col5_Width4",workGrid5->Columns->Items[5]->Width);
  ini->WriteInteger("MainForm","Col6_Width4",workGrid5->Columns->Items[6]->Width);
  ini->WriteInteger("MainForm","Col7_Width4",workGrid5->Columns->Items[7]->Width);

  ini->WriteInteger("MainForm","selectedSD1",selectedSD1);

  ini->WriteInteger("MainForm","Col0_Width1",workGrid1->Columns->Items[0]->Width);
  ini->WriteInteger("MainForm","Col1_Width1",workGrid1->Columns->Items[1]->Width);
  ini->WriteInteger("MainForm","Col2_Width1",workGrid1->Columns->Items[2]->Width);
  ini->WriteInteger("MainForm","Col3_Width1",workGrid1->Columns->Items[3]->Width);
  ini->WriteInteger("MainForm","Col4_Width1",workGrid1->Columns->Items[4]->Width);
  ini->WriteInteger("MainForm","Col5_Width1",workGrid1->Columns->Items[5]->Width);
  ini->WriteInteger("MainForm","Col6_Width1",workGrid1->Columns->Items[6]->Width);

  ini->WriteInteger("MainForm","Col0_Width2",workGrid2->Columns->Items[0]->Width);
  ini->WriteInteger("MainForm","Col1_Width2",workGrid2->Columns->Items[1]->Width);
  ini->WriteInteger("MainForm","Col4_Width2",workGrid2->Columns->Items[2]->Width);
  ini->WriteInteger("MainForm","Col5_Width2",workGrid2->Columns->Items[3]->Width);
  ini->WriteInteger("MainForm","GridFontSize",workGrid->Font->Size);
  ini->WriteInteger("MainForm","GridFontSize4",workGrid4->Font->Size);
  ini->WriteInteger("MainForm","GridFontSize5",workGrid5->Font->Size);
  ini->WriteInteger("MainForm","GridFontSize1",workGrid1->Font->Size);
  ini->WriteInteger("MainForm","GridFontSize2",workGrid2->Font->Size);
  ini->WriteInteger("MainForm","GridFontSize3",selectSDBar->Font->Size);
  ini->WriteInteger("MainForm","GridFontSize6",selectSDBar1->Font->Size);

  delete ini;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::initMainForm(void)
{
  AnsiString sql;
  int fk=0;
  AnsiString IndOps;
  int i,reccount;
  TpFIBDataSet *rDS=GSM_DM->RDS;
  int k=0;
  int pos1,pos2;

  for (int cidm=0;cidm<20;cidm++)
  {
  Massiv[cidm]="";
  }

  sql="select U_INDEX as INDOPS from USERS_TABLE where U_ID="+IntToStr(GSM_DM->UserID);
  rDS->SQLs->SelectSQL->Add(sql);
  try
  {
    rDS->Open();
  }
  catch (Exception &exc)
  {
    MessageDlg("Ошибка - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
    return;
  }
  IndOps=rDS->FieldByName("INDOPS")->AsString.Trim();
  rDS->Close();
  k=0;
  int cur=0, beg=IndOps.Pos(",");
  if (beg>0)
  {
  IndexOps="'";
  while(beg)
  {
    AnsiString S1=IndOps.SubString(cur,cur+beg-1);
    IndexOps=IndexOps+S1.Trim()+"','";
    Massiv[k]=S1.Trim();

    cur=beg+1;
    AnsiString S2=IndOps.SubString(cur,IndOps.Length());
    k++;
    IndOps=S2;
    cur=0;
    beg=IndOps.Pos(",");
    if (beg==0){
    IndexOps=IndexOps+S2.Trim()+"'";
    Massiv[k]= S2.Trim();
   }
  }
  KolOps=k;
  }
  else
  {
  IndexOps="'"+IndOps.Trim()+"'";
  KolOps=1;
  }
  if (GSM_DM->UserRole=="администратор" || GSM_DM->UserRole=="руководитель"){
  fk=0;
  }else
  {
  if (IndexOps.AnsiPos("центр")>0) fk=1;
  if (IndexOps.AnsiPos("жел")>0) fk=2;
  }
  IndexOdpp=Massiv[KolOps].SubString(1,6);


  // список кассиров и кассиров-бухгалтеров
  sql="";
  sql="select U_ID as UID from USERS_TABLE where U_ROLE IN ('кассир','бухгалтер-кассир')";
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
  return;
  }

  i=1;
  rDS->Last();
  reccount=rDS->RecordCount;
  ListOfKassa="";
  rDS->First();
  while(!rDS->Eof)
  {
    if (i==20) break;
    AnsiString KodKassa=IntToStr(rDS->FieldByName("UID")->AsInteger);
    ListOfKassa=ListOfKassa+KodKassa.Trim()+",";
    rDS->Next();
    i++;
  }

  if (GSM_DM->UserRole!="администратор" && GSM_DM->UserRole!="руководитель")
  {
  ListOfKassa=ListOfKassa+IntToStr(GSM_DM->UserID);
  }

  // дерево почтальонов
  sql="";
  sql="select DESCRIPTION as SD_NAME from OPS_TABLE where REC_TYPE=0 and FILE_ID=1 and ID<>8 and VISIBLE=1 ORDER BY DESCRIPTION";
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
  return;
  }

  i=1;
  rDS->Last();
  reccount=rDS->RecordCount;
  rDS->First();
  while(!rDS->Eof)
  {
    if (i==50) break;
    AnsiString sdName=rDS->FieldByName("SD_NAME")->AsString;
    selectSDBar->Items->Items[i]->Caption=sdName;
    selectSDBar->Items->Items[i]->Visible = true;
    rDS->Next();
    i++;
  }

  for (int k = reccount+1;k < selectSDBar->Items->Count; k++)
  {
  selectSDBar->Items->Items[k]->Visible = false;
  }

  rDS->Close();

  // дерево касс

  sql="";
  rDS->Close();
  sql="select DESCRIPTION as SD_NAME from KASSA_TABLE where REC_TYPE=0 and FILE_ID=1 and ID<>8 and VISIBLE=1 ORDER BY DESCRIPTION";
  rDS->SQLs->SelectSQL->Clear();
  rDS->SQLs->SelectSQL->Add(sql);
  try
  {
    rDS->Open();
  }
  catch (Exception &exc)
  {
  MessageDlg("Ошибка - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
  return;
  }

  i=1;
  rDS->Last();
  reccount=rDS->RecordCount;
  rDS->First();
  while(!rDS->Eof)
  {
    if (i==50) break;
    AnsiString sdName=rDS->FieldByName("SD_NAME")->AsString;
    selectSDBar1->Items->Items[i]->Visible = true;
    selectSDBar1->Items->Items[i]->Caption=sdName;
    rDS->Next();
    i++;
  }

  for (int k = reccount+1;k < selectSDBar1->Items->Count; k++)
  {
  selectSDBar1->Items->Items[k]->Visible = false;
  }

  if (fk==1) selectSDBar1->Items->Items[1]->Visible = false;
  if (fk==2) selectSDBar1->Items->Items[2]->Visible = false;

  rDS->Close();

  try
  {
    autoID1=new TStringList();
  }
  catch (Exception &exc)
  { MessageDlg("Ошибка создания объекта TStringList\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
    autoID1=NULL;
    return;
  }

  autoNumberEdit1->Items->Clear();
  autoNumberEdit1->Items->Add("По всем опс");
  autoID1->Add("0");
  if (GSM_DM->UserRole=="администратор" || GSM_DM->UserRole=="руководитель" || GSM_DM->UserRole=="кассир" || GSM_DM->UserRole=="бухгалтер-кассир"){
  if (GSM_DM->Index=="630926" || GSM_DM->Index=="630923" || GSM_DM->Index=="630924")
  {
  autoNumberEdit1->Items->Add(GSM_DM->Index);
  autoID1->Add(GSM_DM->Index);
  }
  if (GSM_DM->Index=="630922")
  {
    if (GSM_DM->UserRole=="администратор" || GSM_DM->UserRole=="руководитель")
    {
     autoNumberEdit1->Items->Add(GSM_DM->Index + " центр ");
     autoID1->Add(GSM_DM->Index + " центр ");
     autoNumberEdit1->Items->Add(GSM_DM->Index + " жел ");
     autoID1->Add(GSM_DM->Index + " жел ");
    }else
    {
     pos1=MainForm->IndexOps.Pos("жел");
     pos2=MainForm->IndexOps.Pos("центр");
     if (pos1>0)
     {
     autoNumberEdit1->Items->Add(GSM_DM->Index + " жел ");
     autoID1->Add(GSM_DM->Index + " жел ");
     }
     if (pos2>0)
     {
     autoNumberEdit1->Items->Add(GSM_DM->Index + " центр ");
     autoID1->Add(GSM_DM->Index + " центр ");
     }
    }
  }
  if (GSM_DM->Index=="630923")
  {
  autoNumberEdit1->Items->Add(GSM_DM->Index + " нсо ");
  autoID1->Add(GSM_DM->Index + " нсо ");
  }
  }

  rDS->Close();
  rDS->SQLs->SelectSQL->Clear();
  sql="";
  if (GSM_DM->UserRole!="администратор" && GSM_DM->UserRole!="руководитель"){
  sql="select distinct DESCRIPTION as SD_NAME from OPS_TABLE where REC_TYPE=1 and VISIBLE = 1 and DESCRIPTION IN (" + MainForm->IndexOps +") UNION select distinct DESCRIPTION as SD_NAME from KASSA_TABLE where REC_TYPE=1 and VISIBLE = 1 and DESCRIPTION IN (" + MainForm->IndexOps +") order by 1 ";
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
  while(!rDS->Eof)
  {
    AnsiString sdName1=rDS->FieldByName("SD_NAME")->AsString;
    autoNumberEdit1->Items->Add(sdName1);
    autoID1->Add(rDS->FieldByName("SD_NAME")->AsString);
    rDS->Next();
  }
  }
  autoNumberEdit1->ItemIndex=1;
  rDS->Close();

  try
  {
    autoID=new TStringList();
  }
  catch (Exception &exc)
  { MessageDlg("Ошибка создания объекта TStringList\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
    autoID=NULL;
    return;
  }

  autoNumberEdit->Items->Clear();
  autoNumberEdit->Items->Add("По всем опс");
  autoID->Add("0");
  if (GSM_DM->UserRole=="администратор" || GSM_DM->UserRole=="руководитель"){
  if (GSM_DM->Index=="630926" || GSM_DM->Index=="630923" || GSM_DM->Index=="630924")
  {
  autoNumberEdit->Items->Add(GSM_DM->Index);
  autoID->Add(GSM_DM->Index);
  }
  if (GSM_DM->Index=="630922")
  {
  autoNumberEdit->Items->Add(GSM_DM->Index + " центр ");
  autoID->Add(GSM_DM->Index + " центр ");
  autoNumberEdit->Items->Add(GSM_DM->Index + " жел ");
  autoID->Add(GSM_DM->Index + " жел ");
  }
  if (GSM_DM->Index=="630923")
  {
  autoNumberEdit->Items->Add(GSM_DM->Index + " нсо ");
  autoID->Add(GSM_DM->Index + " нсо ");
  }
  }

  rDS->Close();
  rDS->SQLs->SelectSQL->Clear();
  if (GSM_DM->UserRole!="администратор" && GSM_DM->UserRole!="руководитель"){
  sql="select distinct DESCRIPTION as SD_NAME from OPS_TABLE where REC_TYPE=1 and VISIBLE = 1 and DESCRIPTION IN (" + MainForm->IndexOps +") UNION select distinct DESCRIPTION as SD_NAME from KASSA_TABLE where REC_TYPE=1 and VISIBLE = 1 and DESCRIPTION IN (" + MainForm->IndexOps +") order by 1 ";
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
  while(!rDS->Eof)
  {
    AnsiString sdName=rDS->FieldByName("SD_NAME")->AsString;
    autoNumberEdit->Items->Add(sdName);
    autoID->Add(rDS->FieldByName("SD_NAME")->AsString);
    rDS->Next();
  }
  }
  autoNumberEdit->ItemIndex=1;
  rDS->Close();

  if(PC->ActivePageIndex == 0) {
  selectSDBar->Items->Items[selectedSD]->OnClick(this);
  Label1->Visible = true;
  autoNumberEdit->Visible = true;
  autoNumberEdit1->Visible = false;}

  if(PC->ActivePageIndex == 1) { selectSDBar1->Items->Items[selectedSD1]->OnClick(this);Label1->Visible = true;autoNumberEdit1->Visible = true;autoNumberEdit->Visible = false;}
  if(PC->ActivePageIndex == 2){
  LoadWorkDS(getSD_ID(),getID());
  autoNumberEdit->Visible = false;
  autoNumberEdit1->Visible = false;
  Label1->Visible = false;
  }

 if (GSM_DM->UserRole=="администратор" || GSM_DM->UserRole=="руководитель") {
 TabSheet1->TabVisible = true;
 TabSheet2->TabVisible = true;
 TabSheet3->TabVisible = true;PC->ActivePageIndex = 2;
 }


if (GSM_DM->UserRole=="бухгалтер") { TabSheet1->TabVisible = true;TabSheet2->TabVisible = false;TabSheet3->TabVisible = false;PC->ActivePageIndex = 0;}
if (GSM_DM->UserRole=="кассир") { TabSheet1->TabVisible = false;TabSheet2->TabVisible = true;TabSheet3->TabVisible = false;PC->ActivePageIndex = 1;}
if (GSM_DM->UserRole=="бухгалтер-кассир") { TabSheet1->TabVisible = true;TabSheet2->TabVisible = true;TabSheet3->TabVisible = false;PC->ActivePageIndex = 0;}
setMainHeader();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::setMainHeader(void)
{
AnsiString s;
AnsiString OPS1;
int index;

if(PC->ActivePageIndex == 0) index = autoNumberEdit->ItemIndex;
if(PC->ActivePageIndex == 1) index = autoNumberEdit1->ItemIndex;

if (index >= 0)
{
if(PC->ActivePageIndex == 0) OPS1=autoID->Strings[index];
if(PC->ActivePageIndex == 1) OPS1=autoID1->Strings[index];
}
else
{
OPS1="0";
}

 if (AnsiPos(GSM_DM->Index,OPS1.Trim())>0)
 {
// workGrid4->Visible=false;
// workGrid5->Visible=false;
 workGrid4->Enabled=false;
 workGrid5->Enabled=false;
 }else
 {
 workGrid4->Enabled=true;
 workGrid5->Enabled=true;
// workGrid5->Visible=true;
// workGrid4->Visible=true;
 }

  if(PC->ActivePageIndex == 0) { s=selectSDBar->Items->Items[selectedSD]->Caption;autoNumberEdit->Visible = true; autoNumberEdit1->Visible = false;Label1->Visible = true;}
  if(PC->ActivePageIndex == 1) { s=selectSDBar1->Items->Items[selectedSD1]->Caption;autoNumberEdit->Visible = false;autoNumberEdit1->Visible = true; Label1->Visible = true;}
  if(PC->ActivePageIndex == 2) { s=" ОДПП ";autoNumberEdit->Visible = false; autoNumberEdit1->Visible = false; Label1->Visible = false;}
  if(Date1 == Date2) s+=" - учет операций за "+Date1.DateString();
  else s+=" - учет операций за период с "+Date1.DateString()+" по "+Date2.DateString();
  if (OPS1.Trim() != "0" && PC->ActivePageIndex < 2) s+= " по ОПС -> " + OPS1.Trim();
  MainHeader->Caption=s;
}

TURB * __fastcall TMainForm::getGSM_RB(int flag)
{
TURB *GSM_RB=NULL;

  try
  {
    GSM_RB=new TURB(this,"OPER_TABLE",flag);
  }
  catch (Exception &exc)
  {
    MessageDlg("Ошибка создания справочника GSM_RB\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
  }
//  if(GSM_RB!=NULL){
//  GSM_RB->raCheck=&rbRemoveableCheck;
//  GSM_RB->FindPositionInTreeViewForFolderName("Расход");
//  }
  return GSM_RB;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::N2Click(TObject *Sender)
{
TURB *GSM_RB=getGSM_RB(0);

  if(GSM_RB==NULL) return;
  GSM_RB->ShowModal();
  delete GSM_RB;
}
//---------------------------------------------------------------------------
TURB * __fastcall TMainForm::getDistinations_RB(void)
{
TURB *Distinations_RB=NULL;

  try
  {
    Distinations_RB=new TURB(this,"DISTINATIONS_TABLE",0);
  }
  catch (Exception &exc)
  {
    MessageDlg("Ошибка создания справочника DISTINATIONS_RB\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
  }
  if(Distinations_RB!=NULL) Distinations_RB->raCheck=&rbRemoveableCheck;
  return Distinations_RB;
}
//---------------------------------------------------------------------------
TURB * __fastcall TMainForm::getDrivers_RB(AnsiString sdName)
{
TURB *Drivers_RB=NULL;

  try
  {
    if (selectedMenu==1){
//    if (GSM_DM->UserRole!="администратор") Drivers_RB=new TURB(this,"OPS_TABLE",1);
    Drivers_RB=new TURB(this,"OPS_TABLE",0);
    }
    if (selectedMenu==2){
//    if (GSM_DM->UserRole!="администратор") Drivers_RB=new TURB(this,"KASSA_TABLE",1);
    Drivers_RB=new TURB(this,"KASSA_TABLE",0);
    }
  }
  catch (Exception &exc)
  {
    MessageDlg("Ошибка создания справочника \n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
  }
  if(Drivers_RB!=NULL)
  { Drivers_RB->raCheck=&rbRemoveableCheck;
    if(!sdName.IsEmpty())
    {
    Drivers_RB->FindPositionInTreeViewForFolderName(sdName);
    }
  }
  return Drivers_RB;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::N6Click(TObject *Sender)
{

selectedMenu=1;
//TURB *Drivers_RB=getDrivers_RB(selectSDBar->Items->Items[selectedSD]->Caption);
TURB *Drivers_RB=getDrivers_RB("Почтальоны");

  if(Drivers_RB==NULL) return;
  Drivers_RB->ShowModal();
  delete Drivers_RB;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::FormShow(TObject *Sender)
{
AnsiString s;
AnsiString OPS1;
int index;
selectedMenu=0;

if(PC->ActivePageIndex == 0) index = autoNumberEdit->ItemIndex;
if(PC->ActivePageIndex == 1) index = autoNumberEdit1->ItemIndex;

if (index >= 0)
{
if(PC->ActivePageIndex == 0) OPS1=autoID->Strings[index];
if(PC->ActivePageIndex == 1) OPS1=autoID1->Strings[index];
}
else
{
OPS1="0";
}

  if (GSM_DM->UserRole=="администратор")
  {
  N4->Visible = false;
  N7->Visible = true;
  N23->Visible = true;
  TabSheet3->TabVisible = true;
  workGrid->Columns->Items[6]->Width=100;
  workGrid4->Columns->Items[6]->Width=100;
  workGrid5->Columns->Items[6]->Width=100;
  workGrid1->Columns->Items[6]->Width=100;
  }else
  {
  N4->Visible = true;
  N7->Visible = false;

  if (GSM_DM->UserRole=="руководитель")
  {
  TabSheet3->TabVisible = true;
  workGrid->Columns->Items[6]->Width=100;
  workGrid4->Columns->Items[6]->Width=100;
  workGrid5->Columns->Items[6]->Width=100;
  workGrid1->Columns->Items[6]->Width=100;
  N12->Visible = true;
  N11->Visible = true;
  N11->Visible = true;
  N23->Visible = true;
  N17->Visible = true;
  }else
  {
  TabSheet3->TabVisible = false;
  workGrid->Columns->Items[6]->Width=0;
  workGrid4->Columns->Items[6]->Width=0;
  workGrid5->Columns->Items[6]->Width=0;
  workGrid1->Columns->Items[6]->Width=100;
  N12->Visible = false;
  N11->Visible = false;
  N11->Visible = false;
  N23->Visible = false;
  N17->Visible = false;
  }

  if (GSM_DM->UserRole=="бухгалтер") { N16->Visible = false;} else {N16->Visible = true;}

  }

  if(GSM_DM->VerForm==1)
  {
  if (GSM_DM->UserRole!="администратор" && GSM_DM->UserRole!="руководитель"){
    JvNavPanelHeader1->Caption="Приход/Расход/Возврат";
  }else
  {
   if (AnsiPos(GSM_DM->Index,OPS1.Trim())>0) JvNavPanelHeader1->Caption="Приход"; else JvNavPanelHeader1->Caption="Приход/Расход/Возврат";
  }
  Panel4->Align=alClient;
  Panel5->Visible=false;
  Panel6->Visible=false;
  }else
  {
  JvNavPanelHeader1->Caption="Приход";
  Panel4->Align=alTop;
  Panel5->Visible=true;
  Panel6->Visible=true;
  }

  ImportButton->Enabled = false;
  ScanButton->Enabled = false;
  reloadButton->Enabled = false;
  impItem->Visible = false;
  LoadWorkDS(getSD_ID(),getID());
  selectSDBarClick(this);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::N3Click(TObject *Sender)
{
  Close();
}
//---------------------------------------------------------------------------
//Выбор периода
void __fastcall TMainForm::PeriodButtonClick(TObject *Sender)
{
TSelectPeriodForm *SPF;

  try
  {
    SPF=new TSelectPeriodForm(this,Date1,Date2);
  }
  catch (Exception &exc)
  { MessageDlg("Ошибка создания формы SelectPeriodForm\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
    return;
  }
  if(SPF->ShowModal()==mrOk)
  {
    Date1=SPF->getDate1();
    Date2=SPF->getDate2();
    setMainHeader();
    LoadWorkDS(getSD_ID(),getID());
  }
  if(SPF!=NULL) delete SPF;
}
//---------------------------------------------------------------------------
AnsiString __fastcall TMainForm::getWorkDir(void)
{
  return workDir;
}
//---------------------------------------------------------------------------
AnsiString __fastcall TMainForm::getSD_ID(void)
{
AnsiString sdID="";
AnsiString sql="";
TpFIBQuery *RQ=GSM_DM->RQ;
AnsiString sdName,sdName1;

sdName="";
sdName1="";


  if(PC->ActivePageIndex == 2) return sdID;
  sdName=selectSDBar->Items->Items[selectedSD]->Caption;
  sdName1=selectSDBar1->Items->Items[selectedSD1]->Caption;
  if(PC->ActivePageIndex == 0) if(selectedSD==0) return sdID;
  if(PC->ActivePageIndex == 1) if(selectedSD1==0) return sdID;
  RQ->Close();
  RQ->SQL->Clear();

  if(PC->ActivePageIndex == 0)
  {
  sql="select ID from OPS_TABLE";
  sql+=" where DESCRIPTION like '"+sdName+"'";
  }

  if(PC->ActivePageIndex == 1)
  {
  sql="select ID from KASSA_TABLE";
  sql+=" where DESCRIPTION like '"+sdName1+"'";
  }

  RQ->SQL->Add(sql);
  try
  {
    RQ->ExecQuery();
  }
  catch (Exception &exc)
  { MessageDlg("Ошибка - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
    return sdID;
  }
  sdID=RQ->FieldByName("ID")->AsString;
  RQ->Close();
  return sdID;
}

//---------------------------------------------------------------------------
AnsiString __fastcall TMainForm::getID(void)
{
int index,index1;
AnsiString ID="";
AnsiString sql="";
TpFIBQuery *RQ=GSM_DM->RQ;
AnsiString sdID=getSD_ID();
AnsiString OPS,OPS1;

index=0;
OPS="";
index1=0;
OPS1="";

index = autoNumberEdit->ItemIndex;
index1 = autoNumberEdit1->ItemIndex;

OPS=autoID->Strings[index];
OPS1=autoID1->Strings[index1];

  if(PC->ActivePageIndex == 2) return ID;
  if(PC->ActivePageIndex == 0) if(selectedSD==0) return ID;
  if(PC->ActivePageIndex == 1) if(selectedSD1==0) return ID;
  RQ->Close();
  RQ->SQL->Clear();

  if(PC->ActivePageIndex == 0)
  {
  sql="select ID from OPS_TABLE";
  sql+=" where DESCRIPTION like '"+OPS.Trim()+"'";
  if (!(sdID.Trim()=="")) sql+= " and FILE_ID = "+sdID.Trim();
  }

  if(PC->ActivePageIndex == 1)
  {
  sql="select ID from KASSA_TABLE";
  sql+=" where DESCRIPTION like '"+OPS1.Trim()+"'";
  if (!(sdID.Trim()=="")) sql+= " and FILE_ID = "+sdID.Trim();
  }

  RQ->SQL->Add(sql);
  try
  {
    RQ->ExecQuery();
  }
  catch (Exception &exc)
  { MessageDlg("Ошибка - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
    return ID;
  }
  ID=RQ->FieldByName("ID")->AsString;
  RQ->Close();
  return ID;
}


//---------------------------------------------------------------------------
void __fastcall TMainForm::LoadWorkDS(AnsiString sdID,AnsiString ID)
{
AnsiString sql;
int index = autoNumberEdit->ItemIndex;
AnsiString OPS=autoID->Strings[index];

int index1 = autoNumberEdit1->ItemIndex;
AnsiString OPS1=autoID1->Strings[index1];

  if(PC->ActivePageIndex == 0){
  if(workDS->Active==true) workDS->Active=false;
  workDS->SQLs->SelectSQL->Clear();
  sql="select e.*, d.DESCRIPTION as DRIVER, m.DESCRIPTION as GSM";
  if (GSM_DM->UserRole=="администратор" || GSM_DM->UserRole=="руководитель") sql+=", u.U_NAME as FIO ";
  sql+=" , sd.description as FIOP";
  sql+=" from EXPENSES_TABLE e";
  sql+=" left outer join OPS_TABLE sd on sd.ID=e.SD_ID";
  sql+=" left outer join OPS_TABLE d on d.ID=e.DRIVER_ID";
  sql+=" left outer join OPER_TABLE m on m.ID=e.GSM_ID";
  if (GSM_DM->UserRole=="администратор" || GSM_DM->UserRole=="руководитель") sql+=" left outer join USERS_TABLE u on u.U_ID=e.U_ID";
  sql+=" where e.EXP_DATE >= '"+Date1.DateString()+"'";
  sql+=" and e.EXP_DATE <= '"+Date2.DateString()+"'";
  if(!sdID.IsEmpty()) sql+=" and e.SD_ID="+sdID;
  if(!ID.IsEmpty())
  {
  sql+=" and e.DRIVER_ID="+ID;
  }
  else
  {
  if (OPS.Trim()!="0") sql+=" and d.DESCRIPTION='" + OPS.Trim()+ "'";
  }
  if (GSM_DM->UserRole!="администратор" && GSM_DM->UserRole!="руководитель") sql+=" and U_ID="+IntToStr(GSM_DM->UserID);
  sql+=" and m.VISIBLE=1";
  sql+=" and sd.VISIBLE=1";
  sql+=" and d.VISIBLE=1";
  sql+=" and e.FLAG=1";
  if (GSM_DM->VerForm==0) sql+=" and e.GSM_ID IN (17,6,3,93,92,99)";
  sql+=selectString;
  sql+=sortString;
  workDS->SQLs->SelectSQL->Add(sql);
  try
  {
    workDS->Open();
  }
  catch (Exception &exc)
  { MessageDlg("Ошибка - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
    return;
  }

  if(workDS3->Active==true) workDS3->Active=false;
  workDS3->SQLs->SelectSQL->Clear();
  sql="select e.*, d.DESCRIPTION as DRIVER,m.DESCRIPTION as GSM";
  if (GSM_DM->UserRole=="администратор" || GSM_DM->UserRole=="руководитель") sql+=", u.U_NAME as FIO";
  sql+=" , sd.description as FIOP";
  sql+=" from EXPENSES_TABLE e";
  sql+=" left outer join OPS_TABLE sd on sd.ID=e.SD_ID";
  sql+=" left outer join OPS_TABLE d on d.ID=e.DRIVER_ID";
  sql+=" left outer join OPER_TABLE m on m.ID=e.GSM_ID";
  if (GSM_DM->UserRole=="администратор" || GSM_DM->UserRole=="руководитель") sql+=" left outer join USERS_TABLE u on u.U_ID=e.U_ID";
  sql+=" where e.EXP_DATE >= '"+Date1.DateString()+"'";
  sql+=" and e.EXP_DATE <= '"+Date2.DateString()+"'";
  if(!sdID.IsEmpty()) sql+=" and e.SD_ID="+sdID;
  if(!ID.IsEmpty())
  {
  sql+=" and e.DRIVER_ID="+ID;
  }
  else
  {
  if (OPS.Trim()!="0") sql+=" and d.DESCRIPTION='" + OPS.Trim()+ "'";
  }
  if (GSM_DM->UserRole!="администратор" && GSM_DM->UserRole!="руководитель") sql+=" and U_ID="+IntToStr(GSM_DM->UserID);
  sql+=" and m.VISIBLE=1";
  sql+=" and sd.VISIBLE=1";
  sql+=" and d.VISIBLE=1";
  sql+=" and e.FLAG=1";
  sql+=" and e.GSM_ID IN (35,39,37,36,44)";
  sql+=selectString;
  sql+=sortString1;
  workDS3->SQLs->SelectSQL->Add(sql);
  try
  {
    workDS3->Open();
  }
  catch (Exception &exc)
  { MessageDlg("Ошибка - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
    return;
  }

  if(workDS4->Active==true) workDS4->Active=false;
  workDS4->SQLs->SelectSQL->Clear();
  sql="select e.*, d.DESCRIPTION as DRIVER,m.DESCRIPTION as GSM";
  if (GSM_DM->UserRole=="администратор" || GSM_DM->UserRole=="руководитель") sql+=", u.U_NAME as FIO";
  sql+=" , sd.description as FIOP";
  sql+=" from EXPENSES_TABLE e";
  sql+=" left outer join OPS_TABLE sd on sd.ID=e.SD_ID";
  sql+=" left outer join OPS_TABLE d on d.ID=e.DRIVER_ID";
  sql+=" left outer join OPER_TABLE m on m.ID=e.GSM_ID";
  if (GSM_DM->UserRole=="администратор" || GSM_DM->UserRole=="руководитель") sql+=" left outer join USERS_TABLE u on u.U_ID=e.U_ID";
  sql+=" where e.EXP_DATE >= '"+Date1.DateString()+"'";
  sql+=" and e.EXP_DATE <= '"+Date2.DateString()+"'";
  if(!sdID.IsEmpty()) sql+=" and e.SD_ID="+sdID;
  if(!ID.IsEmpty())
  {
  sql+=" and e.DRIVER_ID="+ID;
  }
  else
  {
  if (OPS.Trim()!="0") sql+=" and d.DESCRIPTION='" + OPS.Trim()+ "'";
  }
  if (GSM_DM->UserRole!="администратор" && GSM_DM->UserRole!="руководитель") sql+=" and U_ID="+IntToStr(GSM_DM->UserID);
  sql+=" and m.VISIBLE=1";
  sql+=" and sd.VISIBLE=1";
  sql+=" and d.VISIBLE=1";
  sql+=" and e.FLAG=1";
  sql+=" and e.GSM_ID IN (73,74,75,77,78)";
  sql+=selectString;
  sql+=sortString2;
  workDS4->SQLs->SelectSQL->Add(sql);
  try
  {
    workDS4->Open();
  }
  catch (Exception &exc)
  { MessageDlg("Ошибка - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
    return;
  }


  if(selectString.IsEmpty()) UnSelectButton->Enabled=false;
  else UnSelectButton->Enabled=true;
  workGrid->SetFocus();
  RashetWorkDS();
  }

  if(PC->ActivePageIndex == 1){
  if(workDS1->Active==true) workDS1->Active=false;
  workDS1->SQLs->SelectSQL->Clear();
  sql="select e.*, d.DESCRIPTION as DRIVER,m.DESCRIPTION as GSM";
  if (GSM_DM->UserRole=="администратор" || GSM_DM->UserRole=="руководитель" || GSM_DM->UserRole=="кассир" || GSM_DM->UserRole=="бухгалтер-кассир") sql+=", u.U_NAME as FIO";
  sql+=" , sd.description as FIOP";
  sql+=" from EXPENSES_TABLE e";
  sql+=" left outer join KASSA_TABLE sd on sd.ID=e.SD_ID";
  sql+=" left outer join KASSA_TABLE d on d.ID=e.DRIVER_ID";
  sql+=" left outer join OPER_TABLE m on m.ID=e.GSM_ID";
  if (GSM_DM->UserRole=="администратор" || GSM_DM->UserRole=="руководитель" || GSM_DM->UserRole=="кассир" || GSM_DM->UserRole=="бухгалтер-кассир") sql+=" left outer join USERS_TABLE u on u.U_ID=e.U_ID";
  sql+=" where e.EXP_DATE >= '"+Date1.DateString()+"'";
  sql+=" and e.EXP_DATE <= '"+Date2.DateString()+"'";
  if(!sdID.IsEmpty()) sql+=" and e.SD_ID="+sdID;

  if(!ID.IsEmpty())
  {
  sql+=" and e.DRIVER_ID="+ID;
  }
  else
  {
   if (OPS1.Trim()!="0")
   {
   sql+=" and d.DESCRIPTION='" + OPS1.Trim()+ "'";
   }
   else
   {
//   sql+=" and d.DESCRIPTION IN (" + MainForm->IndexOps +")";
   }
  }

//  if (GSM_DM->UserRole!="администратор" && GSM_DM->UserRole!="руководитель")
//  {
//  if (GSM_DM->UserRole=="кассир" || GSM_DM->UserRole=="бухгалтер-кассир") {sql+=" and e.U_ID IN (" + MainForm->ListOfKassa +")";}
//  }

  if (GSM_DM->UserRole!="администратор" && GSM_DM->UserRole!="руководитель") sql+=" and e.U_ID="+IntToStr(GSM_DM->UserID);
  sql+=" and m.VISIBLE=1";
  sql+=" and sd.VISIBLE=1";
  sql+=" and d.VISIBLE=1";
  sql+=" and e.FLAG=0";   
  sql+=" and e.GSM_ID IN (35,39,37,36,44,92,93,96,97,98,99,103)";
  sql+=selectString;
  sql+=sortString;
  workDS1->SQLs->SelectSQL->Add(sql);
  try
  {
    workDS1->Open();
  }
  catch (Exception &exc)
  { MessageDlg("Ошибка - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
    return;
  }
  if(selectString.IsEmpty()) UnSelectButton->Enabled=false;
  else UnSelectButton->Enabled=true;
  workGrid1->SetFocus();
  }

  if(PC->ActivePageIndex == 2){
  if(workDS2->Active==true) workDS2->Active=false;
  workDS2->SQLs->SelectSQL->Clear();
  sql="select e.*, \
m.DESCRIPTION as GSM";
  sql+=" from EXPENSES_TABLE e";
  sql+=" left outer join OPER_TABLE m on m.ID=e.GSM_ID";
  sql+=" where e.EXP_DATE >= '"+Date1.DateString()+"'";
  sql+=" and e.EXP_DATE <= '"+Date2.DateString()+"'";
  if (GSM_DM->UserRole!="администратор" && GSM_DM->UserRole!="руководитель") sql+=" and U_ID="+IntToStr(GSM_DM->UserID);
  sql+=" and m.VISIBLE=1";
  sql+=" and e.SD_ID=0";
  sql+=" and e.FLAG=0";
  sql+=selectString1;
  sql+=sortString;
  workDS2->SQLs->SelectSQL->Add(sql);
  try
  {
    workDS2->Open();
  }
  catch (Exception &exc)
  { MessageDlg("Ошибка - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
    return;
  }
  if(selectString.IsEmpty()) UnSelectButton->Enabled=false;
  else UnSelectButton->Enabled=true;
  workGrid2->SetFocus();
  }
}
//---------------------------------------------------------------------------
//
void __fastcall TMainForm::workGridKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
  if(Key == VK_F11)
  { TRect r=workGrid->CellRect(workGrid->Col,workGrid->Row);
    int x=this->Left+r.Left+r.Width();
    int y=this->Top+workGrid->Top+r.Top+r.Height()+15;
//    Mouse->CursorPos=TPoint(x,y);
    Mouse->CursorPos=TPoint(x+30,y+5);
    workGridPM->Popup(x,y);
    Mouse->CursorPos=TPoint(x,y);
  }
}
//---------------------------------------------------------------------------
//Конфигурирование справочников
void __fastcall TMainForm::N18Click(TObject *Sender)
{
  if(!Application->FindComponent("RBConfigurationForm"))
  { try
    {
      Application->CreateForm(__classid(TRBConfigurationForm), &RBConfigurationForm);
    }
    catch (Exception &exc)
    { MessageDlg("Ошибка создания формы RBConfigurationForm\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      return;
    }
  }
  RBConfigurationForm->Show();
}
//---------------------------------------------------------------------------
//Функция проверки возможности удаления записи из справочника
bool __fastcall TMainForm::rbRemoveableCheck(AnsiString tn, AnsiString id)
{
AnsiString sql;
TpFIBQuery *Q=GSM_DM->RQ;

  Q->Close();
  Q->SQL->Clear();
  if(tn=="OPER_TABLE")
    sql="select count(GSM_ID) as record_count from EXPENSES_TABLE where GSM_ID="+id;
  else if(tn=="OPS_TABLE")
    sql="select count(DRIVER_ID) as record_count from EXPENSES_TABLE where DRIVER_ID="+id;
  else if(tn=="KASSA_TABLE")
    sql="select count(DRIVER_ID) as record_count from EXPENSES_TABLE where DRIVER_ID="+id;
  else return false;
  Q->SQL->Add(sql);
  try
  {
    Q->ExecQuery();
  }
  catch(const Exception &exc)
  { MessageDlg("Ошибка "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
    return false;
  }
  if(Q->FieldByName("RECORD_COUNT")->AsInteger > 0) return false;
  else return true;
}
//---------------------------------------------------------------------------
//Добавление новой записи
void __fastcall TMainForm::addItemClick(TObject *Sender)
{
TAddEditExpenseForm *EF;
ExpensesData *ed;
int flag;
int fkassa;

int index = autoNumberEdit->ItemIndex;
AnsiString OPS=autoID->Strings[index];

int index1 = autoNumberEdit1->ItemIndex;
AnsiString OPS1=autoID1->Strings[index1];


TpFIBQuery *Q=GSM_DM->WQ;
TpFIBQuery *QR=GSM_DM->RQ;

AnsiString sql;

if(PC->ActivePageIndex == 0) selectedOPS=OPS;
if(PC->ActivePageIndex == 1) selectedOPS=OPS1;

if (workGrid->Focused()) ActivTable=1;
if (workGrid4->Focused()) ActivTable=2;
if (workGrid5->Focused()) ActivTable=3;
if (workGrid1->Focused()) ActivTable=4;
if (workGrid2->Focused()) ActivTable=5;

flag=0;
fkassa=0;
if(PC->ActivePageIndex == 0 || PC->ActivePageIndex == 1) flag=1;
if(PC->ActivePageIndex == 2) flag=2;
if(PC->ActivePageIndex == 0 ) fkassa=1;
if(PC->ActivePageIndex == 1 || PC->ActivePageIndex == 2) fkassa=0;

  try
  {
    ed=new ExpensesData();
  }
  catch (Exception &exc)
  {
    MessageDlg("Ошибка создания объекта ExpensesData\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
    return;
  }
  try
  {
    EF=new TAddEditExpenseForm(this,ed);
  }
  catch (Exception &exc)
  {
    MessageDlg("Ошибка создания формы AddEditExpenseForm\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
    return;
  }
  if(PC->ActivePageIndex == 0 || PC->ActivePageIndex == 1) EF->getED()->setSD_ID(StrToInt(getSD_ID()));
  if(PC->ActivePageIndex == 0 || PC->ActivePageIndex == 1)
  {
   if(!getID().IsEmpty())
   {
   EF->getED()->setDriverID(StrToInt(getID()));
   EF->getED()->setDriverName(selectedOPS.Trim());
   }
   else
   {
    if(PC->ActivePageIndex == 0)
    {
    int id_ops=0;

    Q->Close();
    Q->SQL->Clear();
    sql="select GEN_ID(GEN_OPS_TABLE_ID,1) as ID from RDB$DATABASE";
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
    if(Q->RecordCount==0)
    {
      MessageDlg("Ошибка получения значения ID таблицы OPS_TABLE",mtError,TMsgDlgButtons() << mbOK,0);
      Q->Transaction->Rollback();
      return;
    }
    id_ops=Q->FieldByName("ID")->AsInteger;

    Q->Close();
    Q->SQL->Clear();
    sql="insert into OPS_TABLE(ID,FILE_ID,USER_ID,REC_TYPE,DESCRIPTION,VISIBLE) values(";
    sql+=IntToStr(id_ops)+",";
    sql+=IntToStr(ed->getSD_ID())+",";
    sql+=IntToStr(GSM_DM->UserID)+",1,";
    sql+="'"+selectedOPS.Trim()+"',1)";
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
    EF->getED()->setDriverID(StrToInt(id_ops));
    EF->getED()->setDriverName(selectedOPS.Trim());
    }

    if(PC->ActivePageIndex == 1)
    {
    int id_kassa=0;

    Q->Close();
    Q->SQL->Clear();
    sql="select GEN_ID(GEN_KASSA_TABLE_ID,1) as ID from RDB$DATABASE";
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
    if(Q->RecordCount==0)
    {
      MessageDlg("Ошибка получения значения ID таблицы KASSA_TABLE",mtError,TMsgDlgButtons() << mbOK,0);
      Q->Transaction->Rollback();
      return;
    }
    id_kassa=Q->FieldByName("ID")->AsInteger;

    Q->Close();
    Q->SQL->Clear();
    sql="insert into KASSA_TABLE(ID,FILE_ID,USER_ID,REC_TYPE,DESCRIPTION,VISIBLE) values(";
    sql+=IntToStr(id_kassa)+",";
    sql+=IntToStr(ed->getSD_ID())+",";
    sql+=IntToStr(GSM_DM->UserID)+",1,";
    sql+="'"+selectedOPS.Trim()+"',1)";
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
    EF->getED()->setDriverID(StrToInt(id_kassa));
    EF->getED()->setDriverName(selectedOPS.Trim());
    }


   }
  }
  if(PC->ActivePageIndex == 2) EF->getED()->setSD_ID(0);
  if(PC->ActivePageIndex == 2) EF->getED()->setDriverID(0);
  if(PC->ActivePageIndex == 0) EF->getED()->setSD_Name(selectSDBar->Items->Items[selectedSD]->Caption);
  if(PC->ActivePageIndex == 1) EF->getED()->setSD_Name(selectSDBar1->Items->Items[selectedSD1]->Caption);
  if(PC->ActivePageIndex == 2) EF->getED()->setSD_Name("ОДПП");
  if(PC->ActivePageIndex == 0 || PC->ActivePageIndex == 1) EF->Kol->Text=EF->getED()->getKol();
//if(PC->ActivePageIndex == 2) EF->Kol->Text=0;
  if(EF->ShowModal()==mrOk)
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
    { MessageDlg("Ошибка получения значения ID таблицы EXPENSES_TABLE",mtError,TMsgDlgButtons() << mbOK,0);
      Q->Transaction->Rollback();
      return;
    }
    id=Q->FieldByName("ID")->AsInteger;

    Q->Close();
    Q->SQL->Clear();
    sql="insert into EXPENSES_TABLE(ID,EXP_DATE,SD_ID,DRIVER_ID,GSM_ID,KOL,EXPENSE,FLAG,EDITABLE,U_ID,D) values(";
    sql+=IntToStr(id)+",";
    sql+="'"+ed->getExpDate().DateString()+"',";
    sql+=IntToStr(ed->getSD_ID())+",";
    sql+=IntToStr(ed->getDriverID())+",";
    sql+=IntToStr(ed->getGSMID())+",";
    sql+=IntToStr(ed->getKol())+",";
    sql+=FloatToStr(ed->getExpense())+",";
    sql+=IntToStr(fkassa)+",1,";
    sql+=IntToStr(GSM_DM->UserID)+",";
    if (ed->getGSMID() == 58) sql+="1)";else sql+=IntToStr(ed->getD())+")";
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
    rashet(ed);
    newost(Date2);
    LoadWorkDS(getSD_ID(),getID());
    TLocateOptions lo; lo.Clear();
    if(PC->ActivePageIndex == 0){
    if(ActivTable == 1) workDS->Locate("ID",id,lo);
    if(ActivTable == 2) workDS3->Locate("ID",id,lo);
    if(ActivTable == 3) workDS4->Locate("ID",id,lo);
    }
    if(PC->ActivePageIndex == 1) workDS1->Locate("ID",id,lo);
    if(PC->ActivePageIndex == 2) workDS2->Locate("ID",id,lo);
  }
  delete EF;
  delete ed;
}
//---------------------------------------------------------------------------
//Редактирование записи
void __fastcall TMainForm::editItemClick(TObject *Sender)
{
TAddEditExpenseForm *EF;
AnsiString ID;
ExpensesData *ed;

if (workGrid->Focused()) ActivTable=1;
if (workGrid4->Focused()) ActivTable=2;
if (workGrid5->Focused()) ActivTable=3;
if (workGrid1->Focused()) ActivTable=4;
if (workGrid2->Focused()) ActivTable=5;

if(PC->ActivePageIndex == 0)
{
 if (workGrid->Focused())  ID=workGrid->DataSource->DataSet->FieldByName("ID")->AsString;
 if (workGrid4->Focused())  ID=workGrid4->DataSource->DataSet->FieldByName("ID")->AsString;
}
if(PC->ActivePageIndex == 1) ID=workGrid1->DataSource->DataSet->FieldByName("ID")->AsString;
if(PC->ActivePageIndex == 2) ID=workGrid2->DataSource->DataSet->FieldByName("ID")->AsString;

  try
  {
    ed=new ExpensesData();
  }
  catch (Exception &exc)
  {
    MessageDlg("Ошибка создания объекта ExpensesData\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
    return;
  }
  ed->FillData(ID);
  try
  {
    EF=new TAddEditExpenseForm(this,ed);
  }
  catch (Exception &exc)
  { MessageDlg("Ошибка создания формы AddEditExpenseForm\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
    return;
  }

  if(EF->ShowModal()==mrOk)
  { TpFIBQuery *Q=GSM_DM->WQ;
    AnsiString sql, s="";

    Q->Close();
    Q->SQL->Clear();
    sql="update EXPENSES_TABLE set";

    if(PC->ActivePageIndex == 0)
    {
    if (workGrid->Focused())
    {
    if(ed->getDriverID() != workDS->FieldByName("DRIVER_ID")->AsInteger)
    { if(!s.IsEmpty()) s+=",";
      s+=" DRIVER_ID="+IntToStr(ed->getDriverID());
    }
    if(ed->getGSMID() != workDS->FieldByName("GSM_ID")->AsInteger)
    { if(!s.IsEmpty()) s+=",";
      s+=" GSM_ID="+IntToStr(ed->getGSMID());
    }
    double exp=ed->getExpense();
    double newExp=workDS->FieldByName("EXPENSE")->AsFloat;
    if(exp != newExp)
    { if(!s.IsEmpty()) s+=",";
      s+=" EXPENSE="+FloatToStr(ed->getExpense());
    }
    int expkol=ed->getKol();
    int newExpkol=workDS->FieldByName("KOL")->AsInteger;
    if(expkol != newExpkol)
    { if(!s.IsEmpty()) s+=",";
      s+=" KOL="+IntToStr(ed->getKol());
    }

    int expd=ed->getD();
    int newExpd=workDS->FieldByName("D")->AsInteger;
    if(expd != newExpd)
    { if(!s.IsEmpty()) s+=",";
      s+=" D="+IntToStr(ed->getD());
    }

    if(int(ed->getExpDate()) != int(workDS->FieldByName("EXP_DATE")->AsDateTime))
    { if(!s.IsEmpty()) s+=",";
      s+=" EXP_DATE='"+ed->getExpDate().DateString()+"'";
    }
    }
    if (workGrid4->Focused())
    {
    if(ed->getDriverID() != workDS3->FieldByName("DRIVER_ID")->AsInteger)
    { if(!s.IsEmpty()) s+=",";
      s+=" DRIVER_ID="+IntToStr(ed->getDriverID());
    }
    if(ed->getGSMID() != workDS3->FieldByName("GSM_ID")->AsInteger)
    { if(!s.IsEmpty()) s+=",";
      s+=" GSM_ID="+IntToStr(ed->getGSMID());
    }
    double exp=ed->getExpense();
    double newExp=workDS3->FieldByName("EXPENSE")->AsFloat;
    if(exp != newExp)
    { if(!s.IsEmpty()) s+=",";
      s+=" EXPENSE="+FloatToStr(ed->getExpense());
    }
    int expkol=ed->getKol();
    int newExpkol=workDS3->FieldByName("KOL")->AsInteger;
    if(expkol != newExpkol)
    { if(!s.IsEmpty()) s+=",";
      s+=" KOL="+IntToStr(ed->getKol());
    }

    if(int(ed->getExpDate()) != int(workDS3->FieldByName("EXP_DATE")->AsDateTime))
    { if(!s.IsEmpty()) s+=",";
      s+=" EXP_DATE='"+ed->getExpDate().DateString()+"'";
    }
    }
    }

    if(PC->ActivePageIndex == 1)
    {
    if(ed->getDriverID() != workDS1->FieldByName("DRIVER_ID")->AsInteger)
    { if(!s.IsEmpty()) s+=",";
      s+=" DRIVER_ID="+IntToStr(ed->getDriverID());
    }
    if(ed->getGSMID() != workDS1->FieldByName("GSM_ID")->AsInteger)
    { if(!s.IsEmpty()) s+=",";
      s+=" GSM_ID="+IntToStr(ed->getGSMID());
    }
    double exp=ed->getExpense();
    double newExp=workDS1->FieldByName("EXPENSE")->AsFloat;
    if(exp != newExp)
    { if(!s.IsEmpty()) s+=",";
      s+=" EXPENSE="+FloatToStr(ed->getExpense());
    }
    int expkol=ed->getKol();
    int newExpkol=workDS1->FieldByName("KOL")->AsInteger;
    if(expkol != newExpkol)
    { if(!s.IsEmpty()) s+=",";
      s+=" KOL="+IntToStr(ed->getKol());
    }

    if(int(ed->getExpDate()) != int(workDS1->FieldByName("EXP_DATE")->AsDateTime))
    { if(!s.IsEmpty()) s+=",";
      s+=" EXP_DATE='"+ed->getExpDate().DateString()+"'";
    }
    }

    if(PC->ActivePageIndex == 2)
    {
    if(ed->getGSMID() != workDS2->FieldByName("GSM_ID")->AsInteger)
    { if(!s.IsEmpty()) s+=",";
      s+=" GSM_ID="+IntToStr(ed->getGSMID());
    }
    double exp=ed->getExpense();
    double newExp=workDS2->FieldByName("EXPENSE")->AsFloat;
    if(exp != newExp)
    { if(!s.IsEmpty()) s+=",";
      s+=" EXPENSE="+FloatToStr(ed->getExpense());
    }

    if(int(ed->getExpDate()) != int(workDS2->FieldByName("EXP_DATE")->AsDateTime))
    { if(!s.IsEmpty()) s+=",";
      s+=" EXP_DATE='"+ed->getExpDate().DateString()+"'";
    }

    }


    if(!s.IsEmpty())
    { sql+=s;
      sql+=" where ID="+ID;
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
      Q->Transaction->Commit();
      rashet(ed);
      newost(Date2);
      TLocateOptions lo; lo.Clear();
      LoadWorkDS(getSD_ID(),getID());
    if(PC->ActivePageIndex == 0){
    if(ActivTable == 1) workDS->Locate("ID",ID,lo);
    if(ActivTable == 2) workDS3->Locate("ID",ID,lo);
    if(ActivTable == 3) workDS4->Locate("ID",ID,lo);
    }
      if(PC->ActivePageIndex == 1) workDS1->Locate("ID",ID,lo);
      if(PC->ActivePageIndex == 2) workDS2->Locate("ID",ID,lo);
    }
  }
  delete EF;
  delete ed;
}
//---------------------------------------------------------------------------
//Удаление записи о расходе ГСМ
void __fastcall TMainForm::delItemClick(TObject *Sender)
{
AnsiString ID;
int rn;

if (workGrid->Focused()) ActivTable=1;
if (workGrid4->Focused()) ActivTable=2;
if (workGrid5->Focused()) ActivTable=3;
if (workGrid1->Focused()) ActivTable=4;
if (workGrid2->Focused()) ActivTable=5;

if(PC->ActivePageIndex == 0)
{
if (workGrid->Focused())  ID=workGrid->DataSource->DataSet->FieldByName("ID")->AsString;
if (workGrid4->Focused()) ID=workGrid4->DataSource->DataSet->FieldByName("ID")->AsString;
if (workGrid5->Focused()) ID=workGrid5->DataSource->DataSet->FieldByName("ID")->AsString;
}

if(PC->ActivePageIndex == 1) ID=workGrid1->DataSource->DataSet->FieldByName("ID")->AsString;
if(PC->ActivePageIndex == 2) ID=workGrid2->DataSource->DataSet->FieldByName("ID")->AsString;

  if(MessageDlg("Вы уверены, что хотите удалить текущую запись о операций?",mtConfirmation,TMsgDlgButtons() << mbOK << mbCancel,0)==mrOk)
  {
    TpFIBQuery *Q=GSM_DM->WQ;
    AnsiString sql;
    Q->Close();
    Q->SQL->Clear();
    sql="delete from EXPENSES_TABLE where ID="+ID;
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
    Q->Transaction->Commit();
    if(PC->ActivePageIndex == 0){
    if(ActivTable == 1) rn=workDS->RecNo;
    if(ActivTable == 2) rn=workDS3->RecNo;
    if(ActivTable == 3) rn=workDS4->RecNo;
    RashetWorkDS();
    }
    if(PC->ActivePageIndex == 1) rn=workDS1->RecNo;
    if(PC->ActivePageIndex == 2) rn=workDS2->RecNo;
    newost(Date2);
    LoadWorkDS(getSD_ID(),getID());
    if(PC->ActivePageIndex == 0){
    if(ActivTable == 1) workDS->RecNo=rn;
    if(ActivTable == 2) workDS3->RecNo=rn;
    if(ActivTable == 3) workDS4->RecNo=rn;
    }
    if(PC->ActivePageIndex == 1) workDS1->RecNo=rn;
    if(PC->ActivePageIndex == 2) workDS2->RecNo=rn;
  }
}
//---------------------------------------------------------------------------
//Справочник пользователей
void __fastcall TMainForm::N8Click(TObject *Sender)
{
TUsersForm *UF;

  try
  {
    UF=new TUsersForm(this);
  }
  catch (Exception &exc)
  { MessageDlg("Ошибка создания формы UsersForm\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
    return;
  }
  UF->ShowModal();
  delete UF;
}
//---------------------------------------------------------------------------
//Архивироание базы данных
void __fastcall TMainForm::N20Click(TObject *Sender)
{
TBackUpBaseForm *BBF;

  try
  {
    BBF=new TBackUpBaseForm(this);
  }
  catch (Exception &exc)
  { MessageDlg("Ошибка создания формы BackUpBaseForm\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
    return;
  }
  BBF->ShowModal();
  delete BBF;
}
//---------------------------------------------------------------------------
//Восстановление базы из архива
void __fastcall TMainForm::N21Click(TObject *Sender)
{
TRestoreBaseForm *RBF;

  try
  {
    RBF=new TRestoreBaseForm(this);
  }
  catch (Exception &exc)
  { MessageDlg("Ошибка создания формы RestoreBaseForm\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
    return;
  }
  RBF->ShowModal();
  delete RBF;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::workGridSortMarkingChanged(TObject *Sender)
{
  AnsiString fn;
  fn=workGrid->SortMarkedColumns->Items[0]->FieldName;

  if(fn=="ID")
  { if(workGrid->SortMarkedColumns->Items[0]->Title->SortMarker==smDownEh) sortString=" order by e.ID descending";
    else  sortString=" order by e.ID";
  }
  else if(fn=="EXP_DATE")
  { if(workGrid->SortMarkedColumns->Items[0]->Title->SortMarker==smDownEh) sortString=" order by e.EXP_DATE descending, e.ID";
    else sortString=" order by e.EXP_DATE, e.ID";
  }
  else if(fn=="WAYBILL_NUMBER")
  { if(workGrid->SortMarkedColumns->Items[0]->Title->SortMarker==smDownEh) sortString=" order by WAYBILL_NUMBER descending";
    else sortString=" order by WAYBILL_NUMBER";
  }
  else if(fn=="ELECTRONIC_CARD")
  { if(workGrid->SortMarkedColumns->Items[0]->Title->SortMarker==smDownEh) sortString=" order by ec.DESCRIPTION descending";
    else sortString=" order by ec.DESCRIPTION";
  }
  else if(fn=="AUTO")
  { if(workGrid->SortMarkedColumns->Items[0]->Title->SortMarker==smDownEh) sortString=" order by a.DESCRIPTION descending, EXP_DATE";
    else sortString=" order by a.DESCRIPTION, EXP_DATE";
  }
  else if(fn=="DRIVER")
  { if(workGrid->SortMarkedColumns->Items[0]->Title->SortMarker==smDownEh) sortString=" order by d.DESCRIPTION descending, EXP_DATE";
    else sortString=" order by d.DESCRIPTION, EXP_DATE";
  }
  else if(fn=="GSM")
  { if(workGrid->SortMarkedColumns->Items[0]->Title->SortMarker==smDownEh) sortString=" order by m.DESCRIPTION descending, EXP_DATE";
    else sortString=" order by m.DESCRIPTION, EXP_DATE";
  }
  else if(fn=="EXPENSE")
  { if(workGrid->SortMarkedColumns->Items[0]->Title->SortMarker==smDownEh) sortString=" order by EXPENSE descending, EXP_DATE";
    else sortString=" order by EXPENSE, EXP_DATE";
  }
  else if(fn=="KOL")
  { if(workGrid->SortMarkedColumns->Items[0]->Title->SortMarker==smDownEh) sortString=" order by KOL descending, EXP_DATE";
    else sortString=" order by EXPENSE, EXP_DATE";
  }
  int id=workDS->FieldByName("ID")->AsInteger;
  LoadWorkDS(getSD_ID(),getID());
  TLocateOptions lo; lo.Clear();
  workDS->Locate("ID", id, lo);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::N25Click(TObject *Sender)
{
AnsiString sql,fo;

// здесь необходимо формировать отчет Excel

//fo=createVedVyplFile(Date1Edit->Date,Date2Edit->Date);
sql="";


}
//---------------------------------------------------------------------------
void __fastcall TMainForm::SelectButtonClick(TObject *Sender)
{
TConditionsChoiceForm *CCF;

  try
  {
    CCF=new TConditionsChoiceForm(this);
  }
  catch (Exception &exc)
  { MessageDlg("Ошибка создания формы ConditionsChoiceForm\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
    return;
  }
  if(CCF->ShowModal()==mrOk)
  { selectString="";
    selectString1="";
    if(CCF->driverBox->Checked) selectString+=" and e.DRIVER_ID="+IntToStr(CCF->getDriverID());
    if(CCF->gsmBox->Checked)
    {
     selectString+=" and e.GSM_ID="+IntToStr(CCF->getGSMID());
     selectString1+=" and e.GSM_ID="+IntToStr(CCF->getGSMID());
    }
    if(!selectString.IsEmpty()) selectString+=" ";
    if(!selectString1.IsEmpty()) selectString1+=" ";

    int id=workDS->FieldByName("ID")->AsInteger;
    LoadWorkDS(getSD_ID(),getID());
    TLocateOptions lo; lo.Clear();
    workDS->Locate("ID", id, lo);
  }
  delete CCF;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::UnSelectButtonClick(TObject *Sender)
{
int id=workDS->FieldByName("ID")->AsInteger;

  selectString="";
  selectString1="";
  LoadWorkDS(getSD_ID(),getID());
  TLocateOptions lo; lo.Clear();
  workDS->Locate("ID", id, lo);
}
//---------------------------------------------------------------------------
//Формирование модели поиска
void __fastcall TMainForm::workGridKeyPress(TObject *Sender, char &Key)
{
  if(workGrid->Col!=3 && workGrid->Col!=4  && workGrid->Col!=5  && workGrid->Col!=6) return;
  int c=Key&127;
  if(isalnum(c) || c==64)
  { SEdit->Clear();
    AnsiString s=SEdit->Text+Key;
    Key=0;
    SEdit->Text=s;
    SEdit->SetFocus(); SEdit->SelStart=SEdit->GetTextLen();
  }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::SEditKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
  if(Key==VK_RETURN || Key==VK_DOWN || Key==VK_UP){ Key=0; workGrid->SetFocus(); }
  else if(Key == VK_ESCAPE){ Key=0; SEdit->Text=""; }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::SEditChange(TObject *Sender)
{
  if(STimer->Enabled==true) STimer->Enabled=false;
  STimer->Enabled=true;
}
//---------------------------------------------------------------------------
//Отбор по модели
void __fastcall TMainForm::STimerTimer(TObject *Sender)
{
AnsiString sql;

  STimer->Enabled=false;
  if(SEdit->Text.IsEmpty()) return;
  S_DS->Close();
  S_DS->SQLs->SelectSQL->Clear();
  sql="select e.ID from EXPENSES_TABLE e";
//  if(workGrid->Col==4) sql+=" left outer join AUTO_TABLE a on a.ID=e.AUTO_ID";
//  else if(workGrid->Col==5) sql+=" left outer join OPS_TABLE d on d.ID=e.DRIVER_ID";
  sql+=" left outer join OPS_TABLE d on d.ID=e.DRIVER_ID";
  sql+=" left outer join OPER_TABLE m on m.ID=e.GSM_ID";
  sql+=" where e.EXP_DATE>='"+Date1.DateString()+"'";
  sql+=" and e.EXP_DATE<='"+Date2.DateString()+"'";
  if(workGrid->Col==3) sql+=" and UPPER(e.WAYBILL_NUMBER) like '%"+SEdit->Text.UpperCase()+"%'";
  else if(workGrid->Col==4) sql+=" and UPPER(ec.DESCRIPTION) like '%"+SEdit->Text.UpperCase()+"%'";
  else if(workGrid->Col==5) sql+=" and UPPER(a.DESCRIPTION) like '%"+SEdit->Text.UpperCase()+"%'";
  else if(workGrid->Col==6) sql+=" and UPPER(d.DESCRIPTION) like '%"+SEdit->Text.UpperCase()+"%'";
  sql+=sortString;
  S_DS->SQLs->SelectSQL->Add(sql);
  try
  {
    S_DS->Open();
  }
  catch(const Exception &exc)
  {
    MessageDlg("Ошибка - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
    return;
  }
  S_DS->Last();
  S_DS->First();
  if(S_DS->RecordCount > 0)
  { TLocateOptions Opt; Opt.Clear();
    workDS->Locate("ID",Variant(S_DS->FieldByName("ID")->AsString),Opt);
    workGrid->SetFocus();
  }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::FSButtonClick(TObject *Sender)
{
TLocateOptions Opt; Opt.Clear();

  if(S_DS->RecNo < S_DS->RecordCount) S_DS->Next();
  else S_DS->First();
  workDS->Locate("ID",Variant(S_DS->FieldByName("ID")->AsString),Opt);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::BSButtonClick(TObject *Sender)
{
TLocateOptions Opt; Opt.Clear();

  if(S_DS->RecNo > 1) S_DS->Prior();
  else S_DS->Last();
  workDS->Locate("ID",Variant(S_DS->FieldByName("ID")->AsString),Opt);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::S_DSAfterClose(TDataSet *DataSet)
{
  FSButton->Enabled=false;
  BSButton->Enabled=false;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::S_DSAfterOpen(TDataSet *DataSet)
{
  FSButton->Enabled=true;
  BSButton->Enabled=true;
}
//---------------------------------------------------------------------------
//Загрузка данных из файла
//По всем подразделения
void __fastcall TMainForm::action0Execute(TObject *Sender)
{
  if(PC->ActivePageIndex == 0){
  selectSDBar->Items->Items[selectedSD]->Checked=false;
  selectedSD=0;
  if(Showing) LoadWorkDS(getSD_ID(),getID());
  selectSDBar->Items->Items[selectedSD]->Checked=true;
  setMainHeader();
  }
  else
  {
  selectSDBar1->Items->Items[selectedSD1]->Checked=false;
  selectedSD1=0;
  if(Showing) LoadWorkDS(getSD_ID(),getID());
  selectSDBar1->Items->Items[selectedSD1]->Checked=true;
  setMainHeader();
  }
  selectSDBarClick(this);
}
//---------------------------------------------------------------------------
//Автобаза УФПС
void __fastcall TMainForm::action1Execute(TObject *Sender)
{
  if(PC->ActivePageIndex == 0){
  selectSDBar->Items->Items[selectedSD]->Checked=false;
  selectedSD=1;
  if(Showing){
  AnsiString e=getSD_ID();
  LoadWorkDS(getSD_ID(),getID());
  }
  selectSDBar->Items->Items[selectedSD]->Checked=true;
  setMainHeader();
  selectSDBarClick(this);
  }else
  {
  selectSDBar1->Items->Items[selectedSD1]->Checked=false;
  selectedSD1=1;
  if(Showing) LoadWorkDS(getSD_ID(),getID());
  selectSDBar1->Items->Items[selectedSD1]->Checked=true;
  setMainHeader();
  selectSDBarClick(this);
  }
}
//---------------------------------------------------------------------------
//
void __fastcall TMainForm::action2Execute(TObject *Sender)
{
  if(PC->ActivePageIndex == 0){
  selectSDBar->Items->Items[selectedSD]->Checked=false;
  selectedSD=2;
  if(Showing) LoadWorkDS(getSD_ID(),getID());
  selectSDBar->Items->Items[selectedSD]->Checked=true;
  setMainHeader();
  selectSDBarClick(this);
  }else
  {
  selectSDBar1->Items->Items[selectedSD1]->Checked=false;
  selectedSD1=2;
  if(Showing) LoadWorkDS(getSD_ID(),getID());
  selectSDBar1->Items->Items[selectedSD1]->Checked=true;
  setMainHeader();
  selectSDBarClick(this);
  }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::action3Execute(TObject *Sender)
{
  if(PC->ActivePageIndex == 0){
  selectSDBar->Items->Items[selectedSD]->Checked=false;
  selectedSD=3;
  if(Showing) LoadWorkDS(getSD_ID(),getID());
  selectSDBar->Items->Items[selectedSD]->Checked=true;
  setMainHeader();
  selectSDBarClick(this);
  }else
  {
  selectSDBar1->Items->Items[selectedSD1]->Checked=false;
  selectedSD1=3;
  if(Showing) LoadWorkDS(getSD_ID(),getID());
  selectSDBar1->Items->Items[selectedSD1]->Checked=true;
  setMainHeader();
  selectSDBarClick(this);
  }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::action4Execute(TObject *Sender)
{
  if(PC->ActivePageIndex == 0){
  selectSDBar->Items->Items[selectedSD]->Checked=false;
  selectedSD=4;
  if(Showing) LoadWorkDS(getSD_ID(),getID());
  selectSDBar->Items->Items[selectedSD]->Checked=true;
  setMainHeader();
  selectSDBarClick(this);
  }else
  {
  selectSDBar1->Items->Items[selectedSD1]->Checked=false;
  selectedSD1=4;
  if(Showing) LoadWorkDS(getSD_ID(),getID());
  selectSDBar1->Items->Items[selectedSD1]->Checked=true;
  setMainHeader();
  selectSDBarClick(this);
  }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::action5Execute(TObject *Sender)
{
  if(PC->ActivePageIndex == 0){
  selectSDBar->Items->Items[selectedSD]->Checked=false;
  selectedSD=5;
  if(Showing) LoadWorkDS(getSD_ID(),getID());
  selectSDBar->Items->Items[selectedSD]->Checked=true;
  setMainHeader();
  selectSDBarClick(this);
  }else
  {
  selectSDBar1->Items->Items[selectedSD1]->Checked=false;
  selectedSD1=5;
  if(Showing) LoadWorkDS(getSD_ID(),getID());
  selectSDBar1->Items->Items[selectedSD1]->Checked=true;
  setMainHeader();
  selectSDBarClick(this);
  }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::action6Execute(TObject *Sender)
{
  if(PC->ActivePageIndex == 0){
  selectSDBar->Items->Items[selectedSD]->Checked=false;
  selectedSD=6;
  if(Showing) LoadWorkDS(getSD_ID(),getID());
  selectSDBar->Items->Items[selectedSD]->Checked=true;
  setMainHeader();
  selectSDBarClick(this);
  }else
  {
  selectSDBar1->Items->Items[selectedSD1]->Checked=false;
  selectedSD1=6;
  if(Showing) LoadWorkDS(getSD_ID(),getID());
  selectSDBar1->Items->Items[selectedSD1]->Checked=true;
  setMainHeader();
  selectSDBarClick(this);
  }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::action7Execute(TObject *Sender)
{
  if(PC->ActivePageIndex == 0){
  selectSDBar->Items->Items[selectedSD]->Checked=false;
  selectedSD=7;
  if(Showing) LoadWorkDS(getSD_ID(),getID());
  selectSDBar->Items->Items[selectedSD]->Checked=true;
  setMainHeader();
  selectSDBarClick(this);
  }else
  {
  selectSDBar1->Items->Items[selectedSD1]->Checked=false;
  selectedSD1=7;
  if(Showing) LoadWorkDS(getSD_ID(),getID());
  selectSDBar1->Items->Items[selectedSD1]->Checked=true;
  setMainHeader();
  selectSDBarClick(this);
  }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::action8Execute(TObject *Sender)
{
  if(PC->ActivePageIndex == 0){
  selectSDBar->Items->Items[selectedSD]->Checked=false;
  selectedSD=8;
  if(Showing) LoadWorkDS(getSD_ID(),getID());
  selectSDBar->Items->Items[selectedSD]->Checked=true;
  setMainHeader();
  selectSDBarClick(this);
  }else
  {
  selectSDBar1->Items->Items[selectedSD1]->Checked=false;
  selectedSD1=8;
  if(Showing) LoadWorkDS(getSD_ID(),getID());
  selectSDBar1->Items->Items[selectedSD1]->Checked=true;
  setMainHeader();
  selectSDBarClick(this);
  }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::action9Execute(TObject *Sender)
{
  if(PC->ActivePageIndex == 0){
  selectSDBar->Items->Items[selectedSD]->Checked=false;
  selectedSD=9;
  if(Showing) LoadWorkDS(getSD_ID(),getID());
  selectSDBar->Items->Items[selectedSD]->Checked=true;
  setMainHeader();
  selectSDBarClick(this);
  }else
  {
  selectSDBar1->Items->Items[selectedSD1]->Checked=false;
  selectedSD1=9;
  if(Showing) LoadWorkDS(getSD_ID(),getID());
  selectSDBar1->Items->Items[selectedSD1]->Checked=true;
  setMainHeader();
  selectSDBarClick(this);
  }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::action10Execute(TObject *Sender)
{
  if(PC->ActivePageIndex == 0){
  selectSDBar->Items->Items[selectedSD]->Checked=false;
  selectedSD=10;
  if(Showing) LoadWorkDS(getSD_ID(),getID());
  selectSDBar->Items->Items[selectedSD]->Checked=true;
  setMainHeader();
  selectSDBarClick(this);
  }else
  {
  selectSDBar1->Items->Items[selectedSD1]->Checked=false;
  selectedSD1=10;
  if(Showing) LoadWorkDS(getSD_ID(),getID());
  selectSDBar1->Items->Items[selectedSD1]->Checked=true;
  setMainHeader();
  selectSDBarClick(this);
  }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::action11Execute(TObject *Sender)
{
  if(PC->ActivePageIndex == 0){
  selectSDBar->Items->Items[selectedSD]->Checked=false;
  selectedSD=11;
  if(Showing) LoadWorkDS(getSD_ID(),getID());
  selectSDBar->Items->Items[selectedSD]->Checked=true;
  setMainHeader();
  selectSDBarClick(this);
  }else
  {
  selectSDBar1->Items->Items[selectedSD1]->Checked=false;
  selectedSD1=11;
  if(Showing) LoadWorkDS(getSD_ID(),getID());
  selectSDBar1->Items->Items[selectedSD1]->Checked=true;
  setMainHeader();
  selectSDBarClick(this);
  }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::action12Execute(TObject *Sender)
{
  if(PC->ActivePageIndex == 0){
  selectSDBar->Items->Items[selectedSD]->Checked=false;
  selectedSD=12;
  if(Showing) LoadWorkDS(getSD_ID(),getID());
  selectSDBar->Items->Items[selectedSD]->Checked=true;
  setMainHeader();
  selectSDBarClick(this);
  }else
  {
  selectSDBar1->Items->Items[selectedSD1]->Checked=false;
  selectedSD1=12;
  if(Showing) LoadWorkDS(getSD_ID(),getID());
  selectSDBar1->Items->Items[selectedSD1]->Checked=true;
  setMainHeader();
  selectSDBarClick(this);
  }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::action13Execute(TObject *Sender)
{
  if(PC->ActivePageIndex == 0){
  selectSDBar->Items->Items[selectedSD]->Checked=false;
  selectedSD=13;
  if(Showing) LoadWorkDS(getSD_ID(),getID());
  selectSDBar->Items->Items[selectedSD]->Checked=true;
  setMainHeader();
  selectSDBarClick(this);
  }else
  {
  selectSDBar1->Items->Items[selectedSD1]->Checked=false;
  selectedSD1=13;
  if(Showing) LoadWorkDS(getSD_ID(),getID());
  selectSDBar1->Items->Items[selectedSD1]->Checked=true;
  setMainHeader();
  selectSDBarClick(this);
  }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::action14Execute(TObject *Sender)
{
  if(PC->ActivePageIndex == 0){
  selectSDBar->Items->Items[selectedSD]->Checked=false;
  selectedSD=14;
  if(Showing) LoadWorkDS(getSD_ID(),getID());
  selectSDBar->Items->Items[selectedSD]->Checked=true;
  setMainHeader();
  selectSDBarClick(this);
  }else
  {
  selectSDBar1->Items->Items[selectedSD1]->Checked=false;
  selectedSD1=14;
  if(Showing) LoadWorkDS(getSD_ID(),getID());
  selectSDBar1->Items->Items[selectedSD1]->Checked=true;
  setMainHeader();
  selectSDBarClick(this);
  }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::action15Execute(TObject *Sender)
{
  if(PC->ActivePageIndex == 0){
  selectSDBar->Items->Items[selectedSD]->Checked=false;
  selectedSD=15;
  if(Showing) LoadWorkDS(getSD_ID(),getID());
  selectSDBar->Items->Items[selectedSD]->Checked=true;
  setMainHeader();
  selectSDBarClick(this);
  }else
  {
  selectSDBar1->Items->Items[selectedSD1]->Checked=false;
  selectedSD1=15;
  if(Showing) LoadWorkDS(getSD_ID(),getID());
  selectSDBar1->Items->Items[selectedSD1]->Checked=true;
  setMainHeader();
  selectSDBarClick(this);
  }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::action16Execute(TObject *Sender)
{
  if(PC->ActivePageIndex == 0){
  selectSDBar->Items->Items[selectedSD]->Checked=false;
  selectedSD=16;
  if(Showing) LoadWorkDS(getSD_ID(),getID());
  selectSDBar->Items->Items[selectedSD]->Checked=true;
  setMainHeader();
  selectSDBarClick(this);
  }else
  {
  selectSDBar1->Items->Items[selectedSD1]->Checked=false;
  selectedSD1=16;
  if(Showing) LoadWorkDS(getSD_ID(),getID());
  selectSDBar1->Items->Items[selectedSD1]->Checked=true;
  setMainHeader();
  selectSDBarClick(this);
  }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::workGridPMPopup(TObject *Sender)
{
int index = autoNumberEdit->ItemIndex;
AnsiString OPS=autoID->Strings[index];
int index1 = autoNumberEdit1->ItemIndex;
AnsiString OPS1=autoID1->Strings[index1];

if (workGrid->Focused())
{
 if (OPS.Trim()!="0" && selectedSD >0)
 {

   if (workDS->FieldByName("EDITABLE")->AsInteger==1 && Date1 == Date2)
   {

   if (GSM_DM->UserRole!="администратор")
   {
   DeleteButton->Enabled = true;
   EditButton->Enabled = true;
   delItem->Visible = true;
   editItem->Visible = true;
   }else
   {
   DeleteButton->Enabled = false;
   EditButton->Enabled = false;
   delItem->Visible = false;
   editItem->Visible = false;
   }

   }
   else
   {
    if(Date1 >= Date() && Date2 >= Date())
    {
     if (GSM_DM->UserRole!="администратор")
     {
     AddButton->Enabled = true;
     addItem->Visible = true;
     }else
     {
     AddButton->Enabled = false;
     addItem->Visible = false;
     }
    }else
    {
    AddButton->Enabled = false;
    addItem->Visible = false;
    }
   }
   if (workDS->FieldByName("EDITABLE")->AsInteger==1)
   {
    if (workDS->RecordCount > 0) {
     if (GSM_DM->UserRole!="администратор"){
    DeleteButton->Enabled = true;
    EditButton->Enabled = true;
    delItem->Visible = true;
    editItem->Visible = true;
    AddButton->Enabled = true;
    addItem->Visible = true;
    }}
   }
   else
   {
    DeleteButton->Enabled = false;
    EditButton->Enabled = false;
    delItem->Visible = false;
    editItem->Visible = false;
   }
 }
 else
 {
 AddButton->Enabled =false;
 DeleteButton->Enabled=false;
 EditButton->Enabled = false;
 editItem->Visible = false;
 addItem->Visible = false;
 delItem->Visible = false;
 }
}

if (workGrid4->Focused())
{
 if (OPS.Trim()!="0" && selectedSD >0)
 {
   if (workDS3->FieldByName("EDITABLE")->AsInteger==1 && Date1 == Date2)
   {
   if (GSM_DM->UserRole!="администратор")
   {
   DeleteButton->Enabled = true;
   EditButton->Enabled = true;
   delItem->Visible = true;
   editItem->Visible = true;
   }else
   {
   DeleteButton->Enabled = false;
   EditButton->Enabled = false;
   delItem->Visible = false;
   editItem->Visible = false;
   }
   }
   else
   {
    if(Date1 >= Date() && Date2 >= Date())
    {
   if (GSM_DM->UserRole!="администратор")
   {
   AddButton->Enabled = true;
   addItem->Visible = true;
   }else
   {
   AddButton->Enabled = false;
   addItem->Visible = false;
   }
    }else
    {
    AddButton->Enabled = false;
    addItem->Visible = false;
    }
   }
   if (workDS3->FieldByName("EDITABLE")->AsInteger==1)
   {
    if (workDS3->RecordCount > 0) {
    if (GSM_DM->UserRole!="администратор"){
    DeleteButton->Enabled = true;
    EditButton->Enabled = true;
    delItem->Visible = true;
    editItem->Visible = true;
    AddButton->Enabled = true;
    addItem->Visible = true;
    }}
   }
   else
   {
    DeleteButton->Enabled = false;
    EditButton->Enabled = false;
    delItem->Visible = false;
    editItem->Visible = false;
   }
 }
 else
 {
 AddButton->Enabled =false;
 DeleteButton->Enabled=false;
 EditButton->Enabled = false;
 editItem->Visible = false;
 addItem->Visible = false;
 delItem->Visible = false;
 }
}


if (workGrid1->Focused())
{
 if (OPS1.Trim()!="0" &&  AnsiPos(GSM_DM->Index,OPS1.Trim())>0 && selectedSD1 >0)
 {

   if (workDS1->FieldByName("EDITABLE")->AsInteger==1 && Date1 == Date2)
   {
   if (GSM_DM->UserRole!="администратор")
   {
   DeleteButton->Enabled = true;
   EditButton->Enabled = true;
   delItem->Visible = true;
   editItem->Visible = true;
   }else
   {
   DeleteButton->Enabled = false;
   EditButton->Enabled = false;
   delItem->Visible = false;
   editItem->Visible = false;
   }
   }
   else
   {
    if(Date1 == Date() && Date2 == Date())
    {
   if (GSM_DM->UserRole!="администратор")
   {
   AddButton->Enabled = true;
   addItem->Visible = true;
   }else
   {
   AddButton->Enabled = false;
   addItem->Visible = false;
   }
    }else
    {
    AddButton->Enabled = false;
    addItem->Visible = false;
    }
   }
   if (workDS1->FieldByName("EDITABLE")->AsInteger==1)
   {
    if (workDS1->RecordCount > 0) {
   if (GSM_DM->UserRole!="администратор"){
    DeleteButton->Enabled = true;
    EditButton->Enabled = true;
    delItem->Visible = true;
    editItem->Visible = true;}}
   }
   else
   {
    DeleteButton->Enabled = false;
    EditButton->Enabled = false;
    delItem->Visible = false;
    editItem->Visible = false;
   }
 }
 else
 {
 AddButton->Enabled =false;
 DeleteButton->Enabled=false;
 EditButton->Enabled = false;
 editItem->Visible = false;
 addItem->Visible = false;
 delItem->Visible = false;
 }
}

if (workGrid2->Focused())
{
   if (workDS2->FieldByName("EDITABLE")->AsInteger==1 && Date1 == Date2)
   {
   if (GSM_DM->UserRole!="администратор")
   {
   DeleteButton->Enabled = true;
   EditButton->Enabled = true;
   delItem->Visible = true;
   editItem->Visible = true;
   }else
   {
   DeleteButton->Enabled = false;
   EditButton->Enabled = false;
   delItem->Visible = false;
   editItem->Visible = false;
   }
   }
   else
   {
    if(Date1 == Date() && Date2 == Date())
    {
   if (GSM_DM->UserRole!="администратор")
   {
   AddButton->Enabled = true;
   addItem->Visible = true;
   }else
   {
   AddButton->Enabled = false;
   addItem->Visible = false;
   }
    }else
    {
    AddButton->Enabled = false;
    addItem->Visible = false;
    }
   }
   if (workDS2->FieldByName("EDITABLE")->AsInteger==1)
   {
    if (workDS2->RecordCount > 0) {
   if (GSM_DM->UserRole!="администратор"){
    DeleteButton->Enabled = true;
    EditButton->Enabled = true;
    delItem->Visible = true;
    editItem->Visible = true;
    AddButton->Enabled = true;
    addItem->Visible = true;
    }}
   }
   else
   {
    DeleteButton->Enabled = false;
    EditButton->Enabled = false;
    delItem->Visible = false;
    editItem->Visible = false;
    AddButton->Enabled = true;
    addItem->Visible = true;
   }
}

if (workGrid5->Focused())
{
 AddButton->Enabled =false;
 DeleteButton->Enabled=false;
 EditButton->Enabled = false;
 editItem->Visible = false;
 addItem->Visible = false;
 delItem->Visible = false;
}

}

//---------------------------------------------------------------------------
//Обновить данные
void __fastcall TMainForm::reloadButtonClick(TObject *Sender)
{
// здесь импорт данных из Инспектор по дате!!!

AnsiString ID;
int rn;
AnsiString sql;
TpFIBQuery *Q_INS=RQ_INS;
TpFIBQuery *Q=GSM_DM->WQ;
TpFIBQuery *Q_LOC=GSM_DM->RQ;
int idpost,idops,idopsp;
int indops,iduser;
AnsiString indexops,nameops,result;
unsigned short y,m,d;
double sexp1,sexp2,sexp3;
int kol1,kol2,kol3;
TDateTime dexp;
int idexp=0;
int metka1=0;
int pos1,pos2;
int kolzap = 0;

kol1=0;
kol2=0;
kol3=0;
indexops="";
result="";

if(Date1 == Date2)
{
dexp=Date1;
dexp.DecodeDate(&y,&m,&d);
}else
{
MessageDlg("Импорт данных из ИС Инспектор можно делать только за один день!!! Установите пожалуйста правильно период данных!!!",mtWarning,TMsgDlgButtons() << mbOK,0);
return;
}

if (workGrid->Focused()) ActivTable=1;
if (workGrid4->Focused()) ActivTable=2;
if (workGrid5->Focused()) ActivTable=3;
if (workGrid1->Focused()) ActivTable=4;
if (workGrid2->Focused()) ActivTable=5;

if(PC->ActivePageIndex == 0)
{
if (workGrid->Focused())  ID=workGrid->DataSource->DataSet->FieldByName("ID")->AsString;
if (workGrid4->Focused()) ID=workGrid4->DataSource->DataSet->FieldByName("ID")->AsString;
if (workGrid5->Focused()) ID=workGrid5->DataSource->DataSet->FieldByName("ID")->AsString;
}

if(PC->ActivePageIndex == 1) ID=workGrid1->DataSource->DataSet->FieldByName("ID")->AsString;
if(PC->ActivePageIndex == 2) ID=workGrid2->DataSource->DataSet->FieldByName("ID")->AsString;

if (workGrid->Focused())
{
if(MessageDlg("Вы уверены, что хотите получить данные из ИС ИНСПЕКТОР за  " + AnsiString().sprintf("%02d-%02d-%d",d,m,y) + " ? \n ВНИМАНИЕ!!! При импорте старые записи безвозвратно удалятся!!!", mtConfirmation,TMsgDlgButtons() << mbOK << mbCancel,0)==mrOk)
{

kol1=0;
sexp1=0.00;
kol2=0;
sexp2=0.00;
kol3=0;
sexp3=0.00;
metka1=0;

  Q_LOC->Close();
  Q_LOC->SQL->Clear();
  sql="select e.* from USERS_TABLE e";
  sql+=" where e.U_LOGIN='"+GSM_DM->UserLogin+"'";
  Q_LOC->SQL->Add(sql);
  try
  {
    Q_LOC->ExecQuery();
  }
  catch (Exception &exc)
  {
    MessageDlg("Ошибка - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
    return;
  }
  iduser=Q_LOC->FieldByName("IDINS")->AsInteger;
  Q_LOC->Close();

  sql="select SUM(s.SUMMA) as sumexp , s.metka1 , s.fakt_chel from ACCOUNTS a left outer join SGB s on a.ORG_ID=s.ORG_ID";
  sql+=" and a.COUNT_DATE=s.COUNT_DATE and a.COUNT_NUMBER=s.COUNT_NUMBER";
  sql+=" where a.USER_ID="+IntToStr(iduser);
  sql+=" and s.FAKT_DAT="+IntToStr(d);
  sql+=" and a.M="+IntToStr(m);
  sql+=" and a.Y="+IntToStr(y);
  sql+=" group by s.metka1 , s.fakt_chel";
  usersINS->SQLs->SelectSQL->Clear();
  usersINS->SQLs->SelectSQL->Add(sql);

  try
  {
    usersINS->Open();
  }
  catch (Exception &exc)
  {
    MessageDlg("Ошибка открытия таблицы сумм ACCOUNTS из ИС ИНСПЕКТОР\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
    return;
  }
  usersINS->Last();
//  int kolzap=usersINS->RecordCount;
  usersINS->First();
  while(!usersINS->Eof)
  {

  metka1=usersINS->FieldByName("METKA1")->AsInteger;

  // определить код кассы из справочника касс

  Q_LOC->Close();
  Q_LOC->SQL->Clear();
  sql="select e.* from OPS_TABLE e";
  sql+=" where e.IDINS="+IntToStr(usersINS->FieldByName("FAKT_CHEL")->AsInteger);
  sql+=" and e.FILE_ID=1 and e.REC_TYPE=0";
  Q_LOC->SQL->Add(sql);
  try
  {
    Q_LOC->ExecQuery();
  }
  catch (Exception &exc)
  {
    MessageDlg("Ошибка - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
    return;
  }
  idopsp=Q_LOC->FieldByName("ID")->AsInteger;
  idpost=Q_LOC->FieldByName("IDINS")->AsInteger;
  nameops=Q_LOC->FieldByName("DESCRIPTION")->AsString;
  Q_LOC->Close();

  AnsiString kodidpost=IntToStr(metka1);
  AnsiString indexopsfull="";
  if (kodidpost.Length()==1) indexopsfull="63000"+kodidpost.Trim();
  if (kodidpost.Length()==2) indexopsfull="6300"+kodidpost.Trim();
  if (kodidpost.Length()==3) indexopsfull="630"+kodidpost.Trim();
  pos1=MainForm->IndexOps.Pos("жел");
  pos2=MainForm->IndexOps.Pos("центр");
  if (pos1>0)
  {
     indexopsfull=indexopsfull + " жел ";
  }
  if (pos2>0)
  {
     indexopsfull=indexopsfull + " центр ";
  }

  Q_LOC->Close();
  Q_LOC->SQL->Clear();
  sql="select e.* from OPS_TABLE e";
  sql+=" where e.DESCRIPTION STARTING WITH '"+indexopsfull.Trim()+"'";
  sql+=" and e.FILE_ID="+IntToStr(idopsp);
  Q_LOC->SQL->Add(sql);
  try
  {
    Q_LOC->ExecQuery();
  }
  catch (Exception &exc)
  {
    MessageDlg("Ошибка - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
    return;
  }
  idops=Q_LOC->FieldByName("ID")->AsInteger;
  indexops=Q_LOC->FieldByName("DESCRIPTION")->AsString;
  Q_LOC->Close();


  // определить выплаты всего общее and LCHET1 NOT IN ('Прошврем','раздел 1')

  Q_INS->Close();
  Q_INS->SQL->Clear();
  sql="select COUNT(s.LCHET) as kol , s.metka1 , s.fakt_chel from ACCOUNTS a left outer join SGB s on a.ORG_ID=s.ORG_ID";
  sql+=" and a.COUNT_DATE=s.COUNT_DATE and a.COUNT_NUMBER=s.COUNT_NUMBER";
  sql+=" where a.USER_ID="+IntToStr(iduser);
  sql+=" and s.FAKT_CHEL="+IntToStr(idpost);
  sql+=" and s.METKA1="+IntToStr(metka1);
  sql+=" and s.FAKT_DAT="+IntToStr(d);
  sql+=" and s.LCHET1 NOT IN ('Прошврем','раздел 1')";
  sql+=" and a.M="+IntToStr(m);
  sql+=" and a.Y="+IntToStr(y);
  sql+=" group by s.metka1 , s.fakt_chel";
  Q_INS->SQL->Add(sql);
  try
  {
    Q_INS->ExecQuery();
  }
  catch (Exception &exc)
  {
    MessageDlg("Ошибка - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
    return;
  }
  kol1=Q_INS->FieldByName("KOL")->AsInteger;

  Q_INS->Close();
  Q_INS->SQL->Clear();
  sql="select SUM(s.SUMMA) as sumexp, COUNT(s.LCHET) as kol , s.metka1 , s.fakt_chel from ACCOUNTS a left outer join SGB s on a.ORG_ID=s.ORG_ID";
  sql+=" and a.COUNT_DATE=s.COUNT_DATE and a.COUNT_NUMBER=s.COUNT_NUMBER";
  sql+=" where a.USER_ID="+IntToStr(iduser);
  sql+=" and s.METKA1="+IntToStr(metka1);
  sql+=" and s.FAKT_CHEL="+IntToStr(idpost);
  sql+=" and s.FAKT_DAT="+IntToStr(d);
  sql+=" and a.M="+IntToStr(m);
  sql+=" and a.Y="+IntToStr(y);
  sql+=" group by s.metka1 , s.fakt_chel";
  Q_INS->SQL->Add(sql);
  try
  {
    Q_INS->ExecQuery();
  }
  catch (Exception &exc)
  {
    MessageDlg("Ошибка - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
    return;
  }
  sexp1=Q_INS->FieldByName("SUMEXP")->AsFloat;



  // определить выплаты всего выплачено
  Q_INS->Close();
  Q_INS->SQL->Clear();
  sql="select SUM(s.SUMMA) as sumexp, COUNT(s.LCHET) as kol , s.metka1 , s.fakt_chel from ACCOUNTS a left outer join SGB s on a.ORG_ID=s.ORG_ID";
  sql+=" and a.COUNT_DATE=s.COUNT_DATE and a.COUNT_NUMBER=s.COUNT_NUMBER";
  sql+=" where a.USER_ID="+IntToStr(iduser);
  sql+=" and s.METKA1="+IntToStr(metka1);
  sql+=" and s.FAKT_CHEL="+IntToStr(idpost);
  sql+=" and s.FAKT_DAT="+IntToStr(d);
  sql+=" and s.PRICH=''";
  sql+=" and s.LCHET1 NOT IN ('Прошврем','раздел 1')";
  sql+=" and a.M="+IntToStr(m);
  sql+=" and a.Y="+IntToStr(y);
  sql+=" group by s.metka1 , s.fakt_chel";
  Q_INS->SQL->Add(sql);
  try
  {
    Q_INS->ExecQuery();
  }
  catch (Exception &exc)
  {
    MessageDlg("Ошибка - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
    return;
  }
  kol2=Q_INS->FieldByName("KOL")->AsInteger;

  Q_INS->Close();
  Q_INS->SQL->Clear();
  sql="select SUM(s.SUMMA) as sumexp, COUNT(s.LCHET) as kol , s.metka1 , s.fakt_chel from ACCOUNTS a left outer join SGB s on a.ORG_ID=s.ORG_ID";
  sql+=" and a.COUNT_DATE=s.COUNT_DATE and a.COUNT_NUMBER=s.COUNT_NUMBER";
  sql+=" where a.USER_ID="+IntToStr(iduser);
  sql+=" and s.METKA1="+IntToStr(metka1);
  sql+=" and s.FAKT_CHEL="+IntToStr(idpost);
  sql+=" and s.FAKT_DAT="+IntToStr(d);
  sql+=" and s.PRICH=''";
  sql+=" and a.M="+IntToStr(m);
  sql+=" and a.Y="+IntToStr(y);
  sql+=" group by s.metka1 , s.fakt_chel";
  Q_INS->SQL->Add(sql);
  try
  {
    Q_INS->ExecQuery();
  }
  catch (Exception &exc)
  {
    MessageDlg("Ошибка - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
    return;
  }
  sexp2=Q_INS->FieldByName("SUMEXP")->AsFloat;


  // определить выплаты всего неоплата

  Q_INS->Close();
  Q_INS->SQL->Clear();
  sql="select SUM(s.SUMMA) as sumexp, COUNT(s.LCHET) as kol , s.metka1 , s.fakt_chel from ACCOUNTS a left outer join SGB s on a.ORG_ID=s.ORG_ID";
  sql+=" and a.COUNT_DATE=s.COUNT_DATE and a.COUNT_NUMBER=s.COUNT_NUMBER";
  sql+=" where a.USER_ID="+IntToStr(iduser);
  sql+=" and s.METKA1="+IntToStr(metka1);
  sql+=" and s.FAKT_CHEL="+IntToStr(idpost);
  sql+=" and s.FAKT_DAT="+IntToStr(d);
  sql+=" and s.LCHET1 NOT IN ('Прошврем','раздел 1')";
  sql+=" and s.PRICH<>''";
  sql+=" and a.M="+IntToStr(m);
  sql+=" and a.Y="+IntToStr(y);
  sql+=" group by s.metka1 , s.fakt_chel";
  Q_INS->SQL->Add(sql);
  try
  {
    Q_INS->ExecQuery();
  }
  catch (Exception &exc)
  {
    MessageDlg("Ошибка - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
    return;
  }
  kol3=Q_INS->FieldByName("KOL")->AsInteger;

  Q_INS->Close();
  Q_INS->SQL->Clear();
  sql="select SUM(s.SUMMA) as sumexp, COUNT(s.LCHET) as kol , s.metka1 , s.fakt_chel from ACCOUNTS a left outer join SGB s on a.ORG_ID=s.ORG_ID";
  sql+=" and a.COUNT_DATE=s.COUNT_DATE and a.COUNT_NUMBER=s.COUNT_NUMBER";
  sql+=" where a.USER_ID="+IntToStr(iduser);
  sql+=" and s.METKA1="+IntToStr(metka1);
  sql+=" and s.FAKT_CHEL="+IntToStr(idpost);
  sql+=" and s.FAKT_DAT="+IntToStr(d);
  sql+=" and s.PRICH<>''";
  sql+=" and a.M="+IntToStr(m);
  sql+=" and a.Y="+IntToStr(y);
  sql+=" group by s.metka1 , s.fakt_chel";
  Q_INS->SQL->Add(sql);
  try
  {
    Q_INS->ExecQuery();
  }
  catch (Exception &exc)
  {
    MessageDlg("Ошибка - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
    return;
  }
  sexp3=Q_INS->FieldByName("SUMEXP")->AsFloat;
  Q_INS->Close();

    if (kol1>0){
    Q->Close();
    Q->SQL->Clear();
    sql="delete from EXPENSES_TABLE where ";
    sql+="EXP_DATE='"+dexp.DateString()+"'";
    sql+=" and SD_ID = " + IntToStr(idopsp) + "";
    sql+=" and DRIVER_ID = " +IntToStr(idops);
    sql+=" and FLAG = 1";
    sql+=" and GSM_ID IN (3,37,74)";
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
    Q->Transaction->Commit();


    idexp=0;
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
    {
      MessageDlg("Ошибка - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      Q->Transaction->Rollback();
      return;
    }
    if(Q->RecordCount==0)
    {
      MessageDlg("Ошибка получения значения ID таблицы EXPENSES_TABLE",mtError,TMsgDlgButtons() << mbOK,0);
      Q->Transaction->Rollback();
      return;
    }
    idexp=Q->FieldByName("ID")->AsInteger;

    Q->Close();
    Q->SQL->Clear();
    sql="insert into EXPENSES_TABLE(ID,EXP_DATE,SD_ID,DRIVER_ID,GSM_ID,KOL,EXPENSE,FLAG,EDITABLE,U_ID,D) values(";
    sql+=IntToStr(idexp)+",";
    sql+="'"+dexp.DateString()+"',";
    sql+=IntToStr(idopsp)+",";
    sql+=IntToStr(idops)+",3,";
    sql+=IntToStr(kol1)+",";
    sql+=FloatToStr(sexp1)+",1,1,";
    sql+=IntToStr(GSM_DM->UserID)+",0)";
    Q->SQL->Add(sql);
    try
    {
      Q->ExecQuery();
      kolzap++;
    }
    catch (Exception &exc)
    {
      MessageDlg("Ошибка - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      Q->Transaction->Rollback();
      return;
    }
    Q->Transaction->Commit();

    idexp=0;
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
    {
      MessageDlg("Ошибка - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      Q->Transaction->Rollback();
      return;
    }
    if(Q->RecordCount==0)
    {
      MessageDlg("Ошибка получения значения ID таблицы EXPENSES_TABLE",mtError,TMsgDlgButtons() << mbOK,0);
      Q->Transaction->Rollback();
      return;
    }
    idexp=Q->FieldByName("ID")->AsInteger;

    Q->Close();
    Q->SQL->Clear();
    sql="insert into EXPENSES_TABLE(ID,EXP_DATE,SD_ID,DRIVER_ID,GSM_ID,KOL,EXPENSE,FLAG,EDITABLE,U_ID,D) values(";
    sql+=IntToStr(idexp)+",";
    sql+="'"+dexp.DateString()+"',";
    sql+=IntToStr(idopsp)+",";
    sql+=IntToStr(idops)+",37,";
    sql+=IntToStr(kol2)+",";
    sql+=FloatToStr(sexp2)+",1,1,";
    sql+=IntToStr(GSM_DM->UserID)+",0)";
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

    idexp=0;
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
    {
      MessageDlg("Ошибка - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      Q->Transaction->Rollback();
      return;
    }
    if(Q->RecordCount==0)
    {
      MessageDlg("Ошибка получения значения ID таблицы EXPENSES_TABLE",mtError,TMsgDlgButtons() << mbOK,0);
      Q->Transaction->Rollback();
      return;
    }
    idexp=Q->FieldByName("ID")->AsInteger;

    Q->Close();
    Q->SQL->Clear();
    sql="insert into EXPENSES_TABLE(ID,EXP_DATE,SD_ID,DRIVER_ID,GSM_ID,KOL,EXPENSE,FLAG,EDITABLE,U_ID,D) values(";
    sql+=IntToStr(idexp)+",";
    sql+="'"+dexp.DateString()+"',";
    sql+=IntToStr(idopsp)+",";
    sql+=IntToStr(idops)+",74,";
    sql+=IntToStr(kol3)+",";
    sql+=FloatToStr(sexp3)+",1,1,";
    sql+=IntToStr(GSM_DM->UserID)+",0)";
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

    result+="Импортировано по " + nameops + " по ОПС " + indexops + " приход кол " + IntToStr(kol1) + " приход руб " + AnsiString().sprintf("%.02lf",sexp1) + " расход кол " + IntToStr(kol2) + " расход руб " + AnsiString().sprintf("%.02lf",sexp2) + " возврат кол " + IntToStr(kol3) + " возврат руб " + AnsiString().sprintf("%.02lf",sexp3) +"\n";
    }

  if (usersINS->Active)
  {
  usersINS->Next();
  }else
  {
  usersINS->Active=true;
  usersINS->Next();
  }
  }

if ( kolzap == 0) result="Данных нет!!! Отдыхайте!!! )))";

usersINS->Close();
LoadWorkDS(getSD_ID(),getID());
TLocateOptions lo; lo.Clear();
if(PC->ActivePageIndex == 0){
if(ActivTable == 1) workDS->Locate("ID",ID,lo);
if(ActivTable == 2) workDS3->Locate("ID",ID,lo);
if(ActivTable == 3) workDS4->Locate("ID",ID,lo);
}
if(PC->ActivePageIndex == 1) workDS1->Locate("ID",ID,lo);
if(PC->ActivePageIndex == 2) workDS2->Locate("ID",ID,lo);
MessageDlg(result,mtInformation,TMsgDlgButtons() << mbOK,0);
}
}

// импорт по кассе

if (workGrid1->Focused())
{
kolzap = 0;

if(MessageDlg("Вы уверены, что хотите получить данные из ИС ИНСПЕКТОР за " + AnsiString().sprintf("%02d-%02d-%d",d,m,y) + " ? \n ВНИМАНИЕ!!! При импорте старые записи безвозвратно удалятся!!!", mtConfirmation,TMsgDlgButtons() << mbOK << mbCancel,0)==mrOk)
{

kol1=0;
sexp1=0.00;

  Q_LOC->Close();
  Q_LOC->SQL->Clear();
  sql="select e.* from USERS_TABLE e";
  sql+=" where e.U_LOGIN='"+GSM_DM->UserLogin+"'";
  Q_LOC->SQL->Add(sql);
  try
  {
    Q_LOC->ExecQuery();
  }
  catch (Exception &exc)
  {
    MessageDlg("Ошибка - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
    return;
  }
  iduser=Q_LOC->FieldByName("IDINS")->AsInteger;
  Q_LOC->Close();

  sql="select SUM(s.SUMMA) as sumexp , s.metka1 , s.fakt_chel from ACCOUNTS a left outer join SGB s on a.ORG_ID=s.ORG_ID";
  sql+=" and a.COUNT_DATE=s.COUNT_DATE and a.COUNT_NUMBER=s.COUNT_NUMBER";
  sql+=" where a.USER_ID="+IntToStr(iduser);
  sql+=" and s.FAKT_DAT="+IntToStr(d);
  sql+=" and a.M="+IntToStr(m);
  sql+=" and a.Y="+IntToStr(y);
  sql+=" group by s.metka1 , s.fakt_chel";
  usersINS->SQLs->SelectSQL->Clear();
  usersINS->SQLs->SelectSQL->Add(sql);

  try
  {
    usersINS->Open();
  }
  catch (Exception &exc)
  {
    MessageDlg("Ошибка открытия таблицы сумм ACCOUNTS из ИС ИНСПЕКТОР\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
    return;
  }
  usersINS->Last();
  usersINS->First();
  while(!usersINS->Eof)
  {

  metka1=usersINS->FieldByName("METKA1")->AsInteger;

  // определить код кассы из справочника касс

  Q_LOC->Close();
  Q_LOC->SQL->Clear();
  sql="select e.* from KASSA_TABLE e";
  sql+=" where e.IDINS="+IntToStr(usersINS->FieldByName("FAKT_CHEL")->AsInteger);
  sql+=" and e.FILE_ID=1 and e.REC_TYPE=0";
  Q_LOC->SQL->Add(sql);
  try
  {
    Q_LOC->ExecQuery();
  }
  catch (Exception &exc)
  {
    MessageDlg("Ошибка - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
    return;
  }
  idopsp=Q_LOC->FieldByName("ID")->AsInteger;
  idpost=Q_LOC->FieldByName("IDINS")->AsInteger;
  nameops=Q_LOC->FieldByName("DESCRIPTION")->AsString;
  Q_LOC->Close();

  AnsiString kodidpost=IntToStr(metka1);
  AnsiString indexopsfull="";
  if (kodidpost.Length()==1) indexopsfull="63000"+kodidpost.Trim();
  if (kodidpost.Length()==2) indexopsfull="6300"+kodidpost.Trim();
  if (kodidpost.Length()==3) indexopsfull="630"+kodidpost.Trim();
  pos1=MainForm->IndexOps.Pos("жел");
  pos2=MainForm->IndexOps.Pos("центр");
  if (pos1>0)
  {
     if (metka1==7 || metka1==99) indexopsfull=indexopsfull + " жел ";
     nameops="Железнодорожная";
  }
  if (pos2>0)
  {
     if (metka1==7 || metka1==99) indexopsfull=indexopsfull + " центр ";
     nameops="Центральная";
  }

  Q_LOC->Close();
  Q_LOC->SQL->Clear();
  sql="select e.* from KASSA_TABLE e";
  sql+=" where e.DESCRIPTION STARTING WITH '"+indexopsfull.Trim()+"'";
  sql+=" and e.FILE_ID="+IntToStr(idopsp);
  Q_LOC->SQL->Add(sql);
  try
  {
    Q_LOC->ExecQuery();
  }
  catch (Exception &exc)
  {
    MessageDlg("Ошибка - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
    return;
  }
  idops=Q_LOC->FieldByName("ID")->AsInteger;
  indexops=Q_LOC->FieldByName("DESCRIPTION")->AsString;
  Q_LOC->Close();


  // определить выплаты всего общее and LCHET1 NOT IN ('Прошврем','раздел 1')

  Q_INS->Close();
  Q_INS->SQL->Clear();
  sql="select COUNT(s.LCHET) as kol , s.metka1 , s.fakt_chel from ACCOUNTS a left outer join SGB s on a.ORG_ID=s.ORG_ID";
  sql+=" and a.COUNT_DATE=s.COUNT_DATE and a.COUNT_NUMBER=s.COUNT_NUMBER";
  sql+=" where a.USER_ID="+IntToStr(iduser);
  sql+=" and s.FAKT_CHEL="+IntToStr(idpost);
  sql+=" and s.METKA1="+IntToStr(metka1);
  sql+=" and s.FAKT_DAT="+IntToStr(d);
  sql+=" and s.LCHET1 NOT IN ('Прошврем','раздел 1')";
  sql+=" and a.M="+IntToStr(m);
  sql+=" and a.Y="+IntToStr(y);
  sql+=" group by s.metka1 , s.fakt_chel";
  Q_INS->SQL->Add(sql);
  try
  {
    Q_INS->ExecQuery();
  }
  catch (Exception &exc)
  {
    MessageDlg("Ошибка - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
    return;
  }
  kol1=Q_INS->FieldByName("KOL")->AsInteger;

  Q_INS->Close();
  Q_INS->SQL->Clear();
  sql="select SUM(s.SUMMA) as sumexp, COUNT(s.LCHET) as kol , s.metka1 , s.fakt_chel from ACCOUNTS a left outer join SGB s on a.ORG_ID=s.ORG_ID";
  sql+=" and a.COUNT_DATE=s.COUNT_DATE and a.COUNT_NUMBER=s.COUNT_NUMBER";
  sql+=" where a.USER_ID="+IntToStr(iduser);
  sql+=" and s.METKA1="+IntToStr(metka1);
  sql+=" and s.FAKT_CHEL="+IntToStr(idpost);
  sql+=" and s.FAKT_DAT="+IntToStr(d);
  sql+=" and a.M="+IntToStr(m);
  sql+=" and a.Y="+IntToStr(y);
  sql+=" group by s.metka1 , s.fakt_chel";
  Q_INS->SQL->Add(sql);
  try
  {
    Q_INS->ExecQuery();
  }
  catch (Exception &exc)
  {
    MessageDlg("Ошибка - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
    return;
  }
  sexp1=Q_INS->FieldByName("SUMEXP")->AsFloat;


    if (kol1>0){

    Q->Close();
    Q->SQL->Clear();
    sql="delete from EXPENSES_TABLE where ";
    sql+="EXP_DATE='"+dexp.DateString()+"'";
    sql+=" and SD_ID = " + IntToStr(idopsp) + "";
    sql+=" and DRIVER_ID = " +IntToStr(idops);
    sql+=" and FLAG = 0";
    sql+=" and GSM_ID IN (3,37,74)";
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
    Q->Transaction->Commit();

    idexp=0;
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
    {
      MessageDlg("Ошибка - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      Q->Transaction->Rollback();
      return;
    }
    if(Q->RecordCount==0)
    {
      MessageDlg("Ошибка получения значения ID таблицы EXPENSES_TABLE",mtError,TMsgDlgButtons() << mbOK,0);
      Q->Transaction->Rollback();
      return;
    }
    idexp=Q->FieldByName("ID")->AsInteger;

    Q->Close();
    Q->SQL->Clear();
    sql="insert into EXPENSES_TABLE(ID,EXP_DATE,SD_ID,DRIVER_ID,GSM_ID,KOL,EXPENSE,FLAG,EDITABLE,U_ID,D) values(";
    sql+=IntToStr(idexp)+",";
    sql+="'"+dexp.DateString()+"',";
    sql+=IntToStr(idopsp)+",";
    sql+=IntToStr(idops)+",37,";
    sql+=IntToStr(kol1)+",";
    sql+=FloatToStr(sexp1)+",0,1,";
    sql+=IntToStr(GSM_DM->UserID)+",0)";
    Q->SQL->Add(sql);
    try
    {
      Q->ExecQuery();
      kolzap++;
    }
    catch (Exception &exc)
    {
      MessageDlg("Ошибка - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      Q->Transaction->Rollback();
      return;
    }
    Q->Transaction->Commit();


    result+="Импортировано по " + nameops + " по ОПС " + indexops + " расход кол " + IntToStr(kol1) + " расход руб " + AnsiString().sprintf("%.02lf",sexp1) +"\n";
    }

  if (usersINS->Active)
  {
  usersINS->Next();
  }else
  {
  usersINS->Active=true;
  usersINS->Next();
  }
  }

if ( kolzap == 0) result="Данных нет!!! Отдыхайте!!! )))";
usersINS->Close();
LoadWorkDS(getSD_ID(),getID());
TLocateOptions lo; lo.Clear();
if(PC->ActivePageIndex == 0){
if(ActivTable == 1) workDS->Locate("ID",ID,lo);
if(ActivTable == 2) workDS3->Locate("ID",ID,lo);
if(ActivTable == 3) workDS4->Locate("ID",ID,lo);
}
if(PC->ActivePageIndex == 1) workDS1->Locate("ID",ID,lo);
if(PC->ActivePageIndex == 2) workDS2->Locate("ID",ID,lo);
MessageDlg(result,mtInformation,TMsgDlgButtons() << mbOK,0);
}

}

}
//---------------------------------------------------------------------------


void __fastcall TMainForm::selectSDBarItems17Click(TObject *Sender)
{
setMainHeader();setMainHeader();  if(PC->ActivePageIndex == 0){
  selectSDBar->Items->Items[selectedSD]->Checked=false;
  selectedSD=17;
  if(Showing) LoadWorkDS(getSD_ID(),getID());
  selectSDBar->Items->Items[selectedSD]->Checked=true;
  setMainHeader();
  selectSDBarClick(this);
  }else
  {
  selectSDBar1->Items->Items[selectedSD1]->Checked=false;
  selectedSD1=17;
  if(Showing) LoadWorkDS(getSD_ID(),getID());
  selectSDBar1->Items->Items[selectedSD1]->Checked=true;
  setMainHeader();
  selectSDBarClick(this);
  }
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::selectSDBarItems18Click(TObject *Sender)
{
  if(PC->ActivePageIndex == 0){
  selectSDBar->Items->Items[selectedSD]->Checked=false;
  selectedSD=18;
  if(Showing) LoadWorkDS(getSD_ID(),getID());
  selectSDBar->Items->Items[selectedSD]->Checked=true;
  setMainHeader();
  selectSDBarClick(this);
  }else
  {
  selectSDBar1->Items->Items[selectedSD1]->Checked=false;
  selectedSD1=18;
  if(Showing) LoadWorkDS(getSD_ID(),getID());
  selectSDBar1->Items->Items[selectedSD1]->Checked=true;
  setMainHeader();
  selectSDBarClick(this);
  }
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::selectSDBarItems19Click(TObject *Sender)
{
  if(PC->ActivePageIndex == 0){
  selectSDBar->Items->Items[selectedSD]->Checked=false;
  selectedSD=19;
  if(Showing) LoadWorkDS(getSD_ID(),getID());
  selectSDBar->Items->Items[selectedSD]->Checked=true;
  setMainHeader();
  selectSDBarClick(this);
  }else
  {
  selectSDBar1->Items->Items[selectedSD1]->Checked=false;
  selectedSD1=19;
  if(Showing) LoadWorkDS(getSD_ID(),getID());
  selectSDBar1->Items->Items[selectedSD1]->Checked=true;
  setMainHeader();
  selectSDBarClick(this);
  }
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::selectSDBarItems20Click(TObject *Sender)
{
  if(PC->ActivePageIndex == 0){
  selectSDBar->Items->Items[selectedSD]->Checked=false;
  selectedSD=20;
  if(Showing) LoadWorkDS(getSD_ID(),getID());
  selectSDBar->Items->Items[selectedSD]->Checked=true;
  setMainHeader();
  selectSDBarClick(this);
  }else
  {
  selectSDBar1->Items->Items[selectedSD1]->Checked=false;
  selectedSD1=20;
  if(Showing) LoadWorkDS(getSD_ID(),getID());
  selectSDBar1->Items->Items[selectedSD1]->Checked=true;
  setMainHeader();
  selectSDBarClick(this);
  }
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::selectSDBarItems21Click(TObject *Sender)
{
  if(PC->ActivePageIndex == 0){
  selectSDBar->Items->Items[selectedSD]->Checked=false;
  selectedSD=21;
  if(Showing) LoadWorkDS(getSD_ID(),getID());
  selectSDBar->Items->Items[selectedSD]->Checked=true;
  setMainHeader();
  selectSDBarClick(this);
  }else
  {
  selectSDBar1->Items->Items[selectedSD1]->Checked=false;
  selectedSD1=21;
  if(Showing) LoadWorkDS(getSD_ID(),getID());
  selectSDBar1->Items->Items[selectedSD1]->Checked=true;
  setMainHeader();
  selectSDBarClick(this);
  }
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::selectSDBarItems22Click(TObject *Sender)
{
  if(PC->ActivePageIndex == 0){
  selectSDBar->Items->Items[selectedSD]->Checked=false;
  selectedSD=22;
  if(Showing) LoadWorkDS(getSD_ID(),getID());
  selectSDBar->Items->Items[selectedSD]->Checked=true;
  setMainHeader();
  selectSDBarClick(this);
  }else
  {
  selectSDBar1->Items->Items[selectedSD1]->Checked=false;
  selectedSD1=22;
  if(Showing) LoadWorkDS(getSD_ID(),getID());
  selectSDBar1->Items->Items[selectedSD1]->Checked=true;
  setMainHeader();
  selectSDBarClick(this);
  }
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::selectSDBarItems23Click(TObject *Sender)
{
  if(PC->ActivePageIndex == 0){
  selectSDBar->Items->Items[selectedSD]->Checked=false;
  selectedSD=23;
  if(Showing) LoadWorkDS(getSD_ID(),getID());
  selectSDBar->Items->Items[selectedSD]->Checked=true;
  setMainHeader();
  selectSDBarClick(this);
  }else
  {
  selectSDBar1->Items->Items[selectedSD1]->Checked=false;
  selectedSD1=23;
  if(Showing) LoadWorkDS(getSD_ID(),getID());
  selectSDBar1->Items->Items[selectedSD1]->Checked=true;
  setMainHeader();
  selectSDBarClick(this);
  }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::selectSDBarItems24Click(TObject *Sender)
{
  if(PC->ActivePageIndex == 0){
  selectSDBar->Items->Items[selectedSD]->Checked=false;
  selectedSD=24;
  if(Showing) LoadWorkDS(getSD_ID(),getID());
  selectSDBar->Items->Items[selectedSD]->Checked=true;
  setMainHeader();
  selectSDBarClick(this);
  }else
  {
  selectSDBar1->Items->Items[selectedSD1]->Checked=false;
  selectedSD1=24;
  if(Showing) LoadWorkDS(getSD_ID(),getID());
  selectSDBar1->Items->Items[selectedSD1]->Checked=true;
  setMainHeader();
  selectSDBarClick(this);
  }
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::selectSDBarItems25Click(TObject *Sender)
{
  if(PC->ActivePageIndex == 0){
  selectSDBar->Items->Items[selectedSD]->Checked=false;
  selectedSD=25;
  if(Showing) LoadWorkDS(getSD_ID(),getID());
  selectSDBar->Items->Items[selectedSD]->Checked=true;
  setMainHeader();
  selectSDBarClick(this);
  }else
  {
  selectSDBar1->Items->Items[selectedSD1]->Checked=false;
  selectedSD1=25;
  if(Showing) LoadWorkDS(getSD_ID(),getID());
  selectSDBar1->Items->Items[selectedSD1]->Checked=true;
  setMainHeader();
  selectSDBarClick(this);
  }
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::selectSDBarItems26Click(TObject *Sender)
{
  if(PC->ActivePageIndex == 0){
  selectSDBar->Items->Items[selectedSD]->Checked=false;
  selectedSD=26;
  if(Showing) LoadWorkDS(getSD_ID(),getID());
  selectSDBar->Items->Items[selectedSD]->Checked=true;
  setMainHeader();
  selectSDBarClick(this);
  }else
  {
  selectSDBar1->Items->Items[selectedSD1]->Checked=false;
  selectedSD1=26;
  if(Showing) LoadWorkDS(getSD_ID(),getID());
  selectSDBar1->Items->Items[selectedSD1]->Checked=true;
  setMainHeader();
  selectSDBarClick(this);
  }
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::selectSDBarItems27Click(TObject *Sender)
{
  if(PC->ActivePageIndex == 0){
  selectSDBar->Items->Items[selectedSD]->Checked=false;
  selectedSD=27;
  if(Showing) LoadWorkDS(getSD_ID(),getID());
  selectSDBar->Items->Items[selectedSD]->Checked=true;
  setMainHeader();
  selectSDBarClick(this);
  }else
  {
  selectSDBar1->Items->Items[selectedSD1]->Checked=false;
  selectedSD1=27;
  if(Showing) LoadWorkDS(getSD_ID(),getID());
  selectSDBar1->Items->Items[selectedSD1]->Checked=true;
  setMainHeader();
  selectSDBarClick(this);
  }
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::selectSDBarItems28Click(TObject *Sender)
{
  if(PC->ActivePageIndex == 0){
  selectSDBar->Items->Items[selectedSD]->Checked=false;
  selectedSD=28;
  if(Showing) LoadWorkDS(getSD_ID(),getID());
  selectSDBar->Items->Items[selectedSD]->Checked=true;
  setMainHeader();
  selectSDBarClick(this);
  }else
  {
  selectSDBar1->Items->Items[selectedSD1]->Checked=false;
  selectedSD1=28;
  if(Showing) LoadWorkDS(getSD_ID(),getID());
  selectSDBar1->Items->Items[selectedSD1]->Checked=true;
  setMainHeader();
  selectSDBarClick(this);
  }
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::selectSDBarItems29Click(TObject *Sender)
{
  if(PC->ActivePageIndex == 0){
  selectSDBar->Items->Items[selectedSD]->Checked=false;
  selectedSD=29;
  if(Showing) LoadWorkDS(getSD_ID(),getID());
  selectSDBar->Items->Items[selectedSD]->Checked=true;
  setMainHeader();
  selectSDBarClick(this);
  }else
  {
  selectSDBar1->Items->Items[selectedSD1]->Checked=false;
  selectedSD1=29;
  if(Showing) LoadWorkDS(getSD_ID(),getID());
  selectSDBar1->Items->Items[selectedSD1]->Checked=true;
  setMainHeader();
  selectSDBarClick(this);
  }
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::selectSDBarItems30Click(TObject *Sender)
{
  if(PC->ActivePageIndex == 0){
  selectSDBar->Items->Items[selectedSD]->Checked=false;
  selectedSD=30;
  if(Showing) LoadWorkDS(getSD_ID(),getID());
  selectSDBar->Items->Items[selectedSD]->Checked=true;
  setMainHeader();
  selectSDBarClick(this);
  }else
  {
  selectSDBar1->Items->Items[selectedSD1]->Checked=false;
  selectedSD1=30;
  if(Showing) LoadWorkDS(getSD_ID(),getID());
  selectSDBar1->Items->Items[selectedSD1]->Checked=true;
  setMainHeader();
  selectSDBarClick(this);
  }
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::selectSDBarItems31Click(TObject *Sender)
{
  if(PC->ActivePageIndex == 0){
  selectSDBar->Items->Items[selectedSD]->Checked=false;
  selectedSD=31;
  if(Showing) LoadWorkDS(getSD_ID(),getID());
  selectSDBar->Items->Items[selectedSD]->Checked=true;
  setMainHeader();
  selectSDBarClick(this);
  }else
  {
  selectSDBar1->Items->Items[selectedSD1]->Checked=false;
  selectedSD1=31;
  if(Showing) LoadWorkDS(getSD_ID(),getID());
  selectSDBar1->Items->Items[selectedSD1]->Checked=true;
  setMainHeader();
  selectSDBarClick(this);
  }
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::selectSDBarItems32Click(TObject *Sender)
{
  if(PC->ActivePageIndex == 0){
  selectSDBar->Items->Items[selectedSD]->Checked=false;
  selectedSD=32;
  if(Showing) LoadWorkDS(getSD_ID(),getID());
  selectSDBar->Items->Items[selectedSD]->Checked=true;
  setMainHeader();
  selectSDBarClick(this);
  }else
  {
  selectSDBar1->Items->Items[selectedSD1]->Checked=false;
  selectedSD1=32;
  if(Showing) LoadWorkDS(getSD_ID(),getID());
  selectSDBar1->Items->Items[selectedSD1]->Checked=true;
  setMainHeader();
  selectSDBarClick(this);
  }
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::selectSDBarItems33Click(TObject *Sender)
{
  if(PC->ActivePageIndex == 0){
  selectSDBar->Items->Items[selectedSD]->Checked=false;
  selectedSD=33;
  if(Showing) LoadWorkDS(getSD_ID(),getID());
  selectSDBar->Items->Items[selectedSD]->Checked=true;
  setMainHeader();
  selectSDBarClick(this);
  }else
  {
  selectSDBar1->Items->Items[selectedSD1]->Checked=false;
  selectedSD1=33;
  if(Showing) LoadWorkDS(getSD_ID(),getID());
  selectSDBar1->Items->Items[selectedSD1]->Checked=true;
  setMainHeader();
  selectSDBarClick(this);
  }
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::selectSDBarItems34Click(TObject *Sender)
{
  if(PC->ActivePageIndex == 0){
  selectSDBar->Items->Items[selectedSD]->Checked=false;
  selectedSD=34;
  if(Showing) LoadWorkDS(getSD_ID(),getID());
  selectSDBar->Items->Items[selectedSD]->Checked=true;
  setMainHeader();
  selectSDBarClick(this);
  }else
  {
  selectSDBar1->Items->Items[selectedSD1]->Checked=false;
  selectedSD1=34;
  if(Showing) LoadWorkDS(getSD_ID(),getID());
  selectSDBar1->Items->Items[selectedSD1]->Checked=true;
  setMainHeader();
  selectSDBarClick(this);
  }
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::selectSDBarItems35Click(TObject *Sender)
{
  if(PC->ActivePageIndex == 0){
  selectSDBar->Items->Items[selectedSD]->Checked=false;
  selectedSD=35;
  if(Showing) LoadWorkDS(getSD_ID(),getID());
  selectSDBar->Items->Items[selectedSD]->Checked=true;
  setMainHeader();
  selectSDBarClick(this);
  }else
  {
  selectSDBar1->Items->Items[selectedSD1]->Checked=false;
  selectedSD1=35;
  if(Showing) LoadWorkDS(getSD_ID(),getID());
  selectSDBar1->Items->Items[selectedSD1]->Checked=true;
  setMainHeader();
  selectSDBarClick(this);
  }
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::selectSDBarItems36Click(TObject *Sender)
{
  if(PC->ActivePageIndex == 0){
  selectSDBar->Items->Items[selectedSD]->Checked=false;
  selectedSD=36;
  if(Showing) LoadWorkDS(getSD_ID(),getID());
  selectSDBar->Items->Items[selectedSD]->Checked=true;
  setMainHeader();
  selectSDBarClick(this);
  }else
  {
  selectSDBar1->Items->Items[selectedSD1]->Checked=false;
  selectedSD1=36;
  if(Showing) LoadWorkDS(getSD_ID(),getID());
  selectSDBar1->Items->Items[selectedSD1]->Checked=true;
  setMainHeader();
  selectSDBarClick(this);
  }
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::selectSDBarItems37Click(TObject *Sender)
{
  if(PC->ActivePageIndex == 0){
  selectSDBar->Items->Items[selectedSD]->Checked=false;
  selectedSD=37;
  if(Showing) LoadWorkDS(getSD_ID(),getID());
  selectSDBar->Items->Items[selectedSD]->Checked=true;
  setMainHeader();
  selectSDBarClick(this);
  }else
  {
  selectSDBar1->Items->Items[selectedSD1]->Checked=false;
  selectedSD1=37;
  if(Showing) LoadWorkDS(getSD_ID(),getID());
  selectSDBar1->Items->Items[selectedSD1]->Checked=true;
  setMainHeader();
  selectSDBarClick(this);
  }
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::selectSDBarItems38Click(TObject *Sender)
{
  if(PC->ActivePageIndex == 0){
  selectSDBar->Items->Items[selectedSD]->Checked=false;
  selectedSD=38;
  if(Showing) LoadWorkDS(getSD_ID(),getID());
  selectSDBar->Items->Items[selectedSD]->Checked=true;
  setMainHeader();
  selectSDBarClick(this);
  }else
  {
  selectSDBar1->Items->Items[selectedSD1]->Checked=false;
  selectedSD1=38;
  if(Showing) LoadWorkDS(getSD_ID(),getID());
  selectSDBar1->Items->Items[selectedSD1]->Checked=true;
  setMainHeader();
  selectSDBarClick(this);
  }
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::selectSDBarItems39Click(TObject *Sender)
{
  if(PC->ActivePageIndex == 0){
  selectSDBar->Items->Items[selectedSD]->Checked=false;
  selectedSD=39;
  if(Showing) LoadWorkDS(getSD_ID(),getID());
  selectSDBar->Items->Items[selectedSD]->Checked=true;
  setMainHeader();
  selectSDBarClick(this);
  }else
  {
  selectSDBar1->Items->Items[selectedSD1]->Checked=false;
  selectedSD1=39;
  if(Showing) LoadWorkDS(getSD_ID(),getID());
  selectSDBar1->Items->Items[selectedSD1]->Checked=true;
  setMainHeader();
  selectSDBarClick(this);
  }
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::selectSDBarItems40Click(TObject *Sender)
{
  if(PC->ActivePageIndex == 0){
  selectSDBar->Items->Items[selectedSD]->Checked=false;
  selectedSD=40;
  if(Showing) LoadWorkDS(getSD_ID(),getID());
  selectSDBar->Items->Items[selectedSD]->Checked=true;
  setMainHeader();
  selectSDBarClick(this);
  }else
  {
  selectSDBar1->Items->Items[selectedSD1]->Checked=false;
  selectedSD1=40;
  if(Showing) LoadWorkDS(getSD_ID(),getID());
  selectSDBar1->Items->Items[selectedSD1]->Checked=true;
  setMainHeader();
  selectSDBarClick(this);
  }
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::selectSDBarItems41Click(TObject *Sender)
{
  if(PC->ActivePageIndex == 0){
  selectSDBar->Items->Items[selectedSD]->Checked=false;
  selectedSD=41;
  if(Showing) LoadWorkDS(getSD_ID(),getID());
  selectSDBar->Items->Items[selectedSD]->Checked=true;
  setMainHeader();
  selectSDBarClick(this);
  }else
  {
  selectSDBar1->Items->Items[selectedSD1]->Checked=false;
  selectedSD1=41;
  if(Showing) LoadWorkDS(getSD_ID(),getID());
  selectSDBar1->Items->Items[selectedSD1]->Checked=true;
  setMainHeader();
  selectSDBarClick(this);
  }
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::selectSDBarItems42Click(TObject *Sender)
{
  if(PC->ActivePageIndex == 0){
  selectSDBar->Items->Items[selectedSD]->Checked=false;
  selectedSD=42;
  if(Showing) LoadWorkDS(getSD_ID(),getID());
  selectSDBar->Items->Items[selectedSD]->Checked=true;
  setMainHeader();
  selectSDBarClick(this);
  }else
  {
  selectSDBar1->Items->Items[selectedSD1]->Checked=false;
  selectedSD1=42;
  if(Showing) LoadWorkDS(getSD_ID(),getID());
  selectSDBar1->Items->Items[selectedSD1]->Checked=true;
  setMainHeader();
  selectSDBarClick(this);
  }
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::selectSDBarItems43Click(TObject *Sender)
{
  if(PC->ActivePageIndex == 0){
  selectSDBar->Items->Items[selectedSD]->Checked=false;
  selectedSD=43;
  if(Showing) LoadWorkDS(getSD_ID(),getID());
  selectSDBar->Items->Items[selectedSD]->Checked=true;
  setMainHeader();
  selectSDBarClick(this);
  }else
  {
  selectSDBar1->Items->Items[selectedSD1]->Checked=false;
  selectedSD1=43;
  if(Showing) LoadWorkDS(getSD_ID(),getID());
  selectSDBar1->Items->Items[selectedSD1]->Checked=true;
  setMainHeader();
  selectSDBarClick(this);
  }
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::selectSDBarItems44Click(TObject *Sender)
{
  if(PC->ActivePageIndex == 0){
  selectSDBar->Items->Items[selectedSD]->Checked=false;
  selectedSD=44;
  if(Showing) LoadWorkDS(getSD_ID(),getID());
  selectSDBar->Items->Items[selectedSD]->Checked=true;
  setMainHeader();
  selectSDBarClick(this);
  }else
  {
  selectSDBar1->Items->Items[selectedSD1]->Checked=false;
  selectedSD1=44;
  if(Showing) LoadWorkDS(getSD_ID(),getID());
  selectSDBar1->Items->Items[selectedSD1]->Checked=true;
  setMainHeader();
  selectSDBarClick(this);
  }
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::selectSDBarItems45Click(TObject *Sender)
{
  if(PC->ActivePageIndex == 0){
  selectSDBar->Items->Items[selectedSD]->Checked=false;
  selectedSD=45;
  if(Showing) LoadWorkDS(getSD_ID(),getID());
  selectSDBar->Items->Items[selectedSD]->Checked=true;
  setMainHeader();
  selectSDBarClick(this);
  }else
  {
  selectSDBar1->Items->Items[selectedSD1]->Checked=false;
  selectedSD1=45;
  if(Showing) LoadWorkDS(getSD_ID(),getID());
  selectSDBar1->Items->Items[selectedSD1]->Checked=true;
  setMainHeader();
  selectSDBarClick(this);
  }
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::selectSDBarItems46Click(TObject *Sender)
{
  if(PC->ActivePageIndex == 0){
  selectSDBar->Items->Items[selectedSD]->Checked=false;
  selectedSD=46;
  if(Showing) LoadWorkDS(getSD_ID(),getID());
  selectSDBar->Items->Items[selectedSD]->Checked=true;
  setMainHeader();
  selectSDBarClick(this);
  }else
  {
  selectSDBar1->Items->Items[selectedSD1]->Checked=false;
  selectedSD1=46;
  if(Showing) LoadWorkDS(getSD_ID(),getID());
  selectSDBar1->Items->Items[selectedSD1]->Checked=true;
  setMainHeader();
  selectSDBarClick(this);
  }
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::selectSDBarItems47Click(TObject *Sender)
{
  if(PC->ActivePageIndex == 0){
  selectSDBar->Items->Items[selectedSD]->Checked=false;
  selectedSD=47;
  if(Showing) LoadWorkDS(getSD_ID(),getID());
  selectSDBar->Items->Items[selectedSD]->Checked=true;
  setMainHeader();
  selectSDBarClick(this);
  }else
  {
  selectSDBar1->Items->Items[selectedSD1]->Checked=false;
  selectedSD1=47;
  if(Showing) LoadWorkDS(getSD_ID(),getID());
  selectSDBar1->Items->Items[selectedSD1]->Checked=true;
  setMainHeader();
  selectSDBarClick(this);
  }
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::selectSDBarItems48Click(TObject *Sender)
{
  if(PC->ActivePageIndex == 0){
  selectSDBar->Items->Items[selectedSD]->Checked=false;
  selectedSD=48;
  if(Showing) LoadWorkDS(getSD_ID(),getID());
  selectSDBar->Items->Items[selectedSD]->Checked=true;
  setMainHeader();
  selectSDBarClick(this);
  }else
  {
  selectSDBar1->Items->Items[selectedSD1]->Checked=false;
  selectedSD1=48;
  if(Showing) LoadWorkDS(getSD_ID(),getID());
  selectSDBar1->Items->Items[selectedSD1]->Checked=true;
  setMainHeader();
  selectSDBarClick(this);
  }
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::selectSDBarItems49Click(TObject *Sender)
{
  if(PC->ActivePageIndex == 0){
  selectSDBar->Items->Items[selectedSD]->Checked=false;
  selectedSD=49;
  if(Showing) LoadWorkDS(getSD_ID(),getID());
  selectSDBar->Items->Items[selectedSD]->Checked=true;
  setMainHeader();
  selectSDBarClick(this);
  }else
  {
  selectSDBar1->Items->Items[selectedSD1]->Checked=false;
  selectedSD1=49;
  if(Showing) LoadWorkDS(getSD_ID(),getID());
  selectSDBar1->Items->Items[selectedSD1]->Checked=true;
  setMainHeader();
  selectSDBarClick(this);
  }
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::selectSDBarItems50Click(TObject *Sender)
{
  if(PC->ActivePageIndex == 0){
  selectSDBar->Items->Items[selectedSD]->Checked=false;
  selectedSD=50;
  if(Showing) LoadWorkDS(getSD_ID(),getID());
  selectSDBar->Items->Items[selectedSD]->Checked=true;
  setMainHeader();
  selectSDBarClick(this);
  }else
  {
  selectSDBar1->Items->Items[selectedSD1]->Checked=false;
  selectedSD1=50;
  if(Showing) LoadWorkDS(getSD_ID(),getID());
  selectSDBar1->Items->Items[selectedSD1]->Checked=true;
  setMainHeader();
  selectSDBarClick(this);
  }
}
//---------------------------------------------------------------------------


void __fastcall TMainForm::selectSDBarItemClick(TObject *Sender,
      TJvXPBarItem *Item)
{
AddButton->Enabled =false;
DeleteButton->Enabled=false;
EditButton->Enabled=false;
editItem->Visible = false;
addItem->Visible = false;
delItem->Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::selectSDBarClick(TObject *Sender)
{
AddButton->Enabled =false;
DeleteButton->Enabled=false;
EditButton->Enabled=false;
editItem->Visible = false;
addItem->Visible = false;
delItem->Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::AddButtonClick(TObject *Sender)
{
addItemClick(this);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::EditButtonClick(TObject *Sender)
{
editItemClick(this);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::DeleteButtonClick(TObject *Sender)
{
delItemClick(this);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::N5Click(TObject *Sender)
{
selectedMenu=2;

//TURB *Drivers_RB=getDrivers_RB(selectSDBar1->Items->Items[selectedSD1]->Caption);
TURB *Drivers_RB=getDrivers_RB("Кассы");

  if(Drivers_RB==NULL) return;
  Drivers_RB->ShowModal();
  delete Drivers_RB;
        
}
//---------------------------------------------------------------------------


void __fastcall TMainForm::PCClick(TObject *Sender)
{
setMainHeader();
LoadWorkDS(getSD_ID(),getID());
}
//---------------------------------------------------------------------------



void __fastcall TMainForm::N9Click(TObject *Sender)
{
TExpensesListOnAutoForm *EAF;

  try
  {
    EAF=new TExpensesListOnAutoForm(this);
  }
  catch (Exception &exc)
  { MessageDlg("Ошибка создания формы ExpensesListOnAutoForm\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
    return;
  }
  EAF->ShowModal();
  delete EAF;
        
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::N12Click(TObject *Sender)
{
TExpensesListOnDateForm *EDF;

  try
  {
    EDF=new TExpensesListOnDateForm(this);
  }
  catch (Exception &exc)
  { MessageDlg("Ошибка создания формы ExpensesListOnDateForm\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
    return;
  }
  EDF->ShowModal();
  delete EDF;
}
//---------------------------------------------------------------------------


void __fastcall TMainForm::N15Click(TObject *Sender)
{
TExpensesListOnAutoForm1 *EAF;

  try
  {
    EAF=new TExpensesListOnAutoForm1(this);
  }
  catch (Exception &exc)
  { MessageDlg("Ошибка создания формы ExpensesListOnAutoForm1\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
    return;
  }
  EAF->ShowModal();
  delete EAF;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::N16Click(TObject *Sender)
{
TExpensesListOnAutoForm2 *EAF;

  try
  {
    EAF=new TExpensesListOnAutoForm2(this);
  }
  catch (Exception &exc)
  { MessageDlg("Ошибка создания формы ExpensesListOnAutoForm2\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
    return;
  }
  EAF->ShowModal();
  delete EAF;

}
//---------------------------------------------------------------------------

void __fastcall TMainForm::workGridDblClick(TObject *Sender)
{
if (workDS->FieldByName("EDITABLE")->AsInteger==1)
{
if (GSM_DM->UserRole!="администратор") editItemClick(this);
}
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::CheckBox1Click(TObject *Sender)
{
setMainHeader();        
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::N10Click(TObject *Sender)
{
TFormParamProg *FPG;

  try
  {
    FPG=new TFormParamProg(this);
  }
  catch (Exception &exc)
  { MessageDlg("Ошибка создания формы FormParamProg\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
    return;
  }
  if(FPG->ShowModal()==mrOk)
  {
   odpp=FPG->JvEdit1->Text;
   fio=FPG->JvEdit2->Text;
   tel=FPG->JvEdit3->Text;
   email=FPG->JvEdit4->Text;
  }
delete FPG;
}

//---------------------------------------------------------------------------

void __fastcall TMainForm::workGrid2DblClick(TObject *Sender)
{
if (workDS2->FieldByName("EDITABLE")->AsInteger==1)
{
if (GSM_DM->UserRole!="администратор") editItemClick(this);
}

}
//---------------------------------------------------------------------------

void __fastcall TMainForm::workGrid1DblClick(TObject *Sender)
{
if (workDS1->FieldByName("EDITABLE")->AsInteger==1)
{
if (GSM_DM->UserRole!="администратор") editItemClick(this);
}
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::workGrid1SortMarkingChanged(TObject *Sender)
{
  AnsiString fn;
  fn=workGrid1->SortMarkedColumns->Items[0]->FieldName;

  if(fn=="ID")
  { if(workGrid1->SortMarkedColumns->Items[0]->Title->SortMarker==smDownEh) sortString=" order by e.ID descending";
    else  sortString=" order by e.ID";
  }
  else if(fn=="EXP_DATE")
  { if(workGrid1->SortMarkedColumns->Items[0]->Title->SortMarker==smDownEh) sortString=" order by e.EXP_DATE descending, e.ID";
    else sortString=" order by e.EXP_DATE, e.ID";
  }
  else if(fn=="WAYBILL_NUMBER")
  { if(workGrid1->SortMarkedColumns->Items[0]->Title->SortMarker==smDownEh) sortString=" order by WAYBILL_NUMBER descending";
    else sortString=" order by WAYBILL_NUMBER";
  }
  else if(fn=="ELECTRONIC_CARD")
  { if(workGrid1->SortMarkedColumns->Items[0]->Title->SortMarker==smDownEh) sortString=" order by ec.DESCRIPTION descending";
    else sortString=" order by ec.DESCRIPTION";
  }
  else if(fn=="AUTO")
  { if(workGrid1->SortMarkedColumns->Items[0]->Title->SortMarker==smDownEh) sortString=" order by a.DESCRIPTION descending, EXP_DATE";
    else sortString=" order by a.DESCRIPTION, EXP_DATE";
  }
  else if(fn=="DRIVER")
  { if(workGrid1->SortMarkedColumns->Items[0]->Title->SortMarker==smDownEh) sortString=" order by d.DESCRIPTION descending, EXP_DATE";
    else sortString=" order by d.DESCRIPTION, EXP_DATE";
  }
  else if(fn=="GSM")
  { if(workGrid1->SortMarkedColumns->Items[0]->Title->SortMarker==smDownEh) sortString=" order by m.DESCRIPTION descending, EXP_DATE";
    else sortString=" order by m.DESCRIPTION, EXP_DATE";
  }
  else if(fn=="EXPENSE")
  { if(workGrid1->SortMarkedColumns->Items[0]->Title->SortMarker==smDownEh) sortString=" order by EXPENSE descending, EXP_DATE";
    else sortString=" order by EXPENSE, EXP_DATE";
  }
  else if(fn=="KOL")
  { if(workGrid1->SortMarkedColumns->Items[0]->Title->SortMarker==smDownEh) sortString=" order by KOL descending, EXP_DATE";
    else sortString=" order by EXPENSE, EXP_DATE";
  }
  int id=workDS1->FieldByName("ID")->AsInteger;
  LoadWorkDS(getSD_ID(),getID());
  TLocateOptions lo; lo.Clear();
  workDS1->Locate("ID", id, lo);

}
//---------------------------------------------------------------------------

void __fastcall TMainForm::workGrid2SortMarkingChanged(TObject *Sender)
{
  AnsiString fn;
  fn=workGrid2->SortMarkedColumns->Items[0]->FieldName;

  if(fn=="ID")
  { if(workGrid2->SortMarkedColumns->Items[0]->Title->SortMarker==smDownEh) sortString=" order by e.ID descending";
    else  sortString=" order by e.ID";
  }
  else if(fn=="EXP_DATE")
  { if(workGrid2->SortMarkedColumns->Items[0]->Title->SortMarker==smDownEh) sortString=" order by e.EXP_DATE descending, e.ID";
    else sortString=" order by e.EXP_DATE, e.ID";
  }
  else if(fn=="WAYBILL_NUMBER")
  { if(workGrid2->SortMarkedColumns->Items[0]->Title->SortMarker==smDownEh) sortString=" order by WAYBILL_NUMBER descending";
    else sortString=" order by WAYBILL_NUMBER";
  }
  else if(fn=="ELECTRONIC_CARD")
  { if(workGrid2->SortMarkedColumns->Items[0]->Title->SortMarker==smDownEh) sortString=" order by ec.DESCRIPTION descending";
    else sortString=" order by ec.DESCRIPTION";
  }
  else if(fn=="AUTO")
  { if(workGrid2->SortMarkedColumns->Items[0]->Title->SortMarker==smDownEh) sortString=" order by a.DESCRIPTION descending, EXP_DATE";
    else sortString=" order by a.DESCRIPTION, EXP_DATE";
  }
  else if(fn=="DRIVER")
  { if(workGrid2->SortMarkedColumns->Items[0]->Title->SortMarker==smDownEh) sortString=" order by d.DESCRIPTION descending, EXP_DATE";
    else sortString=" order by d.DESCRIPTION, EXP_DATE";
  }
  else if(fn=="GSM")
  { if(workGrid2->SortMarkedColumns->Items[0]->Title->SortMarker==smDownEh) sortString=" order by m.DESCRIPTION descending, EXP_DATE";
    else sortString=" order by m.DESCRIPTION, EXP_DATE";
  }
  else if(fn=="EXPENSE")
  { if(workGrid2->SortMarkedColumns->Items[0]->Title->SortMarker==smDownEh) sortString=" order by EXPENSE descending, EXP_DATE";
    else sortString=" order by EXPENSE, EXP_DATE";
  }
  else if(fn=="KOL")
  { if(workGrid2->SortMarkedColumns->Items[0]->Title->SortMarker==smDownEh) sortString=" order by KOL descending, EXP_DATE";
    else sortString=" order by EXPENSE, EXP_DATE";
  }
  int id=workDS2->FieldByName("ID")->AsInteger;
  LoadWorkDS(getSD_ID(),getID());
  TLocateOptions lo; lo.Clear();
  workDS2->Locate("ID", id, lo);

}
//---------------------------------------------------------------------------

void __fastcall TMainForm::workGridDrawColumnCell(TObject *Sender,
      const TRect &Rect, int DataCol, TColumnEh *Column,
      TGridDrawState State)
{
if (workDS->FieldByName("EDITABLE")->AsInteger==1)
{
 if (workDS->FieldByName("D")->AsInteger==1)
 {
 workGrid->Canvas->Brush->Color=clYellow;
 workGrid->Canvas->Font->Color=clRed;
 workGrid->DefaultDrawColumnCell(Rect,DataCol,Column,State);
 }else
 {
 workGrid->Canvas->Brush->Color=clTeal;
 workGrid->Canvas->Font->Color=clWhite;
 workGrid->DefaultDrawColumnCell(Rect,DataCol,Column,State);
 }
}else
{
workGrid->Canvas->Brush->Color=clSilver;
workGrid->Canvas->Font->Color=clBlack;
workGrid->DefaultDrawColumnCell(Rect,DataCol,Column,State);
}
workGrid->DefaultDrawColumnCell(Rect,DataCol,Column,State);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::workGrid1DrawColumnCell(TObject *Sender,
      const TRect &Rect, int DataCol, TColumnEh *Column,
      TGridDrawState State)
{
if (workDS1->FieldByName("EDITABLE")->AsInteger==1)
{
workGrid1->Canvas->Brush->Color=clTeal;
workGrid1->Canvas->Font->Color=clWhite;
workGrid1->DefaultDrawColumnCell(Rect,DataCol,Column,State);
}else
{
workGrid1->Canvas->Brush->Color=clSilver;
workGrid1->Canvas->Font->Color=clBlack;
workGrid1->DefaultDrawColumnCell(Rect,DataCol,Column,State);
}
workGrid1->DefaultDrawColumnCell(Rect,DataCol,Column,State);

}
//---------------------------------------------------------------------------

void __fastcall TMainForm::workGrid2DrawColumnCell(TObject *Sender,
      const TRect &Rect, int DataCol, TColumnEh *Column,
      TGridDrawState State)
{
if (workDS2->FieldByName("EDITABLE")->AsInteger==1)
{
workGrid2->Canvas->Brush->Color=clTeal;
workGrid2->Canvas->Font->Color=clWhite;
workGrid2->DefaultDrawColumnCell(Rect,DataCol,Column,State);
}else
{
workGrid2->Canvas->Brush->Color=clSilver;
workGrid2->Canvas->Font->Color=clBlack;
workGrid2->DefaultDrawColumnCell(Rect,DataCol,Column,State);
}
workGrid2->DefaultDrawColumnCell(Rect,DataCol,Column,State);

}
//---------------------------------------------------------------------------


void __fastcall TMainForm::workGridCellClick(TColumnEh *Column)
{
int index = autoNumberEdit->ItemIndex;
AnsiString OPS=autoID->Strings[index];

if (Date1 == Date2)
{
if (GSM_DM->UserRole!="администратор" && GSM_DM->UserRole!="руководитель") reloadButton->Enabled=true; else reloadButton->Enabled=false; 
}else
{
reloadButton->Enabled=false;
}

if (workGrid->Focused())
{
//workGrid->Color=clGreen;
//workGrid4->Color=clWhite;
//workGrid5->Color=clWhite;

 if (OPS.Trim()!="0" && selectedSD >0)
 {

   if (GSM_DM->UserRole!="администратор" && GSM_DM->UserRole!="руководитель" && Date1 == Date2)
   {
   ImportButton->Enabled = true;
   ScanButton->Enabled = true;
   impItem->Visible = true;
   }else
   {
   ImportButton->Enabled = false;
   ScanButton->Enabled = false;
   impItem->Visible = false;
   }


   if (workDS->FieldByName("EDITABLE")->AsInteger==1 && Date1 == Date2)
   {
   if (GSM_DM->UserRole!="администратор")
   {
   DeleteButton->Enabled = true;
   EditButton->Enabled = true;
   delItem->Visible = true;
   editItem->Visible = true;
   }else
   {
   DeleteButton->Enabled = false;
   EditButton->Enabled = false;
   delItem->Visible = false;
   editItem->Visible = false;
   }
   }
   else
   {
//   ImportButton->Enabled = false;
//   impItem->Visible = false;
    if((Date1 >= Date() && Date2 >= Date()))
    {
     if (GSM_DM->UserRole!="администратор")
     {
     AddButton->Enabled = true;
     addItem->Visible = true;
     }else
     {
     AddButton->Enabled = false;
     addItem->Visible = false;
     }
    }else
    {
    AddButton->Enabled = false;
    addItem->Visible = false;
    }
   }
   if (workDS->FieldByName("EDITABLE")->AsInteger==1)
   {
    if (workDS->RecordCount > 0) {
     if (GSM_DM->UserRole!="администратор") {
    DeleteButton->Enabled = true;
    EditButton->Enabled = true;
    delItem->Visible = true;
    editItem->Visible = true;
    AddButton->Enabled = true;
    addItem->Visible = true;
    }
    }
   }
   else
   {
    DeleteButton->Enabled = false;
    EditButton->Enabled = false;
    delItem->Visible = false;
    editItem->Visible = false;
    AddButton->Enabled = true;
    addItem->Visible = true;
   }
 }
 else
 {
// workGrid->Color=clWhite;
// workGrid4->Color=clWhite;
// workGrid5->Color=clWhite;
 ImportButton->Enabled = false;
 ScanButton->Enabled = false;
 impItem->Visible = false;
 AddButton->Enabled =false;
 DeleteButton->Enabled=false;
 EditButton->Enabled = false;
 editItem->Visible = false;
 addItem->Visible = false;
 delItem->Visible = false;
 }
}
}

//---------------------------------------------------------------------------

void __fastcall TMainForm::workGrid1CellClick(TColumnEh *Column)
{
int index = autoNumberEdit->ItemIndex;
AnsiString OPS=autoID->Strings[index];

ImportButton->Enabled = false;
ScanButton->Enabled = false;
impItem->Visible = false;

if (Date1 == Date2)
{
if (GSM_DM->UserRole!="администратор" && GSM_DM->UserRole!="руководитель") reloadButton->Enabled=true; else reloadButton->Enabled=false; 
}else
{
reloadButton->Enabled=false;
}

if (workGrid1->Focused())
{
//workGrid1->Color=clGreen;
 if (OPS.Trim()!="0" && selectedSD1 >0)
 {

   if (GSM_DM->UserRole!="администратор" && GSM_DM->UserRole!="руководитель" && Date1 == Date2)
   {
   ImportButton->Enabled = true;
   ScanButton->Enabled = true;
   impItem->Visible = true;
   }else
   {
   ImportButton->Enabled = false;
   ScanButton->Enabled = false;
   impItem->Visible = false;
   }

   if (workDS1->FieldByName("EDITABLE")->AsInteger==1 && Date1 == Date2)
   {
   if (GSM_DM->UserRole!="администратор")
   {
   DeleteButton->Enabled = true;
   EditButton->Enabled = true;
   delItem->Visible = true;
   editItem->Visible = true;
   }else
   {
   DeleteButton->Enabled = false;
   EditButton->Enabled = false;
   delItem->Visible = false;
   editItem->Visible = false;
   }
   }
   else
   {
    if(Date1 >= Date() && Date2 >= Date())
    {
   if (GSM_DM->UserRole!="администратор")
   {
   AddButton->Enabled = true;
   addItem->Visible = true;
   }else
   {
   AddButton->Enabled = false;
   addItem->Visible = false;
   }
    }
   }
   if (workDS1->FieldByName("EDITABLE")->AsInteger==1)
   {
    if (workDS1->RecordCount > 0) {
     if (GSM_DM->UserRole!="администратор") {
    DeleteButton->Enabled = true;
    EditButton->Enabled = true;
    delItem->Visible = true;
    editItem->Visible = true;
    AddButton->Enabled = true;
    addItem->Visible = true;
    }}
   }
   else
   {
    DeleteButton->Enabled = false;
    EditButton->Enabled = false;
    delItem->Visible = false;
    editItem->Visible = false;
    AddButton->Enabled = true;
    addItem->Visible = true;
   }
 }
 else
 {
// workGrid1->Color=clWhite;
 ImportButton->Enabled = false;
 ScanButton->Enabled = false;
 impItem->Visible = false;
 AddButton->Enabled =false;
 DeleteButton->Enabled=false;
 EditButton->Enabled = false;
 editItem->Visible = false;
 addItem->Visible = false;
 delItem->Visible = false;
 }
}
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::workGrid2CellClick(TColumnEh *Column)
{

ImportButton->Enabled = false;
ScanButton->Enabled = false;
impItem->Visible = false;
reloadButton->Enabled=false;

if (workGrid2->Focused())
{
//workGrid2->Color=clGreen;

   if (workDS2->FieldByName("EDITABLE")->AsInteger==1 && Date1 == Date2)
   {
     if (GSM_DM->UserRole!="администратор")
     {
     EditButton->Enabled = true;
     DeleteButton->Enabled = true;
     delItem->Visible = true;
     editItem->Visible = true;
     }else
     {
     EditButton->Enabled = false;
     DeleteButton->Enabled = false;
     delItem->Visible = false;
     editItem->Visible = false;
     }
   }
   else
   {
    if(Date1 == Date() && Date2 == Date())
    {
     if (GSM_DM->UserRole!="администратор")
     {
     AddButton->Enabled = true;
     addItem->Visible = true;
     }else
     {
     AddButton->Enabled = false;
     addItem->Visible = false;
     }
   }
   if (workDS2->FieldByName("EDITABLE")->AsInteger==1)
   {
    if (workDS2->RecordCount > 0) {
     if (GSM_DM->UserRole!="администратор") {
    DeleteButton->Enabled = true;
    EditButton->Enabled = true;
    delItem->Visible = true;
    editItem->Visible = true;
    AddButton->Enabled = true;
    addItem->Visible = true;
    } }
   }
   else
   {
    DeleteButton->Enabled = false;
    EditButton->Enabled = false;
    delItem->Visible = false;
    AddButton->Enabled = true;
    addItem->Visible = true;
    editItem->Visible = false;
   }
  }
 }
 else
 {
// workGrid1->Color=clWhite;
 ImportButton->Enabled = false;
 ScanButton->Enabled = false;
 impItem->Visible = false;
 AddButton->Enabled =false;
 DeleteButton->Enabled=false;
 EditButton->Enabled = false;
 editItem->Visible = false;
 addItem->Visible = false;
 delItem->Visible = false;
 }
}

//---------------------------------------------------------------------------

void __fastcall TMainForm::N13Click(TObject *Sender)
{
TExpensesListOnAutoForm3 *EAF;

  try
  {
    EAF=new TExpensesListOnAutoForm3(this);
  }
  catch (Exception &exc)
  { MessageDlg("Ошибка создания формы ExpensesListOnAutoForm3\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
    return;
  }
  EAF->ShowModal();
  delete EAF;

}
//---------------------------------------------------------------------------

void __fastcall TMainForm::N14Click(TObject *Sender)
{
TExpensesListOnAutoForm4 *EAF;

  try
  {
    EAF=new TExpensesListOnAutoForm4(this);
  }
  catch (Exception &exc)
  {
    MessageDlg("Ошибка создания формы ExpensesListOnAutoForm4\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
    return;
  }
  EAF->ShowModal();
  delete EAF;

}
//---------------------------------------------------------------------------

void __fastcall TMainForm::T(TObject *Sender)
{
AddButton->Enabled =false;
DeleteButton->Enabled=false;
EditButton->Enabled=false;
editItem->Visible = false;
addItem->Visible = false;
delItem->Visible = false;

//  initMainForm();
  LoadWorkDS(getSD_ID(),getID());
  setMainHeader();
}

//---------------------------------------------------------------------------


void __fastcall TMainForm::workGrid4CellClick(TColumnEh *Column)
{
// TEMPLATE
int index = autoNumberEdit->ItemIndex;
AnsiString OPS=autoID->Strings[index];

ImportButton->Enabled = false;
ScanButton->Enabled = false;
impItem->Visible = false;

if (Date1 == Date2)
{
if (GSM_DM->UserRole!="администратор" && GSM_DM->UserRole!="руководитель") reloadButton->Enabled=true; else reloadButton->Enabled=false; 
}else
{
reloadButton->Enabled=false;
}


if (workGrid4->Focused())
{
//workGrid->Color=clWhite;
//workGrid4->Color=clGreen;
//workGrid5->Color=clWhite;

 if (OPS.Trim()!="0" && selectedSD >0)
 {


    if (GSM_DM->UserRole!="администратор" && GSM_DM->UserRole!="руководитель" && Date1 == Date2)
   {
   ImportButton->Enabled = true;
   ScanButton->Enabled = true;
   impItem->Visible = true;
   }else
   {
   ImportButton->Enabled = false;
   ScanButton->Enabled = false;
   impItem->Visible = false;
   }

   if (workDS3->FieldByName("EDITABLE")->AsInteger==1 && Date1 == Date2)
   {
   if (GSM_DM->UserRole!="администратор")
   {
   DeleteButton->Enabled = true;
   EditButton->Enabled = true;
   delItem->Visible = true;
   editItem->Visible = true;
   }else
   {
   DeleteButton->Enabled = false;
   EditButton->Enabled = false;
   delItem->Visible = false;
   editItem->Visible = false;
   }
   }
   else
   {
    if((Date1 >= Date() && Date2 >= Date()))
    {
     if (GSM_DM->UserRole!="администратор")
     {
     AddButton->Enabled = true;
     addItem->Visible = true;
     }else
     {
     AddButton->Enabled = false;
     addItem->Visible = false;
     }
    }else
    {
    AddButton->Enabled = false;
    addItem->Visible = false;
    }
   }
   if (workDS3->FieldByName("EDITABLE")->AsInteger==1)
   {
    if (workDS3->RecordCount > 0) {
     if (GSM_DM->UserRole!="администратор") {
    DeleteButton->Enabled = true;
    EditButton->Enabled = true;
    delItem->Visible = true;
    editItem->Visible = true;
    AddButton->Enabled = true;
    addItem->Visible = true;
    }}
   }
   else
   {
    DeleteButton->Enabled = false;
    EditButton->Enabled = false;
    delItem->Visible = false;
    editItem->Visible = false;
    AddButton->Enabled = true;
    addItem->Visible = true;
   }
 }
 else
 {
// workGrid->Color=clWhite;
// workGrid4->Color=clWhite;
// workGrid5->Color=clWhite;
 ImportButton->Enabled = false;
 ScanButton->Enabled = false;
 impItem->Visible = false;
 AddButton->Enabled =false;
 DeleteButton->Enabled=false;
 EditButton->Enabled = false;
 editItem->Visible = false;
 addItem->Visible = false;
 delItem->Visible = false;
 }
}
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::workGrid4DblClick(TObject *Sender)
{
if (workDS3->FieldByName("EDITABLE")->AsInteger==1)
{
if (GSM_DM->UserRole!="администратор") editItemClick(this);
}
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::workGrid4DrawColumnCell(TObject *Sender,
      const TRect &Rect, int DataCol, TColumnEh *Column,
      TGridDrawState State)
{
if (workDS3->FieldByName("EDITABLE")->AsInteger==1)
{
workGrid4->Canvas->Brush->Color=clTeal;
workGrid4->Canvas->Font->Color=clWhite;
workGrid4->DefaultDrawColumnCell(Rect,DataCol,Column,State);
}else
{
workGrid4->Canvas->Brush->Color=clSilver;
workGrid4->Canvas->Font->Color=clBlack;
workGrid4->DefaultDrawColumnCell(Rect,DataCol,Column,State);
}
workGrid4->DefaultDrawColumnCell(Rect,DataCol,Column,State);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::workGrid4KeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
  if(Key == VK_F11)
  { TRect r=workGrid->CellRect(workGrid->Col,workGrid->Row);
    int x=this->Left+r.Left+r.Width();
    int y=this->Top+workGrid->Top+r.Top+r.Height()+15;
//    Mouse->CursorPos=TPoint(x,y);
    Mouse->CursorPos=TPoint(x+30,y+5);
    workGridPM->Popup(x,y);
    Mouse->CursorPos=TPoint(x,y);
  }
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::workGrid4KeyPress(TObject *Sender, char &Key)
{
  if(workGrid->Col!=3 && workGrid->Col!=4  && workGrid->Col!=5  && workGrid->Col!=6) return;
  int c=Key&127;
  if(isalnum(c) || c==64)
  { SEdit->Clear();
    AnsiString s=SEdit->Text+Key;
    Key=0;
    SEdit->Text=s;
    SEdit->SetFocus(); SEdit->SelStart=SEdit->GetTextLen();
  }
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::workGrid4SortMarkingChanged(TObject *Sender)
{
  AnsiString fn;
  fn=workGrid4->SortMarkedColumns->Items[0]->FieldName;

  if(fn=="ID")
  { if(workGrid4->SortMarkedColumns->Items[0]->Title->SortMarker==smDownEh) sortString1=" order by e.ID descending";
    else  sortString1=" order by e.ID";
  }
  else if(fn=="EXP_DATE")
  { if(workGrid4->SortMarkedColumns->Items[0]->Title->SortMarker==smDownEh) sortString1=" order by e.EXP_DATE descending, e.ID";
    else sortString1=" order by e.EXP_DATE, e.ID";
  }
  else if(fn=="WAYBILL_NUMBER")
  { if(workGrid4->SortMarkedColumns->Items[0]->Title->SortMarker==smDownEh) sortString1=" order by WAYBILL_NUMBER descending";
    else sortString1=" order by WAYBILL_NUMBER";
  }
  else if(fn=="ELECTRONIC_CARD")
  { if(workGrid4->SortMarkedColumns->Items[0]->Title->SortMarker==smDownEh) sortString1=" order by ec.DESCRIPTION descending";
    else sortString1=" order by ec.DESCRIPTION";
  }
  else if(fn=="AUTO")
  { if(workGrid4->SortMarkedColumns->Items[0]->Title->SortMarker==smDownEh) sortString1=" order by a.DESCRIPTION descending, EXP_DATE";
    else sortString1=" order by a.DESCRIPTION, EXP_DATE";
  }
  else if(fn=="DRIVER")
  { if(workGrid4->SortMarkedColumns->Items[0]->Title->SortMarker==smDownEh) sortString1=" order by d.DESCRIPTION descending, EXP_DATE";
    else sortString1=" order by d.DESCRIPTION, EXP_DATE";
  }
  else if(fn=="GSM")
  { if(workGrid4->SortMarkedColumns->Items[0]->Title->SortMarker==smDownEh) sortString1=" order by m.DESCRIPTION descending, EXP_DATE";
    else sortString1=" order by m.DESCRIPTION, EXP_DATE";
  }
  else if(fn=="EXPENSE")
  { if(workGrid4->SortMarkedColumns->Items[0]->Title->SortMarker==smDownEh) sortString1=" order by EXPENSE descending, EXP_DATE";
    else sortString1=" order by EXPENSE, EXP_DATE";
  }
  else if(fn=="KOL")
  { if(workGrid4->SortMarkedColumns->Items[0]->Title->SortMarker==smDownEh) sortString1=" order by KOL descending, EXP_DATE";
    else sortString1=" order by EXPENSE, EXP_DATE";
  }
  int id=workDS3->FieldByName("ID")->AsInteger;
  LoadWorkDS(getSD_ID(),getID());
  TLocateOptions lo; lo.Clear();
  workDS3->Locate("ID", id, lo);

}
//---------------------------------------------------------------------------

void __fastcall TMainForm::DBGridEh5CellClick(TColumnEh *Column)
{
if (workDS4->FieldByName("EDITABLE")->AsInteger==1)
{
EditButton->Enabled = true;
editItem->Visible = true;
}
else
{
EditButton->Enabled = false;
editItem->Visible = false;
}

}
//---------------------------------------------------------------------------


void __fastcall TMainForm::workGrid5DrawColumnCell(TObject *Sender,
      const TRect &Rect, int DataCol, TColumnEh *Column,
      TGridDrawState State)
{
if (workDS4->FieldByName("EDITABLE")->AsInteger==1)
{
workGrid5->Canvas->Brush->Color=clTeal;
workGrid5->Canvas->Font->Color=clWhite;
workGrid5->DefaultDrawColumnCell(Rect,DataCol,Column,State);
}else
{
if (workDS4->FieldByName("EXPENSE")->AsFloat >=0.00 && workDS4->FieldByName("KOL")->AsInteger >=0)
{
workGrid4->Canvas->Brush->Color=clSilver;
workGrid4->Canvas->Font->Color=clBlack;
workGrid4->DefaultDrawColumnCell(Rect,DataCol,Column,State);
}else
{
workGrid5->Canvas->Brush->Color=clRed;
workGrid5->Canvas->Font->Color=clBlack;
workGrid5->DefaultDrawColumnCell(Rect,DataCol,Column,State);
}
}
workGrid5->DefaultDrawColumnCell(Rect,DataCol,Column,State);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::workGrid5SortMarkingChanged(TObject *Sender)
{
  AnsiString fn;
  fn=workGrid5->SortMarkedColumns->Items[0]->FieldName;

  if(fn=="ID")
  { if(workGrid5->SortMarkedColumns->Items[0]->Title->SortMarker==smDownEh) sortString2=" order by e.ID descending";
    else  sortString2=" order by e.ID";
  }
  else if(fn=="EXP_DATE")
  { if(workGrid5->SortMarkedColumns->Items[0]->Title->SortMarker==smDownEh) sortString2=" order by e.EXP_DATE descending, e.ID";
    else sortString2=" order by e.EXP_DATE, e.ID";
  }
  else if(fn=="WAYBILL_NUMBER")
  { if(workGrid5->SortMarkedColumns->Items[0]->Title->SortMarker==smDownEh) sortString2=" order by WAYBILL_NUMBER descending";
    else sortString2=" order by WAYBILL_NUMBER";
  }
  else if(fn=="ELECTRONIC_CARD")
  { if(workGrid5->SortMarkedColumns->Items[0]->Title->SortMarker==smDownEh) sortString2=" order by ec.DESCRIPTION descending";
    else sortString2=" order by ec.DESCRIPTION";
  }
  else if(fn=="AUTO")
  { if(workGrid5->SortMarkedColumns->Items[0]->Title->SortMarker==smDownEh) sortString2=" order by a.DESCRIPTION descending, EXP_DATE";
    else sortString2=" order by a.DESCRIPTION, EXP_DATE";
  }
  else if(fn=="DRIVER")
  { if(workGrid5->SortMarkedColumns->Items[0]->Title->SortMarker==smDownEh) sortString2=" order by d.DESCRIPTION descending, EXP_DATE";
    else sortString2=" order by d.DESCRIPTION, EXP_DATE";
  }
  else if(fn=="GSM")
  { if(workGrid5->SortMarkedColumns->Items[0]->Title->SortMarker==smDownEh) sortString2=" order by m.DESCRIPTION descending, EXP_DATE";
    else sortString2=" order by m.DESCRIPTION, EXP_DATE";
  }
  else if(fn=="EXPENSE")
  { if(workGrid5->SortMarkedColumns->Items[0]->Title->SortMarker==smDownEh) sortString2=" order by EXPENSE descending, EXP_DATE";
    else sortString2=" order by EXPENSE, EXP_DATE";
  }
  else if(fn=="KOL")
  { if(workGrid5->SortMarkedColumns->Items[0]->Title->SortMarker==smDownEh) sortString2=" order by KOL descending, EXP_DATE";
    else sortString2=" order by EXPENSE, EXP_DATE";
  }
  int id=workDS4->FieldByName("ID")->AsInteger;
  LoadWorkDS(getSD_ID(),getID());
  TLocateOptions lo; lo.Clear();
  workDS4->Locate("ID", id, lo);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::RashetWorkDS(void)
{
TpFIBQuery *Q=GSM_DM->WQ;
TpFIBQuery *QR=GSM_DM->RQ;
AnsiString sql;
int flag;
int fkassa;
AnsiString typeoper;
int idexp=0;
AnsiString strras,strpr;
double sumexppr,sumexpras,itexp;
int    sumkolpr,sumkolras,itkol;

sumexppr=0.0;
sumexpras=0.0;
itexp=0.0;
sumkolpr=0;
sumkolras=0;
itkol=0;
flag=0;
fkassa=0;

if(PC->ActivePageIndex == 0 || PC->ActivePageIndex == 1) flag=1;
if(PC->ActivePageIndex == 2) flag=2;
if(PC->ActivePageIndex == 0 ) fkassa=1;
if(PC->ActivePageIndex == 1 || PC->ActivePageIndex == 2) fkassa=0;


    // полный перерасчет!!!

if (workGrid->Focused())
{
if(workDS->Active==false) workDS->Active=true;
workDS->First();
while(!workDS->Eof)
{
    int sd_id=workDS->FieldByName("SD_ID")->AsInteger;
    int id_oper=workDS->FieldByName("GSM_ID")->AsInteger;
    TDateTime Dater=workDS->FieldByName("EXP_DATE")->AsDateTime;
    int id_ops=workDS->FieldByName("DRIVER_ID")->AsInteger;
    int kol=workDS->FieldByName("KOL")->AsInteger;
    double exp=workDS->FieldByName("EXPENSE")->AsFloat;

    switch (id_oper) {
      case 17: case 36: { typeoper="73"; break; }
      case 3:  case 37: { typeoper="74"; break; }
      case 6:  case 35: { typeoper="75"; break; }
      case 42: case 39: { typeoper="77"; break; }
      case 43: case 44: { typeoper="78"; break; }
      default: typeoper="0";
    }
    sql=" select ID as IDEXP from EXPENSES_TABLE ";
    sql+=" where EXP_DATE = '"+Dater.DateString()+"'";
    sql+=" and SD_ID="+IntToStr(sd_id);
    sql+=" and DRIVER_ID="+IntToStr(id_ops);
    sql+=" and GSM_ID="+typeoper.Trim();
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
    {
      MessageDlg("Ошибка - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
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
    sql+="'"+Dater.DateString()+"',";
    sql+=IntToStr(sd_id)+",";
    sql+=IntToStr(id_ops)+",";
    sql+=typeoper.Trim()+",";
    sql+=IntToStr(kol)+",";
    sql+=FloatToStr(exp)+",";
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
    f(id,typeoper.Trim(),Dater,sd_id,id_ops);
}
else
{
    f(idexp,typeoper.Trim(),Dater,sd_id,id_ops);
}
workDS->Next();
}
}

if (workGrid4->Focused())
{
if(workDS3->Active==false) workDS3->Active=true;
workDS3->First();
while(!workDS3->Eof)
{
    int sd_id=workDS3->FieldByName("SD_ID")->AsInteger;
    int id_oper=workDS3->FieldByName("GSM_ID")->AsInteger;
    TDateTime Dater=workDS3->FieldByName("EXP_DATE")->AsDateTime;
    int id_ops=workDS3->FieldByName("DRIVER_ID")->AsInteger;
    int kol=workDS3->FieldByName("KOL")->AsInteger;
    double exp=workDS3->FieldByName("EXPENSE")->AsFloat;

    switch (id_oper) {
      case 17: case 36: { typeoper="73"; break; }
      case 3:  case 37: { typeoper="74"; break; }
      case 6:  case 35: { typeoper="75"; break; }
      case 42: case 39: { typeoper="77"; break; }
      case 43: case 44: { typeoper="78"; break; }
      default: typeoper="0";
    }
    sql=" select ID as IDEXP from EXPENSES_TABLE ";
    sql+=" where EXP_DATE = '"+Dater.DateString()+"'";
    sql+=" and SD_ID="+IntToStr(sd_id);
    sql+=" and DRIVER_ID="+IntToStr(id_ops);
    sql+=" and GSM_ID="+typeoper.Trim();
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
    {
      MessageDlg("Ошибка - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
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
    sql+="'"+Dater.DateString()+"',";
    sql+=IntToStr(sd_id)+",";
    sql+=IntToStr(id_ops)+",";
    sql+=typeoper.Trim()+",";
    sql+=IntToStr(kol)+",";
    sql+=FloatToStr(exp)+",";
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
    f(id,typeoper.Trim(),Dater,sd_id,id_ops);
}
else
{
    f(idexp,typeoper.Trim(),Dater,sd_id,id_ops);
}
workDS3->Next();
}
}



// удаление ненужных пустых !!!
    sql="";
    Q->Close();
    Q->SQL->Clear();
    sql="delete from EXPENSES_TABLE where GSM_ID IN (73,74,75,77) and KOL =0 and EXPENSE =0.0";
    if (GSM_DM->UserRole!="администратор" && GSM_DM->UserRole!="руководитель") sql+=" and U_ID="+IntToStr(GSM_DM->UserID);
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


// все записи об неоплатах блокируются

    Q->Close();
    Q->SQL->Clear();
    sql="update EXPENSES_TABLE set EDITABLE = 0 where GSM_ID IN (73,74,75,77)";
    if (GSM_DM->UserRole!="администратор" && GSM_DM->UserRole!="руководитель") sql+=" and U_ID="+IntToStr(GSM_DM->UserID);
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

void __fastcall TMainForm::f(int idrec, AnsiString toper,TDateTime Dater,int sd_id,int id_ops)
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

/*    if(itexp<0.00 && itkol < 0)
    {
    sql="delete from EXPENSES_TABLE  ";
    sql+=" where EXP_DATE = '"+Dater.DateString()+"'";
    sql+=" and SD_ID="+IntToStr(sd_id);
    sql+=" and DRIVER_ID="+IntToStr(id_ops);
    sql+=" and GSM_ID="+strras.Trim();
    if (GSM_DM->UserRole!="администратор" && GSM_DM->UserRole!="руководитель") sql+=" and U_ID="+IntToStr(GSM_DM->UserID);
    Q->Close();
    Q->SQL->Clear();
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
    }*/

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

// удаление ненужных пустых !!!
    sql="";
    Q->Close();
    Q->SQL->Clear();
    sql="delete from EXPENSES_TABLE where GSM_ID IN (73,74,75,77) and KOL =0 and EXPENSE =0.0";
//    if (GSM_DM->UserRole!="администратор" && GSM_DM->UserRole!="руководитель") sql+=" and U_ID="+IntToStr(GSM_DM->UserID);
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

void __fastcall TMainForm::N17Click(TObject *Sender)
{
TExpensesListOnAutoForm5 *EAF;

  try
  {
    EAF=new TExpensesListOnAutoForm5(this);
  }
  catch (Exception &exc)
  {
    MessageDlg("Ошибка создания формы ExpensesListOnAutoForm5\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
    return;
  }
  EAF->ShowModal();
  delete EAF;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::N22Click(TObject *Sender)
{
TFormF55 *EAF55;

  try
  {
    EAF55=new TFormF55(this);
  }
  catch (Exception &exc)
  {
    MessageDlg("Ошибка создания формы FormF55\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
    return;
  }
  EAF55->ShowModal();
  delete EAF55;

}
//---------------------------------------------------------------------------

void __fastcall TMainForm::workGrid5CellClick(TColumnEh *Column)
{
 ImportButton->Enabled = false;
 ScanButton->Enabled = false;
 reloadButton->Enabled = false;
 impItem->Visible = false;
 AddButton->Enabled =false;
 DeleteButton->Enabled=false;
 EditButton->Enabled = false;
 editItem->Visible = false;
 addItem->Visible = false;
 delItem->Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::increaseButtonClick(TObject *Sender)
{
int fontDPI;
TDBGridEh *grid=NULL;
TJvXPBar  *bar=NULL;

  if(workGrid->Focused()==true) grid=workGrid;
  if(workGrid4->Focused()==true) grid=workGrid4;
  if(workGrid5->Focused()==true) grid=workGrid5;
  if(workGrid1->Focused()==true) grid=workGrid1;
  if(workGrid2->Focused()==true) grid=workGrid2;
  if (selectSDBar->Focused()==true) bar=selectSDBar;
  if (selectSDBar1->Focused()==true) bar=selectSDBar1;
  if(bar!=NULL)
  {
  fontDPI=bar->Font->Size;
    if(fontDPI < 14)
    { fontDPI+=2;
      bar->Font->Size=fontDPI;
      bar->Repaint();
    }
  }
  if(grid!=NULL)
  { fontDPI=grid->Font->Size;
    if(fontDPI < 14)
    { fontDPI+=2;
      grid->Font->Size=fontDPI;
      grid->FooterFont->Size=fontDPI;
      grid->TitleFont->Size=fontDPI;
      grid->Repaint();
    }
  }
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::reduceButtonClick(TObject *Sender)
{
int fontDPI;
TDBGridEh *grid=NULL;
TJvXPBar  *bar=NULL;

  if(workGrid->Focused()==true) grid=workGrid;
  if(workGrid4->Focused()==true) grid=workGrid4;
  if(workGrid5->Focused()==true) grid=workGrid5;
  if(workGrid1->Focused()==true) grid=workGrid1;
  if(workGrid2->Focused()==true) grid=workGrid2;
  if (selectSDBar->Focused()==true) bar=selectSDBar;
  if (selectSDBar1->Focused()==true) bar=selectSDBar1;
  if(bar!=NULL)
  {
  fontDPI=selectSDBar->Font->Size;
    if(fontDPI > 8)
    { fontDPI-=2;
      bar->Font->Size=fontDPI;
      bar->Repaint();
    }
  }
  if(grid!=NULL)
  { fontDPI=grid->Font->Size;
    if(fontDPI > 8)
    { fontDPI-=2;
      grid->Font->Size=fontDPI;
      grid->FooterFont->Size=fontDPI;
      grid->TitleFont->Size=fontDPI;
      grid->Repaint();
    }
  }
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::impItemClick(TObject *Sender)
{
// здесь импорт данных из Инспектор по дате опс и доставщику

AnsiString ID;
int rn;
AnsiString sql;
TpFIBQuery *Q_INS=RQ_INS;
TpFIBQuery *Q=GSM_DM->WQ;
TpFIBQuery *Q_LOC=GSM_DM->RQ;
int idpost,idops,idopsp;
int indops,iduser;
AnsiString indexops,S;
unsigned short y,m,d;
double sexp1,sexp2,sexp3;
int kol1,kol2,kol3;
TDateTime dexp;
int idexp=0;
int pos1,pos2;
kol1=0;
kol2=0;
kol3=0;


if(PC->ActivePageIndex == 0) indexops=autoNumberEdit->Text.Trim();
if(PC->ActivePageIndex == 1) indexops=autoNumberEdit1->Text.Trim();

pos1=MainForm->IndexOps.Pos("жел");
pos2=MainForm->IndexOps.Pos("центр");

if (pos1==0 && pos2==0)
{
if (indexops.Length()>6)
{
MessageDlg("Смотрите пожалуйста внимательно!!! Выберите правильно ОПС из списка!!! Индекс должен содержать только цифры!!!",mtWarning,TMsgDlgButtons() << mbOK,0);
if(PC->ActivePageIndex == 0) autoNumberEdit->SetFocus();
if(PC->ActivePageIndex == 1) autoNumberEdit1->SetFocus();
return;
}
}


S=indexops.SubString(4,3);
indops=StrToInt(S);

if(Date1 == Date2)
{
dexp=Date1;
dexp.DecodeDate(&y,&m,&d);
}else
{
MessageDlg("Импорт данных из ИС Инспектор можно делать только за один день!!! Установите пожалуйста правильно период данных!!!",mtWarning,TMsgDlgButtons() << mbOK,0);
return;
}

if (workGrid->Focused()) ActivTable=1;
if (workGrid4->Focused()) ActivTable=2;
if (workGrid5->Focused()) ActivTable=3;
if (workGrid1->Focused()) ActivTable=4;
if (workGrid2->Focused()) ActivTable=5;

if(PC->ActivePageIndex == 0)
{
if (workGrid->Focused())  ID=workGrid->DataSource->DataSet->FieldByName("ID")->AsString;
if (workGrid4->Focused()) ID=workGrid4->DataSource->DataSet->FieldByName("ID")->AsString;
if (workGrid5->Focused()) ID=workGrid5->DataSource->DataSet->FieldByName("ID")->AsString;
}

if(PC->ActivePageIndex == 1) ID=workGrid1->DataSource->DataSet->FieldByName("ID")->AsString;
if(PC->ActivePageIndex == 2) ID=workGrid2->DataSource->DataSet->FieldByName("ID")->AsString;

if (workGrid->Focused())
{
if(MessageDlg("Вы уверены, что хотите получить данные из ИС ИНСПЕКТОР по  " + selectSDBar->Items->Items[selectedSD]->Caption + " и ОПС " + autoNumberEdit->Text.Trim() + " за " + AnsiString().sprintf("%02d-%02d-%d",d,m,y) + " ? \n ВНИМАНИЕ!!! При импорте старые записи безвозвратно удалятся!!!", mtConfirmation,TMsgDlgButtons() << mbOK << mbCancel,0)==mrOk)
{

kol1=0;
sexp1=0.00;
kol2=0;
sexp2=0.00;
kol3=0;
sexp3=0.00;

  Q_LOC->Close();
  Q_LOC->SQL->Clear();
  sql="select e.* from USERS_TABLE e";
  sql+=" where e.U_LOGIN='"+GSM_DM->UserLogin+"'";
  Q_LOC->SQL->Add(sql);
  try
  {
    Q_LOC->ExecQuery();
  }
  catch (Exception &exc)
  {
    MessageDlg("Ошибка - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
    return;
  }
  iduser=Q_LOC->FieldByName("IDINS")->AsInteger;
  Q_LOC->Close();

  // определить код кассы из справочника касс

  Q_LOC->Close();
  Q_LOC->SQL->Clear();
  sql="select e.* from OPS_TABLE e";
  sql+=" where e.DESCRIPTION = '"+selectSDBar->Items->Items[selectedSD]->Caption.Trim()+"'";
  Q_LOC->SQL->Add(sql);
  try
  {
    Q_LOC->ExecQuery();
  }
  catch (Exception &exc)
  {
    MessageDlg("Ошибка - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
    return;
  }
  idopsp=Q_LOC->FieldByName("ID")->AsInteger;
  idpost=Q_LOC->FieldByName("IDINS")->AsInteger;
  Q_LOC->Close();


  Q_LOC->Close();
  Q_LOC->SQL->Clear();
  sql="select e.* from OPS_TABLE e";
  sql+=" where e.DESCRIPTION = '"+autoNumberEdit->Text.Trim()+"'";
  sql+=" and e.FILE_ID="+IntToStr(idopsp);
  Q_LOC->SQL->Add(sql);
  try
  {
    Q_LOC->ExecQuery();
  }
  catch (Exception &exc)
  {
    MessageDlg("Ошибка - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
    return;
  }
  idops=Q_LOC->FieldByName("ID")->AsInteger;
  Q_LOC->Close();


  // определить выплаты всего общее and LCHET1 NOT IN ('Прошврем','раздел 1')

  Q_INS->Close();
  Q_INS->SQL->Clear();
  sql="select COUNT(s.LCHET) as kol , s.metka1 , s.fakt_chel from ACCOUNTS a left outer join SGB s on a.ORG_ID=s.ORG_ID";
  sql+=" and a.COUNT_DATE=s.COUNT_DATE and a.COUNT_NUMBER=s.COUNT_NUMBER";
  sql+=" where a.USER_ID="+IntToStr(iduser);
  sql+=" and s.FAKT_CHEL="+IntToStr(idpost);
  sql+=" and s.METKA1="+IntToStr(indops);
  sql+=" and s.FAKT_DAT="+IntToStr(d);
  sql+=" and s.LCHET1 NOT IN ('Прошврем','раздел 1')";
  sql+=" and a.M="+IntToStr(m);
  sql+=" and a.Y="+IntToStr(y);
  sql+=" group by s.metka1 , s.fakt_chel";
  Q_INS->SQL->Add(sql);
  try
  {
    Q_INS->ExecQuery();
  }
  catch (Exception &exc)
  {
    MessageDlg("Ошибка - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
    return;
  }
  kol1=Q_INS->FieldByName("KOL")->AsInteger;

  Q_INS->Close();
  Q_INS->SQL->Clear();
  sql="select SUM(s.SUMMA) as sumexp, COUNT(s.LCHET) as kol , s.metka1 , s.fakt_chel from ACCOUNTS a left outer join SGB s on a.ORG_ID=s.ORG_ID";
  sql+=" and a.COUNT_DATE=s.COUNT_DATE and a.COUNT_NUMBER=s.COUNT_NUMBER";
  sql+=" where a.USER_ID="+IntToStr(iduser);
  sql+=" and s.METKA1="+IntToStr(indops);
  sql+=" and s.FAKT_CHEL="+IntToStr(idpost);
  sql+=" and s.FAKT_DAT="+IntToStr(d);
  sql+=" and a.M="+IntToStr(m);
  sql+=" and a.Y="+IntToStr(y);
  sql+=" group by s.metka1 , s.fakt_chel";
  Q_INS->SQL->Add(sql);
  try
  {
    Q_INS->ExecQuery();
  }
  catch (Exception &exc)
  {
    MessageDlg("Ошибка - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
    return;
  }
  sexp1=Q_INS->FieldByName("SUMEXP")->AsFloat;



  // определить выплаты всего выплачено
  Q_INS->Close();
  Q_INS->SQL->Clear();
  sql="select SUM(s.SUMMA) as sumexp, COUNT(s.LCHET) as kol , s.metka1 , s.fakt_chel from ACCOUNTS a left outer join SGB s on a.ORG_ID=s.ORG_ID";
  sql+=" and a.COUNT_DATE=s.COUNT_DATE and a.COUNT_NUMBER=s.COUNT_NUMBER";
  sql+=" where a.USER_ID="+IntToStr(iduser);
  sql+=" and s.METKA1="+IntToStr(indops);
  sql+=" and s.FAKT_CHEL="+IntToStr(idpost);
  sql+=" and s.FAKT_DAT="+IntToStr(d);
  sql+=" and s.PRICH=''";
  sql+=" and s.LCHET1 NOT IN ('Прошврем','раздел 1')";
  sql+=" and a.M="+IntToStr(m);
  sql+=" and a.Y="+IntToStr(y);
  sql+=" group by s.metka1 , s.fakt_chel";
  Q_INS->SQL->Add(sql);
  try
  {
    Q_INS->ExecQuery();
  }
  catch (Exception &exc)
  {
    MessageDlg("Ошибка - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
    return;
  }
  kol2=Q_INS->FieldByName("KOL")->AsInteger;

  Q_INS->Close();
  Q_INS->SQL->Clear();
  sql="select SUM(s.SUMMA) as sumexp, COUNT(s.LCHET) as kol , s.metka1 , s.fakt_chel from ACCOUNTS a left outer join SGB s on a.ORG_ID=s.ORG_ID";
  sql+=" and a.COUNT_DATE=s.COUNT_DATE and a.COUNT_NUMBER=s.COUNT_NUMBER";
  sql+=" where a.USER_ID="+IntToStr(iduser);
  sql+=" and s.METKA1="+IntToStr(indops);
  sql+=" and s.FAKT_CHEL="+IntToStr(idpost);
  sql+=" and s.FAKT_DAT="+IntToStr(d);
  sql+=" and s.PRICH=''";
  sql+=" and a.M="+IntToStr(m);
  sql+=" and a.Y="+IntToStr(y);
  sql+=" group by s.metka1 , s.fakt_chel";
  Q_INS->SQL->Add(sql);
  try
  {
    Q_INS->ExecQuery();
  }
  catch (Exception &exc)
  {
    MessageDlg("Ошибка - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
    return;
  }
  sexp2=Q_INS->FieldByName("SUMEXP")->AsFloat;


  // определить выплаты всего неоплата

  Q_INS->Close();
  Q_INS->SQL->Clear();
  sql="select SUM(s.SUMMA) as sumexp, COUNT(s.LCHET) as kol , s.metka1 , s.fakt_chel from ACCOUNTS a left outer join SGB s on a.ORG_ID=s.ORG_ID";
  sql+=" and a.COUNT_DATE=s.COUNT_DATE and a.COUNT_NUMBER=s.COUNT_NUMBER";
  sql+=" where a.USER_ID="+IntToStr(iduser);
  sql+=" and s.METKA1="+IntToStr(indops);
  sql+=" and s.FAKT_CHEL="+IntToStr(idpost);
  sql+=" and s.FAKT_DAT="+IntToStr(d);
  sql+=" and s.LCHET1 NOT IN ('Прошврем','раздел 1')";
  sql+=" and s.PRICH<>''";
  sql+=" and a.M="+IntToStr(m);
  sql+=" and a.Y="+IntToStr(y);
  sql+=" group by s.metka1 , s.fakt_chel";
  Q_INS->SQL->Add(sql);
  try
  {
    Q_INS->ExecQuery();
  }
  catch (Exception &exc)
  {
    MessageDlg("Ошибка - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
    return;
  }
  kol3=Q_INS->FieldByName("KOL")->AsInteger;

  Q_INS->Close();
  Q_INS->SQL->Clear();
  sql="select SUM(s.SUMMA) as sumexp, COUNT(s.LCHET) as kol , s.metka1 , s.fakt_chel from ACCOUNTS a left outer join SGB s on a.ORG_ID=s.ORG_ID";
  sql+=" and a.COUNT_DATE=s.COUNT_DATE and a.COUNT_NUMBER=s.COUNT_NUMBER";
  sql+=" where a.USER_ID="+IntToStr(iduser);
  sql+=" and s.METKA1="+IntToStr(indops);
  sql+=" and s.FAKT_CHEL="+IntToStr(idpost);
  sql+=" and s.FAKT_DAT="+IntToStr(d);
  sql+=" and s.PRICH<>''";
  sql+=" and a.M="+IntToStr(m);
  sql+=" and a.Y="+IntToStr(y);
  sql+=" group by s.metka1 , s.fakt_chel";
  Q_INS->SQL->Add(sql);
  try
  {
    Q_INS->ExecQuery();
  }
  catch (Exception &exc)
  {
    MessageDlg("Ошибка - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
    return;
  }
  sexp3=Q_INS->FieldByName("SUMEXP")->AsFloat;
  Q_INS->Close();

    if (kol1>0){
    Q->Close();
    Q->SQL->Clear();
    sql="delete from EXPENSES_TABLE where ";
    sql+="EXP_DATE='"+dexp.DateString()+"'";
    sql+=" and SD_ID = " + getSD_ID()+ "";
    sql+=" and DRIVER_ID = " +IntToStr(idops);
    sql+=" and FLAG = 1";
    sql+=" and GSM_ID IN (3,37,74)";
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
    Q->Transaction->Commit();


    idexp=0;
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
    {
      MessageDlg("Ошибка - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      Q->Transaction->Rollback();
      return;
    }
    if(Q->RecordCount==0)
    {
      MessageDlg("Ошибка получения значения ID таблицы EXPENSES_TABLE",mtError,TMsgDlgButtons() << mbOK,0);
      Q->Transaction->Rollback();
      return;
    }
    idexp=Q->FieldByName("ID")->AsInteger;

    Q->Close();
    Q->SQL->Clear();
    sql="insert into EXPENSES_TABLE(ID,EXP_DATE,SD_ID,DRIVER_ID,GSM_ID,KOL,EXPENSE,FLAG,EDITABLE,U_ID,D) values(";
    sql+=IntToStr(idexp)+",";
    sql+="'"+dexp.DateString()+"',";
    sql+=getSD_ID()+",";
    sql+=IntToStr(idops)+",3,";
    sql+=IntToStr(kol1)+",";
    sql+=FloatToStr(sexp1)+",1,1,";
    sql+=IntToStr(GSM_DM->UserID)+",0)";
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

    idexp=0;
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
    {
      MessageDlg("Ошибка - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      Q->Transaction->Rollback();
      return;
    }
    if(Q->RecordCount==0)
    {
      MessageDlg("Ошибка получения значения ID таблицы EXPENSES_TABLE",mtError,TMsgDlgButtons() << mbOK,0);
      Q->Transaction->Rollback();
      return;
    }
    idexp=Q->FieldByName("ID")->AsInteger;

    Q->Close();
    Q->SQL->Clear();
    sql="insert into EXPENSES_TABLE(ID,EXP_DATE,SD_ID,DRIVER_ID,GSM_ID,KOL,EXPENSE,FLAG,EDITABLE,U_ID,D) values(";
    sql+=IntToStr(idexp)+",";
    sql+="'"+dexp.DateString()+"',";
    sql+=getSD_ID()+",";
    sql+=IntToStr(idops)+",37,";
    sql+=IntToStr(kol2)+",";
    sql+=FloatToStr(sexp2)+",1,1,";
    sql+=IntToStr(GSM_DM->UserID)+",0)";
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

    idexp=0;
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
    {
      MessageDlg("Ошибка - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      Q->Transaction->Rollback();
      return;
    }
    if(Q->RecordCount==0)
    {
      MessageDlg("Ошибка получения значения ID таблицы EXPENSES_TABLE",mtError,TMsgDlgButtons() << mbOK,0);
      Q->Transaction->Rollback();
      return;
    }
    idexp=Q->FieldByName("ID")->AsInteger;

    Q->Close();
    Q->SQL->Clear();
    sql="insert into EXPENSES_TABLE(ID,EXP_DATE,SD_ID,DRIVER_ID,GSM_ID,KOL,EXPENSE,FLAG,EDITABLE,U_ID,D) values(";
    sql+=IntToStr(idexp)+",";
    sql+="'"+dexp.DateString()+"',";
    sql+=getSD_ID()+",";
    sql+=IntToStr(idops)+",74,";
    sql+=IntToStr(kol3)+",";
    sql+=FloatToStr(sexp3)+",1,1,";
    sql+=IntToStr(GSM_DM->UserID)+",0)";
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
    RashetWorkDS();
    LoadWorkDS(getSD_ID(),getID());
    TLocateOptions lo; lo.Clear();
    if(PC->ActivePageIndex == 0){
    if(ActivTable == 1) workDS->Locate("ID",ID,lo);
    if(ActivTable == 2) workDS3->Locate("ID",ID,lo);
    if(ActivTable == 3) workDS4->Locate("ID",ID,lo);
    }
    if(PC->ActivePageIndex == 1) workDS1->Locate("ID",ID,lo);
    if(PC->ActivePageIndex == 2) workDS2->Locate("ID",ID,lo);
//    MessageDlg("Данные по почтальону " + selectSDBar->Items->Items[selectedSD]->Caption + " по ОПС " + autoNumberEdit->Text.Trim()+ " из ИС ИНСПЕКТОР получены успешно !!!",mtWarning,TMsgDlgButtons() << mbOK,0);
    }else
    {
    MessageDlg("Данные по почтальону " + selectSDBar->Items->Items[selectedSD]->Caption + " по ОПС " + autoNumberEdit->Text.Trim()+ " из ИС ИНСПЕКТОР НЕТ !!!",mtWarning,TMsgDlgButtons() << mbOK,0);
    }
  }
}

// импорт по кассе

if (workGrid1->Focused())
{

if(MessageDlg("Вы уверены, что хотите получить данные из ИС ИНСПЕКТОР по " + selectSDBar1->Items->Items[selectedSD1]->Caption + " и ОПС " + autoNumberEdit1->Text.Trim() + " за " + AnsiString().sprintf("%02d-%02d-%d",d,m,y) + " ? \n ВНИМАНИЕ!!! При импорте старые записи безвозвратно удалятся!!!", mtConfirmation,TMsgDlgButtons() << mbOK << mbCancel,0)==mrOk)
{
kol1=0;
sexp1=0.00;

  Q_LOC->Close();
  Q_LOC->SQL->Clear();
  sql="select e.* from USERS_TABLE e";
  sql+=" where e.U_LOGIN='"+GSM_DM->UserLogin+"'";
  Q_LOC->SQL->Add(sql);
  try
  {
    Q_LOC->ExecQuery();
  }
  catch (Exception &exc)
  {
    MessageDlg("Ошибка - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
    return;
  }
  iduser=Q_LOC->FieldByName("IDINS")->AsInteger;
  Q_LOC->Close();

  // определить код кассы из справочника касс

  Q_LOC->Close();
  Q_LOC->SQL->Clear();
  sql="select e.* from KASSA_TABLE e";
  sql+=" where e.DESCRIPTION = '"+selectSDBar1->Items->Items[selectedSD1]->Caption.Trim()+"'";
  Q_LOC->SQL->Add(sql);
  try
  {
    Q_LOC->ExecQuery();
  }
  catch (Exception &exc)
  {
    MessageDlg("Ошибка - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
    return;
  }
  idopsp=Q_LOC->FieldByName("ID")->AsInteger;
  idpost=Q_LOC->FieldByName("IDINS")->AsInteger;
  Q_LOC->Close();


  Q_LOC->Close();
  Q_LOC->SQL->Clear();
  sql="select e.* from KASSA_TABLE e";
  sql+=" where e.DESCRIPTION = '"+autoNumberEdit1->Text.Trim()+"'";
  sql+=" and e.FILE_ID="+IntToStr(idopsp);
  Q_LOC->SQL->Add(sql);
  try
  {
    Q_LOC->ExecQuery();
  }
  catch (Exception &exc)
  {
    MessageDlg("Ошибка - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
    return;
  }
  idops=Q_LOC->FieldByName("ID")->AsInteger;
  Q_LOC->Close();

  if (idops==0)
  {
    MessageDlg("Нет данных для импорта !!! Касса " + selectSDBar1->Items->Items[selectedSD1]->Caption + " на ОПС " + autoNumberEdit1->Text.Trim()+ " не работает!!!",mtWarning,TMsgDlgButtons() << mbOK,0);
    return;
  }

  // определить выплаты всего общее and LCHET1 NOT IN ('Прошврем','раздел 1')

  Q_INS->Close();
  Q_INS->SQL->Clear();
  sql="select COUNT(s.LCHET) as kol , s.metka1 , s.fakt_chel from ACCOUNTS a left outer join SGB s on a.ORG_ID=s.ORG_ID";
  sql+=" and a.COUNT_DATE=s.COUNT_DATE and a.COUNT_NUMBER=s.COUNT_NUMBER";
  sql+=" where a.USER_ID="+IntToStr(iduser);
  sql+=" and s.FAKT_CHEL="+IntToStr(idpost);
  sql+=" and s.METKA1="+IntToStr(indops);
  sql+=" and s.FAKT_DAT="+IntToStr(d);
  sql+=" and s.LCHET1 NOT IN ('Прошврем','раздел 1')";
  sql+=" and a.M="+IntToStr(m);
  sql+=" and a.Y="+IntToStr(y);
  sql+=" group by s.fakt_chel, s.metka1";
  Q_INS->SQL->Add(sql);
  try
  {
    Q_INS->ExecQuery();
  }
  catch (Exception &exc)
  {
    MessageDlg("Ошибка - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
    return;
  }
  kol1=Q_INS->FieldByName("KOL")->AsInteger;

  Q_INS->Close();
  Q_INS->SQL->Clear();
  sql="select SUM(s.SUMMA) as sumexp, COUNT(s.LCHET) as kol , s.metka1 , s.fakt_chel from ACCOUNTS a left outer join SGB s on a.ORG_ID=s.ORG_ID";
  sql+=" and a.COUNT_DATE=s.COUNT_DATE and a.COUNT_NUMBER=s.COUNT_NUMBER";
  sql+=" where a.USER_ID="+IntToStr(iduser);
  sql+=" and s.FAKT_CHEL="+IntToStr(idpost);
  sql+=" and s.METKA1="+IntToStr(indops);
  sql+=" and s.FAKT_DAT="+IntToStr(d);
  sql+=" and a.M="+IntToStr(m);
  sql+=" and a.Y="+IntToStr(y);
  sql+=" group by s.fakt_chel, s.metka1";

  Q_INS->SQL->Add(sql);
  try
  {
    Q_INS->ExecQuery();
  }
  catch (Exception &exc)
  {
    MessageDlg("Ошибка - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
    return;
  }
  sexp1=Q_INS->FieldByName("SUMEXP")->AsFloat;


    if (kol1>0){
    Q->Close();
    Q->SQL->Clear();
    sql="delete from EXPENSES_TABLE where ";
    sql+="EXP_DATE='"+dexp.DateString()+"'";
    sql+=" and SD_ID = " + getSD_ID()+ "";
    sql+=" and DRIVER_ID = " +IntToStr(idops);
    sql+=" and FLAG = 0";
    sql+=" and GSM_ID IN (3,37,74)";
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
    Q->Transaction->Commit();



    idexp=0;
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
    {
      MessageDlg("Ошибка - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      Q->Transaction->Rollback();
      return;
    }
    if(Q->RecordCount==0)
    {
      MessageDlg("Ошибка получения значения ID таблицы EXPENSES_TABLE",mtError,TMsgDlgButtons() << mbOK,0);
      Q->Transaction->Rollback();
      return;
    }
    idexp=Q->FieldByName("ID")->AsInteger;

    Q->Close();
    Q->SQL->Clear();
    sql="insert into EXPENSES_TABLE(ID,EXP_DATE,SD_ID,DRIVER_ID,GSM_ID,KOL,EXPENSE,FLAG,EDITABLE,U_ID,D) values(";
    sql+=IntToStr(idexp)+",";
    sql+="'"+dexp.DateString()+"',";
    sql+=getSD_ID()+",";
    sql+=IntToStr(idops)+",37,";
    sql+=IntToStr(kol1)+",";
    sql+=FloatToStr(sexp1)+",0,1,";
    sql+=IntToStr(GSM_DM->UserID)+",0)";
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

    if(PC->ActivePageIndex == 0) RashetWorkDS();
    LoadWorkDS(getSD_ID(),getID());
    TLocateOptions lo; lo.Clear();
    if(PC->ActivePageIndex == 0){
    if(ActivTable == 1) workDS->Locate("ID",ID,lo);
    if(ActivTable == 2) workDS3->Locate("ID",ID,lo);
    if(ActivTable == 3) workDS4->Locate("ID",ID,lo);
    }
    if(PC->ActivePageIndex == 1) workDS1->Locate("ID",ID,lo);
    if(PC->ActivePageIndex == 2) workDS2->Locate("ID",ID,lo);
//    MessageDlg("Данные по кассе " + selectSDBar1->Items->Items[selectedSD1]->Caption + " по ОПС " + autoNumberEdit->Text.Trim()+ " из ИС ИНСПЕКТОР получены успешно !!!",mtWarning,TMsgDlgButtons() << mbOK,0);
    }else
    {
    MessageDlg("Данные по кассе " + selectSDBar1->Items->Items[selectedSD1]->Caption + " по ОПС " + autoNumberEdit1->Text.Trim()+ " из ИС ИНСПЕКТОР НЕТ !!!",mtWarning,TMsgDlgButtons() << mbOK,0);
    }
  }

}

}
//---------------------------------------------------------------------------

void __fastcall TMainForm::ImportButtonClick(TObject *Sender)
{
impItemClick(this);
}
//---------------------------------------------------------------------------







void __fastcall TMainForm::autoNumberEdit1Change(TObject *Sender)
{
AddButton->Enabled =false;
DeleteButton->Enabled=false;
EditButton->Enabled=false;
editItem->Visible = false;
addItem->Visible = false;
delItem->Visible = false;

//  initMainForm();
  LoadWorkDS(getSD_ID(),getID());
  setMainHeader();
        
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::autoNumberEditChange(TObject *Sender)
{
AnsiString s;
AnsiString OPS1;
int index;

AddButton->Enabled =false;
DeleteButton->Enabled=false;
EditButton->Enabled=false;
editItem->Visible = false;
addItem->Visible = false;
delItem->Visible = false;

if(PC->ActivePageIndex == 0) index = autoNumberEdit->ItemIndex;
if(PC->ActivePageIndex == 1) index = autoNumberEdit1->ItemIndex;

if (index >= 0)
{
if(PC->ActivePageIndex == 0) OPS1=autoID->Strings[index];
if(PC->ActivePageIndex == 1) OPS1=autoID1->Strings[index];
}
else
{
OPS1="0";
}

  if(GSM_DM->VerForm==1)
  {
  if (GSM_DM->UserRole!="администратор" && GSM_DM->UserRole!="руководитель"){
    JvNavPanelHeader1->Caption="Приход/Расход/Возврат";
  }else
  {
   if (AnsiPos(GSM_DM->Index,OPS1.Trim())>0) JvNavPanelHeader1->Caption="Приход"; else JvNavPanelHeader1->Caption="Приход/Расход/Возврат";
  }
  }else
  {
  JvNavPanelHeader1->Caption="Приход";
  }
  LoadWorkDS(getSD_ID(),getID());
  setMainHeader();
}
//---------------------------------------------------------------------------




void __fastcall TMainForm::N23Click(TObject *Sender)
{
TFormBlock *FB;

  try
  {
    FB=new TFormBlock(this);
  }
  catch (Exception &exc)
  { MessageDlg("Ошибка создания формы FormBlock\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
    return;
  }
  FB->ShowModal();
  delete FB;

}
//---------------------------------------------------------------------------

void __fastcall TMainForm::N24Click(TObject *Sender)
{
TFormParamProg *FPG;

  try
  {
    FPG=new TFormParamProg(this);
  }
  catch (Exception &exc)
  { MessageDlg("Ошибка создания формы FormParamProg\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
    return;
  }
  if(FPG->ShowModal()==mrOk)
  {
   odpp=FPG->JvEdit1->Text;
   fio=FPG->JvEdit2->Text;
   tel=FPG->JvEdit3->Text;
   email=FPG->JvEdit4->Text;
  }
delete FPG;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::ScanButtonClick(TObject *Sender)
{
TScanerForm *SF;

  try
  {
    SF=new TScanerForm(this);
  }
  catch (Exception &exc)
  { MessageDlg("Ошибка открытия формы TScanerForm\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
    return;
  }

  if(SF->ShowModal()==mrOk){ }

  if(SF!=NULL) delete SF;
}
//---------------------------------------------------------------------------

