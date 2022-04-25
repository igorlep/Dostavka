//---------------------------------------------------------------------------

#ifndef ExpensesListOnDateH
#define ExpensesListOnDateH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "FIBDataSet.hpp"
#include "frxClass.hpp"
#include "frxDBSet.hpp"
#include "frxExportXLS.hpp"
#include "pFIBDataSet.hpp"
#include "Placemnt.hpp"
#include <Buttons.hpp>
#include <DB.hpp>
#include <ExtCtrls.hpp>
#include "SmrtPanel.h"
#include "ToolEdit.hpp"
#include <Mask.hpp>
#include "RzButton.hpp"
#include "RzPrgres.hpp"
#include "CGAUGES.h"
//---------------------------------------------------------------------------
class TExpensesListOnDateForm : public TForm
{
__published:	// IDE-managed Components
        TFormStorage *FormStorage;
        TPanel *Panel2;
        TBitBtn *Re;
        TpFIBDataSet *DS;
        TPanel *Panel1;
        TLabel *Label1;
        TDateEdit *Date1Edit;
        TLabel *Label2;
        TLabel *Label3;
        TEdit *Edit1;
        TEdit *Edit2;
        TLabel *Label5;
        TEdit *Edit4;
        TLabel *Label6;
        TEdit *Edit5;
        TLabel *Label7;
        TEdit *Edit6;
        TLabel *Label8;
        TLabel *Label9;
        TEdit *Edit7;
        TRzBitBtn *RzBitBtn1;
        TEdit *Edit3;
        TCGauge *Indicator;
        TLabel *Label4;
        TEdit *Edit8;
        TLabel *Label10;
        TEdit *Edit9;
        TLabel *Label11;
        TEdit *Edit10;
        TLabel *Label12;
        TEdit *Edit11;
        TEdit *Edit12;
        TLabel *Label13;
        void __fastcall FormDestroy(TObject *Sender);
        void __fastcall FormShow(TObject *Sender);
        void __fastcall ReClick(TObject *Sender);
        void __fastcall Date1EditChange(TObject *Sender);
        void __fastcall RzBitBtn1Click(TObject *Sender);
private:	// User declarations
  AnsiString workDir;
  AnsiString sd_g;
  TStringList *sdID;
public:		// User declarations
  __fastcall TExpensesListOnDateForm(TComponent* Owner);
  void __fastcall RashetF130(TDate date);
  double ost1,ost2,val1,val2,val4,val5,val6,val7,val8,val9,val10,val11,val12,val13,val14,val15,val16,val17,val18,val19,val20,val21,val22,val23,val24,val3,ost3,ost4,ost5,ost6,ost7,ost8,val25,val26,val27,val28,val29,val30,val31,val32,val33,ost9,val34,val35,val36,val37,ost10,val38,val39,val40,ost11,val41,val42,val43;
  TDate date,datemin;
};
//---------------------------------------------------------------------------
//extern PACKAGE TExpensesListOnAutoForm *ExpensesListOnAutoForm;
//---------------------------------------------------------------------------
#endif
