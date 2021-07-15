// FAMÍLIA: PROGRAMAÇÃO DINÂMICA
//
// Este algoritmo tem como objetivo resolver o problema da MOCHILA utilizando para isso um algoritmo baseado em FUNÇÃO DE MEMÓRIA

# include <iostream>
# include <vector>



using namespace std;

void MontarMatriz(vector<vector <int>> &Matriz, int i, int j);
int MFKnapsack (vector<vector <int>> &Matriz, vector <int> Peso, vector <int> Valor, int i, int j);
void MontarTabuleiro(vector<int> peso, vector<int> valor);



int main () {
    setlocale(LC_ALL, "Portuguese");

    vector <int> Peso = {0,2,1,3,2};                                                            // Peso de cada item
    vector <int> Valor = {0, 12, 10, 20, 15};                                                   // Valor de cada item
    int i = (Peso.size()-1);
    int j = 5;                                                                                  // Capacidade da mochila
    MontarTabuleiro(Peso, Valor);
    vector<vector <int>> Matriz(Peso.size()+1, vector<int> (j+1));                              // Matriz de valores
    MontarMatriz(Matriz, i, j);

    cout<< "O peso máximo que a mochila consegue carregar é: "<< j << endl;
    cout<< "O maior valor possível de carregar nesta mochila é: $"<< MFKnapsack (Matriz, Peso, Valor, i, j) << endl;
    cout<< endl;
    cout<< endl;

}

int MFKnapsack (vector<vector <int>> &Matriz, vector <int> Peso, vector <int> Valor, int i, int j){

    int ValorAux;

    if (Matriz[i][j] < 0){
        if (j < Peso[i]){
            ValorAux = MFKnapsack (Matriz, Peso, Valor, i-1, j);
        }
        else {
        ValorAux = max(MFKnapsack (Matriz, Peso, Valor, i-1, j), Valor[i] + MFKnapsack (Matriz, Peso, Valor, i-1, j-Peso[i]));
        }
        Matriz[i][j] = ValorAux;
    }
    return(Matriz[i][j]);
}

void MontarMatriz(vector<vector <int>> &Matriz, int i, int j){
    for (int l=0; l<=i; l++){
        for (int c=0; c<=j; c++){
            if(l==0 or c==0){
                Matriz[l][c] = 0;
            }
            else{
                Matriz[l][c] = -1;
            }
        }
    }
}

void MontarTabuleiro(vector<int> peso, vector<int> valor){

    int lin = peso.size();
    int col = 3;
    int z =0;
    cout << "-----------------------" << endl;
    cout<< "   TABELA DE ITENS" << endl;
    cout << "-----------------------" << endl;
    cout << "-----------------------" << endl;
    cout << "| ITEM | PESO | VALOR |" << endl;
    for(int i=0; i<=lin; i++){
        cout << "--";
        while(z < col){
            cout << "-------";
            z = z+1;
        }

        if (i<lin){
            cout<< endl;
            cout << "|  ";
            cout << "0" <<i;
            cout << "  |  ";
            cout<< "0" << peso[i];
            cout << "  |  ";
            cout << "$" <<valor[i];
            cout << "  |  ";
            z=0;
            cout<< endl;
        }
    }
    cout << endl;
    cout << endl;
}
