int soundInPin = 2;// connect output to Sound module DO
int relayPin = 8;// Connected to relay or buzzer (or LED)
int extra5V = 12;// define a pin for extra extra 5V

// do not change values bellow
int val = 0; // sound value from pin 2
int relayON = 0;//light status
int heard = 0;//sound heard status


void setup() {
  Serial.begin(9600);
  pinMode(soundInPin, INPUT_PULLUP); 
  pinMode(relayPin, OUTPUT);
  pinMode(extra5V,OUTPUT);// set extra5V as output
  digitalWrite(extra5V,HIGH);// turn the extra5V pin HIGH to get 5V

}

void loop() {
  val = digitalRead(soundInPin);// read the sound pin

  if(val == HIGH && relayON == LOW){

    heard = 1-heard;// toggle the value of "heard" from HIGH to LOW or from LOW to HIGH
    delay(100);
  }    
  relayON = val;// save the value of pin 2

      if(heard == HIGH){
        Serial.println("Light ON");
        digitalWrite(relayPin, LOW); // turn relay ON
       
      }else{
        Serial.println("Light OFF");
        digitalWrite(relayPin, HIGH);// turn relay OFF
   
      }     
  delay(100);
}
