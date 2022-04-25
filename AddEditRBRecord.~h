//---------------------------------------------------------------------------

#ifndef AddEditRBRecordH
#define AddEditRBRecordH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <ExtCtrls.hpp>
#include "ToolEdit.hpp"
#include <Mask.hpp>
#include "SmrtPanel.h"
#include <ActnList.hpp>
#include "UniversalReferenceBook.h"
#include "JvComponent.hpp"
#include "JvExControls.hpp"
#include "JvSpeedButton.hpp"
#include "JvBitBtn.hpp"
#include "JvExButtons.hpp"
//***************************************************************************
class RBEditorElement
{
private:
        TComponent* Owner;
        TLabel *label;
        TControl *edit;
        RBEditorElement *prevEditableElement;
        RBEditorElement *nextEditableElement;
        int fieldNumber;
        MFieldInfo *fieldInfo;
        bool editable;
        void __fastcall ComboEditOnClickButton(TObject* Sender);
        void __fastcall ComboEditOnMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift, int X, int Y);
        void __fastcall EditOnKeyDown(TObject* Sender, unsigned short &, TShiftState);
        void __fastcall EditOnKeyPress(TObject* Sender, char &);
public:
        __fastcall RBEditorElement(){ label=NULL; edit=NULL; fieldNumber=0; }
        __fastcall RBEditorElement(TComponent* Owner, MFieldInfo *fi, int fieldNumber);
        __fastcall ~RBEditorElement(void);
        TLabel* __fastcall getLabel(void){ return label; }
        TControl* __fastcall getEdit(void){ return edit; }
        bool __fastcall isEditable(void){ return editable; }
        int __fastcall getFieldNumber(void){ return fieldNumber; }
        MFieldInfo* __fastcall getFieldInfo(void){ return fieldInfo; }
        RBEditorElement * __fastcall getPrevEAE(void){ return prevEditableElement; }
        RBEditorElement * __fastcall getNextEAE(void){ return nextEditableElement; }
        void __fastcall setPrevEAE(RBEditorElement *pe){ prevEditableElement=pe; }
        void __fastcall setNextEAE(RBEditorElement *ne){ nextEditableElement=ne; }
};
//---------------------------------------------------------------------------
class TAddEditRBRecordForm : public TForm
{
__published:	// IDE-managed Components
        TPanel *workPanel;
        TJvBitBtn *SaveButton;
        TJvBitBtn *CancelButton;
        void __fastcall FormDestroy(TObject *Sender);
        void __fastcall FormShow(TObject *Sender);
        void __fastcall SaveButtonClick(TObject *Sender);
        void __fastcall SaveButtonKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall CancelButtonClick(TObject *Sender);
        void __fastcall CancelButtonKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
private:	// User declarations
        AnsiString workDir;
        TURB *RB;
        MFieldsInformation *FI;
        int accessableFieldsCount;
        int editableFieldsCount;
        RBEditorElement **RB_EE;
        bool newRecordFLG;
public:		// User declarations
        __fastcall TAddEditRBRecordForm(TComponent* Owner, MFieldsInformation *FI, bool newRecodFLG);
        void __fastcall getProperties(void);
        void __fastcall setProperties(void);
        RBEditorElement * __fastcall findEAE(int fieldNumber);
        RBEditorElement * __fastcall getFirstEAE(void);
        RBEditorElement * __fastcall getLastEAE(void);
        MFieldsInformation *  __fastcall getFI(void){ return FI; }
};
//---------------------------------------------------------------------------
//extern PACKAGE TAddEditRBRecordForm *AddEditRBRecordForm;
//---------------------------------------------------------------------------
#endif
