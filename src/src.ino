#include <Esplora.h>
#include <TFT.h>
#include <SPI.h>

int menu = 0;

void setup() {
   EsploraTFT.begin();
    EsploraTFT.background(0, 0, 0);
    EsploraTFT.stroke(255, 255, 0);
    EsploraTFT.setTextSize(3);
    EsploraTFT.text("Main menu:\n", 0, 0);
    EsploraTFT.setTextSize(2);
    EsploraTFT.stroke(0, 0, 255); // Math game selected at the begining
    EsploraTFT.text("Math game", 30, 25);
    EsploraTFT.stroke(100, 255, 255); // std color for menu
    EsploraTFT.text("LEDs\n ", 50, 50);
    EsploraTFT.text("Highest score\n ", 5, 75);
}

void loop() {
  

}

void updateMenu(){
  switch (menu){
    case 0: 
       highlightMenuOption(30, 25, "Math game");
       break;
    case 1:
       highlightMenuOption(50, 50, "LEDs");
       break;
    case 2:
      highlightMenuOption(5, 75, "Highest score");
      break;
   }
  
}

void highlightMenuOption(int x, int y, const char *txt) {
    const char *text = txt;
    EsploraTFT.stroke(0, 0, 255);  
    EsploraTFT.text(txt, x, y);
    EsploraTFT.stroke(100, 255, 255);  
    if (y == 25) {
        EsploraTFT.text("LEDs", 50, 50);
        EsploraTFT.text("Highest score", 5, 75);
    } else if (y == 50) {
        EsploraTFT.text("Math game", 30, 25);
        EsploraTFT.text("Highest score", 5, 75);
    } else {
        EsploraTFT.text("Math game", 30, 25);
        EsploraTFT.text("LEDs", 50, 50);
    }
}
