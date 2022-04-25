//---------------------------------------------------------------------------

#ifndef LoadDataFromExcelFileH
#define LoadDataFromExcelFileH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "Placemnt.hpp"
#include <Buttons.hpp>
#include <ExtCtrls.hpp>
#include "JvComponent.hpp"
#include "JvExControls.hpp"
#include "JvExMask.hpp"
#include "JvToolEdit.hpp"
#include "JvXPButtons.hpp"
#include "JvXPCore.hpp"
#include <ADODB.hpp>
#include <DB.hpp>
#include <Mask.hpp>
//---------------------------------------------------------------------------
class TLoadDataFromExcelFileForm : public TForm
{
__published:	// IDE-managed Components
  TFormStorage *FormStorage;
  TPanel *buttonPanel;
  TPanel *workPanel;
  TJvXPButton *loadButton;
  TLabel *Label1;
  TJvFilenameEdit *filenameEdit;
  TMemo *memo;
  TLabel *Label2;
  TPanel *Panel3;
  TLabel *Label3;
  TLabel *Label4;
  TLabel *Label5;
  TJvDateEdit *fromDateEdit;
  TJvDateEdit *toDateEdit;
  TComboBox *cardNumberBox;
  void __fastcall filenameEditAfterDialog(TObject *Sender,AnsiString &Name,bool &Action);
  void __fastcall loadButtonClick(TObject *Sender);
private:	// User declarations
  AnsiString iniFileName;
  AnsiString workDir;
  class DirectWorkExcel *dwe;
  AnsiString sd_id,cod_m,sd_name;
  TpFIBQuery *WQ;
  bool errFLG;
  int allRecords;
  double allSumma;
  int __fastcall loadDataForCard(int rn);
  AnsiString __fastcall getAutoID(AnsiString autoNum);
  AnsiString __fastcall getElectronicCardID(AnsiString cardNum,AnsiString auto_id);
  AnsiString __fastcall getGSM_ID(AnsiString gsmName);
  void __fastcall testAutoForGSM_ID(AnsiString auto_id,AnsiString gsm_id);
public:		// User declarations
  __fastcall TLoadDataFromExcelFileForm(TComponent* Owner,AnsiString iniFN);
  __fastcall ~TLoadDataFromExcelFileForm(void);
};
//---------------------------------------------------------------------------
//extern PACKAGE TLoadDataFromExcelFileForm *LoadDataFromExcelFileForm;
//---------------------------------------------------------------------------
#endif
