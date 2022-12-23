#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int check(char *s);
void take_component();

char databank[][40] = {
						"2AD59F"     ,"Ind�stria de Constru��o Civil",
						"AKSFF1"     ,"Ind�stria Automotiva",
						"MR002B"     ,"Ind�stria Aliment�cia",
						"YZMT7W"     ,"Automa��o Industrial",
						"AU3RE5"     ,"Ind�stria Energ�tica",
						"XLDY6T"     ,"Artigos de Casa",
						"63CL75"     ,"Artigos Geeks",
						"KT6SYR"     ,"Action Figures",
						"ONBT23"     ,"Material para setup de inform�tica",
						"6OWJMI"     ,"Material Cir�rgico",
						"GNTPUN"     ,"Material para consult�rio",

						};

char input[80];
char component[80];
char *point;

int main()
{
		int indice;
		char option;
	do
	{
	    printf("=========================== Fa�a sua Busca aqui =========================== \n",setlocale(LC_ALL,""));
		printf("\nInforme o produto que deseja pesquisar: ");
		gets(input);
		point = input;

		printf("Caracteristicas do produto pesquisado: ",setlocale(LC_ALL,""));
		take_component();

		do
		{

			indice = check(component);


			if(indice != -1){
                printf("%s", databank[indice+1]);}

			else {

                printf("\nN�o foram encontrados nenhum produto. \n");}


			take_component();

		}while(*component);

        printf("\n\n=========================================================================== \n");

		printf("\nDeseja realizar uma nova pesquisa? S - sim | N - nao \n");
		scanf("%c", &option);
		getchar();

	}while(option == 's' || option == 'S');
    printf("\n==================== Pesquisa realizada com Sucesso!! =====================\n\n");

	system("PAUSE")	;
	return 0;
}




int check(char *s)
{
	int i;

	for(i=0; *databank[i];i++)
	{
		if(!strcmp(databank[i],s)) break;

	}

	if(*databank[i]) return(i);
	else return(-1);
}


void take_component()
{
	char *q;

	q = component;

	while(*point && *point!=' ')
	{
		*q = *point;
		point++;
		q++;
	}

	if(*point == ' ') point++;
	*q = '\0';

}
