#include <iostream>
#include <stdio.h>
#include <string> //biblioteca para chamar strings
#include <stdlib.h>
#include <locale.h> //necessário para usar setlocale

using namespace std;
/*
 ------------------JOGO TORRE DE HANOI -----------------------------
 DISCIPLINA: LOGICA DE PROGRAMACAO

*/
int main()
{
    setlocale(LC_ALL, "UTF-8");

    // tela inicial
    cout << "-------------------------------------------" << endl;
    cout << "-----Bem-vindo ao jogo torre de hanoi------" << endl;
    cout << "-------------------------------------------" << endl;
    cout << "-------------MENU PRINCIPAL----------------" << endl;
    cout << "1 - Instruções" << endl;
    cout << "2 - Jogar" << endl;
    cout << "3 - Sair" << endl;
    cout << "-------------------------------------------" << endl;
    cout << "-------------------------------------------" << endl;
    // switch de opções
    int opcao_escolhida, nivel_escolhido;
    cout << "Digite o número para entrar na opção desejada:" << endl;
    cin >> opcao_escolhida;
    switch (opcao_escolhida)
    {
    case 1:
        // opção de instrucoes
        system("cls");
        cout << "-------------------------------------------" << endl;
        cout << "---------INSTRUÇÕES DO JOGO----------------" << endl;
        cout << "-------------------------------------------" << endl;
        cout << endl;
        cout << endl;
        cout << "OBJETIVO:" << endl;
        cout << "O objectivo deste jogo consiste em deslocar todos" << endl;
        cout << "os discos da haste onde se encontram para uma haste diferente" << endl;
        cout << "respeitando as seguintes regras:" << endl;
        cout << " 1. Deslocar um disco de cada vez;" << endl;
        cout << " 2. O qual deverá ser o do topo de uma das três hastes;" << endl;
        cout << " 3. Cada disco nunca poderá ser colocado sobre outro de diâmetro mais pequeno" << endl;
        cout << endl;

        // TEXTO AQUI

        // codigo para voltar ao menu principal

        break;
    case 2:

        // começando o jogo no modo um jogador
        system("cls");
        cout << "-------------------------------------------" << endl;
        cout << "-------------------------------------------" << endl;
        cout << "NÍVEIS DE DIFICULDADE" << endl;
        cout << "-------------------------------------------" << endl;
        cout << "-------------------------------------------" << endl;
        cout << "1 - Fácil (Três discos)" << endl;
        cout << "2 - Médio (Cinco discos)" << endl;
        cout << "3 - Difícil (Sete discos)" << endl;
        cout << "-------------------------------------------" << endl;
        cout << "Digite o número referente ao seu nível de dificuldade:" << endl;
        cin >> nivel_escolhido;

        int countDiscos;

        // codigo modo player
        int isNovaPartida = 1;

        // Condicao de niveis
        if (nivel_escolhido == 1)
        {
            countDiscos = 3;
        }
        else if (nivel_escolhido == 2)
        {
            countDiscos = 5;
        }
        else if (nivel_escolhido == 3)
        {
            countDiscos = 7;
        }
        else
        {
            countDiscos = 3;
        }

        system("cls");
        cout << "-------------------------------------------" << endl;
        cout << "-------------------------------------------" << endl;
        cout << "--------------TORRE DE HANOI---------------" << endl;
        cout << "-------------------------------------------" << endl;
        cout << "-------------------------------------------" << endl;
        string nome;
        cout << "Qual o seu nome jogador?" << endl;
        cin >> nome;
        cout << "Bem-vindo " << nome << endl
             << endl;

        do
        {

            bool jogadaValida = true;
            bool isJogoFinalizado = true;
            // int countDiscos = nivel_escolhido;
            int countPinos = 3;
            int countJogados = 0;

            int indexPinoRemoverDiscoTmp = -1;
            int indexPinoColocarDiscoTmp = -1;
            // coluna da matriz onde esta o disco removido
            int indexDiscoRemovidoDoPinoTmp = -1;
            int indexDiscoColocarNoPinoTmp = -1;
            int valorDiscoTmp = -1;
            int valorDiscoMovidoTmp = -1;

            // pinos x discos
            int matrizJogo[countPinos][countDiscos];

            for (int disco = 0; disco < countDiscos; disco++)
            {
                matrizJogo[1][disco] = 0;
                matrizJogo[2][disco] = 0;
            }

            // cria os pinos na primeira coluna
            for (int disco = 0; disco < countDiscos; disco++)
            {
                matrizJogo[0][disco] = disco + 1;
            }

            do
            {
                jogadaValida = true;
                isJogoFinalizado = true;
                indexPinoRemoverDiscoTmp = -1;
                indexPinoColocarDiscoTmp = -1;
                indexDiscoRemovidoDoPinoTmp = -1;
                indexDiscoColocarNoPinoTmp = -1;
                valorDiscoTmp = -1;
                valorDiscoMovidoTmp = -1;

                // show matriz
                for (int disco = 0; disco < countDiscos; disco++)
                {
                    for (int pino = 0; pino < countPinos; pino++)
                    {
                        cout << matrizJogo[pino][disco] << " ";
                    }
                    cout << endl;
                }

                cout << "\nDe qual pino você quer remover o disco (1, 2 ou 3) " << nome << endl;
                cin >> indexPinoRemoverDiscoTmp;
                indexPinoRemoverDiscoTmp--;

                cout << "Em qual pino você quer colocar o disco (1, 2 ou 3) ? " << nome << endl;
                cin >> indexPinoColocarDiscoTmp;
                indexPinoColocarDiscoTmp--;

                system("cls");

                if (indexPinoColocarDiscoTmp == indexPinoRemoverDiscoTmp)
                {
                    cout << "Disco não pode ser movido para o mesmo pino! Jogada inválida!" << endl;
                    jogadaValida = false;
                    isJogoFinalizado = false;
                }
                else if (indexPinoColocarDiscoTmp > 2 || indexPinoColocarDiscoTmp < 0)
                {
                    cout << "Pino não existe! Jogada inválida!" << endl;
                    jogadaValida = false;
                    isJogoFinalizado = false;
                }
                else if (indexPinoRemoverDiscoTmp > 2 || indexPinoRemoverDiscoTmp < 0)
                {
                    cout << "Pino não existe! Jogada inválida!" << endl;
                    jogadaValida = false;
                    isJogoFinalizado = false;
                }
                else if (matrizJogo[indexPinoRemoverDiscoTmp][countPinos - 1] == 0)
                {
                    cout << "Pino não possui disco para ser movido! Jogada inválida!" << endl;
                    jogadaValida = false;
                    isJogoFinalizado = false;
                }
                else
                {

                    // ver qual a linha da matriz onde esta o disco de cima que sera retirado
                    for (int disco = 0; disco < countDiscos; disco++)
                    {
                        valorDiscoTmp = matrizJogo[indexPinoRemoverDiscoTmp][disco];
                        if (valorDiscoTmp != 0)
                        {
                            indexDiscoRemovidoDoPinoTmp = disco;
                            break;
                        }
                    }

                    if (indexDiscoRemovidoDoPinoTmp != -1)
                    {
                        // ver qual a linha da matriz onde esta o disco de cima para colocar o disco sobre ele
                        for (int disco = 0; disco < countDiscos; disco++)
                        {
                            valorDiscoTmp = matrizJogo[indexPinoColocarDiscoTmp][disco];
                            // se ja chegou na coluna onde tem disco para colocar o novo disco por cima do existente
                            if (valorDiscoTmp != 0)
                            {
                                indexDiscoColocarNoPinoTmp = disco - 1;
                                break;
                            }
                        }

                        valorDiscoMovidoTmp = matrizJogo[indexPinoRemoverDiscoTmp][indexDiscoRemovidoDoPinoTmp];

                        // se nenhum disco for encontrado e pq nao existe disco naquele pino
                        // novo pino sera colocado na base do pino
                        if (indexDiscoColocarNoPinoTmp == -1)
                        {
                            indexDiscoColocarNoPinoTmp = countDiscos - 1;
                        }
                        else if (valorDiscoMovidoTmp > matrizJogo[indexPinoColocarDiscoTmp][indexDiscoColocarNoPinoTmp + 1])
                        {
                            jogadaValida = false;
                            cout << "Um disco maior não pode ficar em cima de um disco menor! Jogada invalida! " << nome << endl;
                        }
                        // jogadaValita é verdadeira
                        if (jogadaValida)
                        {
                            matrizJogo[indexPinoRemoverDiscoTmp][indexDiscoRemovidoDoPinoTmp] = 0;
                            matrizJogo[indexPinoColocarDiscoTmp][indexDiscoColocarNoPinoTmp] = valorDiscoMovidoTmp;
                            countJogados++;

                            if (matrizJogo[1][0] != 1 && matrizJogo[2][0] != 1)
                            {
                                isJogoFinalizado = false;
                            }
                        }
                        else
                        {
                            isJogoFinalizado = false;
                        }
                        cout << "Número de jogadas: " << countJogados << endl;
                    }
                    else
                    {
                        jogadaValida = false;
                        cout << "O pino para retirada do disco não possui disco! Jogada invalida! " << nome << endl;
                    }

                    if (isJogoFinalizado)
                    {
                        cout << "Partida finalizada! Parabéns " << nome << endl;
                    }
                }

            } while (!isJogoFinalizado);

            cout << "Nova partida?" << endl;
            cout << "0 - Sair" << endl;
            cout << "1 ou qualquer outro número - Novo Jogo" << endl;
            cin >> isNovaPartida;

            system("cls");
        } while (isNovaPartida != 0); // Retornando novamente ao jogo // case 2
    } 
}
