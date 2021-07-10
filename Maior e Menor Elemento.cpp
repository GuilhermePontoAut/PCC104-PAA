// FAMÍLIA: DIVIDE AND CONQUER / DIVIDIR E CONQUISTAR
//
// Este algoritmo tem como objetivo encontrar o maior e o menor elemento e suas respectivas posições dentro de um vetor aleatório utilizando para isso a técnica de DIVIDIR E CONQUISTAR

# include <tuple>
# include <iostream>
# include <vector>
# include <ctime>
# include <algorithm>    // max

using namespace std;

void MontaVetor(vector <int> &vetor, int tam);
void MostraVetor (vector <int> vetor);
pair <int, int> MaiorValor (vector <int> &vetor, int ini, int fim);

int main (){

    setlocale(LC_ALL, "Portuguese");
    srand(time(NULL));

    vector <int> vetor;

    int n = 25;

    MontaVetor(vetor, n);
    MostraVetor(vetor);
    pair <int, int> Resposta = MaiorValor(vetor, 0, vetor.size()-1);

    cout << "\n------------------------------------------" << endl;
    cout << " O maior valor do vetor é: " << vetor[Resposta.first] << endl;
    cout << " A posição do maior valor do vetor é: " << Resposta.first << endl;
    cout << "\n O menor valor do vetor é: " << vetor[Resposta.second] << endl;
    cout << " A posição do menor valor do vetor é: " << Resposta.second << endl;
    cout << "------------------------------------------" << endl;
    cout << endl;
    cout << endl;
    cout << endl;

}

pair <int, int> MaiorValor (vector <int> &vetor, int ini, int fim){

    int meio;
    pair <int, int> VetorE;
    pair <int, int> VetorD;
    int aux1, aux2;

    if (fim - ini <= 1){
        if (vetor[ini] > vetor[fim]){
            return make_pair(ini, fim);
        }
        else{
            return make_pair(fim, ini);
        }
    }

    else{
        meio = (ini + fim)/2;
        VetorE = MaiorValor(vetor, ini, meio);
        VetorD = MaiorValor(vetor, meio+1, fim);

        if (vetor[VetorE.first] >= vetor[VetorD.first]){
            aux1 = VetorE.first;
        }
        else{
            aux1 = VetorD.first;
        }
        if (vetor[VetorE.second] <= vetor[VetorD.second]){
            aux2 = VetorE.second;
        }
        else{
            aux2 = VetorD.second;
        }
    }
    return make_pair(aux1, aux2);
}

void MontaVetor(vector <int> &vetor, int tam) {
    for (int i = 0; i < tam; i++){
        vetor.push_back(rand() %30);
    }
}

void MostraVetor (vector <int> vetor){
    cout << " Vetor: { ";
    for (int i =0; i<vetor.size(); i++){
        cout << vetor[i];
        if (i < vetor.size()-1){
            cout << ", ";
        }
    }
    cout << " }" << endl;
}
