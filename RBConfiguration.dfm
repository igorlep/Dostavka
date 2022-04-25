object RBConfigurationForm: TRBConfigurationForm
  Left = 227
  Top = 217
  Width = 982
  Height = 568
  Caption = #1050#1086#1085#1092#1080#1075#1091#1088#1080#1088#1086#1074#1072#1085#1080#1077' '#1089#1087#1088#1072#1074#1086#1095#1085#1080#1082#1086#1074
  Color = clWindow
  Ctl3D = False
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -13
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Scaled = False
  OnClose = FormClose
  OnDestroy = FormDestroy
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 16
  object RBSplitter: TSplitter
    Left = 0
    Top = 161
    Width = 974
    Height = 3
    Cursor = crVSplit
    Align = alTop
    ResizeStyle = rsUpdate
  end
  object RBPanel: TPanel
    Left = 0
    Top = 0
    Width = 974
    Height = 161
    Align = alTop
    BevelOuter = bvNone
    Caption = 'RBPanel'
    TabOrder = 0
    object RBGrid: TDBGridEh
      Left = 26
      Top = 27
      Width = 948
      Height = 134
      Align = alClient
      AutoFitColWidths = True
      DataSource = RBS
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      FooterColor = clWindow
      FooterFont.Charset = DEFAULT_CHARSET
      FooterFont.Color = clWindowText
      FooterFont.Height = -11
      FooterFont.Name = 'MS Sans Serif'
      FooterFont.Style = []
      OptionsEh = [dghHighlightFocus, dghClearSelection]
      ParentFont = False
      TabOrder = 0
      TitleFont.Charset = DEFAULT_CHARSET
      TitleFont.Color = clWindowText
      TitleFont.Height = -11
      TitleFont.Name = 'MS Sans Serif'
      TitleFont.Style = []
      UseMultiTitle = True
      Visible = False
      Columns = <
        item
          EditButtons = <>
          FieldName = 'RB_TABLE_NAME'
          Footers = <>
          ReadOnly = True
          Title.Caption = #1053#1072#1080#1084#1077#1085#1086#1074#1072#1085#1080#1077' '#1090#1072#1073#1083#1080#1094#1099
          Width = 103
        end
        item
          EditButtons = <>
          FieldName = 'RB_TITLE'
          Footers = <>
          Title.Caption = #1047#1072#1075#1086#1083#1086#1074#1086#1082' '#1089#1087#1088#1072#1074#1086#1095#1085#1080#1082#1072
          Width = 105
        end
        item
          Alignment = taCenter
          EditButtons = <>
          FieldName = 'KEY_FIELD_NAME'
          Footers = <>
          ReadOnly = True
          Title.Caption = #1050#1083#1102#1095#1077#1074#1086#1077' '#1087#1086#1083#1077
          Width = 74
        end
        item
          Alignment = taCenter
          EditButtons = <>
          FieldName = 'TREE_VIEWABLE'
          Footers = <>
          Title.Caption = #1055#1086#1082#1072#1079#1099#1074#1072#1090#1100'|'#1076#1077#1088#1077#1074#1086' '#1088#1072#1079#1076#1077#1083#1086#1074
          Width = 86
        end
        item
          Alignment = taCenter
          EditButtons = <>
          FieldName = 'CONTENT_VIEWABLE'
          Footers = <>
          Title.Caption = #1055#1086#1082#1072#1079#1099#1074#1072#1090#1100'|'#1089#1086#1076#1077#1088#1078#1072#1085#1080#1077' '#1079#1072#1087#1080#1089#1080
          Width = 84
        end
        item
          Alignment = taCenter
          EditButtons = <>
          FieldName = 'SEARCH_PANEL_VIEWABLE'
          Footers = <>
          Title.Caption = #1055#1086#1082#1072#1079#1099#1074#1072#1090#1100'|'#1087#1072#1085#1077#1083#1100' '#1073#1099#1089#1090#1088#1086#1075#1086' '#1087#1086#1080#1089#1082#1072
          Width = 68
        end
        item
          EditButtons = <>
          FieldName = 'DIRECT_GRID_EDIT'
          Footers = <>
          Title.Caption = #1055#1088#1072#1074#1080#1090#1100' '#1074' '#1089#1077#1090#1082#1077
        end
        item
          EditButtons = <>
          FieldName = 'SEARCHING_WITH_REGISTER'
          Footers = <>
          Title.Caption = #1048#1089#1082#1072#1090#1100' '#1089' '#1091#1095#1077#1090#1086#1084' '#1088#1077#1075#1080#1089#1090#1088#1072
        end>
    end
    object RBHeader: TJvNavPanelHeader
      Left = 0
      Top = 0
      Width = 974
      Align = alTop
      Alignment = taCenter
      Caption = #1057#1087#1088#1072#1074#1086#1095#1085#1080#1082#1080
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlue
      Font.Height = -16
      Font.Name = 'Arial'
      Font.Style = [fsBold]
      ParentFont = False
      ColorFrom = clGradientActiveCaption
      ColorTo = clWhite
      ImageIndex = 0
    end
    object RBButtonsPanel: TPanel
      Left = 0
      Top = 27
      Width = 26
      Height = 134
      Align = alLeft
      BevelOuter = bvNone
      TabOrder = 2
      object RBPostButton: TSpeedButton
        Left = 4
        Top = 4
        Width = 20
        Height = 20
        Hint = #1057#1086#1093#1088#1072#1085#1080#1090' '#1080#1079#1084#1077#1085#1077#1085#1080#1103
        Enabled = False
        Flat = True
        Glyph.Data = {
          76010000424D7601000000000000760000002800000020000000100000000100
          04000000000000010000120B0000120B00001000000000000000000000000000
          8000008000000080800080000000800080008080000080808000C0C0C0000000
          FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00555555555555
          555555555555555555555555555555555555555555FF55555555555552055555
          55555555577FF5555555555522205555555555557777F5555555555522205555
          555555557777FF5555555552222205555555555777777F555555552222220555
          5555557777777FF5555557220522205555555777757777F55555720555522055
          55557775555777FF5555555555522205555555555557777F5555555555552205
          555555555555777FF5555555555552205555555555555777FF55555555555572
          05555555555555777FF5555555555557205555555555555777FF555555555555
          5220555555555555577755555555555555555555555555555555}
        NumGlyphs = 2
        ParentShowHint = False
        ShowHint = True
        OnClick = RBPostButtonClick
      end
      object RBCancelButton: TSpeedButton
        Left = 4
        Top = 28
        Width = 20
        Height = 20
        Hint = #1086#1090#1084#1077#1085#1080#1090#1100' '#1080#1079#1084#1077#1085#1077#1085#1080#1103
        Enabled = False
        Flat = True
        Glyph.Data = {
          76010000424D7601000000000000760000002800000020000000100000000100
          0400000000000001000000000000000000001000000000000000000000000000
          8000008000000080800080000000800080008080000080808000C0C0C0000000
          FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00888888888888
          8888888888888888888888888888888888888888888888888888888188888888
          8898888188888888887888991888888888888877188888888888889991888888
          8988887771888888878888899988888898888887778888887888888899188889
          9888888877188887788888888991889988888888877188778888888888999998
          8888888888777778888888888889998888888888888777888888888888999918
          8888888888777718888888888999889188888888877788718888888999988889
          1888888777788887188888999988888899888877778888887788889998888888
          8898887778888888887888888888888888888888888888888888}
        NumGlyphs = 2
        ParentShowHint = False
        ShowHint = True
        OnClick = RBCancelButtonClick
      end
    end
  end
  object FieldsPanel: TPanel
    Left = 0
    Top = 164
    Width = 974
    Height = 370
    Align = alClient
    BevelOuter = bvNone
    TabOrder = 1
    object FieldsGrid: TDBGridEh
      Left = 26
      Top = 27
      Width = 948
      Height = 343
      Align = alClient
      AutoFitColWidths = True
      DataSource = FieldsS
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      FooterColor = clWindow
      FooterFont.Charset = DEFAULT_CHARSET
      FooterFont.Color = clWindowText
      FooterFont.Height = -11
      FooterFont.Name = 'MS Sans Serif'
      FooterFont.Style = []
      OptionsEh = [dghHighlightFocus, dghClearSelection]
      ParentFont = False
      TabOrder = 0
      TitleFont.Charset = DEFAULT_CHARSET
      TitleFont.Color = clWindowText
      TitleFont.Height = -11
      TitleFont.Name = 'MS Sans Serif'
      TitleFont.Style = []
      UseMultiTitle = True
      Columns = <
        item
          Alignment = taCenter
          EditButtons = <>
          FieldName = 'FIELD_NUM'
          Footers = <>
          Title.Caption = #8470
          Width = 36
        end
        item
          EditButtons = <>
          FieldName = 'FIELD_NAME'
          Footers = <>
          ReadOnly = True
          Title.Caption = #1053#1072#1080#1084#1077#1085#1086#1074#1072#1085#1080#1077
          Width = 103
        end
        item
          EditButtons = <>
          FieldName = 'FIELD_TITLE'
          Footers = <>
          Title.Caption = #1047#1072#1075#1086#1083#1086#1074#1086#1082
          Width = 106
        end
        item
          Alignment = taCenter
          EditButtons = <>
          FieldName = 'FIELD_TYPE'
          Footers = <>
          KeyList.Strings = (
            '1'
            '2'
            '3'
            '4'
            '5'
            '9')
          PickList.Strings = (
            #1094#1077#1083#1099#1081
            #1074#1077#1097#1077#1089#1090#1074#1077#1085#1085#1099#1081
            #1089#1080#1084#1074#1086#1083#1100#1085#1099#1081
            #1076#1072#1090#1072
            #1074#1088#1077#1084#1103
            #1089#1089#1099#1083#1072)
          Title.Caption = #1058#1080#1087
          Width = 78
        end
        item
          Alignment = taCenter
          AutoFitColWidth = False
          EditButtons = <>
          FieldName = 'FIELD_LENGTH'
          Footers = <>
          Title.Caption = #1064#1080#1088#1080'- '#1085#1072
          Width = 47
        end
        item
          Alignment = taCenter
          AutoFitColWidth = False
          EditButtons = <>
          FieldName = 'ACCESSABLE'
          Footers = <>
          Title.Caption = #1044#1086#1089'- '#1090#1091#1087'- '#1085#1086#1089#1090#1100
          Width = 48
        end
        item
          Alignment = taCenter
          AutoFitColWidth = False
          EditButtons = <>
          FieldName = 'GRID_VIEWABLE'
          Footers = <>
          Title.Caption = #1042#1099#1074#1086'- '#1076#1080#1090#1100' '#1074' '#1089#1077#1090#1082#1077
          Width = 47
        end
        item
          Alignment = taCenter
          AutoFitColWidth = False
          EditButtons = <>
          FieldName = 'EDITABLE'
          Footers = <>
          Title.Caption = #1052#1086#1078#1085#1086' '#1087#1088#1072'- '#1074#1080#1090#1100
          Width = 48
        end
        item
          Alignment = taCenter
          AutoFitColWidth = False
          EditButtons = <>
          FieldName = 'GRID_ALIGN'
          Footers = <>
          KeyList.Strings = (
            'left'
            'right'
            'center')
          PickList.Strings = (
            #1074#1083#1077#1074#1086
            #1074#1087#1088#1072#1074#1086
            #1087#1086' '#1094#1077#1085#1090#1088#1091)
          Title.Caption = #1042#1099#1088#1072#1074#1085#1080'- '#1074#1072#1085#1080#1077
          Width = 85
        end
        item
          EditButtons = <>
          FieldName = 'REFERENCE_TABLE_NAME'
          Footers = <>
          Title.Caption = #1053#1072#1080#1084#1077#1085#1086#1074#1072#1085#1080#1077' '#1089#1089#1099#1083#1086#1095#1085#1086#1081'|'#1090#1072#1073#1083#1080#1094#1099
          Width = 99
        end
        item
          EditButtons = <>
          FieldName = 'REFERENCE_FIELD_NAME'
          Footers = <>
          Title.Caption = #1053#1072#1080#1084#1077#1085#1086#1074#1072#1085#1080#1077' '#1089#1089#1099#1083#1086#1095#1085#1086#1081'|'#1082#1086#1083#1086#1085#1082#1080
          Width = 90
        end
        item
          EditButtons = <>
          FieldName = 'RETURN_FIELD_NAME'
          Footers = <>
          Title.Caption = #1053#1072#1080#1084#1077#1085#1086#1074#1072#1085#1080#1077' '#1074#1086#1079#1074#1088#1072#1097#1072#1077#1084#1086#1075#1086' '#1087#1086#1083#1103
          Width = 112
        end>
    end
    object FieldsHeader: TJvNavPanelHeader
      Left = 0
      Top = 0
      Width = 974
      Align = alTop
      Alignment = taCenter
      Caption = #1050#1086#1083#1086#1085#1082#1080' '#1089#1087#1088#1072#1074#1086#1095#1085#1080#1082#1072
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlue
      Font.Height = -16
      Font.Name = 'Arial'
      Font.Style = [fsBold]
      ParentFont = False
      ColorFrom = clWhite
      ColorTo = clGradientActiveCaption
      ImageIndex = 0
    end
    object FIButtonsPanel: TPanel
      Left = 0
      Top = 27
      Width = 26
      Height = 343
      Align = alLeft
      BevelOuter = bvNone
      TabOrder = 2
      object FIPostButton: TSpeedButton
        Left = 4
        Top = 4
        Width = 20
        Height = 20
        Hint = #1057#1086#1093#1088#1072#1085#1080#1090' '#1080#1079#1084#1077#1085#1077#1085#1080#1103
        Enabled = False
        Flat = True
        Glyph.Data = {
          76010000424D7601000000000000760000002800000020000000100000000100
          04000000000000010000120B0000120B00001000000000000000000000000000
          8000008000000080800080000000800080008080000080808000C0C0C0000000
          FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00555555555555
          555555555555555555555555555555555555555555FF55555555555552055555
          55555555577FF5555555555522205555555555557777F5555555555522205555
          555555557777FF5555555552222205555555555777777F555555552222220555
          5555557777777FF5555557220522205555555777757777F55555720555522055
          55557775555777FF5555555555522205555555555557777F5555555555552205
          555555555555777FF5555555555552205555555555555777FF55555555555572
          05555555555555777FF5555555555557205555555555555777FF555555555555
          5220555555555555577755555555555555555555555555555555}
        NumGlyphs = 2
        ParentShowHint = False
        ShowHint = True
        OnClick = FIPostButtonClick
      end
      object FICancelButton: TSpeedButton
        Left = 4
        Top = 28
        Width = 20
        Height = 20
        Hint = #1086#1090#1084#1077#1085#1080#1090#1100' '#1080#1079#1084#1077#1085#1077#1085#1080#1103
        Enabled = False
        Flat = True
        Glyph.Data = {
          76010000424D7601000000000000760000002800000020000000100000000100
          0400000000000001000000000000000000001000000000000000000000000000
          8000008000000080800080000000800080008080000080808000C0C0C0000000
          FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00888888888888
          8888888888888888888888888888888888888888888888888888888188888888
          8898888188888888887888991888888888888877188888888888889991888888
          8988887771888888878888899988888898888887778888887888888899188889
          9888888877188887788888888991889988888888877188778888888888999998
          8888888888777778888888888889998888888888888777888888888888999918
          8888888888777718888888888999889188888888877788718888888999988889
          1888888777788887188888999988888899888877778888887788889998888888
          8898887778888888887888888888888888888888888888888888}
        NumGlyphs = 2
        ParentShowHint = False
        ShowHint = True
        OnClick = FICancelButtonClick
      end
    end
  end
  object FormStorage: TFormStorage
    StoredValues = <>
    Left = 104
    Top = 112
  end
  object RBDS: TpFIBDataSet
    UpdateSQL.Strings = (
      'UPDATE RB_INFORM_TABLE'
      'SET '
      '    RB_TITLE = :RB_TITLE,'
      '    KEY_FIELD_NAME = :KEY_FIELD_NAME,'
      '    TREE_VIEWABLE = :TREE_VIEWABLE,'
      '    CONTENT_VIEWABLE = :CONTENT_VIEWABLE,'
      '    SEARCH_PANEL_VIEWABLE = :SEARCH_PANEL_VIEWABLE,'
      '    DIRECT_GRID_EDIT = :DIRECT_GRID_EDIT,'
      '    SEARCHING_WITH_REGISTER = :SEARCHING_WITH_REGISTER'
      'WHERE'
      '    RB_TABLE_NAME = :OLD_RB_TABLE_NAME'
      '    ')
    RefreshSQL.Strings = (
      'SELECT'
      '    RB_TABLE_NAME,'
      '    RB_TITLE,'
      '    KEY_FIELD_NAME,'
      '    TREE_VIEWABLE,'
      '    CONTENT_VIEWABLE,'
      '    SEARCH_PANEL_VIEWABLE,'
      '    DIRECT_GRID_EDIT,'
      '    SEARCHING_WITH_REGISTER'
      'FROM'
      '    RB_INFORM_TABLE '
      ''
      ' WHERE '
      '        RB_INFORM_TABLE.RB_TABLE_NAME = :OLD_RB_TABLE_NAME'
      '    ')
    SelectSQL.Strings = (
      'SELECT'
      '    RB_TABLE_NAME,'
      '    RB_TITLE,'
      '    KEY_FIELD_NAME,'
      '    TREE_VIEWABLE,'
      '    CONTENT_VIEWABLE,'
      '    SEARCH_PANEL_VIEWABLE,'
      '    DIRECT_GRID_EDIT,'
      '    SEARCHING_WITH_REGISTER'
      'FROM'
      '    RB_INFORM_TABLE ')
    AutoUpdateOptions.AutoReWriteSqls = True
    AutoUpdateOptions.AutoParamsToFields = True
    Transaction = GSM_DM.readTransaction
    Database = GSM_DM.Database
    UpdateTransaction = GSM_DM.writeTransaction
    AutoCommit = True
    Left = 40
    Top = 112
  end
  object FieldsDS: TpFIBDataSet
    UpdateSQL.Strings = (
      'UPDATE FIELDS_INFORMATION_TABLE'
      'SET '
      '    FIELD_NAME = :FIELD_NAME,'
      '    FIELD_TITLE = :FIELD_TITLE,'
      '    FIELD_TYPE = :FIELD_TYPE,'
      '    FIELD_LENGTH = :FIELD_LENGTH,'
      '    ACCESSABLE = :ACCESSABLE,'
      '    EDITABLE = :EDITABLE,'
      '    GRID_VIEWABLE = :GRID_VIEWABLE,'
      '    GRID_ALIGN = :GRID_ALIGN,'
      '    REFERENCE_TABLE_NAME = :REFERENCE_TABLE_NAME,'
      '    REFERENCE_FIELD_NAME = :REFERENCE_FIELD_NAME,'
      '    RETURN_FIELD_NAME = :RETURN_FIELD_NAME'
      'WHERE'
      '    TABLE_NAME = :OLD_TABLE_NAME'
      '    and FIELD_NUM = :OLD_FIELD_NUM'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    FIELDS_INFORMATION_TABLE'
      'WHERE'
      '        TABLE_NAME = :OLD_TABLE_NAME'
      '    and FIELD_NUM = :OLD_FIELD_NUM'
      '    ')
    RefreshSQL.Strings = (
      'SELECT'
      '    TABLE_NAME,'
      '    FIELD_NUM,'
      '    FIELD_NAME,'
      '    FIELD_TITLE,'
      '    FIELD_TYPE,'
      '    FIELD_LENGTH,'
      '    ACCESSABLE,'
      '    EDITABLE,'
      '    GRID_VIEWABLE,'
      '    GRID_ALIGN,'
      '    REFERENCE_TABLE_NAME,'
      '    REFERENCE_FIELD_NAME,'
      '    RETURN_FIELD_NAME'
      'FROM'
      '    FIELDS_INFORMATION_TABLE '
      'WHERE( '
      '    TABLE_NAME=:TABLE_NAME'
      
        '     ) and (     FIELDS_INFORMATION_TABLE.TABLE_NAME = :OLD_TABL' +
        'E_NAME'
      '    and FIELDS_INFORMATION_TABLE.FIELD_NUM = :OLD_FIELD_NUM'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'SELECT'
      '    TABLE_NAME,'
      '    FIELD_NUM,'
      '    FIELD_NAME,'
      '    FIELD_TITLE,'
      '    FIELD_TYPE,'
      '    FIELD_LENGTH,'
      '    ACCESSABLE,'
      '    EDITABLE,'
      '    GRID_VIEWABLE,'
      '    GRID_ALIGN,'
      '    REFERENCE_TABLE_NAME,'
      '    REFERENCE_FIELD_NAME,'
      '    RETURN_FIELD_NAME'
      'FROM'
      '    FIELDS_INFORMATION_TABLE '
      'WHERE'
      '    TABLE_NAME=?MAS_RB_TABLE_NAME')
    BeforePost = FieldsDSBeforePost
    Transaction = GSM_DM.readTransaction
    Database = GSM_DM.Database
    UpdateTransaction = GSM_DM.writeTransaction
    AutoCommit = True
    DataSource = RBS
    Left = 40
    Top = 280
  end
  object RBS: TDataSource
    DataSet = RBDS
    OnStateChange = RBSStateChange
    OnDataChange = RBSDataChange
    Left = 72
    Top = 112
  end
  object FieldsS: TDataSource
    DataSet = FieldsDS
    OnStateChange = FieldsSStateChange
    Left = 72
    Top = 280
  end
end
