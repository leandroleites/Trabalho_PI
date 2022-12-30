#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

//structs
    typedef struct{
    int id;
    char nome[50];
    int numero;
    int idade;
    }clientes;

    typedef struct{
        int id;
        char data[60];
        char hora[30];
        char tipo[25];
        int duracao;
        int distancia;
        char unidade[2];
    }atividades;
    
    typedef struct{
        int id;
        char data_inicio[60];
        char hora_inicio[30];
        char data_fim[60];
        char hora_fim[30];
        char tipo[25];
        int distancia;
        char unidade[2];
    }planos;
//fim das structs

//ler clientes
    void ler_clientes(const char* f, clientes* cliente, int* nclientes)
    {
    FILE* arquivo = fopen(f, "r");    
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
    }
   
    while (fscanf(arquivo, "%d;%[^;];%d;%d", &cliente[*nclientes].id, cliente[*nclientes].nome, &cliente[*nclientes].numero, &cliente[*nclientes].idade) == 4) {
        (*nclientes)++;
    }
    fclose(arquivo);
    }
//fim ler clientes

//ler atividadess
    void ler_atividades(const char* f, atividades* atividades, int* natividades)
{
    FILE* arquivo = fopen(f, "r");    
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
    }
   
    while (fscanf(arquivo, "%d;%[^;];%[^;];%[^;];%d;%d;%[^\n]", &atividades[*natividades].id, atividades[*natividades].data, atividades[*natividades].hora, atividades[*natividades].tipo, &atividades[*natividades].duracao, &atividades[*natividades].distancia, atividades[*natividades].unidade) == 7) {
     (*natividades)++;
    }
    fclose(arquivo);
}
//fim ler atividades

//ler planos
    void ler_planos(const char* f, planos* planos, int* nplanos)
{
    FILE* arquivo = fopen(f, "r");    
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
    }
   
   while (fscanf(arquivo, "%d;%[^;];%[^;];%[^;];%[^;];%[^;];%d;%s", &planos[*nplanos].id, planos[*nplanos].data_inicio, planos[*nplanos].hora_inicio, planos[*nplanos].data_fim, planos[*nplanos].hora_fim, planos[*nplanos].tipo, &planos[*nplanos].distancia, planos[*nplanos].unidade) == 8) {
        (*nplanos)++;
    }
fclose(arquivo);
}
//fim ler planos

void opcoesgerais() 
{
   printf("1- Colocar aqui\n");
   printf("2- Colocar aqui\n");
   printf("3- Colocar aqui\n");
   printf("4- Colocar aqui\n");
   

}

int main ()
{
    //leitura dos ficheiros
    clientes cliente[100];
    int nclientes=0;
    ler_clientes("C:/Users/dific/OneDrive/Desktop/Trab/dados/1Dados_dos_praticantes.txt",cliente,&nclientes);

    atividades atividade[100];
    int natividades=0;
    ler_atividades("C:/Users/dific/OneDrive/Desktop/Trab/dados/2informacao_de_cada_atividade_realizada_por_cada_praticante.txt",atividade,&natividades);
    
    planos plano[100];
    int nplanos=0;
    ler_planos("C:/Users/dific/OneDrive/Desktop/Trab/dados/3Dados_dos_planos_de_atividades.txt",plano,&nplanos);
    //fim leitura dos ficheiros
    int op=0;
    opcoesgerais(); 
    scanf("%d", op);
    
    return 0;
}