// O objetivo do algoritmo SequentialSearch2 � procurar dentro de um vetor um valor igual ao da key
// Caso ache, retonr a posi��o (i) do vetor. Caso contr�rio retorna -1


# include <iostream>
# include <vector>
# include <ctime>

using namespace std;

int SequentialSearch2 (vector <int> a, int k);
void VetorAleatorio (vector <int> &vetor, int tam);
void MostraVetor (vector <int> vetor, int k);


int main(){
	setlocale(LC_ALL, "Portuguese");                                // Recurso utilizado para conseguir imprimir acentua��o e caracteres especiais
	srand(time(NULL));                                              // Utiliza o rel�gio interno do computador para escolher um "seed" de onde nascer�o os n�meros aleat�rios.
	int n;  														// Vari�vel para indicar o tamanho do vector
    vector <int> NumAle;
    VetorAleatorio (NumAle, 9);                                     // Fun��o que ir� gerar o vector que que iremos fazer a busca

	int k;  														// Defini��o do valor da Key que eu irei procurar
    int a;

    cout << "Digite o valor entre 0 e 20 que ser� buscardo no vetor" << endl;
    cin >> k;

	a = SequentialSearch2 (NumAle,k);
	MostraVetor (NumAle, k);                                        // Fun��o que mostra o vector gerado
return a;
}

void VetorAleatorio (vector <int> &vetor, int tam) {
    for (int i = 0; i<tam; i++){
        vetor.push_back(rand() %20);                                // N�meros gerados randomicamente entre 0 e 19
    }
}

void MostraVetor (vector <int> vetor, int k) {                             // Fun��o para mostrar os elementos do vector aleat�rio que geramos

    cout << "O vetor analisado: {";
    for (int i =0; i<vetor.size(); i++ ){
     cout << vetor[i];
     if (i < vetor.size()-1){
            cout << ",";
		}
    }
    cout << "}" << endl;
}

int SequentialSearch2 (vector <int> a, int k) {

    a.push_back(k); 												// Adiciona o valor de 'k' ao final do vector para termos um crit�rio de parada na busca
	int i;
	i = 0;

	while (a[i] != k) {												// Faz a busca at� encontrar um valor igual a 'k'
		i++;
	}

	if (i != a.size()-1) {											// Se encontrar retornar a posi��o 'i' do vetor
		return i;

	} else {
		return -1;													// Se n�o encontrar retorna -1
	}

}
