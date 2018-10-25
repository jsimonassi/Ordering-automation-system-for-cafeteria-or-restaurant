#include <stdio.h> 
#include <stdlib.h>
#include <windows.h> 
#include <locale.h>

int main()
{   //da a ilusão de carregamento
system("color 100");
	 printf("\t  CARREGANDO:\n");
	 printf(" ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿ \n");
	 printf(" ³                              ³\n");
	 printf(" ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ");
	 Sleep(500);
	 system("cls");
	 printf("\t  CARREGANDO:\n");
	 printf(" ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿ \n");
	 printf(" ³ÛÛÛÛÛ                         ³\n");
	 printf(" ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ");
	 Sleep(700);
	 system("cls");
	 printf("\t  CARREGANDO:\n");
	 printf(" ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿ \n");
	 printf(" ³ÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛ               ³\n");
	 printf(" ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ");
	 Sleep(400);
	 system("cls");
	 printf("\t  CARREGANDO:\n");
	 printf(" ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿ \n");
	 printf(" ³ÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛ     ³\n");
	 printf(" ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ");
	 Sleep(300);
	 system("cls");
	 printf("\t  CARREGANDO:\n");
	 printf(" ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿ \n");
	 printf(" ³ÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛ³\n");
	 printf(" ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ");
	 Sleep(1000);
	 system("cls");
	 
	 
	 
	 
	 setlocale(LC_ALL,"portuguese");  //entra aqui, se não os caracters de cima teriam sido interpretados como acentos
	 
	 char info [50], nome_arquivo[20];
	 int conta = 1;
	 FILE *arq, *num;
	 
	 
	 while(1){
	system("color 4E");//repeti o comando pq no outro programa ele muda a cor
	
	
	//************************************************************** abrindo arquivo só c/ número ************************************************* SERVE PRA INCREMENTAR OS PEDIDOS E O OUTRO PROGRAMA NÃO PERDER A REFERÊNCIA
	  num = fopen("num.txt","w"); //criando arquivo .txt com o número do pedido
                         
                    if(num == NULL)
                    printf("Erro ao se comunicar com o servidor da cozinha!"); // não conseguiu salvar o .TXT

                    else 
    			    fprintf(num,"%d", conta);
    			
   		            fclose(num);
	
	// ************************************************************ abrindo o pedido final *******************************************************
	
	             sprintf(nome_arquivo, "pedido%d.txt", conta); //SPRINTf é utilizado para usar a variável na busca do arquivo. Printa o nome do arquivo no vetor "NOME_ARQUIVO".   //AQUI VAI ENTRAR O ENDEREÇO
		         arq = fopen(nome_arquivo, "r");
				if(arq == NULL)
				{
					printf("\n Nenhum novo pedido na fila"); // Na verdade ele não conseguiu encontar o .txt. Continua como PEDIDO1 até que o arquivo seja criado
	                Sleep(1000);
	            }
	            
	  			else
	  			{
	  				printf("\n NOVO PEDIDO NA FILA\n\n");
	  				Sleep(2000);		
	  				system("cronometro.exe"); //chama o outro programa com a thread
					conta++;
					remove("pedido1.txt");		
				}
     
     			fclose(arq);
     system("cls");
          }
     
    return(0);
}
     

