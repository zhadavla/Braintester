# BrainTester Project
The BrainTester project is a fun and challenging way to improve your memory and math skills using the Esplora buttons and TFT display on the Arduino Esplora platform.

## Features
The project includes two games:

**Random LED Flashing mode**: The screen randomly flashes one of four lights, and the player must identify which lights were illuminated. The difficulty level increases as the length of the light sequence increases.

**Mathematical Operations mode**: Four arithmetic operations (+, -, *) are randomly generated, and the player must solve them by selecting one of three potential answers. The difficulty level increases in correlation with the complexity of the mathematical operations.
Both games have multiple levels, with each level increasing in difficulty to provide a greater challenge for the user.

## Navigation
To navigate through the menu options available in the BrainTester project, kindly make use of the Esplora device's up and down switches. After identifying the desired option, please select it by pressing the right switch. To return to the previous menu, simply use the left switch.

**Note that when led is blinking, the back button doesn't work. You have to end the game to return to the main menu.**

## Issues
During the development of the math game, issues with dividing operations occurred when generating random float numbers. This problem was resolved through the use of type casting, which ensured accurate calculations. However, the dividing option was eventually removed from the game.

### Global Variables
The project includes external global variables to improve the efficiency and organization of the code. These variables can be accessed and modified throughout the project.

#### Through the development of this project, I have learned how to declare global variables visible throughout the project and how to protect headers shortly.


# Getting Started
To start the BrainTester project, you will need an Arduino Esplora platform, which can be purchased from your local electronics store or online retailer. Once you have the hardware, follow these steps:

Connect your Arduino Esplora to your computer using a USB cable.
1. Download and install the Arduino IDE software from the official website.
2. Open the Arduino IDE and select the Esplora board from the Tools menu.
3. Download the BrainTester project files from the official repository.
4. Open the project files in the Arduino IDE and upload them to your Esplora board.
5. Have fun challenging your brain with the BrainTester project!
