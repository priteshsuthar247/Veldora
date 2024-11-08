#include <LiquidCrystal.h>
#include <string.h>

const int rs = 7, en = 6, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

byte DINO_FOOT_PART_1[8] = { B00000, B00000, B00010, B00010, B00011, B00011, B00001, B00001 };
byte DINO_PART_1[8] = { B00111, B00111, B00111, B00100, B11100, B11100, B11000, B01000 };
byte DINO_FOOT_PART_2[8] = { B00000, B00000, B00010, B00010, B00011, B00011, B00001, B00001 };
byte DINO_PART_2[8] = { B00111, B00111, B00111, B00100, B11100, B11100, B11000, B00000 };
byte DINO_FOOT_PART_3[8] = { B00000, B00000, B00010, B00010, B00011, B00011, B00001, B00000 };
byte DINO_PART_3[8] = { B00111, B00111, B00111, B00100, B11100, B11100, B11000, B01000 };
byte CACTUS_1[8] = { B00000, B00100, B00100, B10100, B10100, B11100, B00100, B00100 };
byte CACTUS_2[8] = { B00100, B00101, B00101, B10101, B11111, B00100, B00100, B00100 };
byte BIRD_PART_1[8] = { B00001, B00001, B00001, B00001, B01001, B11111, B00000, B00000 };
byte BIRD_PART_2[8] = { B00000, B10000, B11000, B11100, B11110, B11111, B00000, B00000 };

int dino_column_1 = 1;
int dino_column_2 = 2;
int dino_row = 1;
unsigned long clock = 0;
int period = 100;
int flag = 1;
int cactus_row = 0;
int cactus_column = 13;
int period2 = 100;
unsigned long clock2 = 0;
int a = 0;
int b = 1;
int c = 2;
int d = 0;
unsigned long clock3 = 0;
int period3 = 100;
int points_1 = 0;
int points_2 = 0;
int randomnumber = 0;
int bird_column = 13;
int e = 0;
int bird_row = 1;
int current_signal = 0;
int old_signal = 0;
int f = 13;
int acceleration = 1;
unsigned long clock4 = 0;
int period4 = 800;
int button = 11;

void setup() {
  for (int i = 2; i <= 17; i++) pinMode(i, OUTPUT);

  pinMode(button, INPUT);

  lcd.begin(16, 2);
  lcd.createChar(0, DINO_FOOT_PART_1);
  lcd.createChar(1, DINO_PART_1);
  lcd.createChar(2, DINO_FOOT_PART_2);
  lcd.createChar(3, DINO_PART_2);
  lcd.createChar(4, DINO_FOOT_PART_3);
  lcd.createChar(5, DINO_PART_3);
  lcd.createChar(6, CACTUS_1);
  lcd.createChar(7, CACTUS_2);
}
void loop() {
  if (millis() > clock + period) {
    clock = millis();
    if (flag == 1) {
      flag = 2;
    } else if (flag == 2) {
      flag = 1;
    }
  }

  if (millis() > clock2 + period2) {
    clock2 = millis();

    cactus_column = cactus_column - 1;
    if (cactus_column < 0) {
      cactus_column = 13;
      period2 = period2 - acceleration;
      randomnumber = random(0, 3);
    }

    f = cactus_column + 1;
    lcd.setCursor(f, 1);  //limpio abajo
    lcd.print(" ");

    f = cactus_column + 1;
    lcd.setCursor(f, 0);
    lcd.print(" ");


    lcd.setCursor(0, 1);
    lcd.print(" ");

    lcd.setCursor(0, 0);
    lcd.print(" ");

    a = 1;
  }

  if (d == 0) {
    if (flag == 1) {
      lcd.setCursor(dino_column_1, dino_row);
      lcd.write(byte(2));
      lcd.setCursor(dino_column_2, dino_row);
      lcd.write(byte(3));
    }
    if (flag == 2) {
      lcd.setCursor(dino_column_1, dino_row);
      lcd.write(byte(4));
      lcd.setCursor(dino_column_2, dino_row);
      lcd.write(byte(5));
    }
  }

  if (a == 1) {

    if (randomnumber == 1) {
      cactus_row = 1;
      lcd.createChar(6, CACTUS_1);
      lcd.setCursor(cactus_column, cactus_row);
      lcd.write(byte(6));

    } else if (randomnumber == 2) {
      cactus_row = 1;
      lcd.createChar(7, CACTUS_2);
      lcd.setCursor(cactus_column, cactus_row);
      lcd.write(byte(7));

    } else {

      bird_column = cactus_column;
      bird_column = bird_column - 1;
      cactus_row = 0;
      lcd.createChar(6, BIRD_PART_1);
      lcd.setCursor(bird_column, cactus_row);
      lcd.write(byte(6));

      lcd.createChar(7, BIRD_PART_2);
      lcd.setCursor(cactus_column, cactus_row);
      lcd.write(byte(7));
    }
    a = 0;
  }

  if (digitalRead(button) == HIGH && (cactus_column == 1 || cactus_column == 2 || bird_column == 1 || bird_column == 2) && cactus_row == 0) {
    lcd.clear();
    lcd.setCursor(5, 0);
    lcd.print("GAME OVER");
    delay(2000);
    lcd.clear();
    cactus_column = 15;
    period2 = 100;
    points_1 = 0;
    points_2 = 0;
    period2 = 100;
  }

  if ((cactus_column == b || cactus_column == c) && cactus_row == 1) {
    int note[] = { 200, 150 };
    for (int i = 0; i < 2; i++) {
      delay(200);
    }
    lcd.clear();
    lcd.setCursor(5, 0);
    lcd.print("GAME OVER");
    delay(2000);
    lcd.clear();
    cactus_column = 15;
    period2 = 100;
    points_1 = 0;
    points_1 = 2;
    period2 = 100;
  }

  if (digitalRead(button) == HIGH) {

    b = 50;
    c = 50;

    if (d == 0) {
      lcd.setCursor(0, 1);
      lcd.print("    ");
    }
    d = 1;

    lcd.setCursor(dino_column_1, 0);
    lcd.write(byte(2));
    lcd.setCursor(dino_column_2, 0);
    lcd.write(byte(3));

    if (millis() > clock4 + period4) {
      clock4 = millis();

      int note[] = { 600 };
      for (int i = 0; i < 1; i++) {
        delay(20);
      }
    }
  } else {
    b = 1;
    c = 2;
    d = 0;
  }

  if (millis() > clock3 + period3) {
    clock3 = millis();
    lcd.setCursor(14, 1);
    lcd.print(points_1);

    points_1 = points_1 + 1;

    if (points_1 == 100) {
      int note[] = { 800, 900 };
      for (int i = 0; i < 2; i++) {
        delay(150);
        points_1 = 0;
        points_2 = points_2 + 1;
        if (points_2 == 100) {
          points_2 = 0;
        }
      }
    }


    lcd.setCursor(14, 1);
    lcd.print(points_1);
    lcd.setCursor(14, 0);
    lcd.print(points_2);

    current_signal = digitalRead(button);
    if (current_signal != old_signal) {
      lcd.setCursor(1, 0);
      lcd.print("  ");
    }
    old_signal = current_signal;
  }
}