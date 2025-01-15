#include <TM1637Display.h>
#include <Time.h>
#include <TimeLib.h>
#include <TM1637TinyDisplay.h>

#define clk 4
#define dio 2


//Agregá, al display, mientras suena la alarma, algún mensaje como:
//“HORA” - “DESPERTATE” - “ARRIBAAAA”
//Podés apoyarte con los conceptos de programación del capítulo 5.







//se crea el objeto display de la clase TM1637TinyDisplay

TM1637TinyDisplay display(clk, dio);


const int CLK = 4; //definimos clock
const int DIO = 2; //definimos dio

const int buzzer = 5; //definimos el buzzer

const int ledTest = 13; //definimos el ledTest


TM1637Display Display(CLK, DIO); //creamos el objeto display y le pasamos los pines

time_t t;  //creamos una variable de tipo tiempo

byte Digitos[] = {0, 0, 0, 0}; //creamos un vector llamado "Digitos" que contiene los 4 dígitos para el display

boolean puntos = true; //creamos una variable booleana para que encienda y apague los dos puntos del medio del display (Boolean = True - False (creo))

void setup() {
Serial.begin(9600); //permite iniciar la tranferencia de datos para nuestro display

display.clear();

Display.setBrightness(0x0f);  //establecemos el brillo para nuestro display

setTime(8, 12, 50, 10, 8, 2021);   //definimos (hora, minutos, segundos, dia, mes, año)

//Saludo inicial

pinMode(ledTest, OUTPUT);

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

display.setBrightness(BRIGHT_HIGH);

t = now(); //le asignamos el tiempo actual a la fecha

mostrarHora(); //funcion creada

if (hour(t) == 8 && minute(t) == 13) { //comparamos la hora actual con una hora fijada a mano en el programa
  
       mensajes_display();
  
  }


}




void mostrarHora (){

    Digitos[0] = Display.encodeDigit((hour(t) < 10) ? 0 : (hour(t) / 10));
    Digitos[1] = Display.encodeDigit((hour(t) < 10) ? hour(t) : (hour(t) % 10));
    Digitos[2] = Display.encodeDigit((minute(t) < 10) ? 0 : (minute(t) / 10));
    Digitos[3] = Display.encodeDigit((minute(t) < 10) ? minute(t) : (minute(t) % 10));

    if (puntos == true) {       //si la variable booleana está en true (Recordar los dos iguales para comparar)
      

          Digitos[1] = Digitos[1] + 0b010000000;    //activar los dos puntos sumando logicamente el bit (0 + 1)
          
          
      }
    else {

          Digitos[1] = Digitos[1] + 0b000000000;
    }

      puntos =! puntos;     //invertir el valor de la variable booleana

      Display.setSegments(Digitos);
      delay(1000);





  


}





void mensajes_display () {

    delay(500);
    display.showString("HORA");
    tone(buzzer, 800, 200);      //hacemos sonar el buzzer, 3 veces, durante 50 milisegundos
    delay(500);
    display.showString("DESPERTATE");
    tone(buzzer, 800, 200);      //hacemos sonar el buzzer, 3 veces, durante 50 milisegundos
    delay(500);
    display.showString("ARRIBAAAA");
    tone(buzzer, 800, 200);      //hacemos sonar el buzzer, 3 veces, durante 50 milisegundos
    delay(500);
    
  
  
  
  }
