//---------------------------------------------------------------------------

#ifndef UsersH
#define UsersH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "Placemnt.hpp"
#include "DBGridEh.hpp"
#include "FIBDataSet.hpp"
#include "pFIBDataSet.hpp"
#include <DB.hpp>
#include <Grids.hpp>
#include <Buttons.hpp>
#include <ExtCtrls.hpp>
#include <Menus.hpp>
#include "FIBDatabase.hpp"
#include "pFIBDatabase.hpp"
//---------------------------------------------------------------------------
class TUsersForm : public TForm
{
__published:	// IDE-managed Components
        TFormStorage *FormStorage;
        TpFIBDataSet *usersDS;
        TDBGridEh *usersGrid;
        TDataSource *usersS;
        TPanel *GridButtonsPanel;
        TSpeedButton *PostButton;
        TSpeedButton *CancelButton;
        TPopupMenu *usersPM;
        TMenuItem *N1;
        TMenuItem *N2;
        TMenuItem *N3;
        TMenuItem *N4;
        TMenuItem *N5;
        TFIBSmallIntField *usersDSU_ID;
        TFIBStringField *usersDSU_NAME;
        TFIBStringField *usersDSU_LOGIN;
        TFIBStringField *usersDSU_PASSWORD;
        TFIBStringField *usersDSU_ROLE;
        TFIBStringField *usersDSU_INDEX;
        TSpeedButton *reloadButton;
        TFIBSmallIntField *usersDSIDINS;
        TpFIBDataSet *usersINS;
        void __fastcall usersSStateChange(TObject *Sender);
        void __fastcall PostButtonClick(TObject *Sender);
        void __fastcall CancelButtonClick(TObject *Sender);
        void __fastcall N1Click(TObject *Sender);
        void __fastcall N2Click(TObject *Sender);
        void __fastcall N3Click(TObject *Sender);
        void __fastcall N5Click(TObject *Sender);
        void __fastcall N4Click(TObject *Sender);
        void __fastcall usersGridKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall reloadButtonClick(TObject *Sender);
private:	// User declarations
        AnsiString workDir;
public:		// User declarations
        __fastcall TUsersForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
//extern PACKAGE TUsersForm *UsersForm;
//---------------------------------------------------------------------------
#endif
