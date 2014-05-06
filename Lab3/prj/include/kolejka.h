#ifndef KOLEJKA_H
#define KOLEJKA_H
/*!
 *\file
 *\brief Plik zawiera definicję szablonu klasy kolejka i jej metod składowych
 *
 *Klasa modeluje kolejkę w oparciu o tablicę w której przechowuje dane .
 *Zawiera wskaźnik do dynamicznej tablicy typu wybranego przez użytkowniak i
 *dwie zmienne mówiące o liczbie danych i wielkości tablicy
 *
 */



template<class TYP>
class kolejka
{
enum typPowiekszania{o1, x2};
    TYP *pTab;
    unsigned int liczbaDanych;
    public:
        /*!
         * \brief Dodaje element do kolejki
         *
         * Dodaje element do kolejki w przypadku kiedy jest pełna przesuwa wszystkie elementy na sam dół tablicy,
         * jeżeli jest to niemożliwe zwiększa rozmiar tablicy
         *
         */
        void enqueue(TYP);
        /*!
         *\brief Zbiera element z kolejki
         *
         * Zabier element z koleiki zakładamy, że kolejka nie jest pusta
         */
        TYP dequeue(void);
 void wypiszTablice(void);
        kolejka();
        ~kolejka();
    protected:
    private:
        /*!
         * Zmniejsza rozmiar tablicy o połowę
         *
         */
        bool zmniejszTab();
        /*!
         * Zwiększa rozmiar tablicy o dwukrotnie
         *
         */
        void powiekszTab(typPowiekszania);
        /*!
         * Przesuwa wszystkie elementy na sam dół koleiki
         *
         */
        void przesunElementy(void);


        unsigned int rozmiarTablicy;
        unsigned int iloscZdjetych;

};

#endif // KOLEJKA_H
