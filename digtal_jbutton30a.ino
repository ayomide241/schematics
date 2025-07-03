int a = 2;
int b = 3;
int c = 4;
int d = 5;
int e = 6;
int f = 7;
int g = 8;

int incBtn = 9;
int decBtn = 10;

int currentDigit = 0;

unsigned long lastPressTime = 0;
const unsigned long repeatDelay = 400;  
const unsigned long repeatRate = 150;   

bool incHeld = false;
bool decHeld = false;

void setup() {
  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);
  pinMode(e, OUTPUT);
  pinMode(f, OUTPUT);
  pinMode(g, OUTPUT);

  pinMode(incBtn, INPUT_PULLUP); 
  pinMode(decBtn, INPUT_PULLUP);

  displayDigit(currentDigit);
}

void loop() {
  bool incPressed = digitalRead(incBtn) == LOW;
  bool decPressed = digitalRead(decBtn) == LOW;
  unsigned long now = millis();

  // Increment handling
  if (incPressed && !incHeld) {
    if (currentDigit < 9) currentDigit++;
    displayDigit(currentDigit);
    lastPressTime = now;
    incHeld = true;
  } else if (incPressed && incHeld && (now - lastPressTime >= repeatDelay)) {
    if (now - lastPressTime >= repeatRate) {
      if (currentDigit < 9) currentDigit++;
      displayDigit(currentDigit);
      lastPressTime = now;
    }
  } else if (!incPressed) {
    incHeld = false;
  }

  // Decrement handling
  if (decPressed && !decHeld) {
    if (currentDigit > 0) currentDigit--;
    displayDigit(currentDigit);
    lastPressTime = now;
    decHeld = true;
  } else if (decPressed && decHeld && (now - lastPressTime >= repeatDelay)) {
    if (now - lastPressTime >= repeatRate) {
      if (currentDigit > 0) currentDigit--;
      displayDigit(currentDigit);
      lastPressTime = now;
    }
  } else if (!decPressed) {
    decHeld = false;
  }
}

void displayDigit(int n) {
  switch (n) {
    case 0:
    digitalWrite(a, HIGH);
    digitalWrite(b, HIGH);
    digitalWrite(c, HIGH);
    digitalWrite(d, HIGH);
    digitalWrite(e, HIGH);
    digitalWrite(f, HIGH);
    digitalWrite(g, LOW);
    break;
    case 1:
    digitalWrite(a, LOW);
    digitalWrite(b, HIGH);
    digitalWrite(c, HIGH);
    digitalWrite(d, LOW);
    digitalWrite(e, LOW);
    digitalWrite(f, LOW);
    digitalWrite(g, LOW);
    break;
    case 2:
    digitalWrite(a, HIGH);
    digitalWrite(b, HIGH);
    digitalWrite(c, LOW);
    digitalWrite(d, HIGH);
    digitalWrite(e, HIGH);
    digitalWrite(f, LOW);
    digitalWrite(g, HIGH);
    break;
    case 3:
    digitalWrite(a, HIGH);
    digitalWrite(b, HIGH);
    digitalWrite(c, HIGH);
    digitalWrite(d, HIGH);
    digitalWrite(e, LOW);
    digitalWrite(f, LOW);
    digitalWrite(g, HIGH);
    break;
    case 4:
    digitalWrite(a, LOW);
    digitalWrite(b, HIGH);
    digitalWrite(c, HIGH);
    digitalWrite(d, LOW);
    digitalWrite(e, LOW);
    digitalWrite(f, HIGH);
    digitalWrite(g, HIGH);
    break;
    case 5:
    digitalWrite(a, HIGH);
    digitalWrite(b, LOW);
    digitalWrite(c, HIGH);
    digitalWrite(d, HIGH);
    digitalWrite(e, LOW);
    digitalWrite(f, HIGH);
    digitalWrite(g, HIGH);
    break;
    case 6:
    digitalWrite(a, HIGH);
    digitalWrite(b, LOW);
    digitalWrite(c, HIGH);
    digitalWrite(d, HIGH);
    digitalWrite(e, HIGH);
    digitalWrite(f, HIGH);
    digitalWrite(g, HIGH);
    break;
    case 7:
    digitalWrite(a, HIGH);
    digitalWrite(b, HIGH);
    digitalWrite(c, HIGH);
    digitalWrite(d, LOW);
    digitalWrite(e, LOW);
    digitalWrite(f, LOW);
    digitalWrite(g, LOW);
    break;
    case 8:
    digitalWrite(a, HIGH);
    digitalWrite(b, HIGH);
    digitalWrite(c, HIGH);
    digitalWrite(d, HIGH);
    digitalWrite(e, HIGH);
    digitalWrite(f, HIGH);
    digitalWrite(g, HIGH);
    break;
    case 9:
    digitalWrite(a, HIGH);
    digitalWrite(b, HIGH);
    digitalWrite(c, HIGH);
    digitalWrite(d, HIGH);
    digitalWrite(e, LOW);
    digitalWrite(f, HIGH);
    digitalWrite(g, HIGH);
    break;
  }
}