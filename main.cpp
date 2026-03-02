// ================= PIN DEFINITIONS =================
const int sensorPin = 2;     // HW-201 IR sensor OUT
const int relayPin  = 8;     // Relay IN (ACTIVE-LOW)
const int buzzerPin = 9;     // Buzzer

// ================= TIMING =================
unsigned long detectStartTime = 0;
const unsigned long delayTime = 3000; // 3 seconds

bool objectDetected = false;

void setup() {
  pinMode(sensorPin, INPUT);
  pinMode(relayPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);

  // Initial safe state
  digitalWrite(relayPin, LOW);   // Motor ON
  digitalWrite(buzzerPin, LOW);  // Buzzer OFF
}

void loop() {

  int sensorState = digitalRead(sensorPin);

  // ================= NO OBJECT DETECTED =================
  // Sensor OUT = HIGH
  if (sensorState == HIGH) {

    objectDetected = false;
    detectStartTime = 0;

    digitalWrite(relayPin, LOW);   // Motor ON
    digitalWrite(buzzerPin, LOW);  // Buzzer OFF
  }

  // ================= OBJECT DETECTED =================
  // Sensor OUT = LOW
  else {

    if (!objectDetected) {
      objectDetected = true;
      detectStartTime = millis();  // start timing
    }

    // Object present for 3 seconds or more
    if (millis() - detectStartTime >= delayTime) {
      digitalWrite(relayPin, HIGH);  // Motor OFF
      digitalWrite(buzzerPin, HIGH); // Buzzer ON
    }
  }
}
