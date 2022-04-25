//---------------------------------------------------------------------------

#ifndef AddEditExpenseH
#define AddEditExpenseH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "Placemnt.hpp"
#include <Buttons.hpp>
#include <ExtCtrls.hpp>
#include "JvComponent.hpp"
#include "JvExControls.hpp"
#include "JvNavigationPane.hpp"
#include "ToolEdit.hpp"
#include <Mask.hpp>
#include "JvBitBtn.hpp"
#include "JvExButtons.hpp"
#include "JvBevel.hpp"
#include "JvExExtCtrls.hpp"
#include "DataModule.h"
#include "JvCheckedMaskEdit.hpp"
#include "JvDatePickerEdit.hpp"
#include "JvExMask.hpp"
#include "JvMaskEdit.hpp"
#include "JvToolEdit.hpp"
#include "JvEdit.hpp"
#include "JvExStdCtrls.hpp"
#include "JvValidateEdit.hpp"
//---------------------------------------------------------------------------
class TAddEditExpenseForm : public TForm
{
__published:	// IDE-managed Components
        TFormStorage *FormStorage;
        TJvNavPanelHeader *Header;
        TPanel *Panel1;
        TLabel *Label1;
        TLabel *Label4;
        TComboEdit *driverEdit;
        TJvBitBtn *SaveButton;
        TJvBitBtn *CancelButton;
        TLabel *Label5;
        TComboEdit *gsmEdit;
        TLabel *Label6;
        TLabel *Label7;
        TDateEdit *expDateEdit;
        TJvBevel *JvBevel1;
        TLabel *Label8;
        TLabel *idLabel;
        TBevel *Bevel1;
        TJvValidateEdit *expEdit;
        TLabel *Label3;
        TJvValidateEdit *Kol;
        TCheckBox *CheckBox1;
        void __fastcall SaveButtonClick(TObject *Sender);
        void __fastcall CancelButtonClick(TObject *Sender);
        void __fastcall FormShow(TObject *Sender);
        void __fastcall driverEditButtonClick(TObject *Sender);
        void __fastcall gsmEditButtonClick(TObject *Sender);
//        void __fastcall wbnEditChange(TObject *Sender);
        void __fastcall expDateEditChange(TObject *Sender);
        void __fastcall FormDestroy(TObject *Sender);
        void __fastcall expDateEditKeyPress(TObject *Sender, char &Key);
        void __fastcall driverEditKeyPress(TObject *Sender, char &Key);
        void __fastcall gsmEditKeyPress(TObject *Sender, char &Key);
        void __fastcall driverEditKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall gsmEditKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall expDateEditKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall expEditChange(TObject *Sender);
        void __fastcall expEditKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall expEditKeyPress(TObject *Sender, char &Key);
        void __fastcall KolChange(TObject *Sender);
        void __fastcall KolKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall KolKeyPress(TObject *Sender, char &Key);
        void __fastcall CheckBox1Click(TObject *Sender);
        void __fastcall expEditEnter(TObject *Sender);
        void __fastcall expEditExit(TObject *Sender);
        void __fastcall gsmEditChange(TObject *Sender);
private:	// User declarations
  AnsiString workDir;
  ExpensesData *ED;
  TDateTime lastExpDate;
  AnsiString getRB_FieldData(AnsiString tableName,int id,AnsiString fieldName);
public:		// User declarations
  __fastcall TAddEditExpenseForm(TComponent* Owner, ExpensesData *ed);
  int kol;
  double exp;
  ExpensesData *__fastcall getED(void){ return ED; }
};
//---------------------------------------------------------------------------
//extern PACKAGE TAddEditExpenseForm *AddEditExpenseForm;
//---------------------------------------------------------------------------
#endif
