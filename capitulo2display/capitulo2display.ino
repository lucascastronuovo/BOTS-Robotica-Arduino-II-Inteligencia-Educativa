#include <TM1637Display.h> //librería TM1637

const int CLK = 4;
const int DIO = 2;

const int ledTest = 13;

TM1637Display display(CLK, DIO);

byte palabra[] = {
  0b01111111,  //B
  0b00111111,  //O
  0b00111001,  //C
  0b01110111  //A
};



void setup() {
  display.setBrightness(0x0f); //Brillo del Display

  pinMode(ledTest, OUTPUT);
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
  display.setSegments(palabra); //llama a la función setSegments del objeto display, que muestra el vector "palabra"
                                //asignando a cada segmento el valor del byte correspondiente al vector.

}
