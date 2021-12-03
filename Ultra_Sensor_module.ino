const unsigned TRIG_PIN=12;
const unsigned ECHO_PIN=11;
int echo =0;
int unsigned t0;
int unsigned t1;
int distance =0;
int light = 13;



void setup() {
  // put your setup code here, to run once:
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode (light, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(11);
  digitalWrite(TRIG_PIN, LOW);

  echo = digitalRead(ECHO_PIN);
  while(echo == LOW) {

    echo = digitalRead(ECHO_PIN);
  }

  t0 = micros();

  while (echo == HIGH) {
    echo = digitalRead(ECHO_PIN);
    t1 = micros();
  }

  
  distance = (t1 - t0) / 58;
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  delay(2);

  if (distance < 10) {
  
  digitalWrite(light, HIGH);
}

else {
  digitalWrite(light, LOW);
}
}      
 
  
