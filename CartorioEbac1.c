#include <stdio.h> //Biblioteca de comunicação com usuário
#include <stdlib.h> //Biblioteca de alocação de espaço de memória
#include <locale.h> //bliblioteca de alocação de texto por região
#include <string.h> //biblioteca responsável por cuidar das string

int registro() //Função responsavel por cadastrar os usuários no sistema
{
	//Inicio criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final criação de variáveis/string
	
	printf("Digita o CPF a ser cadastrado: "); //Coletando informações do usuário
	scanf("%s", cpf); //%s refere-se a string (Salvando)
	
	strcpy(arquivo, cpf); //Responsável por copiar os valores dos string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa escrever
	fprintf(file,cpf); //salvo o valor da variável
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); // abrir e adicionar ao arquivo 
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: "); //Coletando informações do usuário
	scanf("%s",nome); //%s refere-se a string (Salvando)
	
	file = fopen(arquivo,"a");// abrir e adicionar ao arquivo 
	fprintf(file,nome); 
	fclose(file);
	
	file = fopen(arquivo, "a");// abrir e adicionar ao arquivo 
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: "); //Coletando informações do usuário
	scanf("%s",sobrenome);  //%s refere-se a string (Salvando)
	
	file = fopen(arquivo, "a"); // abrir e adicionar ao arquivo 
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");// abrir e adicionar ao arquivo 
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: "); //Coletando informações do usuário
	scanf("%s",cargo); //%s refere-se a string (Salvando)
	
	file = fopen(arquivo, "a"); // abrir e adicionar ao arquivo 
	fprintf(file,cargo);
	fclose(file);
		system("pause");
	
}

int consulta() //Inicio função consulta
{
	
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: "); //Coletando informações do usuário
	scanf("%s",cpf); //%s refere-se a string (Salvando)
	
	FILE *file;
	file = fopen(cpf,"r"); //consulta o arquivo já criado
	
	if(file == NULL)
	 {
	 	printf("Não foi possivel abrir o arquivo, não localizado! \n");
	 }
	
	while(fgets(conteudo, 200, file) != NULL)
		{
			printf("\nEssas são as informações do usuário:");
			printf("%s",conteudo);
			printf("\n\n");
		}
		
		fclose(file);
		
		system("pause");
		//Fim função consulta
}

int deletar()  //Inicio função deletar
		
{
		char cpf[40];
		
		printf("Digite o CPF do usuário a ser deletado: "); 
		scanf("%s",cpf);
		
		remove(cpf); 
		
		FILE *file;
		file = fopen(cpf,"r");
		
		if(file == NULL)
		{
			printf("O usuário não se encontra no sistema. \n");
			system("pause");
		}
		//Fim função deletar
}

int main()
{
	int opcao=0; //Definindo variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
		system("cls");
	
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
		printf("### Cartório da EBAC ###\n\n"); //Inicio do menu
		printf("Escolha a opção desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n"); 
		printf("Opção: "); //Fim do menu
	
		scanf("%d", &opcao); //Armazenando a escolha do usuário
	
		system("cls"); //responsavel por limpar a tela
		
		
	switch(opcao) //Inicio da seleção do menu
		{
		case 1:
			registro(); //chamada de funções
			break;
			
		case 2:
			consulta(); //chamada de funções
			break;
			
		case 3:
			deletar(); //chamada de funções
			break;
			
		default:
			printf("Essa opção não está disponivel!\n");
			system("pause");
			break;
 		} //Fim da seleção
			
	} 
}

	
