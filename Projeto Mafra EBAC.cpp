#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das strings

int Registro() //Fun��o respons�vel por cadastrar os usu�rios no sistem
{
	//In�cio cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final da cria��o de vari�veis/string
	
	printf("Digite o cpf a ser cadastrado: "); //Coletando informa��o do usu�rio
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //Respons�vel por copiar os valores das strings
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa escrever 
	fprintf(file,cpf); //salvo  o valor da vari�vel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s" ,nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s" , sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
	
}

int Consulta()
{
	setlocale (LC_ALL, "Portuguese"); //Definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o Cpf a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
	printf("N�o foi possivel abrir o arquivo, n�o localizado!. \n ");	
	}
	
	while(fgets(conteudo, 200, file) != NULL) 
	{
	printf("\nEssas s�o as informa��es do usu�rio: ");
	printf("%s", conteudo);
	printf("\n\n");
	}
	
	system("pause");

	
}

int Deletar()

{

char cpf[40];

	setlocale(LC_ALL,"portuguese");

	printf("Digite o CPF a ser deletado: ");

	scanf("%s",cpf);

	FILE *file;

  	file = fopen(cpf, "r"); // Tenta abrir o arquivo para leitura

	if (file == NULL) 

	{
		
	printf("O usu�rio n�o existe!\n");

    system("pause");

	} 

else 

  {

    fclose(file); // Fecha o arquivo, pois ele existe

    remove(cpf); // Agora voc� pode remover o arquivo

    printf("Usu�rio deletado!\n");

    system("pause");

  }

}

int main()
    {
	int opcao=0; //Definindo vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
	{

	system("cls");
		
	setlocale (LC_ALL, "Portuguese"); //Definindo a linguagem
	
	printf("### Cart�rio de Ebac ###\n\n"); //In�cio do menu
	printf("Escolha a op��o desejada do menu:\n\n"); 
	printf("\t1 - Registrar nomes\n");
	printf("\t2 - Consultar nomes\n");
	printf("\t3 - Deletar nomes\n\n");
	printf("Op��o: ");  //Fim do menu
	
	scanf("%d", &opcao); //armazenando a escolha do usu�rio
	
	system("cls"); //Respons�vel por limpar a tela
		
		
	switch(opcao) //In�co da sele��o do menu
	 
	{
	case 1:
	Registro(); //Chamada de fun��es 
	break;
			
	case 2:
	Consulta();
	break;
			
	case 3:
	Deletar();
	break;
			
	default:
	printf("Essa op��o n�o est� dispon�vel\n");
	system("pause");
	} //Fim da sele��o
		
	}
}
