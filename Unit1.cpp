//---------------------------------------------------------------------------
#include <vcl.h>
#include <math.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------

__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
	n=StrToInt(TrackBar1->Position);
	switch (is_even) {

	case true:
	a=1;
	b=2;
	break;
	case false:
	a=1;
	b=3;
	break;
	}

	count=0;
	brick stack[n];
	max_height=180;
	max_width=140;
	min_width=20;

	Initialize();
	refresh_all();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	Initialize();
}
//---------------------------------------------------------------------------
void TForm1::draw_brick (double x, double y, double height, double width, int num)
{

	int pos=0;
	int doc=1535*num/n;

	R=255;
	G=B=0;
	bool set=false;

	for (int i=0; i < 255; i++) {
		pos++;
		if (doc==pos) {
		R=255;
		G=i;
		B=0;
		}
	}
	for (int i=0; i < 255; i++) {
		pos++;
		if (doc==pos) {
		R=255-i;
		G=255;
		B=0;
		}
	}
	for (int i=0; i < 255; i++) {
		pos++;
		if (doc==pos) {
		R=0;
		G=255;
		B=i;
		}
	}
	for (int i=0; i < 255; i++) {
		pos++;
		if (doc==pos) {
		R=0;
		G=255-i;
		B=255;
		}
	}
	for (int i=0; i < 255; i++) {
		pos++;
		if (doc==pos) {
		R=i;
		G=0;
		B=255;
		}
	}

	for (int i=0; i < 255; i++) {
		pos++;
		if (doc==pos) {
		R=255;
		G=0;
		B=255-i;
		}
	}

	PaintBox1->Canvas->Pen->Color = clBlack;
	PaintBox1->Canvas->Brush->Color = (TColor) RGB(R,G,B);
	PaintBox1->Canvas->Rectangle(x-width/2,y-height/2,x+width/2,y+height/2);
	if (n<10 && Shownumbers1->Checked==true) {
	  PaintBox1->Canvas->TextOut(x-2,y-7,num);
	}
}
//---------------------------------------------------------------------------
void TForm1::draw_line (double xp, double yp, double xk, double yk)
{
	PaintBox1->Canvas->MoveTo(xp,yp);
	PaintBox1->Canvas->LineTo(xk,yk);
}
//---------------------------------------------------------------------------
void TForm1::refresh_all ()
{
   PaintBox1->Canvas->Pen->Color = clBlack;

   PaintBox1->Canvas->Brush->Color =(TColor) RGB(240,240,240);
   PaintBox1->Canvas->FillRect(PaintBox1->Canvas->ClipRect);
   PaintBox1->Canvas->TextOut(100-2,260,"A");
   PaintBox1->Canvas->TextOut(250-2,260,"B");
   PaintBox1->Canvas->TextOut(400-2,260,"C");
   PaintBox1->Canvas->Brush->Color = (TColor) RGB(0,204,204);

   PaintBox1->Canvas->Pen->Width=5;
   draw_line(25,250,475,250);
   draw_line(100,250,100,75);
   draw_line(250,250,250,75);
   draw_line(400,250,400,75);
   PaintBox1->Canvas->Pen->Width=2;

	for (int i=0; i < n; i++)
   {
	   double x;
	   double y;

	   switch(stack[i].column)
		{
		case 1:
			x=100;
			break;
		case 2:
			x=250;
			break;
		case 3:
			x=400;
			break;
		}

		y=250-brick_height/2-stack[i].level*brick_height;

	  draw_brick(x, y, brick_height, stack[i].brick_width, stack[i].number);

	  }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
	Algorithm(1,2);
	AfterClick();
	Check_win();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button4Click(TObject *Sender)
{
	Algorithm(2,3);
	AfterClick();
	Check_win();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button5Click(TObject *Sender)
{
	Algorithm(1,3);
	AfterClick();
	Check_win();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button6Click(TObject *Sender)
{
	if (Timer1->Enabled==True)
	{
	Timer1->Enabled=False;
	Button6->Caption="Start";
	}
	else
	{
	   Timer1->Enabled=True;
	   Button6->Caption="Stop";
	}
}
//---------------------------------------------------------------------------
void TForm1::Algorithm(int k, int l)
{

	int k_max=-1;
	int l_max=-1;
	int k_index;
	int l_index;

	for (int i =0; i < n; i++)
	{
		if(stack[i].level>k_max && stack[i].column==k)
		{
			k_max=stack[i].level;
			k_index=i;
		}
		else if(stack[i].level>l_max && stack[i].column==l)
		{
			l_max=stack[i].level;
			l_index=i;
		}
	}


	if (k_max==-1 && l_max==-1)
	{

	}
	else if (k_max==-1)
	{
	   stack[l_index].column=k;
	   stack[l_index].level=k_max+1;
		count++;
	}

	else if (l_max==-1)

	{
	   stack[k_index].column=l;
	   stack[k_index].level=l_max+1;
		count++;
	}

	else if (stack[k_index].brick_width>stack[l_index].brick_width)
	{
		stack[l_index].column=k;
		stack[l_index].level=k_max+1;
		count++;
	}
	else if (stack[k_index].brick_width<stack[l_index].brick_width)
	{
		stack[k_index].column=l;
		stack[k_index].level=l_max+1;
		count++;
	}

}
void __fastcall TForm1::Timer1Timer(TObject *Sender)
{

	Algorithm(a,b);
	AfterClick();

	switch (is_even)
	{		case true:
			if (a==2 && b==3)
			{
			a=1;
			b=2;
			}
			else if (a==1 && b==3)
			{
			a=2;
			b=3;
			}
			else if (a==1 && b==2)
			{
			a=1;
			b=3;
			}
		break;

		case false:
			if (a==2 && b==3)
			{
			a=1;
			b=3;
			}
			else if (a==1 && b==2)
			{
			a=2;
			b=3;
			}
			else if (a==1 && b==3)
			{
			a=1;
			b=2;
			}
		break;
	}

	ProgressBar1->Position=count;
	if (count==pow(2,n)-1)
	{
		Timer1->Enabled=false;
	}
	Check_win();

}
//---------------------------------------------------------------------------

void __fastcall TForm1::PaintBox1MouseMove(TObject *Sender, TShiftState Shift, int X,
		  int Y)
{
	  StatusBar1->Panels->Items[1]->Text="X: " + IntToStr(X)+" "+ "Y: " + IntToStr(Y);
}
//---------------------------------------------------------------------------

void TForm1::AfterClick()
{
	StatusBar1->Panels->Items[0]->Text="Moves: " + IntToStr(count) ;
	refresh_all();
}

void TForm1::Initialize()
{
	Button6->Caption="Start";
	Timer1->Enabled=False;
	n=StrToInt(TrackBar1->Position);
	if (n%2==0) {
	   is_even=true;
	   a=1;
	   b=2;
	}
	else
	{
		is_even=false;
		a=1;
        b=3;
    }
	brick_height=max_height/n;
	Label1->Caption="Elements: "+IntToStr(TrackBar1->Position);
	count=0;
	ProgressBar1->Max=pow(2,n)-1;
	ProgressBar1->Position=count;
	StatusBar1->Panels->Items[0]->Text="Moves: " + IntToStr(count);

	for (int i=0; i<n; i++)
	{
		stack[i].level=i;
		stack[i].number=i;
		stack[i].column=1;

		double d=double(i)/double(n);

		stack[i].brick_width=max_width-d*(max_width-min_width);
	}

	refresh_all();
}
void __fastcall TForm1::TrackBar1Change(TObject *Sender)
{
	Initialize();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::TrackBar2Change(TObject *Sender)
{
	Timer1->Interval=TrackBar2->Position;
	Label3->Caption="Interval:  "+IntToStr(TrackBar2->Position)+" ms";
}

void TForm1::Check_win()
{
	 bool win=true;

	 for (int i=0; i < n; i++) {
		 if (stack[i].column!=3) {
			 win=false;
		 }
	 }

	 if (win==true) {
		if (count==pow(2,n)-1 && Timer1->Enabled==false)
		{
			ShowMessage("The End.\nMinimum number of moves.");
		}
		else
		{
			ShowMessage("The End.");
		}
		Initialize();

	 }

}

//---------------------------------------------------------------------------

void __fastcall TForm1::Shownumbers1Click(TObject *Sender)
{
	if (Shownumbers1->Checked==true)
	{
		Shownumbers1->Checked=false;
	}
	else
	{
		Shownumbers1->Checked=true;
	}
	refresh_all();
}
//---------------------------------------------------------------------------

