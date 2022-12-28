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

typedef struct {
    int id;
    char date[12];
    char time[6];
    char activity[20];
    int duration;
    int distance;
    char units[2];
} Activity;

void carregaratividades(const char* filename, Activity* activities, int* numActivities) {
    FILE* file = fopen("C:/Users/leand/Documents/Trabalho_PI/Trabalho PI/dados/2Informacao_de_cada_atividade_realizada_por_cada_praticante.txt", "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening file: %s\n", filename);
        exit(1);
    }

    char line[100];
    while (fgets(line, sizeof(line), file) != NULL) {
        sscanf(line, "%d;%[^;];%[^;];%[^;];%d;%d;%s", &activities[*numActivities].id, activities[*numActivities].date, activities[*numActivities].time, activities[*numActivities].activity, &activities[*numActivities].duration, &activities[*numActivities].distance, activities[*numActivities].units);
        (*numActivities)++;
    }

    fclose(file);
}

typedef struct {
    int id;
    char dateinicio[12];
    char timeinicio[6];
    char datefim[12];
    char timefim[6];
    char activity[20];
    int distanceatingir;
    char units[2];
} planoatividade;

void carregarplano(const char* filename, planoatividade* plano, int* numplano) {
    FILE* file = fopen("C:/Users/leand/Documents/Trabalho_PI/Trabalho PI/dados/3Dados_dos_planos_de_atividades.txt", "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening file: %s\n", filename);
        exit(1);
    }

    char line[100];
    while (fgets(line, sizeof(line), file) != NULL) {
        sscanf(line, "%d;%[^;];%[^;];%[^;];%d;%d;%s", &plano[*numplano].id, plano[*numplano].dateinicio, plano[*numplano].timeinicio, plano[*numplano].datefim, plano[*numplano].timefim, plano[*numplano].activity, plano[*numplano].units);
        (*numplano)++;
    }

    fclose(file);
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
   int i;
  
   printf("Insira a opcao que deseja: ");
   scanf("%d", op);
}