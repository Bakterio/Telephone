const bool debug = false;

int yellowP = 2;
int whiteP = 3;
int greenP = 4;

int count = 0;
int lastTime = millis();
int lastStatus = LOW;

void setup() {
  Serial.begin(9600);
  pinMode(yellowP, INPUT_PULLUP);
  pinMode(whiteP, INPUT_PULLUP);
  pinMode(greenP, INPUT_PULLUP);
}

void loop() {
 int yellow = digitalRead(yellowP);
 int white = digitalRead(whiteP);
 int green = digitalRead(greenP);
 if (debug) Serial.println("Y - " + String(yellow) + " W - " + String(white) + " G - " + String(green));

 if (white == LOW) {
    if (yellow == HIGH && lastStatus == LOW) {
      //Serial.println("counting");
      int deltaTime = lastTime - millis();
      if (debug) Serial.println(deltaTime);
      if (deltaTime == 0) return;
      count++;
      lastTime = millis();
      if (debug) {
        Serial.println("count - " + String(count));
        Serial.println(deltaTime);
      }
    }
    lastStatus = yellow;
  } else if (count != 0) {
    if (debug) {
      Serial.println("Suma - " + String(count));
      Serial.print("\n\n\n\n\n");
      delay(1000);
    } else {
      Serial.print(String(count) + ",");
    }
    count = 0;
 }
}

void displayNumber(int number) {
//nemám odpor, takže to nemůžu zkoušet :(
}
