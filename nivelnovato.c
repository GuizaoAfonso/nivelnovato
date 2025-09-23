#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Constantes globais
#define max_territorio 5

// Definição da Estrutura
struct Territorio {
    char nome[30];
    char cor[10];
    int tropas;
};

// Função para limpar o buffer de entrada
void limparBufferEntrada() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Função principal
int main() {
    struct Territorio cadastro[max_territorio];

    printf("====================================\n");
    printf("   CADASTRO DE %d TERRITÓRIOS\n", max_territorio);
    printf("====================================\n\n");

    // Cadastro dos 5 territórios em sequência
    for (int i = 0; i < max_territorio; i++) {
        printf("--- Cadastro do Território %d ---\n", i + 1);

        printf("Digite o nome do Território: ");
        fgets(cadastro[i].nome, sizeof(cadastro[i].nome), stdin);
        cadastro[i].nome[strcspn(cadastro[i].nome, "\n")] = '\0';

        printf("Digite a cor do Exército: ");
        fgets(cadastro[i].cor, sizeof(cadastro[i].cor), stdin);
        cadastro[i].cor[strcspn(cadastro[i].cor, "\n")] = '\0';

        printf("Digite o número de Tropas: ");
        scanf("%d", &cadastro[i].tropas);
        limparBufferEntrada();

        printf("\n");
    }

    // Exibe o "mapa" dos territórios cadastrados
    printf("\n====================================\n");
    printf("       MAPA DE TERRITÓRIOS\n");
    printf("====================================\n\n");

    for (int i = 0; i < max_territorio; i++) {
        printf("Território %d: %s\n", i + 1, cadastro[i].nome);
        printf("Cor do Exército: %s\n", cadastro[i].cor);
        printf("Tropas: %d\n", cadastro[i].tropas);
        printf("-----------------------------\n");
    }

    printf("\nFim do cadastro e exibição do mapa!\n");

    return 0;
}