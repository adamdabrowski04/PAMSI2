#ifndef ELEMENT_H
#define ELEMENT_H

template<class TYP>
class Klucz_i_Element
{
    public:
    TYP Element;
    int Klucz;
        Klucz_i_Element(int Klucz, TYP Element);
         ~Klucz_i_Element();
    protected:
    private:
};

#endif // ELEMENT_H
