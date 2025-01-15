#include <TM1637Display.h>
#include <Wire.h>
#include <MPU6050.h>


MPU6050 mpu;

const int CLK = 4; //el pin CLK está conectado al pin digital 4
const int DIO = 2; //el pin DIO está conectado al pin digital 2

TM1637Display display(CLK, DIO); //creamos el objeto display
byte digitos [] = {0, 0, 0, 0};

const int ledTest = 13;



void setup() {   //inicializamos el display y el sensor y mostramos "init" en el display.

  display.setBrightness(0x0f); //establecemos el brillo del display  
  digitos[0] = 0b00110000; //i
  digitos[1] = 0b01010100; //n
  digitos[2] = 0b00010000; //i
  digitos[3] = 0b01111000; //t
  display.setSegments(digitos);
  delay(1000);

  while(!mpu.begin(MPU6050_SCALE_2000DPS, MPU6050_RANGE_2G))  //hacemos el chequeo del funcionamiento del sensor. Si no funciona bien mostramos "error" en el display
  {
    digitos[0] = 0b01111001; //E
    digitos[1] = 0b00110001; //r
    digitos[2] = 0b00110001; //r
    digitos[3] = 0b00000000; //-
    display.setSegments(digitos);
    delay(1000);

    
  }

  pinMode(ledTest, OUTPUT);

  //Saludo inicial
  digitalWrite(ledTest, LOW);
  delay(50);


  for (int i = 0; i <= 3; i++) {
  digitalWrite(ledTest, HIGH);
  delay(500);
  digitalWrite(ledTest, LOW);
  delay(500);

  }
  
}

void loop() {
  int temp = mpu.readTemperature() * 10; //lee la temperatura y la multiplica por 10 para trabajarla como un número entero

  //establecemos los valores de temperatura a los digitos correspondiente

  digitos[3] = display.encodeDigit(temp % 10);
  digitos[2] = 0b01100011; //formamos el signo de grados con los segmentos individuales
  digitos[1] = display.encodeDigit((temp % 100) / 10);
  digitos[0] = display.encodeDigit(temp / 100);

  display.setSegments(digitos);
  delay(500);
  
}
