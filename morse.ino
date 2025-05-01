const int ledPin = 13;

const char* morseMap[36] = {
  ".-", "-...", "-.-.", "-..", ".",   "..-.", "--.", "....", "..",
  ".---","-.-", ".-..","--",  "-.",  "---", ".--.", "--.-",".-.",
  "...", "-",   "..-","...-",".--","-..-","-.--","--..",
  "-----",".----","..---","...--","....-",".....","-....","--...","---..","----."
};

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if (Serial.available()) {
    String input = Serial.readStringUntil('\n');
    input.toUpperCase();
    blinkMorse(input);
  }
}

void blinkMorse(const String& text) {
  for (int i = 0; i < text.length(); i++) {
    char c = text[i];
    if (c >= 'A' && c <= 'Z') {
      flashSymbol(morseMap[c - 'A']);
      pauseUnits(3);
    }
    else if (c >= '0' && c <= '9') {
      flashSymbol(morseMap[26 + (c - '0')]);
      pauseUnits(3);
    }
    else if (c == ' ') {
      pauseUnits(7);
    }
  }
}

void flashSymbol(const char* symbols) {
  for (int j = 0; symbols[j] != '\0'; j++) {
    if (symbols[j] == '.') {
      digitalWrite(ledPin, HIGH);
      pauseUnits(1);
      digitalWrite(ledPin, LOW);
    } else {
      digitalWrite(ledPin, HIGH);
      pauseUnits(3);
      digitalWrite(ledPin, LOW);
    }
    pauseUnits(1);
  }
}

void pauseUnits(int units) {
  delay(250 * units);
}
