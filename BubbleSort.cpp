// O algoritmo BubbleSort tem como objetivo ordenar os valores que estão dentro de um vetor do menor para o maior
// Ele faz isso comparando um número na posição 'i' com seu sucessor na posição 'i+1', caso seja menor fazemos o swap. Caso não seja comparamos a próxima dupla


# include <iostream>
# include <vector>
# include <ctime>                   // time

using namespace std;

void BubbleSort (vector <int> a, int n);
void VetorAleatorio (vector <int> &vetor, int tam);
void MostraVetor (vector <int> vetor);


int main(){
	srand(time(NULL));                                              // Utiliza o relógio interno do computador para escolher um "seed" de onde nascerão os números aleatórios.
	int n;  														// Variável para indicar o tamanho do vector
    vector <int> VetAle;
    VetorAleatorio (VetAle, 9);                                     // Função que irá gerar o vector que será ordenado
    //MostraVetor (NumAle);                                         // Função que mostra o vector gerado

    n = VetAle.size();
	BubbleSort (VetAle,n);

return 0;
}

void VetorAleatorio (vector <int> &vetor, int tam) {
    for (int i = 0; i<tam; i++){
        vetor.push_back(rand() %100);                               // Números gerados randomicamente entre 0 e 99
    }
}

void MostraVetor (vector <int> vetor) {                             // Função para mostrar os elementos do vector aleatório que geramos
    for (int i =0; i<vetor.size(); i++ ){
     cout << vetor[i] << endl;
    }
}

void BubbleSort (vector <int> a, int n) {

    int i, j, aux;

	for (i=0; i<n-1; i++)	{
		for (j=0; j<n-1-i; j++){
			if (a[j+1] < a[j]) {											// Analisando se o número na posição 'j+1' é menor que o número na posição 'j'
				aux = a[j];													// Se for, iremos trocar ele de posição
				a[j] = a[j+1];
				a[j+1] = aux;
			}
		}
	}

	cout << "O vetor ordenado é: {";										// Imprimindo o vector depois que foi ordenado
	for (i=0; i<n; i++){
		cout << a[i];
		if (i < n-1){
			cout << ", ";
		}
	}
	cout << "}" << endl;
}
