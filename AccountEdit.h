//---------------------------------------------------------------------------

#ifndef AccountEditH
#define AccountEditH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "DBGridEh.hpp"
#include "SmrtPanel.h"
#include <ExtCtrls.hpp>
#include <Grids.hpp>
#include <ADODB.hpp>
#include <DB.hpp>
#include "DBCtrlsEh.hpp"
#include <Mask.hpp>
#include "DBLookupEh.hpp"
#include "ToolEdit.hpp"
#include <Buttons.hpp>
#include "Placemnt.hpp"
#include <DBGrids.hpp>
#include "RxCalc.hpp"
#include "FIBDataSet.hpp"
#include "pFIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBQuery.hpp"
#include "RXDBCtrl.hpp"
#include "FIBDatabase.hpp"
#include "pFIBDatabase.hpp"
#include <DBCtrls.hpp>
//---------------------------------------------------------------------------
class TAccountEditForm : public TForm
{
__published:	// IDE-managed Components
        TSmrtPanel *SmrtPanel1;
        TSmrtPanel *SmrtPanel2;
        TSmrtPanel *SmrtPanel3;
        TSmrtPanel *SmrtPanel4;
        TDataSource *AccountsTempS;
        TDBDateTimeEditEh *DateEdit;
        TDBEditEh *NumberEdit;
        TLabel *Label1;
        TLabel *Label2;
        TLabel *Label3;
        TDataSource *SoldGoodsS;
        TLabel *Label5;
        TFormStorage *FormStorage1;
        TDBGridEh *SoldGoodsGrid;
        TSpeedButton *DelButton;
        TpFIBDataSet *AccountsTempDS;
        TpFIBDataSet *SoldGoodsDS;
        TpFIBQuery *TempQ;
        TSpeedButton *SaveButton;
        TSpeedButton *CancelButton;
        TRxDBComboEdit *CustomerEdit;
        TpFIBQuery *TQ;
        TpFIBTransaction *WT;
        TStaticText *UserName;
        TBitBtn *WriteButton;
        TBitBtn *ExitButton;
        TpFIBTransaction *AccountsT;
        TpFIBTransaction *SouldGoodsT;
        TpFIBTransaction *DT;
        TLabel *Label4;
        TLabel *Label6;
        TLabel *Label7;
        TLabel *Label8;
        TLabel *Label10;
        TLabel *Label11;
        TLabel *Label12;
        TLabel *Label13;
        TLabel *Label14;
        TLabel *Label15;
        TLabel *Label16;
        TLabel *Label17;
        TLabel *Label18;
        TEdit *Edit1;
        TTimer *searchTimer;
        TStaticText *StaticText1;
        TStaticText *StaticText2;
        TStaticText *StaticText3;
        TStaticText *StaticText4;
        TStaticText *StaticText5;
        TStaticText *StaticText7;
        TStaticText *StaticText8;
        TStaticText *StaticText9;
        TStaticText *StaticText10;
        TpFIBDataSet *NDOST;
        TSpeedButton *EditButton;
        TSpeedButton *DelAllButton;
        TpFIBDataSet *DB1;
        TpFIBTransaction *ReadTransaction;
        TFIBSmallIntField *SoldGoodsDSUSER_ID;
        TFIBStringField *SoldGoodsDSORDER_NUM;
        TFIBStringField *SoldGoodsDSSYS_NUM;
        TFIBFloatField *SoldGoodsDSSUMMA;
        TFIBIntegerField *SoldGoodsDSM;
        TFIBIntegerField *SoldGoodsDSY;
        TFIBStringField *SoldGoodsDSPRICH;
        TFIBStringField *SoldGoodsDSTYPEZ2;
        TComboBox *autoNumberEdit;
        TLabel *Label9;
        void __fastcall FormShow(TObject *Sender);
        void __fastcall NumberEditKeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
        void __fastcall DateEditKeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
        void __fastcall DelButtonClick(TObject *Sender);
        void __fastcall SoldGoodsSStateChange(TObject *Sender);
        void __fastcall SaveButtonClick(TObject *Sender);
        void __fastcall CancelButtonClick(TObject *Sender);
        void __fastcall CustomerEditButtonClick(TObject *Sender);
        void __fastcall FormDestroy(TObject *Sender);
        void __fastcall SoldGoodsGridKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall WriteButtonClick(TObject *Sender);
        void __fastcall ExitButtonClick(TObject *Sender);
        void __fastcall DateEditChange(TObject *Sender);
        void __fastcall searchTimerTimer(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall SoldGoodsSDataChange(TObject *Sender,
          TField *Field);
        void __fastcall Edit1KeyPress(TObject *Sender, char &Key);
        void __fastcall Edit1Change(TObject *Sender);
        void __fastcall EditButtonClick(TObject *Sender);
        void __fastcall SoldGoodsGridColumns7UpdateData(TObject *Sender,
          AnsiString &Text, Variant &Value, bool &UseText, bool &Handled);
        void __fastcall SoldGoodsGridGetCellParams(TObject *Sender,
          TColumnEh *Column, TFont *AFont, TColor &Background,
          TGridDrawState State);
        void __fastcall FormActivate(TObject *Sender);
        void __fastcall DelAllButtonClick(TObject *Sender);
        void __fastcall SoldGoodsDSPRICHChange(TField *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TAccountEditForm(TComponent* Owner,TDateTime date, unsigned short number);
        __fastcall TAccountEditForm(TComponent* Owner,TDataSet *DS);
        void __fastcall otbor(int dayv, int kodpost);
        void __fastcall ras(void);
        bool __fastcall prov(void);
        void __fastcall updateset(void);
        unsigned short Number, RS_ID,U_ID;
        TDateTime CountDate;
        bool ErrFLG,NewFLG,PostFLG,LoadFLG;
//        AccountChangeFLG,
        TpFIBDataSet *C_DS, *SG_DST, *SN_DS, *NDOST_DS;
        int ActiveRow;
        double count_total,count_opl,count_neopl,count_tek,count_pr,count_raz,count_neoplp,count_oplp,count_neoplk,count_neoplpk,prh,razdh;
        int count_totali,count_opli,count_neopli,count_neoplik;
};
//---------------------------------------------------------------------------
#endif
