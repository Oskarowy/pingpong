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
    bool isGameOn;
    AnsiString leftPlayerName="Lewy";
    AnsiString rightPlayerName="Prawy";

   /* bool paddleLeftHit(TImage * ball, TImage * paddle)
    {
        if(ball->Left <= paddle->Left + paddle->Width &&
           ball->Top <= paddle->Top + paddle->Height &&
           ball->Top + ball->Height >= paddle->Top)
        return true;
        else return false;
    }

    bool paddleRightHit(TImage * ball, TImage * paddle)
    {
        if(ball->Left + ball->Width >= paddle->Left &&
           ball->Top <= paddle->Top+paddle->Height &&
           ball->Top + ball->Height >= paddle->Top)
        return true;
        else return false;
    }
    */

    void setStartSetup(TImage * ball, TImage * paddleLeft, TImage * paddleRight,  TShape * background)
    {
        paddleLeft->Left=0;
        paddleLeft->Top=background->Height/2-paddleLeft->Height/2;
        paddleRight->Left=background->Width-paddleRight->Width;
        paddleRight->Top=background->Height/2-paddleRight->Height/2;
        ball->Left=background->Width/2;
        ball->Top=background->Height/2;
    }

    void setScoreboard(TLabel *scoreboard, TShape *background)
    {
        scoreboard->Top=background->Top+scoreboard->Height;
        scoreboard->Left=background->Left+background->Width/2-scoreboard->Width;
    }

    bool isPointForRight(TImage *ball, TImage *paddle)
    {
        if(ball->Left <= paddle->Left+ball->Width-45)
        {
            rightPlayerCounter++;
            return true;
        }
        else return false;
    }

    bool isPointForLeft(TImage *ball, TImage *paddle)
    {
        if(ball->Left+ball->Width >= paddle->Left + paddle->Width+20)
        {
            leftPlayerCounter++;
            return true;
        }
        else return false;
    }
    void serve (TImage * ball, TImage * paddleLeft, TImage * paddleRight,  TShape * background)
    {
        setStartSetup(ball,paddleLeft,paddleRight,background);
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
    if(isGameOn)
    {
        ball->Visible=true;
        ball->Left-= x;
        ball->Top+= y;

        if(ball->Top <= background->Top) y = -y;
        if(ball->Top+ball->Height >= background->Top+background->Height) y = -y;

        /*
        if(paddleLeftHit(ball,paddleLeft)) x = -x;
        if(paddleRightHit(ball,paddleRight)) x = -x;
        */

        // odbicie lew¹ paletk¹
        if((ball->Left <= paddleLeft->Left + paddleLeft->Width) &&
           (ball->Top <= paddleLeft->Top + paddleLeft->Height) &&
           (ball->Top + ball->Height >= paddleLeft->Top)) x=-x;

        //odbicie praw¹ paletk¹
        if((ball->Left + ball->Width >= paddleRight->Left) &&
           (ball->Top <= paddleRight->Top+paddleRight->Height) &&
           (ball->Top + ball->Height >= paddleRight->Top)) x=-x;

        if(isPointForLeft(ball,paddleRight))
        {
            if(leftPlayerCounter<11)
            {
                isGameOn=false;
                scoreboard->Visible=true;
                scoreboard->Caption="< Punkt dla gracza: "+leftPlayerName+" \n \n Wynik gry: \n" +leftPlayerName+
                ": "+IntToStr(leftPlayerCounter)+"     "+rightPlayerName+": "+IntToStr(rightPlayerCounter);
                Application->ProcessMessages(); Sleep(1000);
                scoreboard->Visible=false;
                serve(ball,paddleLeft,paddleRight,background);
                isGameOn=true;
            }
            else
            {
                isGameOn=false;
                timerBall->Enabled=false;
                scoreboard->Visible=true;
                scoreboard->Caption="< Punkt dla gracza: "+leftPlayerName+" \n \n Seta wygrywa gracz "+leftPlayerName+"!";
                Application->ProcessMessages(); Sleep(1000);

                if (Application->MessageBox("Czy chcesz zagrac jeszcze raz?",
			    "Rewan¿", MB_YESNO | MB_ICONQUESTION)==IDYES)
                {
                    scoreboard->Visible=false;
                    leftPlayerCounter=0;
                    rightPlayerCounter=0;
                    timerBall->Enabled=true;
                    serve(ball,paddleLeft,paddleRight,background);
                    isGameOn=true;
                }
                else
                {
                    Application->MessageBox("Dziêki za grê! Kliknij OK aby wyjœæ",
                    "Podziêkowanie",NULL);
                    Application->Terminate();
                }
            }
        }

        if(isPointForRight(ball,paddleLeft))
        {
            if(rightPlayerCounter<11)
            {
                isGameOn=false;
                scoreboard->Visible=true;
                scoreboard->Caption="Punkt dla gracza: "+rightPlayerName+" > \n \n Wynik gry: \n" +leftPlayerName+
                ": "+IntToStr(leftPlayerCounter)+"     "+rightPlayerName+": "+IntToStr(rightPlayerCounter);
                Application->ProcessMessages(); Sleep(1000);
                scoreboard->Visible=false;
                serve(ball,paddleLeft,paddleRight,background);
                isGameOn=true;
            }
            else
            {
                isGameOn=false;
                timerBall->Enabled=false;
                scoreboard->Visible=true;
                scoreboard->Caption="< Punkt dla gracza: "+rightPlayerName+" \n \n Seta wygrywa gracz "+rightPlayerName+"!";
                Application->ProcessMessages(); Sleep(1000);

                if (Application->MessageBox("Czy chcesz zagrac jeszcze raz?",
			    "Rewan¿", MB_YESNO | MB_ICONQUESTION)==IDYES)
                {
                    scoreboard->Visible=false;
                    leftPlayerCounter=0;
                    rightPlayerCounter=0;
                    timerBall->Enabled=true;
                    serve(ball,paddleLeft,paddleRight,background);
                    isGameOn=true;
                }
                else
                {
                    Application->MessageBox("Dziêki za grê! Kliknij OK aby wyjœæ",
                    "Podziêkowanie",NULL);
                    Application->Terminate();
                }
            }
        }

    }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::movePaddleUpTimerTimer(TObject *Sender)
{
    if(paddleRight->Top > 5) paddleRight->Top -= 15;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::moveRightPaddleDownTimer(TObject *Sender)
{
    if(paddleRight->Top+paddleRight->Height+10 < background->Top+background->Height) paddleRight->Top += 15;
}

void __fastcall TForm1::moveLeftPaddleDownTimer(TObject *Sender)
{
    if(paddleLeft->Top+paddleLeft->Height+10 < background->Top+background->Height) paddleLeft->Top += 15;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::moveLeftPaddleUpTimer(TObject *Sender)
{
    if(paddleLeft->Top > 5) paddleLeft->Top -= 15;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
    if(Key == VK_UP) moveRightPaddleUp->Enabled = true;
    if(Key == VK_DOWN) moveRightPaddleDown->Enabled = true;
    if(Key == 0x57) moveLeftPaddleUp->Enabled = true;
    if(Key == 0x53) moveLeftPaddleDown->Enabled = true;
    /*if(Key == VK_ADD)
    {
   
    }
    if(Key == VK_SUBTRACT)
    {

    }
    */
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
    setScoreboard(scoreboard,background);
    setStartSetup(ball,paddleLeft,paddleRight,background);
}
//---------------------------------------------------------------------------


void __fastcall TForm1::FormCreate(TObject *Sender)
{
    /*isGameOn=false;
    Application->MessageBox("Witaj w grze w Ping Ponga!\n\nSterowanie: \n   Lewy gracz: klawisze W i S, \n   Prawy gracz: strza³ki góra i dó³\n\nJeœli chcesz, wprowadŸ w nastêpnym ekranie w³asne imiona dla obu graczy.\n\nSeta wygrywa gracz, który pierwszy zdobêdzie 11 punktów.\n\nAby gra by³a ciekawsza, wciœnij klawisz '+' i zobacz, co siê stanie! Poprzednie ustawienie przywraca wciœniêcie klawisza '-' :)\n\nOkno gry mo¿esz dowolnie powiêkszaæ",
				"PingPong by Oskarowy", MB_OK);
    if (Application->MessageBox("Czy chcesz wprowadziæ w³asne imiona graczy?",
			"Wybierz nazwy graczy", MB_YESNO | MB_ICONQUESTION)==IDYES)
            {
                playerLeft->Visible=true;
            }
    else*/ isGameOn=true;

    setScoreboard(scoreboard,background);
    setStartSetup(ball,paddleLeft,paddleRight,background);
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
        playerRight->Visible= true;
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
        isGameOn=true;
    }
}
//---------------------------------------------------------------------------


