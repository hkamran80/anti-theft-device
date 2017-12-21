// Ultrasonic Sensor (HC-SR04)

/* Components:
1 Arduino (Uno R3)
1 4-Pin Ultrasonic Sensor (HC-SR04)
3 LEDs (Red, Yellow, Green)
*/

/* Details:
Ultrasonic --> Arduino
VCC --> 5V
GND --> GND
ECHO --> (Digital Pin) 12
TRIG --> (Digital Pin) 13 (You can change the wiring/code to reflect changes with ECHO/TRIG)
*/

#define trigPin 12
#define echoPin 13

#define highThreat 10
#define medThreat 9
#define noThreat 8

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT); // Microphone
  pinMode(echoPin, INPUT); // Speaker
  highThreat
  pinMode(highThreat, OUTPUT); // Red LED
  pinMode(medThreat, OUTPUT); // Yellow LED
  pinMode(noThreat, OUTPUT); // Green LED
}

void loop() {
  long duration, distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
  
  if (distance >= 400 || distance <= 2) {
    Serial.println("OUT OF RANGE");
  } else {
    Serial.print(distance);
    Serial.println(" cm");
  }
  
  if (distance <= 60) {
    // 60cm = 2ft
    digitalWrite(medThreat, LOW);
    digitalWrite(noThreat, LOW);
    
    digitalWrite(highThreat, HIGH);
  } else if ((distance > 0) && (distance <= 152)) {
    // 152cm = 5ft
    digitalWrite(highThreat, LOW);
    digitalWrite(noThreat, LOW);
    
    digitalWrite(medThreat, HIGH);
    delay(1000);
    digitalWrite(medThreat, LOW);
  } else if (distance > 152) {
    // 152cm = 5ft
    digitalWrite(highThreat, LOW);
    digitalWrite(medThreat, LOW);
    
    digitalWrite(noThreat, HIGH);
    delay(1000);
    digitalWrite(noThreat, LOW);
  } 
    
  delay(500);
}
