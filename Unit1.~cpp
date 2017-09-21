//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

    int x=-5;
    int y=-5;

    bool leftPaddleHit(TImage * ball, TImage * paddle)
    {
        if(ball->Left >= paddle->Left+paddle->Width)
        return true;
        else return false;
    }
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::timerBallTimer(TObject *Sender)
{
    ball->Left-= x;
    ball->Top+= y;

    if(ball->Top <= background->Top) y = -y;
    if(ball->Top+ball->Height >= background->Top+background->Height) y = -y;

    ///////////////// do wywalenia (boczne odbicia) /////////////////////////
    if(ball->Left <= background->Left) x = -x;
    if(ball->Left+ball->Width >= background->Width) x = -x;
    /////////////////////////////////////////////////////////////////////////
}
//---------------------------------------------------------------------------
