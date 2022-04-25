//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UniversalReferenceBook.h"
#include "RBMoveRecords.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "SmrtPanel"
#pragma link "Placemnt"
#pragma resource "*.dfm"
//TRBMoveRecordsForm *RBMoveRecordsForm;
//---------------------------------------------------------------------------
__fastcall TRBMoveRecordsForm::TRBMoveRecordsForm(TComponent* Owner)
        : TForm(Owner)
{
  workDir=ExtractFilePath(Application->ExeName);
  FormStorage->IniFileName=workDir+"AccountGSM.ini";
  FormStorage->IniSection="RBMoveRecordsForm";
  moveSectionID=0;
}
//---------------------------------------------------------------------------
void __fastcall TRBMoveRecordsForm::FormShow(TObject *Sender)
{
  TreeView->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TRBMoveRecordsForm::FormResize(TObject *Sender)
{
  RichEdit->Repaint();
}
//---------------------------------------------------------------------------
void __fastcall TRBMoveRecordsForm::CopyButtonClick(TObject *Sender)
{
  copyFLG=true;
  Close();
  ModalResult=mrOk;
}
//---------------------------------------------------------------------------
void __fastcall TRBMoveRecordsForm::MoveButtonClick(TObject *Sender)
{
  copyFLG=false;
  Close();
  ModalResult=mrOk;
}
//---------------------------------------------------------------------------
void __fastcall TRBMoveRecordsForm::CancelButtonClick(TObject *Sender)
{
  Close();
  ModalResult=mrCancel;
}
//---------------------------------------------------------------------------
void __fastcall TRBMoveRecordsForm::TreeViewChange(TObject *Sender,
      TTreeNode *Node)
{
  moveSectionID=((RBTreeData*)TreeView->Selected->Data)->data;
  moveSectionDescription=TreeView->Selected->Text;
}
//---------------------------------------------------------------------------

