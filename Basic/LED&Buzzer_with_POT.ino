int potPin = A0;       // Potentiometer connected to analog pin A0
int buzzerPin = 11;     // Buzzer connected to PWM pin 9
int ledPin = 9;       // LED connected to PWM pin 10

void setup() {
  // Initialize serial communication for debugging
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // Read the potentiometer value (0-1023)
  int potValue = analogRead(potPin);
  
  // Map the potentiometer value to a suitable frequency range for the buzzer (e.g., 200 - 2000 Hz)
  int buzzerFrequency = map(potValue, 0, 1023, 200, 2000);
  
  // Map the potentiometer value to the PWM range for the LED (0-255)
  int ledBrightness = map(potValue, 0, 1023, 0, 255);
  
  // Set the buzzer frequency
  tone(buzzerPin, buzzerFrequency);
  
  // Set the LED brightness
  analogWrite(ledPin, ledBrightness);
  
  // Delay for a short time to smooth out the changes
  delay(100);
}
