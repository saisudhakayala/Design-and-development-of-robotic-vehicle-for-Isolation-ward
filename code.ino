#include <DHT.h>
#include <DHT_U.h>
#include <servo.h>
#include<SoftwareSerial.h>
servo myservo;
SoftwareSerial Serial1(2,3); //make RX arduino line is pin 2, make TX arduino line is pin 3.
SoftwareSerial Serial2(7,8); //bluetooth. make RX arduino line is pin 2, make TXarduino line is pin 3.
//#include <DHT.h>
int pos = 0;
#define DHTPIN 4 // what pin we're connected to
#define DHTTYPE DHT11 // DHT 11 (AM2302)
DHTdht(DHTPIN, DHTTYPE);
int sen = 5;
int v1 = 6;
int rm1 = 9;
int rm2 = 10;
int lm1 = 11;
int lm2 = 12;
int ob;
char t;
int chk;
float hum; //Stores humidity value
float temp; //Stores temperature value
void setup ()
{
Serial1.begin(9600);
Serial2.begin(9600);
myservo.attach(13);
Serial.begin(9600);
pinMode(v1, OUTPUT);
pinMode(rm1, OUTPUT); //left motors forward
pinMode(rm2, OUTPUT); //left motors reverse
pinMode(lm1, OUTPUT); //right motors forward
pinMode(lm2, OUTPUT); //right motors reverse
pinMode(sen, INPUT);
dht.begin();
Serial.println("ICU Monitoring");
}
void loop ()
{
digitalWrite(v1, LOW);
hum =dht.readHumidity();
temp= dht.readTemperature();
Serial.print("Humidity: ");
Serial.print(hum);
Serial.print(" %, Temp: ");
Serial.print(temp);
Serial.println(" Celsius");
ob = analogRead(A0);
Serial.print("Smoke: ");
Serial.print(ob);
Delay (2000); //Delay 2 sec.
If(Serial2.available()){
t = Serial2.read();
Serial.println(t);
}
}
if(t == '1'){
//move forward(all motors rotate in forward direction)
digitalWrite(rm1, HIGH);
digitalWrite(rm2,LOW);
digitalWrite(lm1,HIGH);
digitalWrite(lm2,LOW);
else if(t == '2'){ //move reverse (all motors rotate in reverse direction)
digitalWrite(rm1,LOW);
digitalWrite(rm2,HIGH);
digitalWrite(lm1,LOW);
digitalWrite(lm2,HIGH);
}
else if(t == '3'){
doesn't rotate)
//turn right (left side motors rotate in forward direction, right side
digitalWrite(rm1,LOW);
digitalWrite(rm2,HIGH);
digitalWrite(lm1,HIGH);
digitalWrite(lm2,LOW);
}
else if(t == '4'){ //turn left (right side motors rotate in forward direction, left side
motors doesn't rotate)
digitalWrite(rm1,HIGH);
digitalWrite(rm2,LOW);
digitalWrite(lm1,LOW);
digitalWrite(lm2,HIGH);
}
else if(t == '5')
{
//STOP (all motors stop)
digitalWrite(rm1,LOW);
digitalWrite(rm2,LOW);
digitalWrite(lm1,LOW);
digitalWrite(lm2,LOW);
}
else if(t == '6')
{
myservo.write(180);
}
else if(t == '7')
{
myservo.write(-180);
}
delay(100);
if (ob>500) // pls change smoke value here
//if (ob == LOW)
{
Serial.println("fire occuring");
Serial.println("Sending SMS");
Serial1.println("AT");
delay(500);
Serial1.println("AT+CMGF=1");
delay(500);
Serial1.print("AT+CMGS=");
Serial1.print('"');
Serial1.print("8179134842"); //mobile no. for SMS alert
Serial1.println('"');
delay(500);
Serial1.print("Fire Occuring");
delay(500);
Serial1.write(26);
delay(500);
Serial.println("SMS Sent");
digitalWrite(v1, HIGH);
delay(500);
Serial.println("fire occuring");
Serial.println("Sending SMS");
Serial1.println("AT");
delay(500);
Serial1.println("AT+CMGF=1");
delay(500);
Serial1.print("AT+CMGS=");
Serial1.print('"');
Serial1.print("9381682379"); //mobile no. for SMS alert
Serial1.println('"');
delay(500);
Serial1.print("Fire Occuring");
delay(500);
Serial1.write(26);
delay(500);
Serial.println("SMS Sent");
digitalWrite(v1, HIGH);
delay(500);
}
if (hum>75) // pls change humidity threshold here
{
Serial.println("High humidity");
Serial.println("Sending SMS");
Serial1.println("AT");
delay(500);
Serial1.println("AT+CMGF=1");
delay(500);
Serial1.print("AT+CMGS=");
Serial1.print('"');
Serial1.print("8179134842"); //mobile no. for SMS alert
Serial1.println('"');
delay(500);
Serial1.print("very high Humidity is observed");
delay(500);
Serial1.write(26);
delay(500);
Serial.println("SMS Sent");
digitalWrite(v1, HIGH);
delay(500);
Serial.println("High humidity");
Serial.println("Sending SMS");
Serial1.println("AT");
delay(500);
Serial1.println("AT+CMGF=1");
delay(500);
Serial1.print("AT+CMGS=");
Serial1.print('"');
Serial1.print("9381682379"); //mobile no. for SMS alert
Serial1.println('"');
delay(500);
Serial1.print("very high Humidity is observed");
delay(500);
Serial1.write(26);
delay(500);
Serial.println("SMS Sent")
digitalWrite(v1, HIGH);
delay(500);
}
if (temp>30) // pls change temperature threshold here
{
Serial.println("High temperature");
Serial.println("Sending SMS");
Serial1.println("AT");
delay(500);
Serial1.println("AT+CMGF=1");
delay(500);
Serial1.print("AT+CMGS=");
Serial1.print('"');
Serial1.print("8179134842"); //mobile no. for SMS alert
Serial1.println('"');
delay(500);
Serial1.print("very high temperature is observed");
delay(500);
Serial1.write(26);
delay(500);
Serial.println("SMS Sent");
digitalWrite(v1, HIGH);
delay(500);
Serial.println("High temperature");
Serial.println("Sending SMS");
Serial1.println("AT");
delay(500);
Serial1.println("AT+CMGF=1");
delay(500);
Serial1.print("AT+CMGS=");
Serial1.print('"');
Serial1.print("9381682379"); //mobile no. for SMS alert
Serial1.println('"');
delay(500);
Serial1.print("very high temperature is observed");
delay(500);
Serial1.write(26);
delay(500);
Serial.println("SMS Sent");
digitalWrite(v1, HIGH);
delay(500);
}
}
