#ifndef OBLICZ_H
#define OBLICZ_H

/*!
 *\file
 *\brief Plik zawiera definicję klasy dane i jej metod składowych
 *
 *Klasa modeluje obiekt w którym przechowuje dane.
 *Zawiera wskaźnik do dynamicznej tablicy typu int i
 *dwie zmienne mówiące o liczbie danych i wielkości tablicy
 *
 */

#include<iostream>
#include<string>
#include<chrono>
#include<fstream>
#include "../include/dane.h"
class oblicz
{

        public:
//        unsigned int rozmiarTablicy;
//        unsigned int liczbaDanych;
        unsigned int liczbaBledow;
        dane TabWyliczona;
        dane TabDanych;
        dane TabSprawdzenie;

        oblicz();
        ~oblicz();

        /*!
         * \brief Wykonuje odpowiednie operacje na danych wejśćiowych
         *
         * Funkcja składowa klasu oblicz, która jest implementacją aktualnie badanego algorytmu.
         */
        double wykonajObliczenia();
        /*!
         * \brief Wykonuje sprawdzenie.
         *
         * Funkcja składowa klasu oblicz, wykonuje sprawdzenie porównując dane wynikowe z dostarczonymi danymi testowymi.
         */
        unsigned int wykonajSprawdzenie();
       /*!
         * \brief Wczytuje dane.
         *
         * Funkcja składowa klasu oblicz, która wczytuje dane do tablicy.
         */

        void dodajElementy(dane tab1, dane tab2);


        /*!
         * \brief Dodaje do tablic elementy.
         *
         * Funkcja składowa klasu oblicz, która dodaje do dwóch różnych tablic podane elementy.
         */
         void dodajElementy(dane tab1, dane tab2, int element1, int element2);


    protected:
    private:
};

#endif // OBLICZ_H
