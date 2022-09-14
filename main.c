
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/resource.h>
#include <sys/time.h>
#include "header.h"


int main (int argc, char ** argv){
  int numerolinhas, i, j, opt;
  char ** matriz; // Cria a matriz que será usada nas funções para resolver o problema //
  char * entrada=NULL, * saida=NULL, * codigo=NULL;
  int ** resultado;
  double t1, t2; // Variáveis do tempo //



 // Getopt usado para ler no terminal
    while( (opt = getopt(argc, argv, "i:o:c:")) > 0 ) {
            switch ( opt ) {
              case 'i':
              entrada= optarg;
              break;
              case 'o':
              saida = optarg;
              break;
              case 'c':
              codigo = optarg;
              break;
              default:
              exit(1);

            }
  }
//
  numerolinhas = contar(entrada);
// Aloca dinamicamente a matriz criada acima//
  matriz = (char**)malloc(numerolinhas * sizeof(char*));
  for (i=0; i < numerolinhas; i++){
        matriz[i] = (char*)malloc(numerolinhas * sizeof(char));
  }
//


  LerArquivo(matriz, entrada);

  t1= timeofday(); // Começa a contagem do tempo //
  switch (codigo[0]){
    case '1':
      ForcaBruta(matriz, numerolinhas, saida);
      break;
    case '2':
      Guloso(matriz, numerolinhas, saida);
      break;
      case '3':
//   matriz criada com intuito de guardar os resultados obtidos na programção dinâmica //

      resultado = (int**)malloc(numerolinhas * sizeof(int*));
      for (i=0; i < numerolinhas; i++)
          resultado[i] = (int*)malloc(numerolinhas * sizeof(int));

      ProgDinamica(matriz, resultado, numerolinhas, saida);
      break;
  default:
    printf ("Escolha uma entrada valida\n");
    break;
}

  t2= timeofday(); // Termina a contagem do tempo //
  printf ("Tempo: %lf", t2-t1); // Printa a diferença //
  return 0;
}
