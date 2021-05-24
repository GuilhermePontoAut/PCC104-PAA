// FAM�LIA: DECREASE AND CONQUER / DIMINUIR PARA CONQUISTAR
//
// O algorito BUSCA BIN�RIA tem como objetivo checar se um valor existe dentro de um vetor ORDENADO e retorna a posi��o deste, sen�o retorna -1

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
    setlocale(LC_ALL, "Portuguese");                           // Recurso utilizado para conseguir imprimir acentua��o e caracteres especiais
    srand(time(NULL));                                         // Utiliza o rel�gio interno do computador para escolher uma semente para gerar os n�meros aleat�rios.

    vector <int> vetor;
    int n = 25;                                                // Tamanho do vetor ordenado
    int k;                                                     // key que ser� procurada no vetor

    cout<< "Qual o valor que voc� deseja procurar no vetor (0-49)?" << endl;
    cin >> k;
    cout << endl;

    MontaVetor(vetor, n);                                      // Monta o vetor desordenado de tamanho "n"
    cout << "Vetor com n�meros escolhidos aleatoriamente: ";
    MostraVetor(vetor);                                        // Mostra o vetor desordenado
    cout << endl;
    cout << "Vetor ordenado: ";
    InsertSort(vetor);                                         // Ordena o vetor
    cout << endl;
    Busca(vetor, k);                                           // Busca o valor "k" no vetor
    textcolor(0);                                              // Muda a cor de qualquer texto ap�s a sa�da da fun��o anterior para preto e assim n�o ir� aparecer na tela
}

void Busca (vector <int> vetor, int k){
    int x;
    int l = 0;                                                 // Left: In�cio da busca do vetor
    int r = vetor.size()-1;                                    // Right: Fim da busca do vetor

    while (r > l) {

        x = (l+r)/2;

        if (k==vetor[x]){
            textcolor(15);
            cout << "Achamos o seu n�mero no vetor na posi��o: " << x << endl;
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
            cout << "N�o achamos o seu n�mero no vetor! "<<endl;
        }
    }
}

void MontaVetor(vector <int> &vetor, int n){
    for (int i=0; i<n; i++){
        vetor.push_back(rand() %50);
    }
}

void InsertSort (vector <int> &vetor){                         // Algoritmo usado na ordena��o do vetor
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
    MostraVetor (vetor);                                       // Chama fun��o para mostrar vetor ordenado

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

void textcolor (int letras){                                   // Fun��o para mudar cor das letras na sa�da do algoritmo
    SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),letras);
}
