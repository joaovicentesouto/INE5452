#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

#include <stdio.h>
#include <stdlib.h>

int troca= 0;

void mergeSort(vector<int> & vetor, int posicaoInicio, int posicaoFim) {
    int i, j, k, metadeTamanho;

    if(posicaoInicio == posicaoFim) return;

    metadeTamanho = (posicaoInicio + posicaoFim ) / 2;
    mergeSort(vetor, posicaoInicio, metadeTamanho);
    mergeSort(vetor, metadeTamanho + 1, posicaoFim);

    i = posicaoInicio;
    j = metadeTamanho + 1;
    k = 0;
    vector<int> vetorTemp(posicaoFim - posicaoInicio + 1);

    while(i < metadeTamanho + 1 || j  < posicaoFim + 1) {
        if (i == metadeTamanho + 1 ) { 
            vetorTemp[k] = vetor[j];
            j++;
            k++;
            troca+= 1; 
        } 
        else {
            if (j == posicaoFim + 1) {
                vetorTemp[k] = vetor[i];
                i++;
                k++;

            } 
            else {
                if (vetor[i] < vetor[j]) { 
                    vetorTemp[k] = vetor[i];
                    i++;
                    k++;

                } 
                else { 
                    vetorTemp[k] = vetor[j];
                    j++;
                    k++;
                }
            }
        }

    }
    for(i = posicaoInicio; i <= posicaoFim; i++) {
        vetor[i] = vetorTemp[i - posicaoInicio];
    }
}

int main()
{
    int n, aux;
    vector<int> auxiliar(10000000);
    
    while (true)
    {
        cin >> n;

        if (!n)
            break;

        for (int i = 0; i < n; ++i)
        {
            cin >> aux;
            auxiliar[i] = aux;
        }

        mergeSort(auxiliar, 0, n);

        if (troca % 2 == 1)
            cout << "Marcelo" << endl;
        else
            cout << "Carlos" << endl;
    }
}