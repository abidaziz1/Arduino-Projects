// Define the pin numbers
const int pirPin = 7;    // PIR motion sensor connected to pin 7
const int buzzerPin = 8; // Buzzer connected to pin 8

// Variables
int pirState = LOW;      // Start assuming no motion detected
int val = 0;             // Variable to store the PIR sensor value

void setup() {
  pinMode(pirPin, INPUT);     // Set PIR pin as input
  pinMode(buzzerPin, OUTPUT); // Set buzzer pin as output
  
  // Begin serial communication for debugging (optional)
  Serial.begin(9600);
}

void loop() {
  // Read the value from the PIR motion sensor
  val = digitalRead(pirPin);

  if (val == HIGH) {            // If motion is detected
    digitalWrite(buzzerPin, HIGH); // Turn the buzzer on
    if (pirState == LOW) {      // If the PIR state was previously LOW
      Serial.println("Motion detected!"); // Print a message to the serial monitor
      pirState = HIGH;          // Update the PIR state to HIGH
    }
  } else {                      // If no motion is detected
    digitalWrite(buzzerPin, LOW);  // Turn the buzzer off
    if (pirState == HIGH) {     // If the PIR state was previously HIGH
      Serial.println("Motion stopped!"); // Print a message to the serial monitor
      pirState = LOW;           // Update the PIR state to LOW
    }
  }
}
