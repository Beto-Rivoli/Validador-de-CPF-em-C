#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int cpf[2][9],cpf2[2][10], cpfverdadeiro[11], cpfmul[10];
int resul,x,y,i, somain,somain2,resto,resto2,vezes,digito1,digito2,validos,invalidos,total;
char resp;

main()
{
	vezes = 1;
	
	printf("deseja iniciar o programa de validacao de cpf? s ou n:\n");
	scanf("%s",&resp);
	while( resp != 's' && resp !='S' && resp !='n' && resp !='N')
	{
		
		
		printf("Digitação invalida");
		printf("\n Por favor, digite um numero valido: ");
		scanf("%s",&resp);
		
		
		
	}
	

	
	while((resp == 's'|| resp =='S') && vezes <=20)
	{
		y=0;
		total++;
		somain = 0;
		somain2 = 0;
		resto = 0;
		resto2 = 0;
		digito1 = 0;
		digito2 = 0;
			for (i=0;i<=10;i++)
			{

					printf("digite um numero do cpf de cada vez: \n");
					scanf("%d",&cpfverdadeiro[i]);
				    	while((cpfverdadeiro[i] <0) || (cpfverdadeiro[i] >9))
						{
				    		printf("Digitacao invalida");
							printf("\n Por favor, digite um numero valido: ");
							scanf("%d",&cpfverdadeiro[i]);	
						}		
				    	
			}
					for(x=0;x<=8;x++)
					{
					cpf[y][x] = 0;	
					}
						//Calculo 1 digito	
					for(x=0;x<=8;x++)
					{
						cpf[y][x] = cpfverdadeiro[x];
						
					}
			
					y=1;
					
					for(x=0;x<=8;x++)
					{
				
						cpf[y][x]= 10-x;
							
					}
				
					i=0;
					for(x=0;x<=8;x++)
					{
					cpfmul[x] = 0;	
					}
					for(x=0;x<=8;x++)
					{
							cpfmul[x] = cpf[i][x] * cpf[y][x];
						//printf(" %d ",cpfmul[x]);
					}
				
					for(x=0;x<=8;x++)
					{
						somain= somain + cpfmul[x] ;
					
					}
			       
					resto = somain % 11;
				if(resto <2)
				{
					digito1 = 0;
				}else
				{
					digito1 = 11 - resto;
				}
					//printf("%d",digito1);
		
					//calculo 2 digito
				y=0;
					for(x=0;x<=9;x++)
					{
						cpf2[y][x] = cpfverdadeiro[x];
					
				
					}
					y=1;	
					for(x=0;x<=9;x++)
					{
				
						cpf2[y][x]= 11-x;
							
					}
				i=0;
			
					for(x=0;x<=9;x++)
					{
						cpfmul[x] = cpf2[i][x] * cpf2[y][x];
					
					}
			
					for(x=0;x<=9;x++)
					{
						somain2= somain2 + cpfmul[x] ;
					
					}
				
			
					resto2 = somain2 % 11;
					if(resto2 <2)
					{
						digito2 = 0;
					}
					else
					{
						digito2 = 11 - resto2;
					}
			
						//printf("%d",digito2);
			
			if (cpfverdadeiro[9] == digito1 && cpfverdadeiro[10] == digito2)
			{
				printf("\nEste cpf e valido!\n");
				validos++;
			}
			else
			{
				printf("\nEste cpf e invalido!\n");
				invalidos++;
			}
			
					 if(vezes <20)
					{
					
						printf("deseja colocar outro cpf para a validacao? s ou n: ");
						scanf("%s",&resp);
							while( resp != 's' && resp !='S' && resp !='n' && resp !='N')
							{
		
		
								printf("Digitação invalida");
								printf("\n Por favor, digite um numero valido: ");
								scanf("%s",&resp);			
							}
					}
		 system("cls");
			
		vezes++;
	}
			printf("O programa foi encerrado, abaixo segue os resultados obtidos:\n");
			printf("O numero total de cps testados e: %d\n",total);
			printf("O numero de cps validos sao: %d\n",validos);
			printf("O numero de cps invalidos sao: %d\n",invalidos);		
				
				
	return 0;
}
