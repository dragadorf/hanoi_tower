//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.Menus.hpp>
#include <Vcl.WinXCtrls.hpp>
#include <Vcl.Buttons.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TPaintBox *PaintBox1;
	TButton *Button1;
	TButton *Button3;
	TButton *Button4;
	TButton *Button5;
	TButton *Button6;
	TTimer *Timer1;
	TEdit *Edit1;
	TLabel *Label3;
	TMainMenu *MainMenu1;
	TStatusBar *StatusBar1;
	TProgressBar *ProgressBar1;
	TLabel *Label1;
	TTrackBar *TrackBar1;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall Button4Click(TObject *Sender);
	void __fastcall Button5Click(TObject *Sender);
	void __fastcall Button6Click(TObject *Sender);
	void __fastcall Timer1Timer(TObject *Sender);
	void __fastcall Edit1Change(TObject *Sender);
	void __fastcall PaintBox1MouseMove(TObject *Sender, TShiftState Shift, int X, int Y);
	void __fastcall TrackBar1Change(TObject *Sender);

private:	// User declarations
public:		// User declarations

	struct brick
	{
		//miejsce na stosie
		int level;
		//kolumna (1-A, 2-B, 3-C)
		int column;
		//szerokosc klocka
		double brick_width;
		//
		int number;
	};
	int n;
    bool is_even;
	int a;
	int b;
	int count;
	double max_height;
	double brick_height;
	double max_width;
	double min_width;
	brick stack[];

	__fastcall TForm1(TComponent* Owner);
	void draw_brick (double height, double width, double x, double y, int num);
	void draw_line (double xp, double yp, double xk, double yk);
	void refresh_all ();
	void Algorithm(int i, int j);
	void AfterClick();
	void Initialize();
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
