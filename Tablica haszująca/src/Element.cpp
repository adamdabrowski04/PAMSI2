#include "../include/Element.h"
#ifndef ELEMENT_CPP
#define ELEMENT_CPP
template<class TYP_KLUCZ, class TYP_WARTOSC>
Klucz_i_Element<TYP_KLUCZ,TYP_WARTOSC >::Klucz_i_Element(TYP_KLUCZ Klucz,TYP_WARTOSC Element):Klucz(Klucz), Element(Element)
{
    ;
}
template<class TYP_KLUCZ, class TYP_WARTOSC>
Klucz_i_Element<TYP_KLUCZ, TYP_WARTOSC>::~Klucz_i_Element()
{
    //dtor
}


#endif
