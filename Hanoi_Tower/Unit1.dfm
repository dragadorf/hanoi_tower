object Form1: TForm1
  Left = 0
  Top = 0
  AutoSize = True
  Caption = 'Wie'#380'a Hanoi'
  ClientHeight = 450
  ClientWidth = 502
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
  object StatusBar1: TStatusBar
    Left = 0
    Top = 431
    Width = 502
    Height = 19
    Panels = <
      item
        Text = 'Liczba ruch'#243'w:'
        Width = 130
      end
      item
        Width = 50
      end>
    ExplicitTop = 307
    ExplicitWidth = 304
  end
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 502
    Height = 289
    Align = alTop
    TabOrder = 1
    ExplicitWidth = 304
    object PaintBox1: TPaintBox
      Tag = 20
      Left = 1
      Top = 1
      Width = 500
      Height = 287
      Align = alClient
      OnMouseMove = PaintBox1MouseMove
      ExplicitHeight = 285
    end
  end
  object Panel2: TPanel
    Left = 0
    Top = 329
    Width = 502
    Height = 102
    Align = alBottom
    TabOrder = 2
    ExplicitTop = 205
    ExplicitWidth = 304
    object Label1: TLabel
      Left = 25
      Top = 14
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
    object Label3: TLabel
      Left = 25
      Top = 40
      Width = 110
      Height = 16
      Caption = 'Interwa'#322':  1000 ms'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
    end
    object TrackBar1: TTrackBar
      Left = 153
      Top = 14
      Width = 132
      Height = 28
      Max = 30
      Min = 3
      Position = 8
      TabOrder = 0
      TickStyle = tsNone
      OnChange = TrackBar1Change
    end
    object Button1: TButton
      Left = 336
      Top = 6
      Width = 143
      Height = 25
      Caption = 'Zainicjuj'
      TabOrder = 1
      OnClick = Button1Click
    end
    object Button6: TButton
      Left = 336
      Top = 37
      Width = 143
      Height = 25
      Caption = 'Start'
      TabOrder = 2
      OnClick = Button6Click
    end
    object ProgressBar1: TProgressBar
      Left = 25
      Top = 68
      Width = 454
      Height = 20
      Max = 255
      TabOrder = 3
    end
    object TrackBar2: TTrackBar
      Left = 153
      Top = 40
      Width = 132
      Height = 28
      DoubleBuffered = False
      Max = 2000
      Min = 10
      ParentDoubleBuffered = False
      Frequency = 100
      Position = 1000
      TabOrder = 4
      TickStyle = tsNone
      OnChange = TrackBar2Change
    end
  end
  object Panel3: TPanel
    Left = 0
    Top = 289
    Width = 502
    Height = 40
    Align = alClient
    TabOrder = 3
    ExplicitWidth = 304
    ExplicitHeight = 37
    object Button3: TButton
      Left = 65
      Top = 6
      Width = 75
      Height = 25
      Caption = 'A-B'
      TabOrder = 0
      OnClick = Button3Click
    end
    object Button4: TButton
      Left = 216
      Top = 6
      Width = 75
      Height = 25
      Caption = 'B-C'
      TabOrder = 1
      OnClick = Button4Click
    end
    object Button5: TButton
      Left = 372
      Top = 6
      Width = 75
      Height = 25
      Caption = 'C-A'
      TabOrder = 2
      OnClick = Button5Click
    end
  end
  object Timer1: TTimer
    Enabled = False
    OnTimer = Timer1Timer
    Left = 432
    Top = 16
  end
  object MainMenu1: TMainMenu
    Left = 432
    Top = 64
  end
end
