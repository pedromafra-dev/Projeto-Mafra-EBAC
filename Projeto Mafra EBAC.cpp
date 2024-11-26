#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das strings

int Registro() //Função responsável por cadastrar os usuários no sistem
{
	//Início criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final da criação de variáveis/string
	
	printf("Digite o cpf a ser cadastrado: "); //Coletando informação do usuário
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //Responsável por copiar os valores das strings
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa escrever 
	fprintf(file,cpf); //salvo  o valor da variável
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
	printf("Não foi possivel abrir o arquivo, não localizado!. \n ");	
	}
	
	while(fgets(conteudo, 200, file) != NULL) 
	{
	printf("\nEssas são as informações do usuário: ");
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
		
	printf("O usuário não existe!\n");

    system("pause");

	} 

else 

  {

    fclose(file); // Fecha o arquivo, pois ele existe

    remove(cpf); // Agora você pode remover o arquivo

    printf("Usuário deletado!\n");

    system("pause");

  }

}

int main()
    {
	int opcao=0; //Definindo variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{

	system("cls");
		
	setlocale (LC_ALL, "Portuguese"); //Definindo a linguagem
	
	printf("### Cartório de Ebac ###\n\n"); //Início do menu
	printf("Escolha a opção desejada do menu:\n\n"); 
	printf("\t1 - Registrar nomes\n");
	printf("\t2 - Consultar nomes\n");
	printf("\t3 - Deletar nomes\n\n");
	printf("Opção: ");  //Fim do menu
	
	scanf("%d", &opcao); //armazenando a escolha do usuário
	
	system("cls"); //Responsável por limpar a tela
		
		
	switch(opcao) //Iníco da seleção do menu
	 
	{
	case 1:
	Registro(); //Chamada de funções 
	break;
			
	case 2:
	Consulta();
	break;
			
	case 3:
	Deletar();
	break;
			
	default:
	printf("Essa opção não está disponível\n");
	system("pause");
	} //Fim da seleção
		
	}
}
