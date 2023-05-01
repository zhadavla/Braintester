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
int result = 100;
int a = 40, b = 60;  

void mathGameMain() {
  mathGameLabel();
  getNextEquation();
  showNextEquation();
}

void getNextEquation(){   
   
    a = rand() % 11; 
    b = rand() % 11;
    
    // generate random integers between 0 and 100 for result1 and result2
    result1 = rand() % 101;
    result2 = rand() % 101;
    
    result = a + b; // calculate the result
}

int tmp[] = {50, 30, 70};

void showNextEquation(){
   int randomIndex = rand() % 3;
   int randomNum = tmp[randomIndex];
   int remainingNum1 = tmp[(randomIndex + 1) % 3];
   int remainingNum2 = tmp[(randomIndex + 2) % 3];
   EsploraTFT.stroke(100, 255, 0);
   const char *strEquation = makeEquationString(a, b, '+');
   EsploraTFT.text(strEquation, 0, 50);
   const char *answeresult1char = intToCStr(result1);
   EsploraTFT.text(answeresult1char, 120, remainingNum2);
   const char *answeresult2char = intToCStr(result2);
   EsploraTFT.text(answeresult2char, 120, remainingNum1);
   EsploraTFT.stroke(0, 255, 0);
   const char *answer3char = intToCStr(result);
   EsploraTFT.text(answer3char, 120, randomNum);
   free(strEquation);
   free(answeresult1char);
   free(answeresult2char);
   free(answer3char);
}
