void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}



void punto() {
    tone(buzzer, 800, 1000);
    delay(2000);    
  
}

 void raya() {
     tone(buzzer, 500, 3000);
     delay(4000);
        


}

int cod_display_SOS () {
  
    display.clear();
    display.showString("SOS");
    delay(2000);
    display.clear();
   
    tone(buzzer, 800, 1000);
    delay(2000);      //S
    tone(buzzer, 800, 1000);
    delay(2000);     
    tone(buzzer, 800, 1000);
    delay(2000);      

    delay(3000);

    tone(buzzer, 500, 3000);      delay(4000);      //O
    tone(buzzer, 500, 3000);      delay(4000);  
    tone(buzzer, 500, 3000);      delay(4000);  

    delay(3000);

    tone(buzzer, 800, 1000);     delay(2000);      //S
    tone(buzzer, 800, 1000);     delay(2000);     
    tone(buzzer, 800, 1000);     delay(2000);      
  
    delay(2000);

    display.clear();   
    

    
  }


 int cod_display_Estoyherido () {

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

  tone(buzzer, 800, 1000);
  delay(2000);   //O
  tone(buzzer, 800, 1000);
  delay(2000);
  tone(buzzer, 800, 1000);
  delay(2000);

  
    
  delay(2000); 
  
    
  display.clear();
  
  
  }



  int cod_display_Llamaalapolicia () {

    display.clear();
    display.showString("Llama");
    delay(1000);
    display.showString("a la");
    delay(1000);
    display.showString("policia");
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
    delay(2000);         //P
    tone(buzzer, 500, 3000);
    delay(4000);  
    tone(buzzer, 500, 3000);
    delay(4000);  
    tone(buzzer, 800, 1000);
    delay(2000);     

    delay(3000);

    tone(buzzer, 500, 3000);
    delay(4000);      //O
    tone(buzzer, 500, 3000);
    delay(4000);  
    tone(buzzer, 500, 3000);
    delay(4000);  

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
    delay(2000);         //I
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
    delay(2000);         //I
    tone(buzzer, 800, 1000);
    delay(2000);     

    delay(3000);

    tone(buzzer, 800, 1000);
    delay(2000);        //A
    tone(buzzer, 500, 3000);
    delay(4000);  




    delay(2000);

    display.clear();
    

    
    }



 int cod_display_Tieneunarma () {

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

  display.clear();
  

  
  }



int cod_display_Incendio() {
  

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

  display.clear();
  

  
  }


int cod_display_Nopuedohablar () {

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

    display.clear();
    
  
  }



  int cod_display_Llamaalaambulancia () {

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

    display.clear();
    

    
    }



int cod_display_Estoyperdido () {

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

  display.clear();
  

  
  }


int cod_display_Noshundimos () {

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

    display.clear();
    

    
  }


int cod_display_Peligro () {

  display.clear();
  display.showString("Peligro");
  delay(2000);
  display.clear();

  
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
  delay(2000);          //L
  tone(buzzer, 500, 3000);
  delay(4000);  
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
  delay(4000);    //G
  tone(buzzer, 500, 3000);
  delay(4000);  
  tone(buzzer, 800, 1000);
  delay(2000);     
  
  delay(3000);

  tone(buzzer, 800, 1000);
  delay(2000);       //R
  tone(buzzer, 500, 3000);
  delay(4000);  
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

  display.clear();
  

  
  }

/*
void luzRoja () {

    digitalWrite(R, 255);
    digitalWrite(G, 0);
    digitalWrite(B, 0);
    
  
  
  
  }


void luzVerde () {
    
    digitalWrite(R, 0);
    digitalWrite(G, 255);
    digitalWrite(B, 0);
    
    
    
    }


void luzAzul () {
    digitalWrite(R, 0);
    digitalWrite(G, 0);
    digitalWrite(B, 255);  
  
  
  }


void luzBlanca () {
  
    digitalWrite(R, 255);
    digitalWrite(G, 255);
    digitalWrite(B, 255);
  
 
  }


void apagarTodaslasluces () {
  
    digitalWrite(R, 0);
    digitalWrite(G, 0);
    digitalWrite(B, 0);
  
  
  
  
  
  }

*/ 


int musica (){

  for (int i=0;i<203;i++)
  {
  int wait = duration[i] * songspeed;
  tone(buzzer,notes[i],wait);
  delay(wait);
  
  }
