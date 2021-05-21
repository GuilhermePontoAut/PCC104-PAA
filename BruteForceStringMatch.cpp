// O objetivo do algorito BruteForceStringMatch é achar uma palavra (pattern) em um texto (text)

#include <iostream>



using namespace std;

int BruteForceStringMatch (string t, string p, int n, int m);



int main () {
    setlocale(LC_ALL, "Portuguese");                               // Recurso utilizado para conseguir imprimir acentuação e caracteres especiais

    int n, m;
    string t, p;														// A variável 't' irá receber o texto e a variável 'p' a palavra que será buscada

	t = "Para que um texto, de fato, exista, é necessário que ele seja lido por alguém. O processo de leitura, entretanto, não é simples. Ler não significa apenas concatenar letras, formando palavras em uma frase. É necessário que o leitor saiba ler, além do básico da língua, questões de ordem contextual. É preciso relacionar o texto com outras leituras prévias, com a bagagem cultural do leitor. Nesse sentido, embora existam parâmetros que balizam a interpretação de texto, ler é um processo individual.";
	p = "texto";

	n = t.length();													// A variável 'n' irá receber o valor que corresponde ao tamanho do texto
	m = p.length();													// A variável 'm' irá receber o valor que corresponde ao tamanho da palavra
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
		while ((j < m) and (p[j] == t[i+j])) {						// Fará uma busca no texto iniciando pela posição 0. Se letra coincidir com a letra da palavra,
			j = j + 1;                                              //irá olhar as demais para ver se são iguais. Senão, munda de posição no texto.
		}

		if (j == m) {												// Caso ache a palavra irá retornar a posição (i) no texto da primeira letra que coincidiu, lembrando que a contagem inicia do valor 0
			return i;
		}
	}
	return -1;														// Caso não ache, retorna -1
}
