object ScanerForm: TScanerForm
  Left = 150
  Top = 56
  Width = 1548
  Height = 926
  Caption = #1057#1082#1072#1085#1080#1088#1086#1074#1072#1085#1080#1077'...'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -13
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  OnDestroy = FormDestroy
  OnShow = FormShow
  PixelsPerInch = 120
  TextHeight = 16
  object Panel2: TPanel
    Left = 0
    Top = 28
    Width = 1530
    Height = 828
    Align = alClient
    TabOrder = 0
    object PC: TRzPageControl
      Left = 1
      Top = 28
      Width = 1528
      Height = 799
      ActivePage = TabSheet1
      ActivePageDefault = TabSheet1
      Align = alClient
      AlignTabs = True
      BackgroundColor = 16776176
      BoldCurrentTab = True
      Color = 16119543
      UseColoredTabs = True
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
      FixedDimension = 22
      object TabSheet1: TRzTabSheet
        Color = 16119543
        Caption = #1047#1072#1076#1072#1085#1080#1103
        object Panel1: TPanel
          Left = 0
          Top = 0
          Width = 209
          Height = 773
          Align = alLeft
          BorderWidth = 2
          BorderStyle = bsSingle
          Caption = 'Panel1'
          TabOrder = 0
          object Panel3: TPanel
            Left = 3
            Top = 408
            Width = 199
            Height = 358
            Align = alBottom
            Caption = #1055#1086#1095#1090#1072#1083#1100#1086#1085#1099
            TabOrder = 0
            object selectSDBar: TJvXPBar
              Left = 1
              Top = 1
              Width = 197
              Height = 663
              Caption = #1055#1086#1095#1090#1072#1083#1100#1086#1085#1099
              Items = <
                item
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
                  OnClick = Action17Execute
                end
                item
                  OnClick = Action18Execute
                end
                item
                  OnClick = Action19Execute
                end
                item
                  OnClick = Action20Execute
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
              Align = alClient
              ParentFont = False
            end
          end
          object Panel6: TPanel
            Left = 3
            Top = 3
            Width = 199
            Height = 142
            Align = alTop
            Caption = #1044#1077#1085#1100' '#1074#1099#1087#1083#1072#1090#1099
            TabOrder = 1
            object Calendar: TCCalendar
              Left = 1
              Top = 1
              Width = 197
              Height = 140
              Align = alClient
              TabOrder = 0
              OnChange = CalendarChange
            end
          end
          object Panel8: TPanel
            Left = 3
            Top = 145
            Width = 199
            Height = 263
            Align = alClient
            Caption = #1054#1055#1057
            TabOrder = 2
            object OpsBar: TJvXPBar
              Left = 1
              Top = 1
              Width = 197
              Height = 663
              Caption = #1054#1055#1057
              Items = <
                item
                  OnClick = Action21Execute
                end
                item
                  OnClick = Action22Execute
                end
                item
                  OnClick = Action23Execute
                end
                item
                  OnClick = Action24Execute
                end
                item
                  OnClick = Action25Execute
                end
                item
                  OnClick = Action26Execute
                end
                item
                  OnClick = Action27Execute
                end
                item
                  OnClick = Action28Execute
                end
                item
                  OnClick = Action29Execute
                end
                item
                  OnClick = Action30Execute
                end
                item
                  OnClick = Action31Execute
                end
                item
                  OnClick = Action32Execute
                end
                item
                  OnClick = Action33Execute
                end
                item
                  OnClick = Action34Execute
                end
                item
                  OnClick = Action35Execute
                end
                item
                  OnClick = Action36Execute
                end
                item
                  OnClick = Action37Execute
                end
                item
                  OnClick = Action38Execute
                end
                item
                  OnClick = Action39Execute
                end
                item
                  OnClick = Action40Execute
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
              Align = alClient
              ParentFont = False
            end
          end
        end
        object Panel10: TPanel
          Left = 209
          Top = 0
          Width = 1315
          Height = 773
          Align = alClient
          Caption = 'Panel10'
          TabOrder = 1
          object Panel5: TPanel
            Left = 1
            Top = 1
            Width = 1313
            Height = 172
            Align = alTop
            TabOrder = 0
            object AccountsGrid: TDBGridEh
              Left = 1
              Top = 33
              Width = 1311
              Height = 138
              Align = alClient
              Ctl3D = False
              DataSource = AccountsS
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
              Options = [dgTitles, dgIndicator, dgColumnResize, dgColLines, dgRowLines, dgTabs, dgRowSelect, dgConfirmDelete, dgCancelOnExit]
              OptionsEh = [dghHighlightFocus, dghClearSelection, dghAutoSortMarking, dghRowHighlight]
              ParentCtl3D = False
              ParentFont = False
              PopupMenu = workGridPM
              ReadOnly = True
              SumList.Active = True
              TabOrder = 0
              TitleFont.Charset = DEFAULT_CHARSET
              TitleFont.Color = clBlack
              TitleFont.Height = -11
              TitleFont.Name = 'MS Sans Serif'
              TitleFont.Style = []
              UseMultiTitle = True
              OnCellClick = AccountsGridCellClick
              Columns = <
                item
                  EditButtons = <>
                  FieldName = 'COUNT_DATE'
                  Footers = <>
                  Title.Caption = #1044#1072#1090#1072
                end
                item
                  Alignment = taLeftJustify
                  EditButtons = <>
                  FieldName = 'COUNT_NUMBER'
                  Footers = <>
                  Title.Caption = #8470
                  Width = 25
                end
                item
                  EditButtons = <>
                  FieldName = 'CUSTOMER_NAME'
                  Footers = <>
                  Title.Caption = #1055#1086#1095#1090#1072#1083#1100#1086#1085
                end
                item
                  EditButtons = <>
                  FieldName = 'OPS_NAME'
                  Footers = <>
                  Title.Caption = #1054#1055#1057
                end
                item
                  Alignment = taCenter
                  EditButtons = <>
                  FieldName = 'COUNT_TOTALI'
                  Footers = <>
                  Title.Caption = #1054#1073#1097#1077#1077' '#1050#1086#1083'-'#1074#1086
                end
                item
                  Alignment = taCenter
                  EditButtons = <>
                  FieldName = 'COUNT_TOTAL'
                  Footers = <>
                  Title.Caption = #1054#1073#1097#1072#1103' '#1089#1091#1084#1084#1072
                end
                item
                  Alignment = taCenter
                  EditButtons = <>
                  FieldName = 'COUNT_OPL_PI'
                  Footers = <>
                  Title.Caption = #1050#1086#1083'-'#1074#1086' '#1086#1087#1083#1072#1095#1077#1085#1085#1099#1093' '#1087#1077#1085#1089#1080#1081
                end
                item
                  Alignment = taCenter
                  EditButtons = <>
                  FieldName = 'COUNT_OPL_P'
                  Footers = <>
                  Title.Caption = #1057#1091#1084#1084#1072' '#1086#1087#1083#1072#1095#1077#1085#1085#1099#1093' '#1087#1077#1085#1089#1080#1081
                end
                item
                  Alignment = taCenter
                  EditButtons = <>
                  FieldName = 'COUNT_NEOPL_PI'
                  Footers = <>
                  Title.Caption = #1050#1086#1083'-'#1074#1086' '#1085#1077#1086#1087#1083#1072#1095#1077#1085#1085#1099#1093' '#1087#1077#1085#1089#1080#1081
                  Width = 84
                end
                item
                  Alignment = taCenter
                  EditButtons = <>
                  FieldName = 'COUNT_NEOPL_P'
                  Footers = <>
                  Title.Caption = #1057#1091#1084#1084#1072' '#1085#1077#1086#1087#1083#1072#1095#1077#1085#1085#1099#1093' '#1087#1077#1085#1089#1080#1081
                  Width = 81
                end
                item
                  Alignment = taCenter
                  EditButtons = <>
                  FieldName = 'COUNT_OPL_EI'
                  Footers = <>
                  Title.Caption = #1050#1086#1083'-'#1074#1086' '#1086#1087#1083#1072#1095#1077#1085#1085#1099#1093' '#1045#1044#1050
                end
                item
                  Alignment = taCenter
                  EditButtons = <>
                  FieldName = 'COUNT_OPL_E'
                  Footers = <>
                  Title.Caption = #1057#1091#1084#1084#1072' '#1086#1087#1083#1072#1095#1077#1085#1085#1093' '#1045#1044#1050
                end
                item
                  Alignment = taCenter
                  EditButtons = <>
                  FieldName = 'COUNT_NEOPLE_I'
                  Footers = <>
                  Title.Caption = #1050#1086#1083'-'#1074#1086' '#1085#1077#1086#1087#1083#1072#1095#1077#1085#1085#1093' '#1045#1044#1050
                  Width = 76
                end
                item
                  Alignment = taCenter
                  EditButtons = <>
                  FieldName = 'COUNT_NEOPL_E'
                  Footers = <>
                  Title.Caption = #1057#1091#1084#1084#1072' '#1085#1077#1086#1087#1083#1072#1095#1077#1085#1085#1093' '#1045#1044#1050
                  Width = 71
                end
                item
                  EditButtons = <>
                  FieldName = 'AVTOR'
                  Footers = <>
                  Title.Caption = #1040#1074#1090#1086#1088
                end>
            end
            object JvNavPanelHeader2: TJvNavPanelHeader
              Left = 1
              Top = 1
              Width = 1311
              Height = 32
              Align = alTop
              Alignment = taCenter
              Caption = #1046#1091#1088#1085#1072#1083
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
          object Panel4: TPanel
            Left = 1
            Top = 173
            Width = 1313
            Height = 599
            Align = alClient
            TabOrder = 1
            object SoldGoodsGrid: TDBGridEh
              Left = 1
              Top = 26
              Width = 1311
              Height = 572
              Align = alClient
              Ctl3D = False
              DataSource = GoodsSource
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
              ReadOnly = True
              SumList.Active = True
              TabOrder = 0
              TitleFont.Charset = DEFAULT_CHARSET
              TitleFont.Color = clBlack
              TitleFont.Height = -11
              TitleFont.Name = 'MS Sans Serif'
              TitleFont.Style = []
              UseMultiTitle = True
              OnCellClick = SoldGoodsGridCellClick
              OnKeyPress = SoldGoodsGridKeyPress
              Columns = <
                item
                  EditButtons = <>
                  FieldName = 'ORDER_NUM'
                  Footers = <>
                  Title.Alignment = taLeftJustify
                  Title.Caption = #1053#1086#1084#1077#1088' '#1087#1086#1088#1091#1095#1077#1085#1080#1103
                end
                item
                  EditButtons = <>
                  FieldName = 'SYS_NUM'
                  Footers = <>
                  Title.Caption = #1057#1080#1089#1090#1077#1084#1085#1099#1081' '#1085#1086#1084#1077#1088
                end
                item
                  Alignment = taLeftJustify
                  EditButtons = <>
                  FieldName = 'SUMMA'
                  Footers = <>
                  Title.Caption = #1057#1091#1084#1084#1072' '#1082' '#1076#1086#1089#1090#1072#1074#1082#1077
                end
                item
                  EditButtons = <>
                  FieldName = 'TYPEZ'
                  Footers = <>
                  Title.Caption = #1058#1080#1087
                end
                item
                  EditButtons = <>
                  FieldName = 'PRICH'
                  Footers = <>
                  Title.Caption = #1057#1090#1072#1090#1091#1089
                end>
            end
            object JvNavPanelHeader1: TJvNavPanelHeader
              Left = 1
              Top = 1
              Width = 1311
              Height = 25
              Align = alTop
              Alignment = taCenter
              Caption = #1055#1086#1088#1091#1095#1077#1085#1080#1103
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
        Caption = #1044#1086' '#1074#1086#1089#1090#1088#1077#1073#1086#1074#1072#1085#1080#1103
        object Panel7: TPanel
          Left = 0
          Top = 0
          Width = 1524
          Height = 773
          Align = alClient
          Caption = 'Panel7'
          TabOrder = 0
          object VostrGrid: TDBGridEh
            Left = 1
            Top = 1
            Width = 1522
            Height = 730
            Align = alClient
            Ctl3D = False
            DataSource = VostrS
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
            OnCellClick = VostrGridCellClick
            OnKeyPress = VostrGridKeyPress
            Columns = <
              item
                EditButtons = <>
                FieldName = 'ORDER_NUM'
                Footers = <>
                Title.Caption = #8470' '#1087#1086#1088#1091#1095#1077#1085#1080#1103
              end>
          end
          object Panel9: TPanel
            Left = 1
            Top = 731
            Width = 1522
            Height = 41
            Align = alBottom
            Caption = 'Panel9'
            TabOrder = 1
            object DBNavigator1: TDBNavigator
              Left = 1
              Top = 1
              Width = 1520
              Height = 39
              DataSource = VostrS
              VisibleButtons = [nbFirst, nbPrior, nbNext, nbLast, nbInsert, nbDelete, nbEdit, nbPost, nbCancel]
              Align = alClient
              Flat = True
              TabOrder = 0
            end
          end
        end
      end
      object TabSheet3: TRzTabSheet
        Color = 16119543
        Caption = #1042#1099#1087#1083#1072#1090#1085#1072#1103' '#1073#1072#1079#1072
        object Panel11: TPanel
          Left = 0
          Top = 0
          Width = 1524
          Height = 773
          Align = alClient
          Caption = 'Panel7'
          TabOrder = 0
          object BazaGrid: TDBGridEh
            Left = 1
            Top = 1
            Width = 1522
            Height = 730
            Align = alClient
            Ctl3D = False
            DataSource = BazaS
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
            SumList.Active = True
            TabOrder = 0
            TitleFont.Charset = DEFAULT_CHARSET
            TitleFont.Color = clBlack
            TitleFont.Height = -11
            TitleFont.Name = 'MS Sans Serif'
            TitleFont.Style = []
            UseMultiTitle = True
            OnCellClick = BazaGridCellClick
            OnKeyPress = BazaGridKeyPress
            Columns = <
              item
                EditButtons = <>
                FieldName = 'SYS_NUM'
                Footers = <>
                Title.Caption = #1057#1080#1089#1090#1077#1084#1085#1099#1081' '#1085#1086#1084#1077#1088
              end
              item
                EditButtons = <>
                FieldName = 'ORDER_NUM'
                Footers = <>
                Title.Caption = #8470' '#1087#1086#1088#1091#1095#1077#1085#1080#1103
              end
              item
                EditButtons = <>
                FieldName = 'SUMMA'
                Footers = <>
                Title.Caption = #1057#1091#1084#1084#1072' '#1082' '#1076#1086#1089#1090#1072#1074#1082#1077
              end
              item
                EditButtons = <>
                FieldName = 'TYPEZ'
                Footers = <>
                Title.Caption = #1058#1080#1087
              end>
          end
          object Panel12: TPanel
            Left = 1
            Top = 731
            Width = 1522
            Height = 41
            Align = alBottom
            Caption = 'Panel9'
            TabOrder = 1
            object DBNavigator2: TDBNavigator
              Left = 1
              Top = 1
              Width = 1520
              Height = 39
              DataSource = BazaS
              VisibleButtons = [nbFirst, nbPrior, nbNext, nbLast]
              Align = alClient
              Flat = True
              TabOrder = 0
            end
          end
        end
      end
    end
    object MainHeader: TJvNavPanelHeader
      Left = 1
      Top = 1
      Width = 1528
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
  end
  object ButtonsPanel: TPanel
    Left = 0
    Top = 0
    Width = 1530
    Height = 28
    Align = alTop
    BevelOuter = bvNone
    Ctl3D = False
    ParentCtl3D = False
    TabOrder = 1
    DesignSize = (
      1530
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
      Visible = False
    end
    object FSButton: TSpeedButton
      Left = 1488
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
    end
    object BSButton: TSpeedButton
      Left = 1512
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
    end
    object SLabel: TLabel
      Left = 445
      Top = 6
      Width = 212
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
    object SEdit: TEdit
      Left = 666
      Top = 4
      Width = 290
      Height = 20
      Anchors = [akTop, akRight]
      AutoSelect = False
      BevelKind = bkFlat
      BevelOuter = bvRaised
      BorderStyle = bsNone
      Ctl3D = False
      ParentCtl3D = False
      TabOrder = 0
      OnChange = SEditChange
      OnKeyDown = SEditKeyDown
    end
  end
  object actionList: TActionList
    Left = 392
    Top = 224
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
      Enabled = False
      OnExecute = action12Execute
    end
    object action13: TAction
      Caption = 'action13'
      Enabled = False
      OnExecute = action13Execute
    end
    object action14: TAction
      Caption = 'action14'
      Enabled = False
      OnExecute = action14Execute
    end
    object action15: TAction
      Caption = 'action15'
      Enabled = False
      OnExecute = action15Execute
    end
    object action16: TAction
      Caption = 'action16'
      Enabled = False
      OnExecute = action16Execute
    end
    object Action17: TAction
      Caption = 'Action17'
      Enabled = False
      OnExecute = Action17Execute
    end
    object Action18: TAction
      Caption = 'Action18'
      Enabled = False
      OnExecute = Action18Execute
    end
    object Action19: TAction
      Caption = 'Action19'
      Enabled = False
      OnExecute = Action19Execute
    end
    object Action20: TAction
      Caption = 'Action20'
      Enabled = False
      OnExecute = Action20Execute
    end
    object Action21: TAction
      Caption = 'Action21'
      Enabled = False
      OnExecute = Action21Execute
    end
    object Action22: TAction
      Caption = 'Action22'
      Enabled = False
      OnExecute = Action22Execute
    end
    object Action23: TAction
      Caption = 'Action23'
      Enabled = False
      OnExecute = Action23Execute
    end
    object Action24: TAction
      Caption = 'Action24'
      Enabled = False
      OnExecute = Action24Execute
    end
    object Action25: TAction
      Caption = 'Action25'
      Enabled = False
      OnExecute = Action25Execute
    end
    object Action26: TAction
      Caption = 'Action26'
      Enabled = False
      OnExecute = Action26Execute
    end
    object Action27: TAction
      Caption = 'Action27'
      Enabled = False
      OnExecute = Action27Execute
    end
    object Action28: TAction
      Caption = 'Action28'
      Enabled = False
      OnExecute = Action28Execute
    end
    object Action29: TAction
      Caption = 'Action29'
      Enabled = False
      OnExecute = Action29Execute
    end
    object Action30: TAction
      Caption = 'Action30'
      Enabled = False
      OnExecute = Action30Execute
    end
    object Action31: TAction
      Caption = 'Action31'
      Enabled = False
      OnExecute = Action31Execute
    end
    object Action32: TAction
      Caption = 'Action32'
      Enabled = False
      OnExecute = Action32Execute
    end
    object Action33: TAction
      Caption = 'Action33'
      Enabled = False
      OnExecute = Action33Execute
    end
    object Action34: TAction
      Caption = 'Action34'
      Enabled = False
      OnExecute = Action34Execute
    end
    object Action35: TAction
      Caption = 'Action35'
      Enabled = False
      OnExecute = Action35Execute
    end
    object Action36: TAction
      Caption = 'Action36'
      Enabled = False
      OnExecute = Action36Execute
    end
    object Action37: TAction
      Caption = 'Action37'
      Enabled = False
      OnExecute = Action37Execute
    end
    object Action38: TAction
      Caption = 'Action38'
      Enabled = False
      OnExecute = Action38Execute
    end
    object Action39: TAction
      Caption = 'Action39'
      Enabled = False
      OnExecute = Action39Execute
    end
    object Action40: TAction
      Caption = 'Action40'
      Enabled = False
      OnExecute = Action40Execute
    end
  end
  object FormStorage: TFormStorage
    StoredValues = <>
    Left = 560
    Top = 144
  end
  object MainMenu1: TMainMenu
    Left = 480
    Top = 112
    object N4: TMenuItem
      Caption = #1054#1090#1095#1077#1090#1099
      object N9: TMenuItem
        Caption = #1054#1090#1095#1077#1090#1099' '#1087#1086' '#1087#1088#1086#1089#1082#1072#1085#1080#1088#1086#1074#1072#1085#1085#1099#1084' '#1096#1090#1088#1080#1093'-'#1082#1086#1076#1072#1084
      end
      object N16: TMenuItem
        Caption = #1060#1086#1088#1084#1072' '#1052#1057'-42 '#1087#1086' '#1082#1072#1089#1089#1077
      end
    end
  end
  object TempQ: TpFIBQuery
    Transaction = QT
    Database = GSM_DM.Database
    Left = 1040
    Top = 304
    qoAutoCommit = True
    qoStartTransaction = True
  end
  object TQ: TpFIBQuery
    Transaction = QT
    Database = GSM_DM.Database
    Left = 984
    Top = 312
  end
  object WQ: TpFIBQuery
    Transaction = WriteTransaction
    Database = GSM_DM.Database
    Left = 1096
    Top = 312
  end
  object WriteTransaction: TpFIBTransaction
    Active = True
    DefaultDatabase = GSM_DM.Database
    TimeoutAction = TARollback
    Left = 904
    Top = 424
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
    AutoCommit = True
    Left = 944
    Top = 304
  end
  object QT: TpFIBTransaction
    DefaultDatabase = GSM_DM.Database
    TimeoutAction = TARollback
    Left = 1144
    Top = 312
  end
  object SGTransaction: TpFIBTransaction
    Active = True
    DefaultDatabase = GSM_DM.Database
    TimeoutAction = TARollback
    Left = 952
    Top = 568
  end
  object SG_DS: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE SGB'
      'SET '
      '    ORG_ID = :ORG_ID,'
      '    COUNT_DATE = :COUNT_DATE,'
      '    COUNT_NUMBER = :COUNT_NUMBER,'
      '    ORDER_NUM = :ORDER_NUM,'
      '    SYS_NUM = :SYS_NUM,'
      '    SUMMA = :SUMMA,'
      '    TYPEZ = :TYPEZ,'
      '    M = :M,'
      '    Y = :Y,'
      '    PRICH=:PRICH'
      'WHERE'
      '    ORG_ID = :OLD_ORG_ID'
      '    and COUNT_DATE = :OLD_COUNT_DATE'
      '    and COUNT_NUMBER = :OLD_COUNT_NUMBER'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    SGB'
      'WHERE'
      '        ORG_ID = :OLD_ORG_ID'
      '    and COUNT_DATE = :OLD_COUNT_DATE'
      '    and COUNT_NUMBER = :OLD_COUNT_NUMBER'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO SGB('
      '    ORG_ID,'
      '    COUNT_DATE,'
      '    COUNT_NUMBER,'
      '    ORDER_NUM,'
      '    SYS_NUM,'
      '    SUMMA,'
      '    TYPEZ,'
      '    M,'
      '    Y,'
      '    PRICH'
      ')'
      'VALUES('
      '    :ORG_ID,'
      '    :COUNT_DATE,'
      '    :COUNT_NUMBER,'
      '    :ORDER_NUM,'
      '    :SYS_NUM,'
      '    :SUMMA,'
      '    :TYPEZ,'
      '    :M,'
      '    :Y,'
      '    :PRICH '
      ')')
    RefreshSQL.Strings = (
      'SELECT'
      '    ORG_ID,'
      '    COUNT_DATE,'
      '    COUNT_NUMBER,'
      '    ORDER_NUM,'
      '    SYS_NUM,'
      '    SUMMA,'
      '    TYPEZ,'
      '    M,'
      '    Y,'
      '    PRICH'
      'FROM'
      '    SGB '
      ''
      ' WHERE '
      '        SGB.ORG_ID = :OLD_ORG_ID'
      '    and SGB.COUNT_DATE = :OLD_COUNT_DATE'
      '    and SGB.COUNT_NUMBER = :OLD_COUNT_NUMBER'
      '    ')
    SelectSQL.Strings = (
      'SELECT'
      '    ORG_ID,'
      '    COUNT_DATE,'
      '    COUNT_NUMBER,'
      '    ORDER_NUM,'
      '    SYS_NUM,'
      '    SUMMA,'
      '    TYPEZ,'
      '    M,'
      '    Y,'
      '    PRICH '
      'FROM'
      '    SGB ')
    Transaction = SGTransaction
    Database = GSM_DM.Database
    AutoCommit = True
    DataSource = AccountsS
    Left = 1184
    Top = 312
    poSQLINT64ToBCD = True
    WaitEndMasterScroll = True
    dcForceMasterRefresh = True
    dcForceOpen = True
    object SG_DSORG_ID: TFIBSmallIntField
      FieldName = 'ORG_ID'
    end
    object SG_DSCOUNT_DATE: TFIBDateField
      FieldName = 'COUNT_DATE'
      DisplayFormat = 'dd.mm.yyyy'
    end
    object SG_DSCOUNT_NUMBER: TFIBSmallIntField
      FieldName = 'COUNT_NUMBER'
    end
    object SG_DSORDER_NUM: TFIBStringField
      FieldName = 'ORDER_NUM'
      Size = 40
      EmptyStrToNull = True
    end
    object SG_DSSYS_NUM: TFIBStringField
      FieldName = 'SYS_NUM'
      Size = 40
      EmptyStrToNull = True
    end
    object SG_DSSUMMA: TFIBFloatField
      FieldName = 'SUMMA'
    end
    object SG_DSTYPEZ: TFIBStringField
      FieldName = 'TYPEZ'
      Size = 8
      EmptyStrToNull = True
    end
    object SG_DSPRICH: TFIBStringField
      FieldName = 'PRICH'
      Size = 10
      EmptyStrToNull = True
    end
    object SG_DSM: TFIBIntegerField
      FieldName = 'M'
    end
    object SG_DSY: TFIBIntegerField
      FieldName = 'Y'
    end
  end
  object ReadTransaction: TpFIBTransaction
    Active = True
    DefaultDatabase = GSM_DM.Database
    TimeoutAction = TARollback
    Left = 904
    Top = 360
  end
  object ATransaction: TpFIBTransaction
    Active = True
    DefaultDatabase = GSM_DM.Database
    TimeoutAction = TARollback
    Left = 968
    Top = 488
  end
  object A_DS: TpFIBDataSet
    CachedUpdates = True
    SelectSQL.Strings = (
      'select t1.*, t4.U_LOGIN as Avtor from ACCOUNTS t1 '
      'left outer join USERS_TABLE t4 on t1.USER_ID=t4.U_ID'
      '')
    Transaction = ATransaction
    Database = GSM_DM.Database
    AutoCommit = True
    Left = 904
    Top = 304
    poSQLINT64ToBCD = True
    object A_DSORG_ID: TFIBSmallIntField
      DisplayWidth = 10
      FieldName = 'ORG_ID'
    end
    object A_DSCOUNT_DATE: TFIBDateField
      DisplayWidth = 10
      FieldName = 'COUNT_DATE'
      DisplayFormat = 'dd.mm.yyyy'
    end
    object A_DSCOUNT_NUMBER: TFIBSmallIntField
      DisplayWidth = 10
      FieldName = 'COUNT_NUMBER'
    end
    object A_DSCUSTOMER_ID: TFIBIntegerField
      DisplayWidth = 10
      FieldName = 'CUSTOMER_ID'
    end
    object A_DSCUSTOMER_NAME: TFIBStringField
      DisplayWidth = 22
      FieldName = 'CUSTOMER_NAME'
      Size = 120
      EmptyStrToNull = True
    end
    object A_DSUSER_ID: TFIBSmallIntField
      DisplayWidth = 10
      FieldName = 'USER_ID'
    end
    object A_DSOPS_ID: TFIBSmallIntField
      DisplayWidth = 10
      FieldName = 'OPS_ID'
    end
    object A_DSOPS_NAME: TFIBStringField
      DisplayWidth = 8
      FieldName = 'OPS_NAME'
      Size = 30
      EmptyStrToNull = True
    end
    object A_DSCOUNT_TOTALI: TFIBIntegerField
      DisplayWidth = 10
      FieldName = 'COUNT_TOTALI'
    end
    object A_DSCOUNT_TOTAL: TFIBFloatField
      DisplayWidth = 10
      FieldName = 'COUNT_TOTAL'
    end
    object A_DSCOUNT_OPL_PI: TFIBIntegerField
      DisplayWidth = 10
      FieldName = 'COUNT_OPL_PI'
    end
    object A_DSCOUNT_OPL_P: TFIBFloatField
      DisplayWidth = 10
      FieldName = 'COUNT_OPL_P'
    end
    object A_DSCOUNT_NEOPL_PI: TFIBIntegerField
      DisplayWidth = 10
      FieldName = 'COUNT_NEOPL_PI'
    end
    object A_DSCOUNT_NEOPL_P: TFIBFloatField
      DisplayWidth = 10
      FieldName = 'COUNT_NEOPL_P'
    end
    object A_DSCOUNT_OPL_EI: TFIBIntegerField
      DisplayWidth = 10
      FieldName = 'COUNT_OPL_EI'
    end
    object A_DSCOUNT_OPL_E: TFIBFloatField
      DisplayWidth = 10
      FieldName = 'COUNT_OPL_E'
    end
    object A_DSCOUNT_NEOPLE_I: TFIBIntegerField
      DisplayWidth = 10
      FieldName = 'COUNT_NEOPLE_I'
    end
    object A_DSCOUNT_NEOPL_E: TFIBFloatField
      DisplayWidth = 10
      FieldName = 'COUNT_NEOPL_E'
    end
    object A_DSM: TFIBIntegerField
      DisplayWidth = 10
      FieldName = 'M'
    end
    object A_DSY: TFIBIntegerField
      DisplayWidth = 10
      FieldName = 'Y'
    end
    object A_DSEDIT_KEY: TFIBBooleanField
      DisplayWidth = 5
      FieldName = 'EDIT_KEY'
    end
    object A_DSAVTOR: TFIBStringField
      DisplayWidth = 20
      FieldName = 'AVTOR'
      EmptyStrToNull = True
    end
  end
  object GoodsSource: TDataSource
    DataSet = SG_DS
    Left = 1136
    Top = 432
  end
  object AccountsS: TDataSource
    DataSet = A_DS
    Left = 1200
    Top = 424
  end
  object VOSTR: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE VOSTR_TABLE'
      'SET '
      '    ORDER_NUM = :ORDER_NUM'
      'WHERE'
      '    ORDER_NUM = :OLD_ORDER_NUM'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    VOSTR_TABLE'
      'WHERE'
      '        ORDER_NUM = :OLD_ORDER_NUM'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO VOSTR_TABLE('
      '    ORDER_NUM'
      ')'
      'VALUES('
      '    :ORDER_NUM'
      ')')
    RefreshSQL.Strings = (
      'SELECT'
      '    ORDER_NUM'
      'FROM'
      '    VOSTR_TABLE '
      ''
      ' WHERE '
      '        VOSTR_TABLE.ORDER_NUM = :OLD_ORDER_NUM'
      '    ')
    SelectSQL.Strings = (
      'SELECT'
      '    ORDER_NUM'
      'FROM'
      '    VOSTR_TABLE ')
    Transaction = ATransaction
    Database = GSM_DM.Database
    AutoCommit = True
    Left = 1216
    Top = 248
    poSQLINT64ToBCD = True
    object VOSTRORDER_NUM: TFIBStringField
      FieldName = 'ORDER_NUM'
      Size = 40
      EmptyStrToNull = True
    end
  end
  object VostrS: TDataSource
    DataSet = VOSTR
    Left = 1424
    Top = 416
  end
  object BAZA: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE BAZA_TABLE'
      'SET '
      '    TYPEZ = :TYPEZ,'
      '    ORDER_NUM = :ORDER_NUM,'
      '    SYS_NUM = :SYS_NUM,'
      '    SUMMA = :SUMMA,'
      '    M = :M,'
      '    Y = :Y'
      'WHERE'
      '    COD = :OLD_COD'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    BAZA_TABLE'
      'WHERE'
      '        COD = :OLD_COD'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO BAZA_TABLE('
      '    COD,'
      '    TYPEZ,'
      '    ORDER_NUM,'
      '    SYS_NUM,'
      '    SUMMA,'
      '    M,'
      '    Y'
      ')'
      'VALUES('
      '    :COD,'
      '    :TYPEZ,'
      '    :ORDER_NUM,'
      '    :SYS_NUM,'
      '    :SUMMA,'
      '    :M,'
      '    :Y'
      ')')
    RefreshSQL.Strings = (
      'SELECT'
      '    COD,'
      '    TYPEZ,'
      '    ORDER_NUM,'
      '    SYS_NUM,'
      '    SUMMA,'
      '    M,'
      '    Y'
      'FROM'
      '    BAZA_TABLE '
      ''
      ' WHERE '
      '        BAZA_TABLE.COD = :OLD_COD'
      '    ')
    SelectSQL.Strings = (
      'SELECT'
      '    COD,'
      '    TYPEZ,'
      '    ORDER_NUM,'
      '    SYS_NUM,'
      '    SUMMA,'
      '    M,'
      '    Y'
      'FROM'
      '    BAZA_TABLE ')
    Transaction = ATransaction
    Database = GSM_DM.Database
    AutoCommit = True
    Left = 1376
    Top = 312
    poSQLINT64ToBCD = True
    object BAZACOD: TFIBIntegerField
      FieldName = 'COD'
    end
    object BAZATYPEZ: TFIBStringField
      FieldName = 'TYPEZ'
      Size = 10
      EmptyStrToNull = True
    end
    object BAZAORDER_NUM: TFIBStringField
      FieldName = 'ORDER_NUM'
      Size = 40
      EmptyStrToNull = True
    end
    object BAZASYS_NUM: TFIBStringField
      FieldName = 'SYS_NUM'
      Size = 40
      EmptyStrToNull = True
    end
    object BAZASUMMA: TFIBFloatField
      FieldName = 'SUMMA'
    end
    object BAZAM: TFIBIntegerField
      FieldName = 'M'
    end
    object BAZAY: TFIBIntegerField
      FieldName = 'Y'
    end
  end
  object BazaS: TDataSource
    DataSet = BAZA
    Left = 1304
    Top = 368
  end
  object workGridPM: TPopupMenu
    MenuAnimation = [maLeftToRight, maRightToLeft, maTopToBottom, maBottomToTop, maNone]
    Left = 400
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
  end
  object STimer: TTimer
    Enabled = False
    Interval = 1500
    OnTimer = STimerTimer
    Left = 552
    Top = 392
  end
end
