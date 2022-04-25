//---------------------------------------------------------------------------

#ifndef RBConfigurationH
#define RBConfigurationH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "Placemnt.hpp"
#include "DBGridEh.hpp"
#include <ExtCtrls.hpp>
#include <Grids.hpp>
#include "FIBDataSet.hpp"
#include "pFIBDataSet.hpp"
#include <DB.hpp>
#include "JvComponent.hpp"
#include "JvExControls.hpp"
#include "JvNavigationPane.hpp"
#include <Buttons.hpp>
//---------------------------------------------------------------------------
class TRBConfigurationForm : public TForm
{
__published:	// IDE-managed Components
        TFormStorage *FormStorage;
        TSplitter *RBSplitter;
        TpFIBDataSet *RBDS;
        TpFIBDataSet *FieldsDS;
        TDataSource *RBS;
        TDataSource *FieldsS;
        TPanel *RBPanel;
        TDBGridEh *RBGrid;
        TJvNavPanelHeader *RBHeader;
        TPanel *FieldsPanel;
        TDBGridEh *FieldsGrid;
        TJvNavPanelHeader *FieldsHeader;
        TPanel *RBButtonsPanel;
        TSpeedButton *RBPostButton;
        TSpeedButton *RBCancelButton;
        TPanel *FIButtonsPanel;
        TSpeedButton *FIPostButton;
        TSpeedButton *FICancelButton;
        void __fastcall FormDestroy(TObject *Sender);
//        void __fastcall RebootButtonClick(TObject *Sender);
//        void __fastcall RBDSAfterPost(TDataSet *DataSet);
//        void __fastcall FieldsDSAfterPost(TDataSet *DataSet);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall RBPostButtonClick(TObject *Sender);
        void __fastcall RBCancelButtonClick(TObject *Sender);
        void __fastcall RBSStateChange(TObject *Sender);
        void __fastcall FIPostButtonClick(TObject *Sender);
        void __fastcall FICancelButtonClick(TObject *Sender);
        void __fastcall FieldsSStateChange(TObject *Sender);
        void __fastcall RBSDataChange(TObject *Sender, TField *Field);
        void __fastcall FormShow(TObject *Sender);
        void __fastcall FieldsDSBeforePost(TDataSet *DataSet);
private:	// User declarations
        AnsiString workDir;
//        bool *rebootFLG;
public:		// User declarations
        __fastcall TRBConfigurationForm(TComponent* Owner);
        void __fastcall saveProperties(void);
        void __fastcall loadProperties(void);
};
//---------------------------------------------------------------------------
extern PACKAGE TRBConfigurationForm *RBConfigurationForm;
//---------------------------------------------------------------------------
#endif
