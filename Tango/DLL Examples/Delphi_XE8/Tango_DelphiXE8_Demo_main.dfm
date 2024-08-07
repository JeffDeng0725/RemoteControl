object Form1: TForm1
  Left = 397
  Top = 279
  Caption = 'Delphi_XE8'
  ClientHeight = 459
  ClientWidth = 418
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poDesigned
  OnCreate = FormCreate
  OnDestroy = FormDestroy
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 8
    Top = 8
    Width = 401
    Height = 217
    TabOrder = 0
    object Button1: TButton
      Left = 256
      Top = 34
      Width = 129
      Height = 25
      Caption = 'ConnectSimple (Tango 1)'
      TabOrder = 0
      OnClick = Button1Click
    end
    object Button2: TButton
      Left = 256
      Top = 65
      Width = 129
      Height = 25
      Caption = 'Disconnect (Tango 1)'
      TabOrder = 1
      OnClick = Button2Click
    end
    object Edit1: TEdit
      Left = 272
      Top = 96
      Width = 97
      Height = 21
      TabOrder = 2
      Text = '0,1'
    end
    object Edit3: TEdit
      Left = 272
      Top = 144
      Width = 97
      Height = 21
      TabOrder = 4
      Text = '0'
    end
    object Edit2: TEdit
      Left = 272
      Top = 120
      Width = 97
      Height = 21
      TabOrder = 3
      Text = '0'
    end
    object Button5: TButton
      Left = 256
      Top = 176
      Width = 129
      Height = 25
      Caption = 'Move relative (Tango 1)'
      TabOrder = 5
      OnClick = Button5Click
    end
    object Button7: TButton
      Left = 16
      Top = 176
      Width = 205
      Height = 25
      Caption = 'Thread1: Moves without waiting for axis'
      TabOrder = 6
      OnClick = Button7Click
    end
    object CheckBox1: TCheckBox
      Left = 256
      Top = 11
      Width = 62
      Height = 17
      Caption = 'Protocol'
      TabOrder = 7
    end
    object InterfaceLS: TPageControl
      Tag = 200
      Left = 12
      Top = 16
      Width = 209
      Height = 137
      ActivePage = ts_RS232
      TabOrder = 8
      object ts_RS232: TTabSheet
        Caption = 'RS-232'
        object Label1: TLabel
          Tag = 100
          Left = 16
          Top = 18
          Width = 46
          Height = 13
          Caption = 'Com-Port:'
        end
        object Label2: TLabel
          Tag = 101
          Left = 16
          Top = 50
          Width = 46
          Height = 13
          Caption = 'Baudrate:'
        end
        object cbo_BaudRate: TComboBox
          Left = 72
          Top = 48
          Width = 113
          Height = 21
          Style = csDropDownList
          TabOrder = 0
          Items.Strings = (
            '9600'
            '19200'
            '38400'
            '57600'
            '115200')
        end
        object cbo_ComPort: TComboBox
          Left = 72
          Top = 16
          Width = 113
          Height = 21
          Style = csDropDownList
          TabOrder = 1
          Items.Strings = (
            'COM1'
            'COM2'
            'COM3'
            'COM4'
            'COM5'
            'COM6'
            'COM7'
            'COM8'
            'COM9')
        end
      end
    end
  end
  object Panel2: TPanel
    Left = 8
    Top = 232
    Width = 401
    Height = 217
    TabOrder = 1
    object Button3: TButton
      Left = 256
      Top = 34
      Width = 129
      Height = 25
      Caption = 'ConnectSimple (Tango 2)'
      TabOrder = 0
      OnClick = Button3Click
    end
    object Button4: TButton
      Left = 256
      Top = 65
      Width = 129
      Height = 25
      Caption = 'Disconnect (Tango 2)'
      TabOrder = 1
      OnClick = Button4Click
    end
    object Edit4: TEdit
      Left = 272
      Top = 96
      Width = 97
      Height = 21
      TabOrder = 2
      Text = '0,1'
    end
    object Edit5: TEdit
      Left = 272
      Top = 120
      Width = 97
      Height = 21
      TabOrder = 3
      Text = '0'
    end
    object Edit6: TEdit
      Left = 272
      Top = 144
      Width = 97
      Height = 21
      TabOrder = 4
      Text = '0'
    end
    object Button6: TButton
      Left = 256
      Top = 176
      Width = 129
      Height = 25
      Caption = 'Move relative (Tango 2)'
      TabOrder = 5
      OnClick = Button6Click
    end
    object InterfaceLS2: TPageControl
      Tag = 200
      Left = 16
      Top = 16
      Width = 205
      Height = 137
      ActivePage = ts_RS232_2
      TabOrder = 6
      object ts_RS232_2: TTabSheet
        Caption = 'RS-232'
        object Label5: TLabel
          Tag = 100
          Left = 16
          Top = 18
          Width = 46
          Height = 13
          Caption = 'Com-Port:'
        end
        object Label6: TLabel
          Tag = 101
          Left = 16
          Top = 50
          Width = 46
          Height = 13
          Caption = 'Baudrate:'
        end
        object cbo_BaudRate2: TComboBox
          Left = 72
          Top = 48
          Width = 113
          Height = 21
          Style = csDropDownList
          TabOrder = 0
          Items.Strings = (
            '9600'
            '19200'
            '38400'
            '57600'
            '115200')
        end
        object cbo_ComPort2: TComboBox
          Left = 72
          Top = 16
          Width = 113
          Height = 21
          Style = csDropDownList
          TabOrder = 1
          Items.Strings = (
            'COM1'
            'COM2'
            'COM3'
            'COM4'
            'COM5'
            'COM6'
            'COM7'
            'COM8'
            'COM9')
        end
      end
    end
    object Button8: TButton
      Left = 18
      Top = 176
      Width = 203
      Height = 25
      Caption = 'Thread2: Moves without waiting for axis'
      TabOrder = 7
      OnClick = Button8Click
    end
    object CheckBox2: TCheckBox
      Left = 256
      Top = 11
      Width = 97
      Height = 17
      Caption = 'Protocol'
      TabOrder = 8
    end
  end
end
