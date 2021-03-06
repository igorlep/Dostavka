//---------------------------------------------------------------------------

#ifndef FormScanH
#define FormScanH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "DBGridEh.hpp"
#include "JvComponent.hpp"
#include "JvExControls.hpp"
#include "JvNavigationPane.hpp"
#include "JvXPBar.hpp"
#include "JvXPCore.hpp"
#include "RzTabs.hpp"
#include <ExtCtrls.hpp>
#include <Grids.hpp>
#include "Placemnt.hpp"
#include <ActnList.hpp>
#include <Buttons.hpp>
#include <Menus.hpp>
#include <DBCtrls.hpp>
#include "FIBDataSet.hpp"
#include "pFIBDataSet.hpp"
#include <DB.hpp>
#include "FIBDatabase.hpp"
#include "pFIBDatabase.hpp"
#include "JvCalendar.hpp"
#include "CCALENDR.h"
#include "FIBQuery.hpp"
#include "pFIBQuery.hpp"
//---------------------------------------------------------------------------
class TScanerForm : public TForm
{
__published:	// IDE-managed Components
        TPanel *Panel2;
        TRzPageControl *PC;
        TRzTabSheet *TabSheet1;
        TJvXPBar *selectSDBar;
        TPanel *Panel4;
        TJvNavPanelHeader *JvNavPanelHeader1;
        TPanel *Panel5;
        TDBGridEh *AccountsGrid;
        TJvNavPanelHeader *JvNavPanelHeader2;
        TRzTabSheet *TabSheet2;
        TDBGridEh *VostrGrid;
        TJvNavPanelHeader *MainHeader;
        TPanel *ButtonsPanel;
        TSpeedButton *PeriodButton;
        TSpeedButton *FSButton;
        TSpeedButton *BSButton;
        TLabel *SLabel;
        TSpeedButton *DeleteButton;
        TSpeedButton *increaseButton;
        TSpeedButton *reduceButton;
        TEdit *SEdit;
        TActionList *actionList;
        TAction *action0;
        TAction *action1;
        TAction *action2;
        TAction *action3;
        TAction *action4;
        TAction *action5;
        TAction *action6;
        TAction *action7;
        TAction *action8;
        TAction *action9;
        TAction *action10;
        TAction *action11;
        TAction *action12;
        TAction *action13;
        TAction *action14;
        TAction *action15;
        TAction *action16;
        TFormStorage *FormStorage;
        TMainMenu *MainMenu1;
        TMenuItem *N4;
        TMenuItem *N9;
        TMenuItem *N16;
        TJvXPBar *OpsBar;
        TPanel *Panel3;
        TPanel *Panel6;
        TPanel *Panel8;
        TPanel *Panel10;
        TPanel *Panel7;
        TPanel *Panel9;
        TDBNavigator *DBNavigator1;
        TRzTabSheet *TabSheet3;
        TPanel *Panel11;
        TDBGridEh *BazaGrid;
        TPanel *Panel12;
        TDBNavigator *DBNavigator2;
        TCCalendar *Calendar;
        TAction *Action17;
        TAction *Action18;
        TAction *Action19;
        TAction *Action20;
        TAction *Action21;
        TAction *Action22;
        TAction *Action23;
        TAction *Action24;
        TAction *Action25;
        TAction *Action26;
        TAction *Action27;
        TAction *Action28;
        TAction *Action29;
        TAction *Action30;
        TAction *Action31;
        TAction *Action32;
        TAction *Action33;
        TAction *Action34;
        TAction *Action35;
        TAction *Action36;
        TAction *Action37;
        TAction *Action38;
        TAction *Action39;
        TAction *Action40;
        TDBGridEh *SoldGoodsGrid;
        TpFIBQuery *TempQ;
        TpFIBQuery *TQ;
        TpFIBQuery *WQ;
        TpFIBTransaction *WriteTransaction;
        TpFIBDataSet *DB1;
        TpFIBTransaction *QT;
        TpFIBTransaction *SGTransaction;
        TpFIBDataSet *SG_DS;
        TpFIBTransaction *ReadTransaction;
        TpFIBTransaction *ATransaction;
        TpFIBDataSet *A_DS;
        TDataSource *GoodsSource;
        TDataSource *AccountsS;
        TFIBSmallIntField *A_DSORG_ID;
        TFIBDateField *A_DSCOUNT_DATE;
        TFIBSmallIntField *A_DSCOUNT_NUMBER;
        TFIBIntegerField *A_DSCUSTOMER_ID;
        TFIBStringField *A_DSCUSTOMER_NAME;
        TFIBSmallIntField *A_DSUSER_ID;
        TFIBSmallIntField *A_DSOPS_ID;
        TFIBStringField *A_DSOPS_NAME;
        TFIBIntegerField *A_DSCOUNT_TOTALI;
        TFIBFloatField *A_DSCOUNT_TOTAL;
        TFIBIntegerField *A_DSCOUNT_OPL_PI;
        TFIBFloatField *A_DSCOUNT_OPL_P;
        TFIBIntegerField *A_DSCOUNT_NEOPL_PI;
        TFIBFloatField *A_DSCOUNT_NEOPL_P;
        TFIBIntegerField *A_DSCOUNT_OPL_EI;
        TFIBFloatField *A_DSCOUNT_OPL_E;
        TFIBIntegerField *A_DSCOUNT_NEOPLE_I;
        TFIBFloatField *A_DSCOUNT_NEOPL_E;
        TFIBIntegerField *A_DSM;
        TFIBIntegerField *A_DSY;
        TFIBBooleanField *A_DSEDIT_KEY;
        TFIBStringField *A_DSAVTOR;
        TFIBSmallIntField *SG_DSORG_ID;
        TFIBDateField *SG_DSCOUNT_DATE;
        TFIBSmallIntField *SG_DSCOUNT_NUMBER;
        TFIBStringField *SG_DSORDER_NUM;
        TFIBStringField *SG_DSSYS_NUM;
        TFIBFloatField *SG_DSSUMMA;
        TFIBIntegerField *SG_DSM;
        TFIBIntegerField *SG_DSY;
        TpFIBDataSet *VOSTR;
        TFIBStringField *VOSTRORDER_NUM;
        TDataSource *VostrS;
        TpFIBDataSet *BAZA;
        TDataSource *BazaS;
        TFIBIntegerField *BAZACOD;
        TFIBStringField *BAZATYPEZ;
        TFIBStringField *BAZAORDER_NUM;
        TFIBStringField *BAZASYS_NUM;
        TFIBFloatField *BAZASUMMA;
        TFIBIntegerField *BAZAM;
        TFIBIntegerField *BAZAY;
        TSpeedButton *AddButton;
        TSpeedButton *EditButton;
        TPopupMenu *workGridPM;
        TMenuItem *addItem;
        TMenuItem *editItem;
        TMenuItem *delItem;
        TTimer *STimer;
        TFIBStringField *SG_DSTYPEZ;
        TFIBStringField *SG_DSPRICH;
        void __fastcall FormShow(TObject *Sender);
        void __fastcall PCClick(TObject *Sender);
        void __fastcall action0Execute(TObject *Sender);
        void __fastcall action1Execute(TObject *Sender);
        void __fastcall Action21Execute(TObject *Sender);
        void __fastcall Action22Execute(TObject *Sender);
        void __fastcall CalendarChange(TObject *Sender);
        void __fastcall AddButtonClick(TObject *Sender);
        void __fastcall EditButtonClick(TObject *Sender);
        void __fastcall DeleteButtonClick(TObject *Sender);
        void __fastcall addItemClick(TObject *Sender);
        void __fastcall editItemClick(TObject *Sender);
        void __fastcall delItemClick(TObject *Sender);
        void __fastcall AccountsGridCellClick(TColumnEh *Column);
        void __fastcall action3Execute(TObject *Sender);
        void __fastcall action2Execute(TObject *Sender);
        void __fastcall action4Execute(TObject *Sender);
        void __fastcall action5Execute(TObject *Sender);
        void __fastcall action6Execute(TObject *Sender);
        void __fastcall action7Execute(TObject *Sender);
        void __fastcall action8Execute(TObject *Sender);
        void __fastcall action9Execute(TObject *Sender);
        void __fastcall action10Execute(TObject *Sender);
        void __fastcall action11Execute(TObject *Sender);
        void __fastcall action12Execute(TObject *Sender);
        void __fastcall action13Execute(TObject *Sender);
        void __fastcall action14Execute(TObject *Sender);
        void __fastcall action15Execute(TObject *Sender);
        void __fastcall action16Execute(TObject *Sender);
        void __fastcall Action17Execute(TObject *Sender);
        void __fastcall Action18Execute(TObject *Sender);
        void __fastcall Action19Execute(TObject *Sender);
        void __fastcall Action20Execute(TObject *Sender);
        void __fastcall Action23Execute(TObject *Sender);
        void __fastcall Action24Execute(TObject *Sender);
        void __fastcall Action25Execute(TObject *Sender);
        void __fastcall Action26Execute(TObject *Sender);
        void __fastcall Action27Execute(TObject *Sender);
        void __fastcall Action28Execute(TObject *Sender);
        void __fastcall Action29Execute(TObject *Sender);
        void __fastcall Action30Execute(TObject *Sender);
        void __fastcall Action31Execute(TObject *Sender);
        void __fastcall Action32Execute(TObject *Sender);
        void __fastcall Action33Execute(TObject *Sender);
        void __fastcall Action34Execute(TObject *Sender);
        void __fastcall Action35Execute(TObject *Sender);
        void __fastcall Action36Execute(TObject *Sender);
        void __fastcall Action37Execute(TObject *Sender);
        void __fastcall Action38Execute(TObject *Sender);
        void __fastcall Action39Execute(TObject *Sender);
        void __fastcall Action40Execute(TObject *Sender);
        void __fastcall FormDestroy(TObject *Sender);
        void __fastcall increaseButtonClick(TObject *Sender);
        void __fastcall reduceButtonClick(TObject *Sender);
        void __fastcall SoldGoodsGridCellClick(TColumnEh *Column);
        void __fastcall VostrGridCellClick(TColumnEh *Column);
        void __fastcall BazaGridCellClick(TColumnEh *Column);
        void __fastcall SoldGoodsGridKeyPress(TObject *Sender, char &Key);
        void __fastcall SEditKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall SEditChange(TObject *Sender);
        void __fastcall STimerTimer(TObject *Sender);
        void __fastcall VostrGridKeyPress(TObject *Sender, char &Key);
        void __fastcall BazaGridKeyPress(TObject *Sender, char &Key);
private:	// User declarations
public:		// User declarations
        __fastcall TScanerForm(TComponent* Owner);
        void __fastcall initMainForm(void);
        void __fastcall setMainHeader(void);
        void __fastcall selectSDBarClick(TObject *Sender);
        AnsiString __fastcall getSD_IDPost(void);
        AnsiString __fastcall getSD_IDOps(void);
        void __fastcall LoadWorkDS(TDateTime d,AnsiString sdID,AnsiString ID);
        AnsiString Massiv[20];
        AnsiString IndexOps;
        AnsiString workDir;
        AnsiString iniFileName;
        TDateTime Date1;
        int selectedSD;
        int selectedSD1;
        int KolOps;
        AnsiString IndexOdpp;
        AnsiString ListOfKassa;
};
//---------------------------------------------------------------------------
extern PACKAGE TScanerForm *ScanerForm;
//---------------------------------------------------------------------------
#endif
