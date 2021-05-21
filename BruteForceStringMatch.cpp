// O objetivo do algorito BruteForceStringMatch � achar uma palavra (pattern) em um texto (text)

#include <iostream>



using namespace std;

int BruteForceStringMatch (string t, string p, int n, int m);



int main () {
    setlocale(LC_ALL, "Portuguese");                               // Recurso utilizado para conseguir imprimir acentua��o e caracteres especiais

    int n, m;
    string t, p;														// A vari�vel 't' ir� receber o texto e a vari�vel 'p' a palavra que ser� buscada

	t = "Para que um texto, de fato, exista, � necess�rio que ele seja lido por algu�m. O processo de leitura, entretanto, n�o � simples. Ler n�o significa apenas concatenar letras, formando palavras em uma frase. � necess�rio que o leitor saiba ler, al�m do b�sico da l�ngua, quest�es de ordem contextual. � preciso relacionar o texto com outras leituras pr�vias, com a bagagem cultural do leitor. Nesse sentido, embora existam par�metros que balizam a interpreta��o de texto, ler � um processo individual.";
	p = "texto";

	n = t.length();													// A vari�vel 'n' ir� receber o valor que corresponde ao tamanho do texto
	m = p.length();													// A vari�vel 'm' ir� receber o valor que corresponde ao tamanho da palavra
	cout<< BruteForceStringMatch (t, p, n, m);

}


int BruteForceStringMatch (string t, string p, int n, int m) {

//n is the length of the text
//m is the length of the pattern
//t is the text
//p is the pattern

int i, j;

	for (i = 0; i <= n-m; i++){
		j = 0;
		while ((j < m) and (p[j] == t[i+j])) {						// Far� uma busca no texto iniciando pela posi��o 0. Se letra coincidir com a letra da palavra,
			j = j + 1;                                              //ir� olhar as demais para ver se s�o iguais. Sen�o, munda de posi��o no texto.
		}

		if (j == m) {												// Caso ache a palavra ir� retornar a posi��o (i) no texto da primeira letra que coincidiu, lembrando que a contagem inicia do valor 0
			return i;
		}
	}
	return -1;														// Caso n�o ache, retorna -1
}
