//Iniciaremos con las variables

int LedBlancoIzq = 8;
int ledBlancoDer = 7;

int LedTest = 13;

int emisor = 4;
int receptor = 2;

long TiempoEms;
float DistMed;


void setup(){

  pinMode(8, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(2, INPUT);

  digitalWrite(8, LOW);
  digitalWrite(7, LOW);
  digitalWrite(13, LOW);
  digitalWrite(4, LOW);

  //Saludo inicial

  for(int i=0 ; i<3 ; i++){
    digitalWrite(13, HIGH);
    delay(500);
    digitalWrite(13,LOW);
    delay(500);
    
  }
}

void loop(){

  Serial.begin(9600);

digitalWrite(4, HIGH);
delayMicroseconds(10);
digitalWrite(4, LOW);

TiempoEms = pulseIn(receptor, HIGH);
DistMed = 0.030 / TiempoEms*2;        //La fórmula representa a la distancia (cuyo tiempo se multiplica por dos, porque se tiene en cuenta la ida y vuelta)

if(TiempoEms<600){
  digitalWrite(8, HIGH);
  digitalWrite(7, LOW);
}
else if(TiempoEms>=600 && TiempoEms<950){
  digitalWrite(8, LOW);
  digitalWrite(7, HIGH);
  }
else if(TiempoEms>=950&& TiempoEms<1700){
  digitalWrite(8, HIGH);
  digitalWrite(7, HIGH);
  delay(500);
  digitalWrite(8, LOW);
  digitalWrite(7, LOW);
  delay(500);
}

else if(TiempoEms>=1700 && TiempoEms<5700){
  digitalWrite(8, HIGH);
  digitalWrite(7, HIGH);
  
}


constrain (






  
}

