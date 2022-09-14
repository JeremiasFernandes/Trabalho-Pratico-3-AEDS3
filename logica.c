
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/resource.h>
#include <sys/time.h>
#include "header.h"






void ProgDinamica (char ** matriz, int ** resultado, int TamanhoMatriz, char * saida){
    int i, j=0, m, CoordenadasX=0, CoordenadasY=0,coluna=-1, linha=0, contador=0, tamanho=0, MaiorMatriz=0;
            // Passa a matriz de char para a Resultado de int
            while(1){

              // Salva na matriz resultado se há uma sub-matriz 1x1 no ponto testado
                  if (contador >= 0){
                      resultado[linha][coluna]= contador;
                      contador=0;
                  }
              //
                  coluna++;

              // Verifica se ná irá fazer comparações desnecessárias
                  if (coluna >  TamanhoMatriz-1){
                      coluna=0;
                      linha++;
                  }
              //
              // Evita testes com pontos que não existem
                  if (linha == TamanhoMatriz-1){
                      break;
                  }
              //

                // Lógica para verificar se há uma matriz 2x2 no ponto testado
                    for (i=0; i < 1; i++){
                          contador=0;
                          if (linha + i > TamanhoMatriz-1){
                              i=2;
                           }
                              for (j=0; j < 1; j++){
                                      if (matriz[linha + i][coluna + j] == '0' || coluna + j == TamanhoMatriz){
                                          contador=0;
                                          i=2;
                                          j=2;
                                      }else{
                                          contador++;
                                      }
                      }
                    }
                  }


   // Acha onde há a maior submatriz quadrada
      for(m=0; m < TamanhoMatriz; m++){
            tamanho++;
          for (i=0; i < TamanhoMatriz; i++){
            for (j=0; j < TamanhoMatriz; j++){
              // faz a comparação em quadrados
                if ((resultado[i][j] == tamanho) && (resultado[i][j+1] == tamanho) && (resultado[i+1][j]==tamanho) && (resultado[i+1][j+1]==tamanho)){
                    resultado[i][j]=tamanho+1;
                }
            // Ocorre a troca, caso ache uma submatriz maior que a atual no momento
                if (resultado[i][j] >= tamanho){
                    CoordenadasX=j; // guarda as coordenadas
                    CoordenadasY=i;
                    MaiorMatriz=resultado[i][j]; // guarda o tamanho da nova maior matriz //
                }
        }
      }
    }
    // Faz a liberação das matrizez
    for(i=0; i < TamanhoMatriz; i++){
      free(matriz[i]);
      free (resultado[i]);
    }
    free(matriz);
    free(resultado);
   //

EscreveMatriz(TamanhoMatriz, CoordenadasX, CoordenadasY, MaiorMatriz, saida); // Escreve no arquivo //


}




void Guloso(char ** matriz, int TamanhoMatriz, char * saida){
    int i, j=0, Contador=0, m=0, condicao=0, MaiorMatriz=0, coluna=0, linha=0, CoordenadasX=0, CoordenadasY=0, Verifica=0;

    int ComparacaoMatriz = TamanhoMatriz;
    // for para fazer a verificação dos pontos //
      for (m=0; m < TamanhoMatriz * TamanhoMatriz; m++){
    // Verifica se há um '0', na matriz em teste
              if (Verifica == 1){
                ComparacaoMatriz = ComparacaoMatriz - Contador;
                Verifica=0;
                }
    //

    // Garante que testará todas as possíveis sub-matrizes, formadas com o primeiro ponto
              if (condicao == TamanhoMatriz-1){
                linha++;
                condicao=0;
                ComparacaoMatriz = TamanhoMatriz - linha; // confirma que não irá testar sub-matrizes inválidas //
                }
    //
    // Quando achar uma sub-matriz maior que a atual maior //
              if(Contador > MaiorMatriz){
                MaiorMatriz=Contador; // faz a troca //
                CoordenadasX= coluna; // guarda as coordenadas //
                CoordenadasY= linha;
                }
    //

    // Caso que a maior sub-matriz seja a própria matriz, evita de fazer comparações inuteis
              if (MaiorMatriz==TamanhoMatriz){
                break;
                }
    //

    // logica para não testar pontos fora da matriz
              if (linha > TamanhoMatriz-1){
                break;
                }
    //
              condicao++;
    // Testa se há uma sub-matriz quadrada do tamanho de ComparacaoMatriz
              for (i=0; i < ComparacaoMatriz; i++){
                    Contador=0;
                    if (linha + i > TamanhoMatriz-1){
                        i=ComparacaoMatriz;
                      }
                        for (j=0; j < ComparacaoMatriz; j++){
                              if (matriz[linha + i][coluna + j] == '0'){
                                  Verifica=1;
                                  i=ComparacaoMatriz;
                                  j=ComparacaoMatriz;
                              }else{
                                  Contador++;
                        }
                        }
                        }

          }
          // Faz a liberação da matriz
          for(i=0; i < TamanhoMatriz; i++){
            free(matriz[i]);
          }
         //

       EscreveMatriz(TamanhoMatriz, CoordenadasX, CoordenadasY, MaiorMatriz, saida); // escreve a matriz no arquivo //
        }


void ForcaBruta(char ** matriz, int TamanhoMatriz, char * saida){
int i, j=0, Contador=0, m, ComparacaoMatriz=1, MaiorMatriz=0, coluna=0, linha=0, CoordenadasX=0, CoordenadasY=0, Condicao=0;
      for (m=0; m < TamanhoMatriz * TamanhoMatriz; m++){  // for para que todos os pontos da matriz, possam ser verificados//

        if (Contador==ComparacaoMatriz){ // Faz as devidas comparações, caso TamanhoMatriz for igual a ComparacaoMatriz
          if( Contador > MaiorMatriz){ // Caso a nova matriz encontrada, for maior do que a ja tiver //
            MaiorMatriz=Contador; // Faz a troca, a nova matriz encontrada será a maior até então //
        // Guarda as novas coordenadas desta nova matriz

            CoordenadasX= coluna;
            CoordenadasY= linha;
        //
        }
            ComparacaoMatriz++; // Garante que matrizes maiores, poderão ser encontradas //
          }



          if (Condicao == 1){ // Caso ache um '0' nas comparações //
              if(Contador<=1){
                coluna++;
                Condicao=0;
              }else{
                coluna=Contador; // anda com a coluna, para verificar o próximo ponto //
                Condicao=0; // Reseto minha condição //
              }}

          if (coluna == TamanhoMatriz-1){ // Se meu ponto de comparação estiver na parede da matriz, logo não preciso compará-lo //
            coluna=0; // Reseta a coluna //
            linha++; // Pula para a próxima linha //
          }
          if (linha > TamanhoMatriz-1){ // Evita que faça comparações com a ultima linha
            break;
          }
          if (MaiorMatriz==TamanhoMatriz){ // Poda feita para evitar comparações desnecessárias, caso minha maior sub-matriz for a própria matriz //
            break;
          }

          for (i=0; i < ComparacaoMatriz; i++){ // For para fazer as devidas comparações //
                Contador=0; // Reseto o tamanho, para que possa apenas da o número certo. Ex: Se achar uma matriz 2x2, devolve 2, ao invés de 4.
                if (linha + i > TamanhoMatriz-1){ // Caso a linha a ser comparada exceder o tamanho da matriz //
                  break;
                }
                    for (j=0; j < ComparacaoMatriz; j++){
                          if (matriz[linha + i][coluna + j] == '0' ||  coluna + j > TamanhoMatriz-1){ // Compara ponto a ponto à procura de um '0' ou evita que a coluna que estou comparado exceder o tamanho da matriz//
                            Condicao=1; // Adiciono um a minha condição, para que possa ser feita a lógica no If no 1º for //
                            i=ComparacaoMatriz; // Encerro meu for //
                            break;
                          }else{
                              Contador++; // caso não ache '0' na posição comparada, adiciona um ao Contador, que guarda o tamanho da matriz testada //
                    }
                    }
                    }

          }
          // Faz a liberação da matriz
          for(i=0; i < TamanhoMatriz; i++){
            free(matriz[i]);
          }
          //
           EscreveMatriz(TamanhoMatriz, CoordenadasX, CoordenadasY, MaiorMatriz, saida); // Escreve a matriz no arquivo //
        }
