# EEPROM
Pentru a salva in memorie data aprinderii becului folosesc un **timestamp** generat cu ajutorul bibiloteciii _UnixTime_
si folosesc functiile oferite de biblioteca _EEPROM_ pentru a citi si a scrie in memorie.
Citirea se poate fac o singura data la rularea programului prin introducerea numarului _1_ in _SerialMonitor_ 
 (citirea din serial se face cu  _istoric =* Serial.parseInt();*_)
Pentru contorizarea timpului folosesc un **RTC DS1302**  ce trebuie setat initial cu data curenta :
 *myRTC.setDS1302Time(secunda, minut, ora, ziDinSapt, zi, luna, an);*
<br> *// 20 mai 2021, 7:04:15 *

![](/EEPROM/eeprom.png)

