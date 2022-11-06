#include <Servo.h>

// Sonic
  // GLOBALS
  const byte trigPin1 = A1;      // trigger pin for sonic ranger #1
  const byte echoPin1 = A0;     // echo (data) pin for sonic ranger #1

  const byte LEDPin = 13;       // onboard LED pin (for diagnostics)

  Servo servo_1;

  void setup() {
  Serial.begin(9600);
  pinMode(trigPin1, OUTPUT);    // set the pinMode for trigger pin #1
  pinMode(echoPin1, INPUT);     // set the pinMode for echo pin #1
  pinMode(LEDPin, OUTPUT);      // set the pinMode for the onboard LED
  delay(100);       // allow the serial window time to open
  
    // Servo
  servo_1.attach(9, 500, 2500);
  }

void loop(){
  float x = sonicRange(trigPin1, echoPin1, 1000);
  Serial.println(x);
  
  servo_1.write(x*2);
}


float sonicRange(byte trigPin, byte echoPin, float maxRange) {
  // function, with arguments: (trigger pin, echo pin, maximum range (in cm))  
  float timeout;                      // # of microseconds sensor will search for object
  long timeRoundTrip;                 // total time (from echo pin) for sound to travel
  float distanceToObject;             // the calculated distance to the object (in cm)
  float const Vs_cmpus = 0.034524;    // speed of sound in centimeters per microseconds

  // calculate the sensor’s timeout value using the maxRange argument and Equation xxx
  timeout = 2.0 * maxRange / Vs_cmpus;

  // make sure the trigger pin starts in the LOW state:
  digitalWrite(trigPin, LOW);
  delayMicroseconds(1500);        // delay to prevent over-sampling (may be smaller)

  // tell SR04 to begin data collection by sending a 10us-pulse to trigger pin:
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);        // 10us is the minimum trigger pulse width
  digitalWrite(trigPin, LOW);

  // grab the pulse width from echo pin (i.e., sound’s total travel time from Tx to Rx):
  timeRoundTrip = pulseIn(echoPin, HIGH, timeout);

  // calculate distance to the object (in cm) using Equation xxx:
  distanceToObject = Vs_cmpus * (float)timeRoundTrip / 2.0;

  return distanceToObject;
}
