// DECLARACION DE VARIABLES PARA PINES
const int pinecho = 8;
const int pintrigger = 9;
const int pinled = 13;
 
// VARIABLES PARA CALCULOS
unsigned int tiempo, distancia;
 
void setup() {
  // PREPARAR LA COMUNICACION SERIAL
  Serial.begin(9600);
  // CONFIGURAR PINES DE ENTRADA Y SALIDA
  pinMode(pinecho, INPUT);
  pinMode(pintrigger, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(30, OUTPUT);
  pinMode(31, OUTPUT);
  pinMode(32, OUTPUT);
}
 
void loop() {
  // ENVIAR PULSO DE DISPARO EN EL PIN "TRIGGER"
  digitalWrite(pintrigger, LOW);
  delayMicroseconds(2);
  digitalWrite(pintrigger, HIGH);
  // EL PULSO DURA AL MENOS 10 uS EN ESTADO ALTO
  delayMicroseconds(10);
  digitalWrite(pintrigger, LOW);
 
  // MEDIR EL TIEMPO EN ESTADO ALTO DEL PIN "ECHO" EL PULSO ES PROPORCIONAL A LA DISTANCIA MEDIDA
  tiempo = pulseIn(pinecho, HIGH);
 
  // LA VELOCIDAD DEL SONIDO ES DE 340 M/S O 29 MICROSEGUNDOS POR CENTIMETRO
  // DIVIDIMOS EL TIEMPO DEL PULSO ENTRE 58, TIEMPO QUE TARDA RECORRER IDA Y VUELTA UN CENTIMETRO LA ONDA SONORA
  distancia = tiempo / 58;
 
  // ENVIAR EL RESULTADO AL MONITOR SERIAL
  Serial.print("Distancia: ");
  Serial.print(distancia);
  Serial.println(" cm");
 // delay(200);
 
  // ENCENDER EL LED CUANDO SE CUMPLA CON CIERTA DISTANCIA
  if (distancia > 50 && distancia<101) {
    digitalWrite(30, HIGH);
    digitalWrite(31, LOW);
    digitalWrite(32, LOW);
  } 
  else if(distancia<51 && distancia>25){
    digitalWrite(30, LOW);
    digitalWrite(31, HIGH);
    digitalWrite(32, LOW);
    }
  else if(distancia<26 && distancia>4){
    digitalWrite(30, LOW);
    digitalWrite(31, LOW);
    digitalWrite(32, HIGH);
    }  
  else {
    digitalWrite(30, LOW);
    digitalWrite(31, LOW);
    digitalWrite(32, LOW);
  }
}
