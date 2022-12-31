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




void calcularTempos(atividades* atividades, int natividades) {
  // cria array de contagem para armazenar quantas vezes cada tipo de atividade foi realizada
  int contagem[natividades];
  memset(contagem, 0, sizeof(contagem));
  
  // percorre o array de atividades e atualiza o valor correspondente no array de contagem
  for (int i = 0; i < natividades; i++) {
    for (int j = 0; j < natividades; j++) {
      if (strcmp(atividades[i].tipo, atividades[j].tipo) == 0) {
        contagem[i]++;
      }
    }
  }
  
  // cria array para armazenar os tempos totais por tipo de atividade
  int temposTotais[natividades];
  memset(temposTotais, 0, sizeof(temposTotais));
  
  // percorre o array de atividades e soma o tempo total para cada tipo de atividade
  for (int i = 0; i < natividades; i++) {
    for (int j = 0; j < natividades; j++) {
      if (strcmp(atividades[i].tipo, atividades[j].tipo) == 0) {
        temposTotais[i] += atividades[j].duracao;
      }
    }
  }
  
  // percorre o array de contagem e tempos totais e exibe os resultados
  for (int i = 0; i < natividades; i++) {
    if (contagem[i] > 0) {
      printf("Tipo de atividade: %s\n", atividades[i].tipo);
      printf("Tempo total: %d\n", temposTotais[i]);
      printf("Tempo médio: %.2f\n", (float) temposTotais[i] / contagem[i]);
    }
  }
}






void opcoesgerais() 
{
        //leitura dos ficheiros
    clientes cliente[100];
    int nclientes=0;
    ler_clientes("C:/Users/leand/Documents/Trabalho_PI/Trabalho PI/dados/1Dados_dos_praticantes.txt",cliente,&nclientes);

    atividades atividade[100];
    int natividades=0;
    ler_atividades("C:/Users/leand/Documents/Trabalho_PI/Trabalho PI/dados/2informacao_de_cada_atividade_realizada_por_cada_praticante.txt",atividade,&natividades);
    
    planos plano[100];
    int nplanos=0;
    ler_planos("C:/Users/leand/Documents/Trabalho_PI/Trabalho PI/dados/3Dados_dos_planos_de_atividades.txt",plano,&nplanos);
    int op=0;
   while (1)
    {

      printf("1- Colocar aqui\n");
      printf("2- Colocar aqui\n");
      printf("3- Colocar aqui\n");
      printf("4- Calcular tempos totais e media de tempos\n");
      printf("5- Colocar aqui\n");
      printf("6- Colocar aqui\n");
      printf("7- Colocar aqui \n");
      printf("8- Colocar aqui\n");
      printf("9- Colocar aqui\n");
      printf("10- Sair\n");
      
      printf("Opcao: ");
      scanf("%d", op);
      switch (op)
        {
            case 1:
                // Executa a opção 1
                break;
            case 2:
                // Executa a opção 2
                break;
            case 3:
                // Executa a opção 3
                break;
            case 4:
            
            ler_atividades("C:/Users/leand/Documents/Trabalho_PI/Trabalho PI/dados/2informacao_de_cada_atividade_realizada_por_cada_praticante.txt", atividade, &natividades);
  
           
            calcularTempos(atividade, natividades);
                break;
            case 5:
                // Executa a opção 3
                break;
            case 6:
                // Executa a opção 3
                break;
            case 7:
                // Executa a opção 3
                break;    
            case 8:
                // Executa a opção 3
                break;
            case 9:
                // Executa a opção 3
                break;    
            case 10:
                // Sair do programa
                return 0;
            default:
                printf("Opcao invalida.\n");
                break;
        }

    }

    return 0;
}

int main ()
{
    //leitura dos ficheiros
    clientes cliente[100];
    int nclientes=0;
    ler_clientes("C:/Users/leand/Documents/Trabalho_PI/Trabalho PI/dados/1Dados_dos_praticantes.txt",cliente,&nclientes);

    atividades atividade[100];
    int natividades=0;
    ler_atividades("C:/Users/leand/Documents/Trabalho_PI/Trabalho PI/dados/2informacao_de_cada_atividade_realizada_por_cada_praticante.txt",atividade,&natividades);
    
    planos plano[100];
    int nplanos=0;
    ler_planos("C:/Users/leand/Documents/Trabalho_PI/Trabalho PI/dados/3Dados_dos_planos_de_atividades.txt",plano,&nplanos);
    //fim leitura dos ficheiros
 
    opcoesgerais(); 



    return 0;
}