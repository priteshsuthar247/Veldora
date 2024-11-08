#include <LiquidCrystal.h>

LiquidCrystal lcd(8, 9, 10, 11, 12, 13);

const int dpad_up = A3;
const int dpad_down = A4;
const int dpad_right = A2;
const int dpad_left = A5;
const int button_a = A1;
const int button_b = A0;

int menuIndex = 0;
int gameState = 0;

void setup() {
  pinMode(dpad_up, INPUT_PULLUP);
  pinMode(dpad_down, INPUT_PULLUP);
  pinMode(dpad_right, INPUT_PULLUP);
  pinMode(dpad_left, INPUT_PULLUP);
  pinMode(button_a, INPUT_PULLUP);
  pinMode(button_b, INPUT_PULLUP);
  lcd.begin(16, 2);

  lcd.setCursor(0, 0);
  lcd.print("Welcome to");
  lcd.setCursor(0, 1);
  lcd.print("Veldora");
  delay(2000);
  lcd.clear();
  delay(500);
  displayMenu();
}

void loop() {
  if (gameState == 0) {
    navigateMenu();
  } else {
    playGame();
  }
}

void navigateMenu() {
  if (digitalRead(dpad_up) == LOW) {
    menuIndex--;
    if (menuIndex < 0) menuIndex = 2;
    displayMenu();
    delay(300);
  }

  if (digitalRead(dpad_down) == LOW) {
    menuIndex++;
    if (menuIndex > 2) menuIndex = 0;
    delay(300);
  }

  if (digitalRead(button_b) == LOW) {
    gameState = menuIndex + 1;
    lcd.clear();
    delay(300);
  }
}

void displayMenu() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Select a game:");

  lcd.setCursor(0, 1);
  if (menuIndex == 0) {
    lcd.print("> Dino");
  } else if (menuIndex == 1) {
    lcd.print("> Tic-Tac-Toe");
  } else if (menuIndex == 2) {
    lcd.print("> Quiz");
  }
}

void playGame() {
  switch (gameState) {
    case 1:
      dinoGame();
      break;
    case 2:
      ticTacToeGame();
      break;
    case 3:
      trueFalseQuizGame();
      break;
  }
  askForReplay();
}

void dinoGame() {
  while (true) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Playing Dino...");
    delay(2000);


    if (digitalRead(A1) == LOW) {
      lcd.clear();
      delay(400);
      return;
    }
  }
}

void ticTacToeGame() {
  while (true) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Tic-Tac-Toe...");
    delay(2000);

    if (digitalRead(A1) == LOW) {
      lcd.clear();
      delay(400);
      return;
    }
  }
}

void trueFalseQuizGame() {
  while (true) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Quiz...");
    delay(2000);
    if (digitalRead(A1) == LOW) {
      lcd.clear();
      delay(400);
      return;
    }
  }
}

void askForReplay() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Play again?");
  lcd.setCursor(0, 1);
  lcd.print("A:Yes B:Menu");

  while (true) {
    if (digitalRead(button_a) == LOW) {
      delay(300);
      playGame();
    }

    if (digitalRead(button_b) == LOW) {
      delay(300);
      gameState = 0;
      displayMenu();
      break;
    }
  }
}
