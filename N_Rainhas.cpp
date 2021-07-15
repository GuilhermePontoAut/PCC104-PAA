// FAMÍLIA: BACKTRACKING
//
// Este algoritmo tem como objetivo resolver o problema das N-RAINHAS utilizando para isso um algoritmo baseado em BACKTRACNKIN

# include <iostream>
# include <vector>



using namespace std;


int Acao(vector<vector<int>> &Tabuleiro, int col, int n);
bool Verificador(vector<vector<int>> &Tabuleiro, int n, int lin, int col);
void MostrarTabuleiro(vector<vector<int>> &Tabuleiro, int n);


int main (){
    setlocale(LC_ALL, "Portuguese");
    int n = 3;
    vector<vector<int>> Tabuleiro(n, vector <int> (n));
    MostrarTabuleiro(Tabuleiro, n);

    Acao(Tabuleiro, 0, n);
    MostrarTabuleiro(Tabuleiro, n);

}

int Acao(vector<vector<int>> &Tabuleiro, int col, int n){


    if (col==n){
        return 1;
    }

    else{
        for(int lin=0; lin<n; lin++){
            if (Verificador(Tabuleiro, n, lin, col) == true){

                //Confirmo a posicao da Rainha
                Tabuleiro[lin][col] = 1;
                cout << "LinhaA = " << lin << " ColunaA = " << col << endl;

                //Chamo de novo a função para a nova coluna
                Acao(Tabuleiro, col+1, n);

                //Desconfirmo a posicao da Rainha
                Tabuleiro[lin][col] = 0;
                cout << "LinhaB = " << lin << " ColunaB = " << col << endl;
            }
        }
    }
}

bool Verificador(vector<vector<int>> &Tabuleiro, int n, int lin, int col){

    int i, j;
    int aux1, aux2, aux3;

    //Verificar linha
    for(j=0; j<n; j++){
        i = lin;
        if (Tabuleiro[i][j]==1 and j!=col){
            return false;
        }
    }

    //Verificar coluna
    for(i=0; i<n; i++){
        j=col;
        if (Tabuleiro[i][j]==1 and i!=lin){
            return false;
        }
    }

    //Verificar Diagonal Principal
    if (lin == col){
        aux3 = lin + col;
        for(i=0, j=0; i<n, j<n; i++, j++){
            if (Tabuleiro[i][j]==1 and i!=lin and j!=col){
                return false;
            }
        }
        for(i=0,j=aux3; i<=aux3,j>=0; i++, j--){
            if (Tabuleiro[i][j]==1 and i!=lin and j!=col){
                return false;
            }
        }
    }

    //Verificador Diagonal inferior à principal
    else if (lin > col){
        aux1 = lin-col;
        aux2 = n-aux1;
        aux3 = lin + col;
        for(j=0, i=aux1; j<aux2, i<n; j++, i++){
            if (Tabuleiro[i][j]==1 and i!=lin and j!=col){
                return false;
            }
        }
        for(i=0,j=aux3; i<=aux3,j<=0; i++, j--){
            if (Tabuleiro[i][j]==1 and i!=lin and j!=col){
                return false;
            }
        }
    }

    //Verificador Diagonal superior à principal
    else if (lin < col){
        aux1 = col-lin;
        aux2 = n-aux1;
        aux3 = lin + col;
        for(j=aux1, i=0; j<n, i<aux2; j++, i++){
            if (Tabuleiro[i][j]==1 and i!=lin and j!=col){
                return false;
            }
        }
        for(i=0,j=aux2; i<aux3, j<=0; i++, j--){
            if (Tabuleiro[i][j]==1 and i!=lin and j!=col){
                return false;
            }
        }
    }
    return true;
}

void MostrarTabuleiro(vector<vector<int>> &Tabuleiro, int n){
    int z;
    cout<< "  TABULEIRO" << endl;
    for(int i=0; i<n; i++){
        cout << "-";
        while(z<n){
            cout << "----";
            z++;
        }
        cout << endl;
        cout<< "| ";
        for(int j=0; j<n; j++){
            cout<< Tabuleiro[i][j];
            cout<< " | ";
            }
        z = 0;
        cout << endl;
    }
    cout << "-";
    while(z<n){
        cout << "----";
        z++;
    }
    cout << endl;
    cout << endl;
}
