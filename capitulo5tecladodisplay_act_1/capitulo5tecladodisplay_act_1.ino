#include <Arduino.h>
#include <Keypad.h>

//Agregué al circuito un led rojo y uno blanco, del kit de bots inicial, con su respectiva
//resistencia. Modificá la programación para que cuando la clave ingresada sea correcta: se
//encienda el led blanco, y cuando la clave ingresada sea incorrecta, se encienda el led rojo.
//Recordá colocar las resistencias a cada uno de los leds.

//definimos los pines de los leds

int ledRojo = 12;
int ledBlanco = 11;


//definimos la cantidad de filas y columnas de nuestro teclado

const byte filas = 4;
const byte columnas = 3;

//definimos los pines de fila y los de columna

byte pinesFilas[filas] = {4, 5, 6, 7};
byte pinesColumnas[columnas] = {8, 9, 10};





//definimos la distribución del teclado

char teclas[filas][columnas] = {

  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'},
  {'*', '0', '#'}
};


//Otras cosas a hacer...

char tecla; //almacenamos la tecla presionada
char clave[5]; //almacena la clave ingresada de 4 dígitos
char claveCorrecta[5] = "3702"; //almacena la clave correcta
byte indice = 0;  //indice del vector


//se crea el objeto teclado de la clase Keypad

Keypad teclado = Keypad(makeKeymap(teclas), pinesFilas, pinesColumnas, filas, columnas);



//definimos el led de Saludo inicial

const int ledTest = 13;









void setup() {
  Serial.begin(9600); //inicia el monitor serie

  pinMode(ledRojo, OUTPUT);
  pinMode(ledBlanco, OUTPUT);

  digitalWrite(ledRojo, LOW);
  digitalWrite(ledBlanco, LOW);

  //Saludo inicial

  pinMode(ledTest, OUTPUT);

  digitalWrite(ledBlanco, HIGH);
  digitalWrite(ledRojo, HIGH);
  delay(500);
  digitalWrite(ledBlanco, LOW);
  digitalWrite(ledRojo, LOW);  
  

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







void loop()
{
  

  tecla = teclado.getKey(); //obtiene tecla del teclado y la almacena en tecla

  if (tecla){
    clave[indice] = tecla; //almacena la tecla presionada en el vector
    indice++;  //incrementa indice en uno
    Serial.print(tecla); //se muestra la tecla presionada en el monitor serie
  }


  if (indice == 4){ //si ya se almacenaron los 4 dígitos...
      
      Serial.println(); //imprima la clave

      if (!strcmp(clave, claveCorrecta)){ //si la clave ingresada coincide con la claveCorrecta...

        digitalWrite(ledBlanco, HIGH);
        delay(1000);
        digitalWrite(ledBlanco, LOW);
        delay(500);
      }

      else { //si la clave ingresada no coincide con la claveCorrecta...
          
        digitalWrite(ledRojo, HIGH);
        delay(1000);
        digitalWrite(ledRojo, LOW);
        delay(500);
        
        
      }
    
      indice = 0;  //reiniciamos el indice para poder escribir la nueva clave
    }

  
 










}
