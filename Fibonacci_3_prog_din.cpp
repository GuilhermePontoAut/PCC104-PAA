// FAM�LIA: PROGRAMA��O DIN�MICA
//
// Este algoritmo tem como objetivo encontrar O EN�SIMO n�mero da sequ�ncia Fibonacci utilizando para isso a t�cnica de PROGRAMA��O DIN�MICA

# include <iostream>
# include <vector>



using namespace std;


int FibonacciBottomUp(int n);
//int FibonacciBottomUpRecursivo(vector <double> &vetor, int n);



int main (){
    setlocale (LC_ALL, "Portuguese");

    int n;

    cout << "Digite qual elemento da sequ�ncia de Fibonacci voc� deseja saber o valor: ";
    cin >> n;
    cout <<"\nO valor do elemento " << n << " da sequ�ncia de Fibonacci �: " << FibonacciBottomUp(n);
    cout << endl;
    cout << endl;

}

int FibonacciBottomUp(int n) {

    vector <double> vetor;
    vetor.push_back(0);
    vetor.push_back(1);
    vetor.push_back(1);
    if(n <= 1){
        return n;
    }
    else{
        for(int i=3; i<=n; i++){
            vetor.push_back(vetor[i-1] + vetor[i-2]);
        }
        return (vetor[n]);
    }
}
