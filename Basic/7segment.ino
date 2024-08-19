// Define the pins connected to each segment
const int segmentPins[] = {2, 3, 4, 5, 6, 7, 8}; // Update these pins based on your actual wiring
const int numDigits = 7; // Number of segments

// Define the segment patterns for numbers 0-9
const byte digitPatterns[10][numDigits] = {
  {1, 1, 1, 1, 1, 1, 0}, // 0
  {0, 1, 1, 0, 0, 0, 0}, // 1
  {1, 1, 0, 1, 1, 0, 1}, // 2
  {1, 1, 1, 1, 0, 0, 1}, // 3
  {0, 1, 1, 0, 0, 1, 1}, // 4
  {1, 0, 1, 1, 0, 1, 1}, // 5
  {1, 0, 1, 1, 1, 1, 1}, // 6
  {1, 1, 1, 0, 0, 0, 0}, // 7
  {1, 1, 1, 1, 1, 1, 1}, // 8
  {1, 1, 1, 1, 0, 1, 1}  // 9
};

void setup() {
  // Set all segment pins as output
  for (int i = 0; i < numDigits; i++) {
    pinMode(segmentPins[i], OUTPUT);
  }
}

void loop() {
  // Loop through each digit from 0 to 9
  for (int num = 0; num <= 9; num++) {
    // Set the segments for the current digit
    for (int i = 0; i < numDigits; i++) {
      digitalWrite(segmentPins[i], digitPatterns[num][i]);
    }
    delay(1000); // Wait for 1 second before showing the next number
  }
}
