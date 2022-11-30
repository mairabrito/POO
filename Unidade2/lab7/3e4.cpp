#include <iostream>

using namespace std;

class base1
{
public:

    string nome;

    base1()
    {
        cout << "base1 criada\n";
    }
    base1(string n){
        nome = n;
    }
    ~base1()
    {
        cout << "base1 destruida \n\n";
    }
    void print(){
        cout << "Nome: " << nome << endl;
    }
};

class base2
{
public:
    int idade;

    base2()
    {
        cout << "base2 criada\n";
    }
    base2(int i){
        idade = i;
    }
    ~base2()
    {
        cout << "base2 destruida \n\n";
    }
    void print(){
        cout << "Idade: " << idade << endl;
    }
};

class D_class1 : public base1, public base2
{
public:
    string cargo;

    D_class1()
    {
        cout << "D_class1 criada \n";
    }
    D_class1(string n, int i, string c="estudante") : base1(n), base2(i){
        cargo = c;
    }
    ~D_class1()
    {
        cout << "D_class1 destruida\n";
    }
    void print(){
        base1::print();
        base2::print();
        cout << "Cargo: " << cargo << endl;
    }

    
};

int main()
{

    D_class1 d1("Maíra", 25, "dev");
    d1.print();
    cout << endl;

    return 0;
}

/**
 * A classe D_class1 é derivada tanto da classe base1 quanto da base2;
 * Acrescentei construtores nas classes bases e fiz a classe deriavada herdar os contrutores e acrescentei mais um parametro.
 * Add a função print em todas classes. Na classe derivada, reescrevi a função, invocando primeiro a função nas classes bases.
*/