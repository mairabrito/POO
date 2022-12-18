/**
 * 8. Mude também o programa principal para que se use esta chamada anterior seguindo uma lógica. Por exemplo: as classes podem ficar com a seguinte ideia: X leitura de dados, Y cálcula, Z mostra resultado.
 */

#include <iostream>

using namespace std;

// Declaração da classe base
class X
{
protected:
  int i; // membro protegidos
  int j; // membro protegidos
public:
  void get_ij(void); // método público
  //void put_ij(void); // método público
};

/* Declaração da classe derivada;
 * Em Y, i e j de X tornam-se membros protegidos;
 * Y herda os métodos get_ij e put_ij de X também como métodos públicos
 */
class Y : public X
{
public:
  int k;             // para a classe Z conseguir acessa k, foi necessário tornar o membro público
 // int get_k(void);   // método público
  void make_k(void); // método público
};

/* Declaração da classe derivada;
 * Em Z, i e j de X tornam-se membros protegidos;
 * Z herda os métodos get_ij e put_ij de X também como métodos públicos;
 * Mas não herda k de Y, ja que ele é privado por definicão
 */
class Z : public Y
{
public:
    int get_k(void); 
    void put_ij(void);
  //void f(void); // método público
};

void X::get_ij(void)
{
  cout << "Informe dois numeros: ";
  cin >> i >> j;
}

void Z::put_ij(void) // Mundando para a classe Z.
{
  cout << i << " " << j << "\n";
}

int Z::get_k(void) // Mundando para a classe Z.
{
  return k;
}
void Y::make_k(void)
{
  k = i * j;
}

//void Z::f(void) 
//{
  //cout << k; // imprimir o cálculo feito em Y
  // i = 2;
  // j = 3;
//}

int main()
{

  Y var;
  Z var2;

  // testes com a variável var2
  var2.get_ij();
  var2.put_ij();
  var2.make_k();
  cout << var2.get_k();
  cout << "\n";

  return 0;
}
