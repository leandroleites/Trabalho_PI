#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

//structs
typedef struct {
    int id;
    char nome[50];
    int numero;
    int idade;
}clientes;

typedef struct {
    int id;
    char data[60];
    char hora[30];
    char tipo[25];
    int duracao;
    int distancia;
    char unidade[2];
}atividades;

typedef struct {
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
    int contagem[10];
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
    int temposTotais[10];
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
            printf("Tempo médio: %.2f\n", (float)temposTotais[i] / contagem[i]);
        }
    }
}

void opcoesgerais()
{
    //leitura dos ficheiros
    clientes cliente[100];
    int nclientes = 0;
    ler_clientes("../fix1.txt", cliente, &nclientes);

    atividades atividade[100];
    int natividades = 0;
    ler_atividades("../fix2.txt", atividade, &natividades);

    planos plano[100];
    int nplanos = 0;
    ler_planos("../fix3.txt", plano, &nplanos);
    int op = 0;
    while (1)
    {
        printf("1- Numero de participantes para uma atividade durante um determinado periodo de tempo\n");
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
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            AtividadeDeterminadoPeriodo(atividade, natividades);
            break;
        case 2:
            // Executa a opção 2
            break;
        case 3:
            // Executa a opção 3
            break;
        case 4:
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

int AtividadeDeterminadoPeriodo(atividades* atividades, int natividades)
{
    char tempoDe[25];
    char tempoAte[25];
    char atividade[25];
    int contagem = 0;
    int numero = 0;
    numero = natividades;

    printf("Atividade que quer procurar\n");
    scanf("%s", atividade);
    printf("Em que periodo de tempo quer procurar?\n");
    printf("De:\n");
    scanf("%s", tempoDe);
    printf("Ate:\n");
    scanf("%s", tempoAte);

    for (int i = 0; i < numero; i++)
    {
        int compareResult = strcmp(atividades[i].tipo, atividade);
        if (compareResult == 0)
        {
            int result = verificar_se_entre_dado_tempo(tempoDe, tempoAte, atividades[i].hora);
            if (result == 1)
            {
                contagem++;
            }
        }
    }

    printf("Para a atividade %s, das %s ate as %s participaram %d atletas.\n", atividade, tempoDe, tempoAte, contagem);
}

int verificar_se_entre_dado_tempo(char* time1_str, char* time2_str, char* time_str) {
    // para não dar erro no mktime
    struct tm time1 = { 0 };
    struct tm time2 = { 0 };
    struct tm time = { 0 };
    time.tm_hour = 9;
    time.tm_min = 30;
    time.tm_mon = 0;
    time.tm_mday = 1;
    time.tm_year = 122;
    time1.tm_hour = 9;
    time1.tm_min = 30;
    time1.tm_mon = 0; 
    time1.tm_mday = 1; 
    time1.tm_year = 122;
    time2.tm_hour = 9;
    time2.tm_min = 30;
    time2.tm_mon = 0; 
    time2.tm_mday = 1;
    time2.tm_year = 122;

    // Usar sscanf para converter char para int dividido por ":"
    int hour1, minute1;
    sscanf(time1_str, "%d:%d", &hour1, &minute1);
    time1.tm_hour = hour1;
    time1.tm_min = minute1;

    int hour2, minute2;
    sscanf(time2_str, "%d:%d", &hour2, &minute2);
    time2.tm_hour = hour2;
    time2.tm_min = minute2;

    int hour, minute;
    sscanf(time_str, "%d:%d", &hour, &minute);
    time.tm_hour = hour;
    time.tm_min = minute;

    // Converter tm para time_t
    time_t t1 = mktime(&time1);
    time_t t2 = mktime(&time2);
    time_t t = mktime(&time);

    // verificar se tem diferença
    double diff1 = difftime(t, t1);
    double diff2 = difftime(t, t2);

    // Retorna 1 se estiver dentro do periodo, 0 se não
    return (diff1 >= 0 && diff2 <= 0);
}


int main()
{
    //leitura dos ficheiros
    clientes cliente[100];
    int nclientes = 0;
    ler_clientes("../fix1.txt", cliente, &nclientes);

    atividades atividade[100];
    int natividades = 0;
    ler_atividades("../fix2.txt", atividade, &natividades);

    planos plano[100];
    int nplanos = 0;
    ler_planos("../fix3.txt", plano, &nplanos);
    //fim leitura dos ficheiros

    opcoesgerais();

    return 0;
}