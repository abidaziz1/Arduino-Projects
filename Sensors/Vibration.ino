// sound intesity increase/decrease koro knob ghuriye

int vibrarationInPin = 2;// define pin 2 for vibraration sensor 
int relayPin = 8;// pin connected to relay 

int  onTime= 1000; // time in melliseond ON and wait before make another reading.
int  offTime= 200; // time in melliseond OFF and wait before make another reading.

void setup() {
    Serial.begin(9600);
    pinMode(vibrarationInPin, INPUT);// define vibrarationInPin as input
    pinMode(relayPin, OUTPUT);// define relayPin as output  for relay         

    Serial.println("Robojax vibraration Sensor");

}

void loop() {

    // read the vibraration sensor
    if(digitalRead(vibrarationInPin) == HIGH){
      Serial.println("shaken! "); 
      digitalWrite(relayPin, HIGH); // Turn the relay ON    
      delay(onTime);// keep the relay or switch ON for the onTime 
    }else{
      digitalWrite(relayPin, LOW);// Turn the relay OFF
      Serial.println("peace");
      delay(offTime);// wait offTime  before reading again    
    }
}
