#include <map>
#include <string>

int led = D7;
#define TIME_UNIT 500

std::map<std::string, std::string> letters = {
    {"a", ".-"},
    {"b", "-..."},
    {"c", "-.-."},
    {"d", "-.."},
    {"e", "."},
    {"f", "..-."},
    {"g", "--."},
    {"h", "...."},
    {"i", ".."},
    {"j", ".---"},
    {"k", "-.-"},
    {"l", ".-.."},
    {"m", "--"},
    {"n", "-."},
    {"o", "---"},
    {"p", ".--."},
    {"q", "--.-"},
    {"r", ".-."},
    {"s", "..."},
    {"t", "-"},
    {"u", "..-"},
    {"v", "...-"},
    {"w", ".--"},
    {"x", "-..-"},
    {"y", "-.--"},
    {"z", ".."}
};
std::string w;

void blink_word(std::string word) {
    for (char& ch : word) {
        blink_letter(ch);
        delay(TIME_UNIT * 3);
    }
}

void blink_letter(char ch) {
    std::string morse = letters[std::string(1, ch)];
    for (char& mc : morse) {
        mc == '.' ? dot() : dash();
        delay(TIME_UNIT);
    }
}

void dash() {
    digitalWrite(led, HIGH);
    delay(TIME_UNIT * 3);
    digitalWrite(led, LOW);
}

void dot() {
    digitalWrite(led, HIGH);
    delay(TIME_UNIT);
    digitalWrite(led, LOW);
}

void setup() {
    pinMode(led, OUTPUT);
    w = "oscar";
}

void loop() {
    blink_word(w);
}
