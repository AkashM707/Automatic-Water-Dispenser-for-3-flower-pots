/* Automatic Water Dispenser for 3 flower pots
made for the PPE for high school board exam by : Akash MAHTANI, Sophie ROQUETA, Emilie CAI, Aleksandra KRIVOKAPIC
We are using a EQV soil humidity sensor module such as this one: https://fr.aliexpress.com/item/32562744759.html
We are using a 4 phase stepper motor connected to the pins 8, 11, 12 and 13
The water pump is connected to the pin 2. The pump could be any peristaltic pump.
Alternatively, you can buy this all in one pack to make this project: https://www.amazon.fr/WayinTop-darrosage-Automatique-Submersibles-Transparent/dp/B07TJQSHR2/ref=asc_df_B07TJQSHR2/?tag=googshopfr-21&linkCode=df0&hvadid=354007743032&hvpos=&hvnetw=g&hvrand=15774594554700346647&hvpone=&hvptwo=&hvqmt=&hvdev=c&hvdvcmdl=&hvlocint=&hvlocphy=9056144&hvtargid=pla-793686734385&psc=1&tag=&ref=&adgrpid=72898046538&hvpone=&hvptwo=&hvadid=354007743032&hvpos=&hvnetw=g&hvrand=15774594554700346647&hvqmt=&hvdev=c&hvdvcmdl=&hvlocint=&hvlocphy=9056144&hvtargid=pla-793686734385
The power supply of the motor is connected to the pin 8 and 9. Please change the code if you change these pins
Github: https://github.com/AkashM707
*/
int sensorPin = A0; // defining the pin of the soil humidity sensor
int sensorValue = 0; // defining a variable to store the value of the soil humidity sensor

// defining the 4 pins for the stepper motor
int A = 8;
int B = 11;
int C = 12;
int D = 13;

int pump = 2

// intializing variables for the for/when loops
int i = 0;
int j=0;
int k=0;
int l=0;
int m=0;
int n=0;
int o=0;

int soil_humidity_treeshold = 200; // this value was set arbitrary by us as the threeshold of the soil humidity. 
//Once below this value, the system will water the plant
// feel free to change this value as your convenience. It ranges from 0 to 1023 

int del =5;//the variable del defines the delay between two steps of the motor (in ms)

void setup() {
  
    Serial.begin(9600);
     pinMode(A, OUTPUT);  
     pinMode(B, OUTPUT);
     pinMode(C, OUTPUT);
     pinMode(D, OUTPUT);
     pinMode(pump, OUTPUT);
}
void loop() {
 
  sensorValue = analogRead(sensorPin);
  Serial.print("sensor = " );
  Serial.println(sensorValue);
 //reading and printing the value of the sensor

      if (sensorValue < soil_humidity_treeshold)
   { 
          // we will move the pump to the first pot thanks to this while loop. We set the limit for i to 175
          //Because it was convenient for us given the distance to the first pot. You will have to change this 
          //value to adapt this code to your system
               while (i<= 175)   
        {
          //the arduino board starts the connection with the motor
                  digitalWrite(9, HIGH);
                  digitalWrite(10, HIGH);
      
          // telling the motor to start its 1st phase of movement
                  digitalWrite(A, HIGH); 
                  digitalWrite(B, HIGH);
                  digitalWrite(C, LOW); 
                  digitalWrite(D, LOW);
 
                  delay(del); 
   
         // telling the motor to start its 2nd phase of movement
                 digitalWrite(A, LOW); 
                 digitalWrite(B, HIGH);
                 digitalWrite(C, HIGH); 
                 digitalWrite(D, LOW);

                 delay(del);
        
         
         // telling the motor to start its 3rd phase of movement
                 digitalWrite(A, LOW);  
                 digitalWrite(B, LOW);
                 digitalWrite(C, HIGH);  
                 digitalWrite(D, HIGH);
 
                 delay(del); 
     
          // telling the motor to start its 3rd phase of movement
                 digitalWrite(A, HIGH);
                 digitalWrite(B, LOW);
                 digitalWrite(C, LOW);  
                 digitalWrite(D, HIGH);
          
                 delay(del);
                 i++;
              Serial.println(i);
      }

      // in this while loop, the pump waters the plant till the end of the loop
                while (j<=750)
          {
                    digitalWrite(pump, HIGH);
                     j++;
               Serial.println(j);    

          }
          digitalWrite(pump,LOW);
         
         delay(750);

          // we will move the pump to the second pot thanks to this while loop. We set the limit for k to 175
          //Because it was convenient for us given the distance to the second pot. You will have to change this 
          //value to adapt this code to your system
          while (k<= 175)   
        {
                  digitalWrite(9, HIGH);
                  digitalWrite(10, HIGH);
                 
                  digitalWrite(A, HIGH); 
                  digitalWrite(B, HIGH);
                  digitalWrite(C, LOW); 
                  digitalWrite(D, LOW);
 
                  delay(del); 

                 digitalWrite(A, LOW); 
                 digitalWrite(B, HIGH);
                 digitalWrite(C, HIGH); 
                 digitalWrite(D, LOW);
 
                 delay(del);
 
                 digitalWrite(A, LOW);  
                 digitalWrite(B, LOW);
                 digitalWrite(C, HIGH);  
                 digitalWrite(D, HIGH);
 
                 delay(del); 
 
                 digitalWrite(A, HIGH);
                 digitalWrite(B, LOW);
                 digitalWrite(C, LOW);  
                 digitalWrite(D, HIGH);
          
                 delay(del);
                 k++;
                 Serial.println(k);
   
      }


  while (l<=750)
          {
                    digitalWrite(pump, HIGH);
                     l++;
                       Serial.println(l);    
          }  digitalWrite(pump,LOW);
         
         delay(750);

          // we will move the pump to the third pot thanks to this while loop. We set the limit for m to 175
          //Because it was convenient for us given the distance to the third pot. You will have to change this 
          //value to adapt this code to your system
 while (m<= 175)   
        {
                  digitalWrite(9, HIGH);
                  digitalWrite(10, HIGH);
                 
                  digitalWrite(A, HIGH); 
                  digitalWrite(B, HIGH);
                  digitalWrite(C, LOW); 
                  digitalWrite(D, LOW);
 
                  delay(del); 

                 digitalWrite(A, LOW); 
                 digitalWrite(B, HIGH);
                 digitalWrite(C, HIGH); 
                 digitalWrite(D, LOW);
 
                 delay(del);
 
                 digitalWrite(A, LOW);  
                 digitalWrite(B, LOW);
                 digitalWrite(C, HIGH);  
                 digitalWrite(D, HIGH);
 
                 delay(del); 
 
                 digitalWrite(A, HIGH);
                 digitalWrite(B, LOW);
                 digitalWrite(C, LOW);  
                 digitalWrite(D, HIGH);
          
                 delay(del);
                 m++;
                 Serial.println(m);
   
      }
       while (n<=750)
          {
                    digitalWrite(pump, HIGH);
                     n++;
                Serial.println(n);    

          }  digitalWrite(pump,LOW);
         
         delay(750);

          // we will move the pump to its initial position. Notice that here, we changed the order of the 
          // blocks. For instance, the second block is LOW LOW HIGH HIGH and not LOW HIGH HIGH LOW as we used to do before 
 while (o<= 525)  
        {        digitalWrite(9, HIGH);
                 digitalWrite(10, HIGH);

                 digitalWrite(A, HIGH);
                 digitalWrite(B, LOW);
                 digitalWrite(C, LOW);  
                 digitalWrite(D, HIGH);

                delay(del);
                // second block: LOW LOW HIGH HIGH
                 digitalWrite(A, LOW);  
                 digitalWrite(B, LOW);
                 digitalWrite(C, HIGH);  
                 digitalWrite(D, HIGH);

               delay(del);
                 digitalWrite(A, LOW); 
                 digitalWrite(B, HIGH);
                 digitalWrite(C, HIGH); 
                 digitalWrite(D, LOW);
 
                 delay(del); 
                  digitalWrite(A, HIGH); 
                  digitalWrite(B, HIGH);
                  digitalWrite(C, LOW); 
                  digitalWrite(D, LOW);
                       
                 delay(del);
                 o++;
                 Serial.println(o);
       }
           }  else
{
  digitalWrite(pump, LOW);
}  }
