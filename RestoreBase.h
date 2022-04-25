//---------------------------------------------------------------------------

#ifndef RestoreBaseH
#define RestoreBaseH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "Placemnt.hpp"
#include "IB_Services.hpp"
#include "ToolEdit.hpp"
#include "ZipBuilder.h"
#include <Buttons.hpp>
#include <ExtCtrls.hpp>
#include <Mask.hpp>
#include "RxRichEd.hpp"
//---------------------------------------------------------------------------
class TRestoreBaseForm : public TForm
{
__published:	// IDE-managed Components
        TFormStorage *FormStorage1;
        TpFIBRestoreService *RestoreService;
        TPanel *Panel1;
        TLabel *Label1;
        TFilenameEdit *FilenameEdit;
        TCheckBox *CheckBox1;
        TLabel *Label2;
        TRxRichEdit *RichEdit1;
        TLabel *Label3;
        TFilenameEdit *NetFilenameEdit;
        TBitBtn *RestoreButton;
        TBitBtn *ExitButton;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall FilenameEditAfterDialog(TObject *Sender,
          AnsiString &Name, bool &Action);
        void __fastcall NetFilenameEditAfterDialog(TObject *Sender,
          AnsiString &Name, bool &Action);
        void __fastcall RestoreButtonClick(TObject *Sender);
        void __fastcall ExitButtonClick(TObject *Sender);
private:	// User declarations
        
public:		// User declarations
        __fastcall TRestoreBaseForm(TComponent* Owner);
//        AnsiString ZipFileName, BackUpFileName, DataBaseFileName, Server, DBNetName;
        AnsiString BackUpFileName, ZipFileName, DBNetName;
};
//---------------------------------------------------------------------------
extern PACKAGE TRestoreBaseForm *RestoreBaseForm;
//---------------------------------------------------------------------------
#endif
