int trigPin = 10; // Ultrasonic Trig pin
int echoPin = 9;  // Ultrasonic Echo pin
int buzzerPin = 12; // Buzzer pin
long duration;
int distance;

void setup() {
  // Initialize the trigPin as an output and the echoPin as an input
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  
  // Initialize serial communication at 9600 baud rate
  Serial.begin(9600);
}

void loop() {
  // Clear the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // Set the trigPin HIGH for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read the echoPin, pulseIn() returns the duration (time) in microseconds
  duration = pulseIn(echoPin, HIGH);

  // Calculate the distance in cm
  distance = duration * 0.034 / 2;

  // Print the distance to the Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Check if the distance is less than 100 cm or approximately 3 feet (91.44 cm)
  if (distance < 100) {
    // Activate the buzzer
    digitalWrite(buzzerPin, HIGH);
  } else {
    // Deactivate the buzzer
    digitalWrite(buzzerPin, LOW);
  }

  // Delay before the next reading
  delay(500);
}
