//---------------------------------------------------------------------------

#ifndef UniversalReferenceBookH
#define UniversalReferenceBookH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include "DBGridEh.hpp"
#include <ComCtrls.hpp>
#include <Grids.hpp>
#include "Placemnt.hpp"
#include "FIBDataSet.hpp"
#include "pFIBDataSet.hpp"
#include <DB.hpp>
#include <ImgList.hpp>
#include <Buttons.hpp>
#include "FIBDatabase.hpp"
#include "pFIBDatabase.hpp"
#include "FIBQuery.hpp"
#include "pFIBQuery.hpp"
#include <Menus.hpp>
//---------------------------------------------------------------------------
// ласс - »нформаци€ о поле таблицы справочника
class MFieldInfo
{
private:
  AnsiString fName;             //наименование пол€
  AnsiString fTitle;            //заголовок пол€
  short fType;                  //тип пол€
  short fLength;                //длина
  bool accessable;              //доступ к пол€ дл€ просмотра и редактировани€
  bool editable;                //возможность редактировани€ пол€
  bool gridViewable;            //отображать в Grid
  AnsiString gridAlign;         //положение в колонке Grid
  AnsiString fData;             //данные
  //если тип пол€ - ссылка (fData содержит ссылку на поле этой или другой таблицы)
  AnsiString refTableName;      //им€ таблицы, на которую сылаетс€ поле
  AnsiString refFieldName;      //наименование пол€-ссылки
  AnsiString retFieldName;      //наименование пол€, значение которого возвращаетс€ по ссылке
  AnsiString retData;           //значение пол€-ссылки
public:
  __fastcall MFieldInfo(void);
  __fastcall MFieldInfo(AnsiString fN, AnsiString fTi, short fTy, short fL, bool ea, bool va, bool gva, AnsiString gp, AnsiString fD, AnsiString rTN, AnsiString rFN, AnsiString retFN, AnsiString rD);
  AnsiString __fastcall getFieldName(void){ return fName; }
  AnsiString __fastcall getFieldTitle(void){ return fTitle; }
  int __fastcall getFieldType(void){ return fType; }
  int __fastcall getFieldLength(void){ return fLength; }
  bool __fastcall isAccessable(void){ return accessable; }
  bool __fastcall isEditable(void){ return editable; }
  bool __fastcall isGridViewable(void){ return gridViewable; }
  AnsiString __fastcall getGridAlign(void){ return gridAlign; }
  AnsiString __fastcall getFieldData(void){ return fData; }
  void __fastcall setFieldData(AnsiString fd){ fData=fd; }
  AnsiString __fastcall getRefTableName(void){ return refTableName; }
  AnsiString __fastcall getRefFieldName(void){ return refFieldName; }
  AnsiString __fastcall getRetFieldName(void){ return retFieldName; }
  AnsiString __fastcall getRetFieldData(void){ return retData; }
  void __fastcall setRetFieldData(AnsiString rfd){ retData=rfd; }
};

// ласс - »нформаци€ о пол€х таблицы справочника
class MFieldsInformation
{
private:
  TComponent* Owner;
  TpFIBDatabase *db;
  TpFIBQuery *Q, *WQ;
  TpFIBDataSet *DS;
  TpFIBTransaction *RTransaction, *WTransaction;
  
  unsigned short fieldsCount;   //количество полей в таблице
  AnsiString tableName;
  AnsiString keyField;
  MFieldInfo **FieldsInfo;     //
  void __fastcall prepareFI_Table();
  void __fastcall PutInFITableOrder(void);
public:
  __fastcall MFieldsInformation(TComponent* Owner, AnsiString tableName, AnsiString keyField);
  __fastcall ~MFieldsInformation(void);
  int __fastcall getFieldsCount(void){ return fieldsCount; }
  MFieldInfo * __fastcall getFieldInfo(int i) { return FieldsInfo[i]; }
  int __fastcall getPisitionField(AnsiString fieldName);
  void __fastcall setFIData(TpFIBDataSet *DS);
  int __fastcall getAccessableFildsCount(void);
  int __fastcall getEditableFildsCount(void);
};

//Ёлемент данных дерева справочника
class RBTreeData
{
public:
  AnsiString data;
};

// ласс - ”ниверсальный справочник
class TURB : public TForm
{
__published:	// IDE-managed Components
        TPanel *LeftPanel;
        TSplitter *VSplitter;
        TPanel *RightPanel;
        TPanel *TreePanel;
        TTreeView *TreeView;
        TDBGridEh *Grid;
        TFormStorage *FormStorage;
        TPanel *LButtonsPanel;
        TPanel *RButtonsPanel;
        TpFIBDataSet *DS;
        TSplitter *HSplitter;
        TRichEdit *ContentMemo;
        TDataSource *S;
        TImageList *ImageList;
        TPanel *SPanel;
        TEdit *SEdit;
        TSpeedButton *FSButton;
        TSpeedButton *BSButton;
        TTimer *STimer;
        TpFIBTransaction *ReadTransaction;
        TpFIBTransaction *WriteTransaction;
        TpFIBDataSet *S_DS;
        TpFIBQuery *Q;
        TSpeedButton *AddSectionButton;
        TSpeedButton *DelSectionButton;
        TPopupMenu *GridMenu;
        TMenuItem *N1;
        TMenuItem *N2;
        TMenuItem *N3;
        TMenuItem *N4;
        TCheckBox *OnFoldersCheckBox;
        TMenuItem *N5;
        TMenuItem *N6;
        TPanel *GridButtonsPanel;
        TSpeedButton *PostButton;
        TSpeedButton *CancelButton;
        TMenuItem *N7;
        TMenuItem *N8;
        TSpeedButton *AddButton;
        TSpeedButton *EditButton;
        TSpeedButton *DeleteButton;
        TSpeedButton *MoveButton;
        TSpeedButton *RestoreButton;
        TSpeedButton *SaveButton;
        TSpeedButton *UndoButton;
        TSpeedButton *SelectButton;
        TPopupMenu *TreeMenu;
        TMenuItem *N9;
        TSpeedButton *reloadButton;
        TpFIBDataSet *usersINS;
        void __fastcall FormShow(TObject *Sender);
        void __fastcall FormDestroy(TObject *Sender);
        void __fastcall TreeViewChange(TObject *Sender, TTreeNode *Node);
        void __fastcall SDataChange(TObject *Sender, TField *Field);
        void __fastcall STimerTimer(TObject *Sender);
        void __fastcall SEditChange(TObject *Sender);
        void __fastcall SEditKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall GridKeyPress(TObject *Sender, char &Key);
        void __fastcall GridKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall TreeViewKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall GridDblClick(TObject *Sender);
        void __fastcall TreeViewDblClick(TObject *Sender);
        void __fastcall TreeViewEdited(TObject *Sender, TTreeNode *Node,
          AnsiString &S);
        void __fastcall FSButtonClick(TObject *Sender);
        void __fastcall BSButtonClick(TObject *Sender);
        void __fastcall AddSectionButtonClick(TObject *Sender);
        void __fastcall DelSectionButtonClick(TObject *Sender);
        void __fastcall GridMenuPopup(TObject *Sender);
        void __fastcall N1Click(TObject *Sender);
        void __fastcall N2Click(TObject *Sender);
        void __fastcall N3Click(TObject *Sender);
        void __fastcall OnFoldersCheckBoxClick(TObject *Sender);
        void __fastcall SStateChange(TObject *Sender);
        void __fastcall N5Click(TObject *Sender);
        void __fastcall N6Click(TObject *Sender);
        void __fastcall PostButtonClick(TObject *Sender);
        void __fastcall CancelButtonClick(TObject *Sender);
        void __fastcall DSAfterInsert(TDataSet *DataSet);
        void __fastcall N7Click(TObject *Sender);
        void __fastcall N8Click(TObject *Sender);
        void __fastcall N4Click(TObject *Sender);
        void __fastcall AddButtonClick(TObject *Sender);
        void __fastcall EditButtonClick(TObject *Sender);
        void __fastcall DeleteButtonClick(TObject *Sender);
        void __fastcall MoveButtonClick(TObject *Sender);
        void __fastcall RestoreButtonClick(TObject *Sender);
        void __fastcall SaveButtonClick(TObject *Sender);
        void __fastcall UndoButtonClick(TObject *Sender);
        void __fastcall SelectButtonClick(TObject *Sender);
        void __fastcall TreeMenuPopup(TObject *Sender);
        void __fastcall reloadButtonClick(TObject *Sender);
private:	// User declarations
        TComponent* Owner;
        AnsiString workDir;
        AnsiString rbTitle;      //Ќаменование справочника
        AnsiString rbTableName;  //»м€ таблицы
        AnsiString keyFieldName; //Ќаименование ключевого поле€
        bool treeViewable;       //‘лаг отображени€ дерева папок
        int  treeLevel;
        bool contentViewable;    //‘лаг отображени€ панели с содержанием записи
        bool searchPanelViewable;//‘лаг отображени€ панели поиска по модели
        bool directGridEdit;     //‘лаг редактировани€ данныз непосредственно в Grid
        bool searchingWithRegister;//‘лаг поиска с учетом регистра
        MFieldsInformation *FI;
        AnsiString orderStr;     //ѕор€док сортировки записей
        AnsiString selectedSectionID;   //»дентификатор активного раздела
        AnsiString parentSectionID;   //»дентификатор активного раздела
        int        selectedLevel;   //¬ыбранный уровень
        bool firstStartFLG;      //‘лаг первого запуска программы
        AnsiString RootSectionID;      // од корневого раздела справочника
        AnsiString DelRecordsSectionID; // од раздела дл€ удаленных записей
        void __fastcall createNode(TTreeNode *node, AnsiString sectionID,int flag);
        void __fastcall ColumnOnClickButton(TObject* Sender,bool &Handled);
        bool __fastcall removeableCheck(AnsiString tableName, AnsiString ID);
public:		// User declarations
        __fastcall TURB(TComponent* Owner, AnsiString tableName,int flag);
        void __fastcall getProperties(void);
        void __fastcall setProperties(void);
        AnsiString __fastcall getRBTitle(void) { return rbTitle; }
        AnsiString __fastcall getTableName(void) { return rbTableName; }
        AnsiString __fastcall getKeyFieldName(void) { return keyFieldName; }
        AnsiString __fastcall getRootSectionID(void) { return RootSectionID; }
        AnsiString __fastcall getDelRecordsSectionID(void) { return DelRecordsSectionID; }
        AnsiString __fastcall getFolderIDByName(AnsiString folderName);
        AnsiString __fastcall createFolderByName(AnsiString parentID,AnsiString folderName);
        void __fastcall loadDS();
        void __fastcall setContentMemo();
        AnsiString __fastcall getNewRB_KeyValue(void);
        void __fastcall createRBTree(int flag);
        void __fastcall deleteRBTree(void);
        MFieldsInformation * __fastcall getFieldInfo(void){ return FI; }
        void __fastcall FindPositionInTreeView(AnsiString id);
        void __fastcall FindPositionInTreeViewForFolderName(AnsiString FolderName);
        typedef bool __fastcall (__closure*pfChk)(AnsiString,AnsiString);
        pfChk raCheck;
        int flagv;
};
//---------------------------------------------------------------------------
//extern PACKAGE TURB *URB;
//---------------------------------------------------------------------------
#endif
