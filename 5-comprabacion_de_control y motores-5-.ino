//Definimos variables

const int AIA = 3; 
const int AIB = 11;
const int BIA = 9; 
const int BIB = 10;

const int ledTest = 13;


void setup() {
  //Definición de salidas
  
  pinMode(AIA, OUTPUT); 
  pinMode(AIB, OUTPUT);
  pinMode(BIA, OUTPUT);
  pinMode(BIB, OUTPUT);
  pinMode(ledTest, OUTPUT);

  analogWrite(AIA, 0);
  analogWrite(AIB, 0);
  analogWrite(BIA, 0);
  analogWrite(BIB, 0);
  digitalWrite(ledTest, LOW);

  //Saludo Inicial
  digitalWrite(ledTest, HIGH);
  delay(500);
  digitalWrite(ledTest, LOW);
  delay(500);
  digitalWrite(ledTest, HIGH);
  delay(500);
  digitalWrite(ledTest, LOW);
  delay(500);
  digitalWrite(ledTest, HIGH);
  delay(500);
  digitalWrite(ledTest, LOW);
  delay(500);
}

void loop() {
  parpadeo(1);
  adelante();
  delay(1500);
  parar();

  parpadeo(2);
  atras();
  delay(1500);
  parar();

  parpadeo(3);
  derecha();
  delay(1000);
  parar();

  parpadeo(4);
  izquierda();
  delay(1000);
  parar();

}

//colocamos en alto los IA y en bajo los IB de los dos motores

void adelante()
{
  analogWrite(AIA, 255);
  analogWrite(AIB, 0);
  analogWrite(BIA, 255);
  analogWrite(BIB, 0);
}

 //colocamos en alto los IB y en bajo los IA de los dos motores
 
void atras()
{
  analogWrite(AIA, 0);
  analogWrite(AIB, 255);
  analogWrite(BIA, 0);
  analogWrite(BIB, 255);
}

//Combinamos adelante y atras

void derecha()
{
  analogWrite(AIA, 255);
  analogWrite(AIB, 0);
  analogWrite(BIA, 0);
  analogWrite(BIB, 255);
}


//Combinamos adelante y atras pero de forma diferente

void izquierda()
{
  analogWrite(AIA, 0);
  analogWrite(AIB, 255);
  analogWrite(BIA, 255);
  analogWrite(BIB, 0);
}


//Colocamos los dos valores en alto

void parar()
{
  analogWrite(AIA, 255);
  analogWrite(AIB, 255);
  analogWrite(BIA, 255);
  analogWrite(BIB, 255);
  delay(500);
}

void parpadeo(int veces) {
  for (int j = 0; j < veces; j++) {
    digitalWrite(ledTest, HIGH);
    delay(200);
    digitalWrite(ledTest, LOW);
    delay(200);
  }
}

