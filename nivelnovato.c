#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Constantes globais
#define max_territorio 5
#define tam_string 100

//Definição da Estrutura
struct Territorio
{
    char nome[30];
    char cor[10];
    int tropas;
};

//Função para limpar o buffer de entrada
void limparBufferEntrada(){
    int c;
    while ((c = getchar()) != '\n' && c != EOF);    
}


// Função principal
int main() {
    struct Territorio cadastro[max_territorio];
    int totalTerritorio = 0;
    int opcao;


//Laço principal do menu
do {
    
    //Exibe o menu de opções
    printf("====================================\n");
    printf("      CADASTRANDO TERRITÓRIOS\n");
    printf("====================================\n");
    printf("1- Cadastrar novo Território\n");
    printf("2- Listar todos os Territórios\n");
    printf("0- Sair\n");
    printf("====================================\n");
    printf("Escolha uma opção:\n");


    //Lê a opção do usuário
    scanf("%d", &opcao);
    limparBufferEntrada(); //limpa o \n deixado pelo scanf

    //Processamento da opção
    switch (opcao)
    {
    case 1: //Cadastro de Territórios
        printf("--- Cadastro do Território 1 ---\n\n");

        if (totalTerritorio < max_territorio)
        {
            printf("Digite o nome do Território:");
            fgets(cadastro[totalTerritorio].nome, tam_string, stdin);

            printf("Digite a cor do Exército:");
            fgets(cadastro[totalTerritorio].cor, tam_string, stdin);

            cadastro[totalTerritorio].nome[strcspn(cadastro[totalTerritorio].nome, "\n")] = '\0';
            cadastro[totalTerritorio].cor[strcspn(cadastro[totalTerritorio].cor, "\n")] = '\0';
                        
            printf("Digite o número de Tropas:");
            scanf("%d", &cadastro[totalTerritorio].tropas);
            limparBufferEntrada();

            totalTerritorio++;

        printf("--- Cadastro do Território 2 ---\n\n");

            printf("Digite o nome do Território:");
            fgets(cadastro[totalTerritorio].nome, tam_string, stdin);

            printf("Digite a cor do Exército:");
            fgets(cadastro[totalTerritorio].cor, tam_string, stdin);

            cadastro[totalTerritorio].nome[strcspn(cadastro[totalTerritorio].nome, "\n")] = '\0';
            cadastro[totalTerritorio].cor[strcspn(cadastro[totalTerritorio].cor, "\n")] = '\0';
                        
            printf("Digite o número de Tropas:");
            scanf("%d", &cadastro[totalTerritorio].tropas);
            limparBufferEntrada();

            totalTerritorio++;

        printf("--- Cadastro do Território 3 ---\n\n");

            printf("Digite o nome do Território:");
            fgets(cadastro[totalTerritorio].nome, tam_string, stdin);

            printf("Digite a cor do Exército:");
            fgets(cadastro[totalTerritorio].cor, tam_string, stdin);

            cadastro[totalTerritorio].nome[strcspn(cadastro[totalTerritorio].nome, "\n")] = '\0';
            cadastro[totalTerritorio].cor[strcspn(cadastro[totalTerritorio].cor, "\n")] = '\0';
                        
            printf("Digite o número de Tropas:");
            scanf("%d", &cadastro[totalTerritorio].tropas);
            limparBufferEntrada();

            totalTerritorio++;

        printf("--- Cadastro do Território 4 ---\n\n");

            printf("Digite o nome do Território:");
            fgets(cadastro[totalTerritorio].nome, tam_string, stdin);

            printf("Digite a cor do Exército:");
            fgets(cadastro[totalTerritorio].cor, tam_string, stdin);

            cadastro[totalTerritorio].nome[strcspn(cadastro[totalTerritorio].nome, "\n")] = '\0';
            cadastro[totalTerritorio].cor[strcspn(cadastro[totalTerritorio].cor, "\n")] = '\0';
                        
            printf("Digite o número de Tropas:");
            scanf("%d", &cadastro[totalTerritorio].tropas);
            limparBufferEntrada();

            totalTerritorio++;

        printf("--- Cadastro do Território 5 ---\n\n");

            printf("Digite o nome do Território:");
            fgets(cadastro[totalTerritorio].nome, tam_string, stdin);

            printf("Digite a cor do Exército:");
            fgets(cadastro[totalTerritorio].cor, tam_string, stdin);

            cadastro[totalTerritorio].nome[strcspn(cadastro[totalTerritorio].nome, "\n")] = '\0';
            cadastro[totalTerritorio].cor[strcspn(cadastro[totalTerritorio].cor, "\n")] = '\0';
                        
            printf("Digite o número de Tropas:");
            scanf("%d", &cadastro[totalTerritorio].tropas);
            limparBufferEntrada();

            totalTerritorio++;

            printf("Territórios Cadastrados com Sucesso!\n");
        } else {
            printf("Territórios cheios! Não é possível cadastrar mais Territórios.\n");
        }
        
        printf("\nPressione Enter para continuar...\n");
        getchar(); // Pausa para o usuário ler a mensagem
        break;

    case 2: //Listagem de Territórios
        printf("---Listas de Territórios cadastrados---\n\n");

        if (totalTerritorio == 0)
        {
            printf("Nenhum Território cadastrado ainda.\n");
        } else
        {
            for (int i = 0; i < totalTerritorio; i++)
            {
                printf("-----------------------------\n");
                printf("Território: %d\n", i + 1);
                printf("Cor do Exército: %d\n", cadastro[i].cor);
                printf("Tropa: %s\n", cadastro[i].tropa);
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