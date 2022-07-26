const bool debug = true;

int yellowP = 2;
int whiteP = 3;
int greenP = 4;

int count = 0;
int lastTime = millis();

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
    if (yellow == HIGH) {
      int deltaTime = lastTime - millis();
      Serial.println(deltaTime);
      //if (deltaTime >= -30) return;
      count++;
      lastTime = millis();
      if (debug) {
        Serial.println("count - " + String(count));
        Serial.println(deltaTime);
      }
    }
  } else if (count != 0) {
    count++;
    if (debug) {
      Serial.println("Suma - " + String(count/2));
      Serial.print("\n\n\n\n\n");
      delay(1000);
    } else {
      Serial.println("Suma - " + String(count/2));
    }
    count = 0;
 }
 
}
