//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "FormScan.h"
#include "DataModule.h"
#include "Main.h"
#include "utils.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "DBGridEh"
#pragma link "JvComponent"
#pragma link "JvExControls"
#pragma link "JvNavigationPane"
#pragma link "JvXPBar"
#pragma link "JvXPCore"
#pragma link "RzTabs"
#pragma link "Placemnt"
#pragma link "FIBDataSet"
#pragma link "pFIBDataSet"
#pragma link "FIBDatabase"
#pragma link "pFIBDatabase"
#pragma link "JvCalendar"
#pragma link "CCALENDR"
#pragma link "FIBQuery"
#pragma link "pFIBQuery"
#pragma resource "*.dfm"
#include "FIBDataSet.hpp"
#include "pFIBDataSet.hpp"
#include "utils.h"


TScanerForm *ScanerForm;
//---------------------------------------------------------------------------
__fastcall TScanerForm::TScanerForm(TComponent* Owner)
        : TForm(Owner)
{
TIniFile* ini;
int GridFontSize,GridFontSize1,GridFontSize4,GridFontSize5,GridFontSize3,GridFontSize6;

  workDir=ExtractFilePath(Application->ExeName);
  iniFileName=workDir+"AccountGSM.ini";
  FormStorage->IniFileName=iniFileName;
  FormStorage->IniSection="ScanerForm";
  ini=new TIniFile(iniFileName);
//  Date1=Date();
  Date1=ini->ReadDate("MainForm","Date1",Date());

  selectedSD=ini->ReadInteger("ScanerForm","selectedSD",0);
  AccountsGrid->Columns->Items[0]->Width=ini->ReadInteger("ScanerForm","Col0_Width",60);
  AccountsGrid->Columns->Items[1]->Width=ini->ReadInteger("ScanerForm","Col1_Width",30);
  AccountsGrid->Columns->Items[2]->Width=ini->ReadInteger("ScanerForm","Col2_Width",140);
  AccountsGrid->Columns->Items[3]->Width=ini->ReadInteger("ScanerForm","Col3_Width",60);
  AccountsGrid->Columns->Items[4]->Width=ini->ReadInteger("ScanerForm","Col4_Width",60);
  AccountsGrid->Columns->Items[5]->Width=ini->ReadInteger("ScanerForm","Col5_Width",70);
  AccountsGrid->Columns->Items[6]->Width=ini->ReadInteger("ScanerForm","Col6_Width",70);
  AccountsGrid->Columns->Items[7]->Width=ini->ReadInteger("ScanerForm","Col7_Width",60);
  AccountsGrid->Columns->Items[8]->Width=ini->ReadInteger("ScanerForm","Col8_Width",60);
  AccountsGrid->Columns->Items[9]->Width=ini->ReadInteger("ScanerForm","Col9_Width",60);
  AccountsGrid->Columns->Items[10]->Width=ini->ReadInteger("ScanerForm","Col10_Width",60);
  AccountsGrid->Columns->Items[11]->Width=ini->ReadInteger("ScanerForm","Col11_Width",60);
  AccountsGrid->Columns->Items[12]->Width=ini->ReadInteger("ScanerForm","Col12_Width",60);
  AccountsGrid->Columns->Items[13]->Width=ini->ReadInteger("ScanerForm","Col13_Width",60);
  AccountsGrid->Columns->Items[14]->Width=ini->ReadInteger("ScanerForm","Col14_Width",140);

  SoldGoodsGrid->Columns->Items[0]->Width=ini->ReadInteger("ScanerForm","Col0_Width3",140);
  SoldGoodsGrid->Columns->Items[1]->Width=ini->ReadInteger("ScanerForm","Col1_Width3",140);
  SoldGoodsGrid->Columns->Items[2]->Width=ini->ReadInteger("ScanerForm","Col2_Width3",90);
  SoldGoodsGrid->Columns->Items[3]->Width=ini->ReadInteger("ScanerForm","Col3_Width3",90);

  VostrGrid->Columns->Items[0]->Width=ini->ReadInteger("ScanerForm","Col0_Width4",140);

  selectedSD1=ini->ReadInteger("ScanerForm","selectedSD1",0);

  BazaGrid->Columns->Items[0]->Width=ini->ReadInteger("ScanerForm","Col0_Width1",60);
  BazaGrid->Columns->Items[1]->Width=ini->ReadInteger("ScanerForm","Col1_Width1",90);
  BazaGrid->Columns->Items[2]->Width=ini->ReadInteger("ScanerForm","Col2_Width1",90);
  BazaGrid->Columns->Items[3]->Width=ini->ReadInteger("ScanerForm","Col3_Width1",90);


  GridFontSize=ini->ReadInteger("ScanerForm","GridFontSize",AccountsGrid->Font->Size);
  GridFontSize4=ini->ReadInteger("ScanerForm","GridFontSize4",SoldGoodsGrid->Font->Size);
  GridFontSize5=ini->ReadInteger("ScanerForm","GridFontSize5",VostrGrid->Font->Size);
  GridFontSize1=ini->ReadInteger("ScanerForm","GridFontSize1",BazaGrid->Font->Size);
  GridFontSize3=ini->ReadInteger("ScanerForm","GridFontSize3",selectSDBar->Font->Size);
  GridFontSize6=ini->ReadInteger("ScanerForm","GridFontSize6",OpsBar->Font->Size);

  AccountsGrid->Font->Size=GridFontSize;
  AccountsGrid->FooterFont->Size=GridFontSize;
  AccountsGrid->TitleFont->Size=GridFontSize;

  SoldGoodsGrid->Font->Size=GridFontSize4;
  SoldGoodsGrid->FooterFont->Size=GridFontSize4;
  SoldGoodsGrid->TitleFont->Size=GridFontSize4;

  VostrGrid->Font->Size=GridFontSize5;
  VostrGrid->FooterFont->Size=GridFontSize5;
  VostrGrid->TitleFont->Size=GridFontSize5;

  BazaGrid->Font->Size=GridFontSize1;
  BazaGrid->FooterFont->Size=GridFontSize1;
  BazaGrid->TitleFont->Size=GridFontSize1;

  selectSDBar->Font->Size=GridFontSize3;
  OpsBar->Font->Size=GridFontSize6;

  delete ini;
  setMainHeader();
  SLabel->Left=ButtonsPanel->Width-SLabel->Width-5-SEdit->Width-4-FSButton->Width-4-BSButton->Width-5;
  SEdit->Left=SLabel->Left+SLabel->Width+5;
  FSButton->Left=SEdit->Left+SEdit->Width+4;
  BSButton->Left=FSButton->Left+FSButton->Width+4;
}
//---------------------------------------------------------------------------

void __fastcall TScanerForm::FormDestroy(TObject *Sender)
{
TIniFile* ini;

  ini=new TIniFile(iniFileName);
  ini->WriteDate("ScanerForm","Date1",Date1);

  ini->WriteInteger("ScanerForm","selectedSD",selectedSD);
  ini->WriteInteger("ScanerForm","Col0_Width",AccountsGrid->Columns->Items[0]->Width);
  ini->WriteInteger("ScanerForm","Col1_Width",AccountsGrid->Columns->Items[1]->Width);
  ini->WriteInteger("ScanerForm","Col2_Width",AccountsGrid->Columns->Items[2]->Width);
  ini->WriteInteger("ScanerForm","Col3_Width",AccountsGrid->Columns->Items[3]->Width);
  ini->WriteInteger("ScanerForm","Col4_Width",AccountsGrid->Columns->Items[4]->Width);
  ini->WriteInteger("ScanerForm","Col5_Width",AccountsGrid->Columns->Items[5]->Width);
  ini->WriteInteger("ScanerForm","Col6_Width",AccountsGrid->Columns->Items[6]->Width);
  ini->WriteInteger("ScanerForm","Col7_Width",AccountsGrid->Columns->Items[7]->Width);
  ini->WriteInteger("ScanerForm","Col8_Width",AccountsGrid->Columns->Items[8]->Width);
  ini->WriteInteger("ScanerForm","Col9_Width",AccountsGrid->Columns->Items[9]->Width);
  ini->WriteInteger("ScanerForm","Col10_Width",AccountsGrid->Columns->Items[10]->Width);
  ini->WriteInteger("ScanerForm","Col11_Width",AccountsGrid->Columns->Items[11]->Width);
  ini->WriteInteger("ScanerForm","Col12_Width",AccountsGrid->Columns->Items[12]->Width);
  ini->WriteInteger("ScanerForm","Col13_Width",AccountsGrid->Columns->Items[13]->Width);
  ini->WriteInteger("ScanerForm","Col14_Width",AccountsGrid->Columns->Items[14]->Width);

  ini->WriteInteger("ScanerForm","Col0_Width3",SoldGoodsGrid->Columns->Items[0]->Width);
  ini->WriteInteger("ScanerForm","Col1_Width3",SoldGoodsGrid->Columns->Items[1]->Width);
  ini->WriteInteger("ScanerForm","Col2_Width3",SoldGoodsGrid->Columns->Items[2]->Width);
  ini->WriteInteger("ScanerForm","Col3_Width3",SoldGoodsGrid->Columns->Items[3]->Width);

  ini->WriteInteger("ScanerForm","Col0_Width4",VostrGrid->Columns->Items[0]->Width);

  ini->WriteInteger("ScanerForm","selectedSD1",selectedSD1);

  ini->WriteInteger("ScanerForm","Col0_Width1",BazaGrid->Columns->Items[0]->Width);
  ini->WriteInteger("ScanerForm","Col1_Width1",BazaGrid->Columns->Items[1]->Width);
  ini->WriteInteger("ScanerForm","Col2_Width1",BazaGrid->Columns->Items[2]->Width);
  ini->WriteInteger("ScanerForm","Col3_Width1",BazaGrid->Columns->Items[3]->Width);

  ini->WriteInteger("ScanerForm","GridFontSize",AccountsGrid->Font->Size);
  ini->WriteInteger("ScanerForm","GridFontSize4",SoldGoodsGrid->Font->Size);
  ini->WriteInteger("ScanerForm","GridFontSize5",VostrGrid->Font->Size);
  ini->WriteInteger("ScanerForm","GridFontSize1",BazaGrid->Font->Size);
  ini->WriteInteger("ScanerForm","GridFontSize3",selectSDBar->Font->Size);
  ini->WriteInteger("ScanerForm","GridFontSize6",OpsBar->Font->Size);

  delete ini;

}


void __fastcall TScanerForm::initMainForm(void)
{
}
//---------------------------------------------------------------------------



void __fastcall TScanerForm::FormShow(TObject *Sender)
{
  AnsiString sql;
  int fk=0;
  AnsiString IndOps;
  int i,reccount;
  TpFIBDataSet *rDS=GSM_DM->RDS1;
  int k=0;
  int pos1,pos2;
  int d=1;
  unsigned short y,m,ds;
  TDateTime tekd;

  tekd=Date();
  tekd.DecodeDate(&y,&m,&ds);

  if (ds>22)
  {
  if (m==12) Calendar->NextYear();
  Calendar->NextMonth();
  }

  for (int cidm=0;cidm<20;cidm++)
  {
  Massiv[cidm]="";
  }

  sql="select U_INDEX as INDOPS from USERS_TABLE where U_ID="+IntToStr(GSM_DM->UserID);
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

  i=0;
  rDS->Last();
  reccount=rDS->RecordCount;
  rDS->First();
  while(!rDS->Eof)
  {
    if (i==30) break;
    AnsiString sdName=rDS->FieldByName("SD_NAME")->AsString;
    selectSDBar->Items->Items[i]->Caption=sdName;
    selectSDBar->Items->Items[i]->Visible = true;
    rDS->Next();
    i++;
  }

  for (int k = reccount;k < selectSDBar->Items->Count; k++)
  {
  selectSDBar->Items->Items[k]->Visible = false;
  }

  // дерево опс
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
  i=0;
  rDS->Last();
  reccount=rDS->RecordCount;
  rDS->First();
  while(!rDS->Eof)
  {
    if (i==30) break;
    AnsiString sdName=rDS->FieldByName("SD_NAME")->AsString;
    OpsBar->Items->Items[i]->Caption=sdName;
    OpsBar->Items->Items[i]->Visible = true;
    rDS->Next();
    i++;
  }
  }
  for (int k = reccount;k < OpsBar->Items->Count; k++)
  {
  OpsBar->Items->Items[k]->Visible = false;
  }
  rDS->Close();
  setMainHeader();
  LoadWorkDS(Date1,getSD_IDPost(),getSD_IDOps());
}
//---------------------------------------------------------------------------
void __fastcall TScanerForm::setMainHeader(void)
{
AnsiString spost,sops,s;


  if(PC->ActivePageIndex == 0) {

   spost=selectSDBar->Items->Items[selectedSD]->Caption;
   sops=OpsBar->Items->Items[selectedSD1]->Caption;
   Date1=Calendar->CalendarDate;
   s="Задание почтальону " + spost.Trim();
   s+= " по ОПС  " + sops.Trim();
   s+=" за "+Date1.DateString();
//   if (spost.Trim()=="") { MessageDlg("Выберите пожалуйста почтальона!!!",mtWarning,TMsgDlgButtons() << mbOK,0);}
//   if (sops.Trim()=="") { MessageDlg("Выберите пожалуйста ОПС!!!",mtWarning,TMsgDlgButtons() << mbOK,0);}
   }


  if(PC->ActivePageIndex == 1) { s="Список получателей до востребования на кассе";}
  if(PC->ActivePageIndex == 2) { s=" Текущая выплатная база ";}

//  if(Date1 == Date2) s+=" - учет операций за "+Date1.DateString();
//  else s+=" - учет операций за период с "+Date1.DateString()+" по "+Date2.DateString();
//  if (OPS1.Trim() != "0" && PC->ActivePageIndex < 2) s+= " по ОПС -> " + OPS1.Trim();
  MainHeader->Caption=s;
}

void __fastcall TScanerForm::PCClick(TObject *Sender)
{
DeleteButton->Enabled = false;
EditButton->Enabled = false;
delItem->Visible = false;
editItem->Visible = false;
AddButton->Enabled = false;
addItem->Visible = false;
setMainHeader();
LoadWorkDS(Date1,getSD_IDPost(),getSD_IDOps());
}
//---------------------------------------------------------------------------

void __fastcall TScanerForm::action0Execute(TObject *Sender)
{
  if(PC->ActivePageIndex == 0){
  selectSDBar->Items->Items[selectedSD]->Checked=false;
  selectedSD=0;
  if(Showing) LoadWorkDS(Date1,getSD_IDPost(),getSD_IDOps());
  selectSDBar->Items->Items[selectedSD]->Checked=true;
  setMainHeader();
  selectSDBarClick(this);
  }
}
//---------------------------------------------------------------------------

void __fastcall TScanerForm::action1Execute(TObject *Sender)
{
  if(PC->ActivePageIndex == 0){
  selectSDBar->Items->Items[selectedSD]->Checked=false;
  selectedSD=1;
  if(Showing) LoadWorkDS(Date1,getSD_IDPost(),getSD_IDOps());
  selectSDBar->Items->Items[selectedSD]->Checked=true;
  setMainHeader();
  selectSDBarClick(this);
  }

}
//---------------------------------------------------------------------------
AnsiString __fastcall TScanerForm::getSD_IDPost(void)
{
AnsiString sdID="";
AnsiString sql="";
TpFIBQuery *RQ=GSM_DM->RQ1;
AnsiString sdName;

sdName="";


  sdName=selectSDBar->Items->Items[selectedSD]->Caption;
  RQ->Close();
  RQ->SQL->Clear();

  sql="select ID from OPS_TABLE";
  sql+=" where DESCRIPTION like '"+sdName+"'";

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

AnsiString __fastcall TScanerForm::getSD_IDOps(void)
{
AnsiString ID="";
AnsiString sql="";
TpFIBQuery *RQ=GSM_DM->RQ1;
AnsiString sdID=getSD_IDPost();
AnsiString OPS;


  OPS="";
  OPS=OpsBar->Items->Items[selectedSD1]->Caption;

  RQ->Close();
  RQ->SQL->Clear();

  sql="select ID from OPS_TABLE";
  sql+=" where DESCRIPTION like '"+OPS.Trim()+"'";
  if (!(sdID.Trim()=="")) sql+= " and FILE_ID = "+sdID.Trim();

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

void __fastcall TScanerForm::LoadWorkDS(TDateTime d,AnsiString sdID,AnsiString ID)
{
AnsiString sql="";

// задания

  if(PC->ActivePageIndex == 0){
  AccountsGrid->Visible=false;
  if(SG_DS->Active==true) SG_DS->Close();
  if(A_DS->Active==true) A_DS->Close();
  A_DS->SQLs->SelectSQL->Clear();
  sql="select t1.*, t4.U_LOGIN as \"Avtor\"";
  sql+=" from ACCOUNTS t1";
  sql+=" left outer join USERS_TABLE t4 on t1.USER_ID=t4.U_ID";
  sql+=" where t1.ORG_ID=1";
  sql+=" and t1.COUNT_DATE='"+d.DateString()+"'";
  sql+=" and USER_ID="+IntToStr(GSM_DM->UserID);
  sql+=" and CUSTOMER_ID="+sdID;
  sql+=" and OPS_ID="+ID;
  sql+=" order by t1.COUNT_DATE,t1.COUNT_NUMBER";

  A_DS->SQLs->SelectSQL->Add(sql);
  try
  {
    A_DS->Open();
  }
  catch(const Exception &exc)
  {
    MessageDlg("Ошибка - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
    return;
  }
  A_DS->Last();

  SG_DS->SQLs->SelectSQL->Clear();
  sql="select t1.* ";
  sql+=" from SGB t1";
  sql+=" where t1.ORG_ID=?MAS_ORG_ID and t1.COUNT_DATE=?MAS_COUNT_DATE \
and t1.COUNT_NUMBER=?MAS_COUNT_NUMBER";
  sql+=" order by t1.SYS_NUM";
  SG_DS->SQLs->SelectSQL->Add(sql);
  try
  {
    SG_DS->Open();
  }
  catch(const Exception &exc)
  {
    MessageDlg("Ошибка чтения таблицы SOLD_GOODS_BOOK\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
  }
  AccountsGrid->Visible=true;
  SoldGoodsGrid->Visible=true;
//  SetButtons();
  try
  {
    AccountsGrid->SetFocus();
  }
  catch(...){};
  }

// список до востребования
  if(PC->ActivePageIndex == 1){
  VostrGrid->Visible=false;
  if(VOSTR->Active==true) VOSTR->Close();
  VOSTR->SQLs->SelectSQL->Clear();
  sql="select t1.* ";
  sql+=" from VOSTR_TABLE t1";
  sql+=" order by t1.ORDER_NUM";

  VOSTR->SQLs->SelectSQL->Add(sql);
  try
  {
    VOSTR->Open();
  }
  catch(const Exception &exc)
  {
    MessageDlg("Ошибка - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
    return;
  }
  VOSTR->First();
  VostrGrid->Visible=true;
  VostrGrid->SetFocus();
  }

// выплатная база

  if(PC->ActivePageIndex == 2){
  BazaGrid->Visible=false;
  if(BAZA->Active==true) BAZA->Close();
  BAZA->SQLs->SelectSQL->Clear();
  sql="select t1.* ";
  sql+=" from BAZA_TABLE t1";
  sql+=" order by t1.SYS_NUM";

  BAZA->SQLs->SelectSQL->Add(sql);
  try
  {
    BAZA->Open();
  }
  catch(const Exception &exc)
  {
    MessageDlg("Ошибка - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
    return;
  }
  BAZA->First();
  BazaGrid->Visible=true;
  BazaGrid->SetFocus();
  }

}
//---------------------------------------------------------------------------


void __fastcall TScanerForm::Action21Execute(TObject *Sender)
{
  if(PC->ActivePageIndex == 0){
  OpsBar->Items->Items[selectedSD1]->Checked=false;
  selectedSD1=0;
  if(Showing) LoadWorkDS(Date1,getSD_IDPost(),getSD_IDOps());
  OpsBar->Items->Items[selectedSD1]->Checked=true;
  selectSDBarClick(this);
  setMainHeader();
  }
}
//---------------------------------------------------------------------------

void __fastcall TScanerForm::Action22Execute(TObject *Sender)
{
  if(PC->ActivePageIndex == 0){
  OpsBar->Items->Items[selectedSD1]->Checked=false;
  selectedSD1=1;
  if(Showing) LoadWorkDS(Date1,getSD_IDPost(),getSD_IDOps());
  OpsBar->Items->Items[selectedSD1]->Checked=true;
  selectSDBarClick(this);
  setMainHeader();
  }
}
//---------------------------------------------------------------------------

void __fastcall TScanerForm::CalendarChange(TObject *Sender)
{
  Date1=Calendar->CalendarDate;
  LoadWorkDS(Date1,getSD_IDPost(),getSD_IDOps());
  setMainHeader();
  selectSDBarClick(this);
}
//---------------------------------------------------------------------------


void __fastcall TScanerForm::selectSDBarClick(TObject *Sender)
{
AddButton->Enabled =false;
DeleteButton->Enabled=false;
EditButton->Enabled=false;
editItem->Visible = false;
addItem->Visible = false;
delItem->Visible = false;
}


void __fastcall TScanerForm::AddButtonClick(TObject *Sender)
{
addItemClick(this);
}
//---------------------------------------------------------------------------

void __fastcall TScanerForm::EditButtonClick(TObject *Sender)
{
editItemClick(this);
}
//---------------------------------------------------------------------------

void __fastcall TScanerForm::DeleteButtonClick(TObject *Sender)
{
delItemClick(this);
}
//---------------------------------------------------------------------------

void __fastcall TScanerForm::addItemClick(TObject *Sender)
{
// new record        
}
//---------------------------------------------------------------------------

void __fastcall TScanerForm::editItemClick(TObject *Sender)
{
// edit record        
}
//---------------------------------------------------------------------------

void __fastcall TScanerForm::delItemClick(TObject *Sender)
{
//delete record        
}
//---------------------------------------------------------------------------

void __fastcall TScanerForm::AccountsGridCellClick(TColumnEh *Column)
{
    if (A_DS->RecordCount > 0) {
    DeleteButton->Enabled = true;
    EditButton->Enabled = true;
    delItem->Visible = true;
    editItem->Visible = true;
    AddButton->Enabled = true;
    addItem->Visible = true;
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
//---------------------------------------------------------------------------

void __fastcall TScanerForm::action3Execute(TObject *Sender)
{
  if(PC->ActivePageIndex == 0){
  selectSDBar->Items->Items[selectedSD]->Checked=false;
  selectedSD=3;
  if(Showing) LoadWorkDS(Date1,getSD_IDPost(),getSD_IDOps());
  selectSDBar->Items->Items[selectedSD]->Checked=true;
  setMainHeader();
  selectSDBarClick(this);
  }

}
//---------------------------------------------------------------------------

void __fastcall TScanerForm::action2Execute(TObject *Sender)
{
  if(PC->ActivePageIndex == 0){
  selectSDBar->Items->Items[selectedSD]->Checked=false;
  selectedSD=2;
  if(Showing) LoadWorkDS(Date1,getSD_IDPost(),getSD_IDOps());
  selectSDBar->Items->Items[selectedSD]->Checked=true;
  setMainHeader();
  selectSDBarClick(this);
  }

}
//---------------------------------------------------------------------------

void __fastcall TScanerForm::action4Execute(TObject *Sender)
{
  if(PC->ActivePageIndex == 0){
  selectSDBar->Items->Items[selectedSD]->Checked=false;
  selectedSD=4;
  if(Showing) LoadWorkDS(Date1,getSD_IDPost(),getSD_IDOps());
  selectSDBar->Items->Items[selectedSD]->Checked=true;
  setMainHeader();
  selectSDBarClick(this);
  }

}
//---------------------------------------------------------------------------

void __fastcall TScanerForm::action5Execute(TObject *Sender)
{
  if(PC->ActivePageIndex == 0){
  selectSDBar->Items->Items[selectedSD]->Checked=false;
  selectedSD=5;
  if(Showing) LoadWorkDS(Date1,getSD_IDPost(),getSD_IDOps());
  selectSDBar->Items->Items[selectedSD]->Checked=true;
  setMainHeader();
  selectSDBarClick(this);
  }

}
//---------------------------------------------------------------------------

void __fastcall TScanerForm::action6Execute(TObject *Sender)
{
  if(PC->ActivePageIndex == 0){
  selectSDBar->Items->Items[selectedSD]->Checked=false;
  selectedSD=6;
  if(Showing) LoadWorkDS(Date1,getSD_IDPost(),getSD_IDOps());
  selectSDBar->Items->Items[selectedSD]->Checked=true;
  setMainHeader();
  selectSDBarClick(this);
  }

}
//---------------------------------------------------------------------------

void __fastcall TScanerForm::action7Execute(TObject *Sender)
{
  if(PC->ActivePageIndex == 0){
  selectSDBar->Items->Items[selectedSD]->Checked=false;
  selectedSD=7;
  if(Showing) LoadWorkDS(Date1,getSD_IDPost(),getSD_IDOps());
  selectSDBar->Items->Items[selectedSD]->Checked=true;
  setMainHeader();
  selectSDBarClick(this);
  }

}
//---------------------------------------------------------------------------

void __fastcall TScanerForm::action8Execute(TObject *Sender)
{
  if(PC->ActivePageIndex == 0){
  selectSDBar->Items->Items[selectedSD]->Checked=false;
  selectedSD=8;
  if(Showing) LoadWorkDS(Date1,getSD_IDPost(),getSD_IDOps());
  selectSDBar->Items->Items[selectedSD]->Checked=true;
  setMainHeader();
  selectSDBarClick(this);
  }

}
//---------------------------------------------------------------------------

void __fastcall TScanerForm::action9Execute(TObject *Sender)
{
  if(PC->ActivePageIndex == 0){
  selectSDBar->Items->Items[selectedSD]->Checked=false;
  selectedSD=9;
  if(Showing) LoadWorkDS(Date1,getSD_IDPost(),getSD_IDOps());
  selectSDBar->Items->Items[selectedSD]->Checked=true;
  setMainHeader();
  selectSDBarClick(this);
  }

}
//---------------------------------------------------------------------------

void __fastcall TScanerForm::action10Execute(TObject *Sender)
{
  if(PC->ActivePageIndex == 0){
  selectSDBar->Items->Items[selectedSD]->Checked=false;
  selectedSD=10;
  if(Showing) LoadWorkDS(Date1,getSD_IDPost(),getSD_IDOps());
  selectSDBar->Items->Items[selectedSD]->Checked=true;
  setMainHeader();
  selectSDBarClick(this);
  }

}
//---------------------------------------------------------------------------

void __fastcall TScanerForm::action11Execute(TObject *Sender)
{
  if(PC->ActivePageIndex == 0){
  selectSDBar->Items->Items[selectedSD]->Checked=false;
  selectedSD=11;
  if(Showing) LoadWorkDS(Date1,getSD_IDPost(),getSD_IDOps());
  selectSDBar->Items->Items[selectedSD]->Checked=true;
  setMainHeader();
  selectSDBarClick(this);
  }

}
//---------------------------------------------------------------------------

void __fastcall TScanerForm::action12Execute(TObject *Sender)
{
  if(PC->ActivePageIndex == 0){
  selectSDBar->Items->Items[selectedSD]->Checked=false;
  selectedSD=12;
  if(Showing) LoadWorkDS(Date1,getSD_IDPost(),getSD_IDOps());
  selectSDBar->Items->Items[selectedSD]->Checked=true;
  setMainHeader();
  selectSDBarClick(this);
  }

}
//---------------------------------------------------------------------------

void __fastcall TScanerForm::action13Execute(TObject *Sender)
{
  if(PC->ActivePageIndex == 0){
  selectSDBar->Items->Items[selectedSD]->Checked=false;
  selectedSD=13;
  if(Showing) LoadWorkDS(Date1,getSD_IDPost(),getSD_IDOps());
  selectSDBar->Items->Items[selectedSD]->Checked=true;
  setMainHeader();
  selectSDBarClick(this);
  }

}
//---------------------------------------------------------------------------

void __fastcall TScanerForm::action14Execute(TObject *Sender)
{
  if(PC->ActivePageIndex == 0){
  selectSDBar->Items->Items[selectedSD]->Checked=false;
  selectedSD=14;
  if(Showing) LoadWorkDS(Date1,getSD_IDPost(),getSD_IDOps());
  selectSDBar->Items->Items[selectedSD]->Checked=true;
  setMainHeader();
  selectSDBarClick(this);
  }

}
//---------------------------------------------------------------------------

void __fastcall TScanerForm::action15Execute(TObject *Sender)
{
  if(PC->ActivePageIndex == 0){
  selectSDBar->Items->Items[selectedSD]->Checked=false;
  selectedSD=15;
  if(Showing) LoadWorkDS(Date1,getSD_IDPost(),getSD_IDOps());
  selectSDBar->Items->Items[selectedSD]->Checked=true;
  setMainHeader();
  selectSDBarClick(this);
  }

}
//---------------------------------------------------------------------------

void __fastcall TScanerForm::action16Execute(TObject *Sender)
{
  if(PC->ActivePageIndex == 0){
  selectSDBar->Items->Items[selectedSD]->Checked=false;
  selectedSD=16;
  if(Showing) LoadWorkDS(Date1,getSD_IDPost(),getSD_IDOps());
  selectSDBar->Items->Items[selectedSD]->Checked=true;
  setMainHeader();
  selectSDBarClick(this);
  }

}
//---------------------------------------------------------------------------

void __fastcall TScanerForm::Action17Execute(TObject *Sender)
{
  if(PC->ActivePageIndex == 0){
  selectSDBar->Items->Items[selectedSD]->Checked=false;
  selectedSD=17;
  if(Showing) LoadWorkDS(Date1,getSD_IDPost(),getSD_IDOps());
  selectSDBar->Items->Items[selectedSD]->Checked=true;
  setMainHeader();
  selectSDBarClick(this);
  }

}
//---------------------------------------------------------------------------

void __fastcall TScanerForm::Action18Execute(TObject *Sender)
{
  if(PC->ActivePageIndex == 0){
  selectSDBar->Items->Items[selectedSD]->Checked=false;
  selectedSD=18;
  if(Showing) LoadWorkDS(Date1,getSD_IDPost(),getSD_IDOps());
  selectSDBar->Items->Items[selectedSD]->Checked=true;
  setMainHeader();
  selectSDBarClick(this);
  }

}
//---------------------------------------------------------------------------

void __fastcall TScanerForm::Action19Execute(TObject *Sender)
{
  if(PC->ActivePageIndex == 0){
  selectSDBar->Items->Items[selectedSD]->Checked=false;
  selectedSD=19;
  if(Showing) LoadWorkDS(Date1,getSD_IDPost(),getSD_IDOps());
  selectSDBar->Items->Items[selectedSD]->Checked=true;
  setMainHeader();
  selectSDBarClick(this);
  }

}
//---------------------------------------------------------------------------

void __fastcall TScanerForm::Action20Execute(TObject *Sender)
{
  if(PC->ActivePageIndex == 0){
  selectSDBar->Items->Items[selectedSD]->Checked=false;
  selectedSD=20;
  if(Showing) LoadWorkDS(Date1,getSD_IDPost(),getSD_IDOps());
  selectSDBar->Items->Items[selectedSD]->Checked=true;
  setMainHeader();
  selectSDBarClick(this);
  }

}
//---------------------------------------------------------------------------

void __fastcall TScanerForm::Action23Execute(TObject *Sender)
{
  if(PC->ActivePageIndex == 0){
  OpsBar->Items->Items[selectedSD1]->Checked=false;
  selectedSD1=2;
  if(Showing) LoadWorkDS(Date1,getSD_IDPost(),getSD_IDOps());
  OpsBar->Items->Items[selectedSD1]->Checked=true;
  selectSDBarClick(this);
  setMainHeader();
  }

}
//---------------------------------------------------------------------------

void __fastcall TScanerForm::Action24Execute(TObject *Sender)
{
  if(PC->ActivePageIndex == 0){
  OpsBar->Items->Items[selectedSD1]->Checked=false;
  selectedSD1=3;
  if(Showing) LoadWorkDS(Date1,getSD_IDPost(),getSD_IDOps());
  OpsBar->Items->Items[selectedSD1]->Checked=true;
  selectSDBarClick(this);
  setMainHeader();
  }

}
//---------------------------------------------------------------------------

void __fastcall TScanerForm::Action25Execute(TObject *Sender)
{
  if(PC->ActivePageIndex == 0){
  OpsBar->Items->Items[selectedSD1]->Checked=false;
  selectedSD1=4;
  if(Showing) LoadWorkDS(Date1,getSD_IDPost(),getSD_IDOps());
  OpsBar->Items->Items[selectedSD1]->Checked=true;
  selectSDBarClick(this);
  setMainHeader();
  }

}
//---------------------------------------------------------------------------

void __fastcall TScanerForm::Action26Execute(TObject *Sender)
{
  if(PC->ActivePageIndex == 0){
  OpsBar->Items->Items[selectedSD1]->Checked=false;
  selectedSD1=5;
  if(Showing) LoadWorkDS(Date1,getSD_IDPost(),getSD_IDOps());
  OpsBar->Items->Items[selectedSD1]->Checked=true;
  selectSDBarClick(this);
  setMainHeader();
  }

}
//---------------------------------------------------------------------------

void __fastcall TScanerForm::Action27Execute(TObject *Sender)
{
  if(PC->ActivePageIndex == 0){
  OpsBar->Items->Items[selectedSD1]->Checked=false;
  selectedSD1=6;
  if(Showing) LoadWorkDS(Date1,getSD_IDPost(),getSD_IDOps());
  OpsBar->Items->Items[selectedSD1]->Checked=true;
  selectSDBarClick(this);
  setMainHeader();
  }

}
//---------------------------------------------------------------------------

void __fastcall TScanerForm::Action28Execute(TObject *Sender)
{
  if(PC->ActivePageIndex == 0){
  OpsBar->Items->Items[selectedSD1]->Checked=false;
  selectedSD1=7;
  if(Showing) LoadWorkDS(Date1,getSD_IDPost(),getSD_IDOps());
  OpsBar->Items->Items[selectedSD1]->Checked=true;
  selectSDBarClick(this);
  setMainHeader();
  }

}
//---------------------------------------------------------------------------

void __fastcall TScanerForm::Action29Execute(TObject *Sender)
{
  if(PC->ActivePageIndex == 0){
  OpsBar->Items->Items[selectedSD1]->Checked=false;
  selectedSD1=8;
  if(Showing) LoadWorkDS(Date1,getSD_IDPost(),getSD_IDOps());
  OpsBar->Items->Items[selectedSD1]->Checked=true;
  selectSDBarClick(this);
  setMainHeader();
  }

}
//---------------------------------------------------------------------------

void __fastcall TScanerForm::Action30Execute(TObject *Sender)
{
  if(PC->ActivePageIndex == 0){
  OpsBar->Items->Items[selectedSD1]->Checked=false;
  selectedSD1=9;
  if(Showing) LoadWorkDS(Date1,getSD_IDPost(),getSD_IDOps());
  OpsBar->Items->Items[selectedSD1]->Checked=true;
  selectSDBarClick(this);
  setMainHeader();
  }

}
//---------------------------------------------------------------------------

void __fastcall TScanerForm::Action31Execute(TObject *Sender)
{
  if(PC->ActivePageIndex == 0){
  OpsBar->Items->Items[selectedSD1]->Checked=false;
  selectedSD1=10;
  if(Showing) LoadWorkDS(Date1,getSD_IDPost(),getSD_IDOps());
  OpsBar->Items->Items[selectedSD1]->Checked=true;
  selectSDBarClick(this);
  setMainHeader();
  }

}
//---------------------------------------------------------------------------

void __fastcall TScanerForm::Action32Execute(TObject *Sender)
{
  if(PC->ActivePageIndex == 0){
  OpsBar->Items->Items[selectedSD1]->Checked=false;
  selectedSD1=11;
  if(Showing) LoadWorkDS(Date1,getSD_IDPost(),getSD_IDOps());
  OpsBar->Items->Items[selectedSD1]->Checked=true;
  selectSDBarClick(this);
  setMainHeader();
  }

}
//---------------------------------------------------------------------------

void __fastcall TScanerForm::Action33Execute(TObject *Sender)
{
  if(PC->ActivePageIndex == 0){
  OpsBar->Items->Items[selectedSD1]->Checked=false;
  selectedSD1=12;
  if(Showing) LoadWorkDS(Date1,getSD_IDPost(),getSD_IDOps());
  OpsBar->Items->Items[selectedSD1]->Checked=true;
  selectSDBarClick(this);
  setMainHeader();
  }

}
//---------------------------------------------------------------------------

void __fastcall TScanerForm::Action34Execute(TObject *Sender)
{
  if(PC->ActivePageIndex == 0){
  OpsBar->Items->Items[selectedSD1]->Checked=false;
  selectedSD1=13;
  if(Showing) LoadWorkDS(Date1,getSD_IDPost(),getSD_IDOps());
  OpsBar->Items->Items[selectedSD1]->Checked=true;
  selectSDBarClick(this);
  setMainHeader();
  }

}
//---------------------------------------------------------------------------

void __fastcall TScanerForm::Action35Execute(TObject *Sender)
{
  if(PC->ActivePageIndex == 0){
  OpsBar->Items->Items[selectedSD1]->Checked=false;
  selectedSD1=14;
  if(Showing) LoadWorkDS(Date1,getSD_IDPost(),getSD_IDOps());
  OpsBar->Items->Items[selectedSD1]->Checked=true;
  selectSDBarClick(this);
  setMainHeader();
  }

}
//---------------------------------------------------------------------------

void __fastcall TScanerForm::Action36Execute(TObject *Sender)
{
  if(PC->ActivePageIndex == 0){
  OpsBar->Items->Items[selectedSD1]->Checked=false;
  selectedSD1=15;
  if(Showing) LoadWorkDS(Date1,getSD_IDPost(),getSD_IDOps());
  OpsBar->Items->Items[selectedSD1]->Checked=true;
  selectSDBarClick(this);
  setMainHeader();
  }

}
//---------------------------------------------------------------------------

void __fastcall TScanerForm::Action37Execute(TObject *Sender)
{
  if(PC->ActivePageIndex == 0){
  OpsBar->Items->Items[selectedSD1]->Checked=false;
  selectedSD1=16;
  if(Showing) LoadWorkDS(Date1,getSD_IDPost(),getSD_IDOps());
  OpsBar->Items->Items[selectedSD1]->Checked=true;
  selectSDBarClick(this);
  setMainHeader();
  }

}
//---------------------------------------------------------------------------

void __fastcall TScanerForm::Action38Execute(TObject *Sender)
{
  if(PC->ActivePageIndex == 0){
  OpsBar->Items->Items[selectedSD1]->Checked=false;
  selectedSD1=17;
  if(Showing) LoadWorkDS(Date1,getSD_IDPost(),getSD_IDOps());
  OpsBar->Items->Items[selectedSD1]->Checked=true;
  selectSDBarClick(this);
  setMainHeader();
  }

}
//---------------------------------------------------------------------------

void __fastcall TScanerForm::Action39Execute(TObject *Sender)
{
  if(PC->ActivePageIndex == 0){
  OpsBar->Items->Items[selectedSD1]->Checked=false;
  selectedSD1=18;
  if(Showing) LoadWorkDS(Date1,getSD_IDPost(),getSD_IDOps());
  OpsBar->Items->Items[selectedSD1]->Checked=true;
  selectSDBarClick(this);
  setMainHeader();
  }

}
//---------------------------------------------------------------------------

void __fastcall TScanerForm::Action40Execute(TObject *Sender)
{
  if(PC->ActivePageIndex == 0){
  OpsBar->Items->Items[selectedSD1]->Checked=false;
  selectedSD1=19;
  if(Showing) LoadWorkDS(Date1,getSD_IDPost(),getSD_IDOps());
  OpsBar->Items->Items[selectedSD1]->Checked=true;
  selectSDBarClick(this);
  setMainHeader();
  }

}
//---------------------------------------------------------------------------

void __fastcall TScanerForm::increaseButtonClick(TObject *Sender)
{
int fontDPI;
TDBGridEh *grid=NULL;
TJvXPBar  *bar=NULL;

  if(AccountsGrid->Focused()==true) grid=AccountsGrid;
  if(SoldGoodsGrid->Focused()==true) grid=SoldGoodsGrid;
  if(VostrGrid->Focused()==true) grid=VostrGrid;
  if(BazaGrid->Focused()==true) grid=BazaGrid;
  if (selectSDBar->Focused()==true) bar=selectSDBar;
  if (OpsBar->Focused()==true) bar=OpsBar;
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

void __fastcall TScanerForm::reduceButtonClick(TObject *Sender)
{
int fontDPI;
TDBGridEh *grid=NULL;
TJvXPBar  *bar=NULL;

  if(AccountsGrid->Focused()==true) grid=AccountsGrid;
  if(SoldGoodsGrid->Focused()==true) grid=SoldGoodsGrid;
  if(VostrGrid->Focused()==true) grid=VostrGrid;
  if(BazaGrid->Focused()==true) grid=BazaGrid;
  if (selectSDBar->Focused()==true) bar=selectSDBar;
  if (OpsBar->Focused()==true) bar=OpsBar;
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

void __fastcall TScanerForm::SoldGoodsGridCellClick(TColumnEh *Column)
{
    DeleteButton->Enabled = false;
    EditButton->Enabled = false;
    delItem->Visible = false;
    editItem->Visible = false;
    AddButton->Enabled = false;
    addItem->Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TScanerForm::VostrGridCellClick(TColumnEh *Column)
{
    DeleteButton->Enabled = false;
    EditButton->Enabled = false;
    delItem->Visible = false;
    editItem->Visible = false;
    AddButton->Enabled = false;
    addItem->Visible = false;
        
}
//---------------------------------------------------------------------------

void __fastcall TScanerForm::BazaGridCellClick(TColumnEh *Column)
{
    DeleteButton->Enabled = false;
    EditButton->Enabled = false;
    delItem->Visible = false;
    editItem->Visible = false;
    AddButton->Enabled = false;
    addItem->Visible = false;
}
//---------------------------------------------------------------------------


void __fastcall TScanerForm::SoldGoodsGridKeyPress(TObject *Sender,
      char &Key)
{

//  if(SoldGoodsGrid->Col!=1 && SoldGoodsGrid->Col!=2) return;
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

void __fastcall TScanerForm::SEditKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
  if(Key==VK_RETURN || Key==VK_DOWN || Key==VK_UP){
  Key=0;
  if(PC->ActivePageIndex == 0){SoldGoodsGrid->SetFocus();}
  if(PC->ActivePageIndex == 1){VostrGrid->SetFocus();}
  if(PC->ActivePageIndex == 2){BazaGrid->SetFocus();}
  }
  else if(Key == VK_ESCAPE){ Key=0; SEdit->Text=""; }
}
//---------------------------------------------------------------------------

void __fastcall TScanerForm::SEditChange(TObject *Sender)
{
  if(STimer->Enabled==true) STimer->Enabled=false;
  STimer->Enabled=true;
}
//---------------------------------------------------------------------------

void __fastcall TScanerForm::STimerTimer(TObject *Sender)
{
TLocateOptions opt;
opt<<loPartialKey<<loCaseInsensitive;
AnsiString d=0;
int test=0;
AnsiString n=0;
int l=0;

  STimer->Enabled=false;
  if(SEdit->Text.IsEmpty()) return;
  if(IsNum(SEdit->Text.Trim())){
  d=SEdit->Text.Trim();
  l=d.Length();
  if(PC->ActivePageIndex == 0){
   if(l==20){
      n=d.SubString(4,9);
      SG_DS->Locate("SYS_NUM",n,opt);
    }else
    {
    if(SoldGoodsGrid->Col==1) SG_DS->Locate("ORDER_NUM",d,opt);
    if(SoldGoodsGrid->Col==2) SG_DS->Locate("SYS_NUM",d,opt);
    if (SoldGoodsGrid->Col==3 || SoldGoodsGrid->Col==4){
    MessageDlg("Поиск по этим столбцу не действует!!! Удачи!!!",mtInformation,TMsgDlgButtons() << mbOK,0);
    return;}
    }
  }
  if(PC->ActivePageIndex == 1){
   if(l==20){
      MessageDlg("Сканировать в этом случае не надо , так как поиск идет по номеру поручения , а не системному номеру!!! Удачи!!!",mtInformation,TMsgDlgButtons() << mbOK,0);
    }else
    {
    VOSTR->Locate("ORDER_NUM",d,opt);
    }
  }
  if(PC->ActivePageIndex == 2){
   if(l==20){
      n=d.SubString(4,9);
      BAZA->Locate("SYS_NUM",n,opt);
    }else
    {
    if(BazaGrid->Col==2) BAZA->Locate("ORDER_NUM",d,opt);
    if(BazaGrid->Col==1) BAZA->Locate("SYS_NUM",d,opt);
    if (BazaGrid->Col==3 || BazaGrid->Col==4){
    MessageDlg("Поиск по этим столбцу не действует!!! Удачи!!!",mtInformation,TMsgDlgButtons() << mbOK,0);
    return;}
    }
  }
  SEdit->Text="";
  }else
  {
  SEdit->Text="";
  }

}
//---------------------------------------------------------------------------

void __fastcall TScanerForm::VostrGridKeyPress(TObject *Sender, char &Key)
{
  if(VOSTR->State==dsEdit || VOSTR->State==dsInsert) return;
  if(VostrGrid->Col!=1) return;
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

void __fastcall TScanerForm::BazaGridKeyPress(TObject *Sender, char &Key)
{
//  if(BazaGrid->Col!=1 && BazaGrid->Col!=2) return;
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






