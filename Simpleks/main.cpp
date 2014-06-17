#include <iostream>
#include "include/Simpleks.h"
using namespace std;

int main()
{
Simpleks AA;
AA.A[0][0]=1;
AA.A[0][1]=1;
AA.A[0][2]=3;

AA.A[1][0]=2;
AA.A[1][1]=2;
AA.A[1][2]=5;

AA.A[2][0]=4;
AA.A[2][1]=1;
AA.A[2][2]=2;




AA.wyrazy_wolne[0]=30;
AA.wyrazy_wolne[0]=24;
AA.wyrazy_wolne[0]=36;

AA.c[0]=3;
AA.c[1]=1;
AA.c[2]=2;

AA.N[0]=0;
AA.N[1]=1;
AA.N[2]=2;
AA.B[0]=3;
AA.B[1]=4;
AA.B[2]=5;
AA.Oblicz();

    cout << "Hello world!" << endl;
    return 0;
}
