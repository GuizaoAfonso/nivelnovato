#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Constantes globais
#define max_livros 50
#define tam_string 100

//Definição da Estrutura
struct Livro
{
    char nome[tam_string];
    char autor[tam_string];
    char editora[tam_string];
    int edicao;
};

//Função para limpar o buffer de entrada
void limparBufferEntrada(){
    int c;
    while ((c = getchar()) != '\n' && c != EOF);    
}


// Função principal
int main() {
    struct Livro biblioteca[max_livros];
    int totalLivros = 0;
    int opcao;


//Laço principal do menu
do {
    
    //Exibe o menu de opções
    printf("====================================\n");
    printf("=====BIBLIOTECA - PARTE 1\n");
    printf("====================================\n");
    printf("1- Cadastrar novo Livro\n");
    printf("2- Listar todos os Livros\n");
    printf("0- Sair\n");
    printf("====================================\n");
    printf("Escolha uma opção:\n");


    //Lê a opção do usuário
    scanf("%d", &opcao);
    limparBufferEntrada(); //limpa o \n deixado pelo scanf

    //Processamento da opção
    switch (opcao)
    {
    case 1: //Cadastro de Livros
        printf("--- Cadastro de Novo livro ---\n\n");

        if (totalLivros < max_livros)
        {
            printf("Digite o nome do Livro:");
            fgets(biblioteca[totalLivros].nome, tam_string, stdin);

            printf("Digite o nome do Autor:");
            fgets(biblioteca[totalLivros].autor, tam_string, stdin);

            printf("Digite o nome da Editora:");
            fgets(biblioteca[totalLivros].editora, tam_string, stdin);

            biblioteca[totalLivros].nome[strcspn(biblioteca[totalLivros].nome, "\n")] = '\0';
            biblioteca[totalLivros].autor[strcspn(biblioteca[totalLivros].autor, "\n")] = '\0';
            biblioteca[totalLivros].editora[strcspn(biblioteca[totalLivros].editora, "\n")] ='\0';
            
            printf("Digite a edição:");
            scanf("%d", &biblioteca[totalLivros].edicao);
            limparBufferEntrada();

            totalLivros++;

            printf("Livro Cadastrado com sucesso!\n");
        } else {
            printf("Biblioteca cheia! Não é possível cadastrar mais livros.\n");
        }
        
        printf("\nPressione Enter para continuar...\n");
        getchar(); // Pausa para o usuário ler a mensagem
        break;

    case 2: //Listagem de livros
        printf("---Listas de livros cadastrados---\n\n");

        if (totalLivros == 0)
        {
            printf("Nenhum livro cadastrado ainda.\n");
        } else
        {
            for (int i = 0; i < totalLivros; i++)
            {
                printf("-----------------------------\n");
                printf("Livro: %d\n", i + 1);
                printf("Nome: %s\n", biblioteca[i].nome);
                printf("Autor: %s\n", biblioteca[i].autor);
                printf("Editora: %s\n", biblioteca[i].editora);
                printf("Edição: %s\n", biblioteca[i].edicao);
            }
            printf("-----------------------------\n");
            
        }

        //pausa para leitura

        printf("\nPressione Enter para continuar...\n");
        getchar();
        break;

    case 0: //sair
        printf("\nSaindo do Sistema...\n");
        break;

    default: //opção inválida
        printf("\nOpção inválida, tente novamente...\n");
        printf("\nPressione Enter para continuar...\n");
        getchar();
        break;
}
        

} while (opcao != 0);

return 0;  //fim do programa

}
