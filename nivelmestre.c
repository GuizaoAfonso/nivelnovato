#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Estrutura do Território
struct Territorio {
    char nome[30];
    char cor[10];
    int tropas;
};

// Função para limpar buffer
void limparBufferEntrada() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Exibe o mapa do mundo
void exibirMapa(struct Territorio* mapa, int total) {
    printf("============ MAPA DO MUNDO ==========\n");
    for (int i = 0; i < total; i++) {
        printf("%d. %-10s (Exercito: %-7s , Tropas: %d)\n",
               i + 1, mapa[i].nome, mapa[i].cor, mapa[i].tropas);
    }
    printf("=====================================\n");
}

// Função para atribuir uma missão aleatória
void atribuirMissao(char* destino, char* missoes[], int totalMissoes) {
    int sorteio = rand() % totalMissoes;
    strcpy(destino, missoes[sorteio]);
}

// Exibe a missão
void exibirMissao(char* missao, char* exercito) {
    printf("\n--- SUA MISSAO (Exercito %s) ---\n", exercito);
    printf("%s\n", missao);
}

// Verifica missão (simplificado)
int verificarMissao(char* missao, struct Territorio* mapa, int total) {
    // Exemplo básico: "Destruir o exercito Verde"
    if (strstr(missao, "Verde") != NULL) {
        for (int i = 0; i < total; i++) {
            if (strcmp(mapa[i].cor, "Verde") == 0) {
                return 0; // ainda existe o exército Verde
            }
        }
        return 1; // cumpriu missão
    }
    return 0;
}

// Função de ataque
void atacar(struct Territorio* atacante, struct Territorio* defensor) {
    if (strcmp(atacante->cor, defensor->cor) == 0) {
        printf("\n[ERRO] Não pode atacar seu próprio exército!\n");
        return;
    }

    printf("\n>>> BATALHA: %s (%s) ATACANDO %s (%s)\n",
           atacante->nome, atacante->cor, defensor->nome, defensor->cor);

    int dadoAtq = (rand() % 6) + 1;
    int dadoDef = (rand() % 6) + 1;

    printf("Dado Atacante: %d | Dado Defensor: %d\n", dadoAtq, dadoDef);

    if (dadoAtq > dadoDef) {
        printf(">> O atacante venceu!\n");
        if (defensor->tropas == 1) {
            printf(">> Território %s CONQUISTADO!\n", defensor->nome);

            // troca a cor para a do atacante
            strcpy(defensor->cor, atacante->cor);

            // metade das tropas do atacante vão ocupar
            int tropasTransferidas = atacante->tropas / 2;
            if (tropasTransferidas < 1) tropasTransferidas = 1;

            defensor->tropas = tropasTransferidas;
            atacante->tropas -= tropasTransferidas;
        } else {
            defensor->tropas--;
        }
    } 
    else if (dadoDef > dadoAtq) {
        printf(">> O defensor venceu!\n");
        if (atacante->tropas == 1) {
            printf(">> Território %s CONQUISTADO!\n", atacante->nome);

            // troca a cor para a do defensor
            strcpy(atacante->cor, defensor->cor);

            // metade das tropas do defensor vão ocupar
            int tropasTransferidas = defensor->tropas / 2;
            if (tropasTransferidas < 1) tropasTransferidas = 1;

            atacante->tropas = tropasTransferidas;
            defensor->tropas -= tropasTransferidas;
        } else {
            atacante->tropas--;
        }
    } 
    else {
        printf(">> Empate! Ninguém perde tropas.\n");
    }
}


// Libera memória
void liberarMemoria(struct Territorio* mapa, char* missao) {
    free(mapa);
    free(missao);
}

int main() {
    srand(time(NULL));

    int totalTerritorios = 5;

    // Pré-cadastro dos territórios
    struct Territorio* mapa = (struct Territorio*) calloc(totalTerritorios, sizeof(struct Territorio));

    strcpy(mapa[0].nome, "America"); strcpy(mapa[0].cor, "Verde"); mapa[0].tropas = 5;
    strcpy(mapa[1].nome, "Europa"); strcpy(mapa[1].cor, "Azul"); mapa[1].tropas = 3;
    strcpy(mapa[2].nome, "Asia"); strcpy(mapa[2].cor, "Vermelho"); mapa[2].tropas = 2;
    strcpy(mapa[3].nome, "Africa"); strcpy(mapa[3].cor, "Amarelo"); mapa[3].tropas = 4;
    strcpy(mapa[4].nome, "Oceania"); strcpy(mapa[4].cor, "Branco"); mapa[4].tropas = 1;

    // Missões possíveis
    char* missoes[] = {
        "Destruir o exercito Verde.",
        "Conquistar 3 territorios seguidos.",
        "Eliminar todas as tropas Vermelhas.",
        "Controlar America e Europa.",
        "Ser o ultimo exercito restante."
    };

    // Sorteio da missão
    char* missao = (char*) malloc(100 * sizeof(char));
    atribuirMissao(missao, missoes, 5);

    // Exibe tela inicial
    exibirMapa(mapa, totalTerritorios);
    exibirMissao(missao, "Azul");

    // Menu principal
    int opcao;
    do {
        printf("\n--- MENU DE ACOES ---\n");
        printf("1 - Atacar\n");
        printf("2 - Verificar Missao\n");
        printf("0 - Sair\n");
        printf("Escolha sua acao: ");
        scanf("%d", &opcao);
        limparBufferEntrada();

        switch (opcao) {
            case 1: {
                exibirMapa(mapa, totalTerritorios);
                int atq, def;
                printf("Território atacante: ");
                scanf("%d", &atq);
                printf("Território defensor: ");
                scanf("%d", &def);
                limparBufferEntrada();

                if (atq < 1 || atq > totalTerritorios ||
                    def < 1 || def > totalTerritorios || atq == def) {
                    printf("\n[ERRO] Territórios inválidos!\n");
                } else {
                    atacar(&mapa[atq - 1], &mapa[def - 1]);
                }

                if (verificarMissao(missao, mapa, totalTerritorios)) {
                    printf("\n>>> MISSAO CUMPRIDA! Você venceu o jogo!\n");
                    opcao = 0;
                }
                break;
            }
            case 2:
                exibirMissao(missao, "Azul");
                break;
            case 0:
                printf("\nSaindo...\n");
                break;
            default:
                printf("\nOpção inválida!\n");
        }
    } while (opcao != 0);

    liberarMemoria(mapa, missao);
    return 0;
}