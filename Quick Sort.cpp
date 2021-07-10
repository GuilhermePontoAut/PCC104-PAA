// FAMÍLIA: DIVIDE AND CONQUER / DIVIDIR E CONQUISTAR
//
// O algoritmo QUICK SORT tem como objetivo ordenar um vetor de números inteiros e aleatórios utilizando para isso a técnica de DIVIDIR E CONQUISTAR


# include <iostream>
# include <vector>


using namespace std;

void MostrarVetor (vector <double> vetor);
void VetorAleatorio (vector <double> &x, int tam);
void QuickSort(vector <double> &data, int ini, int fim);
double Particao(vector <double> &data, int ini, int fim);


int main (){

    setlocale(LC_ALL, "Portuguese");
    vector <double> vetor;
    int n = 15;
    VetorAleatorio(vetor, n);

    cout<< "\nVetor com números aleatórios: ";
    MostrarVetor(vetor);
    QuickSort(vetor, 0, n-1);
    cout << "\n----------------------------------------------------------------------------";
    cout<< "\n O vetor ordenado é: ";
    MostrarVetor(vetor);
    cout << "----------------------------------------------------------------------------"<< endl;
    cout << endl;
    cout << endl;
}

void VetorAleatorio (vector <double> &x, int tam) {
    for (int i=0; i<tam; i++){
        x.push_back(rand() %50);
    }
}

void MostrarVetor (vector <double> vetor){
    cout << "{ ";
    for(int i=0; i<vetor.size(); i++){
        cout << vetor[i];
        if (i<vetor.size()-1){
            cout << ",";
        }
    }
    cout <<" }" << endl;
}

 double Particao (vector <double> &data, int ini, int fim){

    int pivot = data[fim];
    int i = ini-1;

    for (int j = ini; j <= fim - 1; j++){
        if (data[j] <= pivot){
            i++;
            swap(data[i], data[j]);
        }
    }
    swap(data[i + 1], data[fim]);
    return (i + 1);
}

void QuickSort(vector <double> &data, int ini, int fim){
    if (ini < fim){
        int posicao = Particao(data, ini, fim);
        QuickSort(data, ini, posicao - 1);
        QuickSort(data, posicao + 1, fim);
    }
}
