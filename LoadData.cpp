//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Main.h"
#include "DataModule.h"
#include "UniversalReferenceBook.h"
#include "LoadData.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "JvComponent"
#pragma link "JvExControls"
#pragma link "JvNavigationPane"
#pragma link "Placemnt"
#pragma link "JvDotNetControls"
#pragma link "JvExMask"
#pragma link "JvToolEdit"
#pragma link "JvExComCtrls"
#pragma link "JvProgressBar"
#pragma resource "*.dfm"
TLoadDataForm *LoadDataForm;
//---------------------------------------------------------------------------
__fastcall TLoadDataForm::TLoadDataForm(TComponent* Owner)
        : TForm(Owner)
{
  workDir=MainForm->workDir;

  FormStorage->IniFileName=workDir+"AccountGSM.ini";
  FormStorage->IniSection="LoadDataForm";
  if(!DirectoryExists(workDir+"In")) CreateDir(workDir+"In");
  DirectoryEdit->InitialDir=workDir+"In";
  DirectoryEdit->Text=DirectoryEdit->InitialDir;
  Memo1->Clear();
  LoadButton->Enabled=false;
  DateEdit1->Clear(); DateEdit2->Clear();
  COD_M=NULL;
  SD_COD=NULL;
  try
  {
    COD_M=new TStringList;
  }
  catch (Exception &exc)
  { MessageDlg("Ошибка создания объекта TStringList - COD_M\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
    return;
  }
  try
  {
    SD_COD=new TStringList;
  }
  catch (Exception &exc)
  { MessageDlg("Ошибка создания объекта TStringList - CD_COD\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
    return;
  }
  TpFIBDataSet *rds=GSM_DM->RDS;
  rds->Close();
  rds->SQLs->SelectSQL->Clear();
  AnsiString sql="select ID as SD_COD,DESCRIPTION as SD_NAME,COD_M from SUBDIVISIONS_TABLE";
  sql+=" where REC_TYPE=1";
  sql+=" order by DESCRIPTION";
  rds->SQLs->SelectSQL->Add(sql);
  try
  {
    rds->Open();
  }
  catch (Exception &exc)
  { MessageDlg("Ошибка - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
    return;
  }
  rds->First();
  while(!rds->Eof)
  { sdBox->Items->Add(rds->FieldByName("SD_NAME")->AsString);
    SD_COD->Add(rds->FieldByName("SD_COD")->AsString);
    COD_M->Add(rds->FieldByName("COD_M")->AsString);
    rds->Next();
  }
  rds->Close();
  sdBox->ItemIndex=0;
}
//---------------------------------------------------------------------------
void __fastcall TLoadDataForm::FormDestroy(TObject *Sender)
{
  if(COD_M!=NULL) delete COD_M;
  if(SD_COD!=NULL) delete SD_COD;
}
//---------------------------------------------------------------------------
void __fastcall TLoadDataForm::FormShow(TObject *Sender)
{
  DirectoryEdit->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TLoadDataForm::sdBoxChange(TObject *Sender)
{
  readDataForMemo();
}
//---------------------------------------------------------------------------
void __fastcall TLoadDataForm::readDataForMemo(void)
{
  Memo1->Clear();
  if(ADOConnection->Connected==false) return;
  AnsiString sd_name=sdBox->Items->Strings[sdBox->ItemIndex];
  AnsiString cod_m=COD_M->Strings[sdBox->ItemIndex];
  if(cod_m.IsEmpty()) return;
  //Читаем данные протокола заправок для предприятия cod_m
  ADOTable->Active=false;
  ADOTable->SQL->Clear();
  AnsiString sql="select COD_OWN,DAT from "+ExtractFileName(filename_s);
  sql+=" where COD_M="+cod_m;
  sql+=" order by DAT";
  ADOTable->SQL->Add(sql);
  try
  {
    ADOTable->Active=true;
  }
  catch (Exception &exc)
  { MessageDlg("Ошибка открытия таблицы\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
    return;
  }
  TDateTime d1, d2;
  ADOTable->First();
  d1=ADOTable->FieldByName("DAT")->AsDateTime;
  ADOTable->Last();
  d2=ADOTable->FieldByName("DAT")->AsDateTime;
  AnsiString s="Протокол заправок подразделения \""+sd_name+"\"";
  Memo1->Lines->Add(s);
  s="Период: с "+d1.DateString()+" по "+d2.DateString();
  Memo1->Lines->Add(s);
  s="Количество записей - "+IntToStr(ADOTable->RecordCount);
  Memo1->Lines->Add(s);
  LoadButton->Enabled=true;
  DateEdit1->Date=d2; DateEdit2->Date=d2;
}
//---------------------------------------------------------------------------
void __fastcall TLoadDataForm::DirectoryEditAfterDialog(TObject *Sender,
      AnsiString &Name, bool &Action)
{
AnsiString sql;

  if(!FileExists(Name+"\\mp3865.dbf"))
  { MessageDlg("Отсуствует необходимый для загрузки данных файл \"mp3865.dbf\"",mtWarning,TMsgDlgButtons() << mbOK,0);
    Action=false;
    return;
  }
  if(!FileExists(Name+"\\mt3865.dbf"))
  { MessageDlg("Отсуствует необходимый для загрузки данных файл \"mt3865.dbf\"",mtWarning,TMsgDlgButtons() << mbOK,0);
    Action=false;
    return;
  }
  if(!FileExists(Name+"\\s3865.dbf"))
  { MessageDlg("Отсуствует необходимый для загрузки данных файл \"s3865.dbf\"",mtWarning,TMsgDlgButtons() << mbOK,0);
    Action=false;
    return;
  }
  Action=true;
  filename_mp=Name+"\\mp3865.dbf";
  filename_mt=Name+"\\mt3865.dbf";
  filename_s=Name+"\\s3865.dbf";
  //Подключаемся
  AnsiString str;
  str="Provider=MSDASQL.1;";
  str+="Persist Security Info=False;";
  str+="Data Source=Файлы dBASE;";
  str+="Mode=Read;";
  str+="Extended Properties=\"DSN=Файлы dBASE;";
  str+="DBQ="+Name+";";
  str+="DefaultDir="+Name+";";
  str+="DriverId=533;MaxBufferSize=2048;PageTimeout=5;\";";
  str+="Initial Catalog="+Name;
  ADOConnection->ConnectionString=str;
  try
  {
    ADOConnection->Connected=true;
  }
  catch (Exception &exc)
  { MessageDlg("Ошибка инициализации ADO подключения\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
    return;
  }
/*
  //Ищем код автобазы в файле filename_mt
  AnsiString sd_name="";
  ADOTable->Active=false;
  ADOTable->SQL->Clear();
  sql="select NAM_M,COD_M from "+ExtractFileName(filename_mt);
  sql+=" where NAM_M like '%Автобаза%'";
  ADOTable->SQL->Add(sql);
  try
  {
    ADOTable->Active=true;
  }
  catch (Exception &exc)
  { MessageDlg("Ошибка открытия таблицы\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
    return;
  }
  if(ADOTable->RecordCount > 0)
  { sd_name=ADOTable->FieldByName("NAM_M")->AsString.Trim();
    cod_m=ADOTable->FieldByName("COD_M")->AsInteger;
  }
*/
  readDataForMemo();
//  AnsiString sd_name=sdBox->Items->Strings[sdBox->ItemIndex];
//  AnsiString cod_m=COD_M->Strings[sdBox->ItemIndex];
/*  //Читаем данные протокола заправок для предприятия cod_m
  ADOTable->Active=false;
  ADOTable->SQL->Clear();
  sql="select COD_OWN,DAT from "+ExtractFileName(filename_s);
  sql+=" where COD_M="+cod_m;
  sql+=" order by DAT";
  ADOTable->SQL->Add(sql);
  try
  {
    ADOTable->Active=true;
  }
  catch (Exception &exc)
  { MessageDlg("Ошибка открытия таблицы\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
    return;
  }
  TDateTime d1, d2;
  ADOTable->First();
  d1=ADOTable->FieldByName("DAT")->AsDateTime;
  ADOTable->Last();
  d2=ADOTable->FieldByName("DAT")->AsDateTime;
  Memo1->Clear();
  AnsiString s="Протокол заправок подразделения \""+sd_name+"\"";
  Memo1->Lines->Add(s);
  s="Период: с "+d1.DateString()+" по "+d2.DateString();
  Memo1->Lines->Add(s);
  s="Количество записей - "+IntToStr(ADOTable->RecordCount);
  Memo1->Lines->Add(s);
  LoadButton->Enabled=true;
  DateEdit1->Date=d2; DateEdit2->Date=d2;
*/
}
//---------------------------------------------------------------------------
//Загрузка данных
void __fastcall TLoadDataForm::LoadButtonClick(TObject *Sender)
{
AnsiString sql;
TpFIBQuery *RQ=GSM_DM->RQ;
TpFIBQuery *WQ=GSM_DM->WQ;
TpFIBTransaction *WT=GSM_DM->writeTransaction;
TDateTime d1=DateEdit1->Date;
TDateTime d2=DateEdit2->Date;
AnsiString sd_id=SD_COD->Strings[sdBox->ItemIndex];
AnsiString sd_name=sdBox->Items->Strings[sdBox->ItemIndex];
AnsiString cod_m=COD_M->Strings[sdBox->ItemIndex];
int count_id=0;

  if(cod_m.IsEmpty())
  { MessageDlg("Не задан код подразделения COD_M",mtWarning,TMsgDlgButtons() << mbOK,0);
    return;
  }

  //Определяем количество записей в таблице расходов за выбранный периодДля подразделения sd_cod
  RQ->Close();
  RQ->SQL->Clear();
  sql="select count(ID) as COUNT_ID from EXPENSES_TABLE where";
  sql+=" SD_ID="+sd_id;
  sql+=" and EXP_DATE>='"+d1.DateString()+"'";
  sql+=" and EXP_DATE<='"+d2.DateString()+"'";

  RQ->SQL->Add(sql);
  try
  {
    RQ->ExecQuery();
  }
  catch (Exception &exc)
  { MessageDlg("Ошибка - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
    return;
  }
  count_id=RQ->FieldByName("COUNT_ID")->AsInteger;
  if(count_id > 0)
  { if(MessageDlg("Внимание!!! Все записи в таблице расходов ГСМ за выбранные период будут удалены и на их место будут загружены данные из файла с протоколом заправок.\nПродолжить загрузку?",mtConfirmation,TMsgDlgButtons() << mbOK << mbCancel,0)==mrCancel)
      return;
  }
  RQ->Close();

  ADOTable->Active=false;
  ADOTable->SQL->Clear();
  sql="select s.VOLUM,s.DAT,s.SESORT, m.FIO_OWN,m.EK_N";
  sql+=" from "+ExtractFileName(filename_s)+" s";
  sql+=" left outer join "+ExtractFileName(filename_mp)+" m on m.COD_OWN=s.COD_OWN";
  sql+=" where s.COD_M="+cod_m;
  sql+=" and s.DAT>="+IntToStr(int(DateEdit1->Date));
  sql+=" and s.DAT<="+IntToStr(int(DateEdit2->Date));
  sql+=" order by s.DAT, m.EK_N";
  ADOTable->SQL->Add(sql);
  GetAsyncKeyState(VK_ESCAPE);
  try
  {
    ADOTable->Active=true;
  }
  catch (Exception &exc)
  { MessageDlg("Ошибка - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
    return;
  }

  //Стартуем транзакцию
  WT->StartTransaction();

  if(count_id > 0)
  { //Удаляем данные из таблицы EXPENSES_TABLE за выбранный период
    WQ->Close();
    WQ->SQL->Clear();
    sql="delete from EXPENSES_TABLE where";
    sql+=" SD_ID="+sd_id;
    sql+=" and EXP_DATE>='"+d1.DateString()+"'";
    sql+=" and EXP_DATE<='"+d2.DateString()+"'";
    WQ->SQL->Add(sql);
    try
    {
      WQ->ExecQuery();
    }
    catch (Exception &exc)
    { MessageDlg("Ошибка - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      WT->Rollback();
      return;
    }
  }

  //Грузим данные из протокола заправки
  ADOTable->Last();
  ProgressBar->Max=ADOTable->RecordCount;
  ProgressBar->Position=0;
  ADOTable->First();
  GetAsyncKeyState(VK_ESCAPE);
  while(!ADOTable->Eof)
  { double expense=ADOTable->FieldByName("VOLUM")->AsFloat;
    TDateTime exp_date=ADOTable->FieldByName("DAT")->AsDateTime;
    AnsiString gsm_description=ADOTable->FieldByName("SESORT")->AsString.Trim();
    AnsiString auto_description=ADOTable->FieldByName("FIO_OWN")->AsString.Trim();
    AnsiString ec_description=ADOTable->FieldByName("EK_N")->AsString.Trim();
    int ec_id=0;
    int auto_id=0;
    int driver_id=0;
    int gsm_id=0;

    //Ищем запись в справочнике ГСМ по марке
    WQ->Close();
    WQ->SQL->Clear();
    sql="select ID from GSM_TABLE where DESCRIPTION like '"+gsm_description+"'";
    WQ->SQL->Add(sql);
    try
    {
      WQ->ExecQuery();
    }
    catch (Exception &exc)
    { MessageDlg("Ошибка - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      WT->Rollback();
      return;
    }
    if(WQ->RecordCount == 0) //создаем новую запись в таблице GSM_TABLE
    { TURB *GSM_RB=MainForm->getGSM_RB();
      if(GSM_RB==NULL)
      { WT->Rollback();
        return;
      }
      AnsiString id=GSM_RB->getNewRB_KeyValue();
      AnsiString root_id=GSM_RB->getRootSectionID();
      delete GSM_RB; GSM_RB=NULL;
      if(id.IsEmpty())
      { MessageDlg("Ошибка создания новой записи в таблице GSM_TABLE",mtError,TMsgDlgButtons() << mbOK,0);
        WT->Rollback();
        return;
      }
      WQ->Close();
      WQ->SQL->Clear();
      sql="insert into GSM_TABLE(ID,FILE_ID,REC_TYPE,DESCRIPTION) values(";
      sql+=id+",";
      sql+=root_id+",1,";
      sql+="'"+gsm_description+"')";
      WQ->SQL->Add(sql);
      try
      {
        WQ->ExecQuery();
      }
      catch (Exception &exc)
      { MessageDlg("Ошибка - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
        WT->Rollback();
        return;
      }
      gsm_id=StrToInt(id);
    }
    else gsm_id=WQ->FieldByName("ID")->AsInteger;

    //Ищем запись в справочнике автомобилей по номеру автомобиля
    WQ->Close();
    WQ->SQL->Clear();
    sql="select ID from AUTO_TABLE where DESCRIPTION like '%"+auto_description+"%'";
    sql+=" and SD_ID="+sd_id;
    WQ->SQL->Add(sql);
    try
    {
      WQ->ExecQuery();
    }
    catch (Exception &exc)
    { MessageDlg("Ошибка - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      WT->Rollback();
      return;
    }
    if(WQ->RecordCount == 0) //создаем новую запись в таблице AUTO_TABLE
    { TURB *Auto_RB=MainForm->getAuto_RB(sd_name);
      if(Auto_RB==NULL)
      { WT->Rollback();
        return;
      }
      AnsiString id=Auto_RB->getNewRB_KeyValue();
      AnsiString folder_id=Auto_RB->getFolderIDByName(sd_name);
      if(folder_id.IsEmpty())
      { AnsiString parent_id=Auto_RB->getRootSectionID();
        folder_id=Auto_RB->createFolderByName(parent_id,sd_name);
      }
      delete Auto_RB; Auto_RB=NULL;
      if(folder_id.IsEmpty())
      { MessageDlg("Ошибка создания новой папки в таблице AUTO_TABLE",mtError,TMsgDlgButtons() << mbOK,0);
        WT->Rollback();
        return;
      }
      if(id.IsEmpty())
      { MessageDlg("Ошибка создания новой записи в таблице AUTO_TABLE",mtError,TMsgDlgButtons() << mbOK,0);
        WT->Rollback();
        return;
      }
      int distination_id=0;
      AnsiString distination="Основная деятельность";
      if(auto_description.Pos("Б/H")>0 || auto_description.Pos("б/н")>0) distination="Внутренние работы";
      //Ищем запись в таблице назаначений
      WQ->Close();
      WQ->SQL->Clear();
      sql="select ID from DISTINATIONS_TABLE where DESCRIPTION like '%"+distination+"%'";
      WQ->SQL->Add(sql);
      try
      {
        WQ->ExecQuery();
      }
      catch (Exception &exc)
      { MessageDlg("Ошибка - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
        WT->Rollback();
        return;
      }
      if(WQ->RecordCount > 0) distination_id=WQ->FieldByName("ID")->AsInteger;
      WQ->Close();
      WQ->SQL->Clear();
      sql="insert into AUTO_TABLE(ID,FILE_ID,REC_TYPE,DESCRIPTION,SD_ID,GSM_ID,DISTINATION) values(";
      sql+=id+",";
      sql+=folder_id+",1,";
      sql+="'"+auto_description+"',";
      sql+=sd_id+",";
      sql+=IntToStr(gsm_id)+",";
      sql+=IntToStr(distination_id)+")";
      WQ->SQL->Add(sql);
      try
      {
        WQ->ExecQuery();
      }
      catch (Exception &exc)
      { MessageDlg("Ошибка - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
        WT->Rollback();
        return;
      }
      auto_id=StrToInt(id);
    }
    else auto_id=WQ->FieldByName("ID")->AsInteger;
    //Пробуем найти водителя по автомобилю
    WQ->Close();
    WQ->SQL->Clear();
    sql="select DRIVER_ID from AUTO_TABLE where ID="+IntToStr(auto_id);
    WQ->SQL->Add(sql);
    try
    {
      WQ->ExecQuery();
    }
    catch (Exception &exc)
    { MessageDlg("Ошибка - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      WT->Rollback();
      return;
    }
    if(WQ->RecordCount > 0) driver_id=WQ->FieldByName("DRIVER_ID")->AsInteger;

    //Ищем запись в справочнике электронных карт по номеру карты
    WQ->Close();
    WQ->SQL->Clear();
    sql="select ID from ELECTRONIC_CARDS_TABLE where DESCRIPTION like '%"+ec_description+"%'";
    sql+=" and SD_ID="+sd_id;
    WQ->SQL->Add(sql);
    try
    {
      WQ->ExecQuery();
    }
    catch (Exception &exc)
    { MessageDlg("Ошибка - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      WT->Rollback();
      return;
    }
    if(WQ->RecordCount == 0) //создаем новую запись в таблице ELECTRONIC_CARDS_TABLE
    { TURB *EC_RB=MainForm->getElectronicCards_RB(sd_name);
      if(EC_RB==NULL)
      { WT->Rollback();
        return;
      }
      AnsiString id=EC_RB->getNewRB_KeyValue();
      AnsiString folder_id=EC_RB->getFolderIDByName(sd_name);
      if(folder_id.IsEmpty())
      { AnsiString parent_id=EC_RB->getRootSectionID();
        folder_id=EC_RB->createFolderByName(parent_id,sd_name);
      }
      delete EC_RB; EC_RB=NULL;
      if(folder_id.IsEmpty())
      { MessageDlg("Ошибка создания новой папки в таблице ELECTRONIC_CARDS_TABLE",mtError,TMsgDlgButtons() << mbOK,0);
        WT->Rollback();
        return;
      }
      if(id.IsEmpty())
      { MessageDlg("Ошибка создания новой записи в таблице ELECTRONIC_CARDS_TABLE",mtError,TMsgDlgButtons() << mbOK,0);
        WT->Rollback();
        return;
      }

      WQ->Close();
      WQ->SQL->Clear();
      sql="insert into ELECTRONIC_CARDS_TABLE(ID,FILE_ID,REC_TYPE,DESCRIPTION,SD_ID,AUTO_ID) values(";
      sql+=id+",";
      sql+=folder_id+",1,";
      sql+="'"+ec_description+"',";
      sql+=sd_id+",";
      sql+=IntToStr(auto_id)+")";
      WQ->SQL->Add(sql);
      try
      {
        WQ->ExecQuery();
      }
      catch (Exception &exc)
      { MessageDlg("Ошибка - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
        WT->Rollback();
        return;
      }
      ec_id=StrToInt(id);
    }
    else ec_id=WQ->FieldByName("ID")->AsInteger;

    //Создаем запись в таблице расходов ГСМ - EXPENSES_TABLE
    WQ->Close();
    WQ->SQL->Clear();
    sql="insert into EXPENSES_TABLE(ID,EXP_DATE,SD_ID,EC_ID,AUTO_ID,DRIVER_ID,GSM_ID,EXPENSE) values(";
    sql+="GEN_ID(GEN_EXPENSES_TABLE_ID,1),";
    sql+="'"+exp_date.DateString()+"',";
    sql+=sd_id+",";
    sql+=IntToStr(ec_id)+",";
    sql+=IntToStr(auto_id)+",";
    sql+=IntToStr(driver_id)+",";
    sql+=IntToStr(gsm_id)+",";
    sql+=FloatToStr(expense)+")";
    WQ->SQL->Add(sql);
    try
    {
      WQ->ExecQuery();
    }
    catch (Exception &exc)
    { MessageDlg("Ошибка - "+sql+"\n"+exc.Message,mtError,TMsgDlgButtons() << mbOK,0);
      WT->Rollback();
      return;
    }

    ADOTable->Next();
    ProgressBar->StepIt();
    if((GetAsyncKeyState(VK_ESCAPE) << 1)!=0)
    { MessageDlg("Прекратить обработку файла?",mtConfirmation,TMsgDlgButtons() << mbYes << mbNo,0);
      if(MessageDlg("Прекратить обработку файла?",mtConfirmation,TMsgDlgButtons() << mbYes << mbNo,0) == mrYes)
      { WT->Rollback();
        return;
      }
    }
  }
  WT->Commit();
  ADOTable->Close();
  WQ->Close();
  WQ->Close();
  ProgressBar->Position=0;
  MessageDlg("Операция успешно завершена",mtInformation,TMsgDlgButtons() << mbOK,0);
  Close();
  ModalResult=mrOk;
}
//---------------------------------------------------------------------------

