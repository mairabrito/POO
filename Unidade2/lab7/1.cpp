#include <iostream>

using namespace std;

class base
{
public:
    // construtor e destrutor da classe base
    base() { cout << "\n base criada\n"; }
    ~base() { cout << "base destruida \n\n"; }
};

// classe derivada da classe base
class D_class1 : public base
{
public:
    // construtor e destrutor da classe derivada 1
    D_class1() { cout << "D_class1 criada \n"; }
    ~D_class1() { cout << "D_class1 destruida\n"; };
};

// classe derivada da classe D_class1
class D_class2 : public D_class1
{
public:
    // construtor e destrutor da classe derivada 2
    D_class2() { cout << "D_class2 criada \n"; }
    ~D_class2() { cout << "D_class2 destruida\n"; };
};
int main()
{

    D_class1 d1;
    D_class2 d2;

    cout << "\n";

    return 0;
}

/*Para o primeiro objeto, é invocado o construtor da classe base, e só depois o construtor da classe derivada D_class1.
 *Para o segundo objeto, é incado o construtor da classe base, o construtor da classe D_class1 e só depois o construtor da classe  D_class2.
 * Por fim, para o segundo obj, é invocado o destrutor da classe D_class2, em seguinda o da classe o destrutor da classe D_class1 e só depois o destrutor da classe base.
 * Para o primeiro obj, é invocado o destrutor da classe D_class1 e em seguinda o destrutor da classe base.
 */