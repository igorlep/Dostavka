//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "DataModule.h"
#include "Main.h"
#include "RestoreBase.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "Placemnt"
#pragma link "IB_Services"
#pragma link "ToolEdit"
#pragma link "ZipBuilder"
#pragma link "RxRichEd"
#pragma resource "*.dfm"
TRestoreBaseForm *RestoreBaseForm;
//---------------------------------------------------------------------------
__fastcall TRestoreBaseForm::TRestoreBaseForm(TComponent* Owner)
        : TForm(Owner)
{
  FormStorage1->IniFileName=MainForm->workDir+"AccountGSM.ini";
  FormStorage1->IniSection="RestoreBaseForm";

  Label2->Caption="???? ?????? - "+GSM_DM->Server+GSM_DM->DB_Name;
  TIniFile *ini = new TIniFile(MainForm->workDir+"AccountGSM.ini");
  FilenameEdit->InitialDir=ini->ReadString("RestoreBaseForm","RestoreDir","");
  NetFilenameEdit->InitialDir=ini->ReadString("RestoreBaseForm","NetRestoreDir","");
  delete ini;
}
//---------------------------------------------------------------------------
void __fastcall TRestoreBaseForm::FormClose(TObject *Sender,
      TCloseAction &Action)
{
  TIniFile *ini = new TIniFile(MainForm->workDir+"AccountGSM.ini");
  ini->WriteString("RestoreBaseForm","RestoreDir",ExtractFileDir(FilenameEdit->FileName));
  ini->WriteString("RestoreBaseForm","NetRestoreDir",ExtractFileDir(NetFilenameEdit->FileName));
  delete ini;

  SetCurrentDir(MainForm->workDir);
  Action=caFree;
}
//---------------------------------------------------------------------------
void __fastcall TRestoreBaseForm::ExitButtonClick(TObject *Sender)
{
  Close();
}
//---------------------------------------------------------------------------
void __fastcall TRestoreBaseForm::FilenameEditAfterDialog(TObject *Sender,
      AnsiString &Name, bool &Action)
{
  if(Action)
  { if(ExtractFileExt(Name).LowerCase()==".gbk")
    { BackUpFileName=Name;
      ZipFileName="";
    }
    else
    { ZipFileName=Name;
      BackUpFileName=ExtractFilePath(Name)+ChangeFileExt(GSM_DM->Base_Name,".gbk");
    }
    RestoreButton->Enabled=true;
  }
}
//---------------------------------------------------------------------------
void __fastcall TRestoreBaseForm::NetFilenameEditAfterDialog(TObject *Sender,
      AnsiString &Name, bool &Action)
{
  if(Action)
  { if(ExtractFileExt(Name).LowerCase()==".gdb") DBNetName = Name;
    else
    { MessageDlg("?????????? ??????? ???????????? ???? ?????? dbGSM.gdb",mtError,TMsgDlgButtons() << mbOK,0);
      Action=false;
    }
  }
}
//---------------------------------------------------------------------------
void __fastcall TRestoreBaseForm::RestoreButtonClick(TObject *Sender)
{
  if(MessageDlg("?????????????? ???? ?????? ?????????? ????????? ? ??????????? ??????.\n???????????",mtWarning,TMsgDlgButtons() << mbOK << mbCancel,0)==mrCancel) return;

  if(DBNetName.IsEmpty() || !FileExists(DBNetName))
  { if(DBNetName.IsEmpty()) MessageDlg("?? ??????? ??????? ??? ???? ??????",mtError,TMsgDlgButtons() << mbOK,0);
    else MessageDlg("???? - "+DBNetName+" ???????????",mtError,TMsgDlgButtons() << mbOK,0);
    return;
  }
  RichEdit1->Lines->Clear();
  RichEdit1->SetFocus();
  TColor color=RichEdit1->DefAttributes->Color;
  int size=RichEdit1->DefAttributes->Size;
  RichEdit1->SelAttributes->Color=clRed;
  RichEdit1->SelAttributes->Size=10;

  //????????????? ?????
  if(!ZipFileName.IsEmpty())
  { RichEdit1->Lines->Add("?????????? BackUp ????? ?? ??????...");
    RichEdit1->Repaint();

    GSM_DM->ZipBuilder->ZipFileName=ZipFileName;
    GSM_DM->ZipBuilder->ExtrBaseDir=ExtractFilePath(ZipFileName);
    GSM_DM->ZipBuilder->FSpecArgs->Clear();
    GSM_DM->ZipBuilder->ExtrOptions.Clear();
    GSM_DM->ZipBuilder->ExtrOptions << ExtrOverWrite;
    GSM_DM->ZipBuilder->Extract();
    if(GSM_DM->ZipBuilder->SuccessCnt != 1)
    { MessageDlg("?????? ?????????? BackUp ?????",mtError,TMsgDlgButtons() << mbOK,0);
      RichEdit1->Lines->Clear();
      return;
    }

    RichEdit1->SelAttributes->Color=clBlue;
    RichEdit1->SelAttributes->Size=10;
    RichEdit1->Lines->Add("BackUp ???? ????????!");
    RichEdit1->Repaint();
  }


  MainForm->workDS->Close();
  GSM_DM->DisConnectDataBase();

  //????????? ?????? ????
  RichEdit1->SelAttributes->Color=clRed;
  RichEdit1->SelAttributes->Size=10;
  RichEdit1->Lines->Add("????????? ?????? ???? ??????");
  RichEdit1->Repaint();

  AnsiString OldDBFileName;
  OldDBFileName=DBNetName.SubString(1,DBNetName.Pos("."))+"old";

  int hDB, hOldDB;
  hDB=FileOpen(DBNetName,fmOpenRead);
  if(hDB < 0)
  { MessageDlg("?????? ???????? ????? - "+DBNetName,mtError,TMsgDlgButtons() << mbOK,0);
    RichEdit1->Lines->Clear();
    return;
  }
  if(FileExists(OldDBFileName)) DeleteFile(OldDBFileName);
  hOldDB=FileCreate(OldDBFileName);
  if(hOldDB < 0)
  { MessageDlg("?????? ???????? ????? - "+OldDBFileName,mtError,TMsgDlgButtons() << mbOK,0);
    RichEdit1->Lines->Clear();
    return;
  }
  char buf[32768];
  int rb=0;
  while((rb=FileRead(hDB,buf,sizeof(buf))) > 0)
  { if(FileWrite(hOldDB,buf,rb) < 0)
    { MessageDlg("?????? ??????????? ????? - ",mtError,TMsgDlgButtons() << mbOK,0);
      RichEdit1->Lines->Clear();
      return;
    }
  }
  FileClose(hDB);
  FileClose(hOldDB);

  RichEdit1->SelAttributes->Color=clBlue;
  RichEdit1->SelAttributes->Size=10;
  RichEdit1->Lines->Add("?????? ???? ????????? ? ????? - "+OldDBFileName);
  RichEdit1->Repaint();

  //?????????? ??????
  RestoreService->ServerName=GSM_DM->Server.SubString(0,GSM_DM->Server.Length()-1);
  RestoreService->LoginPrompt=false;
  RestoreService->Params->Clear();
  RestoreService->Params->Add("user_name=SYSDBA");
  RestoreService->Params->Add("password=masterkey");
  RestoreService->Protocol=TCP;
  RestoreService->Active = true;
  if(CheckBox1->Checked) RestoreService->Verbose = true;
  else RestoreService->Verbose = false;
  RestoreService->Options.Clear();
  RestoreService->Options << Replace << UseAllSpace;
  RestoreService->PageSize=8192;
  RestoreService->DatabaseName->Clear();
  RestoreService->DatabaseName->Add(GSM_DM->Database->DatabaseName);
  RestoreService->BackupFile->Clear();
  if(GSM_DM->Database->DatabaseName.Pos("/"))
////
    RestoreService->BackupFile->Add("/tmp/archives/GSM/"+ExtractFileName(BackUpFileName));
////
  else RestoreService->BackupFile->Add(BackUpFileName);

  RichEdit1->SelAttributes->Color=clRed;
  RichEdit1->SelAttributes->Size=10;
  RichEdit1->Lines->Add("?????????????? ???? ?????? ?? BackUp ?????...");
  RichEdit1->SelAttributes->Color=color;
  RichEdit1->SelAttributes->Size=size;
  RichEdit1->Repaint();
  try
  {
    RestoreService->ServiceStart();
  }
  catch(const Exception &exc)
  { MessageDlg("?????? ??????? RestoreUp ???????\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
    return;
  }

  try
  { while(!RestoreService->Eof)
    { AnsiString s=RestoreService->GetNextChunk();
      if(CheckBox1->Checked)
      { RichEdit1->Lines->Add(s);
        RichEdit1->Repaint();
      }
    }
  }
  catch(const Exception &exc)
  { MessageDlg("?????? ?????????????? BackUp ?????\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
    return;
  }

  RestoreService->Active=false;

  RichEdit1->SelAttributes->Color=clBlue;
  RichEdit1->SelAttributes->Size=10;
  RichEdit1->Lines->Add("???? ?????? ?????????????!");
  RichEdit1->Repaint();

  //???????? BackUp ?????
  if(!ZipFileName.IsEmpty() && FileExists(BackUpFileName))
  { RichEdit1->SelAttributes->Color=clRed;
    RichEdit1->SelAttributes->Size=10;
    RichEdit1->Lines->Add("???????? BackUp ?????...");
    RichEdit1->Repaint();
    DeleteFile(BackUpFileName);
    RichEdit1->SelAttributes->Color=clBlue;
    RichEdit1->SelAttributes->Size=10;
    if(!FileExists(BackUpFileName))
      RichEdit1->Lines->Add("???? ??????!");
    else
      MessageDlg("?? ???? ??????? BackUp ???? - "+BackUpFileName,mtError,TMsgDlgButtons() << mbOK,0);
    RichEdit1->Lines->Add("\n");
    RichEdit1->SelAttributes->Color=clBlue;
    RichEdit1->SelAttributes->Size=10;
    RichEdit1->Lines->Add("???????? ?????????!");
    RichEdit1->Repaint();
  }

  RichEdit1->SelAttributes->Color=color;
  RichEdit1->SelAttributes->Size=size;

  GSM_DM->ConnectToDataBase();
  MainForm->initMainForm();
  MainForm->LoadWorkDS(MainForm->getSD_ID(),MainForm->getID());
}
//---------------------------------------------------------------------------

