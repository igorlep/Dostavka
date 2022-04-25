//---------------------------------------------------------------------------

#ifndef FormNastrProgH
#define FormNastrProgH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "Placemnt.hpp"
#include "SmrtPanel.h"
#include <Buttons.hpp>
#include <ExtCtrls.hpp>
#include "JvExMask.hpp"
#include "JvToolEdit.hpp"
#include <Mask.hpp>
#include "JvEdit.hpp"
#include "JvExStdCtrls.hpp"
#include "JvHtControls.hpp"
//---------------------------------------------------------------------------
class TFormParamProg : public TForm
{
__published:	// IDE-managed Components
        TPanel *Panel2;
        TBitBtn *SaveButton;
        TFormStorage *FormStorage;
        TPanel *Panel1;
        TLabel *Label1;
        TLabel *Label5;
        TLabel *Label8;
        TLabel *Label2;
        TButton *Button1;
        TJvEdit *JvEdit1;
        TJvEdit *JvEdit2;
        TJvEdit *JvEdit3;
        TLabel *Label3;
        TJvEdit *JvEdit4;
        TJvEdit *JvEdit5;
        TLabel *Label4;
        TLabel *Label6;
        TJvHTComboBox *JvHTComboBox1;
        TLabel *Label7;
        void __fastcall SaveButtonClick(TObject *Sender);
        void __fastcall FormActivate(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
private:	// User declarations
    int s,o,i,m;
public:		// User declarations
        __fastcall TFormParamProg(TComponent* Owner);
    AnsiString workDir;
    AnsiString iniFileName;
    AnsiString odpp,fio,tel,email,index;
};
//---------------------------------------------------------------------------
extern PACKAGE TFormParamProg *FormParamProg;
//---------------------------------------------------------------------------
#endif
