// FAMÍLIA: DECREASE AND CONQUER / DIMINUIR PARA CONQUISTAR
//
// O algorito BUSCA BINÁRIA tem como objetivo checar se um valor existe dentro de um vetor ORDENADO e retorna a posição deste, senão retorna -1

# include <iostream>
# include <vector>
# include <ctime>
# include <windows.h>           //SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE)


using namespace std;

void MontaVetor(vector <int> &vetor, int n);
void MostraVetor (vector <int> vetor);
void InsertSort (vector <int> &vetor);
void Busca (vector <int> vetor, int k);
void textcolor (int letras);
typedef enum{black,blue,green,cyan,red,magenta,brown,lightgray,darkgray,lightblue,lightgreen,lightcyan,lightred,lightmagenta,yellow,white} colors;

int main () {
    setlocale(LC_ALL, "Portuguese");                           // Recurso utilizado para conseguir imprimir acentuação e caracteres especiais
    srand(time(NULL));                                         // Utiliza o relógio interno do computador para escolher uma semente para gerar os números aleatórios.

    vector <int> vetor;
    int n = 25;                                                // Tamanho do vetor ordenado
    int k;                                                     // key que será procurada no vetor

    cout<< "Qual o valor que você deseja procurar no vetor (0-49)?" << endl;
    cin >> k;
    cout << endl;

    MontaVetor(vetor, n);                                      // Monta o vetor desordenado de tamanho "n"
    cout << "Vetor com números escolhidos aleatoriamente: ";
    MostraVetor(vetor);                                        // Mostra o vetor desordenado
    cout << endl;
    cout << "Vetor ordenado: ";
    InsertSort(vetor);                                         // Ordena o vetor
    cout << endl;
    Busca(vetor, k);                                           // Busca o valor "k" no vetor
    textcolor(0);                                              // Muda a cor de qualquer texto após a saída da função anterior para preto e assim não irá aparecer na tela
}

void Busca (vector <int> vetor, int k){
    int x;
    int l = 0;                                                 // Left: Início da busca do vetor
    int r = vetor.size()-1;                                    // Right: Fim da busca do vetor

    while (r > l) {

        x = (l+r)/2;

        if (k==vetor[x]){
            textcolor(15);
            cout << "Achamos o seu número no vetor na posição: " << x << endl;
            l = 25;
        }
        else if (k>vetor[x]){
            l = x+1;
        }
        else if (k<vetor[x]) {
            r=x-1;
        }
        if (r<=l && l!= 25){
            textcolor(12);
            cout << "Não achamos o seu número no vetor! "<<endl;
        }
    }
}

void MontaVetor(vector <int> &vetor, int n){
    for (int i=0; i<n; i++){
        vetor.push_back(rand() %50);
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
    MostraVetor (vetor);                                       // Chama função para mostrar vetor ordenado

}

void MostraVetor (vector <int> vetor){
    cout << "{";
    for(int i=0; i<vetor.size(); i++){
        cout << vetor[i];
        if (i<vetor.size()-1){
            cout << ",";
        }
    }
    cout <<"}" << endl;
}

void textcolor (int letras){                                   // Função para mudar cor das letras na saída do algoritmo
    SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),letras);
}
