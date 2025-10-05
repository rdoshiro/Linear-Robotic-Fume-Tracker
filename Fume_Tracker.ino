#include <PID_v1.h>
double input;
double output;
double volatile setpoint = 3;
double Kp = 120, Ki = 0, Kd = 1;

int speedMotor = 5;
int pin1 = 4;
int pin2 = 3;

int TRIG = 12;
int ECHO = 13;
float Time;
float Distance;
float speedOfSound = 340; //Speed of sounds in m/s

PID myPID(&input, &output , &setpoint, Kp, Ki, Kd, DIRECT);

void setup() {
    Serial.begin(9600);  

    //SETTING UP PID
    myPID.SetMode(AUTOMATIC);
    myPID.SetSampleTime(60);
    myPID.SetOutputLimits(-255, 255); 
    
    pinMode(speedMotor, OUTPUT);
    pinMode(pin1, OUTPUT);
    pinMode(pin2, OUTPUT);


  pinMode(TRIG, OUTPUT);  
  pinMode(ECHO, INPUT_PULLUP);  

}
void loop() {
     
  digitalWrite(TRIG, LOW); 
  delayMicroseconds(2000); 
  digitalWrite(TRIG, HIGH); 
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);
  delayMicroseconds(10);

  Time= pulseIn(ECHO, HIGH); //measures time signal takes to return 
  Time = Time/1000000.0; //convertint in seconds
  Distance = speedOfSound*Time; //speed time
  Distance = Distance/2; //One way distance
  Distance = Distance*100; //Distance in cm
  Serial.println(Distance);

    //PID INPUT
    input = Distance;
    myPID.Compute();
    Serial.print(input);
    Serial.print(" ");
    Serial.print(output);
    Serial.print(" ");
    Serial.println(setpoint);

    //MOTOR DIRECTION 
    if (output < 0){
    digitalWrite(pin1,HIGH); //FORWARD
    digitalWrite(pin2,LOW);
    analogWrite(speedMotor,abs(output));  //VARYING SPEED
    delay(20);  
    }
    else if (output > 0){
    digitalWrite(pin1,LOW);  //BACKWARD
    digitalWrite(pin2,HIGH);
    analogWrite(speedMotor,abs(output)); //VARYING SPEED
    delay(20);  
    }
}
