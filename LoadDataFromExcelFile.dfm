object LoadDataFromExcelFileForm: TLoadDataFromExcelFileForm
  Left = 385
  Top = 113
  Width = 419
  Height = 319
  Caption = #1047#1072#1075#1088#1091#1079#1082#1072' '#1076#1072#1085#1085#1099#1093' '#1080#1079' Excel '#1092#1072#1081#1083#1072
  Color = clWindow
  Ctl3D = False
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Scaled = False
  PixelsPerInch = 96
  TextHeight = 13
  object buttonPanel: TPanel
    Left = 0
    Top = 247
    Width = 411
    Height = 38
    Align = alBottom
    BevelOuter = bvNone
    Ctl3D = False
    ParentCtl3D = False
    TabOrder = 0
    DesignSize = (
      411
      38)
    object loadButton: TJvXPButton
      Left = 255
      Top = 8
      Width = 137
      Caption = #1047#1072#1075#1088#1091#1079#1080#1090#1100' '#1076#1072#1085#1085#1099#1077
      Enabled = False
      TabOrder = 0
      Glyph.Data = {
        F6000000424DF600000000000000760000002800000010000000100000000100
        0400000000008000000000000000000000001000000000000000000000000000
        8000008000000080800080000000800080008080000080808000C0C0C0000000
        FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00FFFFFF0B7FFF
        FFB0FFFFFF0B7FFFFFB0FFFFFF0B7FFFFFB0FFFFFF0B7FFFFFB0000000000077
        00700FFFFFFFF00077B00FFFFFFFF00077B00000F000F00090070FFFFFFFF0F9
        99FF000000F0F099999F0FFFFFFFF99999990000F00000F999FF0FFFF0FF0FF9
        99FF0077F0FF0FF999FF0FFFF0F0FF7999FF0000000F999999FF}
      Anchors = [akTop, akRight]
      OnClick = loadButtonClick
    end
  end
  object workPanel: TPanel
    Left = 0
    Top = 0
    Width = 411
    Height = 247
    Align = alClient
    BevelOuter = bvNone
    TabOrder = 1
    DesignSize = (
      411
      247)
    object Label1: TLabel
      Left = 20
      Top = 16
      Width = 366
      Height = 13
      Anchors = [akLeft, akTop, akRight]
      AutoSize = False
      Caption = #1060#1072#1081#1083' '#1089' '#1080#1089#1093#1086#1076#1085#1099#1084#1080' '#1076#1072#1085#1085#1099#1084#1080
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label2: TLabel
      Left = 20
      Top = 166
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
    object filenameEdit: TJvFilenameEdit
      Left = 20
      Top = 30
      Width = 371
      Height = 19
      OnAfterDialog = filenameEditAfterDialog
      ButtonFlat = True
      ButtonWidth = 19
      Anchors = [akLeft, akTop, akRight]
      TabOrder = 0
      Text = 'filenameEdit'
    end
    object memo: TMemo
      Left = 20
      Top = 56
      Width = 371
      Height = 101
      Anchors = [akLeft, akTop, akRight, akBottom]
      Constraints.MinHeight = 50
      Constraints.MinWidth = 300
      Ctl3D = False
      Lines.Strings = (
        'memo')
      ParentCtl3D = False
      TabOrder = 1
    end
    object Panel3: TPanel
      Left = 20
      Top = 182
      Width = 371
      Height = 65
      Anchors = [akLeft, akRight, akBottom]
      BevelOuter = bvNone
      BorderStyle = bsSingle
      Ctl3D = False
      ParentCtl3D = False
      TabOrder = 2
      DesignSize = (
        369
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
        Width = 81
        Height = 13
        AutoSize = False
        Caption = #1087#1086' '#1082#1072#1088#1090#1077
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object fromDateEdit: TJvDateEdit
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
      object toDateEdit: TJvDateEdit
        Left = 200
        Top = 8
        Width = 86
        Height = 19
        ButtonFlat = True
        Flat = True
        ParentCtl3D = False
        TabOrder = 1
      end
      object cardNumberBox: TComboBox
        Left = 88
        Top = 32
        Width = 270
        Height = 21
        BevelInner = bvNone
        BevelKind = bkFlat
        BevelOuter = bvRaised
        Anchors = [akLeft, akTop, akRight]
        ItemHeight = 13
        TabOrder = 2
        Text = 'cardNumberBox'
      end
    end
  end
  object FormStorage: TFormStorage
    StoredValues = <>
    Left = 200
  end
end
