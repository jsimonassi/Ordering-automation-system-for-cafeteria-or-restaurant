#include <stdio.h> 
#include <stdlib.h>
#include <windows.h> 
#include <locale.h>

int main()
{   //da a ilus�o de carregamento
system("color 100");
	 printf("\t  CARREGANDO:\n");
	 printf(" ������������������������������Ŀ \n");
	 printf(" �                              �\n");
	 printf(" ��������������������������������");
	 Sleep(500);
	 system("cls");
	 printf("\t  CARREGANDO:\n");
	 printf(" ������������������������������Ŀ \n");
	 printf(" ������                         �\n");
	 printf(" ��������������������������������");
	 Sleep(700);
	 system("cls");
	 printf("\t  CARREGANDO:\n");
	 printf(" ������������������������������Ŀ \n");
	 printf(" ����������������               �\n");
	 printf(" ��������������������������������");
	 Sleep(400);
	 system("cls");
	 printf("\t  CARREGANDO:\n");
	 printf(" ������������������������������Ŀ \n");
	 printf(" ��������������������������     �\n");
	 printf(" ��������������������������������");
	 Sleep(300);
	 system("cls");
	 printf("\t  CARREGANDO:\n");
	 printf(" ������������������������������Ŀ \n");
	 printf(" ������������������������������۳\n");
	 printf(" ��������������������������������");
	 Sleep(1000);
	 system("cls");
	 
	 
	 
	 
	 setlocale(LC_ALL,"portuguese");  //entra aqui, se n�o os caracters de cima teriam sido interpretados como acentos
	 
	 char info [50], nome_arquivo[20];
	 int conta = 1;
	 FILE *arq, *num;
	 
	 
	 while(1){
	system("color 4E");//repeti o comando pq no outro programa ele muda a cor
	
	
	//************************************************************** abrindo arquivo s� c/ n�mero ************************************************* SERVE PRA INCREMENTAR OS PEDIDOS E O OUTRO PROGRAMA N�O PERDER A REFER�NCIA
	  num = fopen("num.txt","w"); //criando arquivo .txt com o n�mero do pedido
                         
                    if(num == NULL)
                    printf("Erro ao se comunicar com o servidor da cozinha!"); // n�o conseguiu salvar o .TXT

                    else 
    			    fprintf(num,"%d", conta);
    			
   		            fclose(num);
	
	// ************************************************************ abrindo o pedido final *******************************************************
	
	             sprintf(nome_arquivo, "pedido%d.txt", conta); //SPRINTf � utilizado para usar a vari�vel na busca do arquivo. Printa o nome do arquivo no vetor "NOME_ARQUIVO".   //AQUI VAI ENTRAR O ENDERE�O
		         arq = fopen(nome_arquivo, "r");
				if(arq == NULL)
				{
					printf("\n Nenhum novo pedido na fila"); // Na verdade ele n�o conseguiu encontar o .txt. Continua como PEDIDO1 at� que o arquivo seja criado
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
     

