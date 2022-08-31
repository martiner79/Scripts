/*
  Segun los datos obtenidos en el experimento anterior vamos a diseñar nuestro seguidor de luz
  aplicaremos un principio similar al del seguidor de linea
*/

//Variables de Salida

const int ledTest = 13;

//Variables Entradas para analogRead corespondiewntes a A0 y A1

const int ldrIzq = A0;
const int ldrDer = A1;

//Variables Motor

int AIA = 3; 
int AIB = 11;
int BIA = 9; 
int BIB = 10;

/*
  Datos resistividad guardados
*/
int refDer = 0;
int refIzq = 0;


void setup() {

  Serial.begin(9600);

  pinMode(ledTest, OUTPUT);
  pinMode(AIA, OUTPUT);
  pinMode(AIB, OUTPUT);
  pinMode(BIA, OUTPUT);
  pinMode(BIB, OUTPUT);

  
  digitalWrite(ledTest, LOW);
  analogWrite(AIA, 0);
  analogWrite(AIB, 0);
  analogWrite(BIA, 0);
  analogWrite(BIB, 0);

  saludoInicial(); //lo definimos al final del código

}


void loop() {

  refIzq =  analogRead(ldrIzq);
    
  /*Realizamos lo mismo con el otro ldr*/
  refDer =  analogRead(ldrDer);
  Serial.print( refDer );
  Serial.print( " ," );
  Serial.println( refIzq );
  
 
  if (refDer < 900 && refIzq < 900) { //(-II-)
    adelante(); //no hago delay, sigue derecho!
  }
  else if (refDer < 900 && refIzq > 900) { //(-XI-)
    izquierda();
    delay(20);
  }
  else { //(-IX-)
    derecha();
    delay(20);
  }
}

void saludoInicial() {
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

/**
   Funciones para controlar el motor
*/
/**
   colocamos en alto los IA y en bajo los IB de los dos motores
*/
void adelante()
{
  analogWrite(AIA, 255);
  analogWrite(AIB, 0);
  analogWrite(BIA, 255);
  analogWrite(BIB, 0);
}

/**
   colocamos en alto los IB y en bajo los IA de los dos motores
*/
void atras()
{
  analogWrite(AIA, 0);
  analogWrite(AIB, 255);
  analogWrite(BIA, 0);
  analogWrite(BIB, 255);
}

/**
   Combinamos adelante y atras
*/
void derecha()
{
  analogWrite(AIA, 255);
  analogWrite(AIB, 255);
  analogWrite(BIA, 255);
  analogWrite(BIB, 0);
}


/**
   Combinamos adelante y atras pero de forma diferente

*/
void izquierda()
{
  analogWrite(AIA, 255);
  analogWrite(AIB, 0);
  analogWrite(BIA, 255);
  analogWrite(BIB, 255);
}

/**
   Colocamos los dos valores en alto
*/
void parar()
{
  analogWrite(AIA, 255);
  analogWrite(AIB, 255);
  analogWrite(BIA, 255);
  analogWrite(BIB, 255);
}

