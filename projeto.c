#include <stdio.h>
#include <stdlib.h>
#include <locale.h>//permite colocar caracteres específicos de regiões do mundo
#include <string.h> //permite inserir strings no programa

//comandos para se lembrar
//"\t" - adjacente à frase, funciona como um TAB
//"\n" - como se fosse o println do arduino
// printf - nome auto-explicativo
//system("cls") -- system cleanse. Fala direto com seu sistema para limpar a tela após uma determinada ação no código for feita
 //scanf -- função de scan de algo
 //for -- é o enquanto. (while). ele especifica a repetição de uma função sobre as condições de valores postas no for. Exemplo: for(x=1,x=10,x++). aqui ele diz que a função via se repetir quando x for 1 e terminar quando x for 10, e diz tamhém que a cada vez que se repetir, há de se adcionar 1 valor à x. Portanto, se repetir 1 vez. x passará a ser 2, e assim vai.
//system("pause") -- para o sistema após uma determinada ação
int consulta()
{
	
	setlocale(LC_ALL, "Portuguese");

	
	char cpf[40];//por que criaste de novo? simples, o essa função não tem ciência de que outra já tem essa char, logo, é mister que criemos outra para que essa função funcione.
	char conteudo[200];//conteúdo a ser lido
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);//"%s" se refere a string, é um jeito de mencionar sem ter que escrever "string"
	
	
	FILE *file;
	file = fopen(cpf, "r");//o "r" é de READ
	if(file == NULL)
	{
		printf("Não foi possível encontrar o CPF digitado.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("Essas são as informações do usuário: ");
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
	
	strcpy(arquivo, cpf);//responsável por copiar os valores de duas strings diferentes, sendo o primeiro o destino e o segundo a fonte de cópia.
	
	FILE *file; //FILE é uma função prórpia do sistema para criar um arquivo
	file = fopen(arquivo, "r");
	if (file == NULL)
	{
	file = fopen(arquivo, "w"); //cria o arquivo. fopen é para abrir, e o "w" é para criar um novo arquivo
	fprintf(file, cpf);//salvar a variável
	fclose(file);//mesma função do break de switch-case
	
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
		printf("Usuário já cadastrado no sistema.\n");
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
		printf("Usuário não se encontra no sistema.\n");
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

        printf("### Cartório da EBAC ###\n\n");
        printf("Escolha a opção desejada do menu:\n\n");
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
                printf("Opção inválida. Tente novamente.\n");
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


