#include "mathGame.h"
int MATH_SCORE;

void mathGameInit() {
  EsploraTFT.background(0, 0, 0);
  EsploraTFT.stroke(255, 255, 0);
  EsploraTFT.setTextSize(3);
  EsploraTFT.text("Math game", 0, 0);
  EsploraTFT.setTextSize(2);
}

int result1, result2, correctResult, a, b;
int difficultyLevel = 1;
int mathSelectedOption = SEL1;
int mathPrevGameState = DIVISION;
int currentMathGameState = SUM;
char currentSign = '+';
int coordinates[3];
int indexesOfResults[3];
int results[3];
int indexes[3];

void mathGameMain() {


  if (!Esplora.readButton(SWITCH_LEFT)) {
    menuState = MATH_SEL;
    prevGameState = SELECTION;
    menuInit();
    delay(100);
    while (!Esplora.readButton(SWITCH_LEFT));
  }

  if (!Esplora.readButton(SWITCH_RIGHT)) {
    mathGameSwitch();
    displayMathMenu();
    Serial.println(correctResult);
    for (int i = 0; i < 3; ++i)
      Serial.println(coordinates[i]);
    delay(100);
    while (!Esplora.readButton(SWITCH_RIGHT));
  }

  if (!Esplora.readButton(SWITCH_UP)) {

    mathSwitchUp();
    displayAnswers();
    switch (mathSelectedOption) {
      case SEL1:
        Serial.println("SEL1");
        break;
      case SEL2:
        Serial.println("SEL2");
        break;
      case SEL3:
        Serial.println("SEL3");
        break;
    }

    delay(100);
    while (!Esplora.readButton(SWITCH_UP));
  }

  if (!Esplora.readButton(SWITCH_DOWN)) {
    mathSwitchDown();
    displayAnswers();

    switch (mathSelectedOption) {
      case SEL1:
        Serial.println("SEL1");
        break;
      case SEL2:
        Serial.println("SEL2");
        break;
      case SEL3:
        Serial.println("SEL3");
        break;
    }
    delay(100);
    while (!Esplora.readButton(SWITCH_DOWN));
  }

}

void displayMathMenu() {
  displayExpresion();
  displayAnswers();
}

void displayExpresion() {
  mathGameInit();

  EsploraTFT.stroke(100, 255, 0);
  const char *strEquation = makeEquationString(a, b, currentSign);
  EsploraTFT.text(strEquation, 0, 50);
  delete[] (strEquation);
}
void printIndexes() {
  Serial.println("Indexes: ");
  for (int i = 0; i < 3; ++i) {
    Serial.println(i);
    Serial.println(indexes[i]);
  }
  Serial.println("====================================");
}


void displayAnswers() {
  getRandomCoordinates();
  results[indexes[0]] = result1;
  results[indexes[1]] = result2;
  results[indexes[2]] = correctResult;
//  printResults();/
  Serial.println("displayAnswers");

  char *sResult1, *sResult2, *sCorrectResult;
  switch (mathSelectedOption) {
    case SEL1:
      EsploraTFT.stroke(255, 0, 0);
      sResult1 = intToCStr(result1);
      EsploraTFT.text((const char *) sResult1, 120, 30);
      EsploraTFT.stroke(0, 255, 0);
      sResult2 = intToCStr(result2);
      EsploraTFT.text((const char *) sResult2, 120, 50);
      sCorrectResult = intToCStr(correctResult);
      EsploraTFT.text((const char *) sCorrectResult, 120, 70);
      break;
    case SEL2:
      EsploraTFT.stroke(0, 255, 0);
      sResult1 = intToCStr(result1);
      EsploraTFT.text((const char *) sResult1, 120, 30);
      EsploraTFT.stroke(255, 0, 0);
      sResult2 = intToCStr(result2);
      EsploraTFT.text((const char *) sResult2, 120, 50);
      EsploraTFT.stroke(0, 255, 0);
      sCorrectResult = intToCStr(correctResult);
      EsploraTFT.text((const char *) sCorrectResult, 120, 70);
      break;
    case SEL3:
      EsploraTFT.stroke(0, 255, 0);
      sResult1 = intToCStr(result1);
      EsploraTFT.text((const char *) sResult1, 120, 30);
      sResult2 = intToCStr(result2);
      EsploraTFT.text((const char *) sResult2, 120, 50);
      sCorrectResult = intToCStr(correctResult);
      EsploraTFT.stroke(255, 0, 0);
      EsploraTFT.text((const char *) sCorrectResult, 120, 70);
      break;
  }

  delete[] (sResult1);
  delete[] (sResult2);
  delete[] (sCorrectResult);
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

bool isCorrectAnswer() {
  Serial.println("isCorrectAnswer");
  for (int i = 0; i < 3; i++) {
    Serial.println("THERE" + correctResult);
    if (correctResult == coordinates[i])
      Serial.println(i + " " + correctResult);
  }
  //  mathSelectedOption = SEL1;/
  return ((mathSelectedOption == SEL1 && correctResult == results[indexes[0]])
          || (mathSelectedOption == SEL2 && correctResult == results[indexes[1]])
          || (mathSelectedOption == SEL3 && correctResult == results[indexes[2]]));
}

// + * - /
void mathGameSwitch() {
  Serial.println("mathGameSwitch");
  switch (mathPrevGameState) {
    case DIVISION:
      if (isCorrectAnswer()) {
        Serial.println("HURAAAAAAAAAAAA!!!!!!!!");
        mathPrevGameState = SUM;
      }

      else {
        mathSelectedOption = SEL1;//
        Serial.println("SUKA");
        mathPrevGameState = INCORRECT;
      }

      getSum();
      currentSign = '+';
      break;
    case SUM:
      if (isCorrectAnswer()) {
        Serial.println("HURAAAAAAAAAAAA!!!!!!!!");
        mathPrevGameState = PRODUCT;
      }

      else {
        Serial.println("SUKA");
        mathSelectedOption = SEL1;//
        mathPrevGameState = INCORRECT;
      }

      getProduct();
      currentSign = '*';
      break;
    case INCORRECT:
      mathPrevGameState = DIVISION;
      break;
    default:

      break;
  }
}





void getRandomCoordinates() {
  int possibleCoordinates[] = {30, 50, 70};
  int randomIndex = rand() % 3;

  indexes[0] = randomIndex;
  indexes[1] = (randomIndex + 1) % 3;
  indexes[2] = (randomIndex + 2) % 3;
//  printIndexes();/
  coordinates[0] = possibleCoordinates[indexes[0]];
  coordinates[1] = possibleCoordinates[indexes[1]];
  coordinates[2] = possibleCoordinates[indexes[2]];
}

void printResults() {
  Serial.println("RESULTS: ");
  for (int i = 0; i < 3; ++i) {
    Serial.println(i);
    Serial.println(results[i]);
  }
  Serial.println("====================================");
}

void getSum() {
  a = rand() % (difficultyLevel * 10 + 1);
  b = rand() % (difficultyLevel * 10 + 1);

  int sum = a + b;

  // Generate unique values for result1, result2, and correctResult
  do {
    result1 = rand() % (sum + 1); // generate random number between 0 and sum
    result2 = rand() % (sum + 1); // generate random number between 0 and sum
    correctResult = a + b;       // calculate the correct result
  } while (result1 == result2 || result1 == correctResult || result2 == correctResult);
}


void getProduct() {
  a = rand() % (difficultyLevel * 10 + 1);
  b = rand() % (difficultyLevel * 10 + 1);

  result1 = rand() % 5 * (a * b);
  result2 = rand() % 4 * (a * b);

  correctResult = a * b;
}
