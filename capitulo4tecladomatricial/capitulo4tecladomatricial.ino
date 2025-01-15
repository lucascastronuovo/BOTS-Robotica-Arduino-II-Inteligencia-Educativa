#include <Keypad.h>


const byte filas = 4; //se declara el número de filas

const byte columnas = 3; //se declara el número de columnas


char teclas [filas][columnas] = {  //Se define la distribución de las teclas
  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'},
  {'*', '0', '#'}
  
   
};


byte pinesFilas[filas] = {4, 5, 6, 7}; //pines de filas

byte pinesColumnas[columnas] = {8, 9, 10}; //pines de columnas


Keypad teclado = Keypad(makeKeymap(teclas), pinesFilas, pinesColumnas, filas, columnas); //Se crea el objeto teclado desde la clase Keypad


char tecla; //se almacena la tecla que se pulsa
char clave[5]; //se almacena la clave ingresada
char claveCorrecta[5] = "3702"; //se almacena la clave que es correcta
char indice = 0; //indice del vector


const int ledTest = 13;

void setup() {
  Serial.begin(9600); //iniciamos el monitor serie

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

  tecla = teclado.getKey(); //obtiene tecla del teclado y la almacena en "tecla"

  if (tecla){ //si se presiona una tecla, que haga lo siguiente...


    clave[indice] = tecla;  //almacena el valor de la tecla en la posición (digito) correspondiente del vector
    indice++; //el indice avanza a la siguiente posición (digito)
    Serial.print(tecla); //se muestra el valor presionado en el monitor serie


    }   


  if (indice == 4){  //si ya se completaron los 4 dígitos....

    
    Serial.println(); //se envía la información al display
    
    if(!strcmp(clave, claveCorrecta)) //compara si los dígitos ingresados (En string) coinciden con la Clave Correcta. Si la clave coincide con la correcta, entonces muestra...
      Serial.println("Clave Correcta"); //que es correcta en el monitor serie
      
    else
      Serial.println("Clave Incorrecta"); //que es incorrecta en el monitor serie

    indice = 0; //reseteamos el indice para la proxima clave a ingresar
    
  }

}
