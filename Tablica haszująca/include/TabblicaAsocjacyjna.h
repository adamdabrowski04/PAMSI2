#ifndef TABBLICAASOCJACYJNA_H
#define TABBLICAASOCJACYJNA_H
#include<list>
#include<vector>
#include<iostream>
#include "../include/Element.h"

using namespace std;

template<class TYP_KLUCZ, class TYP_WARTOSC>
class Tablica_Haszujaca
{
    public:
    vector<  list< Klucz_i_Element<TYP_KLUCZ, TYP_WARTOSC> >  > tablica_list;

    unsigned long int rozmiar_tablicy;


    /*!
     *\brief Wylicza indeks tablicy na podstawie klucza
     *
     *PRzyjmowane argumenty:
     * argument1 - klucz
     *
     *Warunki wtępne:
     *BRAK
     *
     *Warunki końcowe:
     * Dodaje element do tablicy asocjacyjnej, w przypadku kiedy jest już w niej
     * element o takim kluczu zastępuje go tym, który chcemy dodać
     *
     *Zwracane Wartośći:
     *BRAK
     */
    unsigned int FunkcjaHaszujaca(string);

    /*!
     *\brief Dodaje element do listy
     *
     *PRzyjmowane argumenty:
     * argument1 - klucz będący wartośćią typu int
     * argument2 - element tablicy asocjacyjnej
     *
     *Warunki wtępne:
     *BRAK
     *
     *Warunki końcowe:
     * Dodaje element do tablicy asocjacyjnej, w przypadku kiedy jest już w niej
     * element o takim kluczu zastępuje go tym, który chcemy dodać
     *
     *Zwracane Wartośći:
     *BRAK
     */
    void Dodaj(string, TYP_WARTOSC );

    /*!
     *\brief Usuwa element o danym kluczu
     *
     *Przyjmowane argumenty:
     * argument1 - klucz obiektu do usunięcia
     *
     *Warunki wtępne:
     *BRAK
     *
     *Warunki końcowe:
     *Usuwa element o podanym kluczu z tablicy asocjacyjnej
     *
     *Zwracane Wartośći:
     *true- w przypadku powodzenia
     *false - w przypadku porażki
     */
    bool Usun(string);

    /*!
     *\brief Zwraca element o podanym kluczu
     *
     *Przyjmowane argumenty:
     * argument1 - klucz obiektu kóry chcemy pobrać
     *
     *Warunki wtępne:
     *musi istnieć element o podanym kluczu
     *
     *Warunki końcowe:
     *Zwraca element z podanymdanym kluczu z tablicy asocjacyjnej
     ***UWAGA*** nie usuwa tego elementu z tablicy
     *
     *Zwracane Wartośći:
     *Elemnt o podanym klluczu
     */
    TYP_WARTOSC Pobierz(TYP_KLUCZ);


    /*!
     *\brief Sprawdza czy tablica jest pusta
     *
     *Przyjmowane argumenty:
     *BRAK
     *
     *Warunki wtępne:
     *BRAK
     *
     *Warunki końcowe:
     *Sprawdza czy tablica jest pusta
     *
     *Zwracane Wartośći:
     *true - pusta tablica
     *false- w tbalicy jest przynajmniej jeden elemtn
     */
    bool CzyPusta(void);
    /*!
     *\brief Liczy ile jest elemntow w tablicy
     *
     *Przyjmowane argumenty:
     *BRAK
     *
     *Warunki wtępne:
     *BRAK
     *
     *Warunki końcowe:
     *Sprawdza ile w tablicy jest elemntow
     *
     *Zwracane Wartośći:
     * liczba elemntow w tablicy
     */
    int ZliczElementy();
    //TODO (adam#5#)    iterator



        Tablica_Haszujaca(unsigned long int liczba_elementow);
        ~Tablica_Haszujaca();
    protected:

    private:
};

#endif // TABBLICAASOCJACYJNA_H
