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
     * Wylicza indeks tablicy na podstawie klucza
     *
     *Zwracane Wartośći:
     *Indeks tablicy
     */
    unsigned int FunkcjaHaszujaca(string);

    /*!
     *\brief Dodaje element do tablicy
     *
     *PRzyjmowane argumenty:
     * argument1 - klucz
     * argument2 - element do dodania
     *
     *Warunki wtępne:
     *BRAK
     *
     *Warunki końcowe:
     * Dodaje element do tablicy haszującej
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
     *false - w przypadku porażki(brak elementu tego typu)
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
     *Zwraca element z podanymdanym kluczu
     ***UWAGA*** nie usuwa tego elementu z tablicy
     *
     *Zwracane Wartośći:
     *Elemnt o podanym kluczu
     */
    TYP_WARTOSC Pobierz(string);


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

        Tablica_Haszujaca(unsigned long int liczba_elementow);
        ~Tablica_Haszujaca();
    protected:

    private:
};
#endif // TABBLICAASOCJACYJNA_H
