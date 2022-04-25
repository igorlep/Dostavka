//---------------------------------------------------------------------------

#ifndef ReestrFormH
#define ReestrFormH
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
class TExpensesListOnAutoForm2 : public TForm
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
        TpFIBDataSet *DS1;
        TCheckBox *CheckBox1;
        void __fastcall FormDestroy(TObject *Sender);
        void __fastcall FormShow(TObject *Sender);
        void __fastcall SaveButtonClick(TObject *Sender);
//        void __fastcall sdRBButtonClick(TObject *Sender);
private:	// User declarations
  AnsiString workDir;
  TStringList *autoID;
public:		// User declarations
        __fastcall TExpensesListOnAutoForm2(TComponent* Owner);
};
//---------------------------------------------------------------------------
//extern PACKAGE TExpensesListOnAutoForm *ExpensesListOnAutoForm;
//---------------------------------------------------------------------------
#endif
