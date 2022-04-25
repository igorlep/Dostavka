object LoadDataForm: TLoadDataForm
  Left = 228
  Top = 119
  Width = 349
  Height = 353
  Caption = #1047#1072#1075#1088#1091#1079#1082#1072' '#1076#1072#1085#1085#1099#1093' '#1080#1079' '#1092#1072#1081#1083#1072
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnDestroy = FormDestroy
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Panel2: TPanel
    Left = 0
    Top = 278
    Width = 341
    Height = 41
    Align = alBottom
    BevelOuter = bvNone
    BorderStyle = bsSingle
    Ctl3D = False
    ParentCtl3D = False
    TabOrder = 0
    DesignSize = (
      339
      39)
    object LoadButton: TBitBtn
      Left = 221
      Top = 8
      Width = 106
      Height = 25
      Anchors = [akTop, akRight]
      Caption = #1047#1072#1075#1088#1091#1079#1080#1090#1100
      TabOrder = 0
      OnClick = LoadButtonClick
      Glyph.Data = {
        F6000000424DF600000000000000760000002800000010000000100000000100
        0400000000008000000000000000000000001000000000000000000000000000
        8000008000000080800080000000800080008080000080808000C0C0C0000000
        FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00FFFFFF0FFFFF
        FFF0FFFFFF0F0000F0F0FFFFFF0FFFFFFFF0F000000007F000000BBBBBBBB0F0
        FF0F0B77777BB0F0F0FF0B7FFFFFB0F00FFF0B7FFFFFB0009FFF0B7FFFFFB039
        99FF0B7FFFFFB099999F0B7FFFFFB99999990B7FFFFFB0F999FF0700770070F9
        99FF0B770077B0F999FF0BB7007BB9999FFF700000000FFFFFFF}
    end
  end
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 341
    Height = 278
    Align = alClient
    BevelOuter = bvNone
    Ctl3D = False
    ParentCtl3D = False
    TabOrder = 1
    DesignSize = (
      341
      278)
    object Label1: TLabel
      Left = 24
      Top = 24
      Width = 296
      Height = 13
      Anchors = [akLeft, akTop, akRight]
      AutoSize = False
      Caption = #1055#1072#1087#1082#1072' '#1089' '#1080#1089#1093#1086#1076#1085#1099#1084#1080' '#1092#1072#1081#1083#1072#1084#1080
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label2: TLabel
      Left = 24
      Top = 164
      Width = 201
      Height = 17
      Anchors = [akLeft, akBottom]
      AutoSize = False
      Caption = #1047#1072#1075#1088#1091#1079#1080#1090#1100' '#1076#1072#1085#1085#1099#1077
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      Layout = tlCenter
      WordWrap = True
    end
    object DirectoryEdit: TJvDotNetDirectoryEdit
      Left = 24
      Top = 38
      Width = 296
      Height = 19
      OnAfterDialog = DirectoryEditAfterDialog
      DialogKind = dkWin32
      Flat = True
      ParentCtl3D = False
      DirectInput = False
      Anchors = [akLeft, akTop, akRight]
      TabOrder = 0
      Text = 'DirectoryEdit'
    end
    object Memo1: TMemo
      Left = 24
      Top = 64
      Width = 300
      Height = 93
      Anchors = [akLeft, akTop, akRight, akBottom]
      Constraints.MinHeight = 50
      Constraints.MinWidth = 300
      Ctl3D = False
      Lines.Strings = (
        'Memo1')
      ParentCtl3D = False
      TabOrder = 1
    end
    object ProgressBar: TJvProgressBar
      Left = 0
      Top = 261
      Width = 341
      Height = 17
      Align = alBottom
      Min = 0
      Max = 100
      Step = 1
      TabOrder = 2
    end
    object Panel3: TPanel
      Left = 24
      Top = 180
      Width = 297
      Height = 65
      Anchors = [akLeft, akRight, akBottom]
      BevelOuter = bvNone
      BorderStyle = bsSingle
      Ctl3D = False
      ParentCtl3D = False
      TabOrder = 3
      DesignSize = (
        295
        63)
      object Label3: TLabel
        Left = 8
        Top = 10
        Width = 81
        Height = 13
        AutoSize = False
        Caption = #1079#1072' '#1087#1077#1088#1080#1086#1076' '#1089
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Label4: TLabel
        Left = 176
        Top = 10
        Width = 25
        Height = 13
        Alignment = taCenter
        AutoSize = False
        Caption = #1087#1086
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Label5: TLabel
        Left = 8
        Top = 36
        Width = 121
        Height = 13
        AutoSize = False
        Caption = #1087#1086' '#1087#1086#1076#1088#1072#1079#1076#1077#1083#1077#1085#1080#1102
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object DateEdit1: TJvDateEdit
        Left = 88
        Top = 8
        Width = 86
        Height = 19
        Date = 39783
        ButtonFlat = True
        Flat = True
        ParentCtl3D = False
        TabOrder = 0
      end
      object DateEdit2: TJvDateEdit
        Left = 200
        Top = 8
        Width = 86
        Height = 19
        ButtonFlat = True
        Flat = True
        ParentCtl3D = False
        TabOrder = 1
      end
      object sdBox: TComboBox
        Left = 128
        Top = 32
        Width = 158
        Height = 21
        BevelInner = bvNone
        BevelKind = bkFlat
        BevelOuter = bvRaised
        Anchors = [akLeft, akTop, akRight]
        ItemHeight = 13
        TabOrder = 2
        Text = 'sdBox'
        OnChange = sdBoxChange
      end
    end
  end
  object FormStorage: TFormStorage
    StoredValues = <>
    Left = 224
    Top = 8
  end
  object ADOConnection: TADOConnection
    LoginPrompt = False
    Mode = cmRead
    Provider = 'MSDASQL.1'
    Left = 256
    Top = 8
  end
  object ADOTable: TADOQuery
    Connection = ADOConnection
    CursorType = ctStatic
    Parameters = <>
    SQL.Strings = (
      'select * from tirved.dbf')
    Left = 288
    Top = 8
  end
end
