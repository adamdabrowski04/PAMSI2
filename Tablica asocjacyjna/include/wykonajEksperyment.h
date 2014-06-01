#ifndef WYKONAJEKSPERYMENT_H
#define WYKONAJEKSPERYMENT_H
/*!
 *\file
 *\brief Definicja klasy wykonajEksperyment
 *
 *Plik zawiera definicję klasy wykonajEksperyment, która
 *jest odpowiedzialna za policzenie statystyk dla wybranej
 *liczby realizacji badanego algorytmu
 *
 */



#include "../include/oblicz.h"
#include <iostream>
#include <fstream>
#include<random>
#include<string>

const int POCZATEK_NUMERACJI=1;
const int LICZBAPRZEBIEGOW = 20;

class wykonajEksperyment
{

    public:
    int czasyRealizacji[LICZBAPRZEBIEGOW];
    double sredniCzas=0;
    int liczbaBledow[LICZBAPRZEBIEGOW];
    int sumaBledow=0;
        oblicz liczydlo;  //obiekt zawierajacy dane i przeprowadzajacy test
        void test();
         wykonajEksperyment();
        ~wykonajEksperyment();
    dane wyniki;


    protected:
    private:
};
    void wygenerujDaneTestowe(const int ILOSCDANYCH=10);
#endif // WYKONAJEKSPERYMENT_H
