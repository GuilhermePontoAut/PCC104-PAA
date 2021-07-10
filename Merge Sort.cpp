// FAMÍLIA: DIVIDE AND CONQUER / DIVIDIR E CONQUISTAR
//
// O algoritmo MERGE SORT tem como objetivo ordenar um vetor de números inteiros e aleatórios utilizando para isso a técnica de DIVIDIR E CONQUISTAR


# include <iostream>
# include <vector>
# include <ctime>

using namespace std;

void MergeSort (vector <int> &vetor, int INI, int FIM);
void Merge (vector <int> &vetor, int INI, int MEIO, int FIM);
void MontarVetor(vector <int> &vetor, int n);
void MostraVetor (vector <int> vetor);


int main (){
    setlocale(LC_ALL, "Portuguese");
    srand(time(NULL));

    vector<int> vetor;
    int n=4;

    MontarVetor(vetor,n);
    cout<< "\nVetor com números aleatórios: ";
    MostraVetor(vetor);
    MergeSort(vetor,0,n);
    cout << "\n--------------------------------------------";
    cout<< "\n O vetor ordenado é: ";
    MostraVetor(vetor);
    cout << "--------------------------------------------"<< endl;
    cout << endl;
    cout << endl;

}

void MergeSort (vector <int> &vetor, int INI, int FIM) {

    if ((FIM - INI)>1){
        int MEIO = (FIM + INI)/2;
        MergeSort(vetor, INI, MEIO);
        MergeSort(vetor, MEIO, FIM);
        Merge(vetor, INI, MEIO, FIM);
    }
}

void Merge (vector <int> &vetor, int INI, int MEIO, int FIM){

    vector <int> ESQ;
    vector <int> DIR;
    int i=0;
    int j=0;

    ESQ = {vetor.begin()+INI, vetor.begin()+MEIO};
    DIR = {vetor.begin()+MEIO, vetor.begin()+FIM};

    for(int k=INI; k<FIM; k++){

        if (i>=ESQ.size()){
            vetor[k]=DIR[j];
            j = j + 1;
        }

        else if (j>=DIR.size()){
            vetor[k]=ESQ[i];
            i = i + 1;
        }

        else if (ESQ[i]<DIR[j]){
            vetor[k]=ESQ[i];
            i = i + 1;
        }
        else{
            vetor[k]=DIR[j];
            j = j + 1;
        }
    }
}

void MontarVetor (vector <int> &vetor, int tam){
    for (int i=0; i<tam; i++){
        vetor.push_back(rand() %100);
    }
}

void MostraVetor (vector <int> vetor){
    cout<< "{";
    for (int i; i<vetor.size(); i++){
        cout<< vetor[i];
        if (i<vetor.size()-1){
            cout<<",";
        }
    }
    cout<<"}"<< endl;
}



