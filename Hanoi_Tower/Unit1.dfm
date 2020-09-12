object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Wie'#380'a Hanoi'
  ClientHeight = 466
  ClientWidth = 538
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object PaintBox1: TPaintBox
    Tag = 20
    Left = 20
    Top = 20
    Width = 500
    Height = 285
    OnMouseMove = PaintBox1MouseMove
  end
  object Label3: TLabel
    Left = 25
    Top = 419
    Width = 53
    Height = 16
    Caption = 'Interwa'#322':'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Label1: TLabel
    Left = 25
    Top = 358
    Width = 68
    Height = 16
    Caption = 'Elementy: 8'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Button1: TButton
    Left = 173
    Top = 353
    Width = 75
    Height = 25
    Caption = 'Zainicjuj'
    TabOrder = 0
    OnClick = Button1Click
  end
  object Button3: TButton
    Left = 78
    Top = 311
    Width = 75
    Height = 25
    Caption = 'A-B'
    TabOrder = 1
    OnClick = Button3Click
  end
  object Button4: TButton
    Left = 232
    Top = 311
    Width = 75
    Height = 25
    Caption = 'B-C'
    TabOrder = 2
    OnClick = Button4Click
  end
  object Button5: TButton
    Left = 388
    Top = 311
    Width = 75
    Height = 25
    Caption = 'C-A'
    TabOrder = 3
    OnClick = Button5Click
  end
  object Button6: TButton
    Left = 445
    Top = 353
    Width = 75
    Height = 25
    Caption = 'Automat'
    TabOrder = 4
    OnClick = Button6Click
  end
  object Edit1: TEdit
    Left = 100
    Top = 416
    Width = 53
    Height = 21
    TabOrder = 5
    Text = '100'
    OnChange = Edit1Change
  end
  object StatusBar1: TStatusBar
    Left = 0
    Top = 447
    Width = 538
    Height = 19
    Panels = <
      item
        Text = 'Liczba ruch'#243'w:'
        Width = 130
      end
      item
        Width = 50
      end>
    ExplicitTop = 439
    ExplicitWidth = 565
  end
  object ProgressBar1: TProgressBar
    Left = 272
    Top = 358
    Width = 159
    Height = 20
    Max = 255
    TabOrder = 7
  end
  object TrackBar1: TTrackBar
    Left = 20
    Top = 380
    Width = 133
    Height = 28
    Max = 30
    Min = 3
    Position = 6
    TabOrder = 8
    OnChange = TrackBar1Change
  end
  object Timer1: TTimer
    Enabled = False
    Interval = 10
    OnTimer = Timer1Timer
    Left = 480
    Top = 32
  end
  object MainMenu1: TMainMenu
    Left = 456
    Top = 88
  end
end
