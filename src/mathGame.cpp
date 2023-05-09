#include "mathGame.h"

int MATH_SCORE;

void mathGameInit() {
    EsploraTFT.background(0, 0, 0);
    EsploraTFT.stroke(255, 255, 0);
    EsploraTFT.setTextSize(3);
    EsploraTFT.text("Math game", 0, 0);
    EsploraTFT.setTextSize(2);
}

int result1, result2, result, a, b;  
int difficultyLevel = 1;
int mathState = SEL1;

void mathGameMain() {
  if (!Esplora.readButton(SWITCH_LEFT)){
    menuState = MATH_SEL;
    gameState = SELECTION;
    menuInit();    
    delay(100);
    while (!Esplora.readButton(SWITCH_LEFT));
  }

  if (!Esplora.readButton(SWITCH_UP)){
      mathSwitchUp();
      updateMathState();
      delay(100);
      while(!Esplora.readButton(SWITCH_UP));
  }

  if (!Esplora.readButton(SWITCH_DOWN)){
      mathSwitchDown();
      updateMathState();
      delay(100);
      while(!Esplora.readButton(SWITCH_DOWN));
  }
  
  mathGameSwitch();
}

void updateMathState(){
  
}

void mathSwitchUp(){
  switch (mathState) {
    case SEL3:
      mathState = SEL1;
      break;
    case SEL1:
      mathState = SEL2;
      break;
    case SEL2:
      mathState = SEL3;
      break;
  }
}

void mathSwitchDown(){
  switch (mathState) {
    case SEL3:
      mathState = SEL2;
      break;
    case SEL2:
      mathState = SEL1;
      break;
    case SEL1:
      mathState = SEL3;
      break;
  }
}

void mathGameSwitch(){
  switch(mathState){
    default:
      break;
  }
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
   delete[] (strEquation);
   delete[] (answeresult1char);
   delete[] (answeresult2char);
   delete[] (answer3char);
}
