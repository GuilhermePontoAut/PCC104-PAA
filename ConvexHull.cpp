// Convex Hull: esse algorito tem como propósito a solução do problema de Convex Hull.
// Dado um conjunto de n pontos em um plano, o convex hull (casco convexo) desse conjunto de pontos é o menor polígono convexo que contém todos estes pontos em seus limites.
// Primeira verificação: dada um conjunto de pontos em um plano bidimensional, escolha dois pontos e forme um segmento de reta. A verficação nos retornará que este segmento de reta
// faz parte dos segmentos que formarão o CONVEX HULL se TODOS os demais pontos estiverem do mesmo lado, ou seja, TODOS devem estar ACIMA ou ABAIXO do segmento de reta.

# include <iostream>
# include <ctime>                   // time
# include <vector>

using namespace std;

vector <int> VetorAleatorio (vector <int> &vetor, int tam);
vector<vector<int>> VarrerPontos (vector <int> &x, vector <int> &y);
void ImprimeSegmentos(vector<vector<int>> &segmentos);


int main () {
        setlocale(LC_ALL, "Portuguese");                           // Recurso utilizado para conseguir imprimir acentuação e caracteres especiais
        srand(time(NULL));                                         // Utiliza o relógio interno do computador para escolher uma semente para gerar os números aleatórios.
        int n = 16;
        vector <int> x;
        vector <int> y;

        /*int aa[16] = {3,1,3,6,9,10,9,6,8,7,6,5,4,5,6,7};         // TESTE: para criar vetor de teste conhecido
        int bb[16] = {3,6,9,10,9,6,3,1,4,4,4,4,4,6,6,6};           // TESTE: para criar vetor de teste conhecido
        for (int i=0; i<16; i++){                                  // TESTE: para criar vetor de teste conhecido
            x.push_back(aa[i]);                                    // TESTE: para criar vetor de teste conhecido
        }                                                          // TESTE: para criar vetor de teste conhecido
        for (int i=0; i<16; i++){                                  // TESTE: para criar vetor de teste conhecido
            y.push_back(bb[i]);                                    // TESTE: para criar vetor de teste conhecido
        }*/

        VetorAleatorio(x, n);
        VetorAleatorio(y, n);

        vector<vector<int>> segmentos = VarrerPontos(x, y);
        ImprimeSegmentos(segmentos);
}

vector <int> VetorAleatorio (vector <int> &vetor, int tam){        // Função parar gerar os pontos no espaço.
    for (int i=0; i<tam; i++){
        vetor.push_back(rand() %1000);                             // Números gerados randomicamente entre 0 e 999
    }
    return vetor;
}

vector<vector<int>> VarrerPontos (vector <int> &x, vector <int> &y){

    vector<vector<int>> segmentos;

    for (int i=0; i<x.size()-1; i++){
        for (int j=i+1; j<x.size(); j++){
            int a = y[j] - y[i];
            int b = x[i] - x[j];
            int c = x[i]*y[j] - x[j]*y[i];

            bool flag = false;
            int auxprev = 0;

            for (int k=0; k<x.size(); k++){

                if (k != i && k!=j){

                    int aux = (a*x[k] + b*y[k] < c) ? -1 : 1;

                    if (auxprev == 0) {
                        auxprev = aux;
                    }
                    else if (auxprev != aux){
                        flag = true;
                        break;
                    }

                }
            }
                if (!flag) {
                segmentos.push_back ({x[i], y[i], x[j], y[j]});
                }
        }
    }
    return segmentos;
}

void ImprimeSegmentos(vector<vector<int>> &segmentos) {
	for (auto segment : segmentos) {
		 cout << "[" <<  segment[0] << " , " << segment[1] <<"] " << " [" << segment[2] << " , " << segment[3] << "]" << endl;
	}
}
