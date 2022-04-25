//---------------------------------------------------------------------------

#ifndef SelectBaseH
#define SelectBaseH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "SmrtPanel.h"
#include <Buttons.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
#include "Placemnt.hpp"
#include "AdjustConnection.h"
#include "FIBDatabase.hpp"
#include "pFIBDatabase.hpp"
#include "JvAnimTitle.hpp"
#include "JvComponent.hpp"
#include "FIBQuery.hpp"
#include "pFIBQuery.hpp"
#include "JvExControls.hpp"
#include "JvXPButtons.hpp"
#include "JvXPCore.hpp"
#include "SmrtPanel.h"
#include <ComCtrls.hpp>
#include <jpeg.hpp>
//---------------------------------------------------------------------------
class TSelectBaseForm : public TForm
{
__published:	// IDE-managed Components
        TPanel *Panel1;
        TPanel *Panel2;
        TPanel *Panel4;
        TSmrtPanel *SmrtPanel1;
        TListBox *DBNamesBox;
        TLabel *Label4;
        TFormStorage *FormStorage;
        TpFIBDatabase *DataBase;
        TJvAnimTitle *JvAnimTitle1;
        TLabel *Label3;
        TpFIBTransaction *T;
        TpFIBQuery *Q;
        TJvXPButton *ConnectButton;
        TJvXPButton *AddButton;
        TJvXPButton *EditButton;
        TJvXPButton *DelButton;
        TRichEdit *RichEdit1;
        TImage *Image2;
        TLabel *Label1;
        void __fastcall CancelButtonClick(TObject *Sender);
        void __fastcall FormShow(TObject *Sender);
        void __fastcall DBNamesBoxClick(TObject *Sender);
        void __fastcall EditButtonClick(TObject *Sender);
        void __fastcall AddButtonClick(TObject *Sender);
        void __fastcall DelButtonClick(TObject *Sender);
        void __fastcall FormDestroy(TObject *Sender);
        void __fastcall ConnectButtonClick(TObject *Sender);
        void __fastcall DBNamesBoxDblClick(TObject *Sender);
private:	// User declarations
        AnsiString WorkDir;
        int DBIndex;
        bool EditFLG;
        const int VER_NUMBER;
        TAdjustConnectionForm *ACF;
public:		// User declarations
        __fastcall TSelectBaseForm(TComponent* Owner);
        void __fastcall LoadDBNamesList(void);
        bool __fastcall SaveDBNameToList(bool AddFLG);
        TStringList *DBNames;
};
//---------------------------------------------------------------------------
//extern PACKAGE TSelectBaseForm *SBF;
//---------------------------------------------------------------------------
#endif
