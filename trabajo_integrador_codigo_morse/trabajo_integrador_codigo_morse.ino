#include <TM1637TinyDisplay.h>
#include <Keypad.h>


int buzzer = 11;

const int ledTest = 13;

int ledBlanco = 12;

//definimos filas y columnas de nuestro teclado

const byte filas = 4;
const byte columnas = 3;

#define CLK 3
#define DIO 2

//definimos los pines de fila y los de columna

byte pinesFilas[filas] = {4, 5, 6, 7};
byte pinesColumnas[columnas] = {8, 9, 10}; 

//Distribución del teclado

char teclas[filas][columnas] = {

  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'},
  {'*', '0', '#'}
};

char tecla;
char valor[2];

char valor_esperado_1[2] = "1";
char valor_esperado_2[2]= "2";
char valor_esperado_3[2] = "3";
char valor_esperado_4[2] = "4";
char valor_esperado_5[2] = "5";
char valor_esperado_6[2] = "6";
char valor_esperado_7[2] = "7";
char valor_esperado_8[2] = "8";
char valor_esperado_9[2] = "9";
char valor_esperado_0[2] = "0";
char valor_esperado_asterisco[2] = "*";
char valor_esperado_hashtag[2] = "#";

char indice = 0;



//se crea el objeto teclado de la clase Keypad

Keypad teclado = Keypad(makeKeymap(teclas), pinesFilas, pinesColumnas, filas, columnas);

TM1637TinyDisplay display(CLK, DIO);  //Objeto display clase TM1637TinyDisplay



//Canción de los Piratas del Caribe.  Link: https://technoesolution.blogspot.com/2020/06/pirates-of-caribbean-theme-song-using.html
const int songspeed = 1.5;

#define NOTE_C4  262
#define NOTE_D4  294
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_G4  392
#define NOTE_A4  440
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_D5  587
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_G5  784
#define NOTE_A5  880
#define NOTE_B5  988

int notes[] = {
  
   NOTE_E4, NOTE_G4, NOTE_A4, NOTE_A4, 0, 
   NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, 0, 
   NOTE_C5, NOTE_D5, NOTE_B4, NOTE_B4, 0,
   NOTE_A4, NOTE_G4, NOTE_A4, 0,
   
   NOTE_E4, NOTE_G4, NOTE_A4, NOTE_A4, 0, 
   NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, 0, 
   NOTE_C5, NOTE_D5, NOTE_B4, NOTE_B4, 0,
   NOTE_A4, NOTE_G4, NOTE_A4, 0,
   
   NOTE_E4, NOTE_G4, NOTE_A4, NOTE_A4, 0, 
   NOTE_A4, NOTE_C5, NOTE_D5, NOTE_D5, 0, 
   NOTE_D5, NOTE_E5, NOTE_F5, NOTE_F5, 0,
   NOTE_E5, NOTE_D5, NOTE_E5, NOTE_A4, 0,
   
   NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, 0, 
   NOTE_D5, NOTE_E5, NOTE_A4, 0, 
   NOTE_A4, NOTE_C5, NOTE_B4, NOTE_B4, 0,
   NOTE_C5, NOTE_A4, NOTE_B4, 0,

   NOTE_A4, NOTE_A4, 
   //Repeat of first part
   NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, 0, 
   NOTE_C5, NOTE_D5, NOTE_B4, NOTE_B4, 0,
   NOTE_A4, NOTE_G4, NOTE_A4, 0,

   NOTE_E4, NOTE_G4, NOTE_A4, NOTE_A4, 0, 
   NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, 0, 
   NOTE_C5, NOTE_D5, NOTE_B4, NOTE_B4, 0,
   NOTE_A4, NOTE_G4, NOTE_A4, 0,
   
   NOTE_E4, NOTE_G4, NOTE_A4, NOTE_A4, 0, 
   NOTE_A4, NOTE_C5, NOTE_D5, NOTE_D5, 0, 
   NOTE_D5, NOTE_E5, NOTE_F5, NOTE_F5, 0,
   NOTE_E5, NOTE_D5, NOTE_E5, NOTE_A4, 0,
   
   NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, 0, 
   NOTE_D5, NOTE_E5, NOTE_A4, 0, 
   NOTE_A4, NOTE_C5, NOTE_B4, NOTE_B4, 0,
   NOTE_C5, NOTE_A4, NOTE_B4, 0,
   //End of Repeat

   NOTE_E5, 0, 0, NOTE_F5, 0, 0,
   NOTE_E5, NOTE_E5, 0, NOTE_G5, 0, NOTE_E5, NOTE_D5, 0, 0,
   NOTE_D5, 0, 0, NOTE_C5, 0, 0,
   NOTE_B4, NOTE_C5, 0, NOTE_B4, 0, NOTE_A4,

   NOTE_E5, 0, 0, NOTE_F5, 0, 0,
   NOTE_E5, NOTE_E5, 0, NOTE_G5, 0, NOTE_E5, NOTE_D5, 0, 0,
   NOTE_D5, 0, 0, NOTE_C5, 0, 0,
   NOTE_B4, NOTE_C5, 0, NOTE_B4, 0, NOTE_A4
   
};

int duration[] = 
{
  
  125, 125, 250, 125, 125, 
  125, 125, 250, 125, 125,
  125, 125, 250, 125, 125,
  125, 125, 375, 125, 
  
  125, 125, 250, 125, 125, 
  125, 125, 250, 125, 125,
  125, 125, 250, 125, 125,
  125, 125, 375, 125, 
  
  125, 125, 250, 125, 125, 
  125, 125, 250, 125, 125,
  125, 125, 250, 125, 125,
  125, 125, 125, 250, 125,

  125, 125, 250, 125, 125, 
  250, 125, 250, 125, 
  125, 125, 250, 125, 125,
  125, 125, 375, 375,

  250, 125,
  //Rpeat of First Part
  125, 125, 250, 125, 125,
  125, 125, 250, 125, 125,
  125, 125, 375, 125, 
  
  125, 125, 250, 125, 125, 
  125, 125, 250, 125, 125,
  125, 125, 250, 125, 125,
  125, 125, 375, 125, 
  
  125, 125, 250, 125, 125, 
  125, 125, 250, 125, 125,
  125, 125, 250, 125, 125,
  125, 125, 125, 250, 125,

  125, 125, 250, 125, 125, 
  250, 125, 250, 125, 
  125, 125, 250, 125, 125,
  125, 125, 375, 375,
  
  //End of Repeat
  
  250, 125, 375, 250, 125, 375,
  125, 125, 125, 125, 125, 125, 125, 125, 375,
  250, 125, 375, 250, 125, 375,
  125, 125, 125, 125, 125, 500,

  250, 125, 375, 250, 125, 375,
  125, 125, 125, 125, 125, 125, 125, 125, 375,
  250, 125, 375, 250, 125, 375,
  125, 125, 125, 125, 125, 500
  
};


void setup() {
  
display.clear(); //se limpia el display
Serial.begin(9600);

pinMode(buzzer, OUTPUT); 

pinMode(ledTest, OUTPUT);

pinMode(ledBlanco, OUTPUT);
digitalWrite(ledBlanco, LOW);



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
  //definimos el brillo del display
  display.setBrightness(BRIGHT_HIGH);

  tecla = teclado.getKey();

  if (tecla) {

    if (tecla){ //si se presiona una tecla, que haga lo siguiente...


    valor[indice] = tecla;  
    indice++; 
    Serial.print(tecla); 


    } 
  }  

  if (indice == 1){
    
    Serial.println();
    
   if (!strcmp(valor, valor_esperado_1)) {
      
    //SOS     
    display.clear();
    display.showString("SOS");
    delay(2000);
    display.clear();
   
    tone(buzzer, 800, 1000);
    delay(2000);                //S
    tone(buzzer, 800, 1000);
    delay(2000);
    tone(buzzer, 800, 1000);
    delay(2000); 

    delay(3000);

    tone(buzzer, 500, 3000);
    delay(4000);                      //O
    tone(buzzer, 500, 3000);
    delay(4000);
    tone(buzzer, 500, 3000);
    delay(4000);

    delay(3000);

    tone(buzzer, 800, 1000);
    delay(2000);                     //S
    tone(buzzer, 800, 1000);
    delay(2000);
    tone(buzzer, 800, 1000);
    delay(2000); 
  
    delay(2000);

    display.showString("FIN");
    delay(1000);
    display.clear();   
    

      
      }

    else if (!strcmp(valor, valor_esperado_2)) {
      
    //Estoy Herido    
    display.clear();
    display.showString("Estoy");
    delay(1000);
    display.showString("Herido");
    delay(2000);
    display.clear();
  
  tone(buzzer, 800, 1000);
  delay(2000); //E

  delay(3000);


  tone(buzzer, 800, 1000);
  delay(2000);                    //S
  tone(buzzer, 800, 1000);
  delay(2000);
  tone(buzzer, 800, 1000);
  delay(2000); 

  delay(3000);


  tone(buzzer, 500, 3000);
  delay(4000);   //T

  delay(3000);


  tone(buzzer, 500, 3000);
  delay(4000);   //O
  tone(buzzer, 500, 3000);
  delay(4000);
  tone(buzzer, 500, 3000);
  delay(4000);
  
  delay(3000);

  
  tone(buzzer, 500, 3000);
  delay(4000);   //Y
  tone(buzzer, 800, 1000);
  delay(2000);
  tone(buzzer, 500, 3000);
  delay(4000);
  tone(buzzer, 500, 3000);
  delay(4000);
  
  delay(5000);

  tone(buzzer, 800, 1000);
  delay(2000);   //H
  tone(buzzer, 800, 1000);
  delay(2000);
  tone(buzzer, 800, 1000);
  delay(2000);
  tone(buzzer, 800, 1000);
  delay(2000);

  delay(3000);


  
  tone(buzzer, 800, 1000);
  delay(2000);   //E

  delay(3000);



  tone(buzzer, 800, 1000);
  delay(2000);  //R
  tone(buzzer, 500, 3000);
  delay(4000);
  tone(buzzer, 800, 1000);
  delay(2000);

  delay(3000);

  tone(buzzer, 800, 1000);
  delay(2000);   //I
  tone(buzzer, 800, 1000);
  delay(2000);

  delay(3000);

  tone(buzzer, 500, 3000);
  delay(4000);  //D
  tone(buzzer, 800, 1000);
  delay(2000);
  tone(buzzer, 800, 1000);
  delay(2000);

  delay(3000);

  tone(buzzer, 500, 3000);
  delay(4000);                      //O
  tone(buzzer, 500, 3000);
  delay(4000);
  tone(buzzer, 500, 3000);
  delay(4000);

  
    
  delay(2000); 
  
  display.showString("FIN");
  delay(1000);  
  display.clear();
      
      }

    else if (!strcmp(valor, valor_esperado_3)) {
      
     //Llama a la policía   
    display.clear();
    display.showString("Llama");
    delay(1000);
    display.showString("a la");
    delay(1000);
    display.showString("policia");
    delay(2000);
    display.clear();
   
    tone(buzzer, 800, 1000);
    delay(2000);       //L
    tone(buzzer, 500, 3000);
    delay(4000);
    tone(buzzer, 800, 1000);
    delay(2000);    
    tone(buzzer, 800, 1000);
    delay(2000);    


    delay(3000); 

    tone(buzzer, 800, 1000);
    delay(2000);    //L
    tone(buzzer, 500, 3000);
    delay(4000);
    tone(buzzer, 800, 1000);
    delay(2000); 
    tone(buzzer, 800, 1000);
    delay(2000); 

    delay(3000);

    tone(buzzer, 800, 1000);
    delay(2000);       //A
    tone(buzzer, 500, 3000);
    delay(4000);

    delay(3000);

    tone(buzzer, 500, 3000);
    delay(4000);       //M
    tone(buzzer, 500, 3000);
    delay(4000);

    delay(3000);


    tone(buzzer, 800, 1000);
    delay(2000);      //A
    tone(buzzer, 500, 3000);
    delay(4000);


    delay(5000);


    tone(buzzer, 800, 1000);
    delay(2000);      //A
    tone(buzzer, 500, 3000);
    delay(4000);


    delay(5000);



    tone(buzzer, 800, 1000);
    delay(2000);      //L
    tone(buzzer, 500, 3000);
    delay(4000);
    tone(buzzer, 800, 1000);
    delay(2000); 
    tone(buzzer, 800, 1000);
    delay(2000); 

    delay(3000);

    tone(buzzer, 800, 1000);
    delay(2000);      //A
    tone(buzzer, 500, 3000);
    delay(4000);

    delay(5000);




    tone(buzzer, 800, 1000);
    delay(2000);     //P
    tone(buzzer, 500, 3000);
    delay(4000);
    tone(buzzer, 500, 3000);
    delay(4000);
    tone(buzzer, 800, 1000);
    delay(2000); 

    delay(3000);

    tone(buzzer, 500, 3000);
    delay(4000);    //O
    tone(buzzer, 500, 3000);
    delay(4000);
    tone(buzzer, 500, 3000);
    delay(4000);

    delay(3000);

    tone(buzzer, 800, 1000);
    delay(2000);     //L
    tone(buzzer, 500, 3000);
    delay(4000);
    tone(buzzer, 800, 1000);
    delay(2000); 
    tone(buzzer, 800, 1000);
    delay(2000); 


    delay(3000);

    tone(buzzer, 800, 1000);
    delay(2000);     //I
    tone(buzzer, 800, 1000);
    delay(2000); 

    delay(3000);

    tone(buzzer, 500, 3000);
    delay(4000);      //C
    tone(buzzer, 800, 1000);
    delay(2000); 
    tone(buzzer, 500, 3000);
    delay(4000);
    tone(buzzer, 800, 1000);
    delay(2000); 

    delay(3000);

    tone(buzzer, 800, 1000);
    delay(2000);     //I
    tone(buzzer, 800, 1000);
    delay(2000); 

    delay(3000);

    tone(buzzer, 800, 1000);
    delay(2000);    //A
    tone(buzzer, 500, 3000);
    delay(4000);




    delay(2000);

    display.showString("FIN");
    delay(1000);
    display.clear();
    
      
      }

    else if (!strcmp(valor, valor_esperado_4)) {

    //Tiene un arma
    display.clear();
    display.showString("Tiene");
    delay(1000);
    display.showString("un");
    delay(1000);
    display.showString("arma");
    delay(2000);
    display.clear();
      
      tone(buzzer, 500, 3000);
      delay(4000);    //T
      
      delay(3000);
    
      tone(buzzer, 800, 1000);
      delay(2000);      //I
      tone(buzzer, 800, 1000);
      delay(2000);      
      
      delay(3000);
    
      tone(buzzer, 800, 1000);
      delay(2000);       //E
    
      delay(3000);
    
      tone(buzzer, 500, 3000);
      delay(4000);     //N
      tone(buzzer, 800, 1000);
      delay(2000);     
    
      delay(3000);
    
      tone(buzzer, 800, 1000);
      delay(2000);      //E
    
    
      delay(5000);
    
       
    
      tone(buzzer, 800, 1000);
      delay(2000);         //U
      tone(buzzer, 800, 1000);
      delay(2000);     
      tone(buzzer, 500, 3000);
      delay(4000);  
      
      delay(3000);
    
      tone(buzzer, 500, 3000);
      delay(4000);     //N
      tone(buzzer, 800, 1000);
      delay(2000);     
    
    
      delay(5000);
    
       
      
      tone(buzzer, 800, 1000);
      delay(2000);       //A
      tone(buzzer, 500, 3000);
      delay(4000);  
      
      
      delay(3000);
    
      tone(buzzer, 800, 1000);
      delay(2000);       //R
      tone(buzzer, 500, 3000);
      delay(4000);  
      tone(buzzer, 800, 1000);
      delay(2000);     
      
      
      delay(3000);
    
    
      tone(buzzer, 500, 3000);
      delay(4000);     //M
      tone(buzzer, 500, 3000);
      delay(4000);  
      
      delay(3000);
    
      tone(buzzer, 800, 1000);
      delay(2000);       //A
      tone(buzzer, 500, 3000);
      delay(4000);  
    
    
      delay(2000);

      display.showString("FIN");
      delay(1000);
      display.clear();
      
      
      }

    else if (!strcmp(valor, valor_esperado_5)) {
      
          
  //Incendio
  display.clear();
  display.showString("Incendio");
  delay(2000);
  display.clear();
    
  tone(buzzer, 800, 1000);
  delay(2000);      //I
  tone(buzzer, 800, 1000);
  delay(2000);      
  
  delay(3000);

  tone(buzzer, 500, 3000);
  delay(4000);     //N
  tone(buzzer, 800, 1000);
  delay(2000);     

  delay(3000);

  tone(buzzer, 500, 3000);
  delay(4000);        //C
  tone(buzzer, 800, 1000);
  delay(2000);     
  tone(buzzer, 500, 3000);
  delay(4000);  
  tone(buzzer, 800, 1000);
  delay(2000);     

  delay(3000);

  tone(buzzer, 800, 1000);
  delay(2000);       //E  

  delay(3000);

  tone(buzzer, 500, 3000);
  delay(4000);     //N
  tone(buzzer, 800, 1000);
  delay(2000);     


  delay(3000);  

  tone(buzzer, 500, 3000);
  delay(4000);    //D
  tone(buzzer, 800, 1000);
  delay(2000);     
  tone(buzzer, 800, 1000);
  delay(2000);     

  delay(3000);

  tone(buzzer, 800, 1000);
  delay(2000);      //I
  tone(buzzer, 800, 1000);
  delay(2000);      

  delay(3000);

  tone(buzzer, 500, 3000);
  delay(4000);      //O
  tone(buzzer, 500, 3000);
  delay(4000);  
  tone(buzzer, 500, 3000);
  delay(4000);  


  delay(2000);

  display.showString("FIN");
  delay(1000);
  display.clear();
  

      
      }

    else if (!strcmp(valor, valor_esperado_6)) {

      
    //No puedo hablar
    display.clear();
    display.showString("No");
    delay(1000);
    display.showString("puedo");
    delay(1000);
    display.showString("hablar");
    delay(2000);
    display.clear();


  
    tone(buzzer, 500, 3000);
    delay(4000);     //N
    tone(buzzer, 800, 1000);
    delay(2000);     

    delay(3000);

    tone(buzzer, 500, 3000);
    delay(4000);      //O
    tone(buzzer, 500, 3000);
    delay(4000);  
    tone(buzzer, 500, 3000);
    delay(4000);  

    delay(5000);

    

    tone(buzzer, 800, 1000);
    delay(2000);         //P
    tone(buzzer, 500, 3000);
    delay(4000);  
    tone(buzzer, 500, 3000);
    delay(4000);  
    tone(buzzer, 800, 1000);
    delay(2000);     

    delay(3000);

    tone(buzzer, 800, 1000);
    delay(2000);        //U
    tone(buzzer, 800, 1000);
    delay(2000);     
    tone(buzzer, 500, 3000);
    delay(4000);  
    
    delay(3000);

    tone(buzzer, 800, 1000);
    delay(2000);       //E

    delay(3000);

    tone(buzzer, 500, 3000);
    delay(4000);    //D
    tone(buzzer, 800, 1000);
    delay(2000);     
    tone(buzzer, 800, 1000);
    delay(2000);     

    delay(3000);

    tone(buzzer, 500, 3000);
    delay(4000);      //O
    tone(buzzer, 500, 3000);
    delay(4000);  
    tone(buzzer, 500, 3000);
    delay(4000);  


    delay(5000);




    tone(buzzer, 800, 1000);
    delay(2000);        //H
    tone(buzzer, 800, 1000);
    delay(2000);     
    tone(buzzer, 800, 1000);
    delay(2000);     
    tone(buzzer, 800, 1000);
    delay(2000);     

    delay(3000);

    tone(buzzer, 800, 1000);
    delay(2000);       //A
    tone(buzzer, 500, 3000);
    delay(4000);  

    delay(3000);

    tone(buzzer, 500, 3000);
    delay(4000);     //B
    tone(buzzer, 800, 1000);
    delay(2000);     
    tone(buzzer, 800, 1000);
    delay(2000);     
    tone(buzzer, 800, 1000);
    delay(2000);     

    delay(3000);

    tone(buzzer, 800, 1000);
    delay(2000);         //L
    tone(buzzer, 500, 3000);
    delay(4000);  
    tone(buzzer, 800, 1000);
    delay(2000);     
    tone(buzzer, 800, 1000);
    delay(2000);     

    delay(3000);

    tone(buzzer, 800, 1000);
    delay(2000);       //A
    tone(buzzer, 500, 3000);
    delay(4000);  

    delay(3000);
    
    tone(buzzer, 800, 1000);
    delay(2000);       //R
    tone(buzzer, 500, 3000);
    delay(4000);  
    tone(buzzer, 800, 1000);
    delay(2000);      


    delay(2000);

    display.showString("FIN");
    delay(1000);
    display.clear();
      }
    
    else if (!strcmp(valor, valor_esperado_7)) {

    //Llama a la ambulancia
    display.clear();
    display.showString("Llama");
    delay(1000);
    display.showString("a la");
    delay(1000);
    display.showString("ambulancia");
    delay(2000);
    display.clear();

   
    tone(buzzer, 800, 1000);
    delay(2000);        //L
    tone(buzzer, 500, 3000);
    delay(4000);  
    tone(buzzer, 800, 1000);
    delay(2000);     
    tone(buzzer, 800, 1000);
    delay(2000);     

    delay(3000);

    tone(buzzer, 800, 1000);
    delay(2000);        //L
    tone(buzzer, 500, 3000);
    delay(4000);  
    tone(buzzer, 800, 1000);
    delay(2000);     
    tone(buzzer, 800, 1000);
    delay(2000);     

    delay(3000);


    tone(buzzer, 800, 1000);
    delay(2000);           //A
    tone(buzzer, 500, 3000);
    delay(4000);  

    delay(3000);

    tone(buzzer, 500, 3000);
    delay(4000);         //M
    tone(buzzer, 500, 3000);
    delay(4000);  

    delay(3000);


    tone(buzzer, 800, 1000);
    delay(2000);          //A
    tone(buzzer, 500, 3000);
    delay(4000);  


    delay(5000);

    

    tone(buzzer, 800, 1000);
    delay(2000);          //A
    tone(buzzer, 500, 3000);
    delay(4000);  


    delay(5000);

    

    tone(buzzer, 800, 1000);
    delay(2000);          //L
    tone(buzzer, 500, 3000);
    delay(4000);  
    tone(buzzer, 800, 1000);
    delay(2000);     
    tone(buzzer, 800, 1000);
    delay(2000);     

    delay(3000);

    tone(buzzer, 800, 1000);
    delay(2000);          //A
    tone(buzzer, 500, 3000);
    delay(4000);  

    delay(5000);

    

    tone(buzzer, 800, 1000);
    delay(2000);          //A
    tone(buzzer, 500, 3000);
    delay(4000);  

    delay(3000);

    tone(buzzer, 500, 3000);
    delay(4000);         //M
    tone(buzzer, 500, 3000);
    delay(4000);  
    
    delay(3000);

    tone(buzzer, 500, 3000);
    delay(4000);     //B
    tone(buzzer, 800, 1000);
    delay(2000);     
    tone(buzzer, 800, 1000);
    delay(2000);     
    tone(buzzer, 800, 1000);
    delay(2000);     
    
    delay(3000);

    tone(buzzer, 800, 1000);
    delay(2000);        //U
    tone(buzzer, 800, 1000);
    delay(2000);     
    tone(buzzer, 500, 3000);
    delay(4000);  
    
    delay(3000);

    tone(buzzer, 800, 1000);
    delay(2000);          //L
    tone(buzzer, 500, 3000);
    delay(4000);  
    tone(buzzer, 800, 1000);
    delay(2000);     
    tone(buzzer, 800, 1000);
    delay(2000);     

    delay(3000);

    tone(buzzer, 800, 1000);
    delay(2000);          //A
    tone(buzzer, 500, 3000);
    delay(4000);  

    delay(3000);

    tone(buzzer, 500, 3000);
    delay(4000);     //N
    tone(buzzer, 800, 1000);
    delay(2000);     

    delay(3000);

    tone(buzzer, 500, 3000);
    delay(4000);        //C
    tone(buzzer, 800, 1000);
    delay(2000);     
    tone(buzzer, 500, 3000);
    delay(4000);  
    tone(buzzer, 800, 1000);
    delay(2000);     
  
    delay(3000);

    tone(buzzer, 800, 1000);
    delay(2000);           //I
    tone(buzzer, 800, 1000);
    delay(2000);      

    delay(3000);

    tone(buzzer, 800, 1000);
    delay(2000);          //A
    tone(buzzer, 500, 3000);
    delay(4000);  


    delay(2000);

    display.showString("FIN");
    delay(1000);
    display.clear();
    
 
      }
  
    else if (!strcmp(valor, valor_esperado_8)) {

    //Estoy perdido
    display.clear();
    display.showString("Estoy");
    delay(1000);
    display.showString("perdido");
    delay(2000);
    display.clear();

  
  tone(buzzer, 800, 1000);
  delay(2000);      //E

  delay(3000);

  tone(buzzer, 800, 1000);
  delay(2000);     
  tone(buzzer, 800, 1000);
  delay(2000);     
  tone(buzzer, 800, 1000);
  delay(2000);      //S

  delay(3000);

  tone(buzzer, 500, 3000);
  delay(4000);     //T

  delay(3000);

  tone(buzzer, 500, 3000);
  delay(4000);     //O
  tone(buzzer, 500, 3000);
  delay(4000);  
  tone(buzzer, 500, 3000);
  delay(4000);  
  
  delay(3000);

  tone(buzzer, 500, 3000);
  delay(4000);     //Y
  tone(buzzer, 800, 1000);
  delay(2000);     
  tone(buzzer, 500, 3000);
  delay(4000);  
  tone(buzzer, 500, 3000);
  delay(4000);  
  
  delay(5000);



  tone(buzzer, 800, 1000);
  delay(2000);         //P
  tone(buzzer, 500, 3000);
  delay(4000);  
  tone(buzzer, 500, 3000);
  delay(4000);  
  tone(buzzer, 800, 1000);
  delay(2000);     

  delay(3000);

  tone(buzzer, 800, 1000);
  delay(2000);       //E

  delay(3000);
    
  tone(buzzer, 800, 1000);
  delay(2000);       //R
  tone(buzzer, 500, 3000);
  delay(4000);  
  tone(buzzer, 800, 1000);
  delay(2000);      

  delay(3000);

  tone(buzzer, 500, 3000);
  delay(4000);    //D
  tone(buzzer, 800, 1000);
  delay(2000);     
  tone(buzzer, 800, 1000);
  delay(2000);     

  delay(3000);

  tone(buzzer, 800, 1000);
  delay(2000);      //I
  tone(buzzer, 800, 1000);
  delay(2000);     

  delay(3000);

  tone(buzzer, 500, 3000);
  delay(4000);    //D
  tone(buzzer, 800, 1000);
  delay(2000);     
  tone(buzzer, 800, 1000);
  delay(2000);     

  delay(3000);

  tone(buzzer, 500, 3000);
  delay(4000);     //O
  tone(buzzer, 500, 3000);
  delay(4000);  
  tone(buzzer, 500, 3000);
  delay(4000);  

  
  delay(2000);

  display.showString("FIN");
  delay(1000);
  display.clear();
  
      
      }

    else if (!strcmp(valor, valor_esperado_9)) {
    
    //Nos hundimos
    display.clear();
    display.showString("Nos");
    delay(1000);
    display.showString("hundimos");
    delay(2000);
    display.clear();
  
    tone(buzzer, 500, 3000);
    delay(4000);     //N
    tone(buzzer, 800, 1000);
    delay(2000);     

    delay(3000);

    tone(buzzer, 500, 3000);
    delay(4000);     //O
    tone(buzzer, 500, 3000);
    delay(4000);  
    tone(buzzer, 500, 3000);
    delay(4000);  

    delay(3000);

    tone(buzzer, 800, 1000);
    delay(2000);     
    tone(buzzer, 800, 1000);
    delay(2000);     
    tone(buzzer, 800, 1000);
    delay(2000);      //S


    delay(5000);



    tone(buzzer, 800, 1000);
    delay(2000);        //H
    tone(buzzer, 800, 1000);
    delay(2000);     
    tone(buzzer, 800, 1000);
    delay(2000);     
    tone(buzzer, 800, 1000);
    delay(2000);     

      
    delay(3000);

    tone(buzzer, 800, 1000);
    delay(2000);        //U
    tone(buzzer, 800, 1000);
    delay(2000);     
    tone(buzzer, 500, 3000);
    delay(4000);  

    delay(3000);

    tone(buzzer, 500, 3000);
    delay(4000);     //N
    tone(buzzer, 800, 1000);
    delay(2000);     

    delay(3000);

    tone(buzzer, 500, 3000);
    delay(4000);    //D
    tone(buzzer, 800, 1000);
    delay(2000);     
    tone(buzzer, 800, 1000);
    delay(2000);     
      
    delay(3000);

    tone(buzzer, 800, 1000);
    delay(2000);      //I
    tone(buzzer, 800, 1000);
    delay(2000);     

    delay(3000);

    tone(buzzer, 500, 3000);
    delay(4000);         //M
    tone(buzzer, 500, 3000);
    delay(4000);  

    delay(3000);

    tone(buzzer, 500, 3000);
    delay(4000);     //O
    tone(buzzer, 500, 3000);
    delay(4000);  
    tone(buzzer, 500, 3000);
    delay(4000);  

    delay(3000);

    tone(buzzer, 800, 1000);
    delay(2000);       //S
    tone(buzzer, 800, 1000);
    delay(2000);     
    tone(buzzer, 800, 1000);
    delay(2000);      


    delay(2000);

    display.showString("FIN");
    delay(1000);
    display.clear();
      
      }

    else if (!strcmp(valor, valor_esperado_0)) {
      
        for (int i=0;i<203;i++)
        {
        int wait = duration[i] * songspeed;
        tone(buzzer,notes[i],wait);
        delay(wait);

        
        }

        delay(2000);
        display.showString("FIN");
        delay(1000);
        display.clear();
        
      
      }

    else if (!strcmp(valor, valor_esperado_asterisco)) {

        digitalWrite(ledBlanco, HIGH);
        display.showString("ON");
        delay(1000);
        display.clear();
      
      }

    else if (!strcmp(valor, valor_esperado_hashtag)) {
      
        digitalWrite(ledBlanco, LOW);
        display.showString("OFF");
        delay(1000);
        display.clear();
      
      }
      
    indice = 0;
  }

    noTone(buzzer);
    display.clear();

   
  }

 



  




  
  
