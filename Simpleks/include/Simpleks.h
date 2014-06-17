#ifndef SIMPLEKS_H
#define SIMPLEKS_H
#include<vector>
  const int ROZMIAR_M=4;
  const int ROZMIAR_N=4;
class Simpleks
{
  public:
  double A[ROZMIAR_M][ROZMIAR_N];
  int N[ROZMIAR_N];
  int B[ROZMIAR_M];
  double wyrazy_wolne[ROZMIAR_M+ROZMIAR_N];
  double c[ROZMIAR_M+ROZMIAR_N];
  double v=0;
  double delta[ROZMIAR_M+ROZMIAR_N];
  double wyniki[ROZMIAR_M+ROZMIAR_N];
  int e,l;
  void Oblicz();
    Simpleks();
    ~Simpleks();
  bool czy_jest_dodatnie_c();
  int indeks_dodatniego_c();
  void Pivot(Simpleks stary);
  protected:

  private:

};

#endif // SIMPLEKS_H
