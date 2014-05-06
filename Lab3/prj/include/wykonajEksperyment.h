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


#include <iostream>
#include <fstream>
#include <string>
#include<chrono>
#include "../include/stos.h"
#include "../src/stos.cpp"
#include "../include/kolejka.h"
#include "../src/kolejka.cpp"



class wykonajEksperyment
{
    enum kolejkaCzyStos{KOLEJKA, STOS};
    public:
    const kolejkaCzyStos wyborPojemnika = KOLEJKA;
    const unsigned int  rozmiarTabIlosciDanych=5;
    const unsigned int liczbaWywolan=300;
    unsigned int *pTabIloscDanych;
    unsigned int *pTabCzasyKolejnychSeriiDanych;

    void test();

    /*!
     *\brief wywoluje kilkukrotnie funkcje badajaca czas trwania badanego algorytmu
     *
     *Wywoluje kilkukrotnie funkcje mierzaca czas trwania badanego algorytmu po czym zwraca sredni czas trwania
     *
     *ARGUMENTY: liczbaWywolan - liczba wywolan badanej funkcji( mierzony jest czas pojedynczego wywolania)
     *           iloscDanych   - ilosc danych kladzionych na stos\kolejke
     */
    unsigned int seriaPomiarow(unsigned int liczbaWywolan, unsigned int iloscDanych);
    /*!
     *\brief Wywałanie rozwiązania aktualnie badanego problemu
     *
     *PARAMETRY: liczbaDanych - liczba danych dla jakich badamy problem, w tym wypadku jest to liczba elementów kładzionych na stos lub kolejkę
     */
    void uruchomKolejka(unsigned int liczbaDanych);
        /*!
     *\brief Wywałanie rozwiązania aktualnie badanego problemu
     *
     *PARAMETRY: liczbaDanych - liczba danych dla jakich badamy problem, w tym wypadku jest to liczba elementów kładzionych na stos lub kolejkę
     */
    void uruchomStos(unsigned int liczbaDanych);
    /*!
     *
     * Alokuje pamiec i inicjalizuje tabelę pTabIloscDanych kolejnymi potęgami 10 przy czym pierwszy element=50
     *
     */
    wykonajEksperyment();
        ~wykonajEksperyment();
//    void wygenerujDaneTestowe();
    double zmierzCzasTrwania(unsigned int);

    protected:
    private:
};
template<class TYP>
TYP potega(TYP, unsigned int );
#endif // WYKONAJEKSPERYMENT_H
