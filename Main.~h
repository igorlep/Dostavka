//---------------------------------------------------------------------------

#ifndef MainH
#define MainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <Menus.hpp>
#include "JvComponent.hpp"
#include "JvExControls.hpp"
#include "JvNavigationPane.hpp"
#include "Placemnt.hpp"
#include <Buttons.hpp>
#include <ExtCtrls.hpp>
#include "DBGridEh.hpp"
#include <Grids.hpp>
#include "FIBDataSet.hpp"
#include "pFIBDataSet.hpp"
#include <DB.hpp>
#include "FIBDatabase.hpp"
#include "pFIBDatabase.hpp"
#include "UniversalReferenceBook.h"
#include "frxClass.hpp"
#include "frxDBSet.hpp"
#include "frxExportXLS.hpp"
#include "JvXPBar.hpp"
#include "JvXPCore.hpp"
#include <ActnList.hpp>
#include "RzTabs.hpp"
#include "FIBQuery.hpp"
#include "pFIBQuery.hpp"
#include "pFIBStoredProc.hpp"
#include "JvImageList.hpp"
#include <ImgList.hpp>
//---------------------------------------------------------------------------
class TMainForm : public TForm
{
__published:	// IDE-managed Components
        TStatusBar *MainStatusBar;
        TMainMenu *MainMenu1;
        TMenuItem *N1;
        TMenuItem *N2;
        TMenuItem *N3;
        TMenuItem *N4;
        TMenuItem *N6;
        TMenuItem *N7;
        TMenuItem *N8;
        TMenuItem *N9;
        TMenuItem *N12;
        TJvNavPanelHeader *MainHeader;
        TPanel *ButtonsPanel;
        TSpeedButton *PeriodButton;
        TFormStorage *FormStorage;
        TSpeedButton *SelectButton;
        TSpeedButton *UnSelectButton;
        TDataSource *workSource;
        TpFIBDataSet *workDS;
        TPopupMenu *workGridPM;
        TMenuItem *addItem;
        TMenuItem *editItem;
        TMenuItem *delItem;
        TMenuItem *N18;
        TMenuItem *N19;
        TMenuItem *N20;
        TMenuItem *N21;
        TfrxDBDataset *frxDBDataset;
        TfrxXLSExport *frxXLSExport;
        TpFIBDataSet *repDS;
        TfrxDBDataset *frxDBDataset1;
        TpFIBDataSet *repDS1;
        TTimer *STimer;
        TEdit *SEdit;
        TSpeedButton *FSButton;
        TSpeedButton *BSButton;
        TLabel *SLabel;
        TpFIBDataSet *S_DS;
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
        TfrxReport *frxReport;
        TSpeedButton *reloadButton;
        TSpeedButton *AddButton;
        TSpeedButton *EditButton;
        TSpeedButton *DeleteButton;
        TMenuItem *N5;
        TPanel *Panel2;
        TpFIBDataSet *workDS1;
        TDataSource *workSource1;
        TMenuItem *N15;
        TMenuItem *N16;
        TMenuItem *N10;
        TpFIBDataSet *workDS2;
        TDataSource *DS2;
        TMenuItem *N11;
        TMenuItem *N13;
        TMenuItem *N14;
        TComboBox *autoNumberEdit;
        TLabel *Label1;
        TpFIBDataSet *workDS3;
        TDataSource *DS3;
        TDataSource *DS4;
        TpFIBDataSet *workDS4;
        TMenuItem *N17;
        TMenuItem *N22;
        TSpeedButton *increaseButton;
        TSpeedButton *reduceButton;
        TSpeedButton *ImportButton;
        TMenuItem *impItem;
        TpFIBQuery *RQ_INS;
        TpFIBTransaction *RT_INS;
        TpFIBDatabase *INS_DB;
        TpFIBDataSet *usersINS;
        TRzPageControl *PC;
        TRzTabSheet *TabSheet1;
        TSplitter *Splitter1;
        TJvXPBar *selectSDBar;
        TPanel *Panel7;
        TPanel *Panel4;
        TSplitter *Splitter3;
        TDBGridEh *workGrid;
        TJvNavPanelHeader *JvNavPanelHeader1;
        TPanel *Panel5;
        TSplitter *Splitter4;
        TDBGridEh *workGrid4;
        TJvNavPanelHeader *JvNavPanelHeader2;
        TPanel *Panel6;
        TDBGridEh *workGrid5;
        TJvNavPanelHeader *JvNavPanelHeader3;
        TRzTabSheet *TabSheet2;
        TPanel *Panel3;
        TSplitter *Splitter2;
        TJvXPBar *selectSDBar1;
        TDBGridEh *workGrid1;
        TRzTabSheet *TabSheet3;
        TPanel *Panel1;
        TDBGridEh *workGrid2;
        TComboBox *autoNumberEdit1;
        TMenuItem *N23;
        TMenuItem *N24;
        TSpeedButton *ScanButton;
        void __fastcall N3Click(TObject *Sender);
        void __fastcall FormDestroy(TObject *Sender);
        void __fastcall PeriodButtonClick(TObject *Sender);
        void __fastcall FormShow(TObject *Sender);
        void __fastcall workGridKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall N2Click(TObject *Sender);
        void __fastcall N6Click(TObject *Sender);
        void __fastcall N18Click(TObject *Sender);
        void __fastcall addItemClick(TObject *Sender);
        void __fastcall editItemClick(TObject *Sender);
        void __fastcall delItemClick(TObject *Sender);
        void __fastcall N8Click(TObject *Sender);
        void __fastcall N20Click(TObject *Sender);
        void __fastcall N21Click(TObject *Sender);
        void __fastcall workGridSortMarkingChanged(TObject *Sender);
        void __fastcall SelectButtonClick(TObject *Sender);
        void __fastcall UnSelectButtonClick(TObject *Sender);
        void __fastcall workGridKeyPress(TObject *Sender, char &Key);
        void __fastcall SEditKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall SEditChange(TObject *Sender);
        void __fastcall STimerTimer(TObject *Sender);
        void __fastcall FSButtonClick(TObject *Sender);
        void __fastcall BSButtonClick(TObject *Sender);
        void __fastcall S_DSAfterClose(TDataSet *DataSet);
        void __fastcall S_DSAfterOpen(TDataSet *DataSet);
        void __fastcall N25Click(TObject *Sender);
        void __fastcall action0Execute(TObject *Sender);
        void __fastcall action1Execute(TObject *Sender);
        void __fastcall action2Execute(TObject *Sender);
        void __fastcall action3Execute(TObject *Sender);
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
        void __fastcall workGridPMPopup(TObject *Sender);
        void __fastcall reloadButtonClick(TObject *Sender);
        void __fastcall selectSDBarItems17Click(TObject *Sender);
        void __fastcall selectSDBarItems18Click(TObject *Sender);
        void __fastcall selectSDBarItems19Click(TObject *Sender);
        void __fastcall selectSDBarItems20Click(TObject *Sender);
        void __fastcall selectSDBarItems21Click(TObject *Sender);
        void __fastcall selectSDBarItems22Click(TObject *Sender);
        void __fastcall selectSDBarItems23Click(TObject *Sender);
        void __fastcall selectSDBarItems24Click(TObject *Sender);
        void __fastcall selectSDBarItems25Click(TObject *Sender);
        void __fastcall selectSDBarItems26Click(TObject *Sender);
        void __fastcall selectSDBarItems27Click(TObject *Sender);
        void __fastcall selectSDBarItems28Click(TObject *Sender);
        void __fastcall selectSDBarItems29Click(TObject *Sender);
        void __fastcall selectSDBarItems30Click(TObject *Sender);
        void __fastcall selectSDBarItems31Click(TObject *Sender);
        void __fastcall selectSDBarItems32Click(TObject *Sender);
        void __fastcall selectSDBarItems33Click(TObject *Sender);
        void __fastcall selectSDBarItems34Click(TObject *Sender);
        void __fastcall selectSDBarItems35Click(TObject *Sender);
        void __fastcall selectSDBarItems36Click(TObject *Sender);
        void __fastcall selectSDBarItems37Click(TObject *Sender);
        void __fastcall selectSDBarItems38Click(TObject *Sender);
        void __fastcall selectSDBarItems39Click(TObject *Sender);
        void __fastcall selectSDBarItems40Click(TObject *Sender);
        void __fastcall selectSDBarItems41Click(TObject *Sender);
        void __fastcall selectSDBarItems42Click(TObject *Sender);
        void __fastcall selectSDBarItems43Click(TObject *Sender);
        void __fastcall selectSDBarItems44Click(TObject *Sender);
        void __fastcall selectSDBarItems45Click(TObject *Sender);
        void __fastcall selectSDBarItems46Click(TObject *Sender);
        void __fastcall selectSDBarItems47Click(TObject *Sender);
        void __fastcall selectSDBarItems48Click(TObject *Sender);
        void __fastcall selectSDBarItems49Click(TObject *Sender);
        void __fastcall selectSDBarItems50Click(TObject *Sender);
        void __fastcall selectSDBarItemClick(TObject *Sender,
          TJvXPBarItem *Item);
        void __fastcall selectSDBarClick(TObject *Sender);
        void __fastcall AddButtonClick(TObject *Sender);
        void __fastcall EditButtonClick(TObject *Sender);
        void __fastcall DeleteButtonClick(TObject *Sender);
        void __fastcall N5Click(TObject *Sender);
        void __fastcall PCClick(TObject *Sender);
        void __fastcall N9Click(TObject *Sender);
        void __fastcall N12Click(TObject *Sender);
        void __fastcall N15Click(TObject *Sender);
        void __fastcall N16Click(TObject *Sender);
        void __fastcall workGridDblClick(TObject *Sender);
        void __fastcall CheckBox1Click(TObject *Sender);
        void __fastcall N10Click(TObject *Sender);
        void __fastcall workGrid2DblClick(TObject *Sender);
        void __fastcall workGrid1DblClick(TObject *Sender);
        void __fastcall workGrid1SortMarkingChanged(TObject *Sender);
        void __fastcall workGrid2SortMarkingChanged(TObject *Sender);
        void __fastcall workGridDrawColumnCell(TObject *Sender,
          const TRect &Rect, int DataCol, TColumnEh *Column,
          TGridDrawState State);
        void __fastcall workGrid1DrawColumnCell(TObject *Sender,
          const TRect &Rect, int DataCol, TColumnEh *Column,
          TGridDrawState State);
        void __fastcall workGrid2DrawColumnCell(TObject *Sender,
          const TRect &Rect, int DataCol, TColumnEh *Column,
          TGridDrawState State);
        void __fastcall workGridCellClick(TColumnEh *Column);
        void __fastcall workGrid1CellClick(TColumnEh *Column);
        void __fastcall workGrid2CellClick(TColumnEh *Column);
        void __fastcall N13Click(TObject *Sender);
        void __fastcall N14Click(TObject *Sender);
        void __fastcall T(TObject *Sender);
        void __fastcall workGrid4CellClick(TColumnEh *Column);
        void __fastcall workGrid4DblClick(TObject *Sender);
        void __fastcall workGrid4DrawColumnCell(TObject *Sender,
          const TRect &Rect, int DataCol, TColumnEh *Column,
          TGridDrawState State);
        void __fastcall workGrid4KeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall workGrid4KeyPress(TObject *Sender, char &Key);
        void __fastcall workGrid4SortMarkingChanged(TObject *Sender);
        void __fastcall DBGridEh5CellClick(TColumnEh *Column);
        void __fastcall workGrid5DrawColumnCell(TObject *Sender,
          const TRect &Rect, int DataCol, TColumnEh *Column,
          TGridDrawState State);
        void __fastcall workGrid5SortMarkingChanged(TObject *Sender);
        void __fastcall N17Click(TObject *Sender);
        void __fastcall N22Click(TObject *Sender);
        void __fastcall workGrid5CellClick(TColumnEh *Column);
        void __fastcall increaseButtonClick(TObject *Sender);
        void __fastcall reduceButtonClick(TObject *Sender);
        void __fastcall impItemClick(TObject *Sender);
        void __fastcall ImportButtonClick(TObject *Sender);
        void __fastcall autoNumberEdit1Change(TObject *Sender);
        void __fastcall autoNumberEditChange(TObject *Sender);
        void __fastcall N23Click(TObject *Sender);
        void __fastcall N24Click(TObject *Sender);
        void __fastcall ScanButtonClick(TObject *Sender);
private:	// User declarations
  TDateTime Date1, Date2;
  TStringList *autoID;
  TStringList *autoID1;
//  TURB *SD_RB,*GSM_CR_RB, *ElectronicCards_RB, *Auto_RB, *Drivers_RB, *GSM_RB;
//  TURB *Distinations_RB;
  bool __fastcall rbRemoveableCheck(AnsiString tn, AnsiString id);
  AnsiString sortString,sortString1,sortString2;
  AnsiString selectString;
  AnsiString selectString1;
  AnsiString servername,dbPath,uname,pass;
  TDateTime EDate;
  AnsiString autoNum;
  int OD_ID; //ссылка на запись "ќсновна€ де€тельность" в таблице DISTINATIONS_TABLE
  int WR_ID; //ссылка на запись "¬нутренние работы" в таблице DISTINATIONS_TABLE
public:		// User declarations
  AnsiString workDir;
  AnsiString odpp,fio,tel,email;
  AnsiString iniFileName;
  AnsiString IndexOps;
  AnsiString IndexOdpp;
  AnsiString ListOfKassa;
  AnsiString Massiv[20];
  AnsiString OPS1;
  int index;
  int KolOps;
  int selectedSD;
  int selectedSD1;
  int selectedMenu;
  int ActivTable;
  AnsiString selectedOPS;
  __fastcall TMainForm(TComponent* Owner);
  void __fastcall initMainForm(void);
  void __fastcall setMainHeader(void);
  AnsiString __fastcall getSD_ID(void);
  AnsiString __fastcall getID(void);
  int __fastcall getSetectidSD(void){ return selectedSD; }
  void __fastcall LoadWorkDS(AnsiString sdID,AnsiString ID);
  void __fastcall RashetWorkDS(void);
  void __fastcall f(int idrec, AnsiString toper,TDateTime Dater,int sd_id,int id_ops);
  AnsiString __fastcall getWorkDir(void);
  TURB * __fastcall getGSM_RB(int flag);
  TURB * __fastcall getDistinations_RB(void);
  TURB * __fastcall getDrivers_RB(AnsiString sdName);
  TDateTime __fastcall getDate1(void){ return Date1; }
  TDateTime __fastcall getDate2(void){ return Date2; }
};
//---------------------------------------------------------------------------
extern PACKAGE TMainForm *MainForm;
//---------------------------------------------------------------------------
#endif
