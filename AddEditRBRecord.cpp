//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UniversalReferenceBook.h"
#include "AddEditRBRecord.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "ToolEdit"
#pragma link "SmrtPanel"
#pragma link "JvComponent"
#pragma link "JvExControls"
#pragma link "JvSpeedButton"
#pragma link "JvBitBtn"
#pragma link "JvExButtons"
#pragma resource "*.dfm"
//********************************************
//* Класс RBEditorElemet - элемент редактора *
//********************************************
//Конструктор
__fastcall RBEditorElement::RBEditorElement(TComponent* owner, MFieldInfo *fi, int fieldNum)
{
  Owner=owner;
  fieldInfo=fi;
  fieldNumber=fieldNum;
  label=new TLabel(Owner);
  label->Caption=fieldInfo->getFieldTitle();
  editable=fieldInfo->isEditable();
  if(fieldInfo->isEditable() == true)
  { if(fieldInfo->getFieldType()==4)      //поле - дата
    { edit=new TDateEdit(Owner);
      ((TDateEdit*)edit)->Text=fieldInfo->getFieldData();
      ((TDateEdit*)edit)->ClickKey=VK_INSERT;
      ((TDateEdit*)edit)->OnKeyDown=EditOnKeyDown;
      ((TDateEdit*)edit)->OnKeyPress=EditOnKeyPress;
    }
    else if(fieldInfo->getFieldType()==9) //поле - ссылка
    { edit=new TComboEdit(Owner);
      ((TComboEdit*)edit)->GlyphKind=gkEllipsis;
      ((TComboEdit*)edit)->Text=fieldInfo->getRetFieldData();
      ((TComboEdit*)edit)->OnButtonClick=ComboEditOnClickButton;
      ((TComboEdit*)edit)->OnMouseDown=ComboEditOnMouseDown;
      ((TComboEdit*)edit)->ClickKey=VK_INSERT;
      ((TComboEdit*)edit)->OnKeyDown=EditOnKeyDown;
      ((TComboEdit*)edit)->OnKeyPress=EditOnKeyPress;
    }
    else
    { edit=new TEdit(Owner);
      ((TEdit*)edit)->Text=fieldInfo->getFieldData();
      if(fieldInfo->getFieldType()==3) //текстовое поле
        ((TEdit*)edit)->MaxLength=fieldInfo->getFieldLength();
      ((TEdit*)edit)->OnKeyDown=EditOnKeyDown;
      ((TEdit*)edit)->OnKeyPress=EditOnKeyPress;
    }
  }
  else
  { edit=new TStaticText(Owner);
    ((TStaticText*)edit)->BevelKind=bkFlat;
    ((TStaticText*)edit)->AutoSize=false;
    ((TStaticText*)edit)->Height=24;
    if(fi->getFieldType()==9) ((TStaticText*)edit)->Caption=fieldInfo->getRetFieldData();
    else ((TStaticText*)edit)->Caption=fieldInfo->getFieldData();
  }
  prevEditableElement=NULL;
  nextEditableElement=NULL;
}
//---------------------------------------------------------------------------
//Деструктор
__fastcall RBEditorElement::~RBEditorElement(void)
{
  if(label!=NULL){ delete label; label=NULL; }
  if(edit!=NULL){ delete edit; edit=NULL; }
}
//---------------------------------------------------------------------------
void __fastcall RBEditorElement::ComboEditOnClickButton(TObject* Sender)
{
  if(!fieldInfo->getRefTableName().IsEmpty())
  { TURB *urb=NULL;
    try
    {
      urb=new TURB(Owner,fieldInfo->getRefTableName(),0);
    }
    catch (Exception &exc)
    { MessageDlg("Ошибка создания объекта TURB\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      return;
    }
    TAddEditRBRecordForm *editForm=static_cast<TAddEditRBRecordForm*>(Owner);
    int p=editForm->getFI()->getPisitionField("SD_ID");
    if(p>=0)
    { AnsiString sdName=editForm->getFI()->getFieldInfo(p)->getRetFieldData();
      p=urb->getFieldInfo()->getPisitionField("SD_ID");
      if(p>=0) urb->FindPositionInTreeViewForFolderName(sdName);
    }
    if(urb->ShowModal()==mrOk)
    { ((TComboEdit*)edit)->Text=urb->DS->FieldByName("DESCRIPTION")->AsString;
      fieldInfo->setFieldData(urb->DS->FieldByName(urb->getKeyFieldName())->AsString);
      fieldInfo->setRetFieldData(((TComboEdit*)edit)->Text);
    }
    if(urb!=NULL) delete urb;
  }
}
//---------------------------------------------------------------------------
void __fastcall RBEditorElement::ComboEditOnMouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
TShiftState ss;

  ss << ssAlt << ssRight;
  if(Button==mbRight && Shift==ss)
  { Button=0;
    int te=fieldInfo->getFieldType();
    if(te==9)
    { ((TComboEdit*)edit)->Text="";
      fieldInfo->setFieldData("");
      fieldInfo->setRetFieldData("");
    }
  }
}
//---------------------------------------------------------------------------
void __fastcall RBEditorElement::EditOnKeyDown(TObject* Sender, unsigned short &Key, TShiftState Shift)
{
  if(Key==VK_DOWN)
  { Key=0;
    if(nextEditableElement!=NULL)
    { int te=nextEditableElement->fieldInfo->getFieldType();
      if(te==9) ((TComboEdit*)(nextEditableElement->getEdit()))->SetFocus();
      else if(te==4) ((TDateEdit*)(nextEditableElement->getEdit()))->SetFocus();
      else ((TEdit*)(nextEditableElement->getEdit()))->SetFocus();
    }
    else ((TAddEditRBRecordForm*)Owner)->SaveButton->SetFocus();
  }
  else if(Key==VK_UP)
  { Key=0;
    if(prevEditableElement!=NULL)
    { int te=prevEditableElement->fieldInfo->getFieldType();
      if(te==9) ((TComboEdit*)(prevEditableElement->getEdit()))->SetFocus();
      else if(te==4) ((TDateEdit*)(prevEditableElement->getEdit()))->SetFocus();
      else ((TEdit*)(prevEditableElement->getEdit()))->SetFocus();
    }
    else ((TAddEditRBRecordForm*)Owner)->CancelButton->SetFocus();
  }
  else if(Key == VK_DELETE)
  { int te=fieldInfo->getFieldType();
    if(te==9)
    { ((TComboEdit*)edit)->Text="";
      fieldInfo->setFieldData("");
      fieldInfo->setRetFieldData("");
      Key=0;
    }
  }
}
//---------------------------------------------------------------------------
void __fastcall RBEditorElement::EditOnKeyPress(TObject* Sender, char &Key)
{
  if(Key==VK_RETURN)
  { Key=0;
    if(nextEditableElement!=NULL)
    { int te=nextEditableElement->fieldInfo->getFieldType();
      if(te==9) ((TComboEdit*)(nextEditableElement->getEdit()))->SetFocus();
      else if(te==4) ((TDateEdit*)(nextEditableElement->getEdit()))->SetFocus();
      else ((TEdit*)(nextEditableElement->getEdit()))->SetFocus();
    }
    else ((TAddEditRBRecordForm*)Owner)->SaveButton->SetFocus();
  }
  else if(Key == VK_ESCAPE){ Key=0; ((TAddEditRBRecordForm*)Owner)->CancelButton->Click(); }
}
//***************************************************************************
//*************************************************************
//* Класс TAddEditRBRecordForm  - радактор записи справочника *
//*************************************************************
//---------------------------------------------------------------------------
__fastcall TAddEditRBRecordForm::TAddEditRBRecordForm(TComponent* Owner, MFieldsInformation *fi, bool nrflg)
        : TForm(Owner)
{
  RB=(TURB *)Owner;
  FI=fi;
  newRecordFLG=nrflg;
  if(newRecordFLG==true) Caption="Справочник \""+RB->getRBTitle()+"\" - новая запись";
  else  Caption="Справочник \""+RB->getRBTitle()+"\" - редактирование записи";
  RB_EE=NULL;
  accessableFieldsCount=FI->getAccessableFildsCount();
  editableFieldsCount=FI->getEditableFildsCount();

  int tabNum=0;
  if(accessableFieldsCount > 0)
  { try
    { RB_EE=new RBEditorElement*[accessableFieldsCount];
      for(int i=0, j=0; i<FI->getFieldsCount(); i++)
      { if(FI->getFieldInfo(i)->isAccessable())
        { try
          { int ft=FI->getFieldInfo(i)->getFieldType(); //тип поля
            RB_EE[j]=new RBEditorElement(this, FI->getFieldInfo(i), i);
            TLabel *lab=RB_EE[j]->getLabel();
            if(lab!=NULL)
            { lab->Parent=workPanel;
              lab->Height=20;
              lab->Top=16+(lab->Height+8)*j;
              lab->Left=20;
              lab->Alignment=taRightJustify;
              lab->Visible=true;
            }
            TControl *edit=RB_EE[j]->getEdit();
            if(edit!=NULL)
            { edit->Parent=workPanel;
              edit->Top=lab->Top-4;
              int width;
              if(ft==4 || ft==5) width=100;
              else if(ft==9)
              { int len=FI->getFieldInfo(i)->getRetFieldData().Length();
                width=len*12;
                if(width<100) width=100;
              }
              else width=FI->getFieldInfo(i)->getFieldLength()*7;
              if(width > 500) width=500;
              else if(width < 50) width=50;
              edit->Width=width;
              if(FI->getFieldInfo(i)->isEditable())
              { edit->Enabled=true;
                ((TWinControl*)edit)->TabStop=true;
                ((TWinControl*)edit)->TabOrder=tabNum;
                tabNum++;
              }
              else
              { edit->Enabled=false;
                ((TWinControl*)edit)->TabStop=false;
              }
            }
            j++;
          }
          catch (Exception &exc)
          { MessageDlg("Ошибка выделения памяти под RB_EE["+IntToStr(i)+"]\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
            RB_EE[i]=NULL;
          }
        }
      }
    }
    catch (Exception &exc)
    { MessageDlg("Ошибка выделения памяти под RBEditorElement\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      RB_EE=NULL;
      return;
    }
  }

  //Настраиваем ссылки prevEditableElement и nextEditableElement
  if(editableFieldsCount > 1)
  { RBEditorElement *pe=NULL;//, *ne=NULL;
    for(int i=0, j=0; i<accessableFieldsCount; i++)
    { if(RB_EE[i]->isEditable())
      { AnsiString t=RB_EE[i]->getLabel()->Caption;
        if(j==0) pe=RB_EE[i];
        else
        { RB_EE[j]->setNextEAE(RB_EE[i]);
          RB_EE[i]->setPrevEAE(pe);
          pe=RB_EE[i];
        }
        j=i;
      }
    }
  }

  //Настраиваем расположение компонентов на форме
  int maxLabelWidth=0;
  int maxEditWidth=0;
  for(int i=0; i<accessableFieldsCount; i++)
  { if(RB_EE[i]->getLabel()!=NULL && maxLabelWidth < RB_EE[i]->getLabel()->Width) maxLabelWidth=RB_EE[i]->getLabel()->Width;
    if(RB_EE[i]->getEdit()!=NULL && maxEditWidth < RB_EE[i]->getEdit()->Width) maxEditWidth=RB_EE[i]->getEdit()->Width;
  }
  for(int i=0; i<accessableFieldsCount; i++)
  { if(RB_EE[i]->getLabel()!=NULL)
    { RB_EE[i]->getLabel()->AutoSize=false;
      RB_EE[i]->getLabel()->Width=maxLabelWidth;
      if(RB_EE[i]->getEdit()!=NULL)
        RB_EE[i]->getEdit()->Left=RB_EE[i]->getLabel()->Left+RB_EE[i]->getLabel()->Width+10;
    }
  }
  //Восстанавливаем положение и размеры окна
  workDir=ExtractFilePath(Application->ExeName);
  getProperties();
  //Настраиваем правые границы компонентов, если они выходят за пределы окна
  for(int i=0; i<accessableFieldsCount; i++)
  { if(RB_EE[i]->getEdit()!=NULL)
    { TControl *edit=RB_EE[i]->getEdit();
      if(edit->Left+edit->Width+28 > Width) edit->Width=Width-edit->Left-28;
    }
  }
  //Проверяем правую границу максимального по ширине компонента
  int mn=-1, maxWidth=0;
  for(int i=0; i<accessableFieldsCount; i++)
  { if(RB_EE[i]->getEdit()!=NULL)
    { if(RB_EE[i]->getEdit()->Width  > maxWidth)
      { maxWidth=RB_EE[i]->getEdit()->Width;
        mn=i;
      }
    }
  }
  if(mn >= 0)
  { TControl *edit=RB_EE[mn]->getEdit();
    if(edit->Left+edit->Width+28 < Width)
      edit->Width=Width-edit->Left-28;
  }
  //
  for(int i=0, j=0; i<FI->getFieldsCount(); i++)
  { if(FI->getFieldInfo(i)->isAccessable())
    { if(RB_EE[j]->getEdit()!=NULL)
      { int ft=FI->getFieldInfo(i)->getFieldType();
        if(ft==3 || ft==9) RB_EE[j]->getEdit()->Anchors << akLeft << akRight;
      }
      j++;
    }
  }

  //Настраиваем кнопки
  SaveButton->Top=RB_EE[accessableFieldsCount-1]->getEdit()->Top+RB_EE[accessableFieldsCount-1]->getEdit()->Height+16;
  CancelButton->Top=SaveButton->Top;
  SaveButton->Left=workPanel->Width-244; if(SaveButton->Left < 0) SaveButton->Left=0;
  CancelButton->Left=SaveButton->Left+120;
  SaveButton->TabOrder=tabNum; tabNum++; SaveButton->TabStop=true;
  CancelButton->TabOrder=tabNum; CancelButton->TabStop=true;
}
//---------------------------------------------------------------------------
void __fastcall TAddEditRBRecordForm::FormShow(TObject *Sender)
{
  for(int i=0; i<accessableFieldsCount; i++)
  { if(((TWinControl*)RB_EE[i]->getEdit())->TabStop==true && ((TWinControl*)RB_EE[i]->getEdit())->TabOrder==0)
    { ((TWinControl*)RB_EE[i]->getEdit())->SetFocus();
      break;
    }
  }
}
//---------------------------------------------------------------------------
void __fastcall TAddEditRBRecordForm::FormDestroy(TObject *Sender)
{
  setProperties();
  for(int i=0; i<accessableFieldsCount; i++)
  { if(RB_EE[i]!=NULL)
     delete RB_EE[i];
  }
  if(RB_EE!=NULL) delete[] RB_EE;
}
//---------------------------------------------------------------------------
void __fastcall TAddEditRBRecordForm::getProperties(void)
{
TIniFile* ini;

  ini=new TIniFile(workDir+"AccountGSM.ini");
  //Положение на экране
  Top=ini->ReadInteger(RB->getRBTitle()+" - редактор","Top",0);
  Left=ini->ReadInteger(RB->getRBTitle()+" - редактор","Left",0);
  //Размеры окна
  Width=ini->ReadInteger(RB->getRBTitle()+" - редактор","Width",300);
  Height=ini->ReadInteger(RB->getRBTitle()+" - редактор","Height",200);
  delete ini;
}
//---------------------------------------------------------------------------
void __fastcall TAddEditRBRecordForm::setProperties(void)
{
TIniFile* ini;

  ini=new TIniFile(workDir+"AccountGSM.ini");
  //Положение на экране
  ini->WriteInteger(RB->getRBTitle()+" - редактор","Top",Top);
  ini->WriteInteger(RB->getRBTitle()+" - редактор","Left",Left);
  //Размеры окна
  ini->WriteInteger(RB->getRBTitle()+" - редактор","Width",Width);
  ini->WriteInteger(RB->getRBTitle()+" - редактор","Height",Height);
  delete ini;
}
//---------------------------------------------------------------------------
RBEditorElement * __fastcall TAddEditRBRecordForm::getFirstEAE(void)
{
  if(editableFieldsCount > 1)
  { for(int i=0; i<accessableFieldsCount; i++)
      if(RB_EE[i]->getPrevEAE()==NULL && RB_EE[i]->getNextEAE()!=NULL) return RB_EE[i];
    return NULL;
  }
  else
  { for(int i=0; i<accessableFieldsCount; i++) if(RB_EE[i]->isEditable()) return RB_EE[i];
    return NULL;
  }
}
//---------------------------------------------------------------------------
RBEditorElement * __fastcall TAddEditRBRecordForm::getLastEAE(void)
{
  if(editableFieldsCount > 1)
  { for(int i=0; i<accessableFieldsCount; i++)
      if(RB_EE[i]->getPrevEAE()!=NULL && RB_EE[i]->getNextEAE()==NULL) return RB_EE[i];
    return NULL;
  }
  else
  { for(int i=0; i<accessableFieldsCount; i++) if(RB_EE[i]->isEditable()) return RB_EE[i];
    return NULL;
  }
}
//---------------------------------------------------------------------------

void __fastcall TAddEditRBRecordForm::SaveButtonClick(TObject *Sender)
{
  for(int i=0; i<accessableFieldsCount; i++)
  { if(RB_EE[i]->isEditable())
    { if(RB_EE[i]->getFieldInfo()->getFieldType()==4)
      { if(int(((TDateEdit*)RB_EE[i]->getEdit())->Date) > 0)
          RB_EE[i]->getFieldInfo()->setFieldData(((TDateEdit*)RB_EE[i]->getEdit())->Text);
        else RB_EE[i]->getFieldInfo()->setFieldData("");
      }
      else if(RB_EE[i]->getFieldInfo()->getFieldType()>0 && RB_EE[i]->getFieldInfo()->getFieldType()<4)
        RB_EE[i]->getFieldInfo()->setFieldData(((TEdit*)RB_EE[i]->getEdit())->Text);
    }
  }
  Close();
  ModalResult=mrOk;
}
//---------------------------------------------------------------------------
void __fastcall TAddEditRBRecordForm::SaveButtonKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
  if(Key==VK_UP)
  { RBEditorElement *le=getLastEAE();
    if(le!=NULL)
    { Key=0;
      int te=le->getFieldInfo()->getFieldType();
      TControl *e=le->getEdit();
      if(e!=NULL)
      { if(te==4) ((TDateEdit*)e)->SetFocus();
        else if(te==9) ((TComboEdit*)e)->SetFocus();
        else ((TEdit*)e)->SetFocus();
      }
    }
  }
}
//---------------------------------------------------------------------------
void __fastcall TAddEditRBRecordForm::CancelButtonClick(TObject *Sender)
{
  Close();
  ModalResult=mrCancel;
}
//---------------------------------------------------------------------------
void __fastcall TAddEditRBRecordForm::CancelButtonKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
RBEditorElement *le=getFirstEAE();

  if(le!=NULL && Key==VK_DOWN)
  { Key=0;
    TControl *e=le->getEdit();
    int te=le->getFieldInfo()->getFieldType();
    if(e!=NULL)
    { if(te==4) ((TDateEdit*)e)->SetFocus();
      else if(te==9) ((TComboEdit*)e)->SetFocus();
      else ((TEdit*)e)->SetFocus();
    }
  }
}
//---------------------------------------------------------------------------
RBEditorElement * __fastcall TAddEditRBRecordForm::findEAE(int fieldNumber)
{
RBEditorElement *aee=getFirstEAE();

  do
  { int fn=aee->getFieldNumber();
    if(fn==fieldNumber) break;
    aee=aee->getNextEAE();
  }while(aee!=NULL);
  return aee;
}
//---------------------------------------------------------------------------

