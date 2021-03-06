//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
    TImage *ball;
    TImage *paddleLeft;
    TImage *paddleRight;
    TTimer *timerBall;
    TTimer *moveRightPaddleUp;
    TTimer *moveRightPaddleDown;
    TTimer *moveLeftPaddleUp;
    TTimer *moveLeftPaddleDown;
    TShape *background;
    TLabel *scoreboard;
    TEdit *playerLeft;
    TEdit *playerRight;
    TLabel *gameOnSwitch;
    void __fastcall timerBallTimer(TObject *Sender);
    void __fastcall movePaddleUpTimerTimer(TObject *Sender);
    void __fastcall moveRightPaddleDownTimer(TObject *Sender);
    void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
    void __fastcall moveLeftPaddleDownTimer(TObject *Sender);
    void __fastcall moveLeftPaddleUpTimer(TObject *Sender);
    void __fastcall FormKeyUp(TObject *Sender, WORD &Key,
          TShiftState Shift);
    void __fastcall FormResize(TObject *Sender);
    void __fastcall FormCreate(TObject *Sender);
    void __fastcall playerLeftChange(TObject *Sender);
    void __fastcall playerLeftKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
    void __fastcall playerRightChange(TObject *Sender);
    void __fastcall playerRightKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
    void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:	// User declarations
public:		// User declarations
    __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
