//INICIO VARIABLES

int disparo = 2;
const int echo = 4;

int ledTest = 13;


//Inicio variables temporales


long tiempoPulso;
float dstMedida;


void setup() {
  /*
    Con Serial.begin(9600)  habilitamos la entrada y salida de datos por el puerto serial para poder comunicarnos con otros dispositovs, o bien
    verlos en el monitor serie de la PC (que es lo que vamos a hacer en este caso)
  */
  Serial.begin(9600);

  //INICIO SETUP ENTRADAS / SALIDAS

  pinMode(ledTest, OUTPUT);
  pinMode(disparo, OUTPUT);
  pinMode(echo, INPUT);
  
  digitalWrite(disparo, LOW);

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
  
  //  Disparo de la señal.

  digitalWrite(disparo, HIGH); // envÃ­o del pulso ultrasÃ³nic
  delayMicroseconds(10);      //Hace una pausa en el programa porla cantidad de tiempo (en microsegundos) especificado como parÃ¡metro
  digitalWrite(disparo, LOW);      // hay un millÃ³n de microsegundos en un segundo
  

  /*
     Medimos la longitud del pulso entrante la utilizamos para medir el tiempo que transcurrido entre el envío del pulso ultrasonido 
     y cuando el sensor recibe el rebote, es decir: desde que el pin "echo" empieza a recibir el rebote, HIGH, hasta que deja de hacerlo, 
     LOW, la longitud del pulso entrante. El resultado lo da en microsegundos
  */

  tiempoPulso = pulseIn(echo, HIGH);
  

  /*
    Fórmula para calcular la distancia obteniendo un valor flotante
    340 m/s = 0.034 cm/us
    340 m/s es la velocidad del sonido, este parÃ¡metro lo podemos ajustar ya que depende de la densidad del aire.
  */
  dstMedida = 0.0340 / 2 * tiempoPulso;

  /*
    Enviamos al puerto serie la informacion recibida usando la libreria Serial.
  */ 
  
  Serial.println("Tiempo / Distancia "); /* Serial.println se usa para mostrar la información pasada por parametro y continuar
                                          en la linea de abajo, como si apretaramos "Enter"    */
 
  Serial.print(tiempoPulso);            /* Serial.print se usa para mostrar en el monitor serial, sin bajar de linea, es decir que 
                                           la informacion que enviemos en la proxima instruccion serial.print se escribira a continuación
                                           de la anterior, en la misma linea*/
  Serial.print(" / ");
  Serial.println(dstMedida);
  

  delay(500);
}


