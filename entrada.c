
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/resource.h>
#include <sys/time.h>
#include "header.h"

// ------- função para ler a matriz do arquivo ------ //
void LerArquivo(char ** matriz, char * entrada){

  FILE * arq1;
	arq1=fopen(entrada, "r");
	int i=0, j=0, contador1=0, contador2=0;
 if(arq1 == NULL){
        printf("ERRO na CRIACAO do arquivo: inicial\n");
        exit(1);
    }
	char Caracteres;// variável para guardar os caracteres lido, com intuito de preencher a matriz //
	while( (Caracteres=fgetc(arq1))!= EOF ){

    if (Caracteres == '\n'){ // if feito para andar com o índice I(linha) //
		   i++;
       j=0;// ao fim da linha, zerar a coluna, para que possa preencher a nova linha //
       contador1++;
    }
    if (Caracteres == '1' || Caracteres == '0'){ // aqui, recebo os caracteres e preencho minha matriz
  		matriz[i][j]= Caracteres;
      j++; // andando com índice J(coluna) //
    }
// caso haja um caracterer inválido na matriz. Ex: 2, 3, 4 etc...
    if ((Caracteres != '1') && (Caracteres != '0') && (Caracteres != '\n') && (Caracteres != ' ')){
      printf ("Por favor use uma matriz valida\n");
      exit(1);
    }
//
  }



  fclose(arq1);
    }

    int contar(char * entrada){
          int numerolinhas=1;
          FILE * arq;
          arq=fopen(entrada, "r");
          char lixo;
      	   while( (lixo=fgetc(arq))!= EOF ){
              if (lixo == '\n'){
        		      numerolinhas++;
                  }
              }
            fclose(arq);
            return numerolinhas; // retorna o numero de linhas da matriz //
      }
    //
