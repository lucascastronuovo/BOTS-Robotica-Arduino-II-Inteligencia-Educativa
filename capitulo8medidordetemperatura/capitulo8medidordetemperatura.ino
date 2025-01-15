#include <Wire.h>   //la libreria para usar el I2c
#include <MPU6050.h>   //la libreria para usar el módulo GV-521


MPU6050 mpu;  //creamos el objeto para usar el módulo. No le tenemos que asignar pines porque I2C usa siempre los mismo pines (A4 y A5)

const int ledTest = 13;




void setup() {
  Serial.begin(9600); //activamos el monitor serie

  Serial.println("Inicializando MPU6050");

  while(!mpu.begin(MPU6050_SCALE_2000DPS, MPU6050_RANGE_2G)){                     //While es un bucle que funciona sin una cantidad predeterminada de ciclos. Mientras el
                                                                                  //sensor no se pueda inicializar usando el método begin, mostrar el mensaje e intentar de nuevo

    Serial.print("No se encontró el sensor MPU6050. Revisá el cableado!");
    delay(500);
  }

  pinMode(ledTest, OUTPUT);

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
  float temp = mpu.readTemperature(); //creamos la variable temp y le asignamos el valor directamente.

  Serial.print("Temperatura: ");
  Serial.print(temp);
  Serial.println(" °C");
  
  delay(500);
}
