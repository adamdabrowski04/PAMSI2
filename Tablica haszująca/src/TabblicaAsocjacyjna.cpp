#ifndef TABBLICAASOCJACYJNA_CPP
#define TABBLICAASOCJACYJNA_CPP
#include "../include/TabblicaAsocjacyjna.h"
#include "../src/Element.cpp"
#include <cmath>
#include<cstring>
using namespace std;
template<class TYP_KLUCZ, class TYP_WARTOSC>
Tablica_Haszujaca<TYP_KLUCZ, TYP_WARTOSC>::Tablica_Haszujaca(unsigned long int liczba_elementow)
{
    const unsigned long int tab_liczb_pierwszych[]={53, 97, 193, 389, 769, 1543, 3079, 6151, 12289, 24593, 49157, 98317,
                                    196613, 393241, 786433, 1572869, 3145739, 6291469, 12582917, 25165843,
                                    50331653, 100663319, 201326611, 402653189, 805306457, 1610612741 };
    if(liczba_elementow>1610612741&&tablica_list.max_size() >1610612741)
        rozmiar_tablicy=1610612741;
    else
    {   rozmiar_tablicy=tab_liczb_pierwszych[0];
        for(unsigned int i =0; liczba_elementow>tab_liczb_pierwszych[i]&&tablica_list.max_size() >tab_liczb_pierwszych[i+1]; i++)
        {
            rozmiar_tablicy=tab_liczb_pierwszych[i+1]; ///TODO(1#Adam#) poprawic zam maly rozmiar tablicy
        }
    }

    tablica_list.resize(rozmiar_tablicy);

}

template<class TYP_KLUCZ, class TYP_WARTOSC>
Tablica_Haszujaca<TYP_KLUCZ, TYP_WARTOSC>::~Tablica_Haszujaca()
{
    //dtor
}
template<class TYP_KLUCZ, class TYP_WARTOSC>
unsigned int Tablica_Haszujaca<TYP_KLUCZ, TYP_WARTOSC>::FunkcjaHaszujaca(string klucz)
{
    unsigned const int k=2;
    char *tab= new char[klucz.length()];
    strcpy(tab, klucz.c_str() );
    unsigned long int suma=0;
    for(unsigned int i=0; i<(unsigned int)klucz.length(); i++ )
        suma += tab[i]*pow(k, klucz.length()-1-i);
    return suma%rozmiar_tablicy;
}


template<class TYP_KLUCZ, class TYP_WARTOSC>
void Tablica_Haszujaca<TYP_KLUCZ, TYP_WARTOSC>::Dodaj(string Klucz, TYP_WARTOSC Element )
{

    (tablica_list[FunkcjaHaszujaca(Klucz)]).push_back(Klucz_i_Element<TYP_KLUCZ, TYP_WARTOSC>(Klucz,Element));
}

template<class TYP_KLUCZ, class TYP_WARTOSC>
bool Tablica_Haszujaca<TYP_KLUCZ, TYP_WARTOSC>::Usun(string Klucz)
{

    for( typename list<Klucz_i_Element<TYP_KLUCZ, TYP_WARTOSC> >::iterator it=(tablica_list[FunkcjaHaszujaca(Klucz)]).begin();
            it!=(tablica_list[FunkcjaHaszujaca(Klucz)]).end();it++)
    {

        if( (*it).Klucz==Klucz )
        {
            (tablica_list[FunkcjaHaszujaca(Klucz)]).erase(it);
            return true;
        }
    }
    cerr<<"Element o podanym kluczu nie istnieje"<<endl;
    return false;
}
template<class TYP_KLUCZ, class TYP_WARTOSC>
TYP_WARTOSC Tablica_Haszujaca<TYP_KLUCZ, TYP_WARTOSC>::Pobierz(string Klucz)
{
    for( typename list<Klucz_i_Element<TYP_KLUCZ, TYP_WARTOSC> >::iterator it=(tablica_list[FunkcjaHaszujaca(Klucz)]).begin();
            it!=(tablica_list[FunkcjaHaszujaca(Klucz)]).end();it++)
    {
        if( (*it).Klucz==Klucz )
        {
            return (*it).Element;
        }
    }
    cerr<<"Element o podanym kluczu nie istnieje"<<endl;
    throw 1;
}

template<class TYP_KLUCZ, class TYP_WARTOSC>
bool Tablica_Haszujaca<TYP_KLUCZ, TYP_WARTOSC>::CzyPusta()
{
    return tablica_list.empty();

}
template<class TYP_KLUCZ, class TYP_WARTOSC>
int Tablica_Haszujaca<TYP_KLUCZ, TYP_WARTOSC>::ZliczElementy()
{
    return tablica_list.size();
}
//int Zlicz_Elementy();
#endif
