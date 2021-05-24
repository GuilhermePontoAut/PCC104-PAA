// FAM�LIA: DECREASE AND CONQUER / DIMINUIR PARA CONQUISTAR
//
// O algoritmo Johnson-Trotter tem como objetivo gerar todas as permuta��es de um vetor de n�meros inteiros de tamanho "n"



# include <iostream>
# include <vector>


using namespace std;

void MontarVetor (vector <int> &vetor, vector <bool> &VetDirecao, int n);
void MostrarVetor (vector <int> vetor);
void Permutacao(vector <int> vetor, vector <bool> VetDirecao);
void Swap2 (vector <int> &vetor, vector <bool> &direcao);

int main () {
    setlocale(LC_ALL, "Portuguese");                           // Recurso utilizado para conseguir imprimir acentua��o e caracteres especiais

    int n;                                                     // Vari�vel que define o tamanho do vector a ser permutado
    vector <int> vetor;                                        // Vector que guardar� todos os n�meros inteiros que ser�o utilizados na permuta��o
    vector <bool> VetDirecao;                                  // Vector que guardar� todas as "setas" necess�rias no algoritmo de Johnson-Trotter

    cout << "Defina o tamanho do vetor: ";
    cin >> n;
    cout << endl;

    MontarVetor(vetor, VetDirecao, n);
    cout << "As permuta��es para um vetor de tamanho " << n << " s�o :"<< endl;

    Permutacao(vetor, VetDirecao);
}

void MontarVetor (vector <int> &vetor, vector <bool> &VetDirecao, int n){
    for (int i=0; i<n; i++){
        vetor.push_back(i+1);
        VetDirecao.push_back(false);                             //FALSE = seta da direita para esquerda ; TRUE = seta da esquerda para a direita;
    }
}

void MostrarVetor (vector <int> vetor){                         // Fun��o criada para imprimir todos os valores do vector
    cout << "{";
    for (int i=0; i<vetor.size(); i++){
        cout << vetor[i];
        if (i<vetor.size()-1){
            cout << ", ";
        }
    }
    cout << "}" << endl;
}

void Permutacao(vector <int> vetor, vector <bool> VetDirecao){  // Fun��o que ir� criar as permuta��es do algoritmo

    int i;
    int n = vetor.size();
    vector <int> vetor_orig = vetor;                            // A vari�vel vetor_orig ser� usada como crit�rio de parada do WHILE

    do{
    for (i=n-1; i>0; i--){
        MostrarVetor(vetor);                                    // Mostra (n-1) permuta��es toda vez que for acionado
        swap(vetor[i], vetor[i-1]);                             // Ir� fazer o swap at� que o valor "n" saia da posi��o "n" e chegue na posi��o "0"
        swap(VetDirecao[i], VetDirecao[i-1]);                   // O vector direcional acompanha o vector dos valores a serem permutados
    }

    MostrarVetor(vetor);                                        // Ir� mostrar a (en�sima) permuta��o, pois no "for" acima ele sai nessa condi��o (i=0) e dessa forma falta mostrar 1 permuta��o
    Swap2(vetor, VetDirecao);                                   // A cada n permuta��es o valor n chega a posi��o zero e ent�o chamamos essa fun��o

    for (i=0; i<n-1; i++){
        MostrarVetor(vetor);
        swap(vetor[i], vetor[i+1]);
        swap(VetDirecao[i], VetDirecao[i+1]);
    }
    MostrarVetor(vetor);
    Swap2(vetor, VetDirecao);                                   // A cada n permuta��es o valor n chega a posi��o "n" e ent�o chamamos essa fun��o

    }while (vetor != vetor_orig);                               // Crit�rio de parada: enquanto o vector n�o for igual ao inicial, a fun��o PERMUTACAO ir� continuar iterando
}

void Swap2 (vector <int> &vetor, vector <bool> &direcao){       // Essa fun��o ir� descobrir qual posi��o sofrer� swap e ir� mudar o sentido da seta de todas posi��es que tiverem valor maior
                                                                //que o valor da posi��o que sofreu swap.
    int n = vetor.size()-1;                                     //Ex: n=4; posi��o que sofrer� swap tem valor igual a 2; logo todas posi��es com valor maior que 2, ter�o o sentido da seta alterado
    int PosMob2;                                                // Posi��o que iremos fazer swap
    int i;

    for (i=0; i<n; i++){
        if (vetor[i] < vetor[i+1] && direcao[i+1] == false) {   // Se o valor no vector for menor que seu sucessor e este possuir seta sentido FALSE, [i+1] ser� escolhido para o swap.
            PosMob2=i+1;
        }
        if (vetor [i] > vetor [i+1] && direcao[i] == true){     // Se o valor no vector for maior que seu sucessor e possuir seta sentido TRUE, ele [i] ser� escolhido para o swap.
            PosMob2=i;
        }
    }

     for (i=0; i<=n; i++){                                      // Essa fun��o ir� mudar o sentido da seta de todas posi��es que tiverem valor maior que o valor da posi��o PosMob2
        if (vetor[i]>vetor[PosMob2]){
            direcao[i] = !direcao[i];
        }
    }

    if (direcao[PosMob2] == false){                             // Essa fun��o ir� fazer o swap da pos��o PosMob2 com seu antecessor
        swap(vetor[PosMob2], vetor[PosMob2-1]);
        swap(direcao[PosMob2], direcao[PosMob2-1]);
        }
    else{                                                       // Essa fun��o ir� fazer o swap da pos��o PosMob2 com seu sucessor
        swap(vetor[PosMob2], vetor[PosMob2+1]);
        swap(direcao[PosMob2], direcao[PosMob2+1]);
        }
}
