// Traveling Salesman Problem ou Problema do Caixeiro Viajante
// Problema do caixeiro viajante: o prop�sito deste algoritmo � apresentar a solu��o para o problema do CAIXEIRO VIAJANTE usando um algoritmo de BUSCA EXAUSTIVA.
// O problema do caixeiro viajante �: dado 'n' cidades e determinando uma cidade como ponto de partida, achar o caminho de menor custo para passar em todas as cidades
//uma �nica vez e retornar � cidade de origem.
// Permuta��es s�o agrupamentos formados com 'n' elementos, de forma que a ordem desses elementos � sempre diferente. Existem 2 tipos de permuta��o: com repeti��o e sem repeti��o.
// O comando next_permutation faz permuta��o sem repeti��o partindo do elemento que voc� indicar como primeiro e depois ir� permutar os elementos que forem maiores que ele!
// E por conta do comando next_permutation fazer permuta��o em ordem crescente, temos que usar o comando 'sort' para orden�-los e assim nenhum elemnto ficar� sem ser permutado.
// Comando 'sort' foi retirado!!!!
// A fun��o custo desse problema do CAIXEIRO VIAJANTE � a dist�ncia entre dois pontos!

# include <iostream>
# include <algorithm>				// next_permutation
# include <math.h>					// sqrt, pow
# include <limits>					// numeric_limits<double>::infinity();
# include <vector>
# include <ctime>                   // time

using namespace std;

void VetorAleatorio (vector <int> &vetor, int tam);
float Custo (vector <int> PosX, vector <int> PosY);
vector<vector<int>> Caminho (vector <int> x, vector <int> y);
void CaixeiroViajante (vector <int> x, vector <int> y);


int main () {
    setlocale(LC_ALL, "Portuguese");
    srand(time(NULL));

    int n = 5;                                                              // N�mero de cidades que iremos calcular a melhor rota
    vector <int> x;                                                         // Vector que receber� as abscissas das cidades para calcular a dist�ncia
    vector <int> y;                                                         // Vector que receber� as ordenadas das cidades para calcular a dist�ncia
    VetorAleatorio(x,n);                                                    // Fun��o para gerar os valores aleat�rios das coordenadas das cidades no plano cartesiano
    VetorAleatorio(y,n);                                                    // Fun��o para gerar os valores aleat�rios das coordenadas das cidades no plano cartesiano

    /*int AA[5] = {0,1,2,3,4};                                                // TESTE: para criar vetor de teste conhecido
    int BB[5] = {0,1,2,1,2};                                                // TESTE: para criar vetor de teste conhecido
    for (int i=0; i<5; i++){                                                // TESTE: para criar vetor de teste conhecido
        x.push_back(AA[i]);                                                 // TESTE: para criar vetor de teste conhecido
    }                                                                       // TESTE: para criar vetor de teste conhecido
    for (int i=0; i<5; i++){                                                // TESTE: para criar vetor de teste conhecido
        y.push_back(BB[i]);                                                 // TESTE: para criar vetor de teste conhecido
    }*/

    CaixeiroViajante (x, y);                                                // Chamando a fun��o que ir� resolver o problema do Caixeiro Viajante
}


void CaixeiroViajante (vector <int> x, vector <int> y) {

    int i,j,z;                                                              // Vari�veis usadas para fazer as itera��es. S�o 3 FOR, ent�o precisamos de 3 vari�veis.
    int n=x.size()-1;                                                       // O vetor come�a em zero, logo o n�mero da vari�vel "n" ser� sempre o tamanho do vetor menos 1!!!
    float CustoSoma;                                                        // Vari�vel para guardar o valor do custo do percurso escolhido
    float CustoMenor = numeric_limits<float>::infinity();				    // Vari�vel que guardar� o menor custo encontrado e ser� usado para compara��o

    vector<vector<int>> MelhorCaminho;                                      // Vector para armazenar as coordenadas (x,y) do melhor caminho
    vector <int> x_iter;                                                    // Vector que ir� auxiliar para a parada do WHILE
    vector <int> x_orig = x;                                                // Vector que ir� receber o vector original "x"
    vector <int> y_orig = y;                                                // Vector que ir� receber o vector original "y"

    if (n==4){                                                              // Itera��o utilizada quando se tem 5 cidades para permutar
        for (j=n; j>=0; j--){
            x = x_orig;                                                     // Sempre retornamos os elementos do vector "x" para a posi��o original antes de fazer o swap da posi��o 4
            y = y_orig;                                                     // Sempre retornamos os elementos do vector "y" para a posi��o original antes de fazer o swap da posi��o 4
            swap(x[n],x[j]);
            swap(y[n],y[j]);
            for (i=n-1; i>=0; i--){
                swap(x[n-1],x[i]);                                          // Swap da posi��o 3 ocorrendo depois de ter feito todas as combina��es dos 3 primeiros elementos
                swap(y[n-1],y[i]);
                x_iter = x;                                                 // Vari�vel que ser� usada logo abaixo como crit�rio de parada
                do{
                    for (z=2; z>0; z--){
                        swap(x[z],x[z-1]);                                  // Swap das posi��es 1,2,3 do vetor
                        swap(y[z],y[z-1]);
                        CustoSoma = Custo (x,y);
                        if (CustoSoma < CustoMenor)	{					    // Se o caminho tem custo menor, ent�o eu irei guardar seu valor e sua rota
                            CustoMenor = CustoSoma;
                            MelhorCaminho = Caminho(x,y);
                        }
                    }
                }while (x!=x_iter);                                         // Crit�rio de parada: para quando o vetor gerado for igual ao vetor inicial
            }
        }
    }

    if (n==3){                                                              // Itera��o utilizada quando se tem 4 cidades para permutar
        for (j=n; j>=0; j--){
            x = x_orig;
            swap(x[n],x[j]);
            swap(y[n],y[j]);
                x_iter = x;
                do{
                    for (z=2; z>0; z--){
                        swap(x[z],x[z-1]);
                        swap(y[z],y[z-1]);
                        CustoSoma = Custo (x,y);
                        if (CustoSoma < CustoMenor)	{
                            CustoMenor = CustoSoma;
                            MelhorCaminho = Caminho(x,y);
                        }
                    }
                }while (x!=x_iter);
        }
    }

    if (n==2) {                                                             // Itera��o utilizada quando se tem 3 cidades para permutar
        x_iter = x;
        do {
            for (i=n; i>0; i--){
                swap(x[i],x[i-1]);
                swap(y[i],y[i-1]);
                CustoSoma = Custo (x,y);
                if (CustoSoma < CustoMenor)	{
                    CustoMenor = CustoSoma;
                    MelhorCaminho = Caminho(x,y);
                }
            }
        }while (x!=x_iter);
    }

	cout << "-> Total de cidades  : " << x.size() << endl;
	cout << "-> O melhor caminho �: "<< endl;;
	for (auto segment : MelhorCaminho) {
        cout << "                       [" <<  segment[0] << " , " << segment[1] <<"] " << " [" << segment[2] << " , " << segment[3] << "]" << endl;
	}
	cout << endl;
	cout << "--> Custo do melhor caminho : " << CustoMenor << endl;

}

float Custo (vector <int> PosX, vector <int> PosY){
    float CustoT;														    // Vari�vel auxiliar utilizada para receber o custo do trecho
	float CustoSoma; 													    // Vari�vel auxiliar que ir� guardar a soma dos custos dos trechos
    int n;

    n = PosX.size();
    CustoSoma = 0;

    PosX.push_back(PosX[0]);                                                // Adicionando a cidade de origem ao final do vector.
    PosY.push_back(PosY[0]);                                                // Adicionando a cidade de origem ao final do vector.

	for (int i=0; i<n; i++){
		CustoT = pow((PosX[i+1]-PosX[i]),2) + pow((PosY[i+1]-PosY[i]),2);	// A fun��o pow(vari�vel, expoente) calcula o exponencial
    	CustoT = sqrt(CustoT);										        // Calcula a raiz quadrada para determinar a dist�ncia entre 2 pontos a partir de suas coordenadas (x,y)
    	CustoSoma = CustoSoma + CustoT;								        // A vari�vel 'CustoSoma' guarda o somat�rios dos custos dos trechos e assim no final eu terei o custo total do caminho
    }
return CustoSoma;
}

vector<vector<int>> Caminho (vector <int> x, vector <int> y){
    vector<vector<int>> MelhorCaminho;                                      // Vetor para guardar o melhor caminho. Como come�a e termina na mesma cidade, o caminho � composto de 'n+1" cidades
    int n;
    n= x.size();
    x.push_back(x[0]);                                                      // Adicionando a cidade de origem ao final do vector.
    y.push_back(y[0]);                                                      // Adicionando a cidade de origem ao final do vector.
    for (int i=0; i<n; i++){
        MelhorCaminho.push_back({x[i], y[i], x[i+1], y[i+1]});              //Adiciona ao vector MelhorCaminho os pontos do plano que representam o melhor caminho
    }
return MelhorCaminho;
}

void VetorAleatorio (vector <int> &vetor, int tam){                         // Fun��o parar gerar os pontos no espa�o.
    for (int i=0; i<tam; i++){
        vetor.push_back(rand() %1000);                                      // N�meros gerados randomicamente entre 0 e 999
    }
}
