#include "../include/TabblicaAsocjacyjna.h"
#include "../src/Element.cpp"
using namespace std;
template<class TYP_KLUCZ, class TYP_WARTOSC>
Tablica_Asocjacyjna<TYP_KLUCZ, TYP_WARTOSC>::Tablica_Asocjacyjna()
{
    //ctor
}
template<class TYP_KLUCZ, class TYP_WARTOSC>
Tablica_Asocjacyjna<TYP_KLUCZ, TYP_WARTOSC>::~Tablica_Asocjacyjna()
{
    //dtor
}

template<class TYP_KLUCZ, class TYP_WARTOSC>
void Tablica_Asocjacyjna<TYP_KLUCZ, TYP_WARTOSC>::Dodaj(TYP_KLUCZ Klucz, TYP_WARTOSC Element )
{
    Lista.push_back(Klucz_i_Element<TYP_KLUCZ, TYP_WARTOSC>(Klucz,Element));
}

template<class TYP_KLUCZ, class TYP_WARTOSC>
bool Tablica_Asocjacyjna<TYP_KLUCZ, TYP_WARTOSC>::Usun(TYP_KLUCZ Klucz)
{
    for( typename vector<Klucz_i_Element<TYP_KLUCZ, TYP_WARTOSC> >::iterator it=Lista.begin();it!=Lista.end();it++)
    {
        if( (*it).Klucz==Klucz )
        {
            Lista.erase(it);
            return true;
        }
    }
    return false;
}
template<class TYP_KLUCZ, class TYP_WARTOSC>
TYP_WARTOSC Tablica_Asocjacyjna<TYP_KLUCZ, TYP_WARTOSC>::Pobierz(TYP_KLUCZ Klucz)
{
    for( typename vector<Klucz_i_Element<TYP_KLUCZ, TYP_WARTOSC> >::iterator it=Lista.begin();it!=Lista.end();it++)
    {
        if( (*it).Klucz==Klucz )
        {
            return (*it).Element;
        }
    }
    throw 1;
}

template<class TYP_KLUCZ, class TYP_WARTOSC>
bool Tablica_Asocjacyjna<TYP_KLUCZ, TYP_WARTOSC>::Czy_Pusta()
{
    return Lista.empty();

}
template<class TYP_KLUCZ, class TYP_WARTOSC>
int Tablica_Asocjacyjna<TYP_KLUCZ, TYP_WARTOSC>::Zlicz_Elementy()
{
    return Lista.size();
}
//int Zlicz_Elementy();
