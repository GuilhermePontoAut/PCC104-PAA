// O algoritmo BubbleSort tem como objetivo ordenar os valores que est�o dentro de um vetor do menor para o maior
// Ele faz isso comparando um n�mero na posi��o 'i' com seu sucessor na posi��o 'i+1', caso seja menor fazemos o swap. Caso n�o seja comparamos a pr�xima dupla


# include <iostream>
# include <vector>
# include <ctime>                   // time

using namespace std;

void BubbleSort (vector <int> a, int n);
void VetorAleatorio (vector <int> &vetor, int tam);
void MostraVetor (vector <int> vetor);


int main(){
	srand(time(NULL));                                              // Utiliza o rel�gio interno do computador para escolher um "seed" de onde nascer�o os n�meros aleat�rios.
	int n;  														// Vari�vel para indicar o tamanho do vector
    vector <int> VetAle;
    VetorAleatorio (VetAle, 9);                                     // Fun��o que ir� gerar o vector que ser� ordenado
    //MostraVetor (NumAle);                                         // Fun��o que mostra o vector gerado

    n = VetAle.size();
	BubbleSort (VetAle,n);

return 0;
}

void VetorAleatorio (vector <int> &vetor, int tam) {
    for (int i = 0; i<tam; i++){
        vetor.push_back(rand() %100);                               // N�meros gerados randomicamente entre 0 e 99
    }
}

void MostraVetor (vector <int> vetor) {                             // Fun��o para mostrar os elementos do vector aleat�rio que geramos
    for (int i =0; i<vetor.size(); i++ ){
     cout << vetor[i] << endl;
    }
}

void BubbleSort (vector <int> a, int n) {

    int i, j, aux;

	for (i=0; i<n-1; i++)	{
		for (j=0; j<n-1-i; j++){
			if (a[j+1] < a[j]) {											// Analisando se o n�mero na posi��o 'j+1' � menor que o n�mero na posi��o 'j'
				aux = a[j];													// Se for, iremos trocar ele de posi��o
				a[j] = a[j+1];
				a[j+1] = aux;
			}
		}
	}

	cout << "O vetor ordenado �: {";										// Imprimindo o vector depois que foi ordenado
	for (i=0; i<n; i++){
		cout << a[i];
		if (i < n-1){
			cout << ", ";
		}
	}
	cout << "}" << endl;
}
