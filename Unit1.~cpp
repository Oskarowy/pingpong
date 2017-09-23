//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "mmsystem.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

    int x=-5;
    int y=-5;
    int leftPlayerCounter=0;
    int rightPlayerCounter=0;
    bool gameOn=false;
    AnsiString leftPlayerName="Lewy";
    AnsiString rightPlayerName="Prawy";

    bool paddleLeftHit(TImage * ball, TImage * paddle)
    {
        if(ball->Left <= paddle->Left+paddle->Width &&
           ball->Top >= paddle->Top-ball->Height &&
           ball->Top <= paddle->Top+paddle->Height)
        return true;
        else return false;
    }

    bool paddleRightHit(TImage * ball, TImage * paddle)
    {
        if(ball->Left+ball->Width >= paddle->Left &&
           ball->Top >= paddle->Top-ball->Height &&
           ball->Top <= paddle->Top+paddle->Height)
        return true;
        else return false;
    }

    bool isPointForLeft(TImage *ball, TShape * background)
    {
        if(ball->Left <= background->Left+ball->Width+10)
        {
            leftPlayerCounter++;
            return true;
        }
        else return false;
    }

    bool isPointForRight(TImage *ball, TShape * background)
    {
        if(ball->Left+ball->Width >= background->Width+ball->Width+10)
        {
            rightPlayerCounter++;
            return true;
        }
        else return false;
    }
    void serve (TImage * ball, TImage * paddleLeft, TImage * paddleRight,  TShape * background)
    {
        paddleLeft->Left=0;
        paddleLeft->Top=background->Height/2-paddleLeft->Height/2;
        paddleRight->Left=background->Width-paddleRight->Width;
        paddleRight->Top=background->Height/2-paddleRight->Height/2;
        ball->Left=background->Width/2;
        y=-y;
        x=-x;
    }
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::timerBallTimer(TObject *Sender)
{
    if(gameOn)
    {
        ball->Left-= x;
        ball->Top+= y;

        if(ball->Top <= background->Top) y = -y;
        if(ball->Top+ball->Height >= background->Top+background->Height) y = -y;

        if(paddleLeftHit(ball,paddleLeft)) x = -x;
        if(paddleRightHit(ball,paddleRight)) x = -x;

        if(isPointForLeft(ball,background))
        {
            gameOn=false;
            scoreboard->Visible=true;
            scoreboard->Caption="Punkt dla gracza: "+leftPlayerName+" \n \n Wynik gry: \n" +leftPlayerName+
            ": "+IntToStr(leftPlayerCounter)+"     "+rightPlayerName+": "+IntToStr(rightPlayerCounter);
            Application->ProcessMessages(); Sleep(1000);
            scoreboard->Visible=false;
            serve(ball,paddleLeft,paddleRight,background);
            gameOn=true;
        }
        if(isPointForRight(ball,background))
        {
            gameOn=false;
            scoreboard->Visible=true;
            scoreboard->Caption="Punkt dla gracza: "+rightPlayerName+" \n \n Wynik gry: \n" +leftPlayerName+
            ": "+IntToStr(leftPlayerCounter)+"     "+rightPlayerName+": "+IntToStr(rightPlayerCounter);
            Application->ProcessMessages(); Sleep(1000);
            scoreboard->Visible=false;
            serve(ball,paddleLeft,paddleRight,background);
            gameOn=true;
        }

    }
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

void __fastcall TForm1::FormResize(TObject *Sender)
{
    scoreboard->Top=background->Top+scoreboard->Height;
    scoreboard->Left=background->Left+background->Width/2-scoreboard->Width/2;
    paddleLeft->Left=0;
    paddleLeft->Top=background->Height/2-paddleLeft->Height/2;
    paddleRight->Left=background->Width-paddleRight->Width;
    paddleRight->Top=background->Height/2-paddleRight->Height/2;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::FormCreate(TObject *Sender)
{
    gameOn=false;
    playerLeft->Visible=true;
    scoreboard->Top=background->Top+scoreboard->Height;
    scoreboard->Left=background->Left+background->Width/2-scoreboard->Width/2;
    paddleLeft->Left=0;
    paddleLeft->Top=background->Height/2-paddleLeft->Height/2;
    paddleRight->Left=background->Width-paddleRight->Width;
    paddleRight->Top=background->Height/2-paddleRight->Height/2;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::playerLeftChange(TObject *Sender)
{
   leftPlayerName=playerLeft->Text;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::playerLeftKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
     if(Key == VK_RETURN)
     {
        playerLeft->Visible = false;
        playerRight->Visible=true;
     }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::playerRightChange(TObject *Sender)
{
    rightPlayerName=playerRight->Text;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::playerRightKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
    if(Key == VK_RETURN)
    {
        playerRight->Visible = false;
        gameOn=true;
    }
}
//---------------------------------------------------------------------------

