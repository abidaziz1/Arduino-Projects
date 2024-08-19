int BUTTON = 7;
int LED = 8;
bool ledState = false;  // To keep track of whether the LED should be blinking or not
bool buttonState = false;
bool lastButtonState = false;

void setup() {
  // Initialize the button pin as an input
  pinMode(BUTTON, INPUT);
  // Initialize the LED pin as an output
  pinMode(LED, OUTPUT);
}

void loop() {
  // Read the current state of the button
  buttonState = digitalRead(BUTTON);

  // Check if the button is pressed (HIGH) and was previously not pressed (LOW)
  if (buttonState == HIGH && lastButtonState == LOW) {
    // Toggle the ledState
    ledState = !ledState;
  }

  // Save the current button state as the last button state for the next loop iteration
  lastButtonState = buttonState;

  // If ledState is true, blink the LED
  if (ledState) {
    digitalWrite(LED, HIGH);
    delay(500);  // Delay for 500 milliseconds
    digitalWrite(LED, LOW);
    delay(500);  // Delay for 500 milliseconds
  } else {
    digitalWrite(LED, LOW);  // Ensure the LED is off when ledState is false
  }
}
