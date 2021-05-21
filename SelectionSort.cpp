// O algoritmo SelectionSort tem como objetivo ordenar os valores que est�o dentro de um vetor do menor para o maior
// Ele faz isso escolhendo o valor da primeira posi��o para ser o 'valor m�nimo'. Ele ent�o compara esse valor m�nimo com todas as posi��es do vetor
// Se achar um valor menor ele troca eles de posi��o e continua comparando. Ao achegar ao final do vetor, ele troca o valor do 'm�nimo' e inicia todo o processo novamente

# include <iostream>
# include <vector>
# include <ctime>                   // time

using namespace std;

void SelectionSort (vector <int> a, int n);
void VetorAleatorio (vector <int> &vetor, int tam);
void MostraVetor (vector <int> vetor);


int main(){
    srand(time(NULL));                                              // Utiliza o rel�gio interno do computador para escolher um "seed" de onde nascer�o os n�meros aleat�rios.
    int n;  														// Vari�vel para indicar o tamanho do vector
    vector <int> VetAle;
    VetorAleatorio (VetAle, 9);                                     // Fun��o que ir� gerar o vector que ser� ordenado
    //MostraVetor (VetAle);                                         // Fun��o que mostra o vector gerado

    n = VetAle.size();
	SelectionSort (VetAle,n);

return 0;
}

void VetorAleatorio (vector <int> &vetor, int tam) {
    for (int i = 0; i<tam; i++){
        vetor.push_back(rand() %100);                               // n�meros gerados randomicamente entre 0 e 99
    }
}

void MostraVetor (vector <int> vetor) {                             // Fun��o para mostrar os elementos do vector aleat�rio que geramos
    for (int i =0; i<vetor.size(); i++ ){
     cout << vetor[i] << endl;
    }
}

void SelectionSort (vector <int> a, int n) {

	int i, j, aux, min;

	for (i=0; i<n-1; i++)	{
		min = i;															// Define que o valor m�nimo � o valor da primeira posi��o do vetor
		for (j=i+1; j<n; j++){
			if (a[j] < a[min]) {											// Analisando se o valor na posi��o 'j' � menor que o 'valor m�nimo'
				aux = a[min];
				a[min] = a[j];
				a[j] = aux;
			}
		}
	}

	cout << "O vetor ordenado �: {";										// Imprimindo o vetor depois que foi ordenado
	for (i=0; i<n; i++){
		cout << a[i];
		if (i < n-1){
			cout << ", ";

		}
	}
	cout << "}" << endl;
}
