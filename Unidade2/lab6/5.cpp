/**
 * 5. Adicione e teste agora colocando public. Quem consegue agora usar estes dados diferentemente do código anterior que usava protected, explique e mostre com exemplos.
*/

/* - Adicionando novamente e testando com public, vai funcionar normalmente.
 * A única diferença é que nas classes derivadas os dados que antes eram protegidos, agora são públicos.
*/

#include <iostream>

using namespace std;
  
// Declaração da classe base
class X {
public:
   int i; // membro público
   int j; // membro público

   void get_ij(void); // método público 
   void put_ij(void); // método público 
};

/* Declaração da classe derivada; 
 * Em Y, i e j de X tornam-se membros público;
 * Y herda os métodos get_ij e put_ij de X também como métodos públicos
*/
class  Y: public  X  { 
   int k; //membro privado
public:
   int get_k(void); //método público
   void make_k(void);//método público
};


/* Declaração da classe derivada; 
 * Em Z, i e j de X tornam-se membros público;
 * Z herda os métodos get_ij e put_ij de X também como métodos públicos;
 * Mas não herda k de Y, ja que ele é privado por definicão
*/
class Z:public Y { 
public:
   void f(void);//método público
};

void X::get_ij(void)
{
  cout << "Informe dois numeros: ";
  cin >> i  >> j;
}

void X::put_ij(void)
{
  cout << i  << " " << j << "\n";
}

int Y::get_k(void)
{
  return k;
}
void Y::make_k(void)
{
  k=i*j;
}
void Z::f(void)
{
  i = 2;
  j = 3;
}

int main( )
{

  Y var;
  Z var2;

  var.get_ij();
  var.put_ij();
  var.make_k();
  cout << var.get_k();
  cout << "\n";

  var2.f();
  var2.put_ij();

  return 0;
}