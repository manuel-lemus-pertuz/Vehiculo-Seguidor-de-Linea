int sensor1=13;
int sensor2=12;
int lectura1=0;
int lectura2=0;
int motord=11;
int motord1=8;
int motord2=7;
int motori=10;
int motori1=6;
int motori2=5;
int Echo = 4;
int Trig = 2;

void setup() {
  Serial.begin(9600);
  pinMode(sensor1,INPUT);
  pinMode(sensor2,INPUT);
  pinMode(motord,OUTPUT);
  pinMode(motord1,OUTPUT);
  pinMode(motord2,OUTPUT);
  pinMode(motori,OUTPUT);
  pinMode(motori1,OUTPUT);
  pinMode(motori2,OUTPUT);
  pinMode(Trig,OUTPUT);
  pinMode(Echo,INPUT);
}

void loop() {
  long duracion;
  long distancia;
  digitalWrite(Trig,LOW);
  delayMicroseconds(4);
  digitalWrite(Trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(Trig,LOW);

  duracion = pulseIn(Echo,HIGH);
  duracion = duracion/2;
  distancia = duracion/29;

  if (distancia>50&&digitalRead(sensor1)==1&&digitalRead(sensor2)==1){
    busqueda();
  }
  else{
    if(digitalRead(sensor1)==1&&digitalRead(sensor2)==1){
      adelante();
    }
    else{
      detenerse();
    }
  }
}
void adelante(){
    analogWrite(motord,255);
    analogWrite(motori,255);
    digitalWrite(motord1, HIGH); 
    digitalWrite(motord2, LOW);
    analogWrite(motori2,255);
    analogWrite(motori1,0);
}
void busqueda(){
    analogWrite(motord,120);
    analogWrite(motori,0);
    digitalWrite(motord1, HIGH);
    digitalWrite(motord2, LOW);
}
void detenerse(){
    analogWrite(motord,0);
    analogWrite(motori,0);
}
