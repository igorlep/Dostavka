                                                                                                                                                                         //---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "SelectBase.h"
#include "Entry.h"
#include "DataModule.h"
#include "Main.h"

#define MUTEX_NAME "Programm AccountGSM"
//---------------------------------------------------------------------------
USEFORM("Main.cpp", MainForm);
USEFORM("SelectBase.cpp", SelectBaseForm);
USEFORM("Entry.cpp", EntryForm);
USEFORM("AdjustConnection.cpp", AdjustConnectionForm);
USEFORM("DataModule.cpp", GSM_DM); /* TDataModule: File Type */
USEFORM("SelectPeriod.cpp", SelectPeriodForm);
USEFORM("UniversalReferenceBook.cpp", URB);
USEFORM("AddEditRBRecord.cpp", AddEditRBRecordForm);
USEFORM("RBConfiguration.cpp", RBConfigurationForm);
USEFORM("RBMoveRecords.cpp", RBMoveRecordsForm);
USEFORM("AddEditExpense.cpp", AddEditExpenseForm);
USEFORM("Users.cpp", UsersForm);
USEFORM("ChangePass.cpp", ChangePassForm);
USEFORM("BackUpBase.cpp", BackUpBaseForm);
USEFORM("RestoreBase.cpp", RestoreBaseForm);
USEFORM("ExpensesListOnDate.cpp", ExpensesListOnDateForm);
USEFORM("ExpensesListOnAuto.cpp", ExpensesListOnAutoForm);
USEFORM("ConditionsChoice.cpp", ConditionsChoiceForm);
USEFORM("StatForm.cpp", ExpensesListOnAutoForm1);
USEFORM("ReestrForm.cpp", ExpensesListOnAutoForm2);
USEFORM("FormNastrProg.cpp", FormParamProg);
USEFORM("Vedofvyp.cpp", ExpensesListOnAutoForm3);
USEFORM("Vedofkol.cpp", ExpensesListOnAutoForm4);
USEFORM("ReestrSum.cpp", ExpensesListOnAutoForm5);
USEFORM("UnitF55.cpp", FormF55);
USEFORM("BlockForm.cpp", FormBlock);
USEFORM("FormScan.cpp", ScanerForm);
USEFORM("AccountEdit.cpp", AccountEditForm);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
HANDLE hMutex=0;
TIniFile* ini;
AnsiString workDir,iniFileName;


  try
  { //?????????, ?? ???????? ?? ??? ???????????
    hMutex = OpenMutex( MUTEX_ALL_ACCESS, FALSE, MUTEX_NAME);
    if(hMutex)
    { MessageDlg("????????? \"????????. ???? ????????\" ??? ????????",mtWarning,TMsgDlgButtons() << mbOK,0);
      return 0;
    }
    hMutex = CreateMutex(NULL, false, "Programm AccountGSM");

    Application->Initialize();
    Application->Title = "????????? \"????????. ???? ????????\"";

    TSelectBaseForm *SBF;
    try
    {
      SBF=new TSelectBaseForm(static_cast<void*>(NULL));
    }
    catch(const Exception &exc)
    {
      MessageDlg("?????? ???????? ????? SelectBaseForm\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      if(hMutex)
      { ReleaseMutex(hMutex);
        CloseHandle(hMutex);
      }
      return 0;
    }
    if(SBF->ShowModal()!=mrOk)
    { delete SBF;
      if(hMutex)
      { ReleaseMutex(hMutex);
        CloseHandle(hMutex);
      }
      return 0;
    }

    AnsiString InitString=SBF->DBNames->Strings[SBF->DBNamesBox->ItemIndex];
    delete SBF;

    TEntryForm *Entry;
    try
    {
      Entry=new TEntryForm(static_cast<void*>(NULL),InitString);
    }
    catch(const Exception &exc)
    {
      MessageDlg("?????? ???????? ????? EnrtyForm\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      if(hMutex)
      { ReleaseMutex(hMutex);
        CloseHandle(hMutex);
      }
      return 0;
    }
    if(Entry->ShowModal()==mrOk)
    {
      Application->CreateForm(__classid(TGSM_DM), &GSM_DM);
                 Application->CreateForm(__classid(TMainForm), &MainForm);
                 GSM_DM->InitString=InitString;
      GSM_DM->Alias=InitString.SubString(0,InitString.Pos("=")-1);
      GSM_DM->Server=InitString.SubString(InitString.Pos("=")+1,InitString.Pos(":")-InitString.Pos("="));
      AnsiString DBName=InitString;
      int p2=DBName.Pos(":");
      int p3=DBName.Pos(",");
      AnsiString DBPath=DBName.SubString(p2+1,p3-p2-1);
      GSM_DM->DB_Name=DBPath;
      AnsiString DBLogPass=DBName.SubString(p3+1,DBName.Length());
      int p4=DBLogPass.Pos(",");
      AnsiString DBLog=DBLogPass.SubString(1,p4-1);
      AnsiString DBPass=DBLogPass.SubString(p4+1,DBLogPass.Length());
      int p5=DBName.Pos("63");
      if (p5>0)
      {
      GSM_DM->Index=DBName.SubString(p5,6);
      }else
      {
       workDir=ExtractFilePath(Application->ExeName);
       iniFileName=workDir+"AccountGSM.ini";
       ini=new TIniFile(iniFileName);
       GSM_DM->Index = ini->ReadString("Parametr","index","");
       delete ini;
      }

      GSM_DM->UserName=DBLog;
      GSM_DM->PasswordUser=DBPass;
      int p=InitString.Length(), p1=p;
      while(p>1 && InitString[p]!='\\' && InitString[p]!='/') --p;
      if(InitString[p]=='\\' || InitString[p]=='/') p++;
      GSM_DM->Base_Name=InitString.SubString(p,p1-p+1);

      GSM_DM->UserID=StrToInt(Entry->UsersID->Strings[Entry->UsersBox->ItemIndex]);
      GSM_DM->UserRole=Entry->UsersRole->Strings[Entry->UsersBox->ItemIndex];
      GSM_DM->NetName=Entry->NetName;
      GSM_DM->UserLogin=Entry->UsersBox->Items->Strings[Entry->UsersBox->ItemIndex];
      delete Entry;
      if(!GSM_DM->ConnectToDataBase())
      { if(hMutex)
        { ReleaseMutex(hMutex);
          CloseHandle(hMutex);
        }
        return 0;
      }
      MainForm->initMainForm();
      Application->Run();

    }
    else
    { delete Entry;
      if(hMutex)
      { ReleaseMutex(hMutex);
        CloseHandle(hMutex);
      }
      return 0;
    }
  }

  catch (Exception &exception)
  {
    Application->ShowException(&exception);
  }
  catch (...)
  {
    try
    {
      throw Exception("");
    }
    catch (Exception &exception)
    {
      Application->ShowException(&exception);
    }
  }

  if(hMutex)
  { ReleaseMutex(hMutex);
    CloseHandle(hMutex);
  }
  return 0;
}
//---------------------------------------------------------------------------

