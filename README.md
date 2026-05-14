DESCRIEREA PROIECTULUI
Proiectul Smart Home are ca scop modelarea unui sistem inteligent de gestionare a locuintei.
Aplicatia serveste pentru implementarea, testarea si demonstrarea principiilor fundamentale ale POO.

La nivel structural, sistemul este construit in jurul unei clase centrale de tip manager, CasaSmart,
care actioneaza ca un creier pentru toate dispozitivele conectate. Aceasta gestioneaza o colectie
de echipamente, reprezentata printr-un vector de pointeri (std::vector<DispozitivSmart*>).
Aceasta abordare permite sistemului sa stocheze la un loc entitati diferite (becuri, termostate) sub
o singura clasa de baza. Prin utilizarea mostenirii, sistemul extinde functionalitatea de baza
(porneste, opreste, getNume) catre dispozitive specifice, precum BecRgb si Termostat, fiecare adaugand
atribute private specifice (intensitate, respectiv temperatura).

Din punct de vedere functional, programul ofera utilizatorului un mediu de interactiune continua prin
consola, sustinut de o bucla de tip while(true). Meniul interactiv permite:
1) Monitorizarea (status): Iterarea prin colectia de dispozitive si afișarea starii acestora,
   folosind supraincarcarea operatorului << combinata cu functii virtuale, pentru ca fiecare obiect sa se
   afiseze corect, conform tipului sau.

2) Controlul Individual (seteaza / sterge): Cautarea dinamica a unui dispozitiv dupa nume si modificarea
   parametrilor acestuia sau eliminarea sa completa din retea.

3) Automatizarea (seara): Un macro global care demonstreaza forta polimorfismului si a interfetelor
   (clasa abstracta IReglabil). La declansarea acestui mod, hub-ul central parcurge toate dispozitivele si,
   folosind mecanismul de dynamic_cast, le filtreaza si le modifica comportamentul doar pe cele care suporta
   reglajul (ex: scade intensitatea tuturor becurilor la 20%), ignorand in siguranta restul dispozitivelor.

La nivel de cod, proiectul se distinge prin:
1) Modularitate: Separarea stricta a codului in fisiere header (.h) pentru declaratii de clase si fisiere
   sursa (.cpp) pentru implementarea metodelor, legarea lor fiind gestionata eficient prin sistemul de build
   CMake.

2) Siguranta si Robustete: Implementarea unei ierarhii de exceptii personalizate (SmartHomeException),
   care intercepteaza erorile de tip input invalid (de exemplu, setarea unei intensitati de 150%) sau
   referinte gresite (cautarea unui dispozitiv inexistent). Acest mecanism de tip try-catch previne
   crash-urile aplicatiei si ofera feedback explicit utilizatorului prin fluxul de eroare (std::cerr).

3) Managementul Memoriei: Deoarece dispozitivele sunt alocate dinamic pe zona de memorie Heap
   (folosind operatorul new), clasa CasaSmart isi asuma responsabilitatea completa a eliberarii acesteia.
   Acest lucru se realizeaza prin apelarea explicita a operatorului delete la stergerea unui element
   individual si in destructorul clasei la iesirea din program, prevenind astfel scurgerile de memorie.

Obiective tehnice:
- gestionarea dinamica a dispozitivelor (alocare pe Heap);
- implementarea unei ierarhii de exceptii custom pentru validare;
- interactiune printr-un meniu complet in terminal;
- management riguros al memoriei prin destructori virtuali si eliberare explicita.


CONCEPTE POO IMPLEMENTATE:
Încapsulare: utilizarea modificatorilor de acces private pentru protejarea
datelor si expunerea lor prin metode publice (getteri/setteri);

Moștenire: clasele BecRgb si Termostat deriva din clasa de baza DispozitivSmart;

Polimorfism: utilizarea metodelor virtual si a dynamic_cast pentru a apela
comportamente diferite in functie de tipul real al obiectului la runtime;

Abstractizare (Interfețe): Implementarea interfetei IReglabil pentru a
uniformiza controlul dispozitivelor cu variator;

Supraincarcarea Operatorilor: Implementarea operatorului << pentru afisare si +=
pentru adaugarea facila a dispozitivelor în sistem.


GHID DE UTILIZARE:
status: afiseaza toate dispozitivele si starea lor curenta;
seara: activeaza un macro polimorfic care regleaza automat toate luminile si temperatura;
seteaza: permite modificarea manuala a unui dispozitiv cautat dupa nume;
sterge: elimina un dispozitiv din sistem si elibereaza memoria aferenta;
exit: inchide aplicatia in siguranta.


Proiectul este organizat intr-o structura modulara, unde fisierele sunt interconectate
pentru a asigura o separare clara intre interfata, logica si executie:

- Exceptii.h: Defineste ierarhia proprie de erori, permitand semnalarea si prinderea
              specifica a problemelor de input sau cautare.

- Interfete.h: Contine contractul abstract IReglabil, care impune implementarea
               controlului de nivel pentru dispozitivele compatibile.

- DispozitivSmart.h & .cpp: Constituie „fundatia” proiectului, definind clasa de baza
                            cu atributele si metodele virtuale comune tuturor echipamentelor.

- BecRgb.h & .cpp: Implementeaza un dispozitiv specific prin mostenire (DispozitivSmart)
                   si abstractizare (IReglabil), adaugand logica de control pentru luminozitate.

- Termostat.h & .cpp: O alta specializare a clasei de baza, dedicata gestionarii
                      valorilor de temperatura.

- CasaSmart.h & .cpp: Reprezinta nucleul sistemului; acest fisier include headerele
                      dispozitivelor pentru a le putea stoca polimorfic intr-un vector
                      si pentru a gestiona ciclul lor de viata (creare/stergere).

- main.cpp: Coordoneaza intreaga aplicatie, incluzand clasa manager (CasaSmart)
            si exceptiile, oferind interfata interactiva pentru utilizator.
