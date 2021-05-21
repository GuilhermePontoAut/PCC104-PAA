// O objetivo do algoritmo SequentialSearch2 é procurar dentro de um vetor um valor igual ao da key
// Caso ache, retonr a posição (i) do vetor. Caso contrário retorna -1


# include <iostream>
# include <vector>
# include <ctime>

using namespace std;

int SequentialSearch2 (vector <int> a, int k);
void VetorAleatorio (vector <int> &vetor, int tam);
void MostraVetor (vector <int> vetor, int k);


int main(){
	setlocale(LC_ALL, "Portuguese");                                // Recurso utilizado para conseguir imprimir acentuação e caracteres especiais
	srand(time(NULL));                                              // Utiliza o relógio interno do computador para escolher um "seed" de onde nascerão os números aleatórios.
	int n;  														// Variável para indicar o tamanho do vector
    vector <int> NumAle;
    VetorAleatorio (NumAle, 9);                                     // Função que irá gerar o vector que que iremos fazer a busca

	int k;  														// Definição do valor da Key que eu irei procurar
    int a;

    cout << "Digite o valor entre 0 e 20 que será buscardo no vetor" << endl;
    cin >> k;

	a = SequentialSearch2 (NumAle,k);
	MostraVetor (NumAle, k);                                        // Função que mostra o vector gerado
return a;
}

void VetorAleatorio (vector <int> &vetor, int tam) {
    for (int i = 0; i<tam; i++){
        vetor.push_back(rand() %20);                                // Números gerados randomicamente entre 0 e 19
    }
}

void MostraVetor (vector <int> vetor, int k) {                             // Função para mostrar os elementos do vector aleatório que geramos

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

    a.push_back(k); 												// Adiciona o valor de 'k' ao final do vector para termos um critério de parada na busca
	int i;
	i = 0;

	while (a[i] != k) {												// Faz a busca até encontrar um valor igual a 'k'
		i++;
	}

	if (i != a.size()-1) {											// Se encontrar retornar a posição 'i' do vetor
		return i;

	} else {
		return -1;													// Se não encontrar retorna -1
	}

}
