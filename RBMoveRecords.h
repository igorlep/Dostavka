//---------------------------------------------------------------------------

#ifndef RBMoveRecordsH
#define RBMoveRecordsH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "SmrtPanel.h"
#include <Buttons.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include "Placemnt.hpp"
//---------------------------------------------------------------------------
class TRBMoveRecordsForm : public TForm
{
__published:	// IDE-managed Components
        TSmrtPanel *SmrtPanel2;
        TBitBtn *MoveButton;
        TBitBtn *CancelButton;
        TBitBtn *CopyButton;
        TRichEdit *RichEdit;
        TTreeView *TreeView;
        TFormStorage *FormStorage;
        void __fastcall FormResize(TObject *Sender);
        void __fastcall CopyButtonClick(TObject *Sender);
        void __fastcall MoveButtonClick(TObject *Sender);
        void __fastcall CancelButtonClick(TObject *Sender);
        void __fastcall TreeViewChange(TObject *Sender, TTreeNode *Node);
        void __fastcall FormShow(TObject *Sender);
private:	// User declarations
        AnsiString workDir;
        AnsiString moveSectionID;
        AnsiString moveSectionDescription;
        bool copyFLG;
public:		// User declarations
        __fastcall TRBMoveRecordsForm(TComponent* Owner);
        AnsiString __fastcall getMoveSectionID(void){ return moveSectionID; }
        AnsiString __fastcall getMoveSectionDescription(void){ return moveSectionDescription; }
        bool __fastcall getCopyFLG(void){ return copyFLG; }
};
//---------------------------------------------------------------------------
//extern PACKAGE TRBMoveRecordsForm *RBMoveRecordsForm;
//---------------------------------------------------------------------------
#endif
