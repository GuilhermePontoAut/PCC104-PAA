// FAMÍLIA: DECREASE AND CONQUER / DIMINUIR PARA CONQUISTAR
//
// O algorito INTERPOLATION SEARCH tem como objetivo checar se um valor existe dentro de um vetor ORDENADO e retorna a posição deste, senão retorna -1
// O que difere ele da BUSCA BINÁRIA, por exemplo, é a forma que ele usa para diminuir o tamanho da busca e tentar achar o valor

# include <iostream>
# include <vector>
# include <ctime>
# include <windows.h>           //SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE)

using namespace std;

void MontarVetor(vector <int> &vetor, int n);
void InsertSort (vector <int> &vetor);
void MostraVetor (vector <int> vetor);
void Interpolacao (vector <int> &vetor, int k);
void textcolor (int letras);
typedef enum{black,blue,green,cyan,red,magenta,brown,lightgray,darkgray,lightblue,lightgreen,lightcyan,lightred,lightmagenta,yellow,white} colors;

int main(){
    setlocale(LC_ALL, "Portuguese");                           // Recurso utilizado para conseguir imprimir acentuação e caracteres especiais
    srand(time(NULL));

    vector <int> vetor;
    int n, k;

    cout << "Qual o tamanho que você deseja que seja o vetor?" << endl;
    cin >> n;
    cout << "\nQual o valor que você deseja procurar?"<< endl;
    cin>> k;
    cout << endl;

    MontarVetor(vetor, n);
    InsertSort(vetor);
    MostraVetor (vetor);
    Interpolacao(vetor, k);
    textcolor(0);
}

void Interpolacao (vector <int> &vetor, int k){

    int x;
    int INI = 0;                                               // Variável que representa a posição de início do vetor que iremos fazer a interpolação
    int FIM = vetor.size()-1;                                  // Variável que representa a posição final do vetor que iremos fazer a interpolação

    while(vetor[FIM]!=vetor[INI] && k<=vetor[FIM]){            // Enquanto a posição de início e fim não são a mesma e o valor procurado não é maior que o último elemento

        x = INI + (FIM-INI)*(k - vetor[INI])/(vetor[FIM]-vetor[INI]);
        if (k==vetor[x]){
            textcolor(15);
            cout << "\nAchamos o elemento e a posicação dele dentro do vetor é " << x << endl;
            break;
        }
        else if (k > vetor[x]){                                // Se o valor procurado é maior que o valor da posição, eu irei mudar o limite inferior para a posição comparada +1
            INI = x + 1;
        }
        else if (k < vetor[x]){                                // Se o valor procurado é menor que o valor da posição, eu irei mudar o limite superior para a posição comparada -1
            FIM = x - 1;
        }
        if (vetor[FIM]==vetor[INI] || k>vetor[FIM] || k<vetor[INI]){
            textcolor(12);
            cout << "\nO elemento não existe dentro do vetor!" << endl;
            break;
        }
    }
}

void MontarVetor(vector <int> &vetor, int n){
    for(int i=0; i<n; i++){
        vetor.push_back(rand() %(2*n));
    }
}

void InsertSort (vector <int> &vetor){                         // Algoritmo usado na ordenação do vetor
    int i, j, k;

    for (i=1; i<vetor.size(); i++){
        k = vetor[i];
        j = i -1;
        while (j>=0 && vetor[j] > k){
            swap(vetor[j+1],vetor[j]);                         // MEU JEITO
            //vetor[j+1] = vetor[j];                           // JEITO DO LIVRO
            j = j - 1;
        }
    //vetor[j+1] = k;                                          // JEITO DO LIVRO
    }
}

void MostraVetor (vector <int> vetor){
    cout << "O vetor que foi gerado aleatoriamente com "<< vetor.size() <<" elementos: "<< endl;
    cout << "{";
    for (int i=0; i<vetor.size(); i++){
        cout << vetor[i];
        if (i<vetor.size()-1){
            cout<< ",";
        }
    }
    cout << "}"<< endl;
}

void textcolor (int letras){                                   // Função para mudar cor das letras na saída do algoritmo
    SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),letras);
}
