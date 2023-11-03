# EEPROM
Pentru a salva in memorie data aprinderii becului folosesc un **timestamp** generat cu ajutorul bibiloteciii _UnixTime_
si folosesc functiile oferite de biblioteca _EEPROM_ pentru a citi si a scrie in memorie.
Citirea se poate fac o singura data la rularea programului prin introducerea numarului _1_ in _SerialMonitor_ 
 (citirea din serial se face cu  _istoric =* Serial.parseInt();*_)
Pentru contorizarea timpului folosesc un **RTC DS1302**  ce trebuie setat initial cu data curenta :
 *myRTC.setDS1302Time(secunda, minut, ora, ziDinSapt, zi, luna, an);*
<br> *// 20 mai 2021, 7:04:15 *
<br> In poza se poate observa ca sunt niste date gresite, asta pentru ca am uitat bateria in RTC si s-a descarcat. Voi reveni cu update la poza odata ce imi iau o noua baterie.
![](/EEPROM/eeprom.png)

