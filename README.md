# LinUm-6
Projekt under kursen Linux som Utvecklingsmiljö vid Umeå Universitet.

Bibliotek 1, libresistance.so

Skriv ett bibliotek, libresistance.so, med funktioner för att beräkna den totala resistansen för olika kopplade  resistanser. Resistanserna ska kunna kopplas parallellt eller i serie. Man behöver inte räkna på blandade kopplingar.

float calc_resistance(int count, char conn, float *array);

Där:

    count: Antal komponenter.
    conn: Seriellt eller parallellt kopplade komponeter [ P | S ].
    *array: En pekare på en array av komponentvärden som är lika stor som count.
    Värdet 0 skall returneras om något motstånd är noll vid parallellkoppling, dvs  R1||R2=0, om R1 eller R2 är 0Ohm.
    Biblioteket får inte krascha om en "nollpekare" skickas till funktioen, dvs om array=0.
    Om argumenten är felaktiga skall funktionen returnera -1.

Returvärdet är den resulterande resistansen.


Biliotek 2, libpower.so

Ström som passerar ett motstånd värmer upp motståndet med en viss effekt (P). Effekten kan beräknas med hjälp av spänningen och ström eller spänning och motståndsvärdet enligt dessa formler:

P = U * I  (Spänning gånger strömmen)

P = U^2 / R (Spänning i kvadrat delat i resistansen)

Skriv ett bibliotek, libpower.so, med funktioner för att beräkna den totala effektutvecklingen i en krets med en spänningskälla kopplad i serie med en en resistans:

float calc_power_r(float volt, float resistance);

float calc_power_i(float volt, float current);


Bibliotek 3, libcomponent.so

Skriv ett bibliotek, libcomponent.so, med funktionen:

int count = e_resistance(float orig_resistance, float *res_array );
En funktion som beräknar vilka tre seriekopplade resistorer i E12-serien som närmast ersätter den resistans som skickas med.

    orig_resistance är ersättningsresistansen.
    *res_array är en pekare till en array med 3 resistorer som ska fyllas med värden ur E12-serien.
    count är hur många resistorer ur E12-serien som behövdes för att ersätta orig_resistance Om inte alla 3 komponenterna behövs ska de som inte används fyllas med värdet 0. count kan anta värde mellan 0 och 3.

