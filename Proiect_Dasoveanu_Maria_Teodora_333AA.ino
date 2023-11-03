#include <UnixTime.h>
#include <EEPROM.h>
UnixTime stamp(3); // setare pt ora raportata la gmt
UnixTime stampRetrieved(3);
UnixTime stampRecuperat(3);
#include <virtuabotixRTC.h>
#include <util/delay.h>

// CONNECTIONS:
// DS1302 CLK/SCLK --> 5
// DS1302 DAT/IO --> 8
// DS1302 RST/CE --> 7
// DS1302 VCC --> 3.3v - 5v
// DS1302 GND --> GND
//#define sensorPin 2
//#define relayPin 9
int sensor = 4;              // the pin that the sensor is atteched to
int state = LOW;             // by default, no motion detected
int val = 0;                 // variable to store the sensor status (value)
int relayPin = 10;


virtuabotixRTC myRTC(6,7,8); //  SCLK, io, CE

int eeAddress = 0; // de unde sa inceapa sa scrie in eeprom


volatile int secunda = 30;
volatile int minut =  50;
volatile int ora = 23;
volatile int zi = 30;
volatile int luna = 5;
volatile int an = 2022;
volatile int ziDinSapt = 1;
int istoric = 0;
int oSinguraVizualizare = 0;

//const int backlight = 13;
//volatile boolean backlight_on;
volatile byte set_mode;

void setup() {

  //la pornire lumina de fundal a afisajului este oprita

  
  //setare mod functionare normala
  //set_mode = 0; Serial.begin(9600);
  Serial.begin(9600);

   Serial.println("Introduceti comanda 1  daca doriti sa afisati ultimele 10 aprinderi si 0 in caz contrar");
     
  
  
  myRTC.setDS1302Time(secunda, minut, ora, ziDinSapt, zi, luna, an);
   // 20 mai 2021, 7:04:15
//  pinMode(led, OUTPUT);
  pinMode(sensor, INPUT);    // initialize sensor as an input
  pinMode(relayPin, OUTPUT);
  digitalWrite(relayPin,HIGH);
  
       // initialize serial
}


void loop(){
   // update timp rtc
    
    delay(2000);
   
    
    myRTC.updateTime(); 
    if (oSinguraVizualizare == 0){
       while(Serial.available()==0){
      
       }
       istoric = Serial.parseInt(); 
       Serial.print("Ati introdus comanda: ");
       Serial.println(istoric);
       if (istoric == 1 )
         {
          afisareIstoric();
         
          oSinguraVizualizare +=1;
         }
         else
           {
             Serial.println("Ati apasat  tasta 0");
              oSinguraVizualizare +=1;
            }
   
    }

   
     
    val = digitalRead(sensor);   // read sensor value
    // folosesc un contor pentru a inregistra  starea curenta a becului
    if (val == HIGH) { 
 
    
    stamp.setDateTime(myRTC.year, myRTC.month, myRTC.dayofmonth, myRTC.hours, myRTC.minutes, myRTC.seconds);
    uint32_t unix = stamp.getUnix();
    Serial.println("MY time stamp");
    Serial.println(unix);
    
   
    
    EEPROM.put(eeAddress, stamp);
     
    EEPROM.get(eeAddress, stampRetrieved);
    uint32_t unixRecuperat = stampRetrieved.getUnix();
   
    Serial.println("MY retrived time stamp");
    Serial.println(unixRecuperat);
    
    
    stampRecuperat.getDateTime(unixRecuperat);
    
    
    
    Serial.println("Data recuperata : ");
    Serial.print(stampRecuperat.day);
    Serial.print("/");
    Serial.print(stampRecuperat.month);
    Serial.print("/");
    Serial.print(stampRecuperat.year);
    Serial.print("  ");
    Serial.print(stampRecuperat.hour);
    Serial.print(":");
    Serial.print(stampRecuperat.minute);
    Serial.print(":");
    Serial.println(stampRecuperat.second);

    eeAddress += sizeof(UnixTime);  // trec la urmatoarea locatie din memorie  
   
    digitalWrite(relayPin, LOW);   // turn LED ON
    delay(5000); 
    digitalWrite(relayPin, HIGH);   // apoi imi sting becul peste 5 s
 
    if(state == HIGH){            //schimb starea pentru contor deoarece am oprit curentul prin bec
       Serial.println("Motion stopped!"); 
       state = LOW;       
      }
       delay(200);  // un delay  dupa ce mi  se stinge becul
}  
}  


void afisareIstoric(){

    Serial.println("MY retrieved timestamp");
  while (eeAddress <= EEPROM.length() ){

    EEPROM.get(eeAddress, stampRetrieved);
    uint32_t unixRecuperat = stampRetrieved.getUnix();
    uint32_t unixGresit = 1491177600;
   
    if( unixRecuperat == unixGresit){
      Serial.print("Nu mai exista informatii");
      break;
      }  
    
    Serial.println(" Momentul aprinderii");
    Serial.println(unixRecuperat);
    stampRecuperat.getDateTime(unixRecuperat);
    Serial.println("Data recuperata : ");
    Serial.print(stampRecuperat.day);
    Serial.print("/");
    Serial.print(stampRecuperat.month);
    Serial.print("/");
    Serial.print(stampRecuperat.year);
    Serial.print("  ");
    Serial.print(stampRecuperat.hour);
    Serial.print(":");
    Serial.print(stampRecuperat.minute);
    Serial.print(":");
    Serial.println(stampRecuperat.second);

    eeAddress  += sizeof(UnixTime); 
    }
  
}
