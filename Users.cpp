//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Main.h"
#include "DataModule.h"
#include "ChangePass.h"
#include "Users.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "Placemnt"
#pragma link "DBGridEh"
#pragma link "FIBDataSet"
#pragma link "pFIBDataSet"
#pragma link "FIBDatabase"
#pragma link "pFIBDatabase"
#pragma resource "*.dfm"
//TUsersForm *UsersForm;
//---------------------------------------------------------------------------
__fastcall TUsersForm::TUsersForm(TComponent* Owner)
        : TForm(Owner)
{
  AnsiString sql;

  if(GSM_DM->UserRole=="?????????????" || GSM_DM->UserRole=="????????????")
  { sql="select * from USERS_TABLE";
    usersDS->SQLs->SelectSQL->Clear();
    usersDS->SQLs->SelectSQL->Add(sql);
    N1->Visible=true;
    N2->Visible=true;
    N3->Visible=true;
    N5->Visible=true;
    usersGrid->ReadOnly=false;
  }
  else
  { sql="select * from USERS_TABLE where U_ID="+IntToStr(GSM_DM->UserID);
    usersDS->SQLs->SelectSQL->Clear();
    usersDS->SQLs->SelectSQL->Add(sql);
    N1->Visible=false;
    N2->Visible=false;
    N3->Visible=false;
    N5->Visible=false;
    usersGrid->ReadOnly=true;
    usersGrid->Options << dgRowSelect;
  }

  try
  {
    usersDS->Open();
  }
  catch (Exception &exc)
  { MessageDlg("?????? ???????? ??????? USERS_TABLE\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
    return;
  }

}
//---------------------------------------------------------------------------
void __fastcall TUsersForm::usersSStateChange(TObject *Sender)
{
  if(usersDS->State==dsEdit || usersDS->State==dsInsert)
  { PostButton->Enabled=true;
    CancelButton->Enabled=true;
  }
  else
  { PostButton->Enabled=false;
    CancelButton->Enabled=false;
  }
}
//---------------------------------------------------------------------------
void __fastcall TUsersForm::PostButtonClick(TObject *Sender)
{
  if(usersDS->State==dsEdit || usersDS->State==dsInsert) usersDS->Post();
}
//---------------------------------------------------------------------------
void __fastcall TUsersForm::CancelButtonClick(TObject *Sender)
{
  if(usersDS->State==dsEdit || usersDS->State==dsInsert) usersDS->Cancel();
}
//---------------------------------------------------------------------------
//???????? ????????????
void __fastcall TUsersForm::N1Click(TObject *Sender)
{
  try
  {
    usersDS->Append();
  }
  catch (Exception &exc)
  { MessageDlg("?????? ?????????? ????????????\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
    return;
  }
}
//---------------------------------------------------------------------------
//????????????? ?????? ? ????????????
void __fastcall TUsersForm::N2Click(TObject *Sender)
{
  try
  {
    usersDS->Edit();
  }
  catch (Exception &exc)
  { MessageDlg("?????? ?????????????? ????????????\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
    return;
  }
}
//---------------------------------------------------------------------------
//???????? ????????????
void __fastcall TUsersForm::N3Click(TObject *Sender)
{
  if(MessageDlg("?? ???????, ??? ?????? ??????? ?????? ? ??????? ?????????????",mtConfirmation,TMsgDlgButtons() << mbOK << mbCancel,0)==mrOk)
  {
    try
    {
      usersDS->Delete();
    }
    catch (Exception &exc)
    { MessageDlg("?????? ???????? ????????????\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      return;
    }
  }
}
//---------------------------------------------------------------------------
//???????? ??????? ??????
void __fastcall TUsersForm::N5Click(TObject *Sender)
{
TpFIBQuery *Q=GSM_DM->RQ;
AnsiString sql;

  Q->Close();
  Q->SQL->Clear();
  sql="select U_NAME, U_PASSWORD from USERS_TABLE where U_ID="+usersDS->FieldByName("U_ID")->AsString;
  Q->SQL->Add(sql);
  try
  {
    Q->ExecQuery();
  }
  catch (Exception &exc)
  { MessageDlg("?????? - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
    return;
  }
  MessageDlg("??????????? - \""+Q->FieldByName("U_NAME")->AsString+"\", ?????? - \""+Q->FieldByName("U_PASSWORD")->AsString+"\"",mtInformation,TMsgDlgButtons() << mbOK,0);
  Q->Close();
}
//---------------------------------------------------------------------------
void __fastcall TUsersForm::N4Click(TObject *Sender)
{
TChangePassForm *CPF;
int ID=usersDS->FieldByName("U_ID")->AsInteger;

  try
  {
    CPF=new TChangePassForm(this,ID);
  }
  catch (Exception &exc)
  { MessageDlg("?????? ???????? ????? ChangePassForm\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
    return;
  }
  CPF->ShowModal();
  delete CPF;
}
//---------------------------------------------------------------------------
void __fastcall TUsersForm::usersGridKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
  if(Key == VK_F11)
  { TRect r=usersGrid->CellRect(usersGrid->Col,usersGrid->Row);
    int x=this->Left+r.Left+r.Width();
    int y=this->Top+usersGrid->Top+r.Top+r.Height()+15;
    usersPM->Popup(x,y);
  }
}
//---------------------------------------------------------------------------


void __fastcall TUsersForm::reloadButtonClick(TObject *Sender)
{
TpFIBQuery *Q=GSM_DM->RQ;
TpFIBQuery *QW=GSM_DM->WQ;

AnsiString sql;

    sql="select * from USERS";
    usersINS->SQLs->SelectSQL->Clear();
    usersINS->SQLs->SelectSQL->Add(sql);

  try
  {
    usersINS->Open();
  }
  catch (Exception &exc)
  { MessageDlg("?????? ???????? ??????? USERS ?? ?? ?????????\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
    return;
  }

  usersINS->First();
  while(!usersINS->Eof)
  {
    AnsiString username=usersINS->FieldByName("LOGIN")->AsString.Trim();
    int id=usersINS->FieldByName("ID")->AsInteger;
    Q->Close();
    Q->SQL->Clear();
    sql="select U_ID from USERS_TABLE where U_LOGIN='"+username+"'";
    Q->SQL->Add(sql);
    try
    {
    Q->ExecQuery();
    }
    catch (Exception &exc)
    { MessageDlg("?????? - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      return;
    }

  if(Q->FieldByName("U_ID")->AsInteger > 0)
  {
    QW->Close();
    QW->SQL->Clear();
    sql="update USERS_TABLE set IDINS = " +IntToStr(id);
    sql+=" where U_ID="+IntToStr(Q->FieldByName("U_ID")->AsInteger);
    QW->SQL->Add(sql);
    QW->Transaction->StartTransaction();
    try
    {
      QW->ExecQuery();
    }
    catch (Exception &exc)
    {
      MessageDlg("?????? - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      QW->Transaction->Rollback();
      return;
    }
    QW->Transaction->Commit();
  }
  else
  {
  MessageDlg("???????????? - "+username+" ?? ?????? ? ?? ????????. ?????????? ??? ???????? ? ?? ???????? ? ????? ??????? ????????????? ??????!",mtInformation,TMsgDlgButtons() << mbOK,0);
  return;
  }
  Q->Close();
  usersINS->Next();
  }
usersINS->Close();
MessageDlg("????????????? ?????? ????????? ???????!",mtInformation,TMsgDlgButtons() << mbOK,0);
}
//---------------------------------------------------------------------------

