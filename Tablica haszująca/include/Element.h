#ifndef ELEMENT_H
#define ELEMENT_H

template<class TYP_KLUCZ, class TYP_WARTOSC>
class Klucz_i_Element
{
    public:
    TYP_KLUCZ Klucz;
    TYP_WARTOSC Element;
        Klucz_i_Element(TYP_KLUCZ Klucz, TYP_WARTOSC Element);
         ~Klucz_i_Element();
    protected:
    private:
};

#endif // ELEMENT_H
