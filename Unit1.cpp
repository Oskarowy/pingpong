//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "mmsystem.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

    int x=7;
    int y=7;
    int leftPlayerCounter=0;
    int rightPlayerCounter=0;
    int bounceCounts=0;
    bool isGameOn;
    bool isSoundOn = true;
    AnsiString leftPlayerName="Lewy";
    AnsiString rightPlayerName="Prawy";

    void setStartSetup(TImage * ball, TImage * paddleLeft, TImage * paddleRight,  TShape * background, TLabel *gameOnSwitch)
    {
        paddleLeft->Left=paddleLeft->Width*2;
        paddleLeft->Top=background->Height/2-paddleLeft->Height/2;
        paddleRight->Left=background->Width-paddleRight->Width*3;
        paddleRight->Top=background->Height/2-paddleRight->Height/2;
        ball->Left=background->Width/2;
        ball->Top=background->Height/2;
        gameOnSwitch->Top=background->Top+gameOnSwitch->Height*3;
        gameOnSwitch->Left=background->Left+background->Width/2-gameOnSwitch->Width/2;
    }

    void setScoreboard(TLabel *scoreboard, TShape *background)
    {
        scoreboard->Top=background->Top+scoreboard->Height;
        scoreboard->Left=background->Left+background->Width/2-scoreboard->Width;
    }

    bool isPointForRight(TImage *ball, TImage *paddle)
    {
        if(ball->Left <= paddle->Left+paddle->Width-15)
        {
            ball->Visible=false;
            rightPlayerCounter++;
            return true;
        }
        else return false;
    }

    bool isPointForLeft(TImage *ball, TImage *paddle)
    {
        if(ball->Left+ball->Width >= paddle->Left +15)
        {
            ball->Visible=false;
            leftPlayerCounter++;
            return true;
        }
        else return false;
    }

    void serve (TImage * ball, TImage * paddleLeft, TImage * paddleRight,  TShape * background, TLabel *gameOnSwitch)
    {
        setStartSetup(ball,paddleLeft,paddleRight,background,gameOnSwitch);
        y=-y;
        x=-x;
    }

    void setupTheRevenge(TImage * ball, TImage * paddleLeft, TImage * paddleRight,  TShape * background, TLabel *gameOnSwitch, TLabel *scoreboard, TTimer *timerBall)
    {
        scoreboard->Visible=false;
        leftPlayerCounter=0;
        rightPlayerCounter=0;
        timerBall->Enabled=true;
        serve(ball,paddleLeft,paddleRight,background,gameOnSwitch);
        gameOnSwitch->Visible=true;
    }

    void playBounceSound(bool isSoundOn,int bounceCounts)
    {
      if(isSoundOn)
      {
            if(bounceCounts%2==1) sndPlaySound("snd/First.wav",SND_ASYNC);
            else sndPlaySound("snd/Second.wav",SND_ASYNC);
      }
    }

    void bounce(TImage *ball, TTimer *timer)
    {
        x = -x;
        bounceCounts++;
        playBounceSound(isSoundOn, bounceCounts);
    }

    void playPointSound(bool isSoundOn)
    {
       if(isSoundOn) sndPlaySound("snd/Point.wav",SND_ASYNC);
    }

    void playWinnerSound(bool isSoundOn)
    {
        if(isSoundOn) sndPlaySound("snd/Winner.wav",SND_ASYNC);
    }

    void playServeSound(bool isSoundOn)
    {
        if(isSoundOn) sndPlaySound("snd/Serve.wav",SND_ASYNC);
    }

    void playGameOverSound(bool isSoundOn)
    {
        if(isSoundOn) sndPlaySound("snd/Over.wav",SND_ASYNC);
    }

    void exitGame()
    {
        playGameOverSound(isSoundOn);
        Application->MessageBox("Dzi�ki za gr�! Kliknij OK aby wyj��",
        "Podzi�kowanie",NULL);
        Application->Terminate();
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
        ball->Left+= x;
        ball->Top+= y;

        if(ball->Top <= background->Top)y = -y;

        if(ball->Top+ball->Height >= background->Top+background->Height)y = -y;

        // odbicie lew� paletk�
        if((ball->Left <= paddleLeft->Left + paddleLeft->Width) &&
           (ball->Top <= paddleLeft->Top + paddleLeft->Height) &&
           (ball->Top + ball->Height >= paddleLeft->Top))
                {
                    if(x<0)
                        bounce(ball,timerBall);
                }

        //odbicie praw� paletk�
        if((ball->Left + ball->Width >= paddleRight->Left) &&
           (ball->Top <= paddleRight->Top+paddleRight->Height) &&
           (ball->Top + ball->Height >= paddleRight->Top))
                {
                    if(x>0)
                        bounce(ball,timerBall);
                }

        if(isPointForLeft(ball,paddleRight))
        {
            if(leftPlayerCounter<11)
            {
                isGameOn=false;
                playPointSound(isSoundOn);
                scoreboard->Visible=true;
                scoreboard->Caption="< Punkt dla gracza: "+leftPlayerName+" \n \n Wynik gry: \n" +leftPlayerName+
                ": "+IntToStr(leftPlayerCounter)+"     "+rightPlayerName+": "+IntToStr(rightPlayerCounter)+
                "\n\nUda�o Ci si� odbi� pi�eczk� "+bounceCounts+" razy!";
                Application->ProcessMessages(); Sleep(1000);
                scoreboard->Visible=false;
                serve(ball,paddleLeft,paddleRight,background,gameOnSwitch);
                gameOnSwitch->Visible=true;
            }
            else
            {
                isGameOn=false;
                playWinnerSound(isSoundOn);
                timerBall->Enabled=false;
                scoreboard->Visible=true;
                scoreboard->Caption="< Punkt dla gracza: "+leftPlayerName+" \n \n Seta wygrywa gracz "+leftPlayerName+"!"+
                "\n\nUda�o Ci si� odbi� pi�eczk� "+bounceCounts+" razy!";
                Application->ProcessMessages(); Sleep(1000);

                if (Application->MessageBox("Czy chcesz zagrac jeszcze raz?",
			    "Rewan�", MB_YESNO | MB_ICONQUESTION)==IDYES)
                setupTheRevenge(ball,paddleLeft,paddleRight,background,gameOnSwitch,scoreboard,timerBall);

                else exitGame();
            }
        }

        if(isPointForRight(ball,paddleLeft))
        {
            if(rightPlayerCounter<11)
            {
                isGameOn=false;
                playPointSound(isSoundOn);
                scoreboard->Visible=true;
                scoreboard->Caption="Punkt dla gracza: "+rightPlayerName+" > \n \n Wynik gry: \n" +leftPlayerName+
                ": "+IntToStr(leftPlayerCounter)+"     "+rightPlayerName+": "+IntToStr(rightPlayerCounter)+
                "\n\nUda�o Ci si� odbi� pi�eczk� "+bounceCounts+" razy!";
                Application->ProcessMessages(); Sleep(1000);
                scoreboard->Visible=false;
                serve(ball,paddleLeft,paddleRight,background,gameOnSwitch);
                gameOnSwitch->Visible=true;
            }
            else
            {
                isGameOn=false;
                playWinnerSound(isSoundOn);
                timerBall->Enabled=false;
                scoreboard->Visible=true;
                scoreboard->Caption="< Punkt dla gracza: "+rightPlayerName+" \n \n Seta wygrywa gracz "+rightPlayerName+"!"+
                "\n\nUda�o Ci si� odbi� pi�eczk� "+bounceCounts+" razy!";
                Application->ProcessMessages(); Sleep(1000);

                if (Application->MessageBox("Czy chcesz zagrac jeszcze raz?",
			    "Rewan�", MB_YESNO | MB_ICONQUESTION)==IDYES)
                setupTheRevenge(ball,paddleLeft,paddleRight,background,gameOnSwitch,scoreboard,timerBall);

                else exitGame();
            }
        }
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::movePaddleUpTimerTimer(TObject *Sender)
{
    if(paddleRight->Top > 10) paddleRight->Top -= 20;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::moveRightPaddleDownTimer(TObject *Sender)
{
    if(paddleRight->Top+paddleRight->Height+10 < background->Top+background->Height) paddleRight->Top += 20;
}

void __fastcall TForm1::moveLeftPaddleDownTimer(TObject *Sender)
{
    if(paddleLeft->Top+paddleLeft->Height+10 < background->Top+background->Height) paddleLeft->Top += 20;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::moveLeftPaddleUpTimer(TObject *Sender)
{
    if(paddleLeft->Top > 10) paddleLeft->Top -= 20;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
    if(Key == VK_UP) moveRightPaddleUp->Enabled = true;
    if(Key == VK_DOWN) moveRightPaddleDown->Enabled = true;
    if(Key == 0x57) moveLeftPaddleUp->Enabled = true;
    if(Key == 0x53) moveLeftPaddleDown->Enabled = true;
    if(Key == VK_SPACE)
    {
        if(gameOnSwitch->Visible==true)
        {
            gameOnSwitch->Visible=false;
            playServeSound(isSoundOn);
            isGameOn=true;
            bounceCounts=0;
        }
    }
    if(Key == VK_ADD) isSoundOn = true;
    if(Key == VK_SUBTRACT) isSoundOn = false;
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
    setStartSetup(ball,paddleLeft,paddleRight,background,gameOnSwitch);
}
//---------------------------------------------------------------------------


void __fastcall TForm1::FormCreate(TObject *Sender)
{
    isGameOn=false;
    Application->MessageBox("Witaj w grze w Ping Ponga!\n\nSterowanie: \n   Lewy gracz: klawisze W i S, \n   Prawy gracz: strza�ki g�ra i d�\n\nJe�li chcesz, wprowad� w nast�pnym ekranie w�asne imiona dla obu graczy.\n\nSeta wygrywa gracz, kt�ry pierwszy zdob�dzie 11 punkt�w.\n\nWci�nij klawisze +/-, aby w��czy�/wy��czy� d�wi�ki podczas gry.\n\nOkno gry mo�esz dowolnie powi�ksza�",
				"PingPong by Oskarowy", MB_OK);
    if (Application->MessageBox("Czy chcesz wprowadzi� w�asne imiona graczy?",
			"Wybierz nazwy graczy", MB_YESNO | MB_ICONQUESTION)==IDYES)
            {
                playerLeft->Visible=true;
            }
    else gameOnSwitch->Visible=true;

    setScoreboard(scoreboard,background);
    setStartSetup(ball,paddleLeft,paddleRight,background,gameOnSwitch);
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
        gameOnSwitch->Visible = true;
    }
}
//---------------------------------------------------------------------------



void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
    playGameOverSound(isSoundOn);
    if(Application->MessageBoxA("Czy na pewno zako�czyc gr�?","Potwierd�",
    MB_YESNO| MB_ICONQUESTION) == IDNO )
    {
       Action=caNone;
    }
}
//---------------------------------------------------------------------------

