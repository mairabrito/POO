#include <iostream>

using namespace std;

const int TAM = 80;
class BasAg
{
protected:
    char nome[TAM];
    char numag[4];

public:
    BasAg() //construtor sem parametros 
    {
        nome[0] = '\0';
        numag[0] = '\0';
    }
    BasAg(char n[], char ng[]) {} //construtor com parametros
    void print() {cout << "teste - ";} //método-membro
};

class Agente : public BasAg // herança ou classe derivada
{
protected:
    float altura;
    int idade;

public:
    Agente() : BasAg()
    {
        altura = 0;
        idade = 0;
    }
    Agente(char n[], char ng[], float a, int i) : BasAg(n, ng)
    {
        altura = a;
        idade = i;
        
    }
    void print()
    {
        BasAg::print();
        cout << idade << endl;
    }
};

int main()
{
    Agente agente("Daniel", "1", 1.78, 21);
    agente.print(); 

    return 0;
}

/**
 * A classe Agente é derivda da classe BasAg. O método print é reescrito na classe derivada para chamar o método print da classe base e imprimir o valor da idade;
*/