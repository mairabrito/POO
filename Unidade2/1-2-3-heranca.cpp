/**
 * 1. Rode e analise o código de EXEMPLO SIMPLES DE HERANÇA (Classes X, Y e Z) do material. ok 
 * 2. Comente qual foi seu entendimento linha por linha em relação a comportamento com herança e acesso aos dados e membros. Analise de quem são as funções membros chamadas por cada objeto e porque é possível fazer. Quando não é possível? ok 
 * 3. Qual foi a Herança (esquema final) entre as diferentes classes? Explique com comentarios no final deste código. Salve este código inicial numa primeira versão.
*/

#include <iostream>

using namespace std;
  
// Declaração da classe base
class X {
protected:
   int i; // membro protegidos
   int j; // membro protegidos
public:
   void get_ij(void); // método público 
   void put_ij(void); // método público 
};

/* Declaração da classe derivada; 
 * Em Y, i e j de X tornam-se membros protegidos;
 * Y herda os métodos get_ij e put_ij de X também como métodos públicos
*/
class  Y: public  X  { 
   int k; //membro privado
public:
   int get_k(void); //método público
   void make_k(void);//método público
};


/* Declaração da classe derivada; 
 * Em Z, i e j de X tornam-se membros protegidos;
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

/* 3)X é a classe base.
 * Y é uma classe derivada de X, logo herda todos os dados públicos e protegidos contidos em X; 
 * Os dados protegidos em X se tornam protegidos em Y. Assim com os dados públicos em X, se torna públicos em Y.
 * Z é uma classe derivada de Y, logo herda todos os dados públicos e protegidos contidos em Y, mas não o dado privado; 
*/








