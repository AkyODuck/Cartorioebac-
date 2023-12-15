#include <stdio.h>  //biblioteca de comunicação com o usuário
#include <stdlib.h>  //biblioteca de alocação de espaço em memória
#include <locale.h>  // biblioteca de alocações de texto por região
#include <string.h>  //biblioteca responsável por cuidar das strings

int registro() //função responsavel por cadastrar cada usuário no sistema
{
//inicio da criação de variáveis/strings
    char arquivo[40];
	char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
//final da criação de variáveis/strings

    printf("Digite o CPF a ser cadastrado: "); //coletando informações do usuário
    scanf("%s", cpf); //%s refere-se a strings
    
    strcpy(arquivo, cpf);  //responsável por copiar os valores das strings
    
    FILE *file;  // cria o arquivo
    file = fopen(arquivo, "w");  //cria o arquivo e o "w" significa escrever /write
    fprintf(file,cpf);  // salvo o valor da variável
    fclose(file); // fecha o arquivo 
    
    file = fopen(arquivo, "a");
    fprintf(file,",");
    fclose(file);
    
    printf("Digite o nome a ser cadastrado: ");
    scanf("%s",nome);
    
    file = fopen(arquivo, "a");
    fprintf(file,nome);
    fclose(file);
    
    file = fopen(arquivo, "a");
    fprintf(file,",");
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
    
    system("pause"); // pausa a mensagem/informação na tela para o usuário 
    
    
    
}

int consulta()
{
    setlocale(LC_ALL, "portuguese");  //definindo a localidade/linguagem	
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("Não foi possivel abrir o arquivo, não localizado!.\n");
	} 
	 
	 
	 while(fgets(conteudo, 200, file) != NULL)
	 {
	 	printf("\nEssas são as informações do usuário: ");
	 	printf("%s", conteudo);
	 	printf("\n\n");
	 }
	 
	 system("pause");

}

int deletar()
{

	char cpf[40];

	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s",cpf);

	remove(cpf);

	FILE *file;
	file = fopen(cpf,"r");

	if(file == NULL)
	{
		printf("Este usuário não se encontra no sistema!.\n");
		system("pause");
	}
}

int main()
{
	int opcao=0;  //definindo variáveis
	int laco=1;  //laço 
	
	for(laco=1;laco=1;)
	{
	 
	    system("cls");
	
	    setlocale(LC_ALL, "portuguese");  //definindo a localidade/linguagem
	
	
	    printf("|||| Super Jambo Strike ||||\n\n\n");  //inicio menu
	    printf("Escolha a opção desejada do menu:\n\n\n");
	    printf("\t1 - Registrar \n");
	    printf("\t2 - Consultar \n");
	    printf("\t3 - Deletar \n");
	    printf("\t4 - Sair \n\n");
	    printf("opção: ");  //fim menu
	
	    scanf("%d", &opcao); //armazenando a escolha do usuário
	
	    system("cls"); //responsavel por limpar a tela
		
		switch(opcao) //inicio da seleção do menu
		{
			case 1:
		    registro(); //chamada de funções 
		    break;
		    
		    case 2:
		    consulta();
		    break;
		    
		    case 3:
		    deletar();
		    break;
		    
		    case 4:
		    printf("Muito Obrigado por utilizar o sistema!/n");
		    return 0;
		    break;
		    
		    default:
		    printf("essa opção não existe,tente novamente!\n");
		    system("pause");
		    break;
		}  //fim da seleção
	

    }
	
	
}
