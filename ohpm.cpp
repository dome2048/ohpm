#include "InternetButton/InternetButton.h"

InternetButton b = InternetButton();


int ohpm(String command);

int j=0;
int i=0;


int sirenPin = 0;


int sirenCounter = 0;
int disconnectTimer = 0;

boolean alarm = false;
boolean light = false;
boolean trouble = false;
boolean disconnected = false;

void setup()
{
    Particle.function("ohpm", ohpm);
	pinMode(sirenPin, OUTPUT);
	delay(10);
	RGB.control(true);
	RGB.color(0, 0, 0);
	b.begin();
	greenWave();
    beep1();
}


void loop() {
    
    if(b.allButtonsOn()) {
        alarm = false;
        trouble = false;
        light = false;
        noTone(0);
        b.allLedsOff();
    }
    
    	if (alarm == true) {
	   tone(sirenPin, 4000);
	   for (int x=0; x<5; x++) {
	      
	           
	           b.allLedsOn(255,0,0);
	           delay(50);
	           b.allLedsOff();
	          delay(50);
	        
             
         }
        tone(sirenPin, 5000);
        for (int y=0; y<5; y++) {
            
                
                b.allLedsOn(0,0,255);
	           delay(50);
	           b.allLedsOff();
	          delay(50);
	      
        }
        

	    
	}
	if (trouble == true) {
	    orangeWave(1);
	    sirenCounter = sirenCounter + 1;
	    if (sirenCounter == 20) {
	        tone(sirenPin, 4000);
	    }
	    if (sirenCounter > 20) {
	        noTone(sirenPin);
	        sirenCounter = 0;
	    }
	}

	if (disconnected == true) {
	    yellowWave(1);
	    blueWave(1);
	    sirenCounter = sirenCounter + 1;
	    if (sirenCounter == 20) {
	        tone(sirenPin, 4000);
	    }
	    if (sirenCounter > 20) {
	        noTone(sirenPin);
	        sirenCounter = 0;
	    }
	}



    disconnectTimer = disconnectTimer + 1;
    
    if (disconnectTimer >= 60000) {
        disconnected = true;
    }
    
    delay(10);
    

}

int ohpm(String command)
{
    if (command == "1") {
    alarm = true;        
    }


    if (command == "2") {
        alarm = false;
        b.allLedsOff();
	    noTone(sirenPin);
	    greenWave();
    }

    if (command == "3") {
    light = true;        
    b.allLedsOn(100, 100, 100);
    }

    if (command == "4") {
    light = false;      
    b.allLedsOn(0, 0, 0);
    }



    if (command == "5") {
    trouble = true;       
    
    }

    if (command == "6") {
    trouble = false;  
    blueWave(2);
    }

    if (command == "7") {
    yellowWave(2);
    }


    if (command == "10") {
        disconnectTimer = 0;
    //beep1();
        b.smoothLedOn(6, 0, 5, 0);
        delay(50);
        b.smoothLedOn(6, 0, 0, 0);
    }


    
}

void blueWave(int n) {
    
    for (int q=0; q<12; q++) {
    b.smoothLedOn(q, 0, 0, 255);
    delay(50);
    b.smoothLedOn(q, 0, 0, 0);

   }


}

void yellowWave(int n) {
    
    for (int q=0; q<12; q++) {
    b.smoothLedOn(q, 255, 255, 0);
    delay(50);
    b.smoothLedOn(q, 0, 0, 0);

   }
    

}

void orangeWave(int n) {
    
    for (int q=0; q<12; q++) {
    b.smoothLedOn(q, 255, 153, 0);
    delay(20);
    b.smoothLedOn(q, 0, 0, 0);

   }
    

}



void greenWave() {
   for (int q=0; q<12; q++) {
    b.smoothLedOn(q, 0, 50, 0);
    delay(50);


   }

    //delay(10);

   for (int w=0; w<12; w++) {
    b.ledOff(w);
    delay(50);
    

   }

 
}



void beep1()
{
  beep(4000, 50, 50);
	beep(4000, 50, 0);
}

void beep2()
{
  beep(4000, 50, 50);
	beep(4000, 1000, 0);
}

void beep3()
{
  beep(4000, 200, 50);
	beep(4650, 500, 0);
}

void beep4()
{
  beep(4125, 100, 50);
	beep(4000, 500, 0);
}


void beep(int freq, int duration, int wait)
{
  tone(sirenPin, freq);
  delay(duration);
  noTone(sirenPin);
  delay(wait);
}