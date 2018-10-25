/*
Centro Universitário Anhanguera de Niterói
João Victor Simonassi Farias. RA: 6000000060 PROUNI
joaovictorsimonassifarias@gmail.com
2º Período
Professora: Alessandra Fonseca
Trabalho final da disciplina de Programação Estruturada
*/

#include <stdio.h> // Entrada e saída
#include <stdlib.h> // Alocação de memória
#include <string.h> 
#include <unistd.h> // Leitura e escrita de arquivos no windows
#include <conio.h> // Limpa a tela e esse tipo de coisa
#include <locale.h> // Acentos e outras coisas pt-br
#include <windows.h> // Funções do windows

#define BUFFER 64 

#define acima 72 // Comandos do teclado pela tabela asc
#define abaixo 80
#define esc 27
#define enter 13

FILE *arquivo; // ponteiro para apontar o txt das vendas.
int volta = 0, conta = 0;  // Variável para armazenar a lista de pedidos.  É DECLARADA DE FORMA GLOBAL PQ SE DECLARAR DENTRO DA FUNÇÃO, SEMPRE QUE VOLTARMOS PELO WHILE, ELA VAI VOLTAR A SER 1.

// Estrutura da lista declarada para armazenar dados.
typedef struct lista {
        char *nome;
        float preco;
        int cod;
        float valor;
        struct lista *proximo;
} Dados; // Estrutura do tipo "Dados" 

//Prototipo das funcoes de manuseio dos dados. 
Dados *inicia_dados(char *nome, float preco, int cod);
Dados *insere_dados(Dados *dados, char *nome, float preco, int cod);
void exibe_dados(Dados *dados);
void busca_dados(Dados *dados, int chave);
Dados *deleta_dados(Dados *dados);
int checa_vazio(Dados *dados);
void venda_dados(Dados *dados, FILE *arquivo, int volta, int conta);

// Prototipo das funcoes do menu.
void insere(void);
void exibe(void);
void busca(void);
void deleta(void);
void venda(void);

// Inicializa a estrutura de dados principal. 
Dados *principal = NULL;

//**************************************************************  FUNÇÃO INICIA_DADOS (STRUCT) *************************************************************************
// Cria a nova lista apontando o proximo no para NULL.
Dados *inicia_dados(char *nome, float preco, int cod) {

        Dados *novo;

        novo = (Dados *)malloc(sizeof(Dados));

        novo->nome = (char *)malloc(strlen(nome)+1);
        strncpy(novo->nome, nome, strlen(nome)+1);

        novo->preco = preco;
        novo->cod = cod;

        novo->proximo = NULL;

        return novo;
}


//**************************************************************  FUNÇÃO INSERE_DADOS (STRUCT) *************************************************************************
// Como a lista nao esta mais vazia, apontamos o proximo no para lista anterior.
Dados *insere_dados(Dados *dados, char *nome, float preco, int cod) {

        Dados *novo;

        novo = (Dados *)malloc(sizeof(Dados));

        novo->nome = (char *)malloc(strlen(nome)+1);
        strncpy(novo->nome, nome, strlen(nome)+1);

        novo->preco = preco;
        novo->cod = cod;


        novo->proximo = dados;

        return novo;
}


//**************************************************************  FUNÇÃO EXIBE_DADOS *************************************************************************
// Percorre todos os campos da lista e imprime ate o ponteiro proximo chegar em NULL.
void exibe_dados(Dados *dados) {

        fprintf(stdout, "Cadastro:\n\n");

        fprintf(stdout, "------------------------\n");

        for (; dados != NULL; dados = dados->proximo) {
                fprintf(stdout, "Nome do produto: %s\n", dados->nome);
                fprintf(stdout, "Código do produto: %d\n", dados->cod);
                fprintf(stdout, " R$: %4.2f reais \n", dados->preco);
                fprintf(stdout, "------------------------\n ");
        }
        printf("Pressione uma tecla para continuar.");
        getch();
}

//**************************************************************  FUNÇÃO BUSCA_DADOS *************************************************************************
// Percorre a lista comparando o nome com a chave.
void busca_dados(Dados *dados, int chave) {

        int achou = 0;

        fprintf(stdout, "Cadastro:\n\n");
        for (; dados != NULL; dados = dados->proximo) {
                if (dados->cod == chave) {

                        printf("------------------------\n");
                        printf("Nome do produto: %s\n", dados->nome);
                        printf("Código do produto: %d\n", dados->cod);
                        printf("R$ %4.2f reais \n", dados->preco);
                        printf("------------------------\n");
                        achou++;
                }
        }

        if (achou == 0)
                printf("Nenhum resultado encontrado.\nPressione uma tecla para continuar.\n");
        else
                printf("Foram encontrados %d registros. \nPressione uma tecla para continuar.\n", achou);

}

//**************************************************************  FUNÇÃO DELETA_DADOS *************************************************************************
// Deleta o ultimo registro inserido.

Dados *deleta_dados(Dados *dados) {

        Dados *novo;

        novo = dados->proximo;

        free(dados->nome);
        free(dados);

        fprintf(stdout, "O ultimo registro inserido foi deletado com sucesso.\n");
        Sleep(1);

        return novo;
}

//**************************************************************  FUNÇÃO CHECA_VAZIO *************************************************************************
// apenas checa se a struct aponta pra NULL.
int checa_vazio(Dados *dados) {

        if (dados == NULL) {
                fprintf(stdout, "Lista vazia!\n");
                Sleep(1000);
                main();
        } else
                return 0;
}


//**************************************************************  FUNÇÃO VENDA_DADOS *************************************************************************
void venda_dados(Dados *dados, FILE *arquivo, int volta, int conta) {

	int qnt, chave, produto = 1; // Conta vai marcar o número de pedidos na fila
    float valor =0, preco;
    char cmd[256];
	static int ped = 1;
        do{
        	int achou = 0; // é declarada aqui, pq se não mesmo que um produto não estivesse cadastrado ele continuaria a venda
        	Dados *b_dados = dados; // Ponteiro para resetar o for. O For, depois de executado para no item escolhido, logo, é como se ignora-se todos os itens antes do escolhido
        	
        	
        		if (!checa_vazio(principal)) { //teste se tá vazio, como na função busca, mas tudo em uma função só
                		fprintf(stdout, "\n Digite o código do produto: \n--> ");
                		scanf("%d", &chave);


        printf("\n Cadastro:\n");
        for ( ; dados != NULL; dados = dados->proximo)
		 {
                 if (dados->cod == chave)
				 {

                        printf(" ------------------------\n");
                        printf(" Nome do produto: %s\n", dados->nome);
                        printf(" Código do produto: %d\n", dados->cod);
                        printf(" R$ %4.2f reais \n", dados->preco);
                        printf(" ------------------------\n");
                        achou++;
                        break;
                }
        }

        if (achou == 0)
                printf("Nenhum resultado encontrado.");
        else{
                printf("\n\n Foram encontrados %d registros. \n\n", achou);
															   conta++;  //adiciona o número do pedido .txt

        printf(" Quantidade: ");
		scanf("%d", &qnt);


						 arquivo = fopen("pedido.txt","a"); //criando arquivo .txt
                         
                        				 if(arquivo == NULL)
                                	     printf("Erro ao se comunicar com o servidor da cozinha!"); // não conseguiu salvar o .TXT

                         				 else {
    			 						        fprintf(arquivo," Pedido número: %d", conta);
    			 						        fprintf(arquivo,"\n\n-------------------------\n");
   			    						        fprintf(arquivo," NOME: %s \n", dados->nome);  // Vai escrever isso no .txt
   			    						        fprintf(arquivo," QUANTIDADE: %d\n", qnt);
   			    						        fprintf(arquivo,"-------------------------\n");
   		              	                      }
   		              	  fclose(arquivo);
   		              	 		sprintf(cmd,"rename pedido.txt pedido%d.txt", ped);//muda o nome do pedido, assim, a cada nova venda é criado um novo .txt
						 		system(cmd);
						 		ped++;// incrementa o valor do pedido, para mudar os txt subsequentes. ENTRA AQUI, PQ SE FOR ADICIONAR MAIS UM PRODUTO, NÃO CRIAR UM NOVO TXT DE PEDIDO		
						  
       
		valor = valor + (dados->preco * qnt); // variável acumulativa
        printf("\n Valor total R$: %4.2f", valor);
        }
        
        dados = b_dados;// Reseta o for  
        
        printf("\n\n Digite 1 para adicionar outro produto a venda, ou 0 para sair ");
        scanf("%d", &volta);
        
        	if (volta == 1) 
        	{
        		produto++;// volta a 1 sempre, toda vez que sai da função
				printf("\n\n****************  PRODUTO 0%d  ****************\n", produto);
        	}
        	else if(volta == 0)
        		 main(); //volta pra main
        		
        
        		
          }// chave do if lá em cima
        }while(volta == 1);
        
       
}



//**************************************************************  FUNÇÃO INSERE  *************************************************************************

/* Obtem os dados necessarios para chamar as funcoes de manuseio de dados. */
void insere(void) {

        char *nome;
        int cod;
        float preco;


        nome = (char *)malloc(BUFFER);
       

        printf("\n Digite o nome do produto: ");
        scanf("%s", nome); 

        printf("\n Digite o código do produto: ");
        scanf("%d", &cod);

        printf("\n Digite o preço: ");
        scanf("%f", &preco);

        printf("\n\n PRODUTO CADASTRADO!");

        if (principal == NULL)
                principal = inicia_dados(nome, preco, cod);
        else
                principal = insere_dados(principal, nome, preco, cod);
}

//**************************************************************  FUNÇÃO EXIBE  *************************************************************************
void exibe(void) {

        if (!checa_vazio(principal))
                exibe_dados(principal);

}

//**************************************************************  FUNÇÃO BUSCA  *************************************************************************
void busca(void) {

        int chave;

        if (!checa_vazio(principal)) {

                printf("Digite o código do produto: \n--> ");
                scanf("%d", &chave);

                busca_dados(principal, chave);
                getch();
        }
}
//**************************************************************  FUNÇÃO DELETA  *************************************************************************
void deleta(void) {

        if (!checa_vazio(principal))
                principal = deleta_dados(principal);
}

//**************************************************************  FUNÇÃO VENDA  *************************************************************************

void venda(void){
              venda_dados(principal, arquivo, volta, conta);
            }


//************************************************************* FUNÇÕES DA SETA **************************************************************************
inicio01()// PROCURAR UM JEITO MENOS ZOADO DE FAZER ISSO 
{
   system("cls");
   printf("\n   ------ Menu Principal --------\n");
   printf("                                 \n");
   printf("   --> Nova venda                 \n");
   printf("       Cadastrar produto          \n");
   printf("       Exibir produtos            \n");
   printf("       Buscar produto             \n");
   printf("       Deletar Dados              \n");
   printf("       Sair                       \n");
   printf("   -------------------------------");

int ch;
ch=getch();

	if (ch==enter)
		{
	 	system("cls");
	 	printf("\t NOVA VENDA\n\n");
     	venda();//Chama a função
     	sleep(1000);
    	}

	if (ch==224)
   		ch=getch();
   		
   			if (ch==acima)
      		inicio06();
      		
  			else if (ch==abaixo)
      		inicio02();
      		
   			else
      		inicio01();
}

//************************************************************** INÍCIO 02 ***********************************************************************
inicio02()
{
   system("cls");
   printf("\n   ------ Menu Principal --------\n");
   printf("                                 \n");
   printf("       Nova venda                 \n");
   printf("   --> Cadastrar produto          \n");
   printf("       Exibir produtos            \n");
   printf("       Buscar produto             \n");
   printf("       Deletar Dados              \n");
   printf("       Sair                       \n");
   printf("   -------------------------------");
int ch;
ch=getch();

	if (ch==enter)
		{
		system("cls");
		printf("\t CADASTRO DE PRODUTOS\n\n");
     	insere();
   	    Sleep(1000);
 	    }
   
	else if (ch==224)
   		ch=getch();
   if (ch==acima)
      inicio01();
   else if (ch==abaixo)
      inicio03();
   else
      inicio02();
}


//************************************************************** INÍCIO 03 ***********************************************************************
inicio03()
{
   system("cls");
    printf("\n   ------ Menu Principal --------\n");
   printf("                                 \n");
   printf("       Nova venda                 \n");
   printf("       Cadastrar produto          \n");
   printf("   --> Exibir produtos            \n");
   printf("       Buscar produto             \n");
   printf("       Deletar Dados              \n");
   printf("       Sair                       \n");
   printf("   -------------------------------");
  
int ch;
ch=getch();

if (ch==enter)
    {
      system("cls");	
      printf("\t EXIBIR PRODUTOS\n\n");
      exibe();
      Sleep(1000);
	}

else if (ch==224)
   ch=getch();
   if (ch==acima)
      inicio02();
   else if (ch==abaixo)
      inicio04();
   else
      inicio03();
}

//************************************************************** INÍCIO 04 ***********************************************************************
inicio04()
{
   system("cls");
   printf("\n   ------ Menu Principal --------\n");
   printf("                                 \n");
   printf("       Nova venda                 \n");
   printf("       Cadastrar produto          \n");
   printf("       Exibir produtos            \n");
   printf("   --> Buscar produto             \n");
   printf("       Deletar Dados              \n");
   printf("       Sair                       \n");
   printf("   -------------------------------");
  
int ch;
ch=getch();

if (ch==enter)
    {
      system("cls");
      printf("\t BUSCA DE PRODUTOS\n\n");
      busca();
      Sleep(1000);
	}

else if (ch==224)
   ch=getch();
   if (ch==acima)
      inicio03();
   else if (ch==abaixo)
      inicio05();
   else
      inicio04();
}

//************************************************************** INÍCIO 05 ***********************************************************************
inicio05()
{
   system("cls");
   printf("\n   ------ Menu Principal --------\n");
   printf("                                 \n");
   printf("       Nova venda                 \n");
   printf("       Cadastrar produto          \n");
   printf("       Exibir produtos            \n");
   printf("       Buscar produto             \n");
   printf("   --> Deletar Dados              \n");
   printf("       Sair                       \n");
   printf("   -------------------------------");
  
int ch;
ch=getch();

if (ch==enter)
    {
     system("cls");
     printf("\t DELETAR DADOS\n\n");
     deleta();
     Sleep(1000); 
	}

else if (ch==224)
   ch=getch();
   if (ch==acima)
      inicio04();
   else if (ch==abaixo)
      inicio06();
   else
      inicio05();
}

//************************************************************** INÍCIO 06 ***********************************************************************
inicio06()
{
   system("cls");
    printf("\n   ------ Menu Principal --------\n");
   printf("                                 \n");
   printf("       Nova venda                 \n");
   printf("       Cadastrar produto          \n");
   printf("       Exibir produtos            \n");
   printf("       Buscar produto             \n");
   printf("       Deletar Dados              \n");
   printf("   --> Sair                       \n");
   printf("   -------------------------------");
  
int ch;
ch=getch();

if (ch==enter)
    {
     exit(0);
	}

else if (ch==224)
   ch=getch();
   if (ch==acima)
      inicio05();
   else if (ch==abaixo)
      inicio01();
   else
      inicio06();
}



//**************************************************************  FUNÇÃO MAIN  *************************************************************************


int main() {     
setlocale(LC_ALL, "Portuguese");
system("color 4E");
system("cls");

while(1)
inicio01();

return 0;
}
