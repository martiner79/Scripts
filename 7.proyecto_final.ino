/*
  Realizamos un programa para leer los datos recibidos a traves de un control remoto 
  y los vamos a colocar en una tabla para su posterior uso.
  En este proyecto no usamos los sensores, ni las fotorresistenci!
*/


#include <IRremote.h>
#include <IRremoteInt.h>


/*INICIO VARIABLES

  Para deteccion de errores usaremos el led integrado del pin 13.
 
*/

int ledTest = 13;

const int AIA = 3; 
const int AIB = 11;
const int BIA = 9; 
const int BIB = 10;

int ledBlancoIzquierda = 7;
int ledBlancoDerecha = 8;
int ledRojo = 4;



/*
   Seteo del receptor infrarojo
*/
int ReceptorIR = 2;                     // Declaramos que usaremos el pin 2 (asociado a la variable ReceptorIR) como entrada del control remoto. 
IRrecv receptorIr(ReceptorIR);          // Creamos un objeto de la clase IRrecv llamado "receptorIr"

decode_results codigoLeido;              //declaramos 2 variables de tipo decode_results llamadas "codigoLeido" y "codigoLeidoNuevo"
decode_results codigoLeidoNuevo;

/*
   Seteo del led RGB pines y variables
   Los valores de potencia serán 0 = apagado, 127 que es un 50% y 255 que sria un 100%
*/


/*FIN VARIABLES*/

void setup() {
  /*
     Seteo receptor infrarojo
  */
  Serial.begin(9600);
  receptorIr.enableIRIn();     // Habilitamos al receptor para que comience a intentar detectar señales infrarrojas.

  

  pinMode(AIA, OUTPUT); 
  pinMode(AIB, OUTPUT);
  pinMode(BIA, OUTPUT);
  pinMode(BIB, OUTPUT);
  
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(4, OUTPUT);
  

  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
  digitalWrite(4, LOW);
  

  analogWrite(AIA, 0);
  analogWrite(AIB, 0);
  analogWrite(BIA, 0);
  analogWrite(BIB, 0);

  
  pinMode(ledTest, OUTPUT);
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

  

  if (receptorIr.decode(&codigoLeidoNuevo))   //Si recibimos algun dato, lo guardamos en codigoLeidoNuevo.
  {
    receptorIr.resume();   // le indica al receptor que ya guardamos el nuevo codigo leÃ­do y ya puede esperar al siguiente
  }


  /*
     Vamos a realizar una acción si el valor leido ha cambiado y si el pulsador no se mantiene pulsado (0xFFFFFFFF)
  */
  
  if (codigoLeidoNuevo.value != codigoLeido.value && codigoLeidoNuevo.value != 0xFFFFFFFF)
  {
    digitalWrite(ledTest, HIGH);      // hacemos parpadear nuestro ledTest para que sepamos que recibimos un codigo desde el control
    delay(50);
    digitalWrite(ledTest, LOW);
    
    
    
   Serial.println(codigoLeido.value, HEX);  // mostramos el valor por el monitor serie. 
   
    
    
   codigoLeido = codigoLeidoNuevo;          //Guardamos el nuevo valor leido, para poder compararlo mas tarde con el siguiente que recibamos
    
    
    switch (codigoLeido.value) {        // switch compara el valor de una variable con los valores escritos en cada
                                        // instruccion case. Cuando encuentra un "caso" (Case) cuyo valor coincide con    
      case 0xFF18E7: //arriba         // el de la variable, ejecuta el codigo especificado                
        adelante();
        break;                          //La palabra reservada break interrumpe la sentencia switch, y se usa al final de cada declaración case. Sin una
                                        // declaración de interrupción, la sentencia switch continuarÃ¡ la ejecución de las siguientes
      case 0xFF4AB5: //abajo         // expresiones hasta que se alcanza una interrupción o hasta el final de la sentencia switch                    
        atras();      
        break;
        
      case 0xFF5AA5: //derecha      
        derecha();
        break;
        
      case 0xFF10EF: //izquierda
        izquierda();
        break;

      case 0xFFB04F: //parar //(#)
        parar();
        break;
        
      case 0xFF38C7: //ok //prender leds      
        digitalWrite(ledBlancoIzquierda, HIGH);
        digitalWrite(ledBlancoDerecha, HIGH);
        digitalWrite(ledRojo, HIGH);
        break;

        case 0xFF6897: //* //apagarLeds     
        digitalWrite(ledBlancoIzquierda, LOW);
        digitalWrite(ledBlancoDerecha, LOW);
        digitalWrite(ledRojo, LOW);
        break;
     
        // Si el codigo recibido no es ninguno de los que buscamos hacemos parpadear el led de prueba 
      
      default:
        digitalWrite(ledTest, HIGH);
        delay(200);
        digitalWrite(ledTest, LOW);
        delay(200);
        digitalWrite(ledTest, HIGH);
        delay(200);
        digitalWrite(ledTest, LOW);
        break;
    }
    
  }




}

void derecha()
{
  analogWrite(AIA, 255);
  analogWrite(AIB, 0);
  analogWrite(BIA, 255);
  analogWrite(BIB, 0);
}

 //colocamos en alto los IB y en bajo los IA de los dos motores
 
void izquierda()
{
  analogWrite(AIA, 0);
  analogWrite(AIB, 255);
  analogWrite(BIA, 0);
  analogWrite(BIB, 255);
}

//Combinamos adelante y atras

void atras()
{
  analogWrite(AIA, 255);
  analogWrite(AIB, 0);
  analogWrite(BIA, 0);
  analogWrite(BIB, 255);
}


//Combinamos adelante y atras pero de forma diferente

void adelante()
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

