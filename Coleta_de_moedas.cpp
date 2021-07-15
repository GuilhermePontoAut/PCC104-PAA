// FAMÍLIA: PROGRAMAÇÃO DINÂMICA
//
// Este algoritmo tem como objetivo resolver o problema da COLETA DE MOEDAS utilizando para isso a técnica de PROGRAMAÇÃO DINÂMICA

# include <iostream>
# include <vector>
# include <ctime>


using namespace std;

void GeradorDeMoedas(vector<vector<int>> &vetor, int lin, int col);
void MontarTabuleiro(vector<vector<int>> vetor, int lin, int col);
int RobotCoin (vector<vector<int>> &TemMoeda, vector<vector<int>> &Caminho, int n, int m);



int main () {
    setlocale(LC_ALL, "Portuguese");
    srand(time(NULL));

    int lin=5;
    int col=5;

    vector<vector<int>> TemMoeda(lin, vector<int>(col));
    vector<vector<int>> Caminho(lin, vector<int>(col));


    GeradorDeMoedas(TemMoeda, lin, col);
    MontarTabuleiro(TemMoeda, lin, col);
    cout << "\n------------------------------------------------"<< endl;
    cout << "O máximo de moedas possível de se recolher é: " << RobotCoin(TemMoeda, Caminho, lin, col) << endl;
    cout << "------------------------------------------------"<< endl;
    cout<< endl;
    cout<< endl;
    cout<< endl;
}

int RobotCoin (vector<vector<int>> &TemMoeda, vector<vector<int>> &Caminho, int n, int m){

    Caminho[0][0] = TemMoeda[0][0];
    int j;

    for (int j=1; j<m; j++){
        Caminho[0][j] = TemMoeda[0][j];
    }

    for (int i=1; i<n; i++){
        Caminho[i][0] = TemMoeda[i][0];
        for (j=1; j<m; j++){
            Caminho[i][j] = max(Caminho[i-1][j], Caminho[i][j-1]) + TemMoeda[i][j];
        }
    }
    return(Caminho[n-1][m-1]);
}

void GeradorDeMoedas (vector<vector<int>> &vetor, int lin, int col){
    for(int i=0; i<lin; i++){
        for(int j=0; j<col; j++){
            vetor[i][j] = (rand() %2);
            if (i==0 and j==0){
                vetor[i][j] = 0;
            }
        }
    }
}

void MontarTabuleiro(vector<vector<int>> vetor, int lin, int col){

    int z =0;
    cout<< "\n  TABULEIRO DE MOEDAS" << endl;
    for(int i=0; i<=lin; i++){
        cout << " -";
        while(z < col){
        cout << "----";
        z = z+1;
        }
        cout<< endl;
        if (i<lin){
            for(int j=0; j<col; j++){
                cout << " | ";
                cout<< vetor[i][j];
            }
            cout<<  " | "<< endl;
        }
        z=0;
    }
}
