// O objetivo do algorito BruteForceClosestPair é achar os dois pontos mais próximos dado um conjunto de pontos no plano cartesiano

# include <iostream>
# include <math.h>					// sqrt, pow
# include <limits>					// numeric_limits<double>::infinity();
# include <vector>
# include <ctime>                   // time

using namespace std;

float BruteForceClosestPair (vector <int> x, vector <int> y, int n);
void VetorAleatorio (vector <int> &vetor, int tam);
void MostraVetor2 (vector <int> vetor1, vector <int> vetor2);


int main () {
    setlocale(LC_ALL, "Portuguese");                               // Recurso utilizado para conseguir imprimir acentuação e caracteres especiais

    srand(time(NULL));                                             // Utiliza o relógio interno do computador para escolher um "seed" de onde nascerão os números aleatórios.
    int n = 5;													   // Número de pontos que iremos calcular a distânica
    vector <int> x,y;                                              // Função que irá gerar o vector com os pontos (x,y) usados para calcular a distância
    VetorAleatorio(x,5);                                           // Valores aletórios para x
    VetorAleatorio(y,5);                                           // Valores aletórios para y
    MostraVetor2(x, y);
    BruteForceClosestPair (x, y, n);
return 0;
}

void VetorAleatorio (vector <int> &vetor, int tam){
    for (int i=0; i<tam; i++){
        vetor.push_back(rand() %1000);                            // Números gerados randomicamente entre 0 e 999
    }
}

void MostraVetor2 (vector <int> vetor1, vector <int> vetor2) {    // Função para mostrar os pontos aleatórios que geramos
    cout << "Pontos: { ";
    for (int i =0; i<vetor1.size(); i++ ){
        cout << "(";
        cout << vetor1[i];
        cout << ", ";
        cout << vetor2[i];
        cout <<")";
     if (i < vetor1.size()-1){
			cout <<", ";
         }
    }
    cout << " }" << endl;
}

float BruteForceClosestPair (vector <int> x, vector <int> y, int n) {

    int i, j;
    int pontoA[2], pontoB[2];
    float e;															// A variável 'e' recebe o valor da distância entre os pontos
    float d = numeric_limits<float>::infinity();						// Variável 'd' recebe um grande valor inicialmente

	for (i=0; i<n-1; i++){
		for (j=i+1;j<n;j++){
			e = (pow((x[i] - x[j]),2) + (pow((y[i] - y[j]),2)));		// A função pow(variável, expoente) calcula o exponencial
			if (e < d){													// A variável 'e' recebe o valor da distância entre os pontos e a gente compara com 'd' para saber qual a distância menor
				d = e;													// A variável 'd' sempre assume o valor da menor distância
				pontoA[0] = x[i];
				pontoA[1] = y[i];
				pontoB[0] = x[j];
				pontoB[1] = y[j];
			}
		}
	}
	cout << "Os pontos que têm a menor distância são (" <<pontoA[0] << ", " << pontoA[1] << ") e (" << pontoB[0] << ", " << pontoB[1] << ")."<< endl;
    cout << "A distância entre eles é: " << d << endl;


return 0;
}
