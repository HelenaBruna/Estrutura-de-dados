#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <assert.h>
#include <cstdlib>
#include <ctime>

#define qtdCartas 52
#define qtdBaralho 2
#define qtdJogadores 4
#define qtdCartasJogadores 11

using namespace std;

int main()
{
    int i = 0, j = 0, k = 0, cartaSorteada = 0, baralhoSorteado = 0;
    bool check;

    int valorCarta = 1011;
    int valorCarta2 = 2011;
    int valorCarta3 = 3011;
    int valorCarta4 = 4011;

    int valorCarta5 = 1012;
    int valorCarta6 = 2012;
    int valorCarta7 = 3012;
    int valorCarta8 = 4012;

    int **baralho = (int **)malloc(qtdBaralho * sizeof(int));

    for (i = 0; i < qtdBaralho; ++i)
    {
        baralho[i] = (int *)malloc(qtdCartas * sizeof(int));
    }

    int **mao = (int **)malloc(qtdJogadores * sizeof(int));

    for (i = 0; i < qtdJogadores; i++)
    {
        mao[i] = (int *)malloc(qtdCartasJogadores * sizeof(int));
    }

    for (i = 0; i < qtdBaralho; ++i) 
    {
        for (j = 0; j < qtdCartas; ++j) 
        {
            if (i == 0)
            {
                if (j < 13)
                {
                    baralho[i][j] = valorCarta;
                    valorCarta += 10;
                }
                else if (j >= 13 && j < 26)
                {
                    baralho[i][j] = valorCarta2;
                    valorCarta2 += 10;
                }
                else if (j >= 26 && j < 39)
                {
                    baralho[i][j] = valorCarta3;
                    valorCarta3 += 10;
                }
                else
                {
                    baralho[i][j] = valorCarta4;
                    valorCarta4 += 10;
                }
            }
            else
            {
                if (j < 13)
                {
                    baralho[i][j] = valorCarta5;
                    valorCarta5 += 10;
                }
                else if (j >= 13 && j < 26)
                {
                    baralho[i][j] = valorCarta6;
                    valorCarta6 += 10;
                }
                else if (j >= 26 && j < 39)
                {
                    baralho[i][j] = valorCarta7;
                    valorCarta7 += 10;
                }
                else
                {
                    baralho[i][j] = valorCarta8;
                    valorCarta8 += 10;
                }
            }
        }
    }

    for (i = 0; i < qtdJogadores; ++i)
    {
        for (j = 0; j < qtdCartasJogadores; ++j)
        {
            do
            {
                cartaSorteada = rand() % 52;
                baralhoSorteado = rand() % 2;
                check = true;

                if (baralho[baralhoSorteado][cartaSorteada] == 0)
                {
                    check = false;
                }

            } while (!check);

            mao[i][j] = baralho[baralhoSorteado][cartaSorteada];
            baralho[baralhoSorteado][cartaSorteada] = 0;

            cout << setw(5) << "mao[" << i << "][" << j << "]: " << mao[i][j];
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}
