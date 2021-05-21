// Knapsack Problem
// Problema da mochila: o propósito deste algoritmo é apresentar a solução para o problema da MOCHILA usando um algoritmo de BUSCA EXAUSTIVA.
// O problema da mochila é um problema onde você tem itens com pesos (w) e valores (v) e uma mochila que aguenta um peso máximo (W)
// Seu objetivo é conseguir colocar na mochila o maior valor em itens possível

# include <iostream>
# include <vector>
# include <windows.h>           //SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE)

using namespace std;
void print_vec(vector<int> Mochila, int MochPeso, int MochValor, int esp, int esp2 );
void Solucao (vector <int> MelhorMochila, int MelhorValor, int MelhorPeso);

void textcolor_2 (int letras);
typedef enum{black,blue,green,cyan,red,magenta,brown,lightgray,darkgray,lightblue,lightgreen,lightcyan,lightred,lightmagenta,yellow,white} colors;
static int __FOREGROUND = lightgray;

int main(){
    setlocale(LC_ALL, "Portuguese");                                        // Recurso utilizado para conseguir imprimir acentuação e caracteres especiais
    vector <int> x = {1,2,3,4};                                             // Vector
    vector <int> p = {7,3,4,5};
    vector <int> v = {42,12,40,25};
    vector <int> Mochila;
    vector <int> MelhorMochila;
    int MelhorValor = 0;
    int MelhorPeso = 0;
    int MochPeso = 0;
    int MochValor = 0;
    int i,j,k;

    cout << "---------------------------------------------"<< endl;
    cout << "|  ";
    cout << "Subset";
    cout << "   |";
    cout << "  ";
    cout << "Peso Total";
    cout << "  |";
    cout << "   ";
    cout << "Valor Total";
    cout << "  |" << endl;
    cout << "---------------------------------------------"<< endl;

    for (i=0; i<=3; i++){
        Mochila.assign(x.begin()+i, x.begin()+i+1);
        MochPeso = (p[i]);
        MochValor = (v[i]);
        print_vec(Mochila,MochPeso,MochValor,7,6);

        if (MochPeso <= 10 && MochValor > MelhorValor){
            MelhorMochila = Mochila;
            MelhorValor = MochValor;
            MelhorPeso = MochPeso;
        }
    }

    for (i=0; i<=2; i++){
        for (j=i+1; j<4; j++){
            Mochila.clear();
            MochPeso = 0;
            MochValor = 0;
            Mochila.push_back(x[i]);
            Mochila.push_back(x[j]);
            MochPeso = MochPeso+(p[i])+(p[j]);
            MochValor = MochValor+(v[i])+(v[j]);
            print_vec(Mochila,MochPeso,MochValor,5,6);
            if (MochPeso <= 10 && MochValor > MelhorValor){
            MelhorMochila = Mochila;
            MelhorValor = MochValor;
            MelhorPeso = MochPeso;
            }
        }
    }

    for (i=0; i<=1; i++){
        for (j=i+1; j<=2; j++){
            for (k=j+1; k<=3; k++){
                Mochila.clear();
                MochPeso = 0;
                MochValor = 0;
                Mochila.push_back(x[i]);
                Mochila.push_back(x[j]);
                Mochila.push_back(x[k]);
                MochPeso = MochPeso+p[i]+p[j]+p[k];
                MochValor = MochValor+v[i]+v[j]+v[k];
                print_vec(Mochila,MochPeso,MochValor,3,5);
                if (MochPeso <= 10 && MochValor > MelhorValor){
                    MelhorMochila = Mochila;
                    MelhorValor = MochValor;
                    MelhorPeso = MochPeso;
                }
            }
        }
    }


    MochPeso = 0;
    MochValor = 0;
    for (i=0; i<=3; i++){
        Mochila.assign(x.begin(), x.begin()+i+1);
        MochPeso = MochPeso+p[i];
        MochValor = MochValor+v[i];
        if (MochPeso <= 10 && MochValor > MelhorValor){
            MelhorMochila = Mochila;
            MelhorValor = MochValor;
            MelhorPeso = MochPeso;
        }
    } print_vec(Mochila,MochPeso,MochValor,1,3);

    cout << "---------------------------------------------"<< endl;
    Solucao(MelhorMochila, MelhorValor, MelhorPeso);
}


void print_vec(vector<int> Mochila, int MochPeso, int MochValor, int esp, int esp2){

    cout << "| ";

    for (auto x: Mochila) {
         cout << " " <<x;
    }
    int i = 0;
    while(i<esp){
    cout <<" ";
    i = i+1;
    }


    cout << " | ";
    cout << "     ";
    cout << MochPeso;

    i = 0;
    if (MochPeso >= 10){
        esp2 = 5;
    }
    while(i<esp2){
    cout <<" ";
    i = i+1;
    }

    cout << " | ";


    if (MochPeso > 10){
        cout << " ";
        cout << "Não é viável!";
        cout << " |";
        cout << '\n';
    }
    else{
    cout << "       ";
    cout << MochValor;
    cout << "      |";
    cout << '\n';
    }
}

void Solucao (vector <int> MelhorMochila, int MelhorValor, int MelhorPeso){

    textcolor_2(10);

    cout << "---------------------------------------------"<< endl;
    cout << "|   ";
    cout << "           MELHOR SOLUÇÃO";
    cout << "               |" << endl;
    cout << "---------------------------------------------"<< endl;
    cout << "|   ";
    for (auto x: MelhorMochila) {
         cout << " " <<x;
    }
    cout << "    | ";
    cout << "     ";
    cout << MelhorPeso;
    cout << "       |       ";
    cout << MelhorValor;
    cout << "       | " << endl;
    cout << "---------------------------------------------"<< endl;

    textcolor_2(0);
}

void textcolor_2 (int letras){
    __FOREGROUND = letras;
    SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),letras);
}
