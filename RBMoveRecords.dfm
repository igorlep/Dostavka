object RBMoveRecordsForm: TRBMoveRecordsForm
  Left = 212
  Top = 172
  Width = 393
  Height = 439
  BorderIcons = [biSystemMenu]
  Caption = #1055#1077#1088#1077#1085#1086#1089' ('#1082#1086#1087#1080#1088#1086#1074#1072#1085#1080#1077') '#1079#1072#1087#1080#1089#1077#1081
  Color = clWindow
  Ctl3D = False
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -13
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Scaled = False
  OnResize = FormResize
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 16
  object SmrtPanel2: TSmrtPanel
    Left = 0
    Top = 364
    Width = 385
    Height = 41
    Align = alBottom
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    TabOrder = 0
    DesignSize = (
      385
      41)
    object MoveButton: TBitBtn
      Left = 148
      Top = 8
      Width = 117
      Height = 25
      Anchors = [akTop, akRight]
      Caption = #1055#1077#1088#1077#1085#1077#1089#1090#1080
      TabOrder = 0
      OnClick = MoveButtonClick
      Glyph.Data = {
        F6000000424DF600000000000000760000002800000010000000100000000100
        0400000000008000000000000000000000001000000000000000000000000000
        80000080000000808000800000008000800080800000C0C0C000808080000000
        FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00700000000000
        0000700000CACCCCCCC0222222AA0FFFFFC022222AAA00000FC02A22AAAAAAAA
        0FC02A2AAAAAAAAA0FC02A22AAAAAAAA0FC02A222AAA00000FC02A2222AA0FFF
        FFC02A2222CA0F000FC02AA222CFFFFFFFC02AAA22CCCCCCCCC02AAAA2222222
        7777222222222222777722222777777777772222777777777777}
    end
    object CancelButton: TBitBtn
      Left = 270
      Top = 8
      Width = 107
      Height = 25
      Anchors = [akTop, akRight]
      Caption = #1054#1090#1082#1072#1079#1072#1090#1100#1089#1103
      TabOrder = 1
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
    end
    object CopyButton: TBitBtn
      Left = 30
      Top = 8
      Width = 113
      Height = 25
      Anchors = [akTop, akRight]
      Caption = #1050#1086#1087#1080#1088#1086#1074#1072#1090#1100
      TabOrder = 2
      OnClick = CopyButtonClick
      Glyph.Data = {
        F6000000424DF600000000000000760000002800000010000000100000000100
        0400000000008000000000000000000000001000000000000000000000000000
        8000008000000080800080000000800080008080000080808000C0C0C0000000
        FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00888888888888
        88888888888888888888888888CCCCCCCCC8888888CFFFFFFFC8888888CF0000
        0FC8777777CFFFFFFFC87FFFFFCF00000FC87F7777CFFFFFFFC87FFFFFCF00FC
        CCC87F7777CFFFFCFC887FFFFFCFFFFCC8887F77F7CCCCCC88887FFFF7F78888
        88887FFFF7788888888877777788888888888888888888888888}
    end
  end
  object RichEdit: TRichEdit
    Left = 0
    Top = 0
    Width = 385
    Height = 49
    TabStop = False
    Align = alTop
    Alignment = taCenter
    BevelOuter = bvNone
    BorderStyle = bsNone
    Color = clActiveBorder
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clNavy
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    Lines.Strings = (
      #1059#1082#1072#1078#1080#1090#1077' '#1088#1072#1079#1076#1077#1083', '#1074' '#1082#1086#1090#1086#1088#1099#1081' '#1085#1091#1078#1085#1086' '
      #1087#1077#1088#1077#1085#1077#1089#1090#1080' ('#1089#1082#1086#1087#1080#1088#1086#1074#1072#1090#1100') '#1079#1072#1087#1080#1089#1080)
    ParentFont = False
    PlainText = True
    ReadOnly = True
    TabOrder = 1
  end
  object TreeView: TTreeView
    Left = 0
    Top = 49
    Width = 385
    Height = 315
    Align = alClient
    BevelKind = bkFlat
    BorderStyle = bsNone
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    Indent = 19
    ParentFont = False
    TabOrder = 2
    OnChange = TreeViewChange
  end
  object FormStorage: TFormStorage
    StoredValues = <>
    Left = 112
    Top = 80
  end
end
