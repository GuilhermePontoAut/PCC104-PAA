// FAM�LIA: PROGRAMA��O DIN�MICA
//
// Este algoritmo tem como objetivo encontrar O EN�SIMO n�mero da sequ�ncia Fibonacci N�O podendo utilizar para isso a t�cnica de PROGRAMA��O DIN�MICA

# include <iostream>




using namespace std;

int Fibonacci (int n);





int main () {
    setlocale(LC_ALL, "Portuguese");

    int n;

    cout << "Qual elemento voc� deseja saber da sequ�ncia de Fibonacci?" << endl;
    cin >> n;

    cout<< "\nO n�mero de posi��o " << n << " na sequ�ncia Fibonacci �: " << Fibonacci(n) << endl;
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
