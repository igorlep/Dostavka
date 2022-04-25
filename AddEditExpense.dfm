object AddEditExpenseForm: TAddEditExpenseForm
  Left = 942
  Top = 222
  Width = 290
  Height = 344
  BorderIcons = [biSystemMenu]
  Caption = #1057#1074#1077#1076#1077#1085#1080#1103' '#1086#1073' '#1086#1087#1077#1088#1072#1094#1080#1081
  Color = clWindow
  Ctl3D = False
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -13
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Scaled = False
  OnDestroy = FormDestroy
  OnShow = FormShow
  PixelsPerInch = 120
  TextHeight = 16
  object Header: TJvNavPanelHeader
    Left = 0
    Top = 0
    Width = 272
    Align = alTop
    Alignment = taCenter
    Caption = 'Header'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clTeal
    Font.Height = -17
    Font.Name = 'Arial'
    Font.Style = [fsBold]
    ParentFont = False
    ColorFrom = clMoneyGreen
    ColorTo = 16776176
    ImageIndex = 0
  end
  object Panel1: TPanel
    Left = 0
    Top = 27
    Width = 272
    Height = 272
    Align = alClient
    BevelOuter = bvNone
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    TabOrder = 1
    DesignSize = (
      272
      272)
    object Label1: TLabel
      Left = 16
      Top = 22
      Width = 97
      Height = 16
      AutoSize = False
      Caption = #1050#1086#1076
    end
    object Label4: TLabel
      Left = 16
      Top = 50
      Width = 98
      Height = 15
      AutoSize = False
      Caption = #1054#1055#1057
    end
    object JvBevel1: TJvBevel
      Left = 16
      Top = 91
      Width = 247
      Height = 118
      Anchors = [akLeft, akTop, akRight]
      Shape = bsFrame
    end
    object Label8: TLabel
      Left = 16
      Top = 70
      Width = 65
      Height = 15
      AutoSize = False
      Caption = ' '#1054#1087#1077#1088#1072#1094#1080#1103
    end
    object idLabel: TLabel
      Left = 128
      Top = 20
      Width = 57
      Height = 16
      AutoSize = False
      Caption = 'idLabel'
    end
    object Bevel1: TBevel
      Left = 120
      Top = 18
      Width = 65
      Height = 21
      Shape = bsFrame
    end
    object Label5: TLabel
      Left = 32
      Top = 98
      Width = 65
      Height = 16
      AutoSize = False
      Caption = #1058#1080#1087
    end
    object Label6: TLabel
      Left = 32
      Top = 181
      Width = 65
      Height = 16
      AutoSize = False
      Caption = #1057#1091#1084#1084#1072
    end
    object Label7: TLabel
      Left = 32
      Top = 124
      Width = 65
      Height = 16
      AutoSize = False
      Caption = #1044#1072#1090#1072
    end
    object Label3: TLabel
      Left = 32
      Top = 155
      Width = 34
      Height = 13
      Caption = #1050#1086#1083'-'#1074#1086
    end
    object driverEdit: TComboEdit
      Left = 120
      Top = 48
      Width = 146
      Height = 20
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      GlyphKind = gkEllipsis
      ButtonWidth = 18
      Anchors = [akLeft, akTop, akRight]
      NumGlyphs = 1
      ParentFont = False
      TabOrder = 0
      Text = 'driverEdit'
      OnButtonClick = driverEditButtonClick
      OnKeyDown = driverEditKeyDown
      OnKeyPress = driverEditKeyPress
    end
    object SaveButton: TJvBitBtn
      Left = 45
      Top = 242
      Width = 105
      Height = 25
      Anchors = [akTop, akRight]
      Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100
      TabOrder = 3
      OnClick = SaveButtonClick
      Glyph.Data = {
        F6000000424DF600000000000000760000002800000010000000100000000100
        0400000000008000000000000000000000001000000000000000000000000000
        8000008000000080800080000000800080008080000080808000C0C0C0000000
        FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00888888888888
        8888880000000000000880330000008803088033000000880308803300000088
        0308803300000000030880333333333333088033000000003308803088888888
        0308803088888888030880308888888803088030888888880308803088888888
        0008803088888888080880000000000000088888888888888888}
      HotTrackFont.Charset = DEFAULT_CHARSET
      HotTrackFont.Color = clWindowText
      HotTrackFont.Height = -11
      HotTrackFont.Name = 'MS Sans Serif'
      HotTrackFont.Style = []
    end
    object CancelButton: TJvBitBtn
      Left = 161
      Top = 242
      Width = 105
      Height = 25
      Anchors = [akTop, akRight]
      Caption = #1054#1090#1082#1072#1079#1072#1090#1100#1089#1103
      TabOrder = 4
      OnClick = CancelButtonClick
      Glyph.Data = {
        F6000000424DF600000000000000760000002800000010000000100000000100
        0400000000008000000000000000000000001000000000000000000000000000
        8000008000000080800080000000800080008080000080808000C0C0C0000000
        FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00888888888888
        8888888888888888888888818888888888988899188888888888889991888888
        8988888999888888988888889918888998888888899188998888888888999998
        8888888888899988888888888899991888888888899988918888888999988889
        1888889999888888998888999888888888988888888888888888}
      HotTrackFont.Charset = DEFAULT_CHARSET
      HotTrackFont.Color = clWindowText
      HotTrackFont.Height = -11
      HotTrackFont.Name = 'MS Sans Serif'
      HotTrackFont.Style = []
    end
    object gsmEdit: TComboEdit
      Left = 105
      Top = 96
      Width = 145
      Height = 21
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      GlyphKind = gkEllipsis
      ButtonWidth = 18
      Anchors = [akLeft, akTop, akRight]
      NumGlyphs = 1
      ParentFont = False
      TabOrder = 1
      Text = 'gsmEdit'
      OnButtonClick = gsmEditButtonClick
      OnChange = gsmEditChange
      OnKeyDown = gsmEditKeyDown
      OnKeyPress = gsmEditKeyPress
    end
    object expDateEdit: TDateEdit
      Left = 104
      Top = 122
      Width = 112
      Height = 21
      ClickKey = 45
      DialogTitle = #1042#1099#1073#1086#1088' '#1076#1072#1090#1099
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      NumGlyphs = 2
      ParentFont = False
      TabOrder = 2
      OnChange = expDateEditChange
      OnKeyDown = expDateEditKeyDown
      OnKeyPress = expDateEditKeyPress
    end
    object expEdit: TJvValidateEdit
      Left = 104
      Top = 179
      Width = 113
      Height = 19
      Alignment = taLeftJustify
      CriticalPoints.CheckPoints = cpNone
      CriticalPoints.ColorAbove = clBlue
      CriticalPoints.ColorBelow = clRed
      TrimDecimals = True
      DisplayFormat = dfNone
      DecimalPlaces = 3
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 5
      Value = ''
      OnChange = expEditChange
      OnEnter = expEditEnter
      OnExit = expEditExit
      OnKeyDown = expEditKeyDown
      OnKeyPress = expEditKeyPress
    end
    object Kol: TJvValidateEdit
      Left = 104
      Top = 155
      Width = 113
      Height = 19
      Alignment = taLeftJustify
      CriticalPoints.CheckPoints = cpNone
      CriticalPoints.ColorAbove = clBlue
      CriticalPoints.ColorBelow = clRed
      DisplayFormat = dfNone
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 6
      Value = ''
      ZeroEmpty = True
      OnChange = KolChange
      OnKeyDown = KolKeyDown
      OnKeyPress = KolKeyPress
    end
    object CheckBox1: TCheckBox
      Left = 96
      Top = 216
      Width = 137
      Height = 17
      Caption = #1044#1086#1087#1086#1083#1085#1080#1090#1077#1083#1100#1085#1086
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 7
      Visible = False
      OnClick = CheckBox1Click
    end
  end
  object FormStorage: TFormStorage
    StoredValues = <>
    Left = 48
  end
end
