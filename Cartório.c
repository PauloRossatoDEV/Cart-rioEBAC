#include <stdio.h> //Biblioteca de comunica��o com o usu�rio.
#include <stdlib.h> //Biblioteca de aloca��o de  espa�o de mem�ria.
#include <locale.h> //Biblioteca de aloca��es de texto por regi�o.
#include <string.h> //Biblioteca responsavel por cuidar das string.

int registro() //Fun��o responsavel por cadastrar os usu�rios no sistema.
{
	//Inico da cria��o de vari�veis.
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final da cri��o de vari�veis.
	printf("Digite o CPF a ser cadastrado: ");//Coletando informa��es do usu�rio.
	scanf("%s",cpf); //%S Refere-se ao salvamento de uma String.
	
	strcpy(arquivo, cpf); //Responsavel por copiar os valores das string.
	
	FILE *file; //Cria o arquivo.
	file = fopen(arquivo, "w"); //Cria e salva os dados a serem inseridos. "W" Significa escrever.
	fprintf(file,cpf); //Salvo o valor da varivel.
	fclose(file); //Fecho o arquivo.
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: "); //Requisitando os nomes a serem integrados a base de dados.
	scanf("%s",nome); //Criando a salvando os nomes.
	
	file = fopen(arquivo, "a"); //Abrindo a inserindo o nome na base de dados.
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,","); //Inserindo virgula entre os dados a serem salvos.
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
	
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("N�o foi possivel abrir o arquivo, n�o localizado!\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r"); //Fazendo a leitura do dado CPF
	
	if(file == NULL)
	{
		printf("O usu�rio n�o se encontra no sistema! \n");
		system("pause");
	}
	
}

int main()
{
	int opcao=0; //Definindo as vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		
		system("cls");
		
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
		printf("### Cart�rio da EBAC###\n\n"); //Inicio do Menu
		printf("Escolha a op��o desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n");
		printf("\t4 - Sair do sistema\n\n");
		printf ("Op��o:"); //Fim do Menu
	
		scanf("%d", &opcao); //Armazenando a escolha do usu�rio
	
		system("cls"); //Limpando a tela para melhor est�tica
		
		
		switch(opcao) //Inicio da sele��o do Menu.
		{
			case 1:
			registro();
			break;
			
			case 2:
			consulta(); //Chamada de Fun��es.
			break;
			
			case 3:
			deletar();
			break;
			
			case 4:
			printf("Obrigado por utilizar o sistema!");
			return 0;
			break;
			
			default:
			printf("Essa op��o n�o esta disponivel!");
			system("pause");
			break;
			//Fim da Sele��o.
		}
		
	}
}
