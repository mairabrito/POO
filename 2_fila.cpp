#include <iostream>
using namespace std;

// criacao da classe fila
class fila 
{
    int q[100];
    int sloc, rloc;
public:
    void init(void);
    void qput(int i);
    int qget(void);

    bool filaVazia(void);
    bool filaCheia(void);
};

void fila::init (void)
{
    rloc = sloc = 0;
}

void fila::qput (int i)
{
    if (sloc==100)
    {
        cout << "a fila está cheia" << endl;
        return;
    }
    sloc++;
    q[sloc] = i;
}

int fila::qget (void)
{
    if(rloc==sloc)
    {
        cout << "fila sem elementos" << endl;
        return 0;
    }
    rloc++;
    return q [rloc];
}

bool fila::filaVazia(void)
{
    if (sloc <= 0)
    {
        return true;
    }
    return false;
}

bool fila::filaCheia(void)
{
    if (sloc == 100)
    {
        return true;
    }
    return false;
}

int main ()
{
    fila a, b; // criando dois objetos de tipo fila

    a.init();
    b.init();

    a.qput(10);
    b.qput(19);

    a.qput(20);
    b.qput(1);

    cout << "elementos de a : ";
    cout << a.qget() << "   ";
    cout << a.qget () << "\n";

    cout << "elementos de b : ";
    cout << b.qget() << "   ";
    cout << b.qget () << "\n";

    fila c;

    c.init();

    // Exercício 1, fila vazia, retornando mensagem de que a fila não tem
    // nenhum elemento.
    c.qget(); 
    // Exercício 1, fila cheia, adicionando 101 elementos a uma fila
    // que deveria conter no máximo 100 elementos, retornando mensagem
    // de que a fila está cheia na situação em que i for 101!
    for (int i = 1; i <= 101; i++) {
        c.qput(i);
    }
    // Exercício 2, 2.1, 2.2
    // A solução para o subitem 1 está presente na linha 45.
    // A solução para o subitem 2 está presente na linha 54.

    return 0;
}


