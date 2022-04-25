object MainForm: TMainForm
  Left = 282
  Top = 113
  Width = 1519
  Height = 1010
  Caption = #1044#1086#1089#1090#1072#1074#1082#1072'. '#1059#1095#1077#1090' '#1086#1087#1077#1088#1072#1094#1080#1081
  Color = clBtnFace
  Constraints.MinHeight = 300
  Constraints.MinWidth = 450
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  Scaled = False
  OnDestroy = FormDestroy
  OnShow = FormShow
  PixelsPerInch = 120
  TextHeight = 13
  object MainHeader: TJvNavPanelHeader
    Left = 0
    Top = 28
    Width = 1501
    Align = alTop
    Alignment = taCenter
    Caption = 'MainHeader'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clTeal
    Font.Height = -16
    Font.Name = 'Arial'
    Font.Style = [fsBold]
    ParentFont = False
    ColorFrom = clMoneyGreen
    ColorTo = 16776176
    ImageIndex = 0
  end
  object ButtonsPanel: TPanel
    Left = 0
    Top = 0
    Width = 1501
    Height = 28
    Align = alTop
    BevelOuter = bvNone
    Ctl3D = False
    ParentCtl3D = False
    TabOrder = 1
    DesignSize = (
      1501
      28)
    object PeriodButton: TSpeedButton
      Left = 8
      Top = 4
      Width = 20
      Height = 20
      Hint = #1042#1099#1073#1086#1088' '#1087#1077#1088#1080#1086#1076#1072
      Flat = True
      Glyph.Data = {
        F6000000424DF600000000000000760000002800000010000000100000000100
        0400000000008000000000000000000000001000000000000000000000000000
        80000080000000808000800000008000800080800000C0C0C000808080000000
        FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00F00000000000
        00FFF0FFFFF2FFFFF0FFFFFFFF222FFFFFFFFFFFF22222FFFFFFFFFF2222222F
        FFFFFFFFFF222FFFFFFFFFFFFF222FFFFFFFFFFFFF222FFFFFFFFFFFFF222FFF
        FFFFFFFFFF222FFFFFFFFFFFFF222FFFFFFFFFFF2222222FFFFFFFFFF22222FF
        FFFFFFFFFF222FFFFFFFF0FFFFF2FFFFF0FFF0000000000000FF}
      ParentShowHint = False
      ShowHint = True
      OnClick = PeriodButtonClick
    end
    object SelectButton: TSpeedButton
      Left = 144
      Top = 4
      Width = 20
      Height = 20
      Hint = #1054#1090#1073#1086#1088' '#1079#1072#1087#1080#1089#1077#1081
      Flat = True
      Glyph.Data = {
        76010000424D7601000000000000760000002800000020000000100000000100
        0400000000000001000000000000000000001000000000000000000000000000
        80000080000000808000800000008000800080800000C0C0C000808080000000
        FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00FFFFFFFFFFFF
        CFFFFFFFFFFFFFFF8FFFFFFFCFFFCCCCCCFFFFFF8FFF888888FFCCCCCCFFCCCC
        CCCF888888FF8888888FCCCCCCCFCCCCCCCC8888888F88888888CCCCCCFFCCCC
        CCCF888888FF8888888FFFFFCFFFCCCCCCFFFFFF8FFF888888FFFFFF9FFFFFFF
        CFFFFFFF8FFFFFFF8FFF999999FFFFFFFFFF888888FFFFFFFFFF9999999FFFFF
        FFFF8888888FFFFFFFFF999999FFFFFFFFFF888888FFFFFFFFFFFFFF9FFFFFFF
        FFFFFFFF8FFFFFFFFFFFFFFF2FFFFFFFFFFFFFFF8FFFFFFFFFFF222222FFFFFF
        FFFF888888FFFFFFFFFF2222222FFFFFFFFF8888888FFFFFFFFF222222FFFFFF
        FFFF888888FFFFFFFFFFFFFF2FFFFFFFFFFFFFFF8FFFFFFFFFFF}
      NumGlyphs = 2
      ParentShowHint = False
      ShowHint = True
      Visible = False
      OnClick = SelectButtonClick
    end
    object UnSelectButton: TSpeedButton
      Left = 168
      Top = 4
      Width = 20
      Height = 20
      Hint = #1054#1090#1084#1077#1085#1072' '#1086#1090#1073#1086#1088#1072' '#1079#1072#1087#1080#1089#1077#1081
      Flat = True
      Glyph.Data = {
        76010000424D7601000000000000760000002800000020000000100000000100
        0400000000000001000000000000000000001000000000000000000000000000
        80000080000000808000800000008000800080800000C0C0C000808080000000
        FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00FFFFFFFF99FF
        CF99FFFFFFFF88FF8F88FFFFCFFFC99CCC99FFFF8FFF88888888CCCCCCFFCC99
        C99F888888FF8888888FCCCCCCCFCCC999CC8888888F88888888CCCCCCFFCCC9
        99CF888888FF8888888FFFFFCFFFCC99C99FFFFF8FFF8888888FFFFF9FFFF99F
        CF99FFFF8FFFF88F8F88999999FF99FFFF99888888FF88FFFF889999999FFFFF
        FFFF8888888FFFFFFFFF999999FFFFFFFFFF888888FFFFFFFFFFFFFF9FFFFFFF
        FFFFFFFF8FFFFFFFFFFFFFFF2FFFFFFFFFFFFFFF8FFFFFFFFFFF222222FFFFFF
        FFFF888888FFFFFFFFFF2222222FFFFFFFFF8888888FFFFFFFFF222222FFFFFF
        FFFF888888FFFFFFFFFFFFFF2FFFFFFFFFFFFFFF8FFFFFFFFFFF}
      NumGlyphs = 2
      ParentShowHint = False
      ShowHint = True
      Visible = False
      OnClick = UnSelectButtonClick
    end
    object FSButton: TSpeedButton
      Left = 1459
      Top = 4
      Width = 20
      Height = 20
      Hint = #1055#1086#1080#1089#1082' - '#1074#1087#1077#1088#1077#1076
      Anchors = [akTop, akRight]
      Enabled = False
      Flat = True
      Glyph.Data = {
        76010000424D7601000000000000760000002800000020000000100000000100
        0400000000000001000000000000000000001000000000000000000000000000
        8000008000000080800080000000800080008080000080808000C0C0C0000000
        FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00FFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFF00000FF00000FFFF77777FF77777FFFF0F000FF0F0
        00FFFF7F777FF7F777FFFF0F000FF0F000FFFF7F777FF7F777FFFF0F000FF0F0
        00FFFF7F777FF7F777FFFF0F000000F000FFFF7F777777F777FFFF0000000000
        00FFFF777777777777FFFF00000FF00000FFFF77777FF77777FFFFF00FFFFFF0
        0FFFFFF77FFFFFF77FFFFFF00FFFFFF00FFFFFF77FFFFFF77FFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFCCCCFFFFFFFFFFFF7777FFFFFFCFFFFFFFCC
        FFFFFF7FFFFFFF77FFFFFFCCFFFFFCFCFFFFFF77FFFFF7F7FFFFFFFCCCCCCFFC
        FFFFFFF777777FF7FFFFFFFFCCCCFFFFFFFFFFFF7777FFFFFFFF}
      NumGlyphs = 2
      ParentShowHint = False
      ShowHint = True
      Visible = False
      OnClick = FSButtonClick
    end
    object BSButton: TSpeedButton
      Left = 1483
      Top = 4
      Width = 20
      Height = 20
      Hint = #1055#1086#1080#1089#1082' - '#1085#1072#1079#1072#1076
      Anchors = [akTop, akRight]
      Enabled = False
      Flat = True
      Glyph.Data = {
        76010000424D7601000000000000760000002800000020000000100000000100
        0400000000000001000000000000000000001000000000000000000000000000
        8000008000000080800080000000800080008080000080808000C0C0C0000000
        FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00FFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFF00000FF00000FFFF77777FF77777FFFF0F000FF0F0
        00FFFF7F777FF7F777FFFF0F000FF0F000FFFF7F777FF7F777FFFF0F000FF0F0
        00FFFF7F777FF7F777FFFF0F000000F000FFFF7F777777F777FFFF0000000000
        00FFFF777777777777FFFF00000FF00000FFFF77777FF77777FFFFF00FFFFFF0
        0FFFFFF77FFFFFF77FFFFFF00FFFFFF00FFFFFF77FFFFFF77FFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFCCCCFFFFFFFFFFFF7777FFFFFFFFFFFFCCFFFFFFF
        CFFFFFF77FFFFFFF7FFFFFFCFCFFFFFCCFFFFFF7F7FFFFF77FFFFFFCFFCCCCCC
        FFFFFFF7FF777777FFFFFFFFFFFCCCCFFFFFFFFFFFF7777FFFFF}
      NumGlyphs = 2
      ParentShowHint = False
      ShowHint = True
      Visible = False
      OnClick = BSButtonClick
    end
    object SLabel: TLabel
      Left = 1125
      Top = 6
      Width = 183
      Height = 16
      Alignment = taRightJustify
      Anchors = [akLeft, akTop, akRight, akBottom]
      AutoSize = False
      Caption = #1055#1086#1080#1089#1082' '#1087#1086' '#1084#1086#1076#1077#1083#1080
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clGreen
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      Visible = False
    end
    object reloadButton: TSpeedButton
      Left = 32
      Top = 4
      Width = 20
      Height = 20
      Hint = #1054#1073#1097#1080#1081' '#1080#1084#1087#1086#1088#1090' '#1076#1072#1085#1085#1099#1093' '#1080#1079' '#1048#1057' '#1048#1085#1089#1087#1077#1082#1090#1086#1088'  '#1087#1086' '#1076#1072#1090#1077
      Flat = True
      Glyph.Data = {
        F6000000424DF600000000000000760000002800000010000000100000000100
        0400000000008000000000000000000000001000000000000000000000000000
        8000008000000080800080000000800080008080000080808000C0C0C0000000
        FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00888888888888
        8888888888888888888888888888888888880000088888889888000008888889
        9988000008888899999800000888899999990000088899999999800008888899
        9988880008888999998888800088999998888888000999998888888888888888
        8888888888888888888888888888888888888888888888888888}
      ParentShowHint = False
      ShowHint = True
      OnClick = reloadButtonClick
    end
    object AddButton: TSpeedButton
      Left = 208
      Top = 4
      Width = 23
      Height = 22
      Hint = #1044#1086#1073#1072#1074#1080#1090#1100' '#1079#1072#1087#1080#1089#1100
      Flat = True
      Glyph.Data = {
        F6000000424DF600000000000000760000002800000010000000100000000100
        0400000000008000000000000000000000001000000000000000000000000000
        8000008000000080800080000000800080008080000080808000C0C0C0000000
        FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00FFFFFCFFFFFF
        FFFFFCCCCCCFFFFFFFFFCCCCCCCCCF999999CCCCCCCCCF999999CCCCCCCFFFFF
        FFFFCCCFFCF777777777CCCF7F7777777777CCCFFFFFFFFFFFFFCCC777777777
        7777FFF7777777777777FFFFFFFFFFFFFFFFFFF7777777777777FFF777777777
        7777FFFFFFFFFFFFFFFFFFF7777777777777FFF7777777777777}
      ParentShowHint = False
      ShowHint = True
      OnClick = AddButtonClick
    end
    object EditButton: TSpeedButton
      Left = 233
      Top = 4
      Width = 23
      Height = 22
      Hint = #1056#1077#1076#1072#1082#1090#1080#1088#1086#1074#1072#1090#1100' '#1079#1072#1087#1080#1089#1100
      Flat = True
      Glyph.Data = {
        F6000000424DF600000000000000760000002800000010000000100000000100
        0400000000008000000000000000000000001000000000000000000000000000
        8000008000000080800080000000800080008080000080808000C0C0C0000000
        FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00FFFFFFFFFFFF
        FFFF444444444444444442FFF0FF00000FF44F20FFFFFFFFFFF44F0000FFF000
        0FF44FF00F00FFFFFFF44FF0FFF03F000FF44FFF0F0233FFFFF44F0F00222330
        0FF44FFFFA222233FFF44F000FA222233FF44FFFFFFA222233F444444444A222
        23344F444F444A2222334444444444A22223FFFFFFFFFFFA2226}
      ParentShowHint = False
      ShowHint = True
      OnClick = EditButtonClick
    end
    object DeleteButton: TSpeedButton
      Left = 259
      Top = 4
      Width = 23
      Height = 22
      Hint = #1059#1076#1072#1083#1080#1090#1100' '#1079#1072#1087#1080#1089#1100
      Flat = True
      Glyph.Data = {
        F6000000424DF600000000000000760000002800000010000000100000000100
        0400000000008000000000000000000000001000000000000000000000000000
        8000008000000080800080000000800080008080000080808000C0C0C0000000
        FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00FFFFFFFFFFFF
        FFFFF599758997555555F58998998FFFFFF5F5C89998CCCFCCC5F5C89998CCCF
        CCC5F58998998FFFFFF5F5997589975F5555F55F555F555F5555F5FFFFFFFFFF
        FFF5F555555555555555F55F555F555F5555F555555555555555F5FFFFFFFFFF
        FFF5F5FFF55F5555FFF5F5FFFFFFFFFFFFF5F555555555555555}
      ParentShowHint = False
      ShowHint = True
      OnClick = DeleteButtonClick
    end
    object Label1: TLabel
      Tag = 12
      Left = 344
      Top = 7
      Width = 49
      Height = 16
      Alignment = taRightJustify
      Anchors = [akLeft, akTop, akBottom]
      AutoSize = False
      Caption = #1054#1055#1057
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object increaseButton: TSpeedButton
      Left = 64
      Top = 4
      Width = 20
      Height = 20
      Hint = #1059#1074#1077#1083#1080#1095#1080#1090#1100
      Flat = True
      Glyph.Data = {
        9E050000424D9E05000000000000360400002800000012000000120000000100
        0800000000006801000000000000000000000001000000000000000000000000
        80000080000000808000800000008000800080800000C0C0C000C0DCC000F0CA
        A6000020400000206000002080000020A0000020C0000020E000004000000040
        20000040400000406000004080000040A0000040C0000040E000006000000060
        20000060400000606000006080000060A0000060C0000060E000008000000080
        20000080400000806000008080000080A0000080C0000080E00000A0000000A0
        200000A0400000A0600000A0800000A0A00000A0C00000A0E00000C0000000C0
        200000C0400000C0600000C0800000C0A00000C0C00000C0E00000E0000000E0
        200000E0400000E0600000E0800000E0A00000E0C00000E0E000400000004000
        20004000400040006000400080004000A0004000C0004000E000402000004020
        20004020400040206000402080004020A0004020C0004020E000404000004040
        20004040400040406000404080004040A0004040C0004040E000406000004060
        20004060400040606000406080004060A0004060C0004060E000408000004080
        20004080400040806000408080004080A0004080C0004080E00040A0000040A0
        200040A0400040A0600040A0800040A0A00040A0C00040A0E00040C0000040C0
        200040C0400040C0600040C0800040C0A00040C0C00040C0E00040E0000040E0
        200040E0400040E0600040E0800040E0A00040E0C00040E0E000800000008000
        20008000400080006000800080008000A0008000C0008000E000802000008020
        20008020400080206000802080008020A0008020C0008020E000804000008040
        20008040400080406000804080008040A0008040C0008040E000806000008060
        20008060400080606000806080008060A0008060C0008060E000808000008080
        20008080400080806000808080008080A0008080C0008080E00080A0000080A0
        200080A0400080A0600080A0800080A0A00080A0C00080A0E00080C0000080C0
        200080C0400080C0600080C0800080C0A00080C0C00080C0E00080E0000080E0
        200080E0400080E0600080E0800080E0A00080E0C00080E0E000C0000000C000
        2000C0004000C0006000C0008000C000A000C000C000C000E000C0200000C020
        2000C0204000C0206000C0208000C020A000C020C000C020E000C0400000C040
        2000C0404000C0406000C0408000C040A000C040C000C040E000C0600000C060
        2000C0604000C0606000C0608000C060A000C060C000C060E000C0800000C080
        2000C0804000C0806000C0808000C080A000C080C000C080E000C0A00000C0A0
        2000C0A04000C0A06000C0A08000C0A0A000C0A0C000C0A0E000C0C00000C0C0
        2000C0C04000C0C06000C0C08000C0C0A000F0FBFF00A4A0A000808080000000
        FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00FFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFF0000FFFFF608FFFFFFFFFFFFFFFFFFFFFFFFFFFF
        0000FF08A4A507FFFFFFFFFFFFFFFFFFFFFFFFFF0000FF086F66A507FFFFFFFF
        FFFFFFFFFFFFFFFF0000FFF6B76F66A507FFFFFFFFFFFFFFFFFFFFFF0000FFFF
        F6B76F66A507FFFFFFFFFFFFFFFFFFFF0000FFFFFFF6B76F66A5080909ED0909
        F6FFFFFF0000FFFFFFFFF6B76FF7EDED090909090909FFFF0000FFFFFFFFFFF6
        08ED0909FFFFFFFF0809F6FF0000FFFFFFFFFFFF09ED090909FCFFFFFF0909FF
        0000FFFFFFFFFFFF0909090909FC0909FF09EDFF0000FFFFFFFFFFFFED0909FC
        FCFCFCFCFFFFEDFF0000FFFFFFFFFFFF0909090909FC0909FF09EDFF0000FFFF
        FFFFFFFF0909FFF609FCFF09FF0909FF0000FFFFFFFFFFFFF6EDF6FF09090909
        09EDF6FF0000FFFFFFFFFFFFFF09ED0909090909ED09FFFF0000FFFFFFFFFFFF
        FFFFF609EDEDED0909FFFFFF0000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        0000}
      ParentShowHint = False
      ShowHint = True
      OnClick = increaseButtonClick
    end
    object reduceButton: TSpeedButton
      Left = 86
      Top = 4
      Width = 20
      Height = 20
      Hint = #1059#1084#1077#1085#1100#1096#1080#1090#1100
      Flat = True
      Glyph.Data = {
        9E050000424D9E05000000000000360400002800000012000000120000000100
        0800000000006801000000000000000000000001000000000000000000000000
        80000080000000808000800000008000800080800000C0C0C000C0DCC000F0CA
        A6000020400000206000002080000020A0000020C0000020E000004000000040
        20000040400000406000004080000040A0000040C0000040E000006000000060
        20000060400000606000006080000060A0000060C0000060E000008000000080
        20000080400000806000008080000080A0000080C0000080E00000A0000000A0
        200000A0400000A0600000A0800000A0A00000A0C00000A0E00000C0000000C0
        200000C0400000C0600000C0800000C0A00000C0C00000C0E00000E0000000E0
        200000E0400000E0600000E0800000E0A00000E0C00000E0E000400000004000
        20004000400040006000400080004000A0004000C0004000E000402000004020
        20004020400040206000402080004020A0004020C0004020E000404000004040
        20004040400040406000404080004040A0004040C0004040E000406000004060
        20004060400040606000406080004060A0004060C0004060E000408000004080
        20004080400040806000408080004080A0004080C0004080E00040A0000040A0
        200040A0400040A0600040A0800040A0A00040A0C00040A0E00040C0000040C0
        200040C0400040C0600040C0800040C0A00040C0C00040C0E00040E0000040E0
        200040E0400040E0600040E0800040E0A00040E0C00040E0E000800000008000
        20008000400080006000800080008000A0008000C0008000E000802000008020
        20008020400080206000802080008020A0008020C0008020E000804000008040
        20008040400080406000804080008040A0008040C0008040E000806000008060
        20008060400080606000806080008060A0008060C0008060E000808000008080
        20008080400080806000808080008080A0008080C0008080E00080A0000080A0
        200080A0400080A0600080A0800080A0A00080A0C00080A0E00080C0000080C0
        200080C0400080C0600080C0800080C0A00080C0C00080C0E00080E0000080E0
        200080E0400080E0600080E0800080E0A00080E0C00080E0E000C0000000C000
        2000C0004000C0006000C0008000C000A000C000C000C000E000C0200000C020
        2000C0204000C0206000C0208000C020A000C020C000C020E000C0400000C040
        2000C0404000C0406000C0408000C040A000C040C000C040E000C0600000C060
        2000C0604000C0606000C0608000C060A000C060C000C060E000C0800000C080
        2000C0804000C0806000C0808000C080A000C080C000C080E000C0A00000C0A0
        2000C0A04000C0A06000C0A08000C0A0A000C0A0C000C0A0E000C0C00000C0C0
        2000C0C04000C0C06000C0C08000C0C0A000F0FBFF00A4A0A000808080000000
        FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00FFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFF0000FFFFF608FFFFFFFFFFFFFFFFFFFFFFFFFFFF
        0000FF08A4A507FFFFFFFFFFFFFFFFFFFFFFFFFF0000FF086F66A507FFFFFFFF
        FFFFFFFFFFFFFFFF0000FFF6B76F66A507FFFFFFFFFFFFFFFFFFFFFF0000FFFF
        F6B76F66A507FFFFFFFFFFFFFFFFFFFF0000FFFFFFF6B76F66A5080909ED0909
        F6FFFFFF0000FFFFFFFFF6B76FF7EDED090909090909FFFF0000FFFFFFFFFFF6
        08ED0909FFFFFFFF0809F6FF0000FFFFFFFFFFFF09ED0909FFFFFFFFFF0909FF
        0000FFFFFFFFFFFF0909090909090909FF09EDFF0000FFFFFFFFFFFFED0909FC
        FCFCFCFCFFFFEDFF0000FFFFFFFFFFFF0909090909090909FF09EDFF0000FFFF
        FFFFFFFF0909FFF60909FFFFFF0909FF0000FFFFFFFFFFFFF6EDF6FF09090909
        09EDF6FF0000FFFFFFFFFFFFFF09ED0909090909ED09FFFF0000FFFFFFFFFFFF
        FFFFF609EDEDED0909FFFFFF0000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        0000}
      ParentShowHint = False
      ShowHint = True
      OnClick = reduceButtonClick
    end
    object ImportButton: TSpeedButton
      Left = 286
      Top = 5
      Width = 20
      Height = 20
      Hint = #1048#1084#1087#1086#1088#1090' '#1076#1072#1085#1085#1099#1093' '#1080#1079' '#1048#1057' '#1048#1085#1089#1087#1077#1082#1090#1086#1088' '#1087#1086' '#1076#1072#1090#1077','#1054#1055#1057' '#1080' '#1087#1086#1095#1090#1072#1083#1100#1086#1085#1091'/'#1082#1072#1089#1089#1077
      Flat = True
      Glyph.Data = {
        76010000424D7601000000000000760000002800000020000000100000000100
        04000000000000010000130B0000130B00001000000000000000000000000000
        800000800000008080008000000080008000808000007F7F7F00BFBFBF000000
        FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF003333330B7FFF
        FFB0333333777F3333773333330B7FFFFFB0333333777F3333773333330B7FFF
        FFB0333333777F3333773333330B7FFFFFB03FFFFF777FFFFF77000000000077
        007077777777777777770FFFFFFFF00077B07F33333337FFFF770FFFFFFFF000
        7BB07F3FF3FFF77FF7770F00F000F00090077F77377737777F770FFFFFFFF039
        99337F3FFFF3F7F777FF0F0000F0F09999937F7777373777777F0FFFFFFFF999
        99997F3FF3FFF77777770F00F000003999337F773777773777F30FFFF0FF0339
        99337F3FF7F3733777F30F08F0F0337999337F7737F73F7777330FFFF0039999
        93337FFFF7737777733300000033333333337777773333333333}
      NumGlyphs = 2
      ParentShowHint = False
      ShowHint = True
      OnClick = ImportButtonClick
    end
    object ScanButton: TSpeedButton
      Left = 307
      Top = 6
      Width = 20
      Height = 20
      Hint = #1057#1082#1072#1085#1080#1088#1086#1074#1072#1085#1080#1077' '#1087#1086#1088#1091#1095#1077#1085#1080#1081'...'
      Flat = True
      Glyph.Data = {
        F6000000424DF600000000000000760000002800000010000000100000000100
        0400000000008000000000000000000000001000000000000000000000000000
        8000008000000080800080000000800080008080000080808000C0C0C0000000
        FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00370777033333
        3330870700033337073000770333333070008870073333370077700070333333
        0770703707333300080700333333330778083330003333000807073070370733
        0780700070007037007800777770073070000770007703370730080777070003
        3330780807077703333308078707000333330780007703333333}
      ParentShowHint = False
      ShowHint = True
      Visible = False
      OnClick = ScanButtonClick
    end
    object SEdit: TEdit
      Left = 1333
      Top = 4
      Width = 121
      Height = 20
      Anchors = [akTop, akRight]
      AutoSelect = False
      BevelKind = bkFlat
      BevelOuter = bvRaised
      BorderStyle = bsNone
      Ctl3D = False
      ParentCtl3D = False
      TabOrder = 0
      Visible = False
      OnChange = SEditChange
      OnKeyDown = SEditKeyDown
    end
    object autoNumberEdit: TComboBox
      Left = 416
      Top = 4
      Width = 233
      Height = 21
      AutoDropDown = True
      BevelKind = bkFlat
      Style = csDropDownList
      Anchors = [akLeft, akTop, akBottom]
      Ctl3D = False
      DropDownCount = 50
      ItemHeight = 13
      ParentCtl3D = False
      TabOrder = 1
      OnChange = autoNumberEditChange
    end
    object autoNumberEdit1: TComboBox
      Left = 416
      Top = 4
      Width = 233
      Height = 21
      AutoDropDown = True
      BevelKind = bkFlat
      Style = csDropDownList
      Anchors = [akLeft, akTop, akBottom]
      Ctl3D = False
      DropDownCount = 50
      ItemHeight = 13
      ParentCtl3D = False
      TabOrder = 2
      OnChange = autoNumberEdit1Change
    end
  end
  object MainStatusBar: TStatusBar
    Left = 0
    Top = 921
    Width = 1501
    Height = 19
    Panels = <
      item
        Width = 300
      end
      item
        Width = 200
      end>
    SimplePanel = False
  end
  object Panel2: TPanel
    Left = 0
    Top = 55
    Width = 1501
    Height = 866
    Align = alClient
    TabOrder = 3
    object PC: TRzPageControl
      Left = 1
      Top = 1
      Width = 1499
      Height = 864
      ActivePage = TabSheet1
      ActivePageDefault = TabSheet1
      Align = alClient
      BackgroundColor = 16776176
      BoldCurrentTab = True
      Color = 16119543
      FlatColor = 10263441
      HotTrackColor = 3983359
      HotTrackColorType = htctActual
      ParentBackgroundColor = False
      ParentColor = False
      ShowFocusRect = False
      TabColors.HighlightBar = 3983359
      TabIndex = 0
      TabOrder = 0
      TabStyle = tsDoubleSlant
      OnClick = PCClick
      FixedDimension = 19
      object TabSheet1: TRzTabSheet
        Color = 16119543
        Caption = #1055#1086#1095#1090#1072#1083#1100#1086#1085#1099
        object Splitter1: TSplitter
          Left = 0
          Top = 0
          Width = 3
          Height = 841
          Cursor = crHSplit
          Beveled = True
          ResizeStyle = rsUpdate
        end
        object selectSDBar: TJvXPBar
          Left = 3
          Top = 0
          Width = 217
          Height = 1063
          Caption = #1055#1086#1095#1090#1072#1083#1100#1086#1085#1099
          Items = <
            item
              Caption = #1055#1086' '#1074#1089#1077#1084' '#1087#1086#1095#1090#1072#1083#1100#1086#1085#1072#1084
              Name = 'item0'
              OnClick = action0Execute
            end
            item
              OnClick = action1Execute
            end
            item
              OnClick = action2Execute
            end
            item
              OnClick = action3Execute
            end
            item
              OnClick = action4Execute
            end
            item
              OnClick = action5Execute
            end
            item
              OnClick = action6Execute
            end
            item
              OnClick = action7Execute
            end
            item
              OnClick = action8Execute
            end
            item
              OnClick = action9Execute
            end
            item
              OnClick = action10Execute
            end
            item
              OnClick = action11Execute
            end
            item
              OnClick = action12Execute
            end
            item
              OnClick = action13Execute
            end
            item
              OnClick = action14Execute
            end
            item
              OnClick = action15Execute
            end
            item
              OnClick = action16Execute
            end
            item
            end
            item
            end
            item
            end
            item
            end
            item
            end
            item
            end
            item
            end
            item
            end
            item
            end
            item
            end
            item
            end
            item
            end
            item
            end
            item
            end
            item
            end
            item
            end
            item
            end
            item
            end
            item
            end
            item
            end
            item
            end
            item
            end
            item
            end
            item
            end
            item
            end
            item
            end
            item
            end
            item
            end
            item
            end
            item
            end
            item
            end
            item
            end
            item
            end
            item
            end>
          Font.Charset = DEFAULT_CHARSET
          Font.Color = 15159552
          Font.Height = -13
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          HeaderFont.Charset = DEFAULT_CHARSET
          HeaderFont.Color = clRed
          HeaderFont.Height = -17
          HeaderFont.Name = 'MS Sans Serif'
          HeaderFont.Style = [fsBold]
          HotTrackColor = clBackground
          OwnerDraw = False
          ShowItemFrame = True
          RoundedItemFrame = 0
          OnItemClick = selectSDBarItemClick
          Align = alLeft
          ParentFont = False
          OnClick = selectSDBarClick
        end
        object Panel7: TPanel
          Left = 220
          Top = 0
          Width = 1275
          Height = 841
          Align = alClient
          Caption = 'Panel7'
          TabOrder = 1
          object Panel4: TPanel
            Left = 1
            Top = 1
            Width = 1273
            Height = 289
            Align = alTop
            TabOrder = 0
            object Splitter3: TSplitter
              Left = 1
              Top = 285
              Width = 1271
              Height = 3
              Cursor = crVSplit
              Align = alBottom
              Beveled = True
              ResizeStyle = rsUpdate
            end
            object workGrid: TDBGridEh
              Left = 1
              Top = 28
              Width = 1271
              Height = 257
              Align = alClient
              Ctl3D = False
              DataSource = workSource
              Flat = True
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -11
              Font.Name = 'MS Sans Serif'
              Font.Style = []
              FooterColor = clMoneyGreen
              FooterFont.Charset = DEFAULT_CHARSET
              FooterFont.Color = clWindowText
              FooterFont.Height = -11
              FooterFont.Name = 'MS Sans Serif'
              FooterFont.Style = []
              FooterRowCount = 1
              Options = [dgTitles, dgIndicator, dgColumnResize, dgColLines, dgRowLines, dgTabs, dgConfirmDelete, dgCancelOnExit]
              OptionsEh = [dghHighlightFocus, dghClearSelection, dghAutoSortMarking, dghRowHighlight]
              ParentCtl3D = False
              ParentFont = False
              PopupMenu = workGridPM
              SumList.Active = True
              TabOrder = 0
              TitleFont.Charset = DEFAULT_CHARSET
              TitleFont.Color = clBlack
              TitleFont.Height = -11
              TitleFont.Name = 'MS Sans Serif'
              TitleFont.Style = []
              UseMultiTitle = True
              OnCellClick = workGridCellClick
              OnDblClick = workGridDblClick
              OnDrawColumnCell = workGridDrawColumnCell
              OnKeyDown = workGridKeyDown
              OnKeyPress = workGridKeyPress
              OnSortMarkingChanged = workGridSortMarkingChanged
              Columns = <
                item
                  Alignment = taCenter
                  EditButtons = <>
                  FieldName = 'ID'
                  Footer.Alignment = taCenter
                  Footer.Font.Charset = DEFAULT_CHARSET
                  Footer.Font.Color = clWindowText
                  Footer.Font.Height = -13
                  Footer.Font.Name = 'MS Sans Serif'
                  Footer.Font.Style = [fsBold]
                  Footer.ValueType = fvtCount
                  Footers = <>
                  Title.Caption = #1050#1086#1076
                  Title.TitleButton = True
                  Width = 37
                end
                item
                  Alignment = taCenter
                  EditButtons = <>
                  FieldName = 'EXP_DATE'
                  Footers = <>
                  Title.Caption = #1044#1072#1090#1072' '#1086#1087#1077#1088#1072#1094#1080#1081
                  Title.TitleButton = True
                  Width = 72
                end
                item
                  EditButtons = <>
                  FieldName = 'DRIVER'
                  Footer.Font.Charset = DEFAULT_CHARSET
                  Footer.Font.Color = clWindowText
                  Footer.Font.Height = -11
                  Footer.Font.Name = 'MS Sans Serif'
                  Footer.Font.Style = [fsBold]
                  Footers = <>
                  Title.Caption = #1054#1055#1057
                  Title.TitleButton = True
                  Width = 134
                end
                item
                  EditButtons = <>
                  FieldName = 'GSM'
                  Footers = <>
                  Title.Caption = #1058#1080#1087' '#1086#1087#1077#1088#1072#1094#1080#1081
                  Title.TitleButton = True
                  Width = 68
                end
                item
                  Alignment = taCenter
                  DisplayFormat = '0#.0#'
                  EditButtons = <>
                  FieldName = 'EXPENSE'
                  Footer.Alignment = taCenter
                  Footer.DisplayFormat = '0#.0#'
                  Footer.Font.Charset = DEFAULT_CHARSET
                  Footer.Font.Color = clWindowText
                  Footer.Font.Height = -13
                  Footer.Font.Name = 'MS Sans Serif'
                  Footer.Font.Style = [fsBold]
                  Footer.ValueType = fvtSum
                  Footers = <>
                  Title.Caption = #1057#1091#1084#1084#1072
                  Title.TitleButton = True
                  Width = 73
                end
                item
                  Alignment = taCenter
                  EditButtons = <>
                  FieldName = 'KOL'
                  Footer.Alignment = taCenter
                  Footer.Font.Charset = DEFAULT_CHARSET
                  Footer.Font.Color = clWindowText
                  Footer.Font.Height = -11
                  Footer.Font.Name = 'MS Sans Serif'
                  Footer.Font.Style = [fsBold]
                  Footer.ValueType = fvtSum
                  Footers = <>
                  Title.Caption = #1050#1086#1083'-'#1074#1086
                end
                item
                  EditButtons = <>
                  FieldName = 'FIO'
                  Footers = <>
                  Title.Caption = #1040#1074#1090#1086#1088
                end
                item
                  EditButtons = <>
                  FieldName = 'FIOP'
                  Footers = <>
                  Title.Caption = #1060'.'#1048'.'#1054' '#1055#1086#1095#1090#1072#1083#1100#1086#1085#1072
                  Width = 100
                end>
            end
            object JvNavPanelHeader1: TJvNavPanelHeader
              Left = 1
              Top = 1
              Width = 1271
              Align = alTop
              Alignment = taCenter
              Caption = #1055#1088#1080#1093#1086#1076
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clTeal
              Font.Height = -16
              Font.Name = 'Arial'
              Font.Style = [fsBold]
              ParentFont = False
              ColorFrom = clMoneyGreen
              ColorTo = 16776176
              ImageIndex = 0
            end
          end
          object Panel5: TPanel
            Left = 1
            Top = 290
            Width = 1273
            Height = 289
            Align = alClient
            TabOrder = 1
            object Splitter4: TSplitter
              Left = 1
              Top = 285
              Width = 1271
              Height = 3
              Cursor = crVSplit
              Align = alBottom
              AutoSnap = False
              ResizeStyle = rsUpdate
            end
            object workGrid4: TDBGridEh
              Left = 1
              Top = 28
              Width = 1271
              Height = 257
              Align = alClient
              Ctl3D = False
              DataSource = DS3
              Flat = True
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -11
              Font.Name = 'MS Sans Serif'
              Font.Style = []
              FooterColor = clMoneyGreen
              FooterFont.Charset = DEFAULT_CHARSET
              FooterFont.Color = clWindowText
              FooterFont.Height = -11
              FooterFont.Name = 'MS Sans Serif'
              FooterFont.Style = []
              FooterRowCount = 1
              Options = [dgTitles, dgIndicator, dgColumnResize, dgColLines, dgRowLines, dgTabs, dgConfirmDelete, dgCancelOnExit]
              OptionsEh = [dghHighlightFocus, dghClearSelection, dghAutoSortMarking, dghRowHighlight]
              ParentCtl3D = False
              ParentFont = False
              PopupMenu = workGridPM
              SumList.Active = True
              TabOrder = 0
              TitleFont.Charset = DEFAULT_CHARSET
              TitleFont.Color = clBlack
              TitleFont.Height = -11
              TitleFont.Name = 'MS Sans Serif'
              TitleFont.Style = []
              UseMultiTitle = True
              OnCellClick = workGrid4CellClick
              OnDblClick = workGrid4DblClick
              OnDrawColumnCell = workGrid4DrawColumnCell
              OnKeyDown = workGrid4KeyDown
              OnKeyPress = workGrid4KeyPress
              OnSortMarkingChanged = workGrid4SortMarkingChanged
              Columns = <
                item
                  Alignment = taCenter
                  EditButtons = <>
                  FieldName = 'ID'
                  Footer.Alignment = taCenter
                  Footer.Font.Charset = DEFAULT_CHARSET
                  Footer.Font.Color = clWindowText
                  Footer.Font.Height = -13
                  Footer.Font.Name = 'MS Sans Serif'
                  Footer.Font.Style = [fsBold]
                  Footer.ValueType = fvtCount
                  Footers = <>
                  Title.Caption = #1050#1086#1076
                  Title.TitleButton = True
                  Width = 37
                end
                item
                  Alignment = taCenter
                  EditButtons = <>
                  FieldName = 'EXP_DATE'
                  Footers = <>
                  Title.Caption = #1044#1072#1090#1072' '#1086#1087#1077#1088#1072#1094#1080#1081
                  Title.TitleButton = True
                  Width = 72
                end
                item
                  EditButtons = <>
                  FieldName = 'DRIVER'
                  Footer.Font.Charset = DEFAULT_CHARSET
                  Footer.Font.Color = clWindowText
                  Footer.Font.Height = -11
                  Footer.Font.Name = 'MS Sans Serif'
                  Footer.Font.Style = [fsBold]
                  Footers = <>
                  Title.Caption = #1054#1055#1057
                  Title.TitleButton = True
                  Width = 134
                end
                item
                  Alignment = taCenter
                  EditButtons = <>
                  FieldName = 'GSM'
                  Footers = <>
                  Title.Caption = #1058#1080#1087' '#1086#1087#1077#1088#1072#1094#1080#1081
                  Title.TitleButton = True
                  Width = 68
                end
                item
                  Alignment = taCenter
                  DisplayFormat = '0#.0#'
                  EditButtons = <>
                  FieldName = 'EXPENSE'
                  Footer.Alignment = taCenter
                  Footer.DisplayFormat = '0#.0#'
                  Footer.Font.Charset = DEFAULT_CHARSET
                  Footer.Font.Color = clWindowText
                  Footer.Font.Height = -13
                  Footer.Font.Name = 'MS Sans Serif'
                  Footer.Font.Style = [fsBold]
                  Footer.ValueType = fvtSum
                  Footers = <>
                  Title.Caption = #1057#1091#1084#1084#1072
                  Title.TitleButton = True
                  Width = 73
                end
                item
                  Alignment = taCenter
                  EditButtons = <>
                  FieldName = 'KOL'
                  Footer.Alignment = taCenter
                  Footer.Font.Charset = DEFAULT_CHARSET
                  Footer.Font.Color = clWindowText
                  Footer.Font.Height = -11
                  Footer.Font.Name = 'MS Sans Serif'
                  Footer.Font.Style = [fsBold]
                  Footer.ValueType = fvtSum
                  Footers = <>
                  Title.Caption = #1050#1086#1083'-'#1074#1086
                end
                item
                  EditButtons = <>
                  FieldName = 'FIO'
                  Footers = <>
                  Title.Caption = #1040#1074#1090#1086#1088
                end
                item
                  EditButtons = <>
                  FieldName = 'FIOP'
                  Footers = <>
                  Title.Caption = #1060'.'#1048'.'#1054' '#1055#1086#1095#1090#1072#1083#1100#1086#1085#1072
                  Width = 100
                end>
            end
            object JvNavPanelHeader2: TJvNavPanelHeader
              Left = 1
              Top = 1
              Width = 1271
              Align = alTop
              Alignment = taCenter
              Caption = #1056#1072#1089#1093#1086#1076
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clTeal
              Font.Height = -16
              Font.Name = 'Arial'
              Font.Style = [fsBold]
              ParentFont = False
              ColorFrom = clMoneyGreen
              ColorTo = 16776176
              ImageIndex = 0
            end
          end
          object Panel6: TPanel
            Left = 1
            Top = 579
            Width = 1273
            Height = 261
            Align = alBottom
            TabOrder = 2
            object workGrid5: TDBGridEh
              Left = 1
              Top = 28
              Width = 1271
              Height = 232
              Align = alClient
              Ctl3D = False
              DataSource = DS4
              Flat = True
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -11
              Font.Name = 'MS Sans Serif'
              Font.Style = []
              FooterColor = clMoneyGreen
              FooterFont.Charset = DEFAULT_CHARSET
              FooterFont.Color = clWindowText
              FooterFont.Height = -11
              FooterFont.Name = 'MS Sans Serif'
              FooterFont.Style = []
              FooterRowCount = 1
              Options = [dgTitles, dgIndicator, dgColumnResize, dgColLines, dgRowLines, dgTabs, dgCancelOnExit]
              OptionsEh = [dghHighlightFocus, dghClearSelection, dghAutoSortMarking, dghRowHighlight]
              ParentCtl3D = False
              ParentFont = False
              SumList.Active = True
              TabOrder = 0
              TitleFont.Charset = DEFAULT_CHARSET
              TitleFont.Color = clBlack
              TitleFont.Height = -11
              TitleFont.Name = 'MS Sans Serif'
              TitleFont.Style = []
              UseMultiTitle = True
              OnCellClick = workGrid5CellClick
              OnDrawColumnCell = workGrid5DrawColumnCell
              OnSortMarkingChanged = workGrid5SortMarkingChanged
              Columns = <
                item
                  Alignment = taCenter
                  EditButtons = <>
                  FieldName = 'ID'
                  Footer.Alignment = taCenter
                  Footer.Font.Charset = DEFAULT_CHARSET
                  Footer.Font.Color = clWindowText
                  Footer.Font.Height = -13
                  Footer.Font.Name = 'MS Sans Serif'
                  Footer.Font.Style = [fsBold]
                  Footer.ValueType = fvtCount
                  Footers = <>
                  Title.Caption = #1050#1086#1076
                  Title.TitleButton = True
                  Width = 37
                end
                item
                  Alignment = taCenter
                  EditButtons = <>
                  FieldName = 'EXP_DATE'
                  Footers = <>
                  Title.Caption = #1044#1072#1090#1072' '#1086#1087#1077#1088#1072#1094#1080#1081
                  Title.TitleButton = True
                  Width = 72
                end
                item
                  EditButtons = <>
                  FieldName = 'DRIVER'
                  Footer.Font.Charset = DEFAULT_CHARSET
                  Footer.Font.Color = clWindowText
                  Footer.Font.Height = -11
                  Footer.Font.Name = 'MS Sans Serif'
                  Footer.Font.Style = [fsBold]
                  Footers = <>
                  Title.Caption = #1054#1055#1057
                  Title.TitleButton = True
                  Width = 134
                end
                item
                  Alignment = taCenter
                  EditButtons = <>
                  FieldName = 'GSM'
                  Footers = <>
                  Title.Caption = #1058#1080#1087' '#1086#1087#1077#1088#1072#1094#1080#1081
                  Title.TitleButton = True
                  Width = 68
                end
                item
                  Alignment = taCenter
                  DisplayFormat = '0#.0#'
                  EditButtons = <>
                  FieldName = 'EXPENSE'
                  Footer.Alignment = taCenter
                  Footer.DisplayFormat = '0#.0#'
                  Footer.Font.Charset = DEFAULT_CHARSET
                  Footer.Font.Color = clWindowText
                  Footer.Font.Height = -13
                  Footer.Font.Name = 'MS Sans Serif'
                  Footer.Font.Style = [fsBold]
                  Footer.ValueType = fvtSum
                  Footers = <>
                  Title.Caption = #1057#1091#1084#1084#1072
                  Title.TitleButton = True
                  Width = 73
                end
                item
                  Alignment = taCenter
                  EditButtons = <>
                  FieldName = 'KOL'
                  Footer.Alignment = taCenter
                  Footer.Font.Charset = DEFAULT_CHARSET
                  Footer.Font.Color = clWindowText
                  Footer.Font.Height = -11
                  Footer.Font.Name = 'MS Sans Serif'
                  Footer.Font.Style = [fsBold]
                  Footer.ValueType = fvtSum
                  Footers = <>
                  Title.Caption = #1050#1086#1083'-'#1074#1086
                end
                item
                  EditButtons = <>
                  FieldName = 'FIO'
                  Footers = <>
                  Title.Caption = #1040#1074#1090#1086#1088
                end
                item
                  EditButtons = <>
                  FieldName = 'FIOP'
                  Footers = <>
                  Title.Caption = #1060'.'#1048'.'#1054'. '#1055#1086#1095#1090#1072#1083#1100#1086#1085#1072
                  Width = 100
                end>
            end
            object JvNavPanelHeader3: TJvNavPanelHeader
              Left = 1
              Top = 1
              Width = 1271
              Align = alTop
              Alignment = taCenter
              Caption = #1042#1086#1079#1074#1088#1072#1090
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clTeal
              Font.Height = -16
              Font.Name = 'Arial'
              Font.Style = [fsBold]
              ParentFont = False
              ColorFrom = clMoneyGreen
              ColorTo = 16776176
              ImageIndex = 0
            end
          end
        end
      end
      object TabSheet2: TRzTabSheet
        Color = 16119543
        Caption = #1050#1072#1089#1089#1099
        object Panel3: TPanel
          Left = 0
          Top = 0
          Width = 1495
          Height = 841
          Align = alClient
          TabOrder = 0
          object Splitter2: TSplitter
            Left = 218
            Top = 1
            Width = 3
            Height = 839
            Cursor = crHSplit
            Beveled = True
            ResizeStyle = rsUpdate
          end
          object selectSDBar1: TJvXPBar
            Left = 1
            Top = 1
            Width = 217
            Height = 1063
            Caption = #1050#1072#1089#1089#1099
            Items = <
              item
                Caption = #1055#1086' '#1074#1089#1077#1084' '#1082#1072#1089#1089#1072#1084
                Name = 'item0'
                OnClick = action0Execute
              end
              item
                OnClick = action1Execute
              end
              item
                OnClick = action2Execute
              end
              item
                OnClick = action3Execute
              end
              item
                OnClick = action4Execute
              end
              item
                OnClick = action5Execute
              end
              item
                OnClick = action6Execute
              end
              item
              end
              item
              end
              item
              end
              item
              end
              item
              end
              item
              end
              item
              end
              item
              end
              item
              end
              item
              end
              item
              end
              item
              end
              item
              end
              item
              end
              item
              end
              item
              end
              item
              end
              item
              end
              item
              end
              item
              end
              item
              end
              item
              end
              item
              end
              item
              end
              item
              end
              item
              end
              item
              end
              item
              end
              item
              end
              item
              end
              item
              end
              item
              end
              item
              end
              item
              end
              item
              end
              item
              end
              item
              end
              item
              end
              item
              end
              item
              end
              item
              end
              item
              end
              item
              end
              item
              end>
            Font.Charset = DEFAULT_CHARSET
            Font.Color = 15159552
            Font.Height = -13
            Font.Name = 'MS Sans Serif'
            Font.Style = []
            HeaderFont.Charset = DEFAULT_CHARSET
            HeaderFont.Color = clRed
            HeaderFont.Height = -17
            HeaderFont.Name = 'MS Sans Serif'
            HeaderFont.Style = [fsBold]
            HotTrack = False
            HotTrackColor = clBackground
            OwnerDraw = False
            RollMode = rmFixed
            ShowItemFrame = True
            RoundedItemFrame = 0
            OnItemClick = selectSDBarItemClick
            Align = alLeft
            ParentFont = False
            OnClick = selectSDBarClick
          end
          object workGrid1: TDBGridEh
            Left = 221
            Top = 1
            Width = 1273
            Height = 839
            Align = alClient
            Ctl3D = False
            DataSource = workSource1
            Flat = True
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'MS Sans Serif'
            Font.Style = []
            FooterColor = clMoneyGreen
            FooterFont.Charset = DEFAULT_CHARSET
            FooterFont.Color = clWindowText
            FooterFont.Height = -11
            FooterFont.Name = 'MS Sans Serif'
            FooterFont.Style = []
            FooterRowCount = 1
            Options = [dgTitles, dgIndicator, dgColumnResize, dgColLines, dgRowLines, dgTabs, dgConfirmDelete, dgCancelOnExit]
            OptionsEh = [dghHighlightFocus, dghClearSelection, dghAutoSortMarking, dghRowHighlight]
            ParentCtl3D = False
            ParentFont = False
            PopupMenu = workGridPM
            SumList.Active = True
            TabOrder = 1
            TitleFont.Charset = DEFAULT_CHARSET
            TitleFont.Color = clBlack
            TitleFont.Height = -11
            TitleFont.Name = 'MS Sans Serif'
            TitleFont.Style = []
            UseMultiTitle = True
            OnCellClick = workGrid1CellClick
            OnDblClick = workGrid1DblClick
            OnDrawColumnCell = workGrid1DrawColumnCell
            OnKeyDown = workGridKeyDown
            OnKeyPress = workGridKeyPress
            OnSortMarkingChanged = workGrid1SortMarkingChanged
            Columns = <
              item
                Alignment = taCenter
                EditButtons = <>
                FieldName = 'ID'
                Footer.Alignment = taCenter
                Footer.Font.Charset = DEFAULT_CHARSET
                Footer.Font.Color = clWindowText
                Footer.Font.Height = -13
                Footer.Font.Name = 'MS Sans Serif'
                Footer.Font.Style = [fsBold]
                Footer.ValueType = fvtCount
                Footers = <>
                Title.Caption = #1050#1086#1076
                Title.TitleButton = True
                Width = 37
              end
              item
                Alignment = taCenter
                EditButtons = <>
                FieldName = 'EXP_DATE'
                Footers = <>
                Title.Caption = #1044#1072#1090#1072' '#1086#1087#1077#1088#1072#1094#1080#1081
                Title.TitleButton = True
                Width = 72
              end
              item
                EditButtons = <>
                FieldName = 'DRIVER'
                Footer.Font.Charset = DEFAULT_CHARSET
                Footer.Font.Color = clWindowText
                Footer.Font.Height = -11
                Footer.Font.Name = 'MS Sans Serif'
                Footer.Font.Style = [fsBold]
                Footers = <>
                Title.Caption = #1054#1055#1057
                Title.TitleButton = True
                Width = 134
              end
              item
                EditButtons = <>
                FieldName = 'GSM'
                Footers = <>
                Title.Caption = #1058#1080#1087' '#1086#1087#1077#1088#1072#1094#1080#1081
                Title.TitleButton = True
                Width = 68
              end
              item
                Alignment = taCenter
                DisplayFormat = '0#.0#'
                EditButtons = <>
                FieldName = 'EXPENSE'
                Footer.Alignment = taCenter
                Footer.DisplayFormat = '0#.0#'
                Footer.Font.Charset = DEFAULT_CHARSET
                Footer.Font.Color = clWindowText
                Footer.Font.Height = -13
                Footer.Font.Name = 'MS Sans Serif'
                Footer.Font.Style = [fsBold]
                Footer.ValueType = fvtSum
                Footers = <>
                Title.Caption = #1057#1091#1084#1084#1072
                Title.TitleButton = True
                Width = 73
              end
              item
                Alignment = taCenter
                EditButtons = <>
                FieldName = 'KOL'
                Footer.Alignment = taCenter
                Footer.Font.Charset = DEFAULT_CHARSET
                Footer.Font.Color = clWindowText
                Footer.Font.Height = -11
                Footer.Font.Name = 'MS Sans Serif'
                Footer.Font.Style = [fsBold]
                Footer.ValueType = fvtSum
                Footers = <>
                Title.Caption = #1050#1086#1083'-'#1074#1086
              end
              item
                EditButtons = <>
                FieldName = 'FIO'
                Footers = <>
                Title.Caption = #1040#1074#1090#1086#1088
              end
              item
                EditButtons = <>
                FieldName = 'FIOP'
                Footers = <>
                Title.Caption = #1050#1072#1089#1089#1072
              end>
          end
        end
      end
      object TabSheet3: TRzTabSheet
        Color = 16119543
        Caption = #1054#1044#1055#1055
        object Panel1: TPanel
          Left = 0
          Top = 0
          Width = 1495
          Height = 841
          Align = alClient
          BevelOuter = bvNone
          TabOrder = 0
          object workGrid2: TDBGridEh
            Left = 0
            Top = 0
            Width = 1495
            Height = 841
            Align = alClient
            Ctl3D = False
            DataSource = DS2
            Flat = True
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'MS Sans Serif'
            Font.Style = []
            FooterColor = clMoneyGreen
            FooterFont.Charset = DEFAULT_CHARSET
            FooterFont.Color = clWindowText
            FooterFont.Height = -11
            FooterFont.Name = 'MS Sans Serif'
            FooterFont.Style = []
            Options = [dgTitles, dgIndicator, dgColumnResize, dgColLines, dgRowLines, dgTabs, dgConfirmDelete, dgCancelOnExit]
            OptionsEh = [dghHighlightFocus, dghClearSelection, dghAutoSortMarking, dghRowHighlight]
            ParentCtl3D = False
            ParentFont = False
            PopupMenu = workGridPM
            SumList.Active = True
            TabOrder = 0
            TitleFont.Charset = DEFAULT_CHARSET
            TitleFont.Color = clBlack
            TitleFont.Height = -11
            TitleFont.Name = 'MS Sans Serif'
            TitleFont.Style = []
            UseMultiTitle = True
            OnCellClick = workGrid2CellClick
            OnDblClick = workGrid2DblClick
            OnDrawColumnCell = workGrid2DrawColumnCell
            OnKeyDown = workGridKeyDown
            OnKeyPress = workGridKeyPress
            OnSortMarkingChanged = workGrid2SortMarkingChanged
            Columns = <
              item
                Alignment = taCenter
                EditButtons = <>
                FieldName = 'ID'
                Footer.Alignment = taCenter
                Footer.Font.Charset = DEFAULT_CHARSET
                Footer.Font.Color = clWindowText
                Footer.Font.Height = -13
                Footer.Font.Name = 'MS Sans Serif'
                Footer.Font.Style = [fsBold]
                Footer.ValueType = fvtCount
                Footers = <>
                Title.Caption = #1050#1086#1076
                Title.TitleButton = True
                Width = 37
              end
              item
                Alignment = taCenter
                EditButtons = <>
                FieldName = 'EXP_DATE'
                Footers = <>
                Title.Caption = #1044#1072#1090#1072' '#1086#1087#1077#1088#1072#1094#1080#1081
                Title.TitleButton = True
                Width = 170
              end
              item
                EditButtons = <>
                FieldName = 'GSM'
                Footers = <>
                Title.Caption = #1058#1080#1087' '#1086#1087#1077#1088#1072#1094#1080#1081
                Title.TitleButton = True
                Width = 263
              end
              item
                Alignment = taCenter
                DisplayFormat = '0#.0#'
                EditButtons = <>
                FieldName = 'EXPENSE'
                Footer.Alignment = taCenter
                Footer.DisplayFormat = '0#.0#'
                Footer.Font.Charset = DEFAULT_CHARSET
                Footer.Font.Color = clWindowText
                Footer.Font.Height = -13
                Footer.Font.Name = 'MS Sans Serif'
                Footer.Font.Style = [fsBold]
                Footer.ValueType = fvtSum
                Footers = <>
                Title.Caption = #1057#1091#1084#1084#1072
                Title.TitleButton = True
                Width = 254
              end>
          end
        end
      end
    end
  end
  object MainMenu1: TMainMenu
    Left = 448
    Top = 40
    object N4: TMenuItem
      Caption = #1054#1090#1095#1077#1090#1099
      object N9: TMenuItem
        Caption = #1054#1090#1095#1077#1090#1099' '#1087#1086' '#1087#1086#1095#1090#1072#1083#1100#1086#1085#1072#1084
        OnClick = N9Click
      end
      object N16: TMenuItem
        Caption = #1060#1086#1088#1084#1072' '#1052#1057'-42 '#1087#1086' '#1082#1072#1089#1089#1077
        OnClick = N16Click
      end
      object N22: TMenuItem
        Caption = #1042#1077#1076#1086#1084#1086#1089#1090#1100' '#1092#1086#1088#1084#1099' 55'
        OnClick = N22Click
      end
      object N15: TMenuItem
        Caption = #1057#1090#1072#1090#1080#1089#1090#1080#1082#1072' '#1087#1086' '#1054#1057
        OnClick = N15Click
      end
      object N12: TMenuItem
        Caption = #1060#1086#1088#1084#1072' 130'
        OnClick = N12Click
      end
      object N17: TMenuItem
        Caption = #1056#1077#1077#1089#1090#1088' '#1089#1091#1084#1084' '#1087#1086' '#1082#1072#1089#1089#1077
        OnClick = N17Click
      end
      object N11: TMenuItem
        Caption = #1042#1077#1076#1086#1084#1086#1089#1090#1080
        object N13: TMenuItem
          Caption = #1042#1077#1076#1086#1084#1086#1089#1090#1100' '#1087#1086' '#1074#1099#1087#1083#1072#1090#1072#1084
          OnClick = N13Click
        end
        object N14: TMenuItem
          Caption = #1042#1077#1076#1086#1084#1086#1089#1090#1100' '#1087#1086' '#1082#1086#1083'-'#1074#1091' '#1087#1086#1088#1091#1095#1077#1085#1080#1081' '#1080' '#1082#1085#1080#1075#1072' '#1088#1072#1089#1093#1086#1076#1086#1074
          OnClick = N14Click
        end
      end
      object N23: TMenuItem
        Caption = #1047#1072#1082#1088#1099#1090#1100'\'#1054#1090#1082#1088#1099#1090#1100' '#1087#1077#1088#1080#1086#1076
        OnClick = N23Click
      end
      object N24: TMenuItem
        Caption = #1053#1072#1089#1090#1088#1086#1081#1082#1072' '#1040#1048#1057
        OnClick = N24Click
      end
    end
    object N7: TMenuItem
      Caption = #1040#1076#1084#1080#1085#1080#1089#1090#1088#1080#1088#1086#1074#1072#1085#1080#1077
      object N8: TMenuItem
        Bitmap.Data = {
          F6000000424DF600000000000000760000002800000010000000100000000100
          0400000000008000000000000000000000001000000000000000000000000000
          8000008000000080800080000000800080008080000080808000C0C0C0000000
          FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00FFFFFFF000F0
          0FFFFFFFFFFF0CF04FFFFFF000F0CCFCFFFFFFFF0AF0CCCCFFFFFFFFAAFACCCC
          FFFFFFFFBBAACCCCFFBBFFFFACCA4444FCCFBBFFAACCCCCCCCFFFAAF222CCCCC
          FFFFFFAAAAAACC0CFFFFFFFAAAAAFBBFFFFFFFFFAA0ABBBBFFFFFFFFFBBF0BB0
          FFFFFFFFBBBBF00FFFFFFFFF0BB0FFFFFFFFFFFFF00FFFFFFFFF}
        Caption = #1055#1086#1083#1100#1079#1086#1074#1072#1090#1077#1083#1080
        OnClick = N8Click
      end
      object N1: TMenuItem
        Caption = #1057#1087#1088#1072#1074#1086#1095#1085#1080#1082#1080
        object N2: TMenuItem
          Caption = #1054#1087#1077#1088#1072#1094#1080#1081
          OnClick = N2Click
        end
        object N6: TMenuItem
          Caption = #1055#1086#1095#1090#1072#1083#1100#1086#1085#1099
          OnClick = N6Click
        end
        object N5: TMenuItem
          Caption = #1050#1072#1089#1089#1099
          OnClick = N5Click
        end
      end
      object N10: TMenuItem
        Caption = #1053#1072#1089#1090#1088#1086#1081#1082#1072' '#1087#1088#1086#1075#1088#1072#1084#1084#1099' '#1085#1072' '#1086#1088#1075#1072#1085#1080#1079#1072#1094#1080#1102
        OnClick = N10Click
      end
      object N18: TMenuItem
        Caption = #1050#1086#1085#1092#1080#1075#1091#1088#1080#1088#1086#1074#1072#1085#1080#1077' '#1089#1087#1088#1072#1074#1086#1095#1085#1080#1082#1086#1074
        OnClick = N18Click
      end
      object N19: TMenuItem
        Caption = #1054#1073#1089#1083#1091#1078#1080#1074#1072#1085#1080#1077' '#1073#1072#1079#1099' '#1076#1072#1085#1085#1099#1093
        object N20: TMenuItem
          Bitmap.Data = {
            F6000000424DF600000000000000760000002800000010000000100000000100
            0400000000008000000000000000000000001000000000000000000000000000
            8000008000000080800080000000800080008080000080808000C0C0C0000000
            FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00FFFFFF0B7FFF
            FFB0FFFFFF0B7FFFFFB0FFFFFF0B7FFFFFB0FFFFFF0B7FFFFFB0000000000077
            00700FFFFFFFF00077B00FFFFFFFF00077B00000F000F00090070FFFFFFFF0F9
            99FF000000F0F099999F0FFFFFFFF99999990000F00000F999FF0FFFF0FF0FF9
            99FF0077F0FF0FF999FF0FFFF0F0FF7999FF0000000F999999FF}
          Caption = #1057#1086#1079#1076#1072#1085#1080#1077' '#1072#1088#1093#1080#1074#1072' '#1073#1072#1079#1099' '#1076#1072#1085#1085#1099#1093
          OnClick = N20Click
        end
        object N21: TMenuItem
          Bitmap.Data = {
            F6000000424DF600000000000000760000002800000010000000100000000100
            0400000000008000000000000000000000001000000000000000000000000000
            8000008000000080800080000000800080008080000080808000C0C0C0000000
            FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00FFFFFF0B7FFF
            FFB0FFFFFF0B7FFFFFB0FFFFFF0B7FFFFFB0FFFFFF0B7FFFFFB0000000000077
            00700FFFFFFFF00077B00FFFFFFFF00077B00000F000F00000070FFFFFFFF0FF
            99FF000000F0F9FF99FF0FFFFFF799F799FF0000F779999999FF0FFFF7999999
            99FF0077F0F9999999FF0FFFF0F799FFFFFF0000000FF9FFFFFF}
          Caption = #1042#1086#1089#1089#1090#1072#1085#1086#1074#1083#1077#1085#1080#1077' '#1073#1072#1079#1099' '#1080#1079' '#1072#1088#1093#1080#1074#1072
          OnClick = N21Click
        end
      end
    end
    object N3: TMenuItem
      Caption = #1042#1099#1093#1086#1076
      OnClick = N3Click
    end
  end
  object FormStorage: TFormStorage
    StoredValues = <>
    Left = 504
    Top = 48
  end
  object workSource: TDataSource
    DataSet = workDS
    Left = 152
    Top = 120
  end
  object workDS: TpFIBDataSet
    SelectSQL.Strings = (
      'select e.*, d.DESCRIPTION as DRIVER, m.DESCRIPTION as GSM'
      'from EXPENSES_TABLE e'
      'left outer join OPS_TABLE sd on sd.ID=e.SD_ID'
      'left outer join OPS_TABLE d on d.ID=e.DRIVER_ID'
      'left outer join OPER_TABLE m on m.ID=e.GSM_ID'
      '')
    Transaction = GSM_DM.readTransaction
    Database = GSM_DM.Database
    UpdateTransaction = GSM_DM.writeTransaction
    AutoCommit = True
    Left = 96
    Top = 128
  end
  object workGridPM: TPopupMenu
    MenuAnimation = [maLeftToRight, maRightToLeft, maTopToBottom, maBottomToTop, maNone]
    OnPopup = workGridPMPopup
    Left = 384
    Top = 128
    object addItem: TMenuItem
      Bitmap.Data = {
        F6000000424DF600000000000000760000002800000010000000100000000100
        0400000000008000000000000000000000001000000000000000000000000000
        8000008000000080800080000000800080008080000080808000C0C0C0000000
        FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00FFFFFCFFFFFF
        FFFFFCCCCCCFFFFFFFFFCCCCCCCCCF999999CCCCCCCCCF999999CCCCCCCFFFFF
        FFFFCCCFFCF777777777CCCF7F7777777777CCCFFFFFFFFFFFFFCCC777777777
        7777FFF7777777777777FFFFFFFFFFFFFFFFFFF7777777777777FFF777777777
        7777FFFFFFFFFFFFFFFFFFF7777777777777FFF7777777777777}
      Caption = #1044#1086#1073#1072#1074#1080#1090#1100' '#1079#1072#1087#1080#1089#1100
      ShortCut = 113
      OnClick = addItemClick
    end
    object editItem: TMenuItem
      Bitmap.Data = {
        F6000000424DF600000000000000760000002800000010000000100000000100
        0400000000008000000000000000000000001000000000000000000000000000
        8000008000000080800080000000800080008080000080808000C0C0C0000000
        FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00FFFFFFFFFFFF
        FFFF444444444444444442FFF0FF00000FF44F20FFFFFFFFFFF44F0000FFF000
        0FF44FF00F00FFFFFFF44FF0FFF03F000FF44FFF0F0233FFFFF44F0F00222330
        0FF44FFFFA222233FFF44F000FA222233FF44FFFFFFA222233F444444444A222
        23344F444F444A2222334444444444A22223FFFFFFFFFFFA2226}
      Caption = #1056#1077#1076#1072#1082#1090#1080#1088#1086#1074#1072#1090#1100
      ShortCut = 114
      OnClick = editItemClick
    end
    object delItem: TMenuItem
      Bitmap.Data = {
        F6000000424DF600000000000000760000002800000010000000100000000100
        0400000000008000000000000000000000001000000000000000000000000000
        8000008000000080800080000000800080008080000080808000C0C0C0000000
        FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00FFF777777777
        7777FFF7777777777777FFFFFFFFFFFFFFFFFFF7777777777777999777999777
        7777F999F999FFFFFFFFFF99999FFFFFFFFFFFF999CCCCCCCCCCFF99999CCCCC
        CCCCF999F999FFFFFFFF999FFF999FFFFFFFFFF7777777777777FFF777777777
        7777FFFFFFFFFFFFFFFFFFF7777777777777FFF7777777777777}
      Caption = #1059#1076#1072#1083#1080#1090#1100
      ShortCut = 115
      OnClick = delItemClick
    end
    object impItem: TMenuItem
      Bitmap.Data = {
        76010000424D7601000000000000760000002800000020000000100000000100
        0400000000000001000000000000000000001000000000000000000000000000
        8000008000000080800080000000800080008080000080808000C0C0C0000000
        FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF003333330B7FFF
        FFB0333333777F3333773333330B7FFFFFB0333333777F3333773333330B7FFF
        FFB0333333777F3333773333330B7FFFFFB03FFFFF777FFFFF77000000000077
        007077777777777777770FFFFFFFF00077B07F33333337FFFF770FFFFFFFF000
        7BB07F3FF3FFF77FF7770F00F000F00090077F77377737777F770FFFFFFFF039
        99337F3FFFF3F7F777FF0F0000F0F09999937F7777373777777F0FFFFFFFF999
        99997F3FF3FFF77777770F00F000003999337F773777773777F30FFFF0FF0339
        99337F3FF7F3733777F30F08F0F0337999337F7737F73F7777330FFFF0039999
        93337FFFF7737777733300000033333333337777773333333333}
      Caption = #1048#1084#1087#1086#1088#1090#1080#1088#1086#1074#1072#1090#1100
      ShortCut = 116
      OnClick = impItemClick
    end
  end
  object frxReport: TfrxReport
    Version = '3.24'
    DotMatrixReport = False
    IniFile = '\Software\Fast Reports'
    PreviewOptions.Buttons = [pbPrint, pbLoad, pbSave, pbExport, pbZoom, pbFind, pbOutline, pbPageSetup, pbTools, pbEdit, pbNavigator, pbExportQuick]
    PreviewOptions.Zoom = 1
    PrintOptions.Printer = 'Default'
    ReportOptions.CreateDate = 39650.5406343981
    ReportOptions.LastChange = 40428.6886991782
    ScriptLanguage = 'PascalScript'
    ScriptText.Strings = (
      'begin'
      ''
      'end.')
    Left = 104
    Top = 176
    Datasets = <
      item
        DataSet = frxDBDataset
        DataSetName = 'frxDBDataset'
      end
      item
        DataSet = frxDBDataset1
        DataSetName = 'frxDBDataset1'
      end>
    Variables = <>
    Style = <>
    object Page1: TfrxReportPage
      PaperWidth = 210
      PaperHeight = 297
      PaperSize = 9
      LeftMargin = 20
      RightMargin = 10
      TopMargin = 10
      BottomMargin = 10
      object ReportTitle1: TfrxReportTitle
        Height = 51.023655
        Top = 18.89765
        Width = 680.3154
        object Memo1: TfrxMemoView
          Width = 680.3154
          Height = 51.023655
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          HAlign = haCenter
          Memo.UTF8 = (
            '[TitleWR]')
          ParentFont = False
          VAlign = vaCenter
        end
      end
      object PageHeader1: TfrxPageHeader
        Height = 30.2362204724409
        Top = 94.48825
        Width = 680.3154
        object Memo2: TfrxMemoView
          Top = 3.66099999951075E-5
          Width = 113.3859
          Height = 30.2362204724409
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          Memo.UTF8 = (
            #1074#8222#8211' '#1056#1111'/'#1056#1111)
          VAlign = vaCenter
        end
        object Memo3: TfrxMemoView
          Left = 113.3859
          Top = 3.66099999951075E-5
          Width = 188.97637795
          Height = 30.23622047
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          Memo.UTF8 = (
            #1074#8222#8211' '#1056#176#1056#1030#1057#8218#1056#1109#1056#1112#1056#1109#1056#177#1056#1105#1056#187#1057#1039)
          VAlign = vaCenter
        end
        object Memo4: TfrxMemoView
          Left = 302.3624
          Width = 188.97640236
          Height = 30.2362204724409
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          Memo.UTF8 = (
            #1056#1114#1056#176#1057#1026#1056#1108#1056#176' '#1056#8220#1056#1038#1056#1114)
          VAlign = vaCenter
        end
        object Memo5: TfrxMemoView
          Left = 491.3389
          Top = 3.66099999951075E-5
          Width = 188.97640236
          Height = 30.2362204724409
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          Memo.UTF8 = (
            #1056#160#1056#176#1057#1027#1057#8230#1056#1109#1056#1169' '#1056#8220#1056#1038#1056#1114)
          VAlign = vaCenter
        end
      end
      object MasterData1: TfrxMasterData
        Height = 18.8976378
        Top = 249.44898
        Width = 680.3154
        DataSet = frxDBDataset
        DataSetName = 'frxDBDataset'
        RowCount = 0
        object Memo6: TfrxMemoView
          Width = 113.3859
          Height = 18.89765
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          Memo.UTF8 = (
            '[Line#]')
          VAlign = vaCenter
        end
        object Memo7: TfrxMemoView
          Left = 302.3624
          Width = 188.9765
          Height = 18.89765
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          Memo.UTF8 = (
            '[frxDBDataset."GSM"]')
          VAlign = vaCenter
        end
        object Memo8: TfrxMemoView
          Left = 491.3389
          Width = 188.9765
          Height = 18.89765
          DisplayFormat.DecimalSeparator = '.'
          DisplayFormat.FormatStr = '%2.3n'
          DisplayFormat.Kind = fkNumeric
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haRight
          Memo.UTF8 = (
            '[frxDBDataset."EXP_SUM"]')
          VAlign = vaCenter
        end
        object Memo9: TfrxMemoView
          Left = 113.3859
          Width = 188.9765
          Height = 18.89765
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -13
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight]
          HAlign = haCenter
          Memo.UTF8 = (
            '[AutoNum]')
          ParentFont = False
          VAlign = vaCenter
        end
      end
      object GroupHeader1: TfrxGroupHeader
        Height = 0.188976377952756
        Top = 226.7718
        Width = 680.3154
        Condition = 'frxDBDataset."AUTO_NUMBER"'
        KeepTogether = True
        object Memo10: TfrxMemoView
          Width = 680.3154
          Height = 0.188976377952756
          Frame.Typ = [ftBottom]
        end
      end
      object GroupFooter1: TfrxGroupFooter
        Height = 0.188976377952756
        Top = 291.02381
        Width = 680.3154
        object Memo11: TfrxMemoView
          Width = 680.3154
          Height = 0.188976377952756
          Frame.Typ = [ftTop]
        end
      end
      object ReportSummary1: TfrxReportSummary
        Height = 56.69295
        Top = 393.07112
        Width = 680.3154
        object Memo12: TfrxMemoView
          Width = 491.3389
          Height = 18.89765
          Color = clInactiveCaptionText
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -13
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haRight
          Memo.UTF8 = (
            #1056#8217#1057#1027#1056#181#1056#1110#1056#1109':')
          ParentFont = False
          VAlign = vaCenter
        end
        object Memo13: TfrxMemoView
          Left = 491.3389
          Width = 188.9765
          Height = 18.89765
          Color = clInactiveCaptionText
          DisplayFormat.DecimalSeparator = '.'
          DisplayFormat.FormatStr = '%2.3n'
          DisplayFormat.Kind = fkNumeric
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -13
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haRight
          Memo.UTF8 = (
            '[SUM(<frxDBDataset."EXP_SUM">,MasterData1)]')
          ParentFont = False
          VAlign = vaCenter
        end
        object Subreport1: TfrxSubreport
          Top = 37.7953
          Width = 680.3154
          Height = 18.89765
          Page = frxReport.Page2
        end
        object Memo16: TfrxMemoView
          Left = 304.252165
          Top = 18.89765
          Width = 187.086735
          Height = 18.89765
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -13
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          HAlign = haRight
          Memo.UTF8 = (
            #1056#1030' '#1057#8218#1056#1109#1056#1112' '#1057#8225#1056#1105#1057#1027#1056#187#1056#181':')
          ParentFont = False
          VAlign = vaCenter
        end
      end
      object GroupHeader2: TfrxGroupHeader
        Height = 18.8976378
        Top = 185.19697
        Width = 680.3154
        Condition = 'frxDBDataset."SD_NAME"'
        object Memo23: TfrxMemoView
          Width = 680.3154
          Height = 18.89765
          Color = 13434828
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -13
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          Memo.UTF8 = (
            '[frxDBDataset."SD_NAME"]')
          ParentFont = False
          VAlign = vaCenter
        end
      end
      object GroupFooter2: TfrxGroupFooter
        Height = 18.8976378
        Top = 313.70099
        Width = 680.3154
        object Memo24: TfrxMemoView
          Width = 491.3389
          Height = 18.89765
          Color = 13434828
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -13
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haRight
          Memo.UTF8 = (
            #1056#152#1057#8218#1056#1109#1056#1110#1056#1109' - [frxDBDataset."SD_NAME"]')
          ParentFont = False
          VAlign = vaCenter
        end
        object Memo25: TfrxMemoView
          Left = 491.3389
          Width = 188.9765
          Height = 18.89765
          Color = 13434828
          DisplayFormat.DecimalSeparator = '.'
          DisplayFormat.FormatStr = '%2.3n'
          DisplayFormat.Kind = fkNumeric
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -13
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haRight
          Memo.UTF8 = (
            '[SUM(<frxDBDataset."EXP_SUM">,MasterData1)]')
          ParentFont = False
          VAlign = vaCenter
        end
      end
    end
    object Page2: TfrxReportPage
      PaperWidth = 210
      PaperHeight = 297
      PaperSize = 9
      LeftMargin = 20
      RightMargin = 10
      TopMargin = 10
      BottomMargin = 10
      object MasterData2: TfrxMasterData
        Height = 18.8976378
        Top = 18.89765
        Width = 680.3154
        DataSet = frxDBDataset1
        DataSetName = 'frxDBDataset1'
        RowCount = 0
        object Memo14: TfrxMemoView
          Left = 302.3624
          Width = 188.9765
          Height = 18.89765
          Color = clInactiveCaptionText
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -13
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          Memo.UTF8 = (
            '[frxDBDataset1."GSM"]')
          ParentFont = False
          VAlign = vaCenter
        end
        object Memo15: TfrxMemoView
          Left = 491.3389
          Width = 188.9765
          Height = 18.89765
          Color = clInactiveCaptionText
          DisplayFormat.DecimalSeparator = '.'
          DisplayFormat.FormatStr = '%2.3n'
          DisplayFormat.Kind = fkNumeric
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -13
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haRight
          Memo.UTF8 = (
            '[frxDBDataset1."EXP_SUM"]')
          ParentFont = False
          VAlign = vaCenter
        end
      end
    end
  end
  object frxDBDataset: TfrxDBDataset
    UserName = 'frxDBDataset'
    CloseDataSource = False
    DataSet = repDS
    Left = 136
    Top = 176
  end
  object frxXLSExport: TfrxXLSExport
    UseFileCache = True
    ShowProgress = True
    AsText = False
    Background = True
    FastExport = True
    PageBreaks = True
    EmptyLines = True
    SuppressPageHeadersFooters = False
    Left = 72
    Top = 176
  end
  object repDS: TpFIBDataSet
    SelectSQL.Strings = (
      'SELECT'
      ' e.WAYBILL_NUMBER,'
      ' e.EXPENSE,'
      
        ' g.DESCRIPTION as GSM, a.DESCRIPTION as "AUTO", d.DESCRIPTION as' +
        ' DRIVER'
      'FROM'
      ' EXPENSES_TABLE e'
      ' left outer join GSM_TABLE g on g.id=e.gsm_id'
      ' left outer join AUTO_TABLE a on a.id=e.auto_id'
      ' left outer join DRIVERS_TABLE d on d.id=e.driver_id')
    Transaction = GSM_DM.readTransaction
    Database = GSM_DM.Database
    UpdateTransaction = GSM_DM.writeTransaction
    Left = 168
    Top = 176
  end
  object frxDBDataset1: TfrxDBDataset
    UserName = 'frxDBDataset1'
    CloseDataSource = False
    DataSet = repDS1
    Left = 136
    Top = 208
  end
  object repDS1: TpFIBDataSet
    Transaction = GSM_DM.readTransaction
    Database = GSM_DM.Database
    UpdateTransaction = GSM_DM.writeTransaction
    Left = 168
    Top = 208
  end
  object STimer: TTimer
    Enabled = False
    Interval = 1500
    OnTimer = STimerTimer
    Left = 232
    Top = 136
  end
  object S_DS: TpFIBDataSet
    AfterClose = S_DSAfterClose
    AfterOpen = S_DSAfterOpen
    Transaction = GSM_DM.readTransaction
    Database = GSM_DM.Database
    UpdateTransaction = GSM_DM.writeTransaction
    Left = 328
    Top = 208
  end
  object actionList: TActionList
    Left = 560
    Top = 208
    object action0: TAction
      Caption = 'action0'
      Enabled = False
      OnExecute = action0Execute
    end
    object action1: TAction
      Caption = 'action1'
      Enabled = False
      OnExecute = action1Execute
    end
    object action2: TAction
      Caption = 'action2'
      Enabled = False
      OnExecute = action2Execute
    end
    object action3: TAction
      Caption = 'action3'
      Enabled = False
      OnExecute = action3Execute
    end
    object action4: TAction
      Caption = 'action4'
      Enabled = False
      OnExecute = action4Execute
    end
    object action5: TAction
      Caption = 'action5'
      Enabled = False
      OnExecute = action5Execute
    end
    object action6: TAction
      Caption = 'action6'
      Enabled = False
      OnExecute = action6Execute
    end
    object action7: TAction
      Caption = 'action7'
      Enabled = False
      OnExecute = action7Execute
    end
    object action8: TAction
      Caption = 'action8'
      Enabled = False
      OnExecute = action8Execute
    end
    object action9: TAction
      Caption = 'action9'
      Enabled = False
      OnExecute = action9Execute
    end
    object action10: TAction
      Caption = 'action10'
      Enabled = False
      OnExecute = action10Execute
    end
    object action11: TAction
      Caption = 'sction11'
      Enabled = False
      OnExecute = action11Execute
    end
    object action12: TAction
      Caption = 'action12'
      OnExecute = action12Execute
    end
    object action13: TAction
      Caption = 'action13'
      OnExecute = action13Execute
    end
    object action14: TAction
      Caption = 'action14'
      OnExecute = action14Execute
    end
    object action15: TAction
      Caption = 'action15'
      OnExecute = action15Execute
    end
    object action16: TAction
      Caption = 'action16'
      OnExecute = action16Execute
    end
  end
  object workDS1: TpFIBDataSet
    SelectSQL.Strings = (
      'select e.*, d.DESCRIPTION as DRIVER, m.DESCRIPTION as GSM'
      'from EXPENSES_TABLE e'
      'left outer join OPS_TABLE sd on sd.ID=e.SD_ID'
      'left outer join OPS_TABLE d on d.ID=e.DRIVER_ID'
      'left outer join OPER_TABLE m on m.ID=e.GSM_ID')
    Transaction = GSM_DM.readTransaction
    Database = GSM_DM.Database
    UpdateTransaction = GSM_DM.writeTransaction
    AutoCommit = True
    Left = 80
    Top = 264
  end
  object workSource1: TDataSource
    DataSet = workDS1
    Left = 168
    Top = 264
  end
  object workDS2: TpFIBDataSet
    SelectSQL.Strings = (
      'select e.*, d.DESCRIPTION as DRIVER, m.DESCRIPTION as GSM'
      'from EXPENSES_TABLE e'
      'left outer join OPS_TABLE sd on sd.ID=e.SD_ID'
      'left outer join OPS_TABLE d on d.ID=e.DRIVER_ID'
      'left outer join OPER_TABLE m on m.ID=e.GSM_ID')
    Transaction = GSM_DM.readTransaction
    Database = GSM_DM.Database
    UpdateTransaction = GSM_DM.writeTransaction
    AutoCommit = True
    Left = 104
    Top = 344
  end
  object DS2: TDataSource
    DataSet = workDS2
    Left = 176
    Top = 344
  end
  object workDS3: TpFIBDataSet
    SelectSQL.Strings = (
      'select e.*, d.DESCRIPTION as DRIVER, m.DESCRIPTION as GSM'
      'from EXPENSES_TABLE e'
      'left outer join OPS_TABLE sd on sd.ID=e.SD_ID'
      'left outer join OPS_TABLE d on d.ID=e.DRIVER_ID'
      'left outer join OPER_TABLE m on m.ID=e.GSM_ID')
    Transaction = GSM_DM.readTransaction
    Database = GSM_DM.Database
    UpdateTransaction = GSM_DM.writeTransaction
    AutoCommit = True
    Left = 104
    Top = 480
  end
  object DS3: TDataSource
    DataSet = workDS3
    Left = 168
    Top = 464
  end
  object DS4: TDataSource
    DataSet = workDS4
    Left = 160
    Top = 552
  end
  object workDS4: TpFIBDataSet
    SelectSQL.Strings = (
      'select e.*, d.DESCRIPTION as DRIVER, m.DESCRIPTION as GSM'
      'from EXPENSES_TABLE e'
      'left outer join OPS_TABLE sd on sd.ID=e.SD_ID'
      'left outer join OPS_TABLE d on d.ID=e.DRIVER_ID'
      'left outer join OPER_TABLE m on m.ID=e.GSM_ID')
    Transaction = GSM_DM.readTransaction
    Database = GSM_DM.Database
    UpdateTransaction = GSM_DM.writeTransaction
    AutoCommit = True
    Left = 120
    Top = 528
  end
  object RQ_INS: TpFIBQuery
    Transaction = RT_INS
    Database = INS_DB
    Left = 840
    Top = 200
    qoAutoCommit = True
    qoStartTransaction = True
  end
  object RT_INS: TpFIBTransaction
    DefaultDatabase = INS_DB
    TimeoutAction = TARollback
    Left = 920
    Top = 200
  end
  object INS_DB: TpFIBDatabase
    DBName = 'localhost:C:\INSPECTOR\DB\NEWSALEBOOK.GDB'
    DBParams.Strings = (
      'user_name=SYSDBA'
      'password=masterkey'
      'lc_ctype=WIN1251')
    SQLDialect = 3
    Timeout = 0
    WaitForRestoreConnect = 0
    Left = 880
    Top = 144
  end
  object usersINS: TpFIBDataSet
    CachedUpdates = True
    AutoUpdateOptions.UpdateTableName = 'USERS_TABLE'
    AutoUpdateOptions.KeyFields = 'U_ID'
    AutoUpdateOptions.AutoReWriteSqls = True
    AutoUpdateOptions.CanChangeSQLs = True
    AutoUpdateOptions.GeneratorName = 'GEN_USERS_TABLE_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = RT_INS
    Database = INS_DB
    Left = 856
    Top = 272
  end
end
