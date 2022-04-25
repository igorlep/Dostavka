//---------------------------------------------------------------------------

#ifndef LoadDataH
#define LoadDataH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "JvComponent.hpp"
#include "JvExControls.hpp"
#include "JvNavigationPane.hpp"
#include "Placemnt.hpp"
#include <Buttons.hpp>
#include <ExtCtrls.hpp>
#include "JvDotNetControls.hpp"
#include "JvExMask.hpp"
#include "JvToolEdit.hpp"
#include <Mask.hpp>
#include <ADODB.hpp>
#include <DB.hpp>
#include "JvExComCtrls.hpp"
#include "JvProgressBar.hpp"
#include <ComCtrls.hpp>
//---------------------------------------------------------------------------
class TLoadDataForm : public TForm
{
__published:	// IDE-managed Components
        TFormStorage *FormStorage;
        TPanel *Panel2;
        TBitBtn *LoadButton;
        TPanel *Panel1;
        TLabel *Label1;
        TJvDotNetDirectoryEdit *DirectoryEdit;
        TMemo *Memo1;
        TADOConnection *ADOConnection;
        TADOQuery *ADOTable;
        TLabel *Label2;
        TJvProgressBar *ProgressBar;
        TPanel *Panel3;
        TLabel *Label3;
        TJvDateEdit *DateEdit1;
        TLabel *Label4;
        TJvDateEdit *DateEdit2;
        TLabel *Label5;
        TComboBox *sdBox;
        void __fastcall DirectoryEditAfterDialog(TObject *Sender,
          AnsiString &Name, bool &Action);
        void __fastcall FormShow(TObject *Sender);
        void __fastcall LoadButtonClick(TObject *Sender);
        void __fastcall FormDestroy(TObject *Sender);
        void __fastcall sdBoxChange(TObject *Sender);
private:	// User declarations
  AnsiString workDir;
  AnsiString filename_mp, filename_mt, filename_s;
  TStringList *COD_M;
  TStringList *SD_COD;
  void __fastcall readDataForMemo(void);
public:		// User declarations
  __fastcall TLoadDataForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TLoadDataForm *LoadDataForm;
//---------------------------------------------------------------------------
#endif
