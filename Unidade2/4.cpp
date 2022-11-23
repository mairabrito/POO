/**
 * 4. Rode uma copia do código (segunda versão) tirando (com comentarios (//)) protected em X. Que acontece e porque? Explique com comentarios.
*/

/* - Se tirar o protected em X, o código não vai funcionar pois os métodos get_ij e put_ij necessitam das 
 * variáveis i e j inicializadas no protected;
*/

#include <iostream>

using namespace std;
  
// Declaração da classe base
class X {
//protected:
//   int i; // membro protegidos
 //  int j; // membro protegidos
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