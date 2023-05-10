#include "mathGame.h"
int MATH_SCORE;

void mathGameInit() {
  EsploraTFT.background(0, 0, 0);
  EsploraTFT.stroke(255, 255, 0);
  EsploraTFT.setTextSize(3);
  EsploraTFT.text("Math game", 0, 0);
  EsploraTFT.setTextSize(2);
}


#define NUM_OPTIONS 3
#define MIN_NUM 1
#define MAX_NUM_START 10
#define MAX_NUM_INC 10
#define MAX_NUM_MAX 400
#define CORRECT_ANSWERS_THRESHOLD 3

int max_num = MAX_NUM_START;
int mathSelectedOption = SEL1;
int answer, num1, num2;
char op;
int options[3];
int correct_answer_pos;
int correct_answers;
int counter = 0;
int numOfCorrectAnswers = -1;

void mathGameMain() {


  if (!Esplora.readButton(SWITCH_LEFT)) {
    menuState = MATH_SEL;
    prevGameState = SELECTION;
    menuInit();
    delay(100);
    while (!Esplora.readButton(SWITCH_LEFT));
  }

  if (!Esplora.readButton(SWITCH_RIGHT)) {
    Serial.println("MAXXXXXXXXXXXXXXXX: " + String(max_num));
    
    userInput();
    generateRandomEquation();
    displayMathMenu();
    delay(100);
    while (!Esplora.readButton(SWITCH_RIGHT));
  }

  if (!Esplora.readButton(SWITCH_UP)) {

    mathSwitchUp();
    displayAnswers();

    delay(100);
    while (!Esplora.readButton(SWITCH_UP));
  }

  if (!Esplora.readButton(SWITCH_DOWN)) {
    
    mathSwitchDown();
    displayAnswers();


    delay(100);
    while (!Esplora.readButton(SWITCH_DOWN));
  }

}

void generateRandomEquation() {
  num1 = rand() % max_num + MIN_NUM;
  num2 = rand() % max_num + MIN_NUM;
  op = "+-*"[rand() % 3];

  if (op == '+') {
    answer = num1 + num2;
  }
  else if (op == '-') {
    answer = num1 - num2;
  }
  else if (op == '*') {
    answer = num1 * num2;
  }

  correct_answer_pos = rand() % NUM_OPTIONS;
  Serial.println("correct_answer_pos: " + String(correct_answer_pos));
  for (int i = 0; i < NUM_OPTIONS; i++) {
    if (i == correct_answer_pos) {
      options[i] = answer;
    }
    else {
      options[i] = rand() % (max_num * 2 - MIN_NUM + 1) + MIN_NUM;
      if (answer < 0)
        options[i] *= -1;
     
    }
  }


}

int selectedButton() {
  switch (mathSelectedOption) {
    case SEL1:
      Serial.println("SEL1");
      return 0;
      break;
    case SEL2:
      Serial.println("SEL2");
      return 1;
      break;
    case SEL3:
      Serial.println("SEL3");
      return 2;
      break;
  }
}


void userInput() {
  int user_answer = selectedButton();
  
  Serial.println("user_answer: " + String(user_answer));
  if (user_answer == correct_answer_pos) {
    correct_answers++;
    numOfCorrectAnswers++;
    if (correct_answers == CORRECT_ANSWERS_THRESHOLD) {
      correct_answers = 0;
      max_num += MAX_NUM_INC;
      if (max_num > MAX_NUM_MAX) {
        max_num = MAX_NUM_MAX;
      }
    }
  }
  else {
    numOfCorrectAnswers = 0;
    correct_answers = 0;
    max_num = MAX_NUM_START;
  }
}



void displayMathMenu() {
  displayExpresion();
  displayAnswers();
}

void displayExpresion() {
  mathGameInit();

  EsploraTFT.stroke(100, 255, 0);
  const char *strEquation = makeEquationString(num1, num2, op);
  EsploraTFT.text(strEquation, 0, 50);
  const char *idk = ft_itoa(numOfCorrectAnswers);
  EsploraTFT.text(idk, 50, 100);
  delete[] (strEquation);
}

void displayAnswers() {
  char *sOption1, *sOption2, *sCorrectOption;
  switch (mathSelectedOption) {
    case SEL1:
      EsploraTFT.stroke(255, 0, 0);
      sOption1 = ft_itoa(options[0]);
      EsploraTFT.text((const char *) sOption1, 120, 30);
      EsploraTFT.stroke(0, 255, 0);
      sOption2 = ft_itoa(options[1]);
      EsploraTFT.text((const char *) sOption2, 120, 50);
      sCorrectOption = ft_itoa(options[2]);
      EsploraTFT.text((const char *) sCorrectOption, 120, 70);
      break;
    case SEL2:
      EsploraTFT.stroke(0, 255, 0);
      sOption1 = ft_itoa(options[0]);
      EsploraTFT.text((const char *) sOption1, 120, 30);
      EsploraTFT.stroke(255, 0, 0);
      sOption2 = ft_itoa(options[1]);
      EsploraTFT.text((const char *) sOption2, 120, 50);
      EsploraTFT.stroke(0, 255, 0);
      sCorrectOption = ft_itoa(options[2]);
      EsploraTFT.text((const char *) sCorrectOption, 120, 70);
      break;
    case SEL3:
      EsploraTFT.stroke(0, 255, 0);
      sOption1 = ft_itoa(options[0]);
      EsploraTFT.text((const char *) sOption1, 120, 30);
      sOption2 = ft_itoa(options[1]);
      EsploraTFT.text((const char *) sOption2, 120, 50);
      sCorrectOption = ft_itoa(options[2]);
      EsploraTFT.stroke(255, 0, 0);
      EsploraTFT.text((const char *) sCorrectOption, 120, 70);
      break;
  }

  delete[] (sOption1);
  delete[] (sOption2);
  delete[] (sCorrectOption);
}

void mathSwitchDown() {
  switch (mathSelectedOption) {
    case SEL3:
      mathSelectedOption = SEL1;
      break;
    case SEL1:
      mathSelectedOption = SEL2;
      break;
    case SEL2:
      mathSelectedOption = SEL3;
      break;
  }
}

void mathSwitchUp() {
  switch (mathSelectedOption) {
    case SEL3:
      mathSelectedOption = SEL2;
      break;
    case SEL2:
      mathSelectedOption = SEL1;
      break;
    case SEL1:
      mathSelectedOption = SEL3;
      break;
  }
}
