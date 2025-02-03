#include <stdio.h>
#include <stdlib.h>
#include <locale.h>//permite colocar caracteres espec�ficos de regi�es do mundo
#include <string.h> //permite inserir strings no programa

//comandos para se lembrar
//"\t" - adjacente � frase, funciona como um TAB
//"\n" - como se fosse o println do arduino
// printf - nome auto-explicativo
//system("cls") -- system cleanse. Fala direto com seu sistema para limpar a tela ap�s uma determinada a��o no c�digo for feita
 //scanf -- fun��o de scan de algo
 //for -- � o enquanto. (while). ele especifica a repeti��o de uma fun��o sobre as condi��es de valores postas no for. Exemplo: for(x=1,x=10,x++). aqui ele diz que a fun��o via se repetir quando x for 1 e terminar quando x for 10, e diz tamh�m que a cada vez que se repetir, h� de se adcionar 1 valor � x. Portanto, se repetir 1 vez. x passar� a ser 2, e assim vai.
//system("pause") -- para o sistema ap�s uma determinada a��o
int consulta()
{
	
	setlocale(LC_ALL, "Portuguese");

	
	char cpf[40];//por que criaste de novo? simples, o essa fun��o n�o tem ci�ncia de que outra j� tem essa char, logo, � mister que criemos outra para que essa fun��o funcione.
	char conteudo[200];//conte�do a ser lido
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);//"%s" se refere a string, � um jeito de mencionar sem ter que escrever "string"
	
	
	FILE *file;
	file = fopen(cpf, "r");//o "r" � de READ
	if(file == NULL)
	{
		printf("N�o foi poss�vel encontrar o CPF digitado.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("Essas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}			
	
	system("pause");
}

int registro()
{
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o CPF a ser cadastrado\n");
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf);//respons�vel por copiar os valores de duas strings diferentes, sendo o primeiro o destino e o segundo a fonte de c�pia.
	
	FILE *file; //FILE � uma fun��o pr�rpia do sistema para criar um arquivo
	file = fopen(arquivo, "r");
	if (file == NULL)
	{
	file = fopen(arquivo, "w"); //cria o arquivo. fopen � para abrir, e o "w" � para criar um novo arquivo
	fprintf(file, cpf);//salvar a vari�vel
	fclose(file);//mesma fun��o do break de switch-case
	
	file = fopen(arquivo, "a"); //para atualizar um arquivo feito
	fprintf(file, ", ");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado\n");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado\n");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file); 
	
	printf("Selecione o cargo\n");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	system("pause");
	}
	
	else
	{
		printf("Usu�rio j� cadastrado no sistema.\n");
		system("pause");
	}

}

int deletar()
{
	char cpf[40];
	
	printf("Digite o cpf a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	if(file == NULL)
	{
		printf("Usu�rio n�o se encontra no sistema.\n");
		system("pause");
	}
	
	

	
	
	system("pause");
}


int main() {
    int opcao = 0;
    int continuar = 1;

    while (continuar) {
        system("cls");
        setlocale(LC_ALL, "Portuguese");

        printf("### Cart�rio da EBAC ###\n\n");
        printf("Escolha a op��o desejada do menu:\n\n");
        printf("\t1 - Registrar Nomes\n");
        printf("\t2 - Consultar Nomes\n");
        printf("\t3 - Deletar Nomes\n");
        printf("\t4 - Sair\n\n");
        scanf("%d", &opcao);

        system("cls");

        switch (opcao) {
            case 1:
                registro();
                break;
            case 2:
                consulta();
                break;
            case 3:
                deletar();
                break;
            case 4:
                printf("Obrigado por utilizar o sistema!\n");
                continuar = 0; 
                break;
            default:
                printf("Op��o inv�lida. Tente novamente.\n");
                system("pause");
                break;
        }

        
        if (continuar && opcao != 4) {
            char resposta;
            printf("\nDeseja continuar usando o sistema? (s/n): ");
            scanf(" %c", &resposta); 
            if (resposta == 'n' || resposta == 'N') {
                continuar = 0; 
                printf("Obrigado por utilizar o sistema!\n");
            }
        }
    }

    system("pause");
    return 0;
}


