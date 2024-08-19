// Pin definitions
const int ledPin = 13; // LED connected to digital pin 13

// Array to hold the brightness levels
int brightnessLevels[] = {0, 64, 128, 191, 255, 191, 128, 64};
int index = 0; // Index to traverse the brightnessLevels array

void setup() {
  // Initialize the LED pin as an output
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // Set the brightness of pin 13 (LED)
  analogWrite(ledPin, brightnessLevels[index]);

  // Move to the next brightness level
  index++;

  // If we've reached the end of the array, start over
  if (index >= sizeof(brightnessLevels)/sizeof(brightnessLevels[0])) {
    index = 0;
  }

  // Wait for 500 milliseconds to see the change in brightness
  delay(500);
}
