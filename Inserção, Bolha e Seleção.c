#include <stdio.h>
#include <time.h>
void imprimir (int X[], int n) {
  int i;
  printf("(");
  for (i=0; i<n; i++) printf("%3d ", X[i]);
  printf(")\n");
  }
  //Bolha
void ordPedregulho (int V[], int n) {
  int i, j, aux;
  for (i=0; i<n; i++)
    for (j=0; j<n-i-1; j++)
      if (V[j]>V[j+1]) { // troque-os
        aux = V[j]; // presevar V[j]
        V[j] = V[j+1];
        V[j+1] = aux; }
  }

  //Sele��o
void ordSelecao (int V[], int n) {
  int i, j, aux;
  for (i=n-1; i>0; i--)
    for (j=0; j<i; j++)
      if (V[j]>V[i]) { // troque-os
        aux = V[j]; // presevar V[j]
        V[j] = V[i];
        V[i] = aux;
        }
  }

  //Inser��o
void ordInsercao (int V[], int n) {
  int i, j, aux;
  for (i=1; i<n; i++) {
    aux = V[i]; // "abrir espaco" copiando V[i]
    j = i-1;
    while (j > -1 && V[j] > aux) { // mova para direita os maiores que aux
      V[j+1] = V[j]; // mover para direita V[j]
      j -= 1;
      }
    V[j+1] = aux; // coloque aux na posicao correta
    }
  }

int main (void) {

  clock_t t;
  int tam1 = 100000;
  int vectRand_1[tam1],i;

  for(i=0;i<tam1;i++)
    vectRand_1[i]=(rand() %10) + 1;

  //imprimir(vectRand_1, tam1);
  t = clock();
  ordInsercao(vectRand_1, tam1);
  t = clock()-t;
  double tempo = ((double)t)/CLOCKS_PER_SEC;
  //imprimir(vectRand_1, tam1);
  printf("%f segundos se passaram!", tempo);
  }
   
