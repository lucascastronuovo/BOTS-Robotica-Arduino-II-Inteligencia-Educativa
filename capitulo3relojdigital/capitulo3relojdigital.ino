#include <TM1637Display.h> //librería TM1637
#include <Time.h>
#include <TimeLib.h>

const int DIO = 2;
const int CLK = 4;

const int ledTest = 13;

TM1637Display display(CLK, DIO);

time_t t; //creamos una variable de tipo tiempo.
byte Digitos[] = {0, 0, 0, 0}; //creamos un vector que contiene los 4 bytes para formar los dígitos del display
boolean puntos = true; //variable booleana (variable que solo puede valer verdadero o falso) para prender y apagar los puntos del medio del reloj.



void setup() {
  display.setBrightness(0x0f); //Brillo del Display.
  setTime(23,00,00,20,03,2021); //Definimos la fecha y hora actual.

  pinMode(ledTest, OUTPUT);     //Saludo Inicial.
  digitalWrite(ledTest, LOW);

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
  t = now();   //asignamos el tiempo actual a la fecha y ahora tenemos que descomponer la hora total en los diferentes dígitos para mostrarlo en el display.

  if (hour(t)<10){         //si la hora es menor a 10, ponemos el 0, y si no, la decena de la hora.
    Digitos[0] = display.encodeDigit(0);
  }
  else{
    Digitos[0] = display.encodeDigit(hour(t) / 10);
  }

  //para hacer el código más corto podemos usar el operador ternario para los otros 3 digitos

  Digitos[1] = display.encodeDigit((hour(t) < 10) ? hour(t) : (hour(t) % 10)); //si es menor, va la hora, si es mayor a 10, va el resto de la división por 10.
  Digitos[2] = display.encodeDigit((minute(t) < 10) ? 0 : (minute(t) / 10));    //con los minutes es lo mismo, si van menos de 10 minutos ponemos el 0, si no ponemos la decena del minuto.
  Digitos[3] = display.encodeDigit((minute(t) < 10) ? minute(t) : (minute(t) % 10));  //si van menos de 10 minutos, ponemos el minuto, si no, el resto de la división por 10.
  
  if(puntos == true){  //Si la variable booleana esta en true, activar los dos puntos. Recordar los dos iguales.
      Digitos[1] = Digitos[1] | 0b010000000;} //Los dos puntos están incorporados en el dígito 1, debemos activarlos poniendo en 1 o 0 el segmento correspondiente.
  else {
      Digitos[1] = Digitos[1] | 0b000000000;}
  puntos =! puntos;        //Invertir el valor de la variablee booleana.

  display.setSegments(Digitos);
  delay(1000); //Esperamos un segundo para refrescar el reloj.
  
}
