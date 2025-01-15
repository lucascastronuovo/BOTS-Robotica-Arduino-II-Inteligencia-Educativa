#include <MPU6050.h> 

MPU6050 mpu; //creamos el objeto de la clase MPU6050

int16_t ax, ay, az, gx, gy, gz;  //variables del acelerómetro y giroscopio

const int ledTest = 13;

int i;

void setup() {
  Serial.begin(9600); //inicializamos el monitor serie

  mpu.initialize(); //inicianizamos el acelerómetro

  
  if (!mpu.testConnection()) {

      Serial.println("No se pudo conectar el sensor. Revisar conexiones!");
      while(1);
      
    }

  pinMode(ledTest, OUTPUT);
  digitalWrite(ledTest, LOW);

  
  //Saludo inicial

  for (i = 0; i > 3; i++) {
    
      digitalWrite(ledTest, HIGH);
      delay(500);
      digitalWrite(ledTest, LOW);
      delay(500);
    
    }
  




    
}

void loop() {
  
  mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);

  ax = -(ax / 1000);  //esto se hace para que no muestre valores muy altos y eliminar ruido (ojo que quita resolución)
  ay = (ay / 1000);   //esto se hace para que no muestre valores muy altos y eliminar ruido (ojo que quita resolución)
  az = (az / 1000);   //esto se hace para que no muestre valores muy altos y eliminar ruido (ojo que quita resolución)


  //mostramos en el monitor serie los promedios en X y en Y (se puede hacer con ax y ay también)

  Serial.print("Eje X: ");
  Serial.print(ax);
  Serial.print(" , ");
  Serial.print("Eje Y: ");
  Serial.print(ay);
  Serial.print(" , ");
  Serial.print("Eje Z: ");
  Serial.println(az);
  delay(100);
    
  
  
  
  
  

}
