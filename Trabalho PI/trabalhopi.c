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



typedef struct {

  int praticanteid;
  int seguidorid;

}seguidores;

typedef struct {
    int numero_praticante;
    char nome[50];
    char atividade_planeada[50];
    char unidade_planeada[10];
    int valor_planeado;
    char atividade_realizada[50];
    char data_inicio[60];
    char data_fim[60];
    char unidade_realizada[10];
    int valor_realizado;
} tabela_atividades;


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

void Menuseguidores(seguidores* seguidores, clientes* clientes, int* nseguidores, int nclientes)
{
   
    int o;
   printf("--------------------------------------------------\n");

   printf("|1- Ver lista de seguidores e praticantes        |\n");
   printf("|2- Seguir algum praticante                      |\n");

   printf("--------------------------------------------------\n\n\n");
   printf("Escolha a opcao que deseja:                \n");
   scanf("%d", &o);
   if (o== 1)
   {
         printf("Tabela de seguidores:\n");
         printf("Praticante ID | Seguidor ID\n");
          for (int i = 0; i < *nseguidores; i++) {
           printf("%d | %d\n", seguidores[i].praticanteid, seguidores[i].seguidorid);
    }
     
   }
   else if(o==2)
   {  

      int praticanteid, seguidorid;
        printf("Insira o ID do praticante: ");
        scanf("%d", &praticanteid);
        printf("Insira o ID do seguidor: ");
        scanf("%d", &seguidorid);

        // Verifica se os IDs inseridos são válidos e se o seguidor já não está seguindo o praticante
        int praticanteExiste = 0, seguidorExiste = 0, jaSeguindo = 0;
        for (int i = 0; i < nclientes; i++) {
            if (clientes[i].id == praticanteid) {
            praticanteExiste = 1;
            }
            if (clientes[i].id == seguidorid) {
            seguidorExiste = 1;
            }
        }
        for (int i = 0; i < *nseguidores; i++) {
            if (seguidores[i].praticanteid == praticanteid && seguidores[i].seguidorid == seguidorid) {
            jaSeguindo = 1;
            }
        }
        if (!praticanteExiste || !seguidorExiste) {
            printf("Um dos IDs inseridos é inválido.\n");
        }
        else if (jaSeguindo) {
            printf("O seguidor já está seguindo o praticante.\n");
        }
        else {
            seguidores[*nseguidores].praticanteid = praticanteid;
            seguidores[*nseguidores].seguidorid = seguidorid;
            (*nseguidores)++;
            printf("Seguidor adicionado com sucesso.\n \n \n \n \n");
        }
     }
     
      
}

void dez(clientes* cliente,atividades* atividade,seguidores* seguidor,int* natividade,int* nclientes)
{
    int c=0;
    int op=0;
    int guardaid=0;
  for (int i = 0; i < natividade; i++) {
    printf("Atividade: %s", atividade[i].tipo);
    for (int z = 0; z <nclientes; z++) {
      if (atividade[i].id == cliente[z].id) {
        printf("\n Id: %d\nNome: %s \n",cliente[z].id, cliente[z].nome);
        guardaid=cliente[z].id;
      }
    }
    printf("Tempo: %d \n\n",atividade[i].duracao);
  }
  printf("Insira o id:");
  scanf("%d",&op);
  printf("\nSeguidores e seus tempos: ");
  for(int i=0;i<nclientes;i++){
    if(seguidor[i].praticanteid==op)
    {
     for(int c=0;c<nclientes;c++)
     {
        if(cliente[c].id==seguidor[i].seguidorid)
     printf("%d",cliente[c].nome);

     }
    c++;
    }
  }
  if(c==0)
  {
    printf("0 seguidores.");
  }
}

void onze(clientes* cliente,atividades* atividade,seguidores* seguidor,int* natividade,int* nclientes)
{
    int c=0;
  int op=0;
  int guardaid=0;
  for (int i = 0; i < natividade; i++) {
    printf("Atividade: %s", atividade[i].tipo);
    for (int z = 0; z <nclientes; z++) {
      if (atividade[i].id == cliente[z].id) {
        printf("\n Id: %d\nNome: %s \n",cliente[z].id, cliente[z].nome);
        guardaid=cliente[z].id;
      }
    }
    printf("Tempo: %d \n\n",atividade[i].duracao);
  }
  printf("Insira o id:");
  scanf("%d",&op);
  printf("\nSeguidores e seus tempos: ");
  for(int i=0;i<nclientes;i++){
    if(seguidor[i].seguidorid==op)
    {
     for(int c=0;c<nclientes;c++)
     {
        if(cliente[c].id==seguidor[i].praticanteid)
        printf("%d",cliente[c].nome);

     }
    c++;
    }
  }
  if(c==0)
  {
    printf("A seguir 0 pessoas.");
  }
}     
int comparar_ids(const void* a, const void* b) {
    int int_a = *((int*)a);
    int int_b = *((int*)b);

    if (int_a == int_b) return 0;
    else if (int_a < int_b) return -1;
    else return 1;
}


int AlgumaAtividadeDeterminadoPeriodo(atividades* atividades, int natividades)
{
    char tempoDe[25];
    char tempoAte[25];
    char atividade[25];
    int contagem = 0;
    int numero = 0;
    numero = natividades;
    char** ID_utilizador = malloc(0);
    printf("Em que periodo de tempo quer procurar?\n");
    printf("De:\n");
    scanf("%s", tempoDe);
    printf("Ate:\n");
    scanf("%s", tempoAte);

    for (int i = 0; i < numero; i++)
    {
        int result = verificar_se_entre_dado_tempo(tempoDe, tempoAte, atividades[i].hora);
        if (result == 1)
        {
            contagem++;
            ID_utilizador = realloc(ID_utilizador, contagem * sizeof(char*));
            ID_utilizador[contagem - 1] = atividades[i].id;
        }
    }
    qsort(ID_utilizador, contagem, sizeof(char*), comparar_ids);
    printf("Das %s ate as %s a lista de IDs das pessoas que participaram em atividades foram:\n", tempoDe, tempoAte);
    for (int j = contagem - 1; j >= 0; j--) {
        printf("%d\n", ID_utilizador[j]);

    }
    free(ID_utilizador);
    return 0;
}
int ApresentacaodoPlanodeAtividades(planos* planos, int natividades)
{
    char tempoDe[25];
    char tempoAte[25];
    char ID[4];
    int contagem = 0;
    int numero = 0;
    numero = natividades;
    char** tipo = malloc(0);
    char id_scanner[4];

    printf("ID que quer procurar(X):\n");
    scanf("%s", ID);
    printf("Em que periodo de tempo quer procurar?(hh:mm)\n");
    printf("De:\n");
    scanf("%s", tempoDe);
    printf("Ate:\n");
    scanf("%s", tempoAte);
    for (int i = 0; i < numero; i++)
    {
        sprintf(id_scanner, "%d", planos[i].id);
        int compareResult = strcmp(id_scanner, ID);
        if (compareResult == 0)
        {
            int result = verificar_se_entre_dado_tempo(tempoDe, tempoAte, planos[i].hora_inicio);
            if (result == 1)
            {
                contagem++;
                tipo = realloc(tipo, contagem * sizeof(char*));
                tipo[contagem - 1] = planos[i].tipo;
            }
        }

    }
    printf("Das %s ate as %s 0 ID %s tem uma atividade tipo:\n", tempoDe, tempoAte, ID);
    for (int j = 0; j < contagem; j++)
    {
        printf("%s\n", &tipo[j]);

    }
    free(tipo);
    return 0;
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
    seguidores seguidor[100] ;
    int nseguidores=0;
    
    int c=0;
    int op = 0;
    while (1)
    {   
        printf("\n\n");
        printf("-----------------------------------------------------------------------------------------------------\n");
        printf("|1- Numero de participantes para uma atividade durante um determinado periodo de tempo               |\n");
        printf("|2- ID de praticantes que realizaram uma atividade durante um determinado periodo de tempo           |\n"); 
        printf("|3- Apresentação de plano de atividades                                                              |\n");
        printf("|5- Gerar tabela de atividades planeadas                                                             |\n");
        printf("|6- Menu seguidores                                                                                  |\n");
        printf("|7- Listagem por atividade com o praticante com o maior tempo                                        |\n");
        printf("|8- Listagem por atividade com o praticante com o maior tempo    (praticantes seguidos)              |\n");
        printf("|9- ----                                                                                             |\n");
        printf("|10- Sair                                                                                            |\n");
        printf("-----------------------------------------------------------------------------------------------------\n");
        printf("Opcao: ");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            AtividadeDeterminadoPeriodo(atividade, natividades);
            break;
        case 2:
            AlgumaAtividadeDeterminadoPeriodo(atividade, natividades);
            break;
        case 3:
            ApresentacaodoPlanodeAtividades(plano, nplanos);
            break;
        case 4:
            calcularTempos(atividade, natividades);
            break;
        case 5:
            // Executa a opção 3
            break;
        case 6:
            Menuseguidores(seguidor, cliente, &nseguidores, nclientes);
            break;
        case 7:
             dez(cliente,atividade,seguidor,&natividades,&nclientes);
            break;
        case 8:
            onze(cliente,atividade,seguidor,&natividades,&nclientes);
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