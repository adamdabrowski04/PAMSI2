#include <iostream>
#include "../include/Graf.h"

using namespace std;

int main()
{
    Graf przyklad;
    przyklad.DodajWierzcholek("r");
    przyklad.DodajWierzcholek("s");
    przyklad.DodajWierzcholek("t");
    przyklad.DodajWierzcholek("u");
    przyklad.DodajWierzcholek("v");
    przyklad.DodajWierzcholek("w");
    przyklad.DodajWierzcholek("x");
    przyklad.DodajWierzcholek("y");
    przyklad.DodajKrawedz("v","r");
    przyklad.DodajKrawedz("s","r");
    przyklad.DodajKrawedz("w","s");
    przyklad.DodajKrawedz("w","t");
    przyklad.DodajKrawedz("w","x");
    przyklad.DodajKrawedz("t","u");
    przyklad.DodajKrawedz("x","u");
    przyklad.DodajKrawedz("x","y");
    przyklad.DodajKrawedz("u","y");
    przyklad.BFS("s");
    cout << "Hello world!" << endl;
    char a;
    cin>>a;
    return 0;
}
