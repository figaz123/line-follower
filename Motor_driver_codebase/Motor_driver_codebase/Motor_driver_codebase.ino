#define enA 5 //enable enA L293 pin enA 
#define in1 6 //Motor1 L293 pin in1 
#define in2 7 //Motor1 L293 pin in2
#define in3 9 //Motor2 L293pin
#define in4 10//Motor2 L293pin in
#define enB 8//Enable2 L298 pin in1


void setup() {
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(enB, OUTPUT);
  digitalWrite(enA, HIGH);
  digitalWrite(enB, HIGH);
  // put your setup code here, to run once:

}

void loop() {
  maju();
  mundur();
  belok_kanan();
  belok_kiri();
  stop();
  // put your main code here, to run repeatedly:

}

//putar maju 
void maju(){
  digitalWrite(in1, HIGH); 
  digitalWrite(in2, LOW); 
  digitalWrite(in3, LOW); 
  digitalWrite(in4, HIGH);  
}

//putar mundur
void mundur(){
  digitalWrite(in1, LOW); 
  digitalWrite(in2, HIGH); 
  digitalWrite(in3, HIGH); 
  digitalWrite(in4, LOW); 
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


