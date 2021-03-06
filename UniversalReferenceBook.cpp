//????????????? ??????????
//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "DataModule.h"
#include "AddEditRBRecord.h"
#include "RBMoveRecords.h"
#include "Main.h"
#include "UniversalReferenceBook.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "DBGridEh"
#pragma link "Placemnt"
#pragma link "FIBDataSet"
#pragma link "pFIBDataSet"
#pragma link "FIBDatabase"
#pragma link "pFIBDatabase"
#pragma link "FIBQuery"
#pragma link "pFIBQuery"
#pragma resource "*.dfm"
//***************************************************************************
//********************
//* ????? MFieldInfo *
//********************
//????????????
__fastcall MFieldInfo::MFieldInfo(void)
{
  fName=""; fTitle="";
  fType=0; fLength=0;
  accessable=false; editable=false; gridViewable=false; gridAlign="";
  fData="";
  refTableName=""; refFieldName=""; retFieldName=""; retData="";
}
//---------------------------------------------------------------------------
__fastcall MFieldInfo::MFieldInfo(AnsiString fN, AnsiString fTi, short fTy, short fL, bool aa, bool ea, bool gva, AnsiString ga, AnsiString fD, AnsiString rTN, AnsiString rFN, AnsiString retFN, AnsiString rD)
{
  fName=fN; fTitle=fTi;
  fType=fTy; fLength=fL;
  accessable=aa; editable=ea; gridViewable=gva; gridAlign=ga;
  fData=fD;
  refTableName=rTN; refFieldName=rFN; retFieldName=retFN; retData=rD;
}
//***************************************************************************
//****************************
//* ????? MFieldsInformation *
//****************************
//???????????
__fastcall MFieldsInformation::MFieldsInformation(TComponent* owner, AnsiString tn, AnsiString keyF)
{
AnsiString sql;

  Owner=owner;
  db=GSM_DM->Database;
  Q=NULL; WQ=NULL; RTransaction=NULL; WTransaction=NULL;
  DS=NULL;
  tableName=tn;
  keyField=keyF;

  try
  {
    RTransaction=new TpFIBTransaction(Owner);
    RTransaction->DefaultDatabase=db;
    WTransaction=new TpFIBTransaction(Owner);
    WTransaction->DefaultDatabase=db;
    Q=new TpFIBQuery(Owner);
    Q->Transaction=RTransaction;
    Q->Options << qoStartTransaction << qoAutoCommit;
    WQ=new TpFIBQuery(Owner);
    WQ->Transaction=WTransaction;
    WQ->Options << qoStartTransaction << qoAutoCommit;
    DS=new TpFIBDataSet(Owner);
    DS->Database=db;
    DS->Transaction=RTransaction;
    DS->UpdateTransaction=WTransaction;
    DS->AutoCommit=true;
  }
  catch (Exception &exc)
  { MessageDlg("?????? ???????? Query\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
    return;
  }

  prepareFI_Table(); //?????????????? ??????? FIELDS_INFORMATION_TABLE

  Q->Close();
  Q->SQL->Clear();
  sql="select * from "+tableName+" where "+keyField+"=0";
  Q->SQL->Add(sql);
  try
  {
    Q->ExecQuery();
  }
  catch (Exception &exc)
  { MessageDlg("?????? - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
    return;
  }
  fieldsCount=Q->FieldCount();
  if(fieldsCount > 0)
  { try
    {
      FieldsInfo=new MFieldInfo*[fieldsCount]; //?????? ?????? ? ??????????? ? ????? ???????????
      for(int i=0; i<fieldsCount; i++)
      { AnsiString fieldName=Q->FieldName(i);
        try
        { WQ->Close();
          WQ->SQL->Clear();
          sql="select * from FIELDS_INFORMATION_TABLE where TABLE_NAME='"+tableName+"' and FIELD_NAME='"+fieldName+"'";
          WQ->SQL->Add(sql);
          try
          {
            WQ->ExecQuery();
          }
          catch (Exception &exc)
          { MessageDlg("?????? - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
            return;
          }
          if(WQ->RecordCount > 0)
          { AnsiString fti="";
            if(!WQ->FieldByName("FIELD_TITLE")->IsNull) fti=WQ->FieldByName("FIELD_TITLE")->AsString;
            short fty=0;
            if(!WQ->FieldByName("FIELD_TYPE")->IsNull) fty=WQ->FieldByName("FIELD_TYPE")->AsInteger;
            short fl=0;
            if(!WQ->FieldByName("FIELD_LENGTH")->IsNull) fl=WQ->FieldByName("FIELD_LENGTH")->AsInteger;
            bool aa=false;
            if(!WQ->FieldByName("ACCESSABLE")->IsNull) aa=WQ->FieldByName("ACCESSABLE")->AsBoolean;
            bool ea=false;
            if(!WQ->FieldByName("EDITABLE")->IsNull) ea=WQ->FieldByName("EDITABLE")->AsBoolean;
            bool gva=false;
            if(!WQ->FieldByName("GRID_VIEWABLE")->IsNull) gva=WQ->FieldByName("GRID_VIEWABLE")->AsBoolean;
            AnsiString ga="";
            if(!WQ->FieldByName("GRID_ALIGN")->IsNull) ga=WQ->FieldByName("GRID_ALIGN")->AsString;
            AnsiString fd="";
            AnsiString refTN;
            if(!WQ->FieldByName("REFERENCE_TABLE_NAME")->IsNull) refTN=WQ->FieldByName("REFERENCE_TABLE_NAME")->AsString;
            AnsiString refFN;
            if(!WQ->FieldByName("REFERENCE_FIELD_NAME")->IsNull) refFN=WQ->FieldByName("REFERENCE_FIELD_NAME")->AsString;
            AnsiString retFN;
            if(!WQ->FieldByName("RETURN_FIELD_NAME")->IsNull) retFN=WQ->FieldByName("RETURN_FIELD_NAME")->AsString;
            AnsiString retD="";
            FieldsInfo[i]=new MFieldInfo(fieldName,fti,fty,fl,aa,ea,gva,ga,fd,refTN,refFN,retFN,retD);
          }
          else
          {
            FieldsInfo[i]=new MFieldInfo; //?????????? ?? ???????? ????
          }
        }
        catch (Exception &exc)
        { MessageDlg("?????? ????????? ?????? ??? FieldsInfo["+IntToStr(i)+"]\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
          FieldsInfo[i]=NULL;
        }
      }
    }
    catch (Exception &exc)
    { MessageDlg("?????? ????????? ?????? ??? FieldsInfo\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      FieldsInfo=NULL;
      return;
    }
  }
}
//
//---------------------------------------------------------------------------
//??????????
__fastcall MFieldsInformation::~MFieldsInformation(void)
{
  if(WQ!=NULL) delete WQ;
  if(Q!=NULL) delete Q;
  if(DS!=NULL) delete DS;
  if(WTransaction!=NULL) delete WTransaction;
  if(RTransaction!=NULL) delete RTransaction;
  if(FieldsInfo != NULL)
  { for(int i=0; i < fieldsCount; i++) if(FieldsInfo[i]!=NULL) delete FieldsInfo[i];
    delete [] FieldsInfo;
  }
}
//??????? ???????? ??????? ? ???????????? ?????? ? ??????? FIELDS_INFORMATION_TABLE
void __fastcall MFieldsInformation::prepareFI_Table()
{
AnsiString sql;

  //?????? ?????????? ? ????? ??????? ???????????
  Q->Close();
  Q->SQL->Clear();
  sql="select * from "+tableName+" where "+keyField+"=0";
  Q->SQL->Add(sql);
  try
  {
    Q->ExecQuery();
  }
  catch (Exception &exc)
  { MessageDlg("?????? - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
    return;
  }
  int fq=Q->FieldCount();
  //??????? ?? ??????? FIELDS_INFORMATION_TABLE ?????? ??? ??????? ??? ???????? ?? FIELD_NAME ? Q
  DS->Close();
  DS->SQLs->SelectSQL->Clear();
  sql="select FIELD_NAME from FIELDS_INFORMATION_TABLE where TABLE_NAME='"+tableName+"'";
  DS->SQLs->SelectSQL->Add(sql);
  try
  {
    DS->Open();
  }
  catch (Exception &exc)
  { MessageDlg("?????? - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
    return;
  }
  DS->First();
  while(!DS->Eof)
  { int i;
    AnsiString fieldName=DS->FieldByName("FIELD_NAME")->AsString;
    for(i=0; i<fq; i++)
    {
     if(fieldName == Q->FieldName(i)) break;
    }
    if(i==fq)
    { // ??????? ????
      WQ->Close();
      WQ->SQL->Clear();
      sql="delete from FIELDS_INFORMATION_TABLE where TABLE_NAME='"+tableName+"' and FIELD_NAME='"+fieldName+"'";
      WQ->SQL->Add(sql);
      try
      {
        WQ->ExecQuery();
      }
      catch (Exception &exc)
      { MessageDlg("?????? - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
        return;
      }
    }
    DS->Next();
  }
  //????????????? ?????? ? ??????? FIELDS_INFORMATION_TABLE
  if(DS->RecordCount > 0) PutInFITableOrder();
  //????????? ??? ??????????? ?????? ? ??????? FIELDS_INFORMATION_TABLE
  for(int i=0; i<Q->FieldCount(); i++)
  { AnsiString fieldName=Q->FieldName(i);
    DS->Close();
    DS->SQLs->SelectSQL->Clear();
    sql="select * from FIELDS_INFORMATION_TABLE where TABLE_NAME='"+tableName+"' and FIELD_NAME='"+fieldName+"'";
    DS->SQLs->SelectSQL->Add(sql);
    try
    {
      DS->Open();
    }
    catch (Exception &exc)
    { MessageDlg("?????? - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      return;
    }
    if(DS->RecordCount == 0)
    { // ????????? ????? ?????? ? ????
      int num=i+1;
      // ????????? ??? ??? ?????? ? ??????? num
      WQ->Close();
      WQ->SQL->Clear();
      sql="select FIELD_NAME from FIELDS_INFORMATION_TABLE where TABLE_NAME='"+tableName+"' and FIELD_NUM="+IntToStr(num);
      WQ->SQL->Add(sql);
      try
      {
        WQ->ExecQuery();
      }
      catch (Exception &exc)
      { MessageDlg("?????? - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
        return;
      }
      if(WQ->RecordCount > 0) // ???? ? ????? ??????? ????. ???????? ?????
      { AnsiString fname=WQ->FieldByName("FIELD_NAME")->AsString;
        int new_num=1000+i;
        WQ->Close();
        WQ->SQL->Clear();
        sql="update FIELDS_INFORMATION_TABLE set FIELD_NUM="+IntToStr(new_num);
        sql+=" where TABLE_NAME='"+tableName+"' and FIELD_NAME='"+fname+"'";
        WQ->SQL->Add(sql);
        try
        {
          WQ->ExecQuery();
        }
        catch (Exception &exc)
        { MessageDlg("?????? - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
          return;
        }
      }
      // ????????? ????? ????
      AnsiString fieldName=Q->FieldName(i);
      int fieldLength=Q->Fields[i]->Size;
      WQ->Close();
      WQ->SQL->Clear();
      sql="insert into FIELDS_INFORMATION_TABLE(TABLE_NAME,FIELD_NUM,FIELD_NAME,FIELD_TYPE,\
FIELD_LENGTH,ACCESSABLE,EDITABLE,GRID_VIEWABLE,GRID_ALIGN) values(";
      sql+="'"+tableName+"',";
      sql+=IntToStr(num)+",";
      sql+="'"+fieldName+"',";
      sql+="0,"+IntToStr(fieldLength)+",0,0,0,'center')";
      WQ->SQL->Add(sql);
      try
      {
        WQ->ExecQuery();
      }
      catch (Exception &exc)
      { MessageDlg("?????? - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
        return;
      }
    }
    else
    { // ??????????? ????????? ??????
      int fieldLength=Q->Fields[i]->Size;
      WQ->Close();
      WQ->SQL->Clear();
      sql="update FIELDS_INFORMATION_TABLE set FIELD_LENGTH="+IntToStr(fieldLength);
      sql+=" where TABLE_NAME='"+tableName+"' and FIELD_NAME='"+fieldName+"'";
      WQ->SQL->Add(sql);
      try
      {
        WQ->ExecQuery();
      }
      catch (Exception &exc)
      { MessageDlg("?????? - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
        return;
      }
    }
  }
  //????????????? ?????? ? ??????? FIELDS_INFORMATION_TABLE
  PutInFITableOrder();
}
//---------------------------------------------------------------------------
//??????? ?????????????? ??????? ? ??????? FIELDS_INFORMATION_TABLE ?? ????? TABLE_NAME ? FIELD_NUMBER
void __fastcall MFieldsInformation::PutInFITableOrder(void)
{
TpFIBQuery *q=NULL;
AnsiString sql;

  try
  {
    q=new TpFIBQuery(Owner);
    q->Database=db;
    q->Transaction=RTransaction;
  }
  catch (Exception &exc)
  { MessageDlg("?????? ???????? ??????? TpFIBQuery()\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
    if(q!=NULL) delete q;
    return;
  }
  //?????? ?????????? ? ????? ??????? ???????????
  q->Close();
  q->SQL->Clear();
  sql="select * from "+tableName+" where "+keyField+"=0";
  q->SQL->Add(sql);
  try
  {
    q->ExecQuery();
  }
  catch (Exception &exc)
  { MessageDlg("?????? - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
    delete q;
    return;
  }
  //????????????? ?????? ? ??????? FIELDS_INFORMATION_TABLE ??? ??????? tableName
  for(int i=0; i<Q->FieldCount(); i++)
  { AnsiString fieldName=q->FieldName(i);
    WQ->Close();
    WQ->SQL->Clear();
    sql="select FIELD_NUM from FIELDS_INFORMATION_TABLE where TABLE_NAME='"+tableName+"' and FIELD_NAME='"+fieldName+"'";
    WQ->SQL->Add(sql);
    try
    {
      WQ->ExecQuery();
    }
    catch (Exception &exc)
    { MessageDlg("?????? - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      delete q;
      return;
    }
    if(WQ->RecordCount > 0)
    { int fn=WQ->FieldByName("FIELD_NUM")->AsInteger;
      if(fn != i+1)
      { //???? ?????? ? ??????? i+1
        WQ->Close();
        WQ->SQL->Clear();
        sql="select FIELD_NAME from FIELDS_INFORMATION_TABLE where TABLE_NAME='"+tableName+"' and FIELD_NUM="+IntToStr(i+1);
        WQ->SQL->Add(sql);
        try
        {
          WQ->ExecQuery();
        }
        catch (Exception &exc)
        { MessageDlg("?????? - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
          delete q;
          return;
        }
        if(WQ->RecordCount > 0) //????? ?????? ????. ???????? ?? ?????
        { AnsiString fname=WQ->FieldByName("FIELD_NAME")->AsString;
          WQ->Close();
          WQ->SQL->Clear();
          sql="update FIELDS_INFORMATION_TABLE set FIELD_NUM="+IntToStr(2000+i);
          sql+=" where TABLE_NAME='"+tableName+"' and FIELD_NAME='"+fname+"'";
          WQ->SQL->Add(sql);
          try
          {
            WQ->ExecQuery();
          }
          catch (Exception &exc)
          { MessageDlg("?????? - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
            delete q;
            return;
          }
        }
        //?????? ????? ? ?????? ? fieldName
        WQ->Close();
        WQ->SQL->Clear();
        sql="update FIELDS_INFORMATION_TABLE set FIELD_NUM="+IntToStr(i+1);
        sql+=" where TABLE_NAME='"+tableName+"' and FIELD_NAME='"+fieldName+"'";
        WQ->SQL->Add(sql);
        try
        {
          WQ->ExecQuery();
        }
        catch (Exception &exc)
        { MessageDlg("?????? - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
          delete q;
          return;
        }
      }
    }
  }
  delete q;
}
//***************************************************************************
//???????? ?????? ? FieldsInfo
void __fastcall MFieldsInformation::setFIData(TpFIBDataSet *DS)
{
  for(int i=0; i<fieldsCount; i++)
  { if(FieldsInfo[i]->getFieldType()==9) //?????
    { AnsiString fData=DS->FieldByName(FieldsInfo[i]->getFieldName())->AsString;
      if(!fData.IsEmpty())
      { AnsiString refTableName=FieldsInfo[i]->getRefTableName();
        AnsiString refFieldName=FieldsInfo[i]->getRefFieldName();
        AnsiString retFieldName=FieldsInfo[i]->getRetFieldName();
        AnsiString retData="";
        AnsiString sql;
        sql="select "+retFieldName+" from "+refTableName+" where "+refFieldName+" = "+fData;
        TpFIBQuery *q=new TpFIBQuery(GSM_DM);
        TpFIBTransaction *t=new TpFIBTransaction(GSM_DM);
        q->Database=GSM_DM->Database;
        t->DefaultDatabase=GSM_DM->Database;
        q->Transaction=t;
        t->StartTransaction();
        q->SQL->Clear();
        q->SQL->Add(sql);
        try
        {
          q->ExecQuery();
        }
        catch (Exception &exc)
        { MessageDlg("?????? - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
          t->Rollback();
          delete t;
          delete q;
          return;
        }
        t->Commit();
        if(q->RecordCount > 0) retData=q->FieldByName(retFieldName)->AsString;
        else retData="";
        delete t;
        delete q;
        FieldsInfo[i]->setFieldData(fData);
        FieldsInfo[i]->setRetFieldData(retData);
      }
      else
      { FieldsInfo[i]->setFieldData("");
        FieldsInfo[i]->setRetFieldData("");
      }
    }
    else FieldsInfo[i]->setFieldData(DS->FieldByName(FieldsInfo[i]->getFieldName())->AsString);
  }
}
//---------------------------------------------------------------------------
//?????????? ????????? ?????
int __fastcall MFieldsInformation::getAccessableFildsCount(void)
{
int count=0;

  for(int i=0; i<fieldsCount; ++i) if(FieldsInfo[i]->isAccessable()) count++;
  return count;
}
//---------------------------------------------------------------------------
//?????????? ?????, ??????????? ??????????????
int __fastcall MFieldsInformation::getEditableFildsCount(void)
{
int count=0;

  for(int i=0; i<fieldsCount; ++i) if(FieldsInfo[i]->isEditable()) count++;
  return count;
}
//---------------------------------------------------------------------------
int __fastcall MFieldsInformation::getPisitionField(AnsiString fieldName)
{
int i;

  for(i=0; i < fieldsCount; i++)
  {
    if(getFieldInfo(i)->getFieldName()==fieldName) break;
  }
  if(i < fieldsCount) return i;
  else return -1;
}
//---------------------------------------------------------------------------
//***************************************************************************
//************************************
//* ????? - ????????????? ?????????? *
//************************************
//??????????? ?????? - ????????????? ?????????? UniversalReferenseBook
__fastcall TURB::TURB(TComponent* owner, AnsiString tn,int flag)
        : TForm(owner),Owner(owner)
{
  flagv=flag;
  rbTitle="";
  rbTableName=tn;
  orderStr=" order by t.DESCRIPTION";
  firstStartFLG=true;
  SEdit->Text="";
  raCheck=&removeableCheck;

  //?????? ?????????? ? ??????????? ?? ??????? RB_INFORM_TABLE
  AnsiString sql;
  Q->Close();
  Q->SQL->Clear();
  sql="select * from RB_INFORM_TABLE where RB_TABLE_NAME='"+rbTableName+"'";
  Q->SQL->Add(sql);
  try
  {
    Q->ExecQuery();
  }
  catch (Exception &exc)
  { MessageDlg("?????? - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
    return;
  }
  if(Q->RecordCount > 0)
  { rbTitle=Q->FieldByName("RB_TITLE")->AsString;
    keyFieldName=Q->FieldByName("KEY_FIELD_NAME")->AsString;
    treeViewable=Q->FieldByName("TREE_VIEWABLE")->AsBoolean;
    contentViewable=Q->FieldByName("CONTENT_VIEWABLE")->AsBoolean;
    searchPanelViewable=Q->FieldByName("SEARCH_PANEL_VIEWABLE")->AsBoolean;
    directGridEdit=Q->FieldByName("DIRECT_GRID_EDIT")->AsBoolean;
    searchingWithRegister=Q->FieldByName("SEARCHING_WITH_REGISTER")->AsBoolean;
    treeLevel=Q->FieldByName("TREE_LEVEL")->AsInteger;
  }
  else
  { keyFieldName="ID";
    treeViewable=true;
    contentViewable=true;
    searchPanelViewable=true;
    directGridEdit=false;
    searchingWithRegister=true;
    rbTitle=rbTableName;
    treeLevel=0;
    Q->Close();
    Q->SQL->Clear();
    sql="insert into RB_INFORM_TABLE(RB_TABLE_NAME,RB_TITLE,KEY_FIELD_NAME,\
TREE_VIEWABLE,CONTENT_VIEWABLE,SEARCH_PANEL_VIEWABLE,DIRECT_GRID_EDIT,SEARCHING_WITH_REGISTER,TREE_LEVEL) values(";
    sql+="'"+rbTableName+"','"+rbTitle+"','"+keyFieldName+"',1,1,1,0,1,0)";
    Q->SQL->Add(sql);
    try
    {
      Q->ExecQuery();
    }
    catch (Exception &exc)
    { MessageDlg("?????? - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      return;
    }
  }
  LeftPanel->Visible=treeViewable;
//  OnFoldersCheckBox->Visible=LeftPanel->Visible;
  OnFoldersCheckBox->Visible=false;
  ContentMemo->Visible=contentViewable;
  SPanel->Visible=searchPanelViewable;
  if(LeftPanel->Visible==false && SPanel->Visible==false) RButtonsPanel->Visible=false;
  else RButtonsPanel->Visible=true;
  Caption=rbTitle;
  if(directGridEdit==true)
  { DS->AutoCommit=true;
    DS->AutoUpdateOptions->UpdateTableName=rbTableName;
    DS->AutoUpdateOptions->KeyFields=keyFieldName;
    DS->AutoUpdateOptions->UpdateOnlyModifiedFields;
    GridButtonsPanel->Visible=true;
  }
  else
  {
    DS->AutoCommit=false;
    GridButtonsPanel->Visible=false;
  }

  //?????????? ?????????? ? ????? ???????
  FI=new MFieldsInformation(this,rbTableName,keyFieldName);

  workDir=ExtractFilePath(Application->ExeName);
  FormStorage->IniFileName=workDir+"AccountGSM.ini";
  FormStorage->IniSection=rbTitle;

  //????????? Grid
  Grid->Columns->Clear();
  int n=1;
  for(int i=0, j=0; i<FI->getFieldsCount(); i++)
  {  if(FI->getFieldInfo(i)->isAccessable() && FI->getFieldInfo(i)->isGridViewable()==true)
     { TColumnEh *col=Grid->Columns->Add();
       if(FI->getFieldInfo(i)->getFieldType()==9)
       { AnsiString s="F"+IntToStr(n);
         col->FieldName=s;
         if(directGridEdit==true)
         { col->ButtonStyle=Dbgrids::cbsEllipsis;
           col->OnEditButtonClick=ColumnOnClickButton;
         }
         n++;
       }
       else col->FieldName=FI->getFieldInfo(i)->getFieldName();
       col->Title->Caption=FI->getFieldInfo(i)->getFieldTitle();
       col->Title->Alignment=taCenter;
       col->AutoFitColWidth=true;
       col->ReadOnly=true;
       if(FI->getFieldInfo(i)->getGridAlign()=="left") col->Alignment=taLeftJustify;
       else if(FI->getFieldInfo(i)->getGridAlign()=="center") col->Alignment=taCenter;
       else  col->Alignment=taRightJustify;
       if(j==1) col->AutoFitColWidth=true;
       else col->AutoFitColWidth=false;
       if(directGridEdit==true && FI->getFieldInfo(i)->isAccessable() && FI->getFieldInfo(i)->isEditable() && FI->getFieldInfo(i)->isGridViewable())
         col->ReadOnly=false;
       else col->ReadOnly=true;
       j++;
     }
  }
  getProperties();
  //??????????? DS
  if(directGridEdit==true)
  { //Insert ??????
    AnsiString sql;
    sql="insert into "+rbTableName+"(";
    for(int i=0; i<FI->getFieldsCount(); i++)
    { if(i>0) sql+=",";
      sql+=FI->getFieldInfo(i)->getFieldName();
    }
    sql+=") values(";
    for(int i=0; i<FI->getFieldsCount(); i++)
    { if(i>0) sql+=",";
      sql+=":"+FI->getFieldInfo(i)->getFieldName();
    }
    sql+=")";
    DS->SQLs->InsertSQL->Add(sql);
    //Update ??????
    sql="update "+rbTableName+" set ";
    for(int i=0; i<FI->getFieldsCount(); i++)
    { if(i>1) sql+=", ";
      if(FI->getFieldInfo(i)->getFieldName()!=keyFieldName)
        sql+=FI->getFieldInfo(i)->getFieldName()+" = :"+FI->getFieldInfo(i)->getFieldName();
    }
    sql+=" where "+keyFieldName+" = :OLD_"+keyFieldName;
    DS->SQLs->UpdateSQL->Add(sql);
    //Delete ??????
    sql="delete from "+rbTableName;
    sql+=" where "+keyFieldName+" = :OLD_"+keyFieldName;
    DS->SQLs->DeleteSQL->Add(sql);
    //Refresh ???????
    sql="select t.*";
    int n=1;
    for(int i=0; i<FI->getFieldsCount(); i++)
    { if(FI->getFieldInfo(i)->isAccessable() && FI->getFieldInfo(i)->isGridViewable() && FI->getFieldInfo(i)->getFieldType()==9)
      { AnsiString s="r"+IntToStr(n);
        AnsiString f="f"+IntToStr(n);
        sql+=", "+s+"."+FI->getFieldInfo(i)->getRetFieldName()+" as "+f;
        n++;
      }
    }
    sql+=" from "+rbTableName+" t";
    n=1;
    for(int i=0; i<FI->getFieldsCount(); i++)
    { if(FI->getFieldInfo(i)->isAccessable() && FI->getFieldInfo(i)->isGridViewable() && FI->getFieldInfo(i)->getFieldType()==9)
      { AnsiString s="r"+IntToStr(n);
        sql+=" left outer join "+FI->getFieldInfo(i)->getRefTableName()+" "+s+" on "+s+"."+FI->getFieldInfo(i)->getRefFieldName()+"=t."+FI->getFieldInfo(i)->getFieldName();
        n++;
      }
    }
    sql+=" where t."+keyFieldName+" = :OLD_"+keyFieldName;
    DS->SQLs->RefreshSQL->Add(sql);
  }

  //?????????????? ?????????? ? ?????? ??????
  // ????????? ??????? ????????? ???????
  Q->Close();
  Q->SQL->Clear();
  sql="select "+keyFieldName+" as RID, DESCRIPTION from "+rbTableName+" where FILE_ID is NULL and REC_TYPE=0";
  Q->SQL->Add(sql);
  try
  {
    Q->ExecQuery();
  }
  catch (Exception &exc)
  { MessageDlg("?????? - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
    return;
  }
  if(Q->RecordCount == 0)
  { RootSectionID=getNewRB_KeyValue();
    if(RootSectionID.IsEmpty()) return;
    Q->Close();
    Q->SQL->Clear();
    sql="insert into "+rbTableName+"("+keyFieldName+",FILE_ID,REC_TYPE,DESCRIPTION) values(";
    sql+=RootSectionID+",";
    sql+="NULL,0,'"+rbTitle+"')";
    Q->SQL->Add(sql);
    try
    {
      Q->ExecQuery();
    }
    catch (Exception &exc)
    { MessageDlg("?????? - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      return;
    }
  }
  else
  { AnsiString d=Q->FieldByName("DESCRIPTION")->AsString;
    RootSectionID=Q->FieldByName("RID")->AsString;
    if(d!=rbTitle)
    { Q->Close();
      Q->SQL->Clear();
      sql="update "+rbTableName+" set DESCRIPTION='"+rbTitle+"'";
      sql+=" where ID="+RootSectionID;
      Q->SQL->Add(sql);
      try
      {
        Q->ExecQuery();
      }
      catch (Exception &exc)
      { MessageDlg("?????? - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
        return;
      }
    }
  }
  // ????????? ??????? ??????? ??? ????????? ???????
  Q->Close();
  Q->SQL->Clear();
  sql="select "+keyFieldName+" as DID from "+rbTableName+" where DESCRIPTION like '_????????? ??????'";
  Q->SQL->Add(sql);
  try
  {
    Q->ExecQuery();
  }
  catch (Exception &exc)
  { MessageDlg("?????? - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
    return;
  }
  if(Q->RecordCount == 0)
  { DelRecordsSectionID=getNewRB_KeyValue();
    if(DelRecordsSectionID.IsEmpty()) return;
    Q->Close();
    Q->SQL->Clear();
    sql="insert into "+rbTableName+"("+keyFieldName+",FILE_ID,REC_TYPE,DESCRIPTION) values(";
    sql+=DelRecordsSectionID+",";
    sql+=RootSectionID+",0,'_????????? ??????')";
    Q->SQL->Add(sql);
    try
    {
      Q->ExecQuery();
    }
    catch (Exception &exc)
    { MessageDlg("?????? - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      return;
    }
  }
  else DelRecordsSectionID=Q->FieldByName("DID")->AsString;

  if(treeViewable==true)
  {
    createRBTree(flag);
    TreeView->FullExpand();
    TreeView->Selected=TreeView->Items->Item[0];
    N4->Visible=true;
    MoveButton->Enabled = true;
  }
  else
  { selectedSectionID=RootSectionID;
    N4->Visible=false;
    MoveButton->Enabled = false;
  }
}
//---------------------------------------------------------------------------
//???????? DS
void __fastcall TURB::loadDS()
{
AnsiString sql;

  Grid->Visible=false;
  if(DS->Active==true) DS->Close();
  DS->SQLs->SelectSQL->Clear();
  sql="select t.*";
  int n=1;
  for(int i=0; i<FI->getFieldsCount(); i++)
  { if(FI->getFieldInfo(i)->isAccessable() && FI->getFieldInfo(i)->isGridViewable() && FI->getFieldInfo(i)->getFieldType()==9)
    { AnsiString s="r"+IntToStr(n);
      AnsiString f="F"+IntToStr(n);
      sql+=", "+s+"."+FI->getFieldInfo(i)->getRetFieldName()+" as "+f;
      n++;
    }
  }
  sql+=" from "+rbTableName+" t";
  n=1;
  for(int i=0; i<FI->getFieldsCount(); i++)
  { if(FI->getFieldInfo(i)->isAccessable() && FI->getFieldInfo(i)->isGridViewable() && FI->getFieldInfo(i)->getFieldType()==9)
    { AnsiString s="r"+IntToStr(n);
      sql+=" left outer join "+FI->getFieldInfo(i)->getRefTableName()+" "+s+" on "+s+"."+FI->getFieldInfo(i)->getRefFieldName()+"=t."+FI->getFieldInfo(i)->getFieldName();
      n++;
    }
  }
  sql+=" where t.REC_TYPE=1";
  if(treeViewable==true && OnFoldersCheckBox->Checked) sql+=" and t.FILE_ID="+selectedSectionID;
  else sql+=" and t.FILE_ID<>"+DelRecordsSectionID;
  if (GSM_DM->UserRole!="?????????????" && GSM_DM->UserRole!="????????????"){
    if (rbTableName=="OPER_TABLE") {
    if (GSM_DM->VerForm==0)
    {
     if (selectedSectionID==33)
     {
      if(MainForm->ActivTable == 1){
      sql+=" and t.ID IN (3,6,17)";
      }
     }

     if (selectedSectionID==34)
     {
      if(MainForm->ActivTable == 2) sql+=" and t.ID IN (35,36,37)";
      if(MainForm->ActivTable == 4) sql+=" and t.ID IN (35,36,37,39)";
     }
    }
    else
    {
      if(MainForm->ActivTable == 1) sql+=" and t.ID IN (3,6,17,35,36,37)"; else sql+=" and t.ID IN (35,36,37,39)";
    }
    if(MainForm->ActivTable == 4){
     if (AnsiPos(GSM_DM->Index,MainForm->selectedOPS.Trim())>0) sql+=" and t.ID IN (35,36,39,92,93,99)"; else sql+=" and t.ID IN (37)";
    }
  }
    if (rbTableName=="OPS_TABLE") sql+=" and t.DESCRIPTION IN (" + MainForm->IndexOps +")";
    if (rbTableName=="KASSA_TABLE") sql+=" and t.DESCRIPTION IN (" + MainForm->IndexOps +")";
  }else
  {
    if(MainForm->ActivTable == 1){
    if (rbTableName=="OPER_TABLE") sql+=" and t.ID IN (92,93,99)";
    }
    if(MainForm->ActivTable == 4){
    if (rbTableName=="OPER_TABLE") sql+=" and t.ID IN (35,36,39,92,93,96,97,98,99,103)";
    }
    if(MainForm->ActivTable == 5 ){
    if (rbTableName=="OPER_TABLE") sql+=" and t.ID NOT IN (83,84,89,85,70,101,104)";
    }
  }
  sql+=orderStr;
  DS->SQLs->SelectSQL->Add(sql);
  try
  {
    DS->Open();
  }
  catch(const Exception &exc)
  {
    MessageDlg("?????? - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
    return;
  }
  DS->Last();
  Grid->Visible=true;
  DS->First();
  if (flagv==0)
  {
  LeftPanel->Visible=true;
  LButtonsPanel->Visible  = true;
  RButtonsPanel->Visible= true;
  LButtonsPanel->Enabled = true;
  RButtonsPanel->Enabled = true;
  if(DS->RecordCount==0 && selectedSectionID!=RootSectionID && selectedSectionID!=DelRecordsSectionID) DelSectionButton->Enabled=false;
  else DelSectionButton->Enabled=true;
  if(selectedLevel<treeLevel) AddSectionButton->Enabled=true;
  else AddSectionButton->Enabled=false;
  if (treeLevel==0)
  {
  if(selectedSectionID==DelRecordsSectionID) RightPanel->Visible=false;
  else RightPanel->Visible=true;
  }
  if (treeLevel==1)
  {
  if(selectedSectionID==RootSectionID || selectedSectionID==DelRecordsSectionID) RightPanel->Visible=false;
  else RightPanel->Visible=true;
  }
  }else
  {
  LButtonsPanel->Visible  = false;
  RButtonsPanel->Visible= false;
  LButtonsPanel->Enabled = false;
  RButtonsPanel->Enabled = false;
  AddSectionButton->Enabled=false;
  DelSectionButton->Enabled=false;
  LeftPanel->Visible=true;
  }
}
//---------------------------------------------------------------------------
void __fastcall TURB::FormShow(TObject *Sender)
{
/*  if(firstStartFLG==true)
  { loadDS();
    firstStartFLG=false;
  }

  if (GSM_DM->UserRole!="?????????????" && GSM_DM->UserRole!="????????????")
  {
  RButtonsPanel->Visible=false;
  ContentMemo->Visible=false;
  LeftPanel->Visible=false;
  Grid->ReadOnly=true;
//  Grid->Enabled=false;
  Grid->SetFocus();
  }else
  {
  RButtonsPanel->Visible=false;
  if (MainForm->ActivTable==5) LeftPanel->Visible=true; else LeftPanel->Visible=false;
  ContentMemo->Visible=true;
  Grid->ReadOnly=true;
//  Grid->Enabled=true;
//  Grid->SetFocus();
  GridMenuPopup(this);
  }
*/

  if(firstStartFLG==true)
  { loadDS();
    firstStartFLG=false;
  }

  if (GSM_DM->UserRole!="?????????????" && GSM_DM->UserRole!="????????????")
  {
  RButtonsPanel->Visible=false;
  ContentMemo->Visible=false;
  if (rbTableName=="OPER_TABLE")
  {
   if (GSM_DM->VerForm==0) LeftPanel->Visible=false; else LeftPanel->Visible=true;
  }
  Grid->ReadOnly=true;
  Grid->SetFocus();
  }else
  {
  if (rbTableName=="OPER_TABLE")
  {
   if (MainForm->ActivTable==1) LeftPanel->Visible=false; else LeftPanel->Visible=true;
//   if (GSM_DM->VerForm==0) LeftPanel->Visible=false; else LeftPanel->Visible=true;
  }
//  LeftPanel->Visible=true;
//  LeftPanel->Visible=true;
  ContentMemo->Visible=true;
  Grid->ReadOnly=false;
//  Grid->Enabled=true;
  GridMenuPopup(this);
  }
}
//---------------------------------------------------------------------------
//
void __fastcall TURB::FormDestroy(TObject *Sender)
{
//    if(MainForm->PC->ActivePageIndex == 0 || MainForm->PC->ActivePageIndex == 1 )
//    {
//     MainForm->initMainForm();
     setProperties();
     deleteRBTree();
     delete FI;
//    }
//    else
//    {
//     setProperties();
//     deleteRBTree();
//     delete FI;
//    }
}
//---------------------------------------------------------------------------
//????????? ?????? ???????? ????????? ????
AnsiString __fastcall TURB::getNewRB_KeyValue(void)
{
AnsiString sql;

  Q->Close();
  Q->SQL->Clear();
  sql="select GEN_ID(GEN_"+rbTableName+"_ID,1) as ID from RDB$DATABASE";
  Q->SQL->Add(sql);
  try
  {
    Q->ExecQuery();
  }
  catch (Exception &exc)
  { MessageDlg("?????? - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
    return "";
  }
  return Q->FieldByName("ID")->AsString;
}
//---------------------------------------------------------------------------
//???? ??? ????? ?? ?? ????????????
AnsiString __fastcall TURB::getFolderIDByName(AnsiString folderName)
{
AnsiString sql;

  Q->Close();
  Q->SQL->Clear();
  sql="select ID from "+rbTableName+" where DESCRIPTION like '"+folderName+"'";
  sql+=" and REC_TYPE=0";
  Q->SQL->Add(sql);
  try
  {
    Q->ExecQuery();
  }
  catch (Exception &exc)
  { MessageDlg("?????? - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
    return "";
  }
  return Q->FieldByName("ID")->AsString;
}
//---------------------------------------------------------------------------
//???????? ????? ?? ????????????
AnsiString __fastcall TURB::createFolderByName(AnsiString parentID,AnsiString folderName)
{
AnsiString folderID="";
AnsiString sql;

  //????????? ??? ?? ??? ????? ? ????? ?????????????
  folderID=getFolderIDByName(folderName);
  if(folderID.IsEmpty())
  { //??????? ?????
    AnsiString id=getNewRB_KeyValue();
    Q->Close();
    Q->SQL->Clear();
    sql="insert into "+rbTableName+"(ID,FILE_ID,REC_TYPE,DESCRIPTION) values(";
    sql+=id+",";
    sql+=parentID+",0,";
    sql+="'"+folderName+"')";
    Q->SQL->Add(sql);
    try
    {
      Q->ExecQuery();
    }
    catch (Exception &exc)
    { MessageDlg("?????? - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      return folderID;
    }
    folderID=id;
  }
  return folderID;
}
//---------------------------------------------------------------------------
//?????????????? ???????? ???? ???????????
void __fastcall TURB::getProperties(void)
{
TIniFile* ini;

  if(!rbTitle.IsEmpty())
  { ini=new TIniFile(workDir+"AccountGSM.ini");
    //??????? ???????
    LeftPanel->Width=ini->ReadInteger(rbTitle,"TreeView_Width",150);
    ContentMemo->Height=ini->ReadInteger(rbTitle,"ContentMemo_Height",150);
    //??????????????? ??????? ??????? Grid-a
    for(int i=0, j=0; i<FI->getFieldsCount(); i++)
    { if(FI->getFieldInfo(i)->isAccessable() && FI->getFieldInfo(i)->isGridViewable())
      { if(Grid->Columns->Items[j]->AutoFitColWidth==false)
        { AnsiString cn="Col"+IntToStr(j);
          Grid->Columns->Items[j]->Width=ini->ReadInteger(rbTitle,cn,64);
        }
        ++j;
      }
    }
    delete ini;
  }
}
//---------------------------------------------------------------------------
//?????????? ???????? ???? ???????????
void __fastcall TURB::setProperties(void)
{
TIniFile* ini;

  if(!rbTitle.IsEmpty())
  { ini=new TIniFile(workDir+"AccountGSM.ini");
    //??????? ???????
    ini->WriteInteger(rbTitle,"TreeView_Width",LeftPanel->Width);
    ini->WriteInteger(rbTitle,"ContentMemo_Height",ContentMemo->Height);
    //????????? ??????? ??????? Grid-?
    for(int i=0, j=0; i<FI->getFieldsCount(); i++)
    { if(FI->getFieldInfo(i)->isAccessable() && FI->getFieldInfo(i)->isGridViewable())
      { AnsiString cn="Col"+IntToStr(j);
        ini->WriteInteger(rbTitle,cn,Grid->Columns->Items[j]->Width);
        ++j;
      }
    }
    delete ini;
  }
}
//---------------------------------------------------------------------------
//???????? ?????? ???????????
void __fastcall TURB::createRBTree(int flag)
{
  //??????? ??????? ??????
  deleteRBTree();
  //?????? ????? ??????
  createNode(NULL,"",flag);
}
//---------------------------------------------------------------------------
//???????? ?????? ???????????
void __fastcall TURB::deleteRBTree(void)
{
RBTreeData *rbTD;

  for(int i=0; i<TreeView->Items->Count; i++)
  { rbTD=(static_cast<RBTreeData*>(TreeView->Items->Item[i]->Data));
    delete rbTD;
    TreeView->Items->Item[i]->Data=NULL;
  }
  TreeView->Items->Clear();
}
//---------------------------------------------------------------------------
//???????? ???? ???????? ???????????
void __fastcall TURB::createNode(TTreeNode *parentNode, AnsiString sectionID,int flag)
{
TpFIBDataSet *DS;
AnsiString sql;

  DS=NULL;
  try
  {
    DS=new TpFIBDataSet(this);
  }
  catch(const Exception &exc)
  {
    MessageDlg("?????? ??????? DataSet\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
    return;
  }
  DS->Database=GSM_DM->Database;
  DS->Transaction=GSM_DM->readTransaction;
  DS->SQLs->SelectSQL->Clear();
  if(sectionID.IsEmpty())
  {
    sql="select "+keyFieldName+" as ID, DESCRIPTION from "+rbTableName+" where FILE_ID is null and REC_TYPE <> 1 and VISIBLE = 1";
  }
  else
  {
//  if (GSM_DM->UserRole!="?????????????" && GSM_DM->UserRole!="????????????"){
  if (flag == 0) sql="select "+keyFieldName+" as ID, DESCRIPTION from "+rbTableName+" where FILE_ID="+sectionID+" and REC_TYPE <> 1 and VISIBLE = 1";
  if (flag == 1){
  if (GSM_DM->UserRole!="?????????????" && GSM_DM->UserRole!="????????????")
  {
   if(MainForm->PC->ActivePageIndex == 0 || MainForm->PC->ActivePageIndex == 1) sql="select "+keyFieldName+" as ID, DESCRIPTION from "+rbTableName+" where FILE_ID="+sectionID+" and REC_TYPE <> 1 and VISIBLE = 1 and ENABLE in (1,2) ";
  }else
  {
   if(MainForm->PC->ActivePageIndex == 0) sql="select "+keyFieldName+" as ID, DESCRIPTION from "+rbTableName+" where FILE_ID="+sectionID+" and REC_TYPE <> 1 and VISIBLE = 1 and ENABLE in (1) ";
   if(MainForm->PC->ActivePageIndex == 1) sql="select "+keyFieldName+" as ID, DESCRIPTION from "+rbTableName+" where FILE_ID="+sectionID+" and REC_TYPE <> 1 and VISIBLE = 1 and ENABLE in (1,2) ";
  }
  }
  if (flag == 2) sql="select "+keyFieldName+" as ID, DESCRIPTION from "+rbTableName+" where FILE_ID="+sectionID+" and REC_TYPE <> 1 and VISIBLE = 1 and ENABLE in (3) ";
//  if (flag == 4) sql="select "+keyFieldName+" as ID, DESCRIPTION from "+rbTableName+" where FILE_ID in (33,34)" + " and REC_TYPE <> 1 and VISIBLE = 1";
//  if (flag <= 3) sql="select "+keyFieldName+" as ID, DESCRIPTION from "+rbTableName+" where FILE_ID="+sectionID+" and REC_TYPE <> 1 and VISIBLE = 1 and ENABLE = " + IntToStr(flag);
//  }else
//  {
//  sql="select "+keyFieldName+" as ID, DESCRIPTION from "+rbTableName+" where FILE_ID="+sectionID+" and REC_TYPE <> 1 and VISIBLE = 1";
//  }
  }
  sql+=" order by DESCRIPTION DESC";
  DS->SQLs->SelectSQL->Add(sql);
  try
  {
    DS->Open();
  }
  catch(const Exception &exc)
  {
    MessageDlg("?????? - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
    if(DS!=NULL) delete DS;
    return;
  }

  DS->First();
  while(!DS->Eof)
  { TTreeNode *node;
    if(sectionID.IsEmpty()) node=TreeView->Items->Add(NULL,DS->FieldByName("DESCRIPTION")->AsString);
    else node=TreeView->Items->AddChild(parentNode,DS->FieldByName("DESCRIPTION")->AsString);
    node->ImageIndex=0;
    node->SelectedIndex=1;
    RBTreeData *rbTD=new RBTreeData();
    rbTD->data=DS->FieldByName("ID")->AsString;
    node->Data=rbTD;
    createNode(node,rbTD->data,flag);
    DS->Next();
  }
  if(DS!=NULL) delete DS;
}
//---------------------------------------------------------------------------
void __fastcall TURB::TreeViewChange(TObject *Sender, TTreeNode *Node)
{
  selectedSectionID=(static_cast<RBTreeData*>(TreeView->Selected->Data))->data;
  selectedLevel=TreeView->Selected->Level;
  if (selectedSectionID!=1) parentSectionID=TreeView->Selected->Parent->Text;
  GridMenuPopup(this);
  loadDS();
}
//---------------------------------------------------------------------------
//
void __fastcall TURB::setContentMemo()
{
  ContentMemo->Clear();
  FI->setFIData(DS);
  if(contentViewable==false) return;
  int size=ContentMemo->DefAttributes->Size;
  for(int i=0; i<FI->getFieldsCount(); i++)
  { if(FI->getFieldInfo(i)->isAccessable()==true)
    { AnsiString fTitle=FI->getFieldInfo(i)->getFieldTitle();
      AnsiString fData=FI->getFieldInfo(i)->getFieldData();
      AnsiString rData=FI->getFieldInfo(i)->getRetFieldData();
      int fType=FI->getFieldInfo(i)->getFieldType();
      AnsiString s=fTitle+" - ";
      int ss=ContentMemo->Text.Length();
      int l=s.Length(), l1;
      if(fType==9)
      { s+=rData;
        l1=rData.Length();
      }
      else
      { s+=fData;
        l1=fData.Length();
      }
      ContentMemo->Lines->Add(s);
      ContentMemo->SelStart=ss;
      ContentMemo->SelLength=l;
      ContentMemo->SelAttributes->Size=size;
      ContentMemo->SelAttributes->Color=clBlack;
      ContentMemo->SelAttributes->Style >> fsBold;
      ContentMemo->SelStart=ss+l;
      ContentMemo->SelLength=l1;
      ContentMemo->SelAttributes->Size=10;
      ContentMemo->SelAttributes->Color=clBlue;
      ContentMemo->SelAttributes->Style << fsBold;
    }
  }
  ContentMemo->DefAttributes->Size=size;
}
//---------------------------------------------------------------------------
void __fastcall TURB::SDataChange(TObject *Sender, TField *Field)
{
  if(Grid->Visible==true && DS->RecordCount>0)
  { setContentMemo();
    if(OnFoldersCheckBox->Checked==false) FindPositionInTreeView(DS->FieldByName("FILE_ID")->AsString);
  }
}
//---------------------------------------------------------------------------
//
void __fastcall TURB::STimerTimer(TObject *Sender)
{
AnsiString sql;

  STimer->Enabled=false;
  if(SEdit->Text.IsEmpty()) return;
  S_DS->Close();
  S_DS->SQLs->SelectSQL->Clear();
  sql="select t."+keyFieldName+" from "+rbTableName+" t where t.FILE_ID="+selectedSectionID;
  sql+=" and t.REC_TYPE=1";
  if(searchingWithRegister==true) sql+=" and t.DESCRIPTION like '%"+SEdit->Text+"%'";
  else sql+=" and UPPER(t.DESCRIPTION) like '%"+SEdit->Text.UpperCase()+"%'";
  sql+=orderStr;
  S_DS->SQLs->SelectSQL->Add(sql);
  try
  {
    S_DS->Open();
  }
  catch(const Exception &exc)
  {
    MessageDlg("?????? - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
    return;
  }
  S_DS->Last();
  S_DS->First();
  if(S_DS->RecordCount > 0)
  { TLocateOptions Opt; Opt.Clear();
    DS->Locate(keyFieldName,Variant(S_DS->FieldByName(keyFieldName)->AsString),Opt);
  }
}
//---------------------------------------------------------------------------
//
void __fastcall TURB::SEditChange(TObject *Sender)
{
  if(STimer->Enabled==true) STimer->Enabled=false;
  STimer->Enabled=true;
}
//---------------------------------------------------------------------------
//
void __fastcall TURB::SEditKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
  if(Key==VK_RETURN || Key==VK_DOWN || Key==VK_UP){ Key=0; Grid->SetFocus(); }
  else if(Key == VK_ESCAPE){ Key=0; SEdit->Text=""; }
}
//---------------------------------------------------------------------------
//
void __fastcall TURB::GridKeyPress(TObject *Sender, char &Key)
{
  if(searchPanelViewable==false) return;
  if(DS->State==dsEdit || DS->State==dsInsert) return; 

  int c=Key&127;
  if(isalnum(c) || c==64)
  { SEdit->Clear();
    AnsiString s=SEdit->Text+Key;
    Key=0;
    SEdit->Text=s;
    SEdit->SetFocus(); SEdit->SelStart=SEdit->GetTextLen();
  }
}
//---------------------------------------------------------------------------
//
void __fastcall TURB::GridKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
  if(directGridEdit==true)
  { if(DS->State==dsEdit || DS->State==dsInsert)
    { if(Key == VK_INSERT){ Key=0; return; }
      else if(Key==VK_DELETE && (TShiftState() << ssCtrl)==Shift){ Key=0; return;}
      else if(Key == VK_ESCAPE) DS->Cancel();
      if(Key == VK_RETURN)  DS->Post();
      else if(Key == VK_F11)
      { TRect r=Grid->CellRect(Grid->Col,Grid->Row);
        int x=this->Left+RightPanel->Left+r.Left+r.Width();
        int y=this->Top+Grid->Top+r.Top+r.Height()+15;
        GridMenu->Popup(x,y);
      }
    }
    else
    { if(Key == VK_ESCAPE)
      { Close();
        ModalResult=mrCancel;
        return;
      }
      if(selectedSectionID == DelRecordsSectionID) return;
      if(Key == VK_RETURN)
      { if(Grid->SelectedRows->Count==0) Grid->Selection->Rows->CurrentRowSelected=true;
        Close();
        ModalResult=mrOk;
      }
      else if(Key == VK_F11)
      { TRect r=Grid->CellRect(Grid->Col,Grid->Row);
        int x=this->Left+RightPanel->Left+r.Left+r.Width();
        int y=this->Top+Grid->Top+r.Top+r.Height()+15;
        Mouse->CursorPos=TPoint(x+50,y+10);
        GridMenu->Popup(x,y);
        Mouse->CursorPos=TPoint(x,y);
      }
    }
  }
  else
  {
    if(Key == VK_ESCAPE)
    { Close();
      ModalResult=mrCancel;
      return;
    }
    if(selectedSectionID == DelRecordsSectionID) return;
    if(Key == VK_RETURN)
    { if(Grid->SelectedRows->Count==0) Grid->Selection->Rows->CurrentRowSelected=true;
      Close();
      ModalResult=mrOk;
    }
    else if(Key == VK_F11)
    { TRect r=Grid->CellRect(Grid->Col,Grid->Row);
      int x=this->Left+RightPanel->Left+r.Left+r.Width();
      int y=this->Top+Grid->Top+r.Top+r.Height()+15;
      TPoint mp=Mouse->CursorPos;
      Mouse->CursorPos=TPoint(x+50,y+10);
      GridMenu->Popup(x,y);
      Mouse->CursorPos=TPoint(x,y);
    }
  }
}
//---------------------------------------------------------------------------
//
void __fastcall TURB::TreeViewKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
  if(Key == VK_ESCAPE)
  { Close();
    ModalResult=mrCancel;
  }
}
//---------------------------------------------------------------------------
//
void __fastcall TURB::GridDblClick(TObject *Sender)
{
  if(DS->State==dsEdit || DS->State==dsInsert) return;
  if(selectedSectionID == DelRecordsSectionID) return;
  if (getFolderIDByName(parentSectionID) == DelRecordsSectionID)
  {
  MessageDlg("???????? ??? ?????? ?? ??????? ?????? ?? ?????????? !!! ",mtWarning,TMsgDlgButtons() << mbOK,0);
  return;
  }

  if(Grid->SelectedRows->Count==0) Grid->Selection->Rows->CurrentRowSelected=true;
  Close();
  ModalResult=mrOk;
}
//---------------------------------------------------------------------------
//????? ??????
void __fastcall TURB::FSButtonClick(TObject *Sender)
{
TLocateOptions Opt; Opt.Clear();

  if(S_DS->RecNo < S_DS->RecordCount) S_DS->Next();
  else S_DS->First();
  DS->Locate(keyFieldName,Variant(S_DS->FieldByName(keyFieldName)->AsString),Opt);
}
//---------------------------------------------------------------------------
//????? ?????
void __fastcall TURB::BSButtonClick(TObject *Sender)
{
TLocateOptions Opt; Opt.Clear();

  if(S_DS->RecNo > 1) S_DS->Prior();
  else S_DS->Last();
  DS->Locate(keyFieldName,Variant(S_DS->FieldByName(keyFieldName)->AsString),Opt);
}
//---------------------------------------------------------------------------
//?????????????? ???????????? ???????
void __fastcall TURB::TreeViewDblClick(TObject *Sender)
{
  if(selectedSectionID == RootSectionID || selectedSectionID == DelRecordsSectionID)
  { MessageDlg("?????? ???????? ???????????? ????? ???????",mtWarning,TMsgDlgButtons() << mbOK,0);
    return;
  }
  TreeView->Selected->EditText();
}
//---------------------------------------------------------------------------
//?????????? ?????????????? ???????????? ???????
void __fastcall TURB::TreeViewEdited(TObject *Sender, TTreeNode *Node,
      AnsiString &S)
{
AnsiString ID=(static_cast<RBTreeData*>(Node->Data))->data;
AnsiString sql="update "+rbTableName+" set DESCRIPTION='"+S+"' where ID="+ID;

  Q->Close();
  Q->SQL->Clear();
  Q->SQL->Add(sql);
  try
  {
    Q->ExecQuery();
  }
  catch(const Exception &exc)
  { MessageDlg("?????? "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
    if(Q->Transaction->InTransaction) Q->Transaction->Rollback();
    return;
  }
  if(Q->Transaction->InTransaction) Q->Transaction->Commit();
}
//---------------------------------------------------------------------------
//?????????? ???????
void __fastcall TURB::AddSectionButtonClick(TObject *Sender)
{
TTreeNode *node=TreeView->Selected;
AnsiString sql;
AnsiString ID=getNewRB_KeyValue();
AnsiString fileID=(static_cast<RBTreeData*>(node->Data))->data;

  Q->Close();
  Q->SQL->Clear();
  if (rbTableName!="OPER_TABLE"){
  sql="insert into "+rbTableName+"("+keyFieldName+",FILE_ID,REC_TYPE,VISIBLE,DESCRIPTION) values(";
  sql+=ID+",";
  sql+=fileID+",0,1,'')";
  }else
  {
  sql="insert into "+rbTableName+"("+keyFieldName+",FILE_ID,REC_TYPE,VISIBLE,DESCRIPTION,NUMBER,NUMBERROW) values(";
  sql+=ID+",";
  sql+=fileID+",0,1,'','',0)";
  }
  Q->SQL->Add(sql);
  try
  {
    Q->ExecQuery();
  }
  catch(const Exception &exc)
  { MessageDlg("?????? "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
    if(Q->Transaction->InTransaction) Q->Transaction->Rollback();
    return;
  }
  if(Q->Transaction->InTransaction) Q->Transaction->Commit();
  node=TreeView->Items->AddChild(node,"");
  node->ImageIndex=0;
  node->SelectedIndex=1;
  RBTreeData *rbTD= new RBTreeData();
  rbTD->data=ID;
  node->Data=rbTD;
  TreeView->Selected=node;
  selectedSectionID=ID;
  node->EditText();
}
//---------------------------------------------------------------------------
//???????? ??????? ???????
void __fastcall TURB::DelSectionButtonClick(TObject *Sender)
{
AnsiString ID=(static_cast<RBTreeData*>(TreeView->Selected->Data))->data;
AnsiString sql;

  if(MessageDlg("?? ???????, ??? ?????? ??????? ??????? ???????",mtConfirmation,TMsgDlgButtons() << mbOK << mbCancel,0)!=mrOk) return;

  Q->Close();
  Q->SQL->Clear();
  sql="delete from "+rbTableName+" where "+keyFieldName+"="+ID;
  Q->SQL->Add(sql);
  try
  {
    Q->ExecQuery();
  }
  catch(const Exception &exc)
  { MessageDlg("?????? "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
    if(Q->Transaction->InTransaction) Q->Transaction->Rollback();
    return;
  }
  if(Q->Transaction->InTransaction) Q->Transaction->Commit();
  TreeView->Selected->Delete();
}
//---------------------------------------------------------------------------
//
void __fastcall TURB::GridMenuPopup(TObject *Sender)
{

 if (GSM_DM->UserRole=="?????????????" || GSM_DM->UserRole=="????????????")
 {
  if(selectedSectionID==RootSectionID && treeLevel == 1)
  {
  N1->Enabled = false;
  N2->Enabled = false;
  N3->Enabled = false;
  N4->Enabled = false;
  N5->Enabled = false;
  N6->Enabled = false;
  N7->Enabled = false;
  N8->Enabled = false;
  AddButton->Enabled = false;
  EditButton->Enabled = false;
  DeleteButton->Enabled = false;
  MoveButton->Enabled = false;
  RestoreButton->Enabled = false;
  SaveButton->Enabled = false;
  UndoButton->Enabled = false;
  SelectButton->Enabled = false;
  return;
  }

  if(selectedSectionID==DelRecordsSectionID && treeLevel == 0)
  {
  N1->Enabled = false;
  N2->Enabled = false;
  N3->Enabled = false;
  N4->Enabled = false;
  N5->Enabled = false;
  N6->Enabled = false;
  N7->Enabled = false;
  AddButton->Enabled = false;
  EditButton->Enabled = false;
  DeleteButton->Enabled = false;
  MoveButton->Enabled = false;
  SaveButton->Enabled = false;
  UndoButton->Enabled = false;
  SelectButton->Enabled = false;
  if(DS->RecordCount != 0) { N8->Enabled=true; RestoreButton->Enabled = true; } else { N8->Enabled=false;RestoreButton->Enabled = false;}
    if(Grid->SelectedRows->Count > 1)
    {
      N8->Enabled=false;
      RestoreButton->Enabled = false;
    }
    else
    {
      N8->Enabled=true;
      RestoreButton->Enabled = true;
    }
  return;
  }

  if(selectedSectionID==DelRecordsSectionID && treeLevel == 1)
  {
  N1->Enabled = false;
  N2->Enabled = false;
  N3->Enabled = false;
  N4->Enabled = false;
  N5->Enabled = false;
  N6->Enabled = false;
  N7->Enabled = false;
  N8->Enabled = false;
  AddButton->Enabled = false;
  EditButton->Enabled = false;
  DeleteButton->Enabled = false;
  MoveButton->Enabled = false;
  RestoreButton->Enabled = false;
  SaveButton->Enabled = false;
  UndoButton->Enabled = false;
  SelectButton->Enabled = false;
  return;
  }


  if(selectedSectionID==RootSectionID || selectedSectionID==DelRecordsSectionID || AnsiPos("_",parentSectionID)!=0)
  {
    if(treeLevel == 0 && selectedSectionID==RootSectionID) { N1->Enabled=true; AddButton->Enabled = true; } else { N1->Enabled=false; AddButton->Enabled = false;}
    if(treeLevel == 0 && selectedSectionID==RootSectionID) { N2->Enabled=true; EditButton->Enabled = true; } else { N2->Enabled=false; EditButton->Enabled = false;}
    if(treeLevel == 0 && selectedSectionID==RootSectionID) { N3->Enabled=false; DeleteButton->Enabled = false; } else { N3->Enabled=true; DeleteButton->Enabled = true;}
    if(treeLevel == 0 && selectedSectionID==RootSectionID) { N4->Enabled=true; MoveButton->Enabled = true; } else { N4->Enabled=false; MoveButton->Enabled = false;}
    if(treeLevel == 0 && selectedSectionID==RootSectionID) { N5->Enabled=false; SaveButton->Enabled = false; } else { N5->Enabled=false; SaveButton->Enabled = false;}
    if(treeLevel == 0 && selectedSectionID==RootSectionID) { N6->Enabled=false; UndoButton->Enabled = false; } else { N6->Enabled=false; UndoButton->Enabled = false;}
    if(treeLevel == 0 && selectedSectionID==RootSectionID) { N7->Enabled=false; SelectButton->Enabled = false; } else { N7->Enabled=false; SelectButton->Enabled = false;}
    if(treeLevel == 0 && selectedSectionID==RootSectionID) { N8->Enabled=false; RestoreButton->Enabled = false; } else { N8->Enabled=true; RestoreButton->Enabled = true;}
  }
  else
  {
    if(DS->RecordCount != 0) { N3->Enabled=false;DeleteButton->Enabled = false; } else { N3->Enabled=false;DeleteButton->Enabled = false;}
    if(DS->RecordCount != 0) { N4->Enabled=true;MoveButton->Enabled = true; } else { N4->Enabled=false;MoveButton->Enabled = false;}
    if(DS->RecordCount != 0) { N5->Enabled=true;SaveButton->Enabled = true; } else { N5->Enabled=false;SaveButton->Enabled = false;}
    if(DS->RecordCount != 0) { N6->Enabled=true;UndoButton->Enabled = true; } else { N6->Enabled=false;UndoButton->Enabled = false;}
    if(DS->RecordCount != 0) { N7->Enabled=true;SelectButton->Enabled = true; } else { N7->Enabled=false;SelectButton->Enabled = false;}
    if(DS->RecordCount != 0) { N8->Enabled=false;RestoreButton->Enabled = false; } else { N8->Enabled=false;RestoreButton->Enabled = false;}
    if(Grid->SelectedRows->Count > 1)
    {
      N1->Enabled=false;
      N2->Enabled=false;
      AddButton->Enabled = false;
      EditButton->Enabled = false;
    }
    else
    {
      N1->Enabled=true;
      N2->Enabled=true;
      AddButton->Enabled = true;
      EditButton->Enabled = true;
    }
  }
 }else
 {
      N1->Enabled=false;
      N2->Enabled=false;
      N3->Enabled=false;
      N4->Enabled=false;
      N5->Enabled=false;
      N6->Enabled=false;
      N7->Enabled=false;
      N8->Enabled=false;
 }
}
//---------------------------------------------------------------------------
//?????????? ?????? ? ??????????
void __fastcall TURB::N1Click(TObject *Sender)
{
  if(directGridEdit==false)
  { AnsiString keyValue="";
    TAddEditRBRecordForm *ARF;
    MFieldsInformation *fi;

    try
    {
      fi=new MFieldsInformation(this, rbTableName, keyFieldName);
    }
    catch(const Exception &exc)
    { MessageDlg("?????? ???????? ??????? FI"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      return;
    }

    try
    {
      ARF=new TAddEditRBRecordForm(this, fi, true);
    }
    catch(const Exception &exc)
    { MessageDlg("?????? ???????? ????? "+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      delete fi;
      return;
    }
    //?????????? ???? SD_ID
    int poz=ARF->getFI()->getPisitionField("SD_ID");
    if(poz>=0)
    { AnsiString sdid="";
      AnsiString sdname="";
      AnsiString className=Owner->ClassName();
      if(className=="TMainForm")
      { sdid=(static_cast<TMainForm*>(Owner))->getSD_ID();
        sdname=(static_cast<TMainForm*>(Owner))->selectSDBar->Items->Items[(static_cast<TMainForm*>(Owner))->getSetectidSD()]->Caption;
      }
      else if(className=="TAddEditRBRecordForm")
      { TAddEditRBRecordForm *aef=static_cast<TAddEditRBRecordForm*>(Owner);
        int p=aef->getFI()->getPisitionField("SD_ID");
        if(p>=0)
        { sdid=aef->getFI()->getFieldInfo(p)->getFieldData();
          sdname=aef->getFI()->getFieldInfo(p)->getRetFieldData();
        }
      }
      ARF->getFI()->getFieldInfo(poz)->setFieldData(sdid);
      ARF->getFI()->getFieldInfo(poz)->setRetFieldData(sdname);
      RBEditorElement *aee=ARF->findEAE(poz);
      if(aee!=NULL) (static_cast<TComboBox*>(aee->getEdit()))->Text=sdname;
    }
    if(ARF->ShowModal()==mrOk)
    { AnsiString sql;
      if(DS->RecordCount > 0)
      { //?????????, ??? ?? ??? ?????? ? ????? ?? ????? DESCRIPTION ??? ? ? ????? ??????
        AnsiString newDescription;
        for(int i=3; i<fi->getFieldsCount(); i++) if(fi->getFieldInfo(i)->getFieldName()=="DESCRIPTION"){ newDescription=fi->getFieldInfo(i)->getFieldData(); break; }
        Q->Close();
        Q->SQL->Clear();
        sql="select "+keyFieldName+" from "+rbTableName+" where FILE_ID="+DS->FieldByName("FILE_ID")->AsString+" and DESCRIPTION like '"+newDescription+"'";
        Q->SQL->Add(sql);
        try
        {
          Q->ExecQuery();
        }
        catch(const Exception &exc)
        { MessageDlg("?????? "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
          if(ARF!=NULL) delete ARF;
          return;
        }
        if(Q->RecordCount > 0)
        { if(treeViewable)
            MessageDlg("? ??????? \""+TreeView->Selected->Text+"\" ??? ??????? ?????? ? ????????????? \""+newDescription+"\".\n????? ?????? ?? ???????????.",mtWarning,TMsgDlgButtons() << mbOK,0);
          else
            MessageDlg("? ??????????? ??? ??????? ?????? ? ????????????? \""+newDescription+"\".\n????? ?????? ?? ???????????.",mtWarning,TMsgDlgButtons() << mbOK,0);
          if(ARF!=NULL) delete ARF;
          return;
        }
      }
      //????????? ????? ??????
      AnsiString ID=getNewRB_KeyValue();
      Q->Close();
      Q->SQL->Clear();
      sql="insert into "+rbTableName+"(";
      for(int i=0; i<fi->getFieldsCount(); i++)
      { if(i>0) sql+=",";
        sql+=fi->getFieldInfo(i)->getFieldName();
      }
      sql+=") values(";
      sql+=ID+",";
      sql+=selectedSectionID+",1,";
      for(int i=3; i<fi->getFieldsCount(); i++)
      { if(!fi->getFieldInfo(i)->getFieldData().IsEmpty())
        { if(fi->getFieldInfo(i)->getFieldType()>2 && fi->getFieldInfo(i)->getFieldType()<6) sql+="'";
          sql+=fi->getFieldInfo(i)->getFieldData();
          if(fi->getFieldInfo(i)->getFieldType()>2 && fi->getFieldInfo(i)->getFieldType()<6) sql+="'";
        }
        else sql+="NULL";
        if(i<fi->getFieldsCount()-1) sql+=",";
      }
      sql+=")";
      Q->SQL->Add(sql);
      try
      {
        Q->ExecQuery();
      }
      catch(const Exception &exc)
      { MessageDlg("?????? "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
        return;
      }

      loadDS();
      TLocateOptions lo; lo.Clear();
      DS->Locate(keyFieldName,ID,lo);
    }
    delete ARF;
    delete fi;
    Grid->SetFocus();
  }
  else
  {
    AnsiString sql=DS->SQLs->InsertSQL->Strings[0];
    try
    {
      DS->Append();
    }
    catch(const Exception &exc)
    { MessageDlg("?????? "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      return;
    }
  }
}
//---------------------------------------------------------------------------
//?????????????? ??????? ??????
void __fastcall TURB::N2Click(TObject *Sender)
{
  if(directGridEdit==false)
  { AnsiString keyValue="";
    TAddEditRBRecordForm *ARF;
    MFieldsInformation *fi;
    AnsiString sql;

    try
    {
      fi=new MFieldsInformation(this, rbTableName, keyFieldName);
    }
    catch(const Exception &exc)
    { MessageDlg("?????? ???????? ??????? FI"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      return;
    }
    fi->setFIData(DS);
    try
    {
      ARF=new TAddEditRBRecordForm(this, fi, false);
    }
    catch(const Exception &exc)
    { MessageDlg("?????? ???????? ????? "+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      delete fi;
      return;
    }
    if(ARF->ShowModal()==mrOk)
    { AnsiString ID=DS->FieldByName(keyFieldName)->AsString;

      //?????????, ??? ?? ??? ?????? ? ????? ?? ????? DESCRIPTION ??? ? ? ????????????????? ??????
      AnsiString newDescription;
      for(int i=3; i<fi->getFieldsCount(); i++) if(fi->getFieldInfo(i)->getFieldName()=="DESCRIPTION"){ newDescription=fi->getFieldInfo(i)->getFieldData(); break; }
      Q->Close();
      Q->SQL->Clear();
      sql="select "+keyFieldName+" from "+rbTableName+" where FILE_ID="+DS->FieldByName("FILE_ID")->AsString+" and ID<>"+ID+" and DESCRIPTION like '"+newDescription+"'";
      Q->SQL->Add(sql);
      try
      {
        Q->ExecQuery();
      }
      catch(const Exception &exc)
      { MessageDlg("?????? "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
        if(ARF!=NULL) delete ARF;
        return;
      }
      if(Q->RecordCount > 0)
      { if(treeViewable)
          MessageDlg("? ??????? \""+TreeView->Selected->Text+"\" ??? ??????? ?????? ? ????????????? \""+newDescription+"\".\n????????? ?? ???????????.",mtWarning,TMsgDlgButtons() << mbOK,0);
        else
          MessageDlg("? ??????????? ??? ??????? ?????? ? ????????????? \""+newDescription+"\".\n????????? ?? ???????????.",mtWarning,TMsgDlgButtons() << mbOK,0);
        if(ARF!=NULL) delete ARF;
        return;
      }
      //????????? ?????????
      Q->Close();
      Q->SQL->Clear();
      sql="update "+rbTableName+" set ";
      bool firstField=true;
      for(int i=3; i<fi->getFieldsCount(); i++)
      { AnsiString newFD=fi->getFieldInfo(i)->getFieldData();
        AnsiString oldFD=FI->getFieldInfo(i)->getFieldData();
        if(newFD!=oldFD)
        { if(firstField==false) sql+=",";
          sql+=fi->getFieldInfo(i)->getFieldName()+"=";
          if(!fi->getFieldInfo(i)->getFieldData().IsEmpty())
          { if(fi->getFieldInfo(i)->getFieldType()>2 && fi->getFieldInfo(i)->getFieldType()<6) sql+="'";
            sql+=newFD;
            if(fi->getFieldInfo(i)->getFieldType()>2 && fi->getFieldInfo(i)->getFieldType()<6) sql+="'";
          }
          else sql+="NULL";
          firstField=false;
        }
      }
      if(firstField==false)
      { sql+=" where "+keyFieldName+"="+ID;
        Q->SQL->Add(sql);
        try
        {
          Q->ExecQuery();
        }
        catch(const Exception &exc)
        { MessageDlg("?????? "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
          return;
        }
        loadDS();
        TLocateOptions lo; lo.Clear();
        DS->Locate(keyFieldName,ID,lo);
      }
    }
    delete ARF;
    delete fi;
    Grid->SetFocus();
  }
  else
  {
    AnsiString sql=DS->SQLs->UpdateSQL->Strings[0];
    try
    {
      DS->Edit();
    }
    catch(const Exception &exc)
    { MessageDlg("?????? "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      return;
    }
  }
}
//---------------------------------------------------------------------------
//???????? ?????????? ???????
void __fastcall TURB::N3Click(TObject *Sender)
{
AnsiString sql;
AnsiString ID;
AnsiString FN;
AnsiString FID;

FN=TreeView->Selected->Text.Trim();

if(Grid->SelectedRows->Count==0) Grid->Selection->Rows->CurrentRowSelected=true;

sql="?? ???????, ??? ?????? ";
sql+="??????? ???????? ";
if(Grid->SelectedRows->Count==1) sql+="????????? ?????? ?? ???????";
else sql+="????????? ?????? ?? ?????? ? ";
sql+=" ????????!!! ??? ????????? ?????? ????? ???????????? ??????? !!!!";

if(MessageDlg(sql,mtConfirmation,TMsgDlgButtons() << mbOK << mbCancel,0)==mrOk)
{
  int rn=DS->RecNo;
  for(int i=0; i<Grid->SelectedRows->Count; ++i)
  {
        DS->GotoBookmark((void *)Grid->SelectedRows->Items[i].c_str());
        sql="";
        // ????? ?????????? FILE_ID
        Q->Close();
        Q->SQL->Clear();
        sql="select "+keyFieldName+" from "+rbTableName+" where DESCRIPTION like '"+TreeView->Selected->Text.Trim()+"'" + " and REC_TYPE =0 and FILE_ID <> " + DelRecordsSectionID;
        Q->SQL->Add(sql);
        try
        {
          Q->ExecQuery();
        }
        catch(const Exception &exc)
        {
          MessageDlg("?????? "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
          return;
        }
        if(Q->RecordCount > 0)
        {
        FID=Q->FieldByName("ID")->AsString;
        }
        else
        {
        MessageDlg("? ?? ?? ??????? ?????? ? ????????????? \""+DS->FieldByName("DESCRIPTION")->AsString+"\".\n ?????? ????????????",mtWarning,TMsgDlgButtons() << mbOK,0);
        continue;
        }

        sql="";
        sql="delete from EXPENSES_TABLE where DRIVER_ID = "+DS->FieldByName(keyFieldName)->AsString;
        Q->Close();
        Q->SQL->Clear();
        Q->SQL->Add(sql);
        try
        {
          Q->ExecQuery();
        }
        catch(const Exception &exc)
        {
          MessageDlg("?????? "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
          if(Q->Transaction->InTransaction) Q->Transaction->Rollback();
          return;
        }
        if(Q->Transaction->InTransaction) Q->Transaction->Commit();

        sql="";
        sql="delete from "+rbTableName+" where "+keyFieldName+"="+DS->FieldByName(keyFieldName)->AsString;
        Q->Close();
        Q->SQL->Clear();
        Q->SQL->Add(sql);
        try
        {
        Q->ExecQuery();
        }
        catch(const Exception &exc)
        {
        MessageDlg("?????? "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
        if(Q->Transaction->InTransaction) Q->Transaction->Rollback();
        return;
        }
        if(Q->Transaction->InTransaction) Q->Transaction->Commit();

        DS->Refresh();
        DS->Last();
        if (DS->RecordCount == 1)
        {
        // ???????? ?? ??????? ?????? ? ??????!!!!
        Q->Close();
        Q->SQL->Clear();
        sql="select "+keyFieldName+" from "+rbTableName+" where ID = "+FID+" and REC_TYPE =0 and VISIBLE =0";
        Q->SQL->Add(sql);
        try
        {
          Q->ExecQuery();
        }
        catch(const Exception &exc)
        { MessageDlg("?????? "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
          return;
        }
          if(Q->RecordCount > 0)
          {
            sql="";
            sql="delete from EXPENSES_TABLE where SD_ID = "+FID;
            Q->Close();
            Q->SQL->Clear();
            Q->SQL->Add(sql);
            try
            {
            Q->ExecQuery();
            }
            catch(const Exception &exc)
            {
            MessageDlg("?????? "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
            if(Q->Transaction->InTransaction) Q->Transaction->Rollback();
            return;
            }
            if(Q->Transaction->InTransaction) Q->Transaction->Commit();

            sql="";
            sql="delete from "+rbTableName+" where "+keyFieldName+"="+selectedSectionID;
            Q->Close();
            Q->SQL->Clear();
            Q->SQL->Add(sql);
            try
            {
            Q->ExecQuery();
            }
            catch(const Exception &exc)
            {
            MessageDlg("?????? "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
            if(Q->Transaction->InTransaction) Q->Transaction->Rollback();
            return;
            }
            if(Q->Transaction->InTransaction) Q->Transaction->Commit();

            sql="";
            sql="delete from "+rbTableName+" where "+keyFieldName+"="+FID;
            Q->Close();
            Q->SQL->Clear();
            Q->SQL->Add(sql);
            try
            {
            Q->ExecQuery();
            }
            catch(const Exception &exc)
            {
            MessageDlg("?????? "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
            if(Q->Transaction->InTransaction) Q->Transaction->Rollback();
            return;
            }
            if(Q->Transaction->InTransaction) Q->Transaction->Commit();

            if(treeViewable==true)
            {
            createRBTree(flagv);
            TreeView->FullExpand();
  //        FindPositionInTreeViewForFolderName(FN);
            }
            else
            {
            selectedSectionID=RootSectionID;
            N4->Visible=false;
            MoveButton->Enabled = false;
            }
          }else
          {
            sql="update "+rbTableName+" set VISIBLE = 0 where ID="+selectedSectionID;
            Q->Close();
            Q->SQL->Clear();
            Q->SQL->Add(sql);
            try
            {
            Q->ExecQuery();
            }
            catch(const Exception &exc)
            {
            MessageDlg("?????? "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
            if(Q->Transaction->InTransaction) Q->Transaction->Rollback();
            return;
            }
            if(Q->Transaction->InTransaction) Q->Transaction->Commit();
            if(treeViewable==true)
            {
            createRBTree(flagv);
            TreeView->FullExpand();
            FindPositionInTreeViewForFolderName(FN);
            }
            else
            {
            selectedSectionID=RootSectionID;
            N4->Visible=false;
            MoveButton->Enabled = false;
            }
          }
        }
  }
      loadDS();
      DS->RecNo=rn;
}
  Grid->SetFocus();
}
//---------------------------------------------------------------------------
//??????? ?????????? ??????? ? ?????
void __fastcall TURB::FindPositionInTreeView(AnsiString id)
{
bool finded=false;
RBTreeData* rbTD;

  if(treeViewable==false) return;
  for(int i=0; i < TreeView->Items->Count; i++)
  { rbTD=static_cast<RBTreeData*>(TreeView->Items->Item[i]->Data);
    if(rbTD->data==id)
    { TreeView->Selected=TreeView->Items->Item[i];
      finded=true;
      break;
    }
  }
  if(!finded) TreeView->Selected=TreeView->Items->Item[0];
}
//---------------------------------------------------------------------------
void __fastcall TURB::FindPositionInTreeViewForFolderName(AnsiString FolderName)
{
int i;

  if(treeViewable==false) return;
  for(i=0; i < TreeView->Items->Count; i++)
  { if(TreeView->Items->Item[i]->Text==FolderName)
      break;
  }
  if(i==TreeView->Items->Count) i=0;
  TreeView->Selected=TreeView->Items->Item[i];
}
//---------------------------------------------------------------------------
//
void __fastcall TURB::OnFoldersCheckBoxClick(TObject *Sender)
{
AnsiString ID=DS->FieldByName(keyFieldName)->AsString;

  FindPositionInTreeView(DS->FieldByName("FILE_ID")->AsString);
  loadDS();
  TLocateOptions lo; lo.Clear();
  DS->Locate(keyFieldName,ID,lo);
}
//---------------------------------------------------------------------------
void __fastcall TURB::SStateChange(TObject *Sender)
{
  if(Grid->Visible==true)
  { if(DS->State==dsEdit || DS->State==dsInsert)
    { N5->Visible=true;
      N6->Visible=true;
      PostButton->Enabled=true;
      CancelButton->Enabled=true;
    }
    else
    { N5->Visible=false;
      N6->Visible=false;
      PostButton->Enabled=false;
      CancelButton->Enabled=false;
    }
  }
}
//---------------------------------------------------------------------------
void __fastcall TURB::N5Click(TObject *Sender)
{
  if(DS->State==dsEdit || DS->State==dsInsert) DS->Post();
  DS->Refresh(); 
}
//---------------------------------------------------------------------------
void __fastcall TURB::N6Click(TObject *Sender)
{
  if(DS->State==dsEdit || DS->State==dsInsert) DS->Cancel();
}
//---------------------------------------------------------------------------
void __fastcall TURB::PostButtonClick(TObject *Sender)
{
  if(DS->State==dsEdit || DS->State==dsInsert) DS->Post();
  DS->Refresh(); 
}
//---------------------------------------------------------------------------
void __fastcall TURB::CancelButtonClick(TObject *Sender)
{
  if(DS->State==dsEdit || DS->State==dsInsert) DS->Cancel();
  DS->Refresh(); 
}
//---------------------------------------------------------------------------
void __fastcall TURB::ColumnOnClickButton(TObject* Sender, bool &Handled)
{
  if(DS->State!=dsEdit && DS->State!=dsInsert) return;

  AnsiString gName=Grid->Columns->Items[Grid->Col-1]->FieldName;
  AnsiString fName="";
  int fn=0;
  TURB *urb=NULL;
  int n=1;

  for(fn=0; fn<FI->getFieldsCount(); fn++)
  { if(FI->getFieldInfo(fn)->getFieldType()==9 && FI->getFieldInfo(fn)->isGridViewable())
    { AnsiString s="F"+IntToStr(n);
      if(s==gName)
      { fName=FI->getFieldInfo(fn)->getFieldName();
        break;
      }
      n++;
    }
  }

  if(fn==FI->getFieldsCount()) return;

  try
  { AnsiString refTableName=FI->getFieldInfo(fn)->getRefTableName();
    urb=new TURB(Owner,refTableName,0);
  }
  catch (Exception &exc)
  { MessageDlg("?????? ???????? ??????? TURB\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
    return;
  }
  if(urb->ShowModal()==mrOk)
  {
    DS->FieldByName(fName)->Value=urb->DS->FieldByName(urb->getKeyFieldName())->Value;
    DS->FieldByName(gName)->Value=urb->DS->FieldByName("DESCRIPTION")->Value;
  }
  if(urb!=NULL) delete urb;
}
//---------------------------------------------------------------------------
void __fastcall TURB::DSAfterInsert(TDataSet *DataSet)
{
  if(directGridEdit==true)
  { if(DS->State==dsInsert)
    { AnsiString ID=getNewRB_KeyValue();
      DS->FieldByName(keyFieldName)->AsString=ID;
      DS->FieldByName("FILE_ID")->AsString=selectedSectionID;
      DS->FieldByName("REC_TYPE")->AsInteger=1;
    }
  }
}
//---------------------------------------------------------------------------
bool __fastcall TURB::removeableCheck(AnsiString tableName, AnsiString ID)
{
  return false;
}
//---------------------------------------------------------------------------
void __fastcall TURB::N7Click(TObject *Sender)
{
  GridDblClick(this);
}
//---------------------------------------------------------------------------



void __fastcall TURB::N8Click(TObject *Sender)
{
AnsiString sql;
AnsiString ID;
AnsiString FN;

FN=TreeView->Selected->Text.Trim();

  if(Grid->SelectedRows->Count==0) Grid->Selection->Rows->CurrentRowSelected=true;

    sql="?? ???????, ??? ?????? ";
    sql+="???????????? ";
    if(Grid->SelectedRows->Count==1) sql+="????????? ?????? ?? ???????";
    else sql+="????????? ?????? ?? ?????? ?";
    if(MessageDlg(sql,mtConfirmation,TMsgDlgButtons() << mbOK << mbCancel,0)==mrOk)
    {
      int rn=DS->RecNo;
      for(int i=0; i<Grid->SelectedRows->Count; ++i)
      {
        DS->GotoBookmark((void *)Grid->SelectedRows->Items[i].c_str());
        //?????????, ??? ?? ? ?????? ????????? ?????
        Q->Close();
        Q->SQL->Clear();
        sql="select "+keyFieldName+" from "+rbTableName+" where DESCRIPTION like '"+TreeView->Selected->Text.Trim()+"'" + " and REC_TYPE =0";
        Q->SQL->Add(sql);
        try
        {
          Q->ExecQuery();
        }
        catch(const Exception &exc)
        { MessageDlg("?????? "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
          return;
        }
        if(Q->RecordCount > 0)
        {
        ID=IntToStr(Q->FieldByName("ID")->AsInteger);
        sql="update "+rbTableName+" set VISIBLE = 1 where ID="+ID;
        Q->Close();
        Q->SQL->Clear();
        Q->SQL->Add(sql);
        try
        {
          Q->ExecQuery();
        }
        catch(const Exception &exc)
        {
          MessageDlg("?????? "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
          if(Q->Transaction->InTransaction) Q->Transaction->Rollback();
          return;
        }
        if(Q->Transaction->InTransaction) Q->Transaction->Commit();
        sql="";
        sql="update "+rbTableName+" set FILE_ID = "+ID+" where ID="+IntToStr(DS->FieldByName("ID")->AsInteger);
        Q->Close();
        Q->SQL->Clear();
        Q->SQL->Add(sql);
        try
        {
          Q->ExecQuery();
        }
        catch(const Exception &exc)
        {
          MessageDlg("?????? "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
          if(Q->Transaction->InTransaction) Q->Transaction->Rollback();
          return;
        }
        if(Q->Transaction->InTransaction) Q->Transaction->Commit();
        sql="";
        sql="update "+rbTableName+" set VISIBLE = 1 where ID="+IntToStr(DS->FieldByName("ID")->AsInteger);
        Q->Close();
        Q->SQL->Clear();
        Q->SQL->Add(sql);
        try
        {
          Q->ExecQuery();
        }
        catch(const Exception &exc)
        {
          MessageDlg("?????? "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
          if(Q->Transaction->InTransaction) Q->Transaction->Rollback();
          return;
        }
        if(Q->Transaction->InTransaction) Q->Transaction->Commit();
        DS->Refresh();
        DS->Last();
        if (DS->RecordCount == 1)
        {
        sql="update "+rbTableName+" set VISIBLE = 0 where ID="+selectedSectionID;
        Q->Close();
        Q->SQL->Clear();
        Q->SQL->Add(sql);
        try
        {
          Q->ExecQuery();
        }
        catch(const Exception &exc)
        {
          MessageDlg("?????? "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
          if(Q->Transaction->InTransaction) Q->Transaction->Rollback();
          return;
        }
        if(Q->Transaction->InTransaction) Q->Transaction->Commit();
        }
        }else
        {
        MessageDlg("? ????????? ??? ??????????? ???????????? ?????? ? ????????????? \""+DS->FieldByName("DESCRIPTION")->AsString+"\".\n ?????? ????????????. ?????? ?????? ??????? ??????? ?? ?????? ????? !!!",mtWarning,TMsgDlgButtons() << mbOK,0);
        continue;
        }
      }
      if(treeViewable==true)
      {
        createRBTree(flagv);
        TreeView->FullExpand();
        FindPositionInTreeViewForFolderName(FN);
      }
      else
      {
        selectedSectionID=RootSectionID;
        N4->Visible=false;
        MoveButton->Enabled = false;
      }
      loadDS();
      DS->RecNo=rn;
    }
  Grid->SetFocus();
}
//---------------------------------------------------------------------------

void __fastcall TURB::N4Click(TObject *Sender)
{
AnsiString sql;
AnsiString ID;
AnsiString FN;

FN=TreeView->Selected->Text.Trim();

  if(Grid->SelectedRows->Count==0) Grid->Selection->Rows->CurrentRowSelected=true;

    sql="?? ???????, ??? ?????? ";
    sql+="????????? ";
    if(Grid->SelectedRows->Count==1) sql+="????????? ?????? ? ??????";
    else sql+="????????? ?????? ? ????? ?";
    if(MessageDlg(sql,mtConfirmation,TMsgDlgButtons() << mbOK << mbCancel,0)==mrOk)
    {
      int rn=DS->RecNo;
      for(int i=0; i<Grid->SelectedRows->Count; ++i)
      {
        DS->GotoBookmark((void *)Grid->SelectedRows->Items[i].c_str());
        //?????????, ??? ?? ? ?????? ????????? ?????
        Q->Close();
        Q->SQL->Clear();
        sql="select "+keyFieldName+" from "+rbTableName+" where FILE_ID="+DelRecordsSectionID+" and DESCRIPTION like '"+TreeView->Selected->Text.Trim()+"'" + " and REC_TYPE =0";
        Q->SQL->Add(sql);
        try
        {
          Q->ExecQuery();
        }
        catch(const Exception &exc)
        { MessageDlg("?????? "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
          return;
        }
        if(Q->RecordCount > 0)
        {
        ID=IntToStr(Q->FieldByName("ID")->AsInteger);
        }else
        {
        ID=getNewRB_KeyValue();
        Q->Close();
        Q->SQL->Clear();
        sql="insert into "+rbTableName+"("+keyFieldName+",FILE_ID,REC_TYPE,VISIBLE,DESCRIPTION) values(";
        sql+=ID+",";
        sql+=DelRecordsSectionID+",0,1,";
        sql+= "'" +TreeView->Selected->Text.Trim()+ "')";
        Q->SQL->Add(sql);
        try
        {
        Q->ExecQuery();
        }
        catch(const Exception &exc)
        { MessageDlg("?????? "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
          if(Q->Transaction->InTransaction) Q->Transaction->Rollback();
          return;
        }
        if(Q->Transaction->InTransaction) Q->Transaction->Commit();
        }
        sql="";
        //?????????, ??? ?? ? ??????? ?????? ? ????? ?? ????? DESCRIPTION ??? ? ? ??????????? ? ????? ??????
        Q->Close();
        Q->SQL->Clear();
        sql="select "+keyFieldName+" from "+rbTableName+" where FILE_ID="+ID+" and DESCRIPTION like '"+DS->FieldByName("DESCRIPTION")->AsString+"'";
        Q->SQL->Add(sql);
        try
        {
          Q->ExecQuery();
        }
        catch(const Exception &exc)
        { MessageDlg("?????? "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
          return;
        }
        if(Q->RecordCount > 0)
        {
          MessageDlg("? ?????? ??? ??????? ?????? ? ????????????? \""+DS->FieldByName("DESCRIPTION")->AsString+"\".\n ?????? ????????????",mtWarning,TMsgDlgButtons() << mbOK,0);
          continue;
        }
        sql="";
        sql="update "+rbTableName+" set VISIBLE = 1 where ID="+ID;
        Q->Close();
        Q->SQL->Clear();
        Q->SQL->Add(sql);
        try
        {
          Q->ExecQuery();
        }
        catch(const Exception &exc)
        {
          MessageDlg("?????? "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
          if(Q->Transaction->InTransaction) Q->Transaction->Rollback();
          return;
        }
        if(Q->Transaction->InTransaction) Q->Transaction->Commit();
        //????????? ????????? ?????? ? ?????
        sql="update "+rbTableName+" set FILE_ID = "+ID+" where ID="+DS->FieldByName(keyFieldName)->AsString;
        Q->Close();
        Q->SQL->Clear();
        Q->SQL->Add(sql);
        try
        {
          Q->ExecQuery();
        }
        catch(const Exception &exc)
        { MessageDlg("?????? "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
          if(Q->Transaction->InTransaction) Q->Transaction->Rollback();
          return;
        }
        if(Q->Transaction->InTransaction) Q->Transaction->Commit();
        sql="";
        sql="update "+rbTableName+" set VISIBLE = 0 where ID="+DS->FieldByName(keyFieldName)->AsString;
        Q->Close();
        Q->SQL->Clear();
        Q->SQL->Add(sql);
        try
        {
          Q->ExecQuery();
        }
        catch(const Exception &exc)
        { MessageDlg("?????? "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
          if(Q->Transaction->InTransaction) Q->Transaction->Rollback();
          return;
        }
        if(Q->Transaction->InTransaction) Q->Transaction->Commit();

      }
      DS->Refresh();
      DS->Last();
      if (DS->RecordCount == 1)
      {
        sql="update "+rbTableName+" set VISIBLE = 0 where ID="+selectedSectionID;
        Q->Close();
        Q->SQL->Clear();
        Q->SQL->Add(sql);
        try
        {
          Q->ExecQuery();
        }
        catch(const Exception &exc)
        {
          MessageDlg("?????? "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
          if(Q->Transaction->InTransaction) Q->Transaction->Rollback();
          return;
        }
        if(Q->Transaction->InTransaction) Q->Transaction->Commit();
      }
      if(treeViewable==true)
      {
        createRBTree(flagv);
        TreeView->FullExpand();
        FindPositionInTreeViewForFolderName(FN);
      }
      else
      {
        selectedSectionID=RootSectionID;
        N4->Visible=false;
        MoveButton->Enabled = false;
      }
      loadDS();
      DS->RecNo=rn;
    }
  Grid->SetFocus();
}
//---------------------------------------------------------------------------

void __fastcall TURB::AddButtonClick(TObject *Sender)
{
N1Click(this);
}
//---------------------------------------------------------------------------

void __fastcall TURB::EditButtonClick(TObject *Sender)
{
N2Click(this);
}
//---------------------------------------------------------------------------

void __fastcall TURB::DeleteButtonClick(TObject *Sender)
{
N3Click(this);
}
//---------------------------------------------------------------------------

void __fastcall TURB::MoveButtonClick(TObject *Sender)
{
N4Click(this);
}
//---------------------------------------------------------------------------

void __fastcall TURB::RestoreButtonClick(TObject *Sender)
{
N8Click(this);
}
//---------------------------------------------------------------------------

void __fastcall TURB::SaveButtonClick(TObject *Sender)
{
N5Click(this);
}
//---------------------------------------------------------------------------

void __fastcall TURB::UndoButtonClick(TObject *Sender)
{
N6Click(this);
}
//---------------------------------------------------------------------------

void __fastcall TURB::SelectButtonClick(TObject *Sender)
{
N7Click(this);
}
//---------------------------------------------------------------------------

void __fastcall TURB::TreeMenuPopup(TObject *Sender)
{

  if (rbTableName!="OPER_TABLE")
  {
  N9->Visible = true;
  if(selectedSectionID==RootSectionID )
  {
  N9->Visible  = false;
  }

  if(selectedSectionID==DelRecordsSectionID )
  {
  N9->Visible = false;
  }
  }
  else
  {
  N9->Visible = false;
  }

}
//---------------------------------------------------------------------------

void __fastcall TURB::reloadButtonClick(TObject *Sender)
{
TpFIBQuery *Q=GSM_DM->RQ;
TpFIBQuery *QW=GSM_DM->WQ;

AnsiString sql;


    sql="select * from EI";
    if (rbTableName=="OPS_TABLE") sql+=" where DESCRIPTION not containing '?????'";
    if (rbTableName=="KASSA_TABLE") sql+=" where DESCRIPTION containing '?????'";

    usersINS->SQLs->SelectSQL->Clear();
    usersINS->SQLs->SelectSQL->Add(sql);

  try
  {
    usersINS->Open();
  }
  catch (Exception &exc)
  { MessageDlg("?????? ???????? ??????? EI ?? ?? ?????????\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
    return;
  }

  usersINS->First();
  while(!usersINS->Eof)
  {
    AnsiString username=usersINS->FieldByName("DESCRIPTION")->AsString.Trim();
    int id=usersINS->FieldByName("ID")->AsInteger;
    Q->Close();
    Q->SQL->Clear();
    if (rbTableName=="OPS_TABLE") sql="select ID from OPS_TABLE where DESCRIPTION='"+username+"'";
    if (rbTableName=="KASSA_TABLE") sql="select ID from KASSA_TABLE where DESCRIPTION='"+username+"'";

    Q->SQL->Add(sql);
    try
    {
    Q->ExecQuery();
    }
    catch (Exception &exc)
    { MessageDlg("?????? - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      return;
    }

  if(Q->FieldByName("ID")->AsInteger > 0)
  {
    QW->Close();
    QW->SQL->Clear();
    if (rbTableName=="OPS_TABLE") sql="update OPS_TABLE set IDINS = " +IntToStr(id);
    if (rbTableName=="KASSA_TABLE") sql="update KASSA_TABLE set IDINS = " +IntToStr(id);
    sql+=" where ID="+IntToStr(Q->FieldByName("ID")->AsInteger);
    QW->SQL->Add(sql);
    QW->Transaction->StartTransaction();
    try
    {
      QW->ExecQuery();
    }
    catch (Exception &exc)
    {
      MessageDlg("?????? - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      QW->Transaction->Rollback();
      return;
    }
    QW->Transaction->Commit();
    QW->Close();
    QW->SQL->Clear();
    if (rbTableName=="OPS_TABLE") sql="update OPS_TABLE set IDINS = " +IntToStr(id);
    if (rbTableName=="KASSA_TABLE") sql="update KASSA_TABLE set IDINS = " +IntToStr(id);
    sql+=" where FILE_ID="+IntToStr(Q->FieldByName("ID")->AsInteger);
    QW->SQL->Add(sql);
    QW->Transaction->StartTransaction();
    try
    {
      QW->ExecQuery();
    }
    catch (Exception &exc)
    {
      MessageDlg("?????? - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      QW->Transaction->Rollback();
      return;
    }
    QW->Transaction->Commit();
  }
  else
  {
  if (rbTableName=="OPS_TABLE") MessageDlg("????????? - "+username+" ?? ?????? ? ?? ????????. ?????????? ??? ???????? ? ?? ???????? ? ????? ??????? ????????????? ??????!",mtInformation,TMsgDlgButtons() << mbOK,0);
  if (rbTableName=="KASSA_TABLE") MessageDlg("????? - "+username+" ?? ?????? ? ?? ????????. ?????????? ??? ???????? ? ?? ???????? ? ????? ??????? ????????????? ??????!",mtInformation,TMsgDlgButtons() << mbOK,0);
//  return;
  }
  Q->Close();
  usersINS->Next();
  }
usersINS->Close();
MessageDlg("????????????? ?????? ????????? ???????!",mtInformation,TMsgDlgButtons() << mbOK,0);
}
//---------------------------------------------------------------------------

