#include "../include/TabblicaAsocjacyjna.h"
using namespace std;
template<class TYP>
Tablica_Asocjacyjna<TYP>::Tablica_Asocjacyjna()
{
    //ctor
}
template<class TYP>
Tablica_Asocjacyjna<TYP>::~Tablica_Asocjacyjna()
{
    //dtor
}

template<class TYP>
void Tablica_Asocjacyjna<TYP>::Dodaj(int Klucz, TYP Element )
{
    Lista.push_front(Klucz_i_Element<TYP>(Klucz,Element));

}

template<class TYP>
bool Tablica_Asocjacyjna<TYP>::Usun(int Klucz)
{

    for(list<Klucz_i_Element<TYP> >::iterator it=Lista.begin();it!=Lista.end();it++)
    {
        if( (*it).Klucz==Klucz )
        {
            Lista.pop(it);
            return true;
        }
    }
    return false;
}
template<class TYP>
TYP Tablica_Asocjacyjna<TYP>::Pobierz(int Klucz)
{
    for(list<Klucz_i_Element<TYP> >::iterator it=Lista.begin();it!=Lista.end();it++)
    {
        if( (*it).Klucz==Klucz )
        {
            return (*it).Element;
        }
    }
    throw 1;
}

template<class TYP>
bool Tablica_Asocjacyjna<TYP>::Czy_Pusta()
{
    return Lista.empty();

}

int Tablica_Asocjacyjna<TYP>::Zlicz_Elementy()
{
    return Lista.size();
}
//int Zlicz_Elementy();
