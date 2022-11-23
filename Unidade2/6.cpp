/**
 * 6. Salve a versão anterior. Mude agora no código inicial o tipo de acesso da Herança na DEFINIÇÂO da classe Y: "class  Y : public X"  (para protected e privado) e rode novamente. Que acontece em cada caso?  Explique. Mantenha os acessos e mude os lugares no código para que consiga rodar. Pode mostrar exemplos.
 */

/**
 * - A princípio não vai funcionar. Para que funcione, é necessário reescrever as funções-membro da classe base(X) na classe derivada (Y), tanto para o acesso protected quanto para o private. No private se faz necessário tbm reescrever as variáveis i e j.
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
  void get_ij(void); // função-membro
  void put_ij(void); // função-membro
};

class Y : protected X
{
  int k; // membro privado

public:
  //X::i; // para o acesso private
  //X::j; // para o acesso private
  int get_k(void);   // método público
  void make_k(void); // método público
  void get_ij(void) { X::get_ij(); }; // para o acesso private e protected
  void put_ij(void) { X::put_ij(); }; // para o acesso private e protected
};


class Z : public Y
{
public:
  void f(void); // método público
};

void X::get_ij(void)
{
  cout << "Informe dois numeros: ";
  cin >> i >> j;
}

void X::put_ij(void)
{
  cout << i << " " << j << "\n";
}

int Y::get_k(void)
{
  return k;
}
void Y::make_k(void)
{
  k = i * j;
}
void Z::f(void)
{
  i = 2;
  j = 3;
}

int main()
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
