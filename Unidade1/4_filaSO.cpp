#include <iostream>
using namespace std;
const int tamanho = 100;

// criacao da classe fila
class fila
{
    int q[tamanho];
    int sloc, rloc, auxiliar;

public:
    fila(void);  // Construtor
    //~fila(void); // Destrutor

    void qput(int i);
    int qget(void);
    bool filaVazia(void);
    bool filaCheia(void);
    void ImprimeFila(void);
    void operator++();
    void operator--();  


    //Função usando o operador binario, acrescenta um elemento rand(), no incio da fila, quando chamada. Na vida real, em uma fila é necessario colocar alguem que tenha prioridade na frente, ou seja, no inicio da fila. 
    fila operator+(){
    {
        sloc++;
        int indice = sloc;
        while (1 < indice) {
            q[indice] = q[indice-1];
            indice--;
        }
         auxiliar++;
        q[1] = rand();
    }
    };
};

//Função construtora
fila::fila(void)
{
    rloc = sloc = auxiliar = 0;
    cout << ">> Fila inicializada >> \n";
}

void fila::qput(int i) //acrescenta um elemento na fila
{
    if (sloc == tamanho)
    {
        cout << "\nA fila está cheia!" << endl;
    }
    else
    {
        sloc++;
        q[sloc] = i;
    }
}

int fila::qget(void) 
{
    if (rloc == sloc)
    {
        cout << "\nFila sem elementos!";
        return 0;
    }
    else
    {
        rloc++;
        return q[rloc];
    }
}

bool fila::filaVazia(void) //verificar se a fila está vazia
{
    if (sloc <= 0)
    {
        return true;
    }
    return false;
}

bool fila::filaCheia(void) //verificar se a fila está cheia
{
    if (sloc == tamanho)
    {
        return true;
    }
    return false;
}

void fila::ImprimeFila(void) // Função para imprimir todos os elementos da Fila
{
    cout << "\nElementos da Fila: [";
    for (int i = 1; i <= sloc; i++)
    {
        cout << q[i];
        if (i < sloc)
        {
            cout << ",";
        }
    }
    cout << "]";
}

void fila::operator++() // Função operadora prefixada ++, incrementa um novo elemento no final da fila.
{
    if (sloc == tamanho)
    {
        cout << "\nA fila está cheia!" << endl;
        return;
    }
    else
    {
        sloc++;
        auxiliar++;
        q[sloc] = auxiliar;
    }
}

void fila::operator--() // Função operadora prefixada --, decrementa o primeiro elemento da fila.
{
    if (sloc <= 0)
    {
        cout << "\nFila vazia!" << endl;
    }
    else
    {
        for (int i = 1; i < sloc; i++)
        {
            q[i] = q[i + 1];
        }

        sloc--;
    }
}



/*fila::~fila(void) // Função destrutora
{
    cout << "Fila destruida!\n";
}*/

int main()
{
    fila a, b; // criando os objetos de tipo fila

    //acrescentar elementos na fila usando a função qout
    a.qput(10);
    a.qput(20);
    a.qput(5);

    //acrescentar elementos na fila usando a função ++;
    ++a;
    ++a;
    //acrescentar elemetos na frente da fila (exceções)
    +a;
    +a;
    +a;

   
   //imprimir fila 
    a.ImprimeFila();

    //Tirar elementos na fila usando a função --;
    --a;
    --a;
    --a;
    a.ImprimeFila();

    //tentando acessar o qget de uma fila vazia
    b.qget();
    //tentando tirar um elemento de uma fila vazia
    --b;

    return 0;
}
