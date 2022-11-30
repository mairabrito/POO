/**
 * 9. Reescreva alguma função membro de alguma classe base na classe derivada e chame esta função no programa principal. Tente manter uma lógica do seu programa.
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
    void put_ij(void); // método público
};

/* Declaração da classe derivada;
 * Em Y, i e j de X tornam-se membros protegidos;
 * Y herda os métodos get_ij e put_ij de X também como métodos públicos
 */
class Y : public X
{

public:
    int k;             // Mudando para membro publico para Z ter acesso
    int get_k(void);   // método público
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
    void f(void); // método público
    void make_k(void)
    {
        Y::make_k();
        k = i / j;
    };
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

    var2.get_ij();
    var2.put_ij();
    var2.make_k();
    cout << var2.get_k();
    cout << "\n";

    return 0;
}
