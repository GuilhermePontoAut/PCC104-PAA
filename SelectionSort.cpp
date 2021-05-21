// O algoritmo SelectionSort tem como objetivo ordenar os valores que estão dentro de um vetor do menor para o maior
// Ele faz isso escolhendo o valor da primeira posição para ser o 'valor mínimo'. Ele então compara esse valor mínimo com todas as posições do vetor
// Se achar um valor menor ele troca eles de posição e continua comparando. Ao achegar ao final do vetor, ele troca o valor do 'mínimo' e inicia todo o processo novamente

# include <iostream>
# include <vector>
# include <ctime>                   // time

using namespace std;

void SelectionSort (vector <int> a, int n);
void VetorAleatorio (vector <int> &vetor, int tam);
void MostraVetor (vector <int> vetor);


int main(){
    srand(time(NULL));                                              // Utiliza o relógio interno do computador para escolher um "seed" de onde nascerão os números aleatórios.
    int n;  														// Variável para indicar o tamanho do vector
    vector <int> VetAle;
    VetorAleatorio (VetAle, 9);                                     // Função que irá gerar o vector que será ordenado
    //MostraVetor (VetAle);                                         // Função que mostra o vector gerado

    n = VetAle.size();
	SelectionSort (VetAle,n);

return 0;
}

void VetorAleatorio (vector <int> &vetor, int tam) {
    for (int i = 0; i<tam; i++){
        vetor.push_back(rand() %100);                               // números gerados randomicamente entre 0 e 99
    }
}

void MostraVetor (vector <int> vetor) {                             // Função para mostrar os elementos do vector aleatório que geramos
    for (int i =0; i<vetor.size(); i++ ){
     cout << vetor[i] << endl;
    }
}

void SelectionSort (vector <int> a, int n) {

	int i, j, aux, min;

	for (i=0; i<n-1; i++)	{
		min = i;															// Define que o valor mínimo é o valor da primeira posição do vetor
		for (j=i+1; j<n; j++){
			if (a[j] < a[min]) {											// Analisando se o valor na posição 'j' é menor que o 'valor mínimo'
				aux = a[min];
				a[min] = a[j];
				a[j] = aux;
			}
		}
	}

	cout << "O vetor ordenado é: {";										// Imprimindo o vetor depois que foi ordenado
	for (i=0; i<n; i++){
		cout << a[i];
		if (i < n-1){
			cout << ", ";

		}
	}
	cout << "}" << endl;
}
