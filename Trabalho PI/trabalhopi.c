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

   int ncliente;
   FILE *fp;
   fp = fopen("C:/Users/leand/Documents/Trabalho_PI/Trabalho PI/dados/1Dados_dos_praticantes.txt", "r");
      if(fp != NULL) {
         printf("Clientes carregados\n");
         struct clientes cliente[100];
         char line[100];
         while (fgets(line, sizeof(line), fp) != NULL)
         {
             sscanf(line, "%[^;];%[^;];%[^;]", &cliente[ncliente].id, cliente[ncliente].nome, cliente[ncliente].idade);
             ncliente++;
            
         } 
         fclose(fp);
      } else 
      {
         printf("Erro ao abrir o ficheiro.\n");
      }
         
   

} 

struct atividades {
    int id;
    char date[12];
    char time[6];
    char activity[20];
    int duration;
    int distance;
    char units[2];
} ;

void carregaratividades() {
    int numActivities;
    FILE *fp;
    fp = fopen("C:/Users/leand/Documents/Trabalho_PI/Trabalho PI/dados/2Informacao_de_cada_atividade_realizada_por_cada_praticante.txt", "r");
     if(fp != NULL) {
         printf("Atividades carregadas\n");
         struct atividades atividades[100];
         char line[100];
         while (fgets(line, sizeof(line), fp) != NULL)
         {
            sscanf(line, "%d;%[^;];%[^;];%[^;];%d;%d;%s", &atividades[numActivities].id, atividades[numActivities].date, atividades[numActivities].time, atividades[numActivities].activity, &atividades[numActivities].duration, &atividades[numActivities].distance, atividades[numActivities].units);
           (numActivities)++;
         }
         fclose(fp);
     }else 
      {
         printf("Erro ao abrir o ficheiro.\n");
      }
         

    fclose(fp);
}

 struct plano {
    int id;
    char dateinicio[12];
    char timeinicio[6];
    char datefim[12];
    char timefim[6];
    char activity[20];
    int distanceatingir;
    char units[2];
};

void carregarplano() {
    int numplano;
    FILE *fp;
    fp = fopen("C:/Users/leand/Documents/Trabalho_PI/Trabalho PI/dados/3Dados_dos_planos_de_atividades.txt", "r");
    if (fp != NULL) {
         printf("Planos carregados\n");
        struct plano plano[100];
         char line[100];
         while (fgets(line, sizeof(line), fp) != NULL) {
        sscanf(line, "%d;%[^;];%[^;];%[^;];%d;%d;%s", &plano[numplano].id, plano[numplano].dateinicio, plano[numplano].timeinicio, plano[numplano].datefim, plano[numplano].timefim, plano[numplano].activity, plano[numplano].units);
        (numplano)++;
    }
        fclose(fp);
    }else 
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
   carregaratividades();
   carregarplano();
   opcoesgerais();

   int op;
   struct clientes cliente;
   struct plano plano;
   struct atividades atividades;
   int i;
  
   printf("Insira a opcao que deseja: ");
   scanf("%d", op);
}