#include <stdio.h> 
#include <process.h> //_beginthread() 
#include <windows.h> 
#include <locale.h>

void tempo(); // Protótipo da função beep()


void tempo(para) // Observe que a função não tem o parâmetro ponteiro
{ 

char info [50], nome_arquivo[20],numero[20] = "num.txt", ped;
int fim, seg, min;
FILE *arq, *num;




     	num = fopen(numero, "r");        // Abrindo o arquivo com o pedido	
           	if(numero == NULL)
           		printf("Erro, nao foi possivel abrir o arquivo\n");
           		
           	else
           		fscanf(num, "%c", &ped);


        for(min=0;min<60; min++) // Ninguém demora mais de 1h pra fazer um lanche
        {
        	if(min==0)
        		system("color 20");//Cor verde
        		
        	else if(min==1)
				system("color 60");//Cor amarela
				
			else if(min==2)
				system("color 47");//Cor vermelha
									
        	for(seg=0;seg<60;seg++)
           {
    
           	  	  sprintf(nome_arquivo, "pedido%c.txt", ped); //SPRINTf é utilizado para usar a variável na busca do arquivo. Printa o nome do arquivo no vetor "NOME_ARQUIVO".  //AQUI VAI ENTRAR O ENDEREÇO
		          arq = fopen(nome_arquivo, "r");
				 
				 
				 if(arq == NULL)
				 {
				 	printf("Erro, não foi possível encontar o pedido");
				 	break;
			     }
				
				 else
				 {
				 
				 
				  	while((fgets(info, sizeof(info), arq)) !=NULL)
						printf(" %s", info);

					fclose(arq);
     	
		       printf("\n\n Tempo de espera do cliente: %.2d:%.2d " , min, seg);
			     
			   printf("\n\n pressione ENTER quando o produto estiver pronto");//Scanf fica na main, pq é executado em uma thread diferente.
			   sleep(1);
			   system("cls");
			     }
			   	
		    }
		    
		    if(arq == NULL)
				 	break;
			    
		    
           } 
}

// ******************************************************************* Função Main  ***************************************************************************

int main()
{ setlocale(LC_ALL,"portuguese");   
	  
	  /*
	  COMO C NÃO É ORIENTADA A OBJETOS, USAR UMA THREAD É A ÚNICA MANEIRA DE REALIZAR DUAS AÇÕES SIMULTANEAMENTE.
	  NESSE CASO, TEMOS UM FOR CONTANDO O TEMPO AO MESMO TEMPO EM QUE ESPERA A VERIFICAÇÃO DO USUÁRIO.
	  UMA THREAD DIVIDE AS INSTRUÇÕES DO PROGRAMA PARA DIFERENTES NÚCLEOS NO PROCESSADOR, DE FORMA QUE SEJA POSSÍVEL FAZER O QUE ACIMA FOI MENCIONADO.
	  */
	  
	  
     _beginthread(tempo,0,NULL); // Chama a função beep() e faz dela uma thread
     getch();
     
     
    return(0);
}
     





