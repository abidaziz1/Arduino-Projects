int potPin = A0;       // Potentiometer connected to analog pin A0
int buzzerPin = 9;     // Buzzer connected to PWM pin 9

void setup() {
  // Initialize serial communication for debugging
  Serial.begin(9600);
}

void loop() {
  // Read the potentiometer value (0-1023)
  int potValue = analogRead(potPin);
  
  // Map the potentiometer value to a suitable frequency range for the buzzer (e.g., 200 - 2000 Hz)
  int buzzerFrequency = map(potValue, 0, 1023, 200, 2000);
  
  // Set the buzzer frequency
  tone(buzzerPin, buzzerFrequency);
  
  // Delay for a short time to smooth out the changes
  delay(100);
}
