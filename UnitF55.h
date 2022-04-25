//---------------------------------------------------------------------------

#ifndef UnitF55H
#define UnitF55H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "RzPanel.hpp"
#include "RzRadGrp.hpp"
#include "ToolEdit.hpp"
#include <Buttons.hpp>
#include <ExtCtrls.hpp>
#include <Mask.hpp>
#include "FIBDataSet.hpp"
#include "pFIBDataSet.hpp"
#include "Placemnt.hpp"
#include <DB.hpp>
#include "CGAUGES.h"
//---------------------------------------------------------------------------
class TFormF55 : public TForm
{
__published:	// IDE-managed Components
        TPanel *Panel1;
        TLabel *Label2;
        TDateEdit *Date1Edit;
        TPanel *Panel2;
        TBitBtn *SaveButton;
        TpFIBDataSet *DS;
        TFormStorage *FormStorage;
        TCheckBox *CheckBox1;
        TLabel *Label4;
        TCheckBox *CheckBox3;
        TRzCheckGroup *CheckGroup2;
        TCheckBox *CheckBox2;
        TpFIBDataSet *DS1;
        TCGauge *Indicator;
        TLabel *Label1;
        void __fastcall FormDestroy(TObject *Sender);
        void __fastcall SaveButtonClick(TObject *Sender);
        void __fastcall p(void);
        void __fastcall Date1EditChange(TObject *Sender);
        void __fastcall CheckBox3Click(TObject *Sender);
        void __fastcall FormShow(TObject *Sender);
private:	// User declarations
  AnsiString workDir;
public:		// User declarations
        __fastcall TFormF55(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormF55 *FormF55;
//---------------------------------------------------------------------------
#endif
