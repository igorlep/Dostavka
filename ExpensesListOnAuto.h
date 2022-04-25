//---------------------------------------------------------------------------

#ifndef ExpensesListOnAutoH
#define ExpensesListOnAutoH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <ExtCtrls.hpp>
#include "SmrtPanel.h"
#include "ToolEdit.hpp"
#include <Mask.hpp>
#include "FIBDataSet.hpp"
#include "frxClass.hpp"
#include "frxDBSet.hpp"
#include "frxExportXLS.hpp"
#include "pFIBDataSet.hpp"
#include "Placemnt.hpp"
#include <DB.hpp>
#include "RzPanel.hpp"
#include "RzRadGrp.hpp"
//---------------------------------------------------------------------------
class TExpensesListOnAutoForm : public TForm
{
__published:	// IDE-managed Components
        TPanel *Panel2;
        TBitBtn *SaveButton;
        TFormStorage *FormStorage;
        TpFIBDataSet *DS;
        TPanel *Panel1;
        TLabel *Label1;
        TComboBox *autoNumberEdit;
        TLabel *Label2;
        TDateEdit *Date1Edit;
        TRzCheckGroup *CheckGroup;
        TpFIBDataSet *DS1;
        TLabel *Label3;
        TComboBox *autoNumberEdit1;
        TpFIBDataSet *DS2;
        TCheckBox *CheckBox1;
        TCheckBox *CheckBox2;
        TLabel *Label4;
        TRzCheckGroup *CheckGroup2;
        TCheckBox *CheckBox3;
        void __fastcall FormDestroy(TObject *Sender);
        void __fastcall FormShow(TObject *Sender);
        void __fastcall SaveButtonClick(TObject *Sender);
        void __fastcall CheckGroupChange(TObject *Sender, int Index,
          TCheckBoxState NewState);
        void __fastcall autoNumberEditChange(TObject *Sender);
        void __fastcall p(void);
        void __fastcall Date1EditChange(TObject *Sender);
        void __fastcall CheckBox2Click(TObject *Sender);
        void __fastcall CheckBox1Click(TObject *Sender);
        void __fastcall CheckBox3Click(TObject *Sender);
//        void __fastcall sdRBButtonClick(TObject *Sender);
private:	// User declarations
  AnsiString workDir;
  TStringList *autoID;
  TStringList *autoID1;
public:		// User declarations
        AnsiString __fastcall getFIO(void);
        __fastcall TExpensesListOnAutoForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
//extern PACKAGE TExpensesListOnAutoForm *ExpensesListOnAutoForm;
//---------------------------------------------------------------------------
#endif
