object ExpensesListOnAutoForm2: TExpensesListOnAutoForm2
  Left = 535
  Top = 340
  Width = 459
  Height = 189
  Caption = #1060#1086#1088#1084#1072' '#1052#1057'-42'
  Color = clBtnFace
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
  object Panel2: TPanel
    Left = 0
    Top = 103
    Width = 441
    Height = 41
    Align = alBottom
    BevelOuter = bvNone
    TabOrder = 0
    DesignSize = (
      441
      41)
    object SaveButton: TBitBtn
      Left = 274
      Top = 8
      Width = 146
      Height = 25
      Anchors = [akTop, akRight]
      Caption = #1057#1092#1086#1088#1084#1080#1088#1086#1074#1072#1090#1100
      TabOrder = 0
      OnClick = SaveButtonClick
      Glyph.Data = {
        36030000424D3603000000000000360000002800000010000000100000000100
        18000000000000030000120B0000120B00000000000000000000ED8C2E834D17
        834D17834D17834D17834D17834D17834D16834D16834D16834E17603A11FFFF
        FFFFFFFFFFFFFFFFFFFFFFB973FFE2B7FFE1B5FFE1B5FFE1B5FFE1B5FFE1B5FF
        E0B4FFE1B2FFE3B2FFE6B5865114FFFFFFFFFFFFFFFFFFFFFFFFFFB872FFE0B4
        FFA03FFFA03FFFA03FFFA13EFFA23EFFA23CFFE2ADA8A98F054B5E0735400A2B
        310C2B300B2429A5AEAFFFB872FFDFB3FFDEB0FFDEAFFFDFAEFFE2ADFFE5ACFF
        E7ABFFE7AA054C5B91E8FC00D2FF00D3FF00D6FF029AC00B2429FFB872FFE1B9
        FF9F3CFF9F3BFFE1AB9D99A1001F940021930021940C4E57B3FCFF1FDAFF07D1
        FF01CFFF00D6FF0D2B30FFB871FFE7C6FFE4BCFFE1B4FFE4AB001D93669FF900
        63FF0063FF0F5054D5FEFF64EFFF47E4FF29DEFF0EDBFF0C2B30FFB870FFEDD2
        FF9F3FFFA13BFFEAB6001D919CCEFF0774FF0168FF105152CFEEEAE7FFFFD9FE
        FFCDFDFF8FCFDC0D333AFFB770FFF3DEFFEDD4FFECCDFFEFC4001D90A9DAFF23
        8DFF1681FF0E6AC60E4F570E4E5C0F4D61124D61155363AAC0C5FFB770FFF7EB
        FFA041FFA13EFFF3D0001A90A1C8F2B3E1FFADDCFFA8D7FF74A1F10020A012CD
        00004E00FFFFFFFFFFFFFFB76FFFFDF6FFF8ECFFF5E4FFF6DB9DA4BB001B9200
        1F94001F95001E97001E9B1694441DD102003200FFFFFFFFFFFFFFB76EFFFEFC
        FFA143FFA140FFF7E8FFF8E1FFFBDF005800AEEDA5C3FDB8BCFCB3B8FCB0A6E3
        A1003A00FFFFFFFFFFFFFFB76EFFFFFEFFFEFDFFFEFCFFFCF6FFFAEFFFFAEB9D
        BB87005400005500005700005800005D00A2C4A2FFFFFFFFFFFFFFB76EFFFFFF
        FFA348FFA349FFA247FFA243FFFDF7FFFCF3FFFBF0FFFAEFFFFCEFCE7B25FFFF
        FFFFFFFFFFFFFFFFFFFFFFB870FFFFFFFFFFFFFFFFFFFFFFFFFFFFFEFFFEFDFF
        FEFDFFFDFBFFFDFAFFFDF9834E18FFFFFFFFFFFFFFFFFFFFFFFFFFC993FFB870
        FFB76FFFB76EFFB76EFFB76EFFB76EFFB66EFFB76EFFB76FFFB871ED8C2DFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF}
    end
  end
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 441
    Height = 103
    Align = alClient
    BevelOuter = bvNone
    TabOrder = 1
    object Label1: TLabel
      Tag = 12
      Left = 24
      Top = 20
      Width = 73
      Height = 16
      AutoSize = False
      Caption = #1050#1072#1089#1089#1072
    end
    object Label2: TLabel
      Tag = 12
      Left = 24
      Top = 56
      Width = 73
      Height = 16
      AutoSize = False
      Caption = #1047#1072' '#1076#1072#1090#1091
    end
    object autoNumberEdit: TComboBox
      Left = 104
      Top = 16
      Width = 305
      Height = 24
      BevelKind = bkFlat
      Style = csDropDownList
      Ctl3D = False
      DropDownCount = 50
      ItemHeight = 16
      ParentCtl3D = False
      TabOrder = 0
    end
    object Date1Edit: TDateEdit
      Tag = 13
      Left = 104
      Top = 52
      Width = 305
      Height = 21
      Ctl3D = False
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      NumGlyphs = 2
      ParentCtl3D = False
      ParentFont = False
      TabOrder = 1
    end
    object CheckBox1: TCheckBox
      Left = 80
      Top = 88
      Width = 97
      Height = 17
      Caption = #1042#1089#1077' '#1076#1072#1085#1085#1099#1077
      TabOrder = 2
    end
  end
  object FormStorage: TFormStorage
    StoredValues = <>
    Left = 8
    Top = 93
  end
  object DS: TpFIBDataSet
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
    Left = 64
    Top = 93
  end
  object DS1: TpFIBDataSet
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
    Left = 112
    Top = 88
  end
end
