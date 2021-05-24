// FAMÍLIA: DECREASE AND CONQUER / DIMINUIR PARA CONQUISTAR
//
// O algorito FAKE COIN tem como objetivo descobrir qual moeda é a falsa da forma menos custosa possível, sabendo que a FAKE COIN é a mais leve

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
    setlocale(LC_ALL, "Portuguese");                           // Recurso utilizado para conseguir imprimir acentuação e caracteres especiais
    srand(time(NULL));

    vector <int> vetor;
    int Posicao;
    int n;

    cout << "Digite o número de moedas que você deseja que o algoritmo procure a FAKE COIN: ";
    cin>> n;
    //cout<< endl;

    MontaVetorCoin(vetor, n);
    Posicao = Pesagem(vetor);

    textcolor(15);                                              // Muda a cor de qualquer texto após a saída da função anterior para preto e assim não irá aparecer na tela
    cout << "\nA posição da moeda é " << Posicao << endl;
    cout<< endl;
    textcolor(7);                                              // Muda a cor de qualquer texto após a saída da função anterior para preto e assim não irá aparecer na tela
    cout << "O vetor aleatório inicial criado com todas as moedas é este:" << endl;
    MostraVetor(vetor);
    cout<< endl;
    cout<< endl;
    textcolor(0);                                              // Muda a cor de qualquer texto após a saída da função anterior para preto e assim não irá aparecer na tela
}

int Pesagem (vector <int> vetor){

    int i, W1, W2, INICIO, MEIO, FIM, EXTRA;

    INICIO = 0;
    FIM = vetor.size();

    while(INICIO!=FIM){                                        // Equanto o número de moedas não for igual a 1, eu não paro de dividir e pesar.
        W1=0;                                                  // Variável que irá marcar o peso da balança 1
        W2=0;                                                  // Variável que irá marcar o peso da balança 2

        if ((INICIO + FIM)%2 !=0){                             // Se o número for ímpar, é retirado a última moeda e guardamos a posição dela na variável EXTRA
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

        if (W1 < W2){                                          // Se a primeira balança marcar peso menor, a moeda está na primeira metade
            FIM = MEIO;
        }
        else if (W1>W2) {                                      // Se a primeira balança marcar peso maior, a moeda está na segunda metade
            INICIO = MEIO;
        }
        else if (W1==W2){                                      // Se os pesos forem iguais, a moeda é a EXTRA.
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

void textcolor (int letras){                                   // Função para mudar cor das letras na saída do algoritmo
    SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),letras);
}
