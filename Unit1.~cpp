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
void __fastcall TForm1::movePaddleUpTimerTimer(TObject *Sender)
{
    if(paddleRight->Top > 10) paddleRight->Top -= 10;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::moveRightPaddleDownTimer(TObject *Sender)
{
    if(paddleRight->Top+paddleRight->Height+10 < background->Top+background->Height) paddleRight->Top += 10;
}

void __fastcall TForm1::moveLeftPaddleDownTimer(TObject *Sender)
{
    if(paddleLeft->Top+paddleLeft->Height+10 < background->Top+background->Height) paddleLeft->Top += 10;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::moveLeftPaddleUpTimer(TObject *Sender)
{
    if(paddleLeft->Top > 10) paddleLeft->Top -= 10;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
    if(Key == VK_UP) moveRightPaddleUp->Enabled = true;
    if(Key == VK_DOWN) moveRightPaddleDown->Enabled = true;
    if(Key == 0x57) moveLeftPaddleUp->Enabled = true;
    if(Key == 0x53) moveLeftPaddleDown->Enabled = true;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
void __fastcall TForm1::FormKeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
    if(Key == VK_UP) moveRightPaddleUp->Enabled = false;
    if(Key == VK_DOWN) moveRightPaddleDown->Enabled = false;
    if(Key == 0x57) moveLeftPaddleUp->Enabled = false;
    if(Key == 0x53) moveLeftPaddleDown->Enabled = false;
}
//---------------------------------------------------------------------------
