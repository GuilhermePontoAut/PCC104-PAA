// FAMÍLIA: DECREASE AND CONQUER / DIMINUIR PARA CONQUISTAR
//
// O algoritmo LexicographicPermute tem como objetivo gerar todas as permutações de um vetor de números inteiros de tamanho "n" em ORDEM LEXICOGRÁFICA!
// Há possibilidade tambem de se fazer essa permutação com letras ao invés de números

# include <algorithm>                  //reverse()
# include <iostream>
# include <vector>


using namespace std;

void MontarVetor(vector <int> &vetor, int n);
void MostrarVetor(vector <int> vetor);
void PermutaLex (vector<int> vetor);


int main (){

    setlocale(LC_ALL, "Portuguese");                           // Recurso utilizado para conseguir imprimir acentuação e caracteres especiais
    vector <int> vetor;
    int n;

    cout << "Qual o tamanho do vetor que você deseja permutar?" << endl;
    cin >> n;
    cout << endl;

    MontarVetor(vetor, n);
    PermutaLex (vetor);
}

void MontarVetor(vector <int> &vetor, int n){
    for (int i=0; i<n; i++){
        vetor.push_back(i);
    }
}

void MostrarVetor(vector <int> vetor){
    cout << "{ ";
    for (int i=0; i<vetor.size(); i++){
        cout << vetor[i];
        if (i<vetor.size()-1){
            cout << ",";
        }
    }
    cout << " }" << endl;
}

void PermutaLex (vector<int> vetor){
    int i,j,Largesti,Largestj;
    MostrarVetor(vetor);

    do{
        Largesti = -1;
        for (i=0; i<vetor.size(); i++){                         // A cada iteração irá procurar a posição do vetor que contém o maior valor que preceda um valor maior.
            if (vetor[i] < vetor[i+1]){                         // Ex: 1 2 3 4 5 6 vai retornar a posição do 5;   3 5 8 2 7 9 4 2 vai retornar a posição do 7
                Largesti = i;
            }
        }

        if (Largesti != -1){
            for (j=0; j<vetor.size(); j++){                     // A cada iteração irá procurar a posição do vetor que contém o último valor que é maior que o Lagersti
                if (vetor[j] > vetor[Largesti]){                // Ex: 1 2 3 4 5 6 vai retornar a posição do 6;   3 5 8 2 7 9 4 2 vai retornar a posição do 9
                    Largestj = j;
                }
            }
        swap(vetor[Largesti], vetor[Largestj]);                 // Irá fazer dos dois valores no vator
        reverse(vetor.begin()+Largesti+1, vetor.end());         // Irá fazer o reverse a partir da primeira posição após a posição Lagersti
        MostrarVetor(vetor);
        }
    } while (Largesti!= -1);                                    // Critério de parada é quando não achar mais Largesti
}
