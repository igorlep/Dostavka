//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <windows.h>
#include "Main.h"
#include "DataModule.h"
#include "UniversalReferenceBook.h"
#include "AddEditExpense.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "Placemnt"
#pragma link "JvComponent"
#pragma link "JvExControls"
#pragma link "JvNavigationPane"
#pragma link "ToolEdit"
#pragma link "JvBitBtn"
#pragma link "JvExButtons"
#pragma link "JvBevel"
#pragma link "JvExExtCtrls"
#pragma link "JvCheckedMaskEdit"
#pragma link "JvDatePickerEdit"
#pragma link "JvExMask"
#pragma link "JvMaskEdit"
#pragma link "JvToolEdit"
#pragma link "JvEdit"
#pragma link "JvExStdCtrls"
#pragma link "JvValidateEdit"
#pragma resource "*.dfm"
//TAddEditExpenseForm *AddEditExpenseForm;
//---------------------------------------------------------------------------
__fastcall TAddEditExpenseForm::TAddEditExpenseForm(TComponent* Owner, ExpensesData *ed)
        : TForm(Owner)
{
TIniFile* ini;

  workDir=MainForm->workDir;
  FormStorage->IniFileName=workDir+"AccountGSM.ini";
  FormStorage->IniSection="AddEditExpenseForm";

  ini=new TIniFile(workDir+"AccountGSM.ini");
  lastExpDate=ini->ReadDate("AddEditExpenseForm","lastExpDate",Date());
  delete ini;

  if(lastExpDate < MainForm->getDate1() || lastExpDate > MainForm->getDate2())
  {
    TpFIBQuery * Q=GSM_DM->RQ;
    Q->Close();
    Q->SQL->Clear();
    AnsiString sql="select max(EXP_DATE) as MAX_EXP_DATE from EXPENSES_TABLE where ";
    sql+="EXP_DATE>='"+MainForm->getDate1().DateString()+"'";
    sql+=" and EXP_DATE<='"+MainForm->getDate2().DateString()+"'";
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
    if(Q->RecordCount > 0) lastExpDate=Q->FieldByName("MAX_EXP_DATE")->AsDateTime;
    Q->Close();
  }

  ED=ed;
  expDateEdit->ClickKey=VK_INSERT;
  if(ED->getID()==0)
  {
    if(int(lastExpDate)==0) lastExpDate=MainForm->getDate1();
    ED->setExpDate(lastExpDate);
    driverEdit->Text=MainForm->selectedOPS.Trim();
    Header->Caption="????? ??????";
    idLabel->Caption=IntToStr(ED->getID());
    gsmEdit->Text=ED->getGSMName();
    Kol->Text=IntToStr(ED->getKol());
    expEdit->Text=FloatToStr(ED->getExpense());
    expDateEdit->Date=ED->getExpDate();
    if (ED->getD()==1) CheckBox1->Checked = true; else CheckBox1->Checked = false;
  }
  else
  {
  Header->Caption="?????????????? ??????";
  idLabel->Caption=IntToStr(ED->getID());
  driverEdit->Text=ED->getDriverName();
  gsmEdit->Text=ED->getGSMName();
  Kol->Text=IntToStr(ED->getKol());
  expEdit->Text=FloatToStr(ED->getExpense());
  expDateEdit->Date=ED->getExpDate();
  if (ED->getD()==1) CheckBox1->Checked = true; else CheckBox1->Checked = false;
  }
}
//---------------------------------------------------------------------------
void __fastcall TAddEditExpenseForm::FormShow(TObject *Sender)
{
  if(MainForm->PC->ActivePageIndex == 2)
  {
  Label4->Visible=false;
  driverEdit->Visible=false;
  Label3->Visible=false;
  Kol->Visible=false;
  if (StrToFloat(expEdit->Text)>0.0)
  {
  expEdit->SetFocus();
  }else
  {
  gsmEdit->SetFocus();
  }
  }else
  {
  if(MainForm->ActivTable == 1)
  {
   if (GSM_DM->UserRole=="?????????????" || GSM_DM->UserRole=="????????????") CheckBox1->Visible=false; else CheckBox1->Visible=true;
  }

  Label4->Visible=true;
  driverEdit->Visible=true;
  if (ED->getGSMID()==92  || ED->getGSMID()==96 || ED->getGSMID()==97 || ED->getGSMID()==98 || ED->getGSMID()==103)
  {
  Label3->Visible=false;
  Kol->Visible=false;
  }else
  {
  Label3->Visible=true;
  Kol->Visible=true;
  }

  driverEdit->Enabled=false;
  if (StrToInt(Kol->Text)>0)
  {
  Kol->SetFocus();
  }else
  {
  gsmEdit->SetFocus();
  }
  }
}
//---------------------------------------------------------------------------
void __fastcall TAddEditExpenseForm::FormDestroy(TObject *Sender)
{

TIniFile* ini;

  if(int(lastExpDate)>0)
  { ini=new TIniFile(workDir+"AccountGSM.ini");
    ini->WriteDate("AddEditExpenseForm","lastExpDate",lastExpDate.DateString());
    delete ini;
  }
}
//---------------------------------------------------------------------------
void __fastcall TAddEditExpenseForm::SaveButtonClick(TObject *Sender)
{
  if(CheckBox1->Checked) ED->setD(1); else ED->setD(0);

  if(MainForm->ActivTable == 5)
  {
  if(expEdit->Text.IsEmpty() || gsmEdit->Text.IsEmpty() || exp==0.00)
  {
  MessageDlg("?????? ??????????? ??? ????? !!! ???????????? ?????? ??? ?????????? ?????? !!!",mtError,TMsgDlgButtons() << mbOK,0);
  }else
  {
  Close();
  ModalResult=mrOk;
  }
  }else
  {
  if (ED->getGSMID()==92  || ED->getGSMID()==96 || ED->getGSMID()==97 || ED->getGSMID()==98 || ED->getGSMID()==103)
  {
  if(Kol->Text.IsEmpty() || expEdit->Text.IsEmpty() || gsmEdit->Text.IsEmpty() || exp==0.00)
  {
  MessageDlg("?????? ??????????? ??? ????? !!! ???????????? ?????? ??? ?????????? ?????? !!!",mtError,TMsgDlgButtons() << mbOK,0);
  }else
  {
  Close();
  ModalResult=mrOk;
  }
  }else
  {
  if(Kol->Text.IsEmpty() || expEdit->Text.IsEmpty() || gsmEdit->Text.IsEmpty() ||  kol==0 || exp==0.00)
  {
  MessageDlg("?????? ??????????? ??? ????? !!! ???????????? ?????? ??? ?????????? ?????? !!!",mtError,TMsgDlgButtons() << mbOK,0);
  }else
  {
  Close();
  ModalResult=mrOk;
  }
  }
  }
}
//---------------------------------------------------------------------------
void __fastcall TAddEditExpenseForm::CancelButtonClick(TObject *Sender)
{
  Close();
  ModalResult=mrCancel;
}
//---------------------------------------------------------------------------
/*
void __fastcall TAddEditExpenseForm::wbnEditKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
  if(Key==VK_DOWN)
  { Key=0;
    ecEdit->SetFocus();
  }
  else if(Key==VK_UP){ Key=0; CancelButton->SetFocus(); }
}
//---------------------------------------------------------------------------
void __fastcall TAddEditExpenseForm::wbnEditKeyPress(TObject *Sender,
      char &Key)
{
  if(Key==VK_RETURN)
  { Key=0;
    if(ecEdit->Text.IsEmpty()) ecEdit->OnButtonClick(this);
    if(autoEdit->Text.IsEmpty()) autoEdit->OnButtonClick(this);
    if(driverEdit->Text.IsEmpty()) driverEdit->OnButtonClick(this);
    if(gsmEdit->Text.IsEmpty()) gsmEdit->OnButtonClick(this);
    if(int(expDateEdit->Date)==0) expDateEdit->OnButtonClick(this);
    expEdit->SetFocus();
  }
  else if(Key==VK_ESCAPE){ Key=0; CancelButton->Click(); }
}
//---------------------------------------------------------------------------
*/
AnsiString TAddEditExpenseForm::getRB_FieldData(AnsiString tableName,int id,AnsiString fieldName)
{
AnsiString sql;
TpFIBQuery *rq=GSM_DM->RQ;
AnsiString fieldData="";

  rq->Close();
  rq->SQL->Clear();
  sql="select "+fieldName+" from "+tableName+" where ID="+IntToStr(id);
  rq->SQL->Add(sql);
  try
  {
    rq->ExecQuery();
  }
  catch (Exception &exc)
  { MessageDlg("?????? - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
    return fieldData;
  }
  fieldData=rq->FieldByName(fieldName)->AsString;
  rq->Close();
  return fieldData;
}
//---------------------------------------------------------------------------
void __fastcall TAddEditExpenseForm::driverEditButtonClick(TObject *Sender)
{

if (MainForm->PC->ActivePageIndex == 0) MainForm->selectedMenu=1;
if (MainForm->PC->ActivePageIndex == 1) MainForm->selectedMenu=2;

TURB *dRB=MainForm->getDrivers_RB(ED->getSD_Name());

  if(dRB==NULL) return;
  dRB->LeftPanel->Enabled = false;
  if(dRB->ShowModal()==mrOk)
  {
    int did=StrToInt(dRB->getFieldInfo()->getFieldInfo(0)->getFieldData());
    AnsiString dn=dRB->getFieldInfo()->getFieldInfo(4)->getFieldData();
    ED->setDriverID(did);
    ED->setDriverName(dn);
    driverEdit->Text=dn;
  }
  delete dRB;
}
//---------------------------------------------------------------------------
void __fastcall TAddEditExpenseForm::driverEditKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
  if(Key==VK_DOWN)
  { Key=0;
    gsmEdit->SetFocus();
  }
  else if(Key == VK_UP){ Key=0; Kol->SetFocus(); }
  else if(Key == VK_INSERT)
  { Key=0;
    driverEdit->OnButtonClick(this);
    if(gsmEdit->Text.IsEmpty()) gsmEdit->OnButtonClick(this);
    if(int(expDateEdit->Date)==0) expDateEdit->OnButtonClick(this);
    Kol->SetFocus();
  }
}
//---------------------------------------------------------------------------
void __fastcall TAddEditExpenseForm::driverEditKeyPress(TObject *Sender,
      char &Key)
{
  if(Key==VK_RETURN)
  { Key=0;
    if(gsmEdit->Text.IsEmpty()) gsmEdit->OnButtonClick(this);
    if(int(expDateEdit->Date)==0) expDateEdit->OnButtonClick(this);
    Kol->SetFocus();
  }
  else if(Key == VK_ESCAPE){ Key=0; CancelButton->Click(); }
}
//---------------------------------------------------------------------------
void __fastcall TAddEditExpenseForm::gsmEditButtonClick(TObject *Sender)
{
TURB *gsmRB;
int gid;

  if(MainForm->PC->ActivePageIndex == 0 && MainForm->ActivTable == 1)
  {
  gsmRB=MainForm->getGSM_RB(1);
  gsmRB->FindPositionInTreeViewForFolderName("??????");
  }
  if(MainForm->PC->ActivePageIndex == 0 && MainForm->ActivTable == 2)
  {
  gsmRB=MainForm->getGSM_RB(1);
  gsmRB->FindPositionInTreeViewForFolderName("??????");
  }

  if(MainForm->PC->ActivePageIndex == 1 )
  {
   gsmRB=MainForm->getGSM_RB(1);
   gsmRB->FindPositionInTreeViewForFolderName("??????");

  /*  if (AnsiPos(GSM_DM->Index,MainForm->selectedOPS.Trim())>0){
   if (GSM_DM->UserRole!="?????????????" && GSM_DM->UserRole!="????????????"){
   gsmRB=MainForm->getGSM_RB(2);
   gsmRB->FindPositionInTreeViewForFolderName("??????");
   }else
   {
   gsmRB=MainForm->getGSM_RB(1);
   gsmRB->FindPositionInTreeViewForFolderName("??????");
   }
  }*/
  }
  if(MainForm->PC->ActivePageIndex == 2 )
  {
  gsmRB=MainForm->getGSM_RB(2);
  gsmRB->FindPositionInTreeViewForFolderName("????????????");
  }
  if(gsmRB==NULL) return;


  if(gsmRB->ShowModal()==mrOk)
  {
    gid=StrToInt(gsmRB->getFieldInfo()->getFieldInfo(0)->getFieldData());
  }

    AnsiString gn=gsmRB->getFieldInfo()->getFieldInfo(3)->getFieldData();
    ED->setGSMID(gid);
    ED->setGSMName(gn);
    gsmEdit->Text=gn;
  delete gsmRB;
}
//---------------------------------------------------------------------------
void __fastcall TAddEditExpenseForm::gsmEditKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
  if(Key==VK_DOWN)
  { Key=0;
    expDateEdit->SetFocus();
  }
  else if(Key == VK_UP){ Key=0; driverEdit->SetFocus(); }
  else if(Key == VK_INSERT)
  { Key=0;
    gsmEdit->OnButtonClick(this);
    if(int(expDateEdit->Date)==0) expDateEdit->OnButtonClick(this);
    Kol->SetFocus();
  }
}
//---------------------------------------------------------------------------
void __fastcall TAddEditExpenseForm::gsmEditKeyPress(TObject *Sender,
      char &Key)
{
  if(Key==VK_RETURN)
  { Key=0;
    if(int(expDateEdit->Date)==0) expDateEdit->OnButtonClick(this);
    expEdit->SetFocus();
  }
  else if(Key == VK_ESCAPE){ Key=0; CancelButton->Click(); }
  else if(Key == VK_INSERT)
  { Key=0;
    Kol->SetFocus();
  }
}
//---------------------------------------------------------------------------
void __fastcall TAddEditExpenseForm::expDateEditKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
  if(Key==VK_DOWN)
  { Key=0;
    if(MainForm->PC->ActivePageIndex == 2) expEdit->SetFocus();
    if(MainForm->PC->ActivePageIndex == 0 || MainForm->PC->ActivePageIndex == 1) Kol->SetFocus();
  }
  else if(Key == VK_UP){ Key=0; gsmEdit->SetFocus(); }
}
//---------------------------------------------------------------------------
void __fastcall TAddEditExpenseForm::expDateEditKeyPress(TObject *Sender,
      char &Key)
{
  if(Key==VK_RETURN)
  { Key=0;
    if(MainForm->PC->ActivePageIndex == 2) expEdit->SetFocus();
    if(MainForm->PC->ActivePageIndex == 0 || MainForm->PC->ActivePageIndex == 1) Kol->SetFocus();
  }
  else if(Key == VK_UP){ Key=0; gsmEdit->SetFocus(); }
  else if(Key == VK_ESCAPE){ Key=0; CancelButton->Click(); }
}
//---------------------------------------------------------------------------
void __fastcall TAddEditExpenseForm::expEditKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
  if(Key==VK_DOWN)
  { Key=0;
    if (gsmEdit->Text.Trim()=="???????")
    {
      if (AnsiPos("-",expEdit->Text.Trim())==0)
      {
      AnsiString Val;
      Val="-"+expEdit->Text.Trim();
      expEdit->Text=Val;
      }
    }else
    {
      if (AnsiPos("-",expEdit->Text.Trim())>0)
      {
      AnsiString Val;
      Val=expEdit->Text.Trim();
      expEdit->Text=Val.SubString(2,255);
      }
    }
    SaveButton->SetFocus();
  }
  else if(Key == VK_UP){ Key=0;
    if (gsmEdit->Text.Trim()=="???????")
    {
      if (AnsiPos("-",expEdit->Text.Trim())==0)
      {
      AnsiString Val;
      Val="-"+expEdit->Text.Trim();
      expEdit->Text=Val;
      }
    }else
    {
      if (AnsiPos("-",expEdit->Text.Trim())>0)
      {
      AnsiString Val;
      Val=expEdit->Text.Trim();
      expEdit->Text=Val.SubString(2,255);
      }
    }
  Kol->SetFocus(); }
}
//---------------------------------------------------------------------------
void __fastcall TAddEditExpenseForm::expEditKeyPress(TObject *Sender,
      char &Key)
{
  if(Key==VK_RETURN)
  { Key=0;
    if (gsmEdit->Text.Trim()=="???????")
    {
      if (AnsiPos("-",expEdit->Text.Trim())==0)
      {
      AnsiString Val;
      Val="-"+expEdit->Text.Trim();
      expEdit->Text=Val;
      }
    }else
    {
      if (AnsiPos("-",expEdit->Text.Trim())>0)
      {
      AnsiString Val;
      Val=expEdit->Text.Trim();
      expEdit->Text=Val.SubString(2,255);
      }
    }
    SaveButton->SetFocus();
  }
  else if(Key == VK_ESCAPE){ Key=0; CancelButton->Click(); }
}
//---------------------------------------------------------------------------
/*
void __fastcall TAddEditExpenseForm::wbnEditChange(TObject *Sender)
{
  ED->setWaybillNumber(wbnEdit->Text);
}
//---------------------------------------------------------------------------
*/
void __fastcall TAddEditExpenseForm::expEditChange(TObject *Sender)
{

  if(!Kol->Text.IsEmpty())
  {
  if(!expEdit->Text.IsEmpty())
  {
    try
    {
      exp=StrToFloat(expEdit->Text);
      ED->setExpense(exp);
    }
    catch (Exception &exc)
    { MessageDlg("???????? ????? ????????????? ???????????? ?????",mtError,TMsgDlgButtons() << mbOK,0);
      return;
    }
  }
  }
  else
  {
   MessageDlg("?????????? ??????? ?????????? !!!",mtWarning,TMsgDlgButtons() << mbOK,0);
   Kol->SetFocus();
  }
}
//---------------------------------------------------------------------------
void __fastcall TAddEditExpenseForm::expDateEditChange(TObject *Sender)
{
  if(this->Visible==true && !expEdit->Text.IsEmpty())
  { TDateTime dt;
    try
    {
      dt=expDateEdit->Date;
    }
    catch (Exception &exc)
    { MessageDlg("???????? ????? ????????????? ????",mtError,TMsgDlgButtons() << mbOK,0);
      return;
    }
    ED->setExpDate(dt);
    lastExpDate=dt;
    if(MainForm->PC->ActivePageIndex == 2) expEdit->SetFocus();
    if(MainForm->PC->ActivePageIndex == 0 || MainForm->PC->ActivePageIndex == 1) Kol->SetFocus();
  }
}
//---------------------------------------------------------------------------

void __fastcall TAddEditExpenseForm::KolChange(TObject *Sender)
{

  if(!Kol->Text.IsEmpty())
  {
    try
    {
      kol=StrToInt(Kol->Text);
      ED->setKol(kol);
    }
    catch (Exception &exc)
    {
      MessageDlg("???????? ????? ????????????? ????? ?????",mtError,TMsgDlgButtons() << mbOK,0);
      return;
    }
  }

}
//---------------------------------------------------------------------------

void __fastcall TAddEditExpenseForm::KolKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
  if(Key==VK_DOWN)
  {
    Key=0;
    if (gsmEdit->Text.Trim()=="???????")
    {
      if (AnsiPos("-",Kol->Text.Trim())==0)
      {
      AnsiString Val;
      Val="-"+Kol->Text.Trim();
      Kol->Text=Val;
      }
    }else
    {
      if (AnsiPos("-",Kol->Text.Trim())>0)
      {
      AnsiString Val;
      Val=Kol->Text.Trim();
      Kol->Text=Val.SubString(2,255);
      }
    }
    expEdit->SetFocus();
  }
  else if(Key == VK_UP){ Key=0;
      if (gsmEdit->Text.Trim()=="???????")
    {
      if (AnsiPos("-",Kol->Text.Trim())==0)
      {
      AnsiString Val;
      Val="-"+Kol->Text.Trim();
      Kol->Text=Val;
      }
    }else
    {
      if (AnsiPos("-",Kol->Text.Trim())>0)
      {
      AnsiString Val;
      Val=Kol->Text.Trim();
      Kol->Text=Val.SubString(2,255);
      }
    }
  expDateEdit->SetFocus(); }
}
//---------------------------------------------------------------------------

void __fastcall TAddEditExpenseForm::KolKeyPress(TObject *Sender,
      char &Key)
{
  if(Key==VK_RETURN)
  { Key=0;
    if (gsmEdit->Text.Trim()=="???????")
    {
      if (AnsiPos("-",Kol->Text.Trim())==0)
      {
      AnsiString Val;
      Val="-"+Kol->Text.Trim();
      Kol->Text=Val;
      }
    }else
    {
      if (AnsiPos("-",Kol->Text.Trim())>0)
      {
      AnsiString Val;
      Val=Kol->Text.Trim();
      Kol->Text=Val.SubString(2,255);
      }
    }
    expEdit->SetFocus();
  }
  else if(Key == VK_UP){ Key=0;
      if (gsmEdit->Text.Trim()=="???????")
    {
      if (AnsiPos("-",Kol->Text.Trim())==0)
      {
      AnsiString Val;
      Val="-"+Kol->Text.Trim();
      Kol->Text=Val;
      }
    }else
    {
      if (AnsiPos("-",Kol->Text.Trim())>0)
      {
      AnsiString Val;
      Val=Kol->Text.Trim();
      Kol->Text=Val.SubString(2,255);
      }
    }
  expDateEdit->SetFocus();
  }
  else if(Key == VK_ESCAPE){ Key=0; CancelButton->Click(); }
}
//---------------------------------------------------------------------------


void __fastcall TAddEditExpenseForm::CheckBox1Click(TObject *Sender)
{
  if(CheckBox1->Checked) ED->setD(1); else ED->setD(0);
}

//---------------------------------------------------------------------------

void __fastcall TAddEditExpenseForm::expEditEnter(TObject *Sender)
{
LoadKeyboardLayout("00000409", KLF_ACTIVATE);
}
//---------------------------------------------------------------------------

void __fastcall TAddEditExpenseForm::expEditExit(TObject *Sender)
{
LoadKeyboardLayout("00000419", KLF_ACTIVATE);        
}
//---------------------------------------------------------------------------

void __fastcall TAddEditExpenseForm::gsmEditChange(TObject *Sender)
{
 if(MainForm->PC->ActivePageIndex == 0 || MainForm->PC->ActivePageIndex == 1){
  if (ED->getGSMID()==92  || ED->getGSMID()==96 || ED->getGSMID()==97 || ED->getGSMID()==98 || ED->getGSMID()==103)
  {
  Label3->Visible=false;
  Kol->Visible=false;
  }else
  {
  Label3->Visible=true;
  Kol->Visible=true;
  }
}        
}
//---------------------------------------------------------------------------

