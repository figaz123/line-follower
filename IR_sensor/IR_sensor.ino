//set variable
int IRsensor_1 = 9;
int IRsensor_2 = 8;
int LED1=13;
int LED2=10;

//setup sensor as input and LED as output
void setup(){
  Serial.begin(115200);
  Serial.println("Start");
  pinMode(IRsensor_1, INPUT);
  pinMode(IRsensor_2, INPUT);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
}

//begin 
void loop(){
  //sensor IR READ 
  int sensorstatus1= digitalRead(IRsensor_1);
  int sensorstatus2= digitalRead(IRsensor_2);
  if(sensorstatus1 == 1){
    digitalWrite(LED1, LOW);
    Serial.println("Sensor 1 worked");
  }else if (sensorstatus1 == 1 && sensorstatus2 == 1) {
   digitalWrite(LED1, LOW);
   digitalWrite(LED2, LOW);
   Serial.println("Sensor 1 & 2 worked");

  }else if (sensorstatus2 == 1) {
   digitalWrite(LED2, LOW);
   Serial.println("Sensor 2 worked");
  }else {
  Serial.println("Sensors are not working");
  }
}