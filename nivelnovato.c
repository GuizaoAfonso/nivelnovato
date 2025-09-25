#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Struct do Território
struct Territorio {
    char nome[30];
    char cor[10];
    int tropas;
};

// Limpa o buffer do teclado
void limparBufferEntrada() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Exibe todos os territórios cadastrados
void exibirMapa(struct Territorio* mapa, int total) {
    printf("\n====================================\n");
    printf("         MAPA DE TERRITÓRIOS\n");
    printf("====================================\n\n");

    for (int i = 0; i < total; i++) {
        printf("Território %d: %s\n", i + 1, mapa[i].nome);
        printf("Cor do Exército: %s\n", mapa[i].cor);
        printf("Tropas: %d\n", mapa[i].tropas);
        printf("-----------------------------\n");
    }
}

// Função de ataque entre territórios
void atacar(struct Territorio* atacante, struct Territorio* defensor) {
    if (strcmp(atacante->cor, defensor->cor) == 0) {
        printf("\n[ERRO] Você não pode atacar um território do mesmo exército!\n");
        return;
    }

    printf("\n>>> BATALHA: %s (%s) ATACANDO %s (%s)\n",
           atacante->nome, atacante->cor, defensor->nome, defensor->cor);

    // Rolagem de dados (1 a 6)
    int dadoAtacante = (rand() % 6) + 1;
    int dadoDefensor = (rand() % 6) + 1;

    printf("Dado do Atacante: %d | Dado do Defensor: %d\n",
           dadoAtacante, dadoDefensor);

    if (dadoAtacante > dadoDefensor) {
        printf(">> O atacante venceu a rodada!\n");

        if (defensor->tropas == 1) {
            // defensor perde território
            printf(">> O território %s foi CONQUISTADO pelo exército %s!\n",
                   defensor->nome, atacante->cor);

            strcpy(defensor->cor, atacante->cor);
            defensor->tropas = 1;      // defensor fica com 1 tropa do vencedor
            atacante->tropas -= 1;     // atacante envia 1 tropa para ocupar
        } else {
            defensor->tropas -= 1;     // defensor perde 1 tropa
        }
    } else if (dadoDefensor > dadoAtacante) {
        printf(">> O defensor venceu a rodada!\n");

        if (atacante->tropas == 1) {
            // atacante perde território
            printf(">> O território %s foi CONQUISTADO pelo exército %s!\n",
                   atacante->nome, defensor->cor);

            strcpy(atacante->cor, defensor->cor);
            atacante->tropas = 1;      // atacante fica com 1 tropa do vencedor
            defensor->tropas -= 1;     // defensor envia 1 tropa para ocupar
        } else {
            atacante->tropas -= 1;     // atacante perde 1 tropa
        }
    } else {
        printf(">> Empate! Ninguém perde tropas nesta rodada.\n");
    }
}

// Libera memória alocada
void liberarMemoria(struct Territorio* mapa) {
    free(mapa);
    printf("\nMemória liberada com sucesso!\n");
}

// Função principal
int main() {
    srand(time(NULL)); // inicializa números aleatórios

    int totalTerritorios;
    printf("Digite o número total de territórios: ");
    scanf("%d", &totalTerritorios);
    limparBufferEntrada();

    // Alocação dinâmica
    struct Territorio* mapa = (struct Territorio*) calloc(totalTerritorios, sizeof(struct Territorio));
    if (mapa == NULL) {
        printf("Erro ao alocar memória!\n");
        return 1;
    }

    // Cadastro dos territórios
    printf("\n====================================\n");
    printf("        CADASTRO DE TERRITÓRIOS\n");
    printf("====================================\n\n");

    for (int i = 0; i < totalTerritorios; i++) {
        printf("--- Cadastro do Território %d ---\n", i + 1);

        printf("Digite o nome do Território: ");
        fgets(mapa[i].nome, sizeof(mapa[i].nome), stdin);
        mapa[i].nome[strcspn(mapa[i].nome, "\n")] = '\0';

        printf("Digite a cor do Exército: ");
        fgets(mapa[i].cor, sizeof(mapa[i].cor), stdin);
        mapa[i].cor[strcspn(mapa[i].cor, "\n")] = '\0';

        printf("Digite o número de Tropas: ");
        scanf("%d", &mapa[i].tropas);
        limparBufferEntrada();

        printf("\n");
    }

    // Menu principal
    int opcao;
    do {
        printf("\n====================================\n");
        printf("               MENU\n");
        printf("====================================\n");
        printf("1 - Exibir Mapa\n");
        printf("2 - Atacar\n");
        printf("0 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        limparBufferEntrada();

        switch (opcao) {
            case 1:
                exibirMapa(mapa, totalTerritorios);
                break;

            case 2: {
                exibirMapa(mapa, totalTerritorios);
                int atq, def;

                printf("\nDigite o número do território ATACANTE: ");
                scanf("%d", &atq);
                printf("Digite o número do território DEFENSOR: ");
                scanf("%d", &def);
                limparBufferEntrada();

                if (atq < 1 || atq > totalTerritorios ||
                    def < 1 || def > totalTerritorios ||
                    atq == def) {
                    printf("\n[ERRO] Territórios inválidos!\n");
                } else {
                    atacar(&mapa[atq - 1], &mapa[def - 1]);
                }
                break;
            }

            case 0:
                printf("\nSaindo do jogo...\n");
                break;

            default:
                printf("\nOpção inválida!\n");
        }
    } while (opcao != 0);

    liberarMemoria(mapa);
    return 0;
}
