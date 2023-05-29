/*Define motor driver variable*/
#define enA 5 //enable enA L293 pin enA 
#define in1 6 //Motor1 L293 pin in1 
#define in2 7 //Motor1 L293 pin in2
#define in3 9 //Motor2 L293pin
#define in4 10//Motor2 L293pin in
#define enB 8//Enable2 L298 pin in1

/*Define IR sensor variable*/
#define IRsensor_Right 4
#define IRsensor_Left 2


//Define mopping DC motor
#define mopping 11

//set driver motor setup
void setup() {
  Serial.begin(9600);
  // Set up motor driver
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(enB, OUTPUT);
  digitalWrite(enA, HIGH);
  digitalWrite(enB, HIGH);
  //set up relay
  pinMode(mopping, OUTPUT);
  //set up sensor 
  pinMode(IRsensor_Right, INPUT);
  pinMode(IRsensor_Left, INPUT);
}


void loop() {
  //read sensor status
  int sensorstatus_Right= digitalRead(IRsensor_Right);
  int sensorstatus_Left= digitalRead(IRsensor_Left);
  // ngepel();
  
  Serial.println("pel jalan");
  //kondisi maju
  if (sensorstatus_Right==0 && sensorstatus_Left == 0){
    maju();
    digitalWrite(mopping, HIGH);    
  }
  //kondisi belok kanan
  else if (sensorstatus_Right==1 && sensorstatus_Left == 0){
    belok_kanan();    
    digitalWrite(mopping, HIGH);
  }
  //kondisi belok kiri
  else if (sensorstatus_Right==0 && sensorstatus_Left == 1){
    belok_kiri();    
    digitalWrite(mopping, HIGH);
  }
  //kondisi stop
  else if (sensorstatus_Right==1 && sensorstatus_Left == 1){
    stop();
    digitalWrite(mopping, LOW);
    Serial.println("pel stop");
    // delay(1000);
  }

}

//putar maju 
void maju(){
  digitalWrite(in1, HIGH); 
  digitalWrite(in2, LOW); 
  digitalWrite(in3, LOW); 
  digitalWrite(in4, HIGH);  
}

//belok kanan
void belok_kanan(){
  digitalWrite(in1, LOW);  //Right Motor forword Pin
  digitalWrite(in2, HIGH); //Right Motor backword Pin 
  digitalWrite(in3, LOW);  //Left Motor backword Pin
  digitalWrite(in4, HIGH); //Left Motor forword Pin
}

//belok kiri
void belok_kiri(){
  digitalWrite(in1, HIGH); //Right Motor forword Pin
  digitalWrite(in2, LOW);  //Right Motor backword Pin
  digitalWrite(in3, HIGH); //Left Motor backword Pin
  digitalWrite(in4, LOW);  //Left Motor forword Pin  
}

//stop
void stop(){
  digitalWrite(in1, LOW); //Right Motor forword Pin 
  digitalWrite(in2, LOW); //Right Motor backword Pin
  digitalWrite(in3, LOW); //Left Motor backword Pin 
  digitalWrite(in4, LOW); //Left Motor forward Pin
}
