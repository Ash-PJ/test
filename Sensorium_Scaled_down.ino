#define echoPin1 A0
#define trigPin1 A1
#define trigPin2 A3
#define echoPin2 A2
#define trigPin3 A5
#define echoPin3 A4
int motor1 = 7;
int motor2 = 6;
int motor3 = 5;
long duration, distance, FIRSTSensor,SECONDSensor,THIRDSensor;
void setup()
{

Serial.begin (9600);

pinMode(trigPin1, OUTPUT);
pinMode(echoPin1, INPUT);
pinMode(trigPin2, OUTPUT);
pinMode(echoPin2, INPUT);
pinMode(trigPin3, OUTPUT);
pinMode(echoPin3, INPUT);
pinMode(motor1, OUTPUT);
pinMode(motor2, OUTPUT);
pinMode(motor3, OUTPUT);  
digitalWrite(motor1, LOW);
digitalWrite(motor2, LOW);
digitalWrite(motor3, LOW);

}

void loop() 
{
  

 
SonarSensor(trigPin1, echoPin1);
FIRSTSensor = distance;
Vibration(FIRSTSensor,motor1);
SonarSensor(trigPin2, echoPin2);
SECONDSensor = distance;
Vibration(SECONDSensor,motor2);
SonarSensor(trigPin3, echoPin3);
THIRDSensor = distance;
Vibration(THIRDSensor,motor3);
  
digitalWrite(motor1, LOW);
digitalWrite(motor2, LOW);
digitalWrite(motor3, LOW);


Serial.print("S1:");Serial.println(FIRSTSensor); delayMicroseconds(10);
Serial.print("S2:");Serial.println(SECONDSensor);delayMicroseconds(10);
Serial.print("S3:");Serial.println(THIRDSensor); delayMicroseconds(10);


}

void SonarSensor(int trigPin,int echoPin)
{
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distance = (duration*0.034)/2;
}

void Vibration(int sensor,int motor)  
{
   if(sensor <= 100)
   {
    digitalWrite(motor,HIGH);
    delay(1000);
    digitalWrite(motor,LOW); 
    delay(100);
   }
  else if(sensor >=100 && sensor < 300)
   {
    digitalWrite(motor,HIGH);
    delay(500);
    digitalWrite(motor,LOW); 
    delay(100);
   }
  else if(sensor >= 300)
   {
    digitalWrite(motor,HIGH);
    delay(250);
    digitalWrite(motor,LOW); 
    delay(100);
   }
 }
  
