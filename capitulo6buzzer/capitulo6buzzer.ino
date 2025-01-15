int buzzer = 5;  //definimos el objeto buzzer
const int ledTest = 13; //definimos el led de saludo principal 

int tones[ ] = {261, 277, 294, 311, 330, 349, 370, 392, 415, 440, 466, 494}; //definimos un vector con las frecuencias de cada nota



void setup() {
pinMode(buzzer, OUTPUT);
pinMode(ledTest, OUTPUT);

//Saludo inicial

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

  for (int i = 0; i < 11; i++) { //hacemos un for para recorrer los 11 tonos.

      tone(buzzer, tones[i]); //en este caso, no indicamos la duración del tono, por lo que cada uno durará hasta que inicie el siguiente
      delay(500);
    
    }

  noTone(buzzer); //con noTone frenamos
  
}
