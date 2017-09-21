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
    TShape *background;
    TImage *ball;
    TImage *paddleLeft;
    TImage *paddleRight;
    TTimer *timerBall;
    TTimer *movePaddleUp;
    TTimer *movePaddleDown;
    void __fastcall timerBallTimer(TObject *Sender);
    void __fastcall movePaddleUpTimerTimer(TObject *Sender);
    void __fastcall movePaddleDownTimer(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
