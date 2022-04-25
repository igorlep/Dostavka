//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Main.h"
#include "DataModule.h"
#include "RBConfiguration.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "Placemnt"
#pragma link "DBGridEh"
#pragma link "FIBDataSet"
#pragma link "pFIBDataSet"
#pragma link "JvComponent"
#pragma link "JvExControls"
#pragma link "JvNavigationPane"
#pragma resource "*.dfm"
TRBConfigurationForm *RBConfigurationForm;
//---------------------------------------------------------------------------
__fastcall TRBConfigurationForm::TRBConfigurationForm(TComponent* Owner)
        : TForm(Owner)
{
  workDir=ExtractFilePath(Application->ExeName);
  FormStorage->IniFileName=workDir+"AccountGSM.ini";
  FormStorage->IniSection="RBConfigurationForm";

  loadProperties();
  RBDS->Open(); RBDS->Last(); RBDS->First();
//  rebootFLG=new bool[RBDS->RecordCount];
//  for(int i=0; i<RBDS->RecordCount; i++)
//    rebootFLG[i]=false;
  FieldsDS->Open();
}
//---------------------------------------------------------------------------
void __fastcall TRBConfigurationForm::FormShow(TObject *Sender)
{
  RBGrid->Visible=true;
}
//---------------------------------------------------------------------------
void __fastcall TRBConfigurationForm::FormClose(TObject *Sender,
      TCloseAction &Action)
{
  Action=caFree;
}
//---------------------------------------------------------------------------
void __fastcall TRBConfigurationForm::loadProperties(void)
{
TIniFile* ini;

  ini=new TIniFile(workDir+"AccountGSM.ini");
  RBPanel->Height=ini->ReadInteger("RBConfigurationForm","RBPanel_Height",150);
  delete ini;
}
//---------------------------------------------------------------------------
void __fastcall TRBConfigurationForm::saveProperties(void)
{
TIniFile* ini;

  FieldsDS->Close();
  RBDS->Close();

  ini=new TIniFile(workDir+"AccountGSM.ini");
  ini->WriteInteger("RBConfigurationForm","RBPanel_Height",RBPanel->Height);
  delete ini;
}
//---------------------------------------------------------------------------
//
void __fastcall TRBConfigurationForm::FormDestroy(TObject *Sender)
{
  saveProperties();
//  delete []rebootFLG;
}
//---------------------------------------------------------------------------
//Перегрузка справочника
/*
void __fastcall TRBConfigurationForm::RebootButtonClick(TObject *Sender)
{
  if(RBDS->State==dsEdit || RBDS->State==dsInsert) RBDS->Post();
  if(FieldsDS->State==dsEdit || FieldsDS->State==dsInsert) FieldsDS->Post();

  if(MessageDlg("Вы уверены, что хотите перегрузить справочник \""+RBDS->FieldByName("RB_TITLE")->AsString+"\"",mtConfirmation,TMsgDlgButtons() << mbOK << mbCancel,0)==mrOk)
  { MainForm->setRB(RBDS->FieldByName("RB_TABLE_NAME")->AsString);
    rebootFLG[RBDS->RecNo-1]=false;
    RebootButton->Enabled=rebootFLG[RBDS->RecNo-1];
  }
}
//---------------------------------------------------------------------------
//
void __fastcall TRBConfigurationForm::RBDSAfterPost(TDataSet *DataSet)
{
//  rebootFLG[RBDS->RecNo-1]=true;
//  RebootButton->Enabled=rebootFLG[RBDS->RecNo-1];
}
//---------------------------------------------------------------------------
//
void __fastcall TRBConfigurationForm::FieldsDSAfterPost(TDataSet *DataSet)
{
//  rebootFLG[RBDS->RecNo-1]=true;
//  RebootButton->Enabled=rebootFLG[RBDS->RecNo-1];
}
//---------------------------------------------------------------------------
*/
void __fastcall TRBConfigurationForm::RBPostButtonClick(TObject *Sender)
{
  if(RBDS->State==dsEdit || RBDS->State==dsInsert) RBDS->Post();
}
//---------------------------------------------------------------------------
void __fastcall TRBConfigurationForm::RBCancelButtonClick(TObject *Sender)
{
  if(RBDS->State==dsEdit || RBDS->State==dsInsert) RBDS->Cancel();
}
//---------------------------------------------------------------------------
void __fastcall TRBConfigurationForm::RBSStateChange(TObject *Sender)
{
  if(RBDS->State==dsEdit || RBDS->State==dsInsert)
  { RBPostButton->Enabled=true;
    RBCancelButton->Enabled=true;
  }
  else
  { RBPostButton->Enabled=false;
    RBCancelButton->Enabled=false;
  }
}
//---------------------------------------------------------------------------
void __fastcall TRBConfigurationForm::FIPostButtonClick(TObject *Sender)
{
  if(FieldsDS->State==dsEdit || FieldsDS->State==dsInsert) FieldsDS->Post();
}
//---------------------------------------------------------------------------
void __fastcall TRBConfigurationForm::FICancelButtonClick(TObject *Sender)
{
  if(FieldsDS->State==dsEdit || FieldsDS->State==dsInsert) FieldsDS->Cancel();
}
//---------------------------------------------------------------------------
void __fastcall TRBConfigurationForm::FieldsSStateChange(TObject *Sender)
{
  if(FieldsDS->State==dsEdit || FieldsDS->State==dsInsert)
  { FIPostButton->Enabled=true;
    FICancelButton->Enabled=true;
  }
  else
  { FIPostButton->Enabled=false;
    FICancelButton->Enabled=false;
  }
}
//---------------------------------------------------------------------------
void __fastcall TRBConfigurationForm::RBSDataChange(TObject *Sender,
      TField *Field)
{
//  if(RBGrid->Visible) RebootButton->Enabled=rebootFLG[RBDS->RecNo-1];
}
//---------------------------------------------------------------------------
void __fastcall TRBConfigurationForm::FieldsDSBeforePost(TDataSet *DataSet)
{
  if(FieldsDS->FieldByName("ACCESSABLE")->AsInteger==0)
  { FieldsDS->FieldByName("EDITABLE")->AsInteger=0;
    FieldsDS->FieldByName("GRID_VIEWABLE")->AsInteger=0;
  }
}
//---------------------------------------------------------------------------

