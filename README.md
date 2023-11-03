
## **Motion Activated Light With Arduino**


    
       
## ***Introducere***
Aceasta este un proiect hardware DIY, mai exact un sistem de alarma, ce consta  in aprinderea unui bec in prezenta unui om si memorarea in EEPROM a orei la care se aprinde becul, putand fi interogate aprinderile pana la ultima inregistrata,  in care am folosit placa de dezvoltare Arduino Uno R3, un breadboard, un senzor de prezenta PIR cu raza de maxim 7 m pe 180 grade, un bec de 7W, un releu SRD-05VDC-SL-C pentru controlarea tensiunii becului in functie de activitatea senzorului de prezenta. Pentru a contoriza la ce ora se aprinde becul am folosit un modul DS1302.

## ***Biblioteci folosite*** 
Pentru a inregistra aprinderile becului am folosit biblioteca _EEPROM_, oferita de Arduino. Pentru a salva in memorie data, o transform intr-un timestamp cu ajutorul bibliotecii _UnixTime_, oferita de GyverLibs. Pentru data am folosit biblioteca _virtuabotixRTC_.
In schema Thinkercad se poate observa unde am legat pinii componentelor si cum am facut montajul.
Pentru a se inchide circuitul, becul trebuie bagat in priza.
![](/PozeProiect/ProiectFinal.jpeg)


 ## ***Recapitulare componente***
* Arduino Uno
![](/PozeProiect/ArduinoUno.jpeg)
* Senzor miscare PIR
![](/PozeProiect/PIR.jpeg)
* Releu de 5V 
![](/PozeProiect/Releu.jpeg)
* Led de 7 Watt
![](/PozeProiect/LED7W.jpeg)
* Modul RTC DS1302
![](/PozeProiect/RTCDS1302.jpeg)
Conectare
* Breadboard
* Fire (MF: 3-PIR, 5-RTC, 3-Releu si MM restul)

## ***Schema electrica sistem de alarma***
![](/SchemaElectrica.png)

## ***Proiecte similare***
* https://www.instructables.com/Motion-activated-light-with-Arduino-and-HC-SR04-se/
In acest proiect  se dezvolta aprinderea unei surse de lumina de 7 W la detectarea prezentei deschiderii unei usi cu ajutorul unui Arduino  si a unui senzor ultrasonic de masurare a distantei, urmand ca becul sa se stinga dupa 15 secunde.

* https://www.circuitbasics.com/setting-up-a-5v-relay-on-the-arduino/
In acest proiect se dezvolta controlarea unor device uri ce necesita 120-140 V pentru functionare, utilizandu-se de asemenea un releu pentru controlul tensiunii. In acest proieect este folosit un termistor ca instrument declansator( becul se aprinde cand termistorul ajunge la o temperatura  mai mare de 30 grd C).

* https://cleste.ro/atelier/senzor-pir/
Acest proiect urmareste intelegerea functionarii senzorului Piroelectric pentru detectarea miscarii intr-un motaj cu un led de o putere mai mica, ce nu mai necesita un releu aditional.

* https://cleste.ro/senzor-pir-hc-sr505-mini.html?utm_medium=GoogleAds&utm_campaign=&utm_source=&gclid=CjwKCAjw9LSSBhBsEiwAKtf0n50aGJwcEit4u3EU7LWasENMVT2MmV9zKLh6DSq7xdl6-LUekYTw8xoCzs8QAvD_BwE
Aici am inca un exemplu pentru folosirea senzorului PIR MINI, pus intr-un motaj similiar cu cel prezentat anterior.
## ***Bibliografie***
* https://create.arduino.cc/projecthub/biharilifehacker/arduino-with-pir-motion-sensor-fd540a
Aici m-am maui uitat cum sa leg senzorul PIR si cum sa il controlez
* https://docs.arduino.cc/learn/built-in-libraries/eeprom
Aici am mai citit pentru a sti sa folosesc EEPROM-ul
* https://surtrtech.com/2018/01/27/how-to-simply-use-ds1302-rtc-module-with-arduino-board-and-lcd-screen/
De aici am luat biblioteca pentru RTC
* https://github.com/GyverLibs/UnixTime
Cu aceasta biblioteca mi-am convertit data intr-un timestamp
