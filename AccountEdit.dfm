object AccountEditForm: TAccountEditForm
  Left = 163
  Top = 197
  Width = 1395
  Height = 516
  BorderIcons = [biSystemMenu, biMinimize, biMaximize, biHelp]
  Caption = #1056#1077#1076#1072#1082#1090#1080#1088#1086#1074#1072#1085#1080#1077
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -13
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  Icon.Data = {
    0000010001001010100000000000280100001600000028000000100000002000
    00000100040000000000C0000000000000000000000000000000000000000000
    000000008000008000000080800080000000800080008080000080808000C0C0
    C0000000FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF000000
    0000000000000CCCCCCCCCCCCCC00CFFFFFFFFFFFFC00C0F000F000F00C00CFF
    FFFFFFFFFFC00C0F000F000F00C00CFFFFFFFFFFFFC00C0F000F000F00C00CFF
    FFFFFFFFFFC00C000000000000C00CF0FFF0FFF0FFC00C000000000000C00CFF
    FFFFFFFFFFC00CFFF00F0000FFC00CFFFFFFFFFFFFC00CCCCCCCCCCCCCC0C000
    0000800000008000000080000000800000008000000080000000800000008000
    000080000000800000008000000080000000800000008000000080010000}
  OldCreateOrder = False
  Scaled = False
  OnActivate = FormActivate
  OnClose = FormClose
  OnDestroy = FormDestroy
  OnShow = FormShow
  PixelsPerInch = 120
  TextHeight = 16
  object SmrtPanel1: TSmrtPanel
    Left = 0
    Top = 0
    Width = 1377
    Height = 97
    Align = alTop
    TabOrder = 0
    DesignSize = (
      1377
      97)
    object Label1: TLabel
      Tag = 13
      Left = 683
      Top = 72
      Width = 104
      Height = 16
      Alignment = taRightJustify
      Anchors = [akTop, akRight]
      AutoSize = False
      Caption = #1047#1072#1076#1072#1085#1080#1077' '#8470
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clMaroon
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label2: TLabel
      Tag = 13
      Left = 901
      Top = 72
      Width = 30
      Height = 16
      Alignment = taRightJustify
      Anchors = [akTop, akRight]
      AutoSize = False
      Caption = #1086#1090
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clMaroon
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label3: TLabel
      Tag = 13
      Left = 621
      Top = 12
      Width = 138
      Height = 16
      Alignment = taRightJustify
      Anchors = [akTop, akRight]
      AutoSize = False
      Caption = #1055#1086#1095#1090#1072#1083#1100#1086#1085
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label5: TLabel
      Tag = 13
      Left = 1187
      Top = 8
      Width = 169
      Height = 16
      Anchors = [akTop, akRight]
      AutoSize = False
      Caption = #1055#1086#1083#1100#1079#1086#1074#1072#1090#1077#1083#1100
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label18: TLabel
      Left = 32
      Top = 16
      Width = 149
      Height = 17
      Alignment = taCenter
      AutoSize = False
      Caption = #1055#1086#1080#1089#1082' '#1087#1086' '#1085#1086#1084#1077#1088#1091' '
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -12
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      WordWrap = True
    end
    object Label9: TLabel
      Tag = 12
      Left = 712
      Top = 39
      Width = 49
      Height = 18
      Alignment = taRightJustify
      Anchors = [akTop, akRight]
      AutoSize = False
      Caption = #1054#1055#1057
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object DateEdit: TDBDateTimeEditEh
      Tag = 13
      Left = 938
      Top = 68
      Width = 113
      Height = 20
      Alignment = taCenter
      Anchors = [akTop, akRight]
      Ctl3D = False
      DataField = 'COUNT_DATE'
      DataSource = AccountsTempS
      EditButtons = <>
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      Flat = True
      ParentCtl3D = False
      ParentFont = False
      TabOrder = 1
      Visible = True
      OnChange = DateEditChange
      OnKeyDown = DateEditKeyDown
      EditFormat = 'DD.MM.YYYY'
    end
    object NumberEdit: TDBEditEh
      Tag = 13
      Left = 793
      Top = 68
      Width = 103
      Height = 20
      Alignment = taCenter
      Anchors = [akTop, akRight]
      Ctl3D = False
      DataField = 'COUNT_NUMBER'
      DataSource = AccountsTempS
      EditButtons = <>
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      Flat = True
      ParentCtl3D = False
      ParentFont = False
      TabOrder = 0
      Visible = True
      OnKeyDown = NumberEditKeyDown
    end
    object CustomerEdit: TRxDBComboEdit
      Tag = 13
      Left = 765
      Top = 8
      Width = 381
      Height = 21
      Ctl3D = False
      DataField = 'CUSTOMER_NAME'
      DataSource = AccountsTempS
      DirectInput = False
      GlyphKind = gkEllipsis
      Anchors = [akTop, akRight]
      NumGlyphs = 1
      ParentCtl3D = False
      TabOrder = 2
    end
    object UserName: TStaticText
      Tag = 13
      Left = 1187
      Top = 24
      Width = 161
      Height = 22
      Anchors = [akTop, akRight]
      AutoSize = False
      BevelInner = bvNone
      BevelKind = bkFlat
      BorderStyle = sbsSingle
      TabOrder = 3
    end
    object Edit1: TEdit
      Left = 166
      Top = 14
      Width = 300
      Height = 19
      Hint = #1055#1086#1080#1089#1082' '#1087#1086' '#1085#1086#1084#1077#1088#1091' '#1076#1077#1083#1072
      AutoSelect = False
      AutoSize = False
      Constraints.MaxWidth = 300
      Constraints.MinWidth = 60
      Ctl3D = False
      ParentCtl3D = False
      ParentShowHint = False
      ShowHint = True
      TabOrder = 4
      OnChange = Edit1Change
      OnKeyPress = Edit1KeyPress
    end
    object autoNumberEdit: TComboBox
      Left = 768
      Top = 36
      Width = 233
      Height = 24
      AutoDropDown = True
      BevelKind = bkFlat
      Style = csDropDownList
      Anchors = [akTop, akRight]
      Ctl3D = False
      DropDownCount = 50
      ItemHeight = 16
      ParentCtl3D = False
      TabOrder = 5
    end
  end
  object SmrtPanel2: TSmrtPanel
    Left = 0
    Top = 331
    Width = 1377
    Height = 140
    Align = alBottom
    TabOrder = 1
    DesignSize = (
      1377
      140)
    object Label4: TLabel
      Tag = 13
      Left = 183
      Top = 8
      Width = 104
      Height = 16
      Alignment = taRightJustify
      Anchors = [akTop, akRight]
      AutoSize = False
      Caption = #1048#1090#1086#1075#1086
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clMaroon
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label6: TLabel
      Tag = 13
      Left = 107
      Top = 32
      Width = 148
      Height = 16
      Alignment = taRightJustify
      Anchors = [akTop, akRight]
      AutoSize = False
      Caption = #1050#1086#1083'-'#1074#1086' '#1087#1086#1088#1091#1095#1077#1085#1080#1081
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clMaroon
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label7: TLabel
      Tag = 13
      Left = 153
      Top = 56
      Width = 104
      Height = 16
      Alignment = taRightJustify
      Anchors = [akTop, akRight]
      AutoSize = False
      Caption = #1055#1077#1085#1089#1080#1103
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clMaroon
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label8: TLabel
      Tag = 13
      Left = 153
      Top = 80
      Width = 104
      Height = 16
      Alignment = taRightJustify
      Anchors = [akTop, akRight]
      AutoSize = False
      Caption = #1045#1044#1050
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clMaroon
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label10: TLabel
      Tag = 13
      Left = 449
      Top = 8
      Width = 104
      Height = 16
      Alignment = taRightJustify
      Anchors = [akTop, akRight]
      AutoSize = False
      Caption = #1054#1055#1051#1040#1063#1045#1053#1054
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clMaroon
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label11: TLabel
      Tag = 13
      Left = 395
      Top = 32
      Width = 104
      Height = 16
      Alignment = taRightJustify
      Anchors = [akTop, akRight]
      AutoSize = False
      Caption = #1050#1086#1083#1080#1095#1077#1089#1090#1074#1086
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clMaroon
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label12: TLabel
      Tag = 13
      Left = 395
      Top = 56
      Width = 104
      Height = 16
      Alignment = taRightJustify
      Anchors = [akTop, akRight]
      AutoSize = False
      Caption = #1055#1077#1085#1089#1080#1103
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clMaroon
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label13: TLabel
      Tag = 13
      Left = 395
      Top = 80
      Width = 104
      Height = 16
      Alignment = taRightJustify
      Anchors = [akTop, akRight]
      AutoSize = False
      Caption = #1045#1044#1050
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clMaroon
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label14: TLabel
      Tag = 13
      Left = 649
      Top = 9
      Width = 141
      Height = 16
      Alignment = taRightJustify
      Anchors = [akTop, akRight]
      AutoSize = False
      Caption = #1053#1045#1054#1055#1051#1040#1063#1045#1053#1054
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clMaroon
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label15: TLabel
      Tag = 13
      Left = 627
      Top = 33
      Width = 104
      Height = 16
      Alignment = taRightJustify
      Anchors = [akTop, akRight]
      AutoSize = False
      Caption = #1050#1086#1083#1080#1095#1077#1089#1090#1074#1086
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clMaroon
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label16: TLabel
      Tag = 13
      Left = 627
      Top = 57
      Width = 104
      Height = 16
      Alignment = taRightJustify
      Anchors = [akTop, akRight]
      AutoSize = False
      Caption = #1055#1077#1085#1089#1080#1103
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clMaroon
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label17: TLabel
      Tag = 13
      Left = 627
      Top = 81
      Width = 104
      Height = 16
      Alignment = taRightJustify
      Anchors = [akTop, akRight]
      AutoSize = False
      Caption = #1045#1044#1050
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clMaroon
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object WriteButton: TBitBtn
      Left = 972
      Top = 40
      Width = 264
      Height = 25
      Anchors = [akTop, akRight]
      Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100' '#1080' '#1079#1072#1082#1088#1099#1090#1100' '#1079#1072#1076#1072#1085#1080#1077
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 0
      OnClick = WriteButtonClick
      Glyph.Data = {
        F6000000424DF600000000000000760000002800000010000000100000000100
        0400000000008000000000000000000000001000000000000000000000000000
        8000008000000080800080000000800080008080000080808000C0C0C0000000
        FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00888888888888
        8888880000000000000880330000008803088033000000880308803300000088
        0308803300000000030880333333333333088033000000003308803088888888
        0308803088888888030880308888888803088030888888880308803088888888
        0008803088888888080880000000000000088888888888888888}
    end
    object ExitButton: TBitBtn
      Left = 972
      Top = 72
      Width = 265
      Height = 25
      Anchors = [akTop, akRight]
      Caption = #1054#1090#1082#1072#1079#1072#1090#1100#1089#1103
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 1
      OnClick = ExitButtonClick
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
    object StaticText1: TStaticText
      Tag = 13
      Left = 259
      Top = 29
      Width = 83
      Height = 22
      Alignment = taCenter
      Anchors = [akTop, akRight]
      AutoSize = False
      BevelInner = bvNone
      BevelKind = bkFlat
      BorderStyle = sbsSingle
      Caption = '0'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 2
    end
    object StaticText2: TStaticText
      Tag = 13
      Left = 509
      Top = 29
      Width = 83
      Height = 22
      Alignment = taCenter
      Anchors = [akTop, akRight]
      AutoSize = False
      BevelInner = bvNone
      BevelKind = bkFlat
      BorderStyle = sbsSingle
      Caption = '0'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 3
    end
    object StaticText3: TStaticText
      Tag = 13
      Left = 739
      Top = 29
      Width = 83
      Height = 22
      Alignment = taCenter
      Anchors = [akTop, akRight]
      AutoSize = False
      BevelInner = bvNone
      BevelKind = bkFlat
      BorderStyle = sbsSingle
      Caption = '0'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 4
    end
    object StaticText4: TStaticText
      Tag = 13
      Left = 259
      Top = 53
      Width = 83
      Height = 22
      Hint = '#0.00'
      Alignment = taCenter
      Anchors = [akTop, akRight]
      AutoSize = False
      BevelInner = bvNone
      BevelKind = bkFlat
      BorderStyle = sbsSingle
      Caption = '0.00'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 5
    end
    object StaticText5: TStaticText
      Tag = 13
      Left = 259
      Top = 77
      Width = 83
      Height = 22
      Alignment = taCenter
      Anchors = [akTop, akRight]
      AutoSize = False
      BevelInner = bvNone
      BevelKind = bkFlat
      BorderStyle = sbsSingle
      Caption = '0.00'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 6
    end
    object StaticText7: TStaticText
      Tag = 13
      Left = 509
      Top = 53
      Width = 83
      Height = 22
      Alignment = taCenter
      Anchors = [akTop, akRight]
      AutoSize = False
      BevelInner = bvNone
      BevelKind = bkFlat
      BorderStyle = sbsSingle
      Caption = '0.00'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 7
    end
    object StaticText8: TStaticText
      Tag = 13
      Left = 509
      Top = 77
      Width = 83
      Height = 22
      Alignment = taCenter
      Anchors = [akTop, akRight]
      AutoSize = False
      BevelInner = bvNone
      BevelKind = bkFlat
      BorderStyle = sbsSingle
      Caption = '0.00'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 8
    end
    object StaticText9: TStaticText
      Tag = 13
      Left = 739
      Top = 53
      Width = 83
      Height = 22
      Alignment = taCenter
      Anchors = [akTop, akRight]
      AutoSize = False
      BevelInner = bvNone
      BevelKind = bkFlat
      BorderStyle = sbsSingle
      Caption = '0.00'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 9
    end
    object StaticText10: TStaticText
      Tag = 13
      Left = 739
      Top = 77
      Width = 83
      Height = 22
      Alignment = taCenter
      Anchors = [akTop, akRight]
      AutoSize = False
      BevelInner = bvNone
      BevelKind = bkFlat
      BorderStyle = sbsSingle
      Caption = '0.00'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 10
    end
  end
  object SmrtPanel3: TSmrtPanel
    Left = 0
    Top = 97
    Width = 1377
    Height = 234
    Align = alClient
    TabOrder = 2
    object SmrtPanel4: TSmrtPanel
      Left = 1
      Top = 1
      Width = 28
      Height = 232
      Align = alLeft
      TabOrder = 0
      object DelButton: TSpeedButton
        Left = 4
        Top = 70
        Width = 20
        Height = 20
        Hint = #1059#1076#1072#1083#1080#1090#1100' '#1090#1077#1082#1091#1097#1077#1077' '#1087#1086#1088#1091#1095#1077#1085#1080#1077
        Flat = True
        Glyph.Data = {
          76010000424D7601000000000000760000002800000020000000100000000100
          0400000000000001000000000000000000001000000000000000000000000000
          8000008000000080800080000000800080008080000080808000C0C0C0000000
          FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00FFF777777777
          7777FFF7777777777777FFF7777777777777FFF7777777777777FFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFF7777777777777FFF7777777777777999777999777
          77777777777777777777F999F999FFFFFFFFF777F777FFFFFFFFFF99999FFFFF
          FFFFFF77777FFFFFFFFFFFF999CCCCCCCCCCFFF7777777777777FF99999CCCCC
          CCCCFFF7777777777777F999F999FFFFFFFFF777F777FFFFFFFF999FFF999FFF
          FFFF777FFF777FFFFFFFFFF7777777777777FFF7777777777777FFF777777777
          7777FFF7777777777777FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF777777777
          7777FFF7777777777777FFF7777777777777FFF7777777777777}
        NumGlyphs = 2
        ParentShowHint = False
        ShowHint = True
        OnClick = DelButtonClick
      end
      object SaveButton: TSpeedButton
        Left = 4
        Top = 4
        Width = 20
        Height = 20
        Hint = #1047#1072#1087#1080#1089#1072#1090#1100
        Flat = True
        Glyph.Data = {
          76010000424D7601000000000000760000002800000020000000100000000100
          0400000000000001000000000000000000001000000000000000000000000000
          8000008000000080800080000000800080008080000080808000C0C0C0000000
          FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00888888888888
          8888888888888888888882882222282222888788777778777788882088888888
          888888778888888888888800008882222288887777888777778888800F008888
          888888877F77888888888880FFF0388222888887FFF73887778888880F023388
          888888887F78338888888888002223388888888877888338888888888A222233
          88888888878888338888888888A22223388888888878888338888888888A2222
          3388888888878888338888888888A22223388888888878888338888888888A22
          223888888888878888388888888888A22228888888888878887888888888888A
          2228888888888887777888888888888888888888888888888888}
        NumGlyphs = 2
        ParentShowHint = False
        ShowHint = True
        OnClick = SaveButtonClick
      end
      object CancelButton: TSpeedButton
        Left = 4
        Top = 47
        Width = 20
        Height = 19
        Hint = #1054#1090#1084#1077#1085#1080#1090#1100
        Flat = True
        Glyph.Data = {
          76010000424D7601000000000000760000002800000020000000100000000100
          0400000000000001000000000000000000001000000000000000000000000000
          8000008000000080800080000000800080008080000080808000C0C0C0000000
          FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00888888888888
          8888888888888888888889982222992222888778777777777788899988899988
          8888877788877788888888999099922222888877777777777788888999998888
          8888888777777888888888809990388222888887777738877788888999993388
          888888877777338888888899909993388888887777777338888889998A299933
          88888777878777338888899888A29923388887788878778338888888888A2222
          3388888888878888338888888888A22223388888888878888338888888888A22
          223888888888878888388888888888A22228888888888878887888888888888A
          2228888888888887777888888888888888888888888888888888}
        NumGlyphs = 2
        ParentShowHint = False
        ShowHint = True
        OnClick = CancelButtonClick
      end
      object EditButton: TSpeedButton
        Left = 3
        Top = 24
        Width = 20
        Height = 20
        Hint = #1056#1077#1076#1072#1082#1090#1080#1088#1086#1074#1072#1090#1100
        Flat = True
        Glyph.Data = {
          76010000424D7601000000000000760000002800000020000000100000000100
          0400000000000001000000000000000000001000000000000000000000000000
          8000008000000080800080000000800080008080000080808000C0C0C0000000
          FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00FFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF2FF44444444
          444FF7FF44444444444F4F20FFFFFFFFFF4F4F88FFFFFFFFFF4F4F0000FFFF00
          0F4F4F8888FFFF000F4F4FF00F00FFFFFF4F4FF88F00FFFFFF4F4FF0FFF03F00
          0F4F4FF8FFF07F000F4F4FFF0F0233FFFF4F4FFF8F0873FFFF4F4F0F00222330
          0F4F4F0F888883300F4F4FFFFA222233FF4F4FFFF7888833FF4F4F000FA22223
          3F4F4F000F7888833F4F4FFFFFFA2222334F4FFFFFF78888774F44444444A222
          233F444444447888877F4F444F444A22223F4F444F444788887F4444444444A2
          222F444444444478888FFFFFFFFFFFFA222FFFFFFFFFFFF7888F}
        NumGlyphs = 2
        ParentShowHint = False
        ShowHint = True
        OnClick = EditButtonClick
      end
      object DelAllButton: TSpeedButton
        Left = 6
        Top = 96
        Width = 17
        Height = 20
        Hint = #1059#1076#1072#1083#1080#1090#1100' '#1074#1089#1077' '#1087#1086#1088#1091#1095#1077#1085#1080#1103'...'
        Flat = True
        Glyph.Data = {
          66010000424D6601000000000000760000002800000014000000140000000100
          040000000000F000000000000000000000001000000010000000000000000000
          8000008000000080800080000000800080008080000080808000C0C0C0000000
          FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00888888888888
          8888888800008888888888888888889800008898888888888888898800008899
          88777777777798880000889990000000000998880000888990BFFFBFFF998888
          0000888899FCCCCCCF97888800008888999FBFFFB9978888000088888999CCC9
          990788880000888880999FB99F0788880000888880FC9999CF07888800008888
          80FF9999BF0788880000888880FC9999000788880000888880B99F099F078888
          0000888880999F099998888800008888999FBF0F089988880000889999000000
          8889988800008899988888888888898800008888888888888888889800008888
          88888888888888880000}
        ParentShowHint = False
        ShowHint = True
        OnClick = DelAllButtonClick
      end
    end
    object SoldGoodsGrid: TDBGridEh
      Left = 29
      Top = 1
      Width = 1347
      Height = 232
      Align = alClient
      AutoFitColWidths = True
      Color = clWhite
      ColumnDefValues.AlwaysShowEditButton = True
      ColumnDefValues.AutoDropDown = True
      ColumnDefValues.DblClickNextVal = True
      ColumnDefValues.DropDownShowTitles = True
      Ctl3D = False
      DataSource = SoldGoodsS
      Flat = True
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      FooterColor = 16776176
      FooterFont.Charset = DEFAULT_CHARSET
      FooterFont.Color = clWindowText
      FooterFont.Height = -13
      FooterFont.Name = 'MS Sans Serif'
      FooterFont.Style = [fsBold]
      FooterRowCount = 1
      HorzScrollBar.Tracking = True
      ImeMode = imHira
      Options = [dgEditing, dgAlwaysShowEditor, dgTitles, dgIndicator, dgColumnResize, dgColLines, dgRowLines, dgTabs, dgAlwaysShowSelection]
      OptionsEh = [dghFixed3D, dghFooter3D, dghData3D, dghHighlightFocus, dghTraceColSizing, dghRowHighlight]
      ParentCtl3D = False
      ParentFont = False
      SumList.Active = True
      TabOrder = 1
      TitleFont.Charset = DEFAULT_CHARSET
      TitleFont.Color = clWindowText
      TitleFont.Height = -13
      TitleFont.Name = 'MS Sans Serif'
      TitleFont.Style = []
      UseMultiTitle = True
      OnGetCellParams = SoldGoodsGridGetCellParams
      OnKeyDown = SoldGoodsGridKeyDown
      Columns = <
        item
          EditButtons = <>
          FieldName = 'ORDER_NUM'
          Footers = <>
          Title.Caption = #8470' '#1087#1086#1088#1091#1095#1077#1085#1080#1103
          Title.Font.Charset = DEFAULT_CHARSET
          Title.Font.Color = clWindowText
          Title.Font.Height = -13
          Title.Font.Name = 'MS Sans Serif'
          Title.Font.Style = [fsBold]
        end
        item
          EditButtons = <>
          FieldName = 'SYS_NUM'
          Footers = <>
          Title.Caption = #8470' '#1089#1080#1089#1090#1077#1084#1085#1099#1081
          Title.Font.Charset = DEFAULT_CHARSET
          Title.Font.Color = clWindowText
          Title.Font.Height = -13
          Title.Font.Name = 'MS Sans Serif'
          Title.Font.Style = [fsBold]
        end
        item
          EditButtons = <>
          FieldName = 'SUMMA'
          Footers = <>
          Title.Caption = #1057#1091#1084#1084#1072' '#1082' '#1086#1087#1083#1072#1090#1077
          Title.Font.Charset = DEFAULT_CHARSET
          Title.Font.Color = clWindowText
          Title.Font.Height = -13
          Title.Font.Name = 'MS Sans Serif'
          Title.Font.Style = [fsBold]
        end
        item
          EditButtons = <>
          FieldName = 'TYPEZ'
          Footers = <>
          Title.Caption = #1058#1080#1087
          Title.Font.Charset = DEFAULT_CHARSET
          Title.Font.Color = clWindowText
          Title.Font.Height = -13
          Title.Font.Name = 'MS Sans Serif'
          Title.Font.Style = [fsBold]
        end
        item
          EditButtons = <>
          FieldName = 'PRICH'
          Footers = <>
          Title.Caption = #1057#1090#1072#1090#1091#1089
          Title.Font.Charset = DEFAULT_CHARSET
          Title.Font.Color = clWindowText
          Title.Font.Height = -13
          Title.Font.Name = 'MS Sans Serif'
          Title.Font.Style = [fsBold]
        end>
    end
  end
  object AccountsTempS: TDataSource
    DataSet = AccountsTempDS
    Left = 352
    Top = 128
  end
  object SoldGoodsS: TDataSource
    DataSet = SoldGoodsDS
    OnStateChange = SoldGoodsSStateChange
    OnDataChange = SoldGoodsSDataChange
    Left = 568
    Top = 128
  end
  object FormStorage1: TFormStorage
    StoredValues = <>
    Left = 200
    Top = 240
  end
  object AccountsTempDS: TpFIBDataSet
    UpdateSQL.Strings = (
      'UPDATE ACCOUNTS_TEMP'
      'SET '
      '    COUNT_DATE = :COUNT_DATE,'
      '    COUNT_NUMBER = :COUNT_NUMBER,'
      '    CUSTOMER_ID = :CUSTOMER_ID,'
      '    USER_ID = :USER_ID,'
      '    OPS_ID = :OPS_ID'
      'WHERE'
      '    ORG_ID = :OLD_ORG_ID'
      '    and COUNT_DATE = :OLD_COUNT_DATE'
      '    and COUNT_NUMBER = :OLD_COUNT_NUMBER'
      '    '
      ' ')
    InsertSQL.Strings = (
      
        'insert into ACCOUNTS_TEMP(ORG_ID,COUNT_DATE,COUNT_NIMBER) valies' +
        '(:ORG_ID,:COUNT_DATE,:COUNT_NUMBER)')
    RefreshSQL.Strings = (
      'SELECT'
      '    ORG_ID,'
      '    COUNT_DATE,'
      '    COUNT_NUMBER,'
      '    CUSTOMER_ID,'
      '    USER_ID,'
      '    OPS_ID'
      'FROM'
      '    ACCOUNTS_TEMP '
      ' WHERE '
      '    ACCOUNTS_TEMP.ORG_ID = :OLD_ORG_ID'
      '    and ACCOUNTS_TEMP.COUNT_DATE = :OLD_COUNT_DAYE'
      '    and ACCOUNTS_TEMP.COUNT_NUMBER = :OLD_COUNT_NUMBER'
      '    ')
    AutoUpdateOptions.UpdateTableName = 'ACCOUNTS'
    AutoUpdateOptions.AutoParamsToFields = True
    Transaction = AccountsT
    Database = GSM_DM.Database
    UpdateTransaction = GSM_DM.writeTransaction
    AutoCommit = True
    Left = 360
    Top = 192
    poSQLINT64ToBCD = True
  end
  object SoldGoodsDS: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE SGBT'
      'SET '
      '    PRICH = :PRICH'
      'WHERE'
      '    ORDER_NUM = :ORDER_NUM'
      '    AND SYS_NUM = :OLD_SYSNUM'
      '')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    SGBT'
      'WHERE'
      '        USER_ID = :OLD_USER_ID'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO SGBT('
      '    ORDER_NUM,'
      '    SYS_NUM,'
      '    SUMMA,'
      '    TYPEZ,'
      '    M,'
      '    Y,'
      '    PRICH'
      ')'
      'VALUES('
      '    :ORDER_NUM,'
      '    :SYS_NUM,'
      '    :SUMMA,'
      '    :TYPEZ,'
      '    :M,'
      '    :Y,'
      '    :PRICH'
      ')')
    RefreshSQL.Strings = (
      'SELECT *'
      'FROM'
      '    SGBT g'
      'where(  g.USER_ID=?MAS_USER_ID'
      '     ) and (     G.SYS_NUM = :OLD_SYS_NUM'
      '     )'
      '    '
      '  ')
    SelectSQL.Strings = (
      'SELECT *'
      'FROM'
      '    SGBT g'
      'where g.USER_ID=?MAS_USER_ID'
      '  ')
    AutoUpdateOptions.AutoReWriteSqls = True
    AutoUpdateOptions.CanChangeSQLs = True
    AutoUpdateOptions.AutoParamsToFields = True
    Transaction = SouldGoodsT
    Database = GSM_DM.Database
    UpdateTransaction = GSM_DM.writeTransaction
    AutoCommit = True
    DataSource = AccountsTempS
    Left = 568
    Top = 184
    poSQLINT64ToBCD = True
    oRefreshAfterPost = False
    object SoldGoodsDSUSER_ID: TFIBSmallIntField
      FieldName = 'USER_ID'
    end
    object SoldGoodsDSORDER_NUM: TFIBStringField
      FieldName = 'ORDER_NUM'
      Size = 40
      EmptyStrToNull = True
    end
    object SoldGoodsDSSYS_NUM: TFIBStringField
      FieldName = 'SYS_NUM'
      Size = 40
      EmptyStrToNull = True
    end
    object SoldGoodsDSSUMMA: TFIBFloatField
      FieldName = 'SUMMA'
    end
    object SoldGoodsDSTYPEZ2: TFIBStringField
      FieldName = 'TYPEZ'
      Size = 8
      EmptyStrToNull = True
    end
    object SoldGoodsDSPRICH: TFIBStringField
      FieldName = 'PRICH'
      Size = 10
      EmptyStrToNull = True
    end
    object SoldGoodsDSM: TFIBIntegerField
      FieldName = 'M'
    end
    object SoldGoodsDSY: TFIBIntegerField
      FieldName = 'Y'
    end
  end
  object TempQ: TpFIBQuery
    Transaction = DT
    Database = GSM_DM.Database
    Left = 64
    Top = 288
    qoAutoCommit = True
    qoStartTransaction = True
  end
  object TQ: TpFIBQuery
    Transaction = WT
    Database = GSM_DM.Database
    ParamCheck = False
    Left = 136
    Top = 184
    qoAutoCommit = True
  end
  object WT: TpFIBTransaction
    DefaultDatabase = GSM_DM.Database
    Timeout = 5
    TimeoutAction = TARollbackRetaining
    TPBMode = tpbDefault
    Left = 136
    Top = 240
  end
  object AccountsT: TpFIBTransaction
    Active = True
    DefaultDatabase = GSM_DM.Database
    TimeoutAction = TARollback
    Left = 360
    Top = 256
  end
  object SouldGoodsT: TpFIBTransaction
    Active = True
    DefaultDatabase = GSM_DM.Database
    TimeoutAction = TARollback
    Left = 560
    Top = 240
  end
  object DT: TpFIBTransaction
    DefaultDatabase = GSM_DM.Database
    TimeoutAction = TARollback
    Left = 136
    Top = 296
  end
  object searchTimer: TTimer
    Enabled = False
    Interval = 2000
    OnTimer = searchTimerTimer
    Left = 200
    Top = 184
  end
  object NDOST: TpFIBDataSet
    UpdateSQL.Strings = (
      'UPDATE ACCOUNTS_TEMP'
      'SET '
      '    COUNT_DATE = :COUNT_DATE,'
      '    COUNT_NUMBER = :COUNT_NUMBER,'
      '    CUSTOMER_ID = :CUSTOMER_ID,'
      '    USER_ID = :USER_ID,'
      '    COUNT_TYPE = :COUNT_TYPE'
      'WHERE'
      '    ORG_ID = :OLD_ORG_ID'
      '    and COUNT_DATE = :OLD_COUNT_DATE'
      '    and COUNT_NUMBER = :OLD_COUNT_NUMBER'
      '    ')
    InsertSQL.Strings = (
      
        'insert into ACCOUNTS_TEMP(ORG_ID,COUNT_DATE,COUNT_NIMBER) valies' +
        '(:ORG_ID,:COUNT_DATE,:COUNT_NUMBER)')
    RefreshSQL.Strings = (
      'SELECT'
      '    ORG_ID,'
      '    COUNT_DATE,'
      '    COUNT_NUMBER,'
      '    CUSTOMER_ID,'
      '    USER_ID,'
      '    COUNT_TYPE'
      'FROM'
      '    ACCOUNTS_TEMP '
      ' WHERE '
      '    ACCOUNTS_TEMP.ORG_ID = :OLD_ORG_ID'
      '    and ACCOUNTS_TEMP.COUNT_DATE = :OLD_COUNT_DAYE'
      '    and ACCOUNTS_TEMP.COUNT_NUMBER = :OLD_COUNT_NUMBER'
      '    ')
    AutoUpdateOptions.UpdateTableName = 'ACCOUNTS'
    AutoUpdateOptions.AutoParamsToFields = True
    Transaction = AccountsT
    Database = GSM_DM.Database
    UpdateTransaction = GSM_DM.writeTransaction
    AutoCommit = True
    Left = 464
    Top = 128
    poSQLINT64ToBCD = True
  end
  object DB1: TpFIBDataSet
    UpdateSQL.Strings = (
      'UPDATE '
      'SET '
      'WHERE'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    '
      'WHERE'
      '        ')
    InsertSQL.Strings = (
      'INSERT INTO ('
      ')'
      'VALUES('
      ')')
    Transaction = ReadTransaction
    Database = GSM_DM.Database
    UpdateTransaction = GSM_DM.writeTransaction
    AutoCommit = True
    Left = 64
    Top = 232
  end
  object ReadTransaction: TpFIBTransaction
    Active = True
    DefaultDatabase = GSM_DM.Database
    TimeoutAction = TARollback
    Left = 64
    Top = 184
  end
end
