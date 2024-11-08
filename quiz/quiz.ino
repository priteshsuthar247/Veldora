#include <LiquidCrystal.h>
#include <string.h>

const int rs = 7, en = 6, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

#define LEFT_BUTTON 13
#define RIGHT_BUTTON 10

// Define quiz structure
struct quiz {
    const char* ques;
    bool correctAnswer;
};

// Store questions in regular memory
const struct quiz quizzes[] = {
    {"C has pointers?", true},
    {"Java is compiled?", false},
    {"Python uses indentation?", true},
    {"C++ supports OOP?", true},
    {"JavaScript is Java?", false},
    {"Python is case-sensitive?", true},
    {"C has no garbage collection?", true},
    {"Java runs on JVM?", true},
    {"C++ can inherit classes?", true},
    {"Python has static typing?", false},
    {"C supports structs?", true},
    {"Java uses interfaces?", true},
    {"Python has lists?", true},
    {"C++ allows multiple inheritance?", true},
    {"Java is platform-independent?", true},
    {"Python is statically typed?", false},
    {"C has a standard library?", true},
    {"Java can throw exceptions?", true},
    {"C++ uses headers?", true},
    {"Python supports lambda?", true}
};

char buffer[50];

void printQuestion(const char* ques) {
    lcd.clear();
    lcd.setCursor(0, 0);

    strncpy(buffer, ques, 16);
    buffer[16] = '\0';
    lcd.print(buffer);

    if (strlen(ques) > 16) {
        lcd.setCursor(0, 1);
        strncpy(buffer, ques + 16, 16);
        buffer[16] = '\0';
        lcd.print(buffer);
    }
}

void setup() {
    lcd.begin(16, 2);
    pinMode(LEFT_BUTTON, INPUT_PULLUP);
    pinMode(RIGHT_BUTTON, INPUT_PULLUP);
}

void loop() {
    lcd.clear();
    for (int i = 0; i < sizeof(quizzes) / sizeof(quizzes[0]); i++) {
        printQuestion(quizzes[i].ques);
        delay(400);

        bool userAnswered = false;
        while (!userAnswered) {
            if (digitalRead(LEFT_BUTTON) == LOW) {
                delay(200);
                displayResult(quizzes[i].correctAnswer);
                userAnswered = true;
            }
            if (digitalRead(RIGHT_BUTTON) == LOW) {
                delay(200);
                displayResult(!quizzes[i].correctAnswer);
                userAnswered = true;
            }
        }

        // delay(2000);
    }
}

void displayResult(bool isCorrect) {
    lcd.clear();
    lcd.setCursor(0, 0);
    if (isCorrect) {
        lcd.print("Correct!");
    } else {
        lcd.print("Incorrect!");
    }
    delay(1000);
}
