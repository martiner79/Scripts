//definir variables

int ledBlancoIzquierda = 4;
int ledRojoIzquierda = 8;

void setup() {
  
 pinMode(ledBlancoIzquierda, OUTPUT);
 pinMode(ledRojoIzquierda, OUTPUT);
 digitalWrite(ledBlancoIzquierda, LOW);
 digitalWrite(ledRojoIzquierda, LOW);
 }
 
void loop() {
  
 digitalWrite(ledBlancoIzquierda, HIGH);
 digitalWrite(ledRojoIzquierda, HIGH);
 delay(1000);
 parpadeo(ledRojoIzquierda, 5, 250);
 parpadeo(ledBlancoIzquierda, 10, 250);
 digitalWrite(ledBlancoIzquierda, LOW);
 digitalWrite(ledRojoIzquierda, LOW);
 delay(1000);
}

void parpadeo(int ledParpadea, int veces, int tiempo) {
 for (int j=0; j <= veces ; j++) {
 digitalWrite(ledParpadea, LOW);
 delay(tiempo);
 digitalWrite(ledParpadea, HIGH);
 delay(tiempo);
  }
    
}   
  
  
