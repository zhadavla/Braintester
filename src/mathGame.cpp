#include "mathGame.h"

int MATH_SCORE;

void mathGameLabel() {
    EsploraTFT.background(0, 0, 0);
    EsploraTFT.stroke(255, 255, 0);
    EsploraTFT.setTextSize(3);
    EsploraTFT.text("Math game", 0, 0);
    EsploraTFT.setTextSize(2);
    Serial.println(makeEquationString(1,2,3));
}

int result1 = 101;
int result2 = 200;
int result3 = 300;
int a = 40, b = 60;  

void mathGameMain() {
  mathGameLabel();
  showNextEquation();
}


void showNextEquation(){
   EsploraTFT.stroke(255, 0, 0);
   const char *strEquation = makeEquationString(a, b, '+');
   EsploraTFT.text(strEquation, 0, 50);
   const char *answer1char = intToCStr(result1);
   EsploraTFT.text(answer1char, 120, 50);
   const char *answer2char = intToCStr(result2);
   EsploraTFT.text(answer2char, 120, 30);
   const char *answer3char = intToCStr(result3);
   EsploraTFT.text(answer3char, 120, 70);
   free(strEquation);
   free(answer1char);
   free(answer2char);
   free(answer3char);
}
