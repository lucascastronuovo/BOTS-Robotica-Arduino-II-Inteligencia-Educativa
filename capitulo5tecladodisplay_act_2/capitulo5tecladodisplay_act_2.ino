#include <Arduino.h>
#include <Keypad.h>
#include <TM1637TinyDisplay.h>


//Generá un cambio en la programación para que en el display se vayan encreibiendo los
//digitos en la medida que se van apretando, y una vez ingresado los 4, con un delay de 1
//segundo, haga la lectura de “correcto/incorrecto”


//definimos los pines de clock y dio

#define CLK 3
#define DIO 2


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

//se crea el objeto display de la clase TM1637TinyDisplay

TM1637TinyDisplay display(CLK, DIO);


//definimos el led de Saludo inicial

const int ledTest = 13;









void setup() {
  Serial.begin(9600); //inicia el monitor serie

  display.clear(); //se limpia el display para que no muestre ningún mensaje al inicio

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







void loop()
{
  //definimos el brillo del display
  display.setBrightness(BRIGHT_HIGH);

  tecla = teclado.getKey(); //obtiene tecla del teclado y la almacena en tecla

  if (tecla){
    display.showString(tecla);
    clave[indice] = tecla; //almacena la tecla presionada en el vector
    indice++;  //incrementa indice en uno
    Serial.print(tecla); //se muestra la tecla presionada en el monitor serie
    
  }


  if (indice == 4){ //si ya se almacenaron los 4 dígitos...


      Serial.println(); //imprima la clave

      delay(1000);
      
      if (!strcmp(clave, claveCorrecta)){ //si la clave ingresada coincide con la claveCorrecta...

        display.showString("ABRIR"); //que se muestre "CORRECTO" en el display
        display.clear(); //limpiamos el display
      }

      else { //si la clave ingresada no coincide con la claveCorrecta...
          
        display.showString("ERROR"); //que muestre "INCORRECTO" en el display
        display.clear();  //limpiamos el display
        
        
      }
    
      indice = 0;  //reiniciamos el indice para poder escribir la nueva clave
    }

  
 










}
