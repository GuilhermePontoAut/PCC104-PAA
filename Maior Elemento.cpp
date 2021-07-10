// FAMÍLIA: DIVIDE AND CONQUER / DIVIDIR E CONQUISTAR
//
// Este algoritmo tem como objetivo encontrar o maior elemento e sua posição dentro de um vetor aleatório utilizando para isso a técnica de DIVIDIR E CONQUISTAR


# include <iostream>
# include <vector>
# include <ctime>
# include <algorithm>    // max

using namespace std;

void MontaVetor(vector <int> &vetor, int tam);
void MostraVetor (vector <int> vetor);
int Merge(vector <int> &vetor, int ini, int fim);
int MergeSort (vector <int> &vetor, int ini, int meio, int fim);
int MergeBigger (vector <int> &vetor, int ini, int fim);
int MaiorValor (vector <int> &vetor, int ini, int fim);

int main (){

    setlocale(LC_ALL, "Portuguese");
    srand(time(NULL));

    vector <int> vetor;

    int n = 25;

    MontaVetor(vetor, n);
    MostraVetor(vetor);
    cout << "\n------------------------------------------" << endl;
    cout << " O maior valor do vetor é: " << MergeBigger(vetor, 0, vetor.size()-1) << endl;
    cout << " A posição do maior valor do vetor é: " << MaiorValor(vetor, 0, vetor.size()-1) << endl;
    cout << "------------------------------------------" << endl;
    cout << endl;
    cout << endl;
    cout << endl;

}

int MaiorValor (vector <int> &vetor, int ini, int fim){

    int VetorE;
    int VetorD;
    int meio;

    if (fim - ini <= 1){
        if (vetor[ini] > vetor[fim]){
            return (ini);
        }
        else{
            return (fim);
        }
    }

    else{
        meio = (ini + fim)/2;
        VetorE = MaiorValor(vetor, ini, meio);
        VetorD = MaiorValor(vetor, meio+1, fim);

        if (vetor[VetorE] >= vetor[VetorD]){
            return (VetorE);
        }
        else{
            return (VetorD);
        }
    }
}

int MergeBigger (vector <int> &vetor, int ini, int fim){

    int VetorE;
    int VetorD;
    int meio;


    if (ini == fim){
        return vetor[ini];
    }

    else{
        meio = (ini + fim)/2;
        VetorE = MergeBigger(vetor, ini, meio);
        VetorD = MergeBigger(vetor, meio+1, fim);
        if (VetorE > VetorD){
            return VetorE;
        }
        else{
            return VetorD;
        }
    }
}

int MergeSort (vector <int> &vetor, int ini, int meio, int fim){

    int i = ini;
    int j = meio;
    vector <int> VetorEspelho = vetor;
    for (int k=ini; k<fim; k++){

        if (i >= meio){
            vetor[k] = VetorEspelho[j];
            j = j+1;
        }

        else if (j >= fim){
            vetor[k] = VetorEspelho[i];
            i = i+1;
        }

        else if (VetorEspelho[i]<VetorEspelho[j]){
            vetor[k] = VetorEspelho[i];
            i = i+1;
        }

        else{
            vetor[k] = VetorEspelho[j];
            j=j+1;
        }
    }
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
