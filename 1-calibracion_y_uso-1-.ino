//Iniciaremos con las variables

int LedBlancoIzq = 8;
int ledBlancoDer = 7;
int LedTest = 13;

void setup(){

  pinMode(8, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(13, OUTPUT);

  digitalWrite(8, LOW);
  digitalWrite(7, LOW);
  digitalWrite(13, LOW);

  //Saludo inicial

  for(int i=0 ; i<3 ; i++){
    digitalWrite(13, HIGH);
    delay(500);
    digitalWrite(13,LOW);
    delay(500);
    
  }
}

void loop(){

  digitalWrite(8, HIGH);
  delay(500);
  digitalWrite(8, LOW);
  delay(500);
  digitalWrite(7, HIGH);
  delay(500);
  digitalWrite(7, LOW);
  delay(500);







  
}

