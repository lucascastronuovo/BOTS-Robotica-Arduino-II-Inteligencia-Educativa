#include <TM1637Display.h>
#include <Time.h>
#include <TimeLib.h>


//Modificá la programación para hacer que la alarma suena con la melodía de “Star Wars”, del
//capítulo anterior.

const int c = 261;
const int d = 294;
const int e = 329;
const int f = 349;
const int g = 391;
const int gS = 415;
const int a = 440;
const int aS = 455;
const int b = 466;
const int cH = 523;
const int cSH = 554;
const int dH = 587;
const int dSH = 622;
const int eH = 659;
const int fH = 698;
const int fSH = 740;
const int gH = 784;
const int gSH = 830;
const int aH = 880;


int counter = 0;

const int CLK = 4; //definimos clock
const int DIO = 2; //definimos dio

const int buzzerPin = 5; //definimos el buzzer

const int ledTest = 13; //definimos el ledTest


TM1637Display Display(CLK, DIO); //creamos el objeto display y le pasamos los pines

time_t t;  //creamos una variable de tipo tiempo

byte Digitos[] = {0, 0, 0, 0}; //creamos un vector llamado "Digitos" que contiene los 4 dígitos para el display

boolean puntos = true; //creamos una variable booleana para que encienda y apague los dos puntos del medio del display (Boolean = True - False (creo))

void setup() {
Serial.begin(9600); //permite iniciar la tranferencia de datos para nuestro display

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

t = now(); //le asignamos el tiempo actual a la fecha

mostrarHora(); //funcion creada

if (hour(t) == 8 && minute(t) == 13) { //comparamos la hora actual con una hora fijada a mano en el programa
  
      

    melodia_StarWars();
      
  
    delay(200);
  
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







void melodia_StarWars () {
  
     
  //Play first section
  firstSection();

  //Play second section
  secondSection();

  //Variant 1
  beep(f, 250);
  beep(gS, 500);
  beep(f, 350);
  beep(a, 125);
  beep(cH, 500);
  beep(a, 375);
  beep(cH, 125);
  beep(eH, 650);

  delay(500);

  //Repeat second section
  secondSection();

  //Variant 2
  beep(f, 250);
  beep(gS, 500);
  beep(f, 375);
  beep(cH, 125);
  beep(a, 500);
  beep(f, 375);
  beep(cH, 125);
  beep(a, 650);

  delay(650);
  
  }


 void beep(int note, int duration)
{
  //Play tone on buzzerPin
  tone(buzzerPin, note, duration);

  //Play different LED depending on value of 'counter'
  if (counter % 2 == 0)
  {
    delay(duration);
  } else
  {
    delay(duration);
  }

  //Stop tone on buzzerPin
  noTone(buzzerPin);

  delay(50);

  //Increment counter
  counter++;
}

void firstSection()
{
  beep(a, 500);
  beep(a, 500);
  beep(a, 500);
  beep(f, 350);
  beep(cH, 150);
  beep(a, 500);
  beep(f, 350);
  beep(cH, 150);
  beep(a, 650);

  delay(500);

  beep(eH, 500);
  beep(eH, 500);
  beep(eH, 500);
  beep(fH, 350);
  beep(cH, 150);
  beep(gS, 500);
  beep(f, 350);
  beep(cH, 150);
  beep(a, 650);

  delay(500);
}

void secondSection()
{
  beep(aH, 500);
  beep(a, 300);
  beep(a, 150);
  beep(aH, 500);
  beep(gSH, 325);
  beep(gH, 175);
  beep(fSH, 125);
  beep(fH, 125);
  beep(fSH, 250);

  delay(325);

  beep(aS, 250);
  beep(dSH, 500);
  beep(dH, 325);
  beep(cSH, 175);
  beep(cH, 125);
  beep(b, 125);
  beep(cH, 250);

  delay(350);
}
