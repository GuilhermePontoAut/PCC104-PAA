// FAMÍLIA: DECREASE AND CONQUER / DIMINUIR PARA CONQUISTAR
//
// O algoritmo Johnson-Trotter tem como objetivo gerar todas as permutações de um vetor de números inteiros de tamanho "n"



# include <iostream>
# include <vector>


using namespace std;

void MontarVetor (vector <int> &vetor, vector <bool> &VetDirecao, int n);
void MostrarVetor (vector <int> vetor);
void Permutacao(vector <int> vetor, vector <bool> VetDirecao);
void Swap2 (vector <int> &vetor, vector <bool> &direcao);

int main () {
    setlocale(LC_ALL, "Portuguese");                           // Recurso utilizado para conseguir imprimir acentuação e caracteres especiais

    int n;                                                     // Variável que define o tamanho do vector a ser permutado
    vector <int> vetor;                                        // Vector que guardará todos os números inteiros que serão utilizados na permutação
    vector <bool> VetDirecao;                                  // Vector que guardará todas as "setas" necessárias no algoritmo de Johnson-Trotter

    cout << "Defina o tamanho do vetor: ";
    cin >> n;
    cout << endl;

    MontarVetor(vetor, VetDirecao, n);
    cout << "As permutações para um vetor de tamanho " << n << " são :"<< endl;

    Permutacao(vetor, VetDirecao);
}

void MontarVetor (vector <int> &vetor, vector <bool> &VetDirecao, int n){
    for (int i=0; i<n; i++){
        vetor.push_back(i+1);
        VetDirecao.push_back(false);                             //FALSE = seta da direita para esquerda ; TRUE = seta da esquerda para a direita;
    }
}

void MostrarVetor (vector <int> vetor){                         // Função criada para imprimir todos os valores do vector
    cout << "{";
    for (int i=0; i<vetor.size(); i++){
        cout << vetor[i];
        if (i<vetor.size()-1){
            cout << ", ";
        }
    }
    cout << "}" << endl;
}

void Permutacao(vector <int> vetor, vector <bool> VetDirecao){  // Função que irá criar as permutações do algoritmo

    int i;
    int n = vetor.size();
    vector <int> vetor_orig = vetor;                            // A variável vetor_orig será usada como critério de parada do WHILE

    do{
    for (i=n-1; i>0; i--){
        MostrarVetor(vetor);                                    // Mostra (n-1) permutações toda vez que for acionado
        swap(vetor[i], vetor[i-1]);                             // Irá fazer o swap até que o valor "n" saia da posição "n" e chegue na posição "0"
        swap(VetDirecao[i], VetDirecao[i-1]);                   // O vector direcional acompanha o vector dos valores a serem permutados
    }

    MostrarVetor(vetor);                                        // Irá mostrar a (enésima) permutação, pois no "for" acima ele sai nessa condição (i=0) e dessa forma falta mostrar 1 permutação
    Swap2(vetor, VetDirecao);                                   // A cada n permutações o valor n chega a posição zero e então chamamos essa função

    for (i=0; i<n-1; i++){
        MostrarVetor(vetor);
        swap(vetor[i], vetor[i+1]);
        swap(VetDirecao[i], VetDirecao[i+1]);
    }
    MostrarVetor(vetor);
    Swap2(vetor, VetDirecao);                                   // A cada n permutações o valor n chega a posição "n" e então chamamos essa função

    }while (vetor != vetor_orig);                               // Critério de parada: enquanto o vector não for igual ao inicial, a função PERMUTACAO irá continuar iterando
}

void Swap2 (vector <int> &vetor, vector <bool> &direcao){       // Essa função irá descobrir qual posição sofrerá swap e irá mudar o sentido da seta de todas posições que tiverem valor maior
                                                                //que o valor da posição que sofreu swap.
    int n = vetor.size()-1;                                     //Ex: n=4; posição que sofrerá swap tem valor igual a 2; logo todas posições com valor maior que 2, terão o sentido da seta alterado
    int PosMob2;                                                // Posição que iremos fazer swap
    int i;

    for (i=0; i<n; i++){
        if (vetor[i] < vetor[i+1] && direcao[i+1] == false) {   // Se o valor no vector for menor que seu sucessor e este possuir seta sentido FALSE, [i+1] será escolhido para o swap.
            PosMob2=i+1;
        }
        if (vetor [i] > vetor [i+1] && direcao[i] == true){     // Se o valor no vector for maior que seu sucessor e possuir seta sentido TRUE, ele [i] será escolhido para o swap.
            PosMob2=i;
        }
    }

     for (i=0; i<=n; i++){                                      // Essa função irá mudar o sentido da seta de todas posições que tiverem valor maior que o valor da posição PosMob2
        if (vetor[i]>vetor[PosMob2]){
            direcao[i] = !direcao[i];
        }
    }

    if (direcao[PosMob2] == false){                             // Essa função irá fazer o swap da posção PosMob2 com seu antecessor
        swap(vetor[PosMob2], vetor[PosMob2-1]);
        swap(direcao[PosMob2], direcao[PosMob2-1]);
        }
    else{                                                       // Essa função irá fazer o swap da posção PosMob2 com seu sucessor
        swap(vetor[PosMob2], vetor[PosMob2+1]);
        swap(direcao[PosMob2], direcao[PosMob2+1]);
        }
}
