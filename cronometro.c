#include <stdio.h> 
#include <process.h> //_beginthread() 
#include <windows.h> 
#include <locale.h>

void tempo(); // Prot�tipo da fun��o beep()


void tempo(para) // Observe que a fun��o n�o tem o par�metro ponteiro
{ 

char info [50], nome_arquivo[20],numero[20] = "num.txt", ped;
int fim, seg, min;
FILE *arq, *num;




     	num = fopen(numero, "r");        // Abrindo o arquivo com o pedido	
           	if(numero == NULL)
           		printf("Erro, nao foi possivel abrir o arquivo\n");
           		
           	else
           		fscanf(num, "%c", &ped);


        for(min=0;min<60; min++) // Ningu�m demora mais de 1h pra fazer um lanche
        {
        	if(min==0)
        		system("color 20");//Cor verde
        		
        	else if(min==1)
				system("color 60");//Cor amarela
				
			else if(min==2)
				system("color 47");//Cor vermelha
									
        	for(seg=0;seg<60;seg++)
           {
    
           	  	  sprintf(nome_arquivo, "pedido%c.txt", ped); //SPRINTf � utilizado para usar a vari�vel na busca do arquivo. Printa o nome do arquivo no vetor "NOME_ARQUIVO".  //AQUI VAI ENTRAR O ENDERE�O
		          arq = fopen(nome_arquivo, "r");
				 
				 
				 if(arq == NULL)
				 {
				 	printf("Erro, n�o foi poss�vel encontar o pedido");
				 	break;
			     }
				
				 else
				 {
				 
				 
				  	while((fgets(info, sizeof(info), arq)) !=NULL)
						printf(" %s", info);

					fclose(arq);
     	
		       printf("\n\n Tempo de espera do cliente: %.2d:%.2d " , min, seg);
			     
			   printf("\n\n pressione ENTER quando o produto estiver pronto");//Scanf fica na main, pq � executado em uma thread diferente.
			   sleep(1);
			   system("cls");
			     }
			   	
		    }
		    
		    if(arq == NULL)
				 	break;
			    
		    
           } 
}

// ******************************************************************* Fun��o Main  ***************************************************************************

int main()
{ setlocale(LC_ALL,"portuguese");   
	  
	  /*
	  COMO C N�O � ORIENTADA A OBJETOS, USAR UMA THREAD � A �NICA MANEIRA DE REALIZAR DUAS A��ES SIMULTANEAMENTE.
	  NESSE CASO, TEMOS UM FOR CONTANDO O TEMPO AO MESMO TEMPO EM QUE ESPERA A VERIFICA��O DO USU�RIO.
	  UMA THREAD DIVIDE AS INSTRU��ES DO PROGRAMA PARA DIFERENTES N�CLEOS NO PROCESSADOR, DE FORMA QUE SEJA POSS�VEL FAZER O QUE ACIMA FOI MENCIONADO.
	  */
	  
	  
     _beginthread(tempo,0,NULL); // Chama a fun��o beep() e faz dela uma thread
     getch();
     
     
    return(0);
}
     





