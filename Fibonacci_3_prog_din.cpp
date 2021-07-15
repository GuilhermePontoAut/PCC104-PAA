// FAMÍLIA: PROGRAMAÇÃO DINÂMICA
//
// Este algoritmo tem como objetivo encontrar O ENÉSIMO número da sequência Fibonacci utilizando para isso a técnica de PROGRAMAÇÃO DINÂMICA

# include <iostream>
# include <vector>



using namespace std;


int FibonacciBottomUp(int n);
//int FibonacciBottomUpRecursivo(vector <double> &vetor, int n);



int main (){
    setlocale (LC_ALL, "Portuguese");

    int n;

    cout << "Digite qual elemento da sequência de Fibonacci você deseja saber o valor: ";
    cin >> n;
    cout <<"\nO valor do elemento " << n << " da sequência de Fibonacci é: " << FibonacciBottomUp(n);
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
