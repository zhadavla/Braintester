#include "mathGame.h"

void mathGameInit() {
  EsploraTFT.background(0, 0, 0);
  EsploraTFT.stroke(255, 255, 0);
  EsploraTFT.setTextSize(3);
  EsploraTFT.text("Math game", 0, 0);
  EsploraTFT.setTextSize(2);
}

void mathGameStart() {
  EsploraTFT.stroke(255, 0, 0);
  EsploraTFT.text("Press", 10, 40);
  EsploraTFT.text("right switch", 10, 60);
  EsploraTFT.text("to start!", 10, 80);
  EsploraTFT.stroke(255, 255, 0);
}

// defines variables to work with
int max_num = MAX_NUM_START;
int mathSelectedOption = MATH_SEL1;
int answer, num1, num2;
char op;
int options[3];
int correct_answer_pos;
int correct_answers;
int numOfCorrectAnswers = -1;
int MATH_MAX_SCORE = 0;


void mathGameMain() {
  if (!Esplora.readButton(SWITCH_LEFT)) { // if switch left return to the main menu
    menuState = MATH_SEL;
    prevGameState = SELECTION;
    menuInit();
    delay(100);
    while (!Esplora.readButton(SWITCH_LEFT));
  }

  if (!Esplora.readButton(SWITCH_RIGHT)) { // select option
    mathUserInput();
    generateRandomEquation();
    displayMathMenu();
    delay(100);
    while (!Esplora.readButton(SWITCH_RIGHT));
  }

  if (!Esplora.readButton(SWITCH_UP)) { // move up
    mathSwitchUp();
    displayAnswers();
    delay(100);
    while (!Esplora.readButton(SWITCH_UP));
  }

  if (!Esplora.readButton(SWITCH_DOWN)) { // move down
    mathSwitchDown();
    displayAnswers();
    delay(100);
    while (!Esplora.readButton(SWITCH_DOWN));
  }
}

void generateRandomEquation() {
  op = "+-*"[rand() % 3]; // choose operation
  // generate random equation
  if (op == '*') {
    if (max_num > MAX_NUM_INC) {
      num1 = rand() % (max_num - MAX_NUM_INC) + MIN_NUM;
      num2 = rand() % (max_num - MAX_NUM_INC) + MIN_NUM;
    }
  } else {
    num1 = rand() % max_num + MIN_NUM;
    num2 = rand() % max_num + MIN_NUM;
  }

  if (op == '+') {
    answer = num1 + num2;
  } else if (op == '-') {
    answer = num1 - num2;
  } else if (op == '*') {
    answer = num1 * num2;
  }

  int num_digits = floor(log10(abs(answer))) + 1;
  int min_option = pow(10, num_digits - 1);
  int max_option = pow(10, num_digits) - 1;

  correct_answer_pos = rand() % NUM_OPTIONS; // generate position of the correct answer
  for (int i = 0; i < NUM_OPTIONS; i++) {
    if (i == correct_answer_pos) {
      options[i] = answer;
    } else {
      int option = 0;
      do { // while all options equal generate new
        option = rand() % (max_option - min_option + 1) + min_option;
        if (answer < 0) options[i] *= -1;
      } while ((options[0] == option || options[1] == option || options[2] == option) || option == 0);
      options[i] = option;
    }
  }
}

void mathUserInput() {
  // if correct answer
  if (mathSelectedOption == correct_answer_pos) {
    correct_answers++; // increase number of them
    if (numOfCorrectAnswers > MATH_MAX_SCORE) MATH_MAX_SCORE = numOfCorrectAnswers;
    if (correct_answers == CORRECT_ANSWERS_THRESHOLD) {
      correct_answers = 0;
      max_num += MAX_NUM_INC;
      if (max_num > MAX_NUM_MAX) max_num = MAX_NUM_MAX;
    }
  } else {
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
  if (options[0] == 0 || options[1] == 0 || options[2] == 0)
    return;
  switch (mathSelectedOption) {
    case MATH_SEL1:
      EsploraTFT.stroke(255, 0, 0);
      sOption1 = ft_itoa(options[0]);
      EsploraTFT.text((const char *) sOption1, 110, 30);
      EsploraTFT.stroke(0, 255, 0);
      sOption2 = ft_itoa(options[1]);
      EsploraTFT.text((const char *) sOption2, 110, 50);
      sCorrectOption = ft_itoa(options[2]);
      EsploraTFT.text((const char *) sCorrectOption, 110, 70);
      break;
    case MATH_SEL2:
      EsploraTFT.stroke(0, 255, 0);
      sOption1 = ft_itoa(options[0]);
      EsploraTFT.text((const char *) sOption1, 110, 30);
      EsploraTFT.stroke(255, 0, 0);
      sOption2 = ft_itoa(options[1]);
      EsploraTFT.text((const char *) sOption2, 110, 50);
      EsploraTFT.stroke(0, 255, 0);
      sCorrectOption = ft_itoa(options[2]);
      EsploraTFT.text((const char *) sCorrectOption, 110, 70);
      break;
    case MATH_SEL3:
      EsploraTFT.stroke(0, 255, 0);
      sOption1 = ft_itoa(options[0]);
      EsploraTFT.text((const char *) sOption1, 110, 30);
      sOption2 = ft_itoa(options[1]);
      EsploraTFT.text((const char *) sOption2, 110, 50);
      sCorrectOption = ft_itoa(options[2]);
      EsploraTFT.stroke(255, 0, 0);
      EsploraTFT.text((const char *) sCorrectOption, 110, 70);
      break;
  }

  delete[] (sOption1);
  delete[] (sOption2);
  delete[] (sCorrectOption);
}

void mathSwitchDown() {
  switch (mathSelectedOption) {
    case MATH_SEL3:
      mathSelectedOption = MATH_SEL1;
      break;
    case MATH_SEL1:
      mathSelectedOption = MATH_SEL2;
      break;
    case MATH_SEL2:
      mathSelectedOption = MATH_SEL3;
      break;
  }
}

void mathSwitchUp() {
  switch (mathSelectedOption) {
    case MATH_SEL3:
      mathSelectedOption = MATH_SEL2;
      break;
    case MATH_SEL2:
      mathSelectedOption = MATH_SEL1;
      break;
    case MATH_SEL1:
      mathSelectedOption = MATH_SEL3;
      break;
  }
}
