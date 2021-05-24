// FAM�LIA: DECREASE AND CONQUER / DIMINUIR PARA CONQUISTAR
//
// O algorito FAKE COIN tem como objetivo descobrir qual moeda � a falsa da forma menos custosa poss�vel, sabendo que a FAKE COIN � a mais leve

# include <iostream>
# include <vector>
# include <ctime>                   // time
# include <windows.h>           //SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE)


using namespace std;

void MontaVetorCoin (vector<int> &vetor, int n);
void MostraVetor (vector <int> vetor);
int Pesagem (vector <int> vetor);
void textcolor (int letras);
typedef enum{black,blue,green,cyan,red,magenta,brown,lightgray,darkgray,lightblue,lightgreen,lightcyan,lightred,lightmagenta,yellow,white} colors;

int main(){
    setlocale(LC_ALL, "Portuguese");                           // Recurso utilizado para conseguir imprimir acentua��o e caracteres especiais
    srand(time(NULL));

    vector <int> vetor;
    int Posicao;
    int n;

    cout << "Digite o n�mero de moedas que voc� deseja que o algoritmo procure a FAKE COIN: ";
    cin>> n;
    //cout<< endl;

    MontaVetorCoin(vetor, n);
    Posicao = Pesagem(vetor);

    textcolor(15);                                              // Muda a cor de qualquer texto ap�s a sa�da da fun��o anterior para preto e assim n�o ir� aparecer na tela
    cout << "\nA posi��o da moeda � " << Posicao << endl;
    cout<< endl;
    textcolor(7);                                              // Muda a cor de qualquer texto ap�s a sa�da da fun��o anterior para preto e assim n�o ir� aparecer na tela
    cout << "O vetor aleat�rio inicial criado com todas as moedas � este:" << endl;
    MostraVetor(vetor);
    cout<< endl;
    cout<< endl;
    textcolor(0);                                              // Muda a cor de qualquer texto ap�s a sa�da da fun��o anterior para preto e assim n�o ir� aparecer na tela
}

int Pesagem (vector <int> vetor){

    int i, W1, W2, INICIO, MEIO, FIM, EXTRA;

    INICIO = 0;
    FIM = vetor.size();

    while(INICIO!=FIM){                                        // Equanto o n�mero de moedas n�o for igual a 1, eu n�o paro de dividir e pesar.
        W1=0;                                                  // Vari�vel que ir� marcar o peso da balan�a 1
        W2=0;                                                  // Vari�vel que ir� marcar o peso da balan�a 2

        if ((INICIO + FIM)%2 !=0){                             // Se o n�mero for �mpar, � retirado a �ltima moeda e guardamos a posi��o dela na vari�vel EXTRA
            FIM = FIM -1;
            EXTRA = FIM;
        }

        MEIO = (INICIO+FIM)/2;                                 // Divide o montante de moedas ao meio

        for (i=INICIO; i<MEIO; i++){                           // Somas as moedas da primeira metade
            W1 = W1 + vetor[i];
        }
        for (i=MEIO; i<FIM; i++){                              // // Somas as moedas da segunda metade
            W2 = W2 + vetor[i];
        }

        if (W1 < W2){                                          // Se a primeira balan�a marcar peso menor, a moeda est� na primeira metade
            FIM = MEIO;
        }
        else if (W1>W2) {                                      // Se a primeira balan�a marcar peso maior, a moeda est� na segunda metade
            INICIO = MEIO;
        }
        else if (W1==W2){                                      // Se os pesos forem iguais, a moeda � a EXTRA.
            INICIO=EXTRA;
            FIM = EXTRA;
        }
    }
return INICIO;
}

void MontaVetorCoin (vector<int> &vetor, int n){
    int Aleatorio = rand() %n;

    for(int i=0; i<n; i++){
        vetor.push_back(1);
    }
    vetor[Aleatorio] = 0;
}
void MostraVetor (vector <int> vetor){
    cout << "{";
    for (int i=0; i<vetor.size(); i++){
        cout<< vetor[i];
        if (i<vetor.size()-1){
            cout << ",";
        }
    }
    cout << "}";
}

void textcolor (int letras){                                   // Fun��o para mudar cor das letras na sa�da do algoritmo
    SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),letras);
}
