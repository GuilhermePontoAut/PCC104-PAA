// FAM�LIA: PROGRAMA��O DIN�MICA
//
// Este algoritmo tem como objetivo encontrar O EN�SIMO n�mero da sequ�ncia Fibonacci utilizando para isso a t�cnica de PROGRAMA��O DIN�MICA

# include <iostream>
# include <vector>



using namespace std;


int FibonacciTopDown(int n);
int FibonacciTopDownRecursivo(vector <double> &vetor, int n);



int main (){
    setlocale (LC_ALL, "Portuguese");

    int n;

    cout << "Digite qual elemento da sequ�ncia de Fibonacci voc� deseja saber o valor: ";
    cin >> n;
    cout <<"\nO valor do elemento " << n << " da sequ�ncia de Fibonacci �: " << FibonacciTopDown(n);
    cout << endl;
    cout << endl;

}

int FibonacciTopDown(int n) {

    vector <double> vetor;
    vetor.push_back(0);
    vetor.push_back(1);
    vetor.push_back(1);
    if(n <= 1){
        return n;
    }
    else{
        for(int i=3; i<=n; i++){
            vetor.push_back(-1);
        }
        return (FibonacciTopDownRecursivo(vetor, n));
    }
}

int FibonacciTopDownRecursivo(vector <double> &vetor, int n) {

    if (vetor[n] == -1){
        vetor[n] = FibonacciTopDownRecursivo(vetor, n-1) + FibonacciTopDownRecursivo(vetor, n-2);
    }
    return (vetor[n]);
}

