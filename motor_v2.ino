#include <Wire.h>
#include <Adafruit_MotorShield.h>

Adafruit_MotorShield AFMS = Adafruit_MotorShield();

Adafruit_DCMotor *myMotor1 = AFMS.getMotor(3);
Adafruit_DCMotor *myMotor2 = AFMS.getMotor(4);
Adafruit_DCMotor *myMotor3 = AFMS.getMotor(2);
Adafruit_DCMotor *myMotor4 = AFMS.getMotor(1);

int r = 0;

const int motorSwitch = 2;

const int RLED = A0;
const int GLED = A1;
const int BLED = A2;

uint8_t i=0;

boolean forward_boolean = false;
boolean backward_boolean = false;
boolean turn_right_boolean = false;
boolean turn_left_boolean = false;
boolean move_right_boolean = false;
boolean move_left_boolean = false;

void moveForward()
{
  myMotor1->run(BACKWARD); //This is actually forward
  myMotor2->run(FORWARD);
  myMotor3->run(BACKWARD);
  myMotor4->run(FORWARD);
  for (i=0; i<101; i++) {
    myMotor1->setSpeed(i);
    myMotor2->setSpeed(i);  
    myMotor3->setSpeed(i);
    myMotor4->setSpeed(i);
    delay(10);
  }
}

void moveBackward()
{
  myMotor1->run(FORWARD); //This is actually backward
  myMotor2->run(BACKWARD);
  myMotor3->run(FORWARD);
  myMotor4->run(BACKWARD);
  for (i=0; i<101; i++) {
    myMotor1->setSpeed(i);
    myMotor2->setSpeed(i);
    myMotor3->setSpeed(i);
    myMotor4->setSpeed(i);  
    delay(10);
  }
}

void moveRight()
{
  myMotor1->run(FORWARD); //This is actually forward
  myMotor2->run(FORWARD);
  myMotor3->run(BACKWARD);
  myMotor4->run(BACKWARD);
  for (i=0; i<101; i++) {
    myMotor1->setSpeed(i);
    myMotor2->setSpeed(i);  
    myMotor3->setSpeed(i);
    myMotor4->setSpeed(i);
    delay(10);
  }
}

void moveLeft()
{
  myMotor1->run(BACKWARD); //This is actually forward
  myMotor2->run(BACKWARD);
  myMotor3->run(FORWARD);
  myMotor4->run(FORWARD);
  for (i=0; i<101; i++) {
    myMotor1->setSpeed(i);
    myMotor2->setSpeed(i);  
    myMotor3->setSpeed(i);
    myMotor4->setSpeed(i);
    delay(10);
  }
}

void turnRight()
{
  myMotor1->run(FORWARD);
  myMotor2->run(FORWARD);
  myMotor3->run(FORWARD);
  myMotor4->run(FORWARD);
  myMotor1->setSpeed(50);
  myMotor2->setSpeed(50);
  myMotor3->setSpeed(50);
  myMotor4->setSpeed(50);
}

void turnLeft()
{
  myMotor1->run(BACKWARD);
  myMotor2->run(BACKWARD);
  myMotor3->run(BACKWARD);
  myMotor4->run(BACKWARD);
  myMotor1->setSpeed(50);
  myMotor2->setSpeed(50);
  myMotor3->setSpeed(50);
  myMotor4->setSpeed(50);  
}

/*void motorStop()
{
  for (i=150; i!=0; i--) {
    myMotor1->setSpeed(i);  
    myMotor2->setSpeed(i);
    delay(10);
  }
}*/

void motorRelease()
{
  myMotor1->run(RELEASE);
  myMotor2->run(RELEASE);
  myMotor3->run(RELEASE);
  myMotor4->run(RELEASE);
}

void setup() {
  // put your setup code here, to run once:
  AFMS.begin();

  Serial.begin(9600);
  delay(10);

  pinMode(motorSwitch, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
if(Serial.available())
{
  r = Serial.read() - '0';

  if(r == 5)
  {
    digitalWrite(motorSwitch, HIGH);
  }

  if(r == 6)
  {
    digitalWrite(motorSwitch, LOW);
  }
  
  if(r == 1)
  {
    moveForward();
    forward_boolean = true;

    while(true)
    {
      myMotor1->setSpeed(100);
      myMotor2->setSpeed(100);
      myMotor3->setSpeed(100);
      myMotor4->setSpeed(100);

      r = Serial.read() - '0';
      
      if(r == 0)
      {
        motorRelease();
        break;
      }
    }
  }

  else if(r == 2)
  {
    moveBackward();
    backward_boolean = true;

    while(true)
    {
      myMotor1->setSpeed(100);
      myMotor2->setSpeed(100);

      r = Serial.read() - '0';
      
      if(r == 0)
      {
        motorRelease();
        break;
      }
    }
  }

  else if(r == 7)
  {
    moveRight();
    move_right_boolean = true;

    while(true)
    {
      myMotor1->setSpeed(100);
      myMotor2->setSpeed(100);
      myMotor3->setSpeed(100);
      myMotor4->setSpeed(100);

      r = Serial.read() - '0';
      
      if(r == 0)
      {
        motorRelease();
        break;
      }
    }
  }

  else if(r == 8)
  {
    moveLeft();
    move_left_boolean = true;

    while(true)
    {
      myMotor1->setSpeed(100);
      myMotor2->setSpeed(100);
      myMotor3->setSpeed(100);
      myMotor4->setSpeed(100);

      r = Serial.read() - '0';
      
      if(r == 0)
      {
        motorRelease();
        break;
      }
    }
  }

  else if(r == 3)
  {
    turnRight();
    turn_right_boolean = true;
  }

  else if(r == 4)
  {
    turnLeft();
    turn_left_boolean = true;
  }

  /*else if((forwardIndicator == LOW && forward_boolean == true) || (backwardIndicator == LOW && backward_boolean == true) || (rightIndicator == LOW && right_boolean == true) || (leftIndicator == LOW && left_boolean == true))
  {
    motorStop();
    forward_boolean = false;
    backward_boolean = false;
    right_boolean = false;
    left_boolean = false;
  }*/

  else{
    motorRelease();
    forward_boolean = false;
    backward_boolean = false;
    turn_right_boolean = false;
    turn_left_boolean = false;
    move_right_boolean = false;
    move_left_boolean = false;
  }
}
}
