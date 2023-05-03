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

int result1, result2, result, a, b;  
int difficultyLevel = 1;

void mathGameMain() {
  mathGameLabel();
  getSum();
  showNextEquation();
}

void getSum(){   
   
    a = rand() % (difficultyLevel * 10 + 1); 
    b = rand() % (difficultyLevel * 10 + 1); 
   
    result1 = rand() % 5 * (a + b);
    result2 = rand() % 4 * (a + b);
    
    result = a + b; // calculate the result
}

void getProduct(){
   a = rand() % (difficultyLevel * 10 + 1); 
   b = rand() % (difficultyLevel * 10 + 1); 
   
   result1 = rand() % 5 * (a * b);
   result2 = rand() % 4 * (a * b);
    
   result = a * b; 
}

void showNextEquation(){
   int possibleCoordinates[] = {50, 30, 70};
   int randomIndex = rand() % 3;
   int randomNum = possibleCoordinates[randomIndex];
   int remainingNum1 = possibleCoordinates[(randomIndex + 1) % 3];
   int remainingNum2 = possibleCoordinates[(randomIndex + 2) % 3];
   
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
