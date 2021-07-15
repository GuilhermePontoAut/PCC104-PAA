// FAMÍLIA: PROGRAMAÇÃO DINÂMICA
//
// Este algoritmo tem como objetivo resolver o problema do troco utilizando para isso a técnica de PROGRAMAÇÃO DINÂMICA

# include <iostream>
# include <vector>
# include <algorithm>

using namespace std;


int MenorTroco(vector <int> D, int n);




int main () {
    setlocale(LC_ALL, "Portuguese");                           // Recurso utilizado para conseguir imprimir acentuação e caracteres especiais

    vector <int> D = {1,3,4};                                  // Valor das moedas
    int n = 13;                                                // Variável "n" é a variável que recebe o valor do TROCO a ser devolvido ao cliente

    cout<<"Moedas disponíveis {1, 3, 4}" << endl;
    cout << "\n---------------------------------------------------------------------------"<< endl;
    cout<<"A menor quantidade de moedas que é possível dar o troco no valor de "<< n <<" é: " << MenorTroco (D, n) << endl;
    cout << "---------------------------------------------------------------------------"<< endl;
    cout << endl;
    cout << endl;
}

int MenorTroco(vector <int> D, int n){

    vector <int> QuantCoin;
    int temp;
    QuantCoin.push_back(0);                                    // Vetor que guardará a quantidade de moeda a ser devolvida para cada valor de troco até o valor de "n"

    for (int i=1; i<=n; i++){
        int j=0;
        temp = numeric_limits<int>::max();
        while(j<D.size() and i>=D[j]){
            temp = min(temp, QuantCoin[i-D[j]]);
            j++;
        }
        QuantCoin.push_back(temp + 1);
    }
    return (QuantCoin[n]);
}
