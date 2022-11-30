#include <iostream>

using namespace std;

class base
{
public:
    // construtores e destrutor da classe base
    base()
    {
        cout << "\n base criada\n";
    }
    base(char n[], int i) {}
    ~base() { cout << "base destruida \n\n"; }
};

// classe derivada da classe base
class D_class1 : public base
{
protected:
    string nome;
    string cargo;
    int idade;

public:
    // construtores e destrutor da classe derivada 1
    D_class1()
    {
        cout << "D_class1 criada \n";
    }
    D_class1(char n[], int i, string c="estudante") : base(n, i)
    {
        nome = n;
        idade = i;
        cargo = c;
    }

    void print()
    {
        cout << "Nome: " << nome << endl;
        cout << "Idade: " << idade << endl;
        cout << "Cargo: " << cargo << endl;
    }

    ~D_class1() { cout << "D_class1 destruida\n"; };
};

// classe derivada da classe D_class1
class D_class2 : public D_class1
{
public:
    float salario;
    // construtores e destrutor da classe derivada 2
    D_class2() { cout << "D_class2 criada \n"; };
    D_class2(char n[], int i, float s, string c="Estudante") : D_class1(n,i,c){
        salario = s;
    };
    ~D_class2() { cout << "D_class2 destruida\n"; };
    void print(){
        D_class1::print();
        cout << "Salário: " << salario << endl;
    }
};
int main()
{

    D_class1 D1("Maíra", 25);
    D1.print();
    cout << endl;

    D_class2 D2("Brito", 22, 3599.9, "Dev");
    D2.print();

    cout << "\n";
   

    return 0;
}

/**
 * Acrescentei contrutor com parametros na classe base e nas classes derivadas D_class1 e D_class2;
 * Na classe D_class1 acrescentei um protected com 3 variáveis para ajudar no exemplo do construtor com parametros.
 * Na class D_class2 além de herda as variáveis de D_class1, acresentei mais uma para compor e também reescrevi a função print();
*/