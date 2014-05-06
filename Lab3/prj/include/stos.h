#ifndef DANE_H
#define DANE_H
/*!
 *\file
 *\brief Plik zawiera definicję szablonu klasy stos i jej metod składowych
 *
 *Klasa modeluje stos w oparciu o tablicę w którym przechowuje dane .
 *Zawiera wskaźnik do dynamicznej tablicy typu int i
 *dwie zmienne mówiące o liczbie danych i wielkości tablicy
 *
 */
#include<iostream>



template<class TYP>
class stos
{
    public:
    enum typPowiekszania{o1, x2};


        /*!
         *\brief Kładzie kolejny element na stos
         *
         * Kładzie nowy element na stot jezeli
         * zachodzi taka koniecznosc zwieksza rozmiar tablicy
         */
    void PUSH( TYP );

        /*!
         *\brief Zdejmuje element ze stosu
         *
         * Zdejmuje element ze stosu jeżeli zachodzi taka potrzeba zmniejsza stos
         */
    TYP POP();

        /*!
         * \brief Wypisuje wszystkie elementy tablicy.
         *
         * Funkcja składowa klasu oblicz, która zamienia miejscami i-ty element tablicy z j-tym
         */
    void wypiszTablice();

    unsigned int size();
        stos();
        ~stos();
    protected:
    private:
        TYP *pTab;
        unsigned int liczbaDanych;
        bool zmniejszTab();
        void powiekszTab(typPowiekszania);
        unsigned int rozmiarTablicy;

};

#endif // DANE_H
