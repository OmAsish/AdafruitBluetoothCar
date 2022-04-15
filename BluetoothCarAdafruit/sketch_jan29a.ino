#include <AFMotor.h>
#include <IRremote.h>

AF_DCMotor motor1(1, MOTOR12_1KHZ); 
AF_DCMotor motor2(2, MOTOR12_1KHZ); 
AF_DCMotor motor3(3, MOTOR34_1KHZ);
AF_DCMotor motor4(4, MOTOR34_1KHZ);


IRrecv IR(A0);
decode_results result;

int Speed = 200;

#define up 16740495
#define down 16734375
#define left 16732335
#define right 16742535
#define Stop 16752735

void setup() {
  Serial.begin(9600);
  motor1.setSpeed(Speed);
  motor2.setSpeed(Speed);
  motor3.setSpeed(Speed);  
  motor4.setSpeed(Speed);
  IR.enableIRIn();
}

void loop() {
  if (IR.decode(&result)) {
    Serial.println(result.value);
    IR.resume();
  }
  delay(100);
  if (result.value == up ) {
    motor1.run(FORWARD);
    motor2.run(FORWARD);
    motor3.run(FORWARD);
    motor4.run(FORWARD);
  } else if (result.value == down ) {
    motor1.run(BACKWARD);
    motor2.run(BACKWARD);
    motor3.run(BACKWARD);
    motor4.run(BACKWARD);
  } else if (result.value == Stop) {
    motor1.run(RELEASE);
    motor2.run(RELEASE);
    motor3.run(RELEASE);
    motor4.run(RELEASE);
  } else if (result.value == left) {
    motor1.run(BACKWARD);
    motor2.run(BACKWARD);
    motor3.run(FORWARD);
    motor4.run(FORWARD);
  } else if (result.value == right) {
    motor1.run(FORWARD);
    motor2.run(FORWARD);
    motor3.run(BACKWARD);
    motor4.run(BACKWARD);
  }
}
