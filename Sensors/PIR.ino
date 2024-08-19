int pirPin = 7;    // PIR motion sensor pin
int buzzerPin = 8; // Buzzer pin
int pirState = LOW; // Variable to store PIR sensor state
int val = 0;       // Variable to store the PIR sensor output value

void setup() {
  pinMode(pirPin, INPUT); // Set PIR pin as input
  pinMode(buzzerPin, OUTPUT); // Set buzzer pin as output
  Serial.begin(9600); // Initialize serial communication
}

void loop() {
  val = digitalRead(pirPin); // Read the PIR sensor value

  if (val == HIGH) { // If motion is detected
    digitalWrite(buzzerPin, HIGH); // Turn on the buzzer
    if (pirState == LOW) {
      // We have just turned on
      Serial.println("Motion detected!");
      pirState = HIGH;
    }
  } else {
    digitalWrite(buzzerPin, LOW); // Turn off the buzzer
    if (pirState == HIGH) {
      // We have just turned off
      Serial.println("Motion stopped!");
      pirState = LOW;
    }
  }

  delay(100); // Delay for a short while to avoid bouncing
}
