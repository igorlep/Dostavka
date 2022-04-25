object RestoreBaseForm: TRestoreBaseForm
  Left = 558
  Top = 623
  Width = 624
  Height = 349
  Caption = #1059#1095#1077#1090' '#1086#1087#1077#1088#1072#1094#1080#1081'. '#1042#1086#1089#1089#1090#1072#1085#1086#1074#1083#1077#1085#1080#1077' '#1073#1072#1079#1099' '#1076#1072#1085#1085#1099#1093' '#1080#1079' '#1072#1088#1093#1080#1074#1072
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -13
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Scaled = False
  OnClose = FormClose
  PixelsPerInch = 96
  TextHeight = 16
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 608
    Height = 161
    Align = alTop
    BevelOuter = bvNone
    TabOrder = 0
    DesignSize = (
      608
      161)
    object Label1: TLabel
      Left = 24
      Top = 24
      Width = 569
      Height = 16
      Anchors = [akLeft, akTop, akRight]
      AutoSize = False
      Caption = #1048#1084#1103' '#1092#1072#1081#1083#1072' '#1089' '#1072#1088#1093#1080#1074#1086#1084' (*.zip '#1080#1083#1080' *.gbk)'
    end
    object Label2: TLabel
      Left = 0
      Top = 0
      Width = 608
      Height = 16
      Align = alTop
      Alignment = taCenter
      Caption = 'Label2'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label3: TLabel
      Left = 24
      Top = 72
      Width = 569
      Height = 16
      Anchors = [akLeft, akTop, akRight]
      AutoSize = False
      Caption = #1057#1077#1090#1077#1074#1086#1077' '#1080#1084#1103' '#1073#1072#1079#1099' '#1076#1072#1085#1085#1099#1093
    end
    object FilenameEdit: TFilenameEdit
      Left = 24
      Top = 40
      Width = 569
      Height = 21
      OnAfterDialog = FilenameEditAfterDialog
      Filter = #1040#1088#1093#1080#1074#1085#1099#1081' '#1092#1072#1081#1083'  (*.zip)|*.zip|BackUp '#1092#1072#1081#1083' (*.gbk)|*.gbk'
      Anchors = [akLeft, akTop, akRight]
      NumGlyphs = 1
      TabOrder = 0
    end
    object CheckBox1: TCheckBox
      Left = 56
      Top = 122
      Width = 169
      Height = 17
      Caption = #1074#1077#1089#1090#1080' '#1087#1088#1086#1090#1086#1082#1086#1083
      TabOrder = 1
    end
    object NetFilenameEdit: TFilenameEdit
      Left = 24
      Top = 88
      Width = 569
      Height = 21
      OnAfterDialog = NetFilenameEditAfterDialog
      Filter = #1060#1072#1081#1083' '#1073#1072#1079#1099' '#1076#1072#1085#1085#1099#1093'  (*.gdb)|*.gdb'
      Anchors = [akLeft, akTop, akRight]
      NumGlyphs = 1
      TabOrder = 2
    end
    object RestoreButton: TBitBtn
      Left = 392
      Top = 122
      Width = 115
      Height = 25
      Anchors = [akTop, akRight]
      Caption = #1042#1099#1087#1086#1083#1085#1080#1090#1100
      Enabled = False
      TabOrder = 3
      OnClick = RestoreButtonClick
      Glyph.Data = {
        F6000000424DF600000000000000760000002800000010000000100000000100
        0400000000008000000000000000000000001000000000000000000000000000
        8000008000000080800080000000800080008080000080808000C0C0C0000000
        FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00FFFFFF0B7FFF
        FFB0FFFFFF0B7FFFFFB0FFFFFF0B7FFFFFB0FFFFFF0B7FFFFFB0000000000077
        00700FFFFFFFF00077B00FFFFFFFF00077B00000F000F00000070FFFFFFFF0FF
        99FF000000F0F9FF99FF0FFFFFF799F799FF0000F779999999FF0FFFF7999999
        99FF0077F0F9999999FF0FFFF0F799FFFFFF0000000FF9FFFFFF}
    end
    object ExitButton: TBitBtn
      Left = 520
      Top = 122
      Width = 75
      Height = 25
      Anchors = [akTop, akRight]
      Caption = #1042#1099#1093#1086#1076
      TabOrder = 4
      OnClick = ExitButtonClick
      Glyph.Data = {
        F6000000424DF600000000000000760000002800000010000000100000000100
        0400000000008000000000000000000000001000000000000000000000000000
        8000008000000080800080000000800080008080000080808000C0C0C0000000
        FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00FFF00FF00F08
        0070F00FF00FF00870070000000008087700FFFFFF0880087770FFFFFF000008
        7770FFFFFF0777087770FFFFFF0777087770FF00000007080770FF0999990708
        7770F099999077087770F090990777087770F000900777087770FFF00F077770
        8770FFFFFF0777770870FFFFFF0777777080FFFFFF0000000000}
    end
  end
  object RichEdit1: TRxRichEdit
    Left = 0
    Top = 161
    Width = 608
    Height = 150
    Align = alClient
    TabOrder = 1
    WordWrap = False
  end
  object FormStorage1: TFormStorage
    IniFileName = '.\Avia'#0'ini'
    IniSection = 'RestoreBaseForm'
    StoredValues = <>
    Left = 176
    Top = 168
  end
  object RestoreService: TpFIBRestoreService
    PageSize = 0
    PageBuffers = 0
    Left = 216
    Top = 168
  end
end
