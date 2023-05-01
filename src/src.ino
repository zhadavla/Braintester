
void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

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
