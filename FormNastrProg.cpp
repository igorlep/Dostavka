//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "FormNastrProg.h"
#include "Main.h"
#include "DataModule.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "Placemnt"
#pragma link "SmrtPanel"
#pragma link "JvExMask"
#pragma link "JvToolEdit"
#pragma link "JvEdit"
#pragma link "JvExStdCtrls"
#pragma link "JvHtControls"
#pragma resource "*.dfm"
TFormParamProg *FormParamProg;
//---------------------------------------------------------------------------
__fastcall TFormParamProg::TFormParamProg(TComponent* Owner)
: TForm(Owner)
{
TIniFile* ini;
  workDir=ExtractFilePath(Application->ExeName);
  iniFileName=workDir+"AccountGSM.ini";
  FormStorage->IniFileName=iniFileName;
  FormStorage->IniSection="FormNastrProg";
  ini=new TIniFile(iniFileName);
  odpp = ini->ReadString("Parametr","odpp","");
  fio = ini->ReadString("Parametr","fio","");
  tel = ini->ReadString("Parametr","tel","");
  email = ini->ReadString("Parametr","email","");
  index = ini->ReadString("Parametr","index","");
  delete ini;
}
//---------------------------------------------------------------------------
void __fastcall TFormParamProg::SaveButtonClick(TObject *Sender)
{
TIniFile* ini;
ini=new TIniFile(iniFileName);

if (JvEdit1->Text=="" && JvEdit2->Text=="" && JvEdit3->Text=="" && JvEdit4->Text=="" && JvEdit5->Text=="")
{
ShowMessage("Неверно указаны параметры!!!");
JvEdit1->SetFocus();
return;
}
else
{
  if (!JvEdit1->Text.IsEmpty())
  {
    odpp=JvEdit1->Text.Trim();
    ini->WriteString("Parametr","odpp",odpp);
  }
  else
  {
    ShowMessage("Не отнесено ОДПП к району !!!");
    JvEdit1->SetFocus();
    return;
  }

  if (!JvEdit2->Text.IsEmpty())
  {
    fio=JvEdit2->Text.Trim();
    ini->WriteString("Parametr","fio",fio);
  }
  else
  {
    ShowMessage("Не указано Ф.И.О. !!!");
    JvEdit2->SetFocus();
    return;
  }

  if (!JvEdit3->Text.IsEmpty())
  {
    tel=JvEdit3->Text.Trim();
    ini->WriteString("Parametr","tel",tel);
  }
  else
  {
    ShowMessage("Не указано Ф.И.О главного кассира !!!");
    JvEdit3->SetFocus();
    return;
  }

  if (!JvEdit4->Text.IsEmpty())
  {
    email=JvEdit4->Text.Trim();
    ini->WriteString("Parametr","email",email);
  }
  else
  {
    ShowMessage("Не указано Ф.И.О кассира !!!");
    JvEdit4->SetFocus();
    return;
  }

  if (!JvEdit5->Text.IsEmpty())
  {
    index=JvEdit5->Text.Trim();
    ini->WriteString("Parametr","index",index);
  }
  else
  {
    ShowMessage("Не указан индекс предприятия !!!");
    JvEdit5->SetFocus();
    return;
  }

  if (!JvHTComboBox1->Text.IsEmpty())
  {
  GSM_DM->SetConstValue(GSM_DM->UserID,JvHTComboBox1->ItemIndex);
  ShowMessage("Изменения вступят в силу ТОЛЬКО после перезапуска АИС Доставка !!!");
  }
  else
  {
    ShowMessage("Не выбрано схема разметки !!!");
    JvHTComboBox1->SetFocus();
    return;
  }
}
delete ini;
Close();
ModalResult=mrOk;
}
//---------------------------------------------------------------------------


void __fastcall TFormParamProg::FormActivate(TObject *Sender)
{
 JvEdit1->Text = odpp;
 JvEdit2->Text = fio;
 JvEdit3->Text = tel;
 JvEdit4->Text = email;
 JvEdit5->Text = index;
 if(GSM_DM->GetConstValue(GSM_DM->UserID)==1)
 {
 JvHTComboBox1->ItemIndex=1;
 }else
 {
 JvHTComboBox1->ItemIndex=0;
 }

}
//---------------------------------------------------------------------------

void __fastcall TFormParamProg::Button1Click(TObject *Sender)
{
        Close();
        ModalResult=mrCancel;
}
//---------------------------------------------------------------------------

