#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/resource.h>
#include <sys/time.h>
#include "header.h"


// ------- função para calcular o tempo de execução ------- //
double timeofday(){
 struct timeval tv;
 gettimeofday(&tv,0);
 return tv.tv_sec + tv.tv_usec/1e6;
}


void EscreveMatriz(int TamanhoMatriz, int coordenadasx, int coordenadasy, int tamanho, char * saida){
  char ** matriz= (char**)malloc(TamanhoMatriz * sizeof(char*));
  int i, j=0;
FILE * arq2= fopen(saida, "w");
  for (i=0; i < TamanhoMatriz; i++){
    matriz[i]= (char*)malloc(TamanhoMatriz * sizeof(char)); // aloca a nova matriz //
  }
for (i=0; i < TamanhoMatriz; i++){
  for(j=0; j < TamanhoMatriz; j++){
    matriz[i][j]= ' '; // preenche ela com espaços //
  }
}
  for (i=0; i < tamanho; i++){ // for de 0 até o tamanho da maior matriz, econtrada na função escolhida //
  for (j=0; j < tamanho; j++){
    matriz[coordenadasy + i][coordenadasx + j]= '1'; // Preenche onde está a maior matriz//

    }
}
 for (i=0; i< TamanhoMatriz; i++){
  for(j=0; j < TamanhoMatriz; j++){
    fputc (matriz[i][j], arq2); // Escreve no arquivo de saida, a nova matriz preenchida //
    fputc(' ', arq2); // Adiciona espaço entre um número e outro, para que possa ficar mais legível//
  }
  fputc('\n', arq2);
 }

    for(i=0; i < TamanhoMatriz; i++){
      free(matriz[i]);
    }
    free(matriz);
fclose (arq2); // fecha o arquivo //

}
