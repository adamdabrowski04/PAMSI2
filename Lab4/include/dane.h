#ifndef DANE_H
#define DANE_H
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
#include<iomanip>
#include<fstream>
using namespace std;
class dane
{
    public:
    int *pTab;
    unsigned int liczbaDanych;

    void heapSort(void);
    void bubbleSort();
    void quickSort(int p, int r);

    /*!
         *\brief Dodaje nowy element w przypadku jezeli
         *       zachodzi taka koniecznosc zwieksza rozmiar tablicy
         */
    void dodajElement( int nowy);
 void powiekszTab();



        /*!
         *\brief Wczytuje elementy do tablicy
         *
         *ARGUMENTY: nazwaPliku-nazwa pliku z którego wczytujemy dane
         */
   void wczytaj(char *nazwaPliku);

        /*!
         * \brief Zamienia miejscami i-ty element tablicy z j-tym
         *
         * Funkcja składowa klasu oblicz, która zamienia miejscami i-ty element tablicy z j-tym
         */
    bool zamienElementy( unsigned int i, unsigned int j);

        /*!
         * \brief Odwraca tablicę
         *
         * Funkcja składowa klasu oblicz, która odwraca miejscami wszystkie elementy
         */
    void odwrocTablice();

        /*!
         *\brief Porównuje elementy tablic.
         *
         * Funkcja składowa klasy oblicz, która po srpawdzeniu czy zgadza się długość tablic porównuje ich elementy.
         */
    bool operator==(dane)const;

        /*!
         *\brief Przepisuje elementy jednej tablicy do drugiej
         *
         * Funkcja składowa klasy oblicz, która przepisuje elementy jednej tablicy do drugiej.
         */
    dane& operator=(dane&tab);

        dane();
        ~dane();
    protected:
    private:

    unsigned int parent(unsigned int i);
    unsigned int left(unsigned int i);
    unsigned int right(unsigned int i);
    void maxHeapify(unsigned int i);
    void buildMaxHeap(void);

    int partition(int p, int r);
    unsigned int rozmiarTablicy;

};
    /*!
         * \brief Wypisuje wszystkie elementy tablicy.
         *
         * Funkcja składowa klasu oblicz, która zamienia miejscami i-ty element tablicy z j-tym
         */


    ostream& operator<<(ostream & strmWy,dane& a);
#endif // DANE_H
