//---------------------------------------------------------------------------

#ifndef ReestrSumH
#define ReestrSumH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "FIBDataSet.hpp"
#include "pFIBDataSet.hpp"
#include "Placemnt.hpp"
#include "ToolEdit.hpp"
#include <Buttons.hpp>
#include <DB.hpp>
#include <ExtCtrls.hpp>
#include <Mask.hpp>
//---------------------------------------------------------------------------
class TExpensesListOnAutoForm5 : public TForm
{
__published:	// IDE-managed Components
        TPanel *Panel2;
        TBitBtn *SaveButton;
        TPanel *Panel1;
        TLabel *Label1;
        TLabel *Label2;
        TComboBox *autoNumberEdit;
        TDateEdit *Date1Edit;
        TFormStorage *FormStorage;
        TpFIBDataSet *DS;
        TpFIBDataSet *DS1;
        TpFIBDataSet *DS2;
        TpFIBDataSet *DS3;
        TpFIBDataSet *DS5;
        TpFIBDataSet *DS6;
        TpFIBDataSet *DS4;
        void __fastcall FormDestroy(TObject *Sender);
        void __fastcall FormShow(TObject *Sender);
        void __fastcall SaveButtonClick(TObject *Sender);
private:	// User declarations
  AnsiString workDir;
  TStringList *autoID;
public:		// User declarations
        __fastcall TExpensesListOnAutoForm5(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TExpensesListOnAutoForm5 *ExpensesListOnAutoForm5;
//---------------------------------------------------------------------------
#endif
