   Setarea orei se face raporatat la **GMT**.
  <br> In functia _loop()_ incrementez timpul, verific _oSinguraVizualizare_ pentru a nu-mi aparea in program la fiecare loop daca vreau sa vad ultimele aprinderi ale becului ( am incercat sa chem din _setup()_ functia de afisare, dar nu mi se mai intorcea din ea, chiar daca o apelam acolo, nu am inteles de ce), verific daca pot sa citesc de la _SerialMonitor_ si imi pun varibila de citire in _istoric_, care este **1** pentru **afisare istoric** si **0** daca **nu** vreau afisare istoric. 
   In cazul in care introduc 1, va fi apelata functia _afisareIstoric_ in care parcurg  aprinderile pana la valoarea in care **timestampul** este **1491177600**, adica o data trecuta in memorie ca un sir de biti de 0(testez cu un _brake in if_), altfel opresc cand memoria a fost umpluta, adica adresa este mai mare decat ultima adresa din EEPROM. Pasul de parcurgere este 
<br> **eeAddress  += sizeof(UnixTime)**
<br> care se regaseste si in _loop()_, pentru a scrie data la urmatoarea adresa.
Pentru senzor folosesc **digialRead** ca sa aflu daca a detectat prezenta. Daca prezenta este detectata salvez ora si o convertesc in timestamp, o scriu in memorie si apoi o afisez. Las becul aprins pentru 5 s, apoi il sting si il las stins cel putin 0.2 ms, pana cand o noua prezenta va fi detectata.
<br>Pentru a aprinde becul, releul trebuie sa fie  programat cu  **digitalWrite(relayPin, LOW)**, are un comportament invers fata de cel intuitiv.
 
  


