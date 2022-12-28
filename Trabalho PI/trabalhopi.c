#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

struct clientes {
    int id;
    char nome[50];
    int idade;
};



void carregarparticipantes()
{

   
   FILE *fp;
   fp = fopen("C:/Users/leand/Documents/Trabalho_PI/Trabalho PI/dados/1Dados_dos_praticantes.txt", "r");
      if(fp != NULL) {
         printf("Clientes carregados\n");
         struct clientes cliente;
         char line[100];
         while (fgets(line, sizeof(line), fp) != NULL)
         {
             sscanf(line, "%[^;];%[^;];%[^;]", &cliente.id, cliente.nome, cliente.idade);
        
         } 
         fclose(fp);
      } else 
      {
         printf("Erro ao abrir o ficheiro.\n");
      }
         
   

} 






void opcoesgerais() 
{
   printf("1- Colocar aqui\n");
   printf("2- Colocar aqui\n");
   printf("3- Colocar aqui\n");
   printf("4- Colocar aqui\n");
   

}


int main() 
{
   carregarparticipantes();
   opcoesgerais();
   int op;
   struct clientes cliente;
 
   printf("Insira a opcao que deseja: ");
   scanf("%d", op);
}