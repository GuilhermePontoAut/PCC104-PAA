// FAMÍLIA: DECREASE AND CONQUER / DIMINUIR PARA CONQUISTAR
//
// O algorito INSERT SORT tem como objetivo ordenar os valores que estão dentro de um vetor do menor para o maior

# include <iostream>
# include <vector>
# include <ctime>
# include <windows.h>           //SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE)


using namespace std;

void VetorAleatorio (vector <int> &x, int tam);
void InsertSort (vector <int> vetor);
void MostraVetor (vector <int> vetor);
void textcolor (int letras);
typedef enum{black,blue,green,cyan,red,magenta,brown,lightgray,darkgray,lightblue,lightgreen,lightcyan,lightred,lightmagenta,yellow,white} colors;

int main () {
    setlocale(LC_ALL, "Portuguese");                           // Recurso utilizado para conseguir imprimir acentuação e caracteres especiais
    srand(time(NULL));                                         // Utiliza o relógio interno do computador para escolher uma semente para gerar os números aleatórios.

    vector <int> vetor;
    int n =25;                                                 // Tamanho do vetor a ser usado no InsertSort

    VetorAleatorio(vetor, n);                                  // Chama função para gera vetor aleatório
    InsertSort(vetor);
}

void VetorAleatorio (vector <int> &x, int tam) {
    for (int i=0; i<tam; i++){
        x.push_back(rand() %100);
    }
}

void InsertSort (vector <int> vetor){
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
    textcolor(0);
}

void MostraVetor (vector <int> vetor) {
    cout << "Vetor ordenado é:" << endl;
    cout << "{ ";
    for (int i=0; i<vetor.size(); i++){
        cout << vetor[i];
        if (i < vetor.size()-1){
            cout << ", ";
        }
    }
    cout << "}";
}

void textcolor (int letras){                                   // Função para mudar cor das letras na saída do algoritmo
    SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),letras);
}
