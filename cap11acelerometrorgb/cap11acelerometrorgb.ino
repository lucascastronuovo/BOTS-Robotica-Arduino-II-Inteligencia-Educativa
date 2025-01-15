#include <MPU6050.h> 

MPU6050 mpu; //creamos el objeto de la clase MPU6050

int16_t ax, ay, az, gx, gy, gz;  //variables del acelerómetro y giroscopio

const int ledTest = 13;

int i;

int R = 3;
int G = 5;
int B = 6;


void setup() {
  Serial.begin(9600); //inicializamos el monitor serie

  mpu.initialize(); //inicianizamos el acelerómetro

  //DECLARO MOVIMIENTOS COMO SALIDA
   pinMode(R, OUTPUT);
   pinMode(G, OUTPUT);
   pinMode(B, OUTPUT);
   //pinMode(derecha, OUTPUT);

  

  if (!mpu.testConnection()) {

      Serial.println("No se pudo conectar el sensor. Revisar conexiones!");
      while(1);
      
    }


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

  movimiento_x();
  movimiento_y();
  equilibrio();
  
}


 //MOVIMIENTOS EN EJE X

 void movimiento_x () {
  
    if (ax <= -5) {

        digitalWrite(R, 255);
        digitalWrite(G, 0);
        digitalWrite(B, 0);
        delay(5);
      
      }

    if (ax >= 5) {

        digitalWrite(R, 0);
        digitalWrite(G, 255);
        digitalWrite(B, 0);
        delay(5);
        
      } 


  
  
  }

  //MOVIMIENTOS EN EJE Y
  
    void movimiento_y () {
      
        if (ay <= -5 ) {
  
          digitalWrite(R, 0);
          digitalWrite(G, 0);
          digitalWrite(B, 255);
          delay(5);
            
          
          }
      
        if (ay >= 5) {
          
          digitalWrite(R, 255);
          digitalWrite(G, 255);
          digitalWrite(B, 255);
          delay(5);
          
          
          }
      
      }
  
  
     //EN EQUILIBRIO
  
    void equilibrio (){ 
  
  
     if (ax == 0 && ay == 0) {
      
          digitalWrite(R, 0);
          digitalWrite(G, 0);
          digitalWrite(B, 0);
          delay(1);
      
      
      }
    }
