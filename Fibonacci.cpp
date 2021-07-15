// FAMÍLIA: PROGRAMAÇÃO DINÂMICA
//
// Este algoritmo tem como objetivo encontrar O ENÉSIMO número da sequência Fibonacci NÃO podendo utilizar para isso a técnica de PROGRAMAÇÃO DINÂMICA

# include <iostream>




using namespace std;

int Fibonacci (int n);





int main () {
    setlocale(LC_ALL, "Portuguese");

    int n;

    cout << "Qual elemento você deseja saber da sequência de Fibonacci?" << endl;
    cin >> n;

    cout<< "\nO número de posição " << n << " na sequência Fibonacci é: " << Fibonacci(n) << endl;
    cout<< endl;
    cout<< endl;
    cout<< endl;

}


int Fibonacci (int n){

    if (n <= 1){
        return n;
    }

    else {
        return (Fibonacci(n-1) + Fibonacci(n-2));
    }
}
