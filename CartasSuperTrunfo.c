#include <stdio.h>
#include <string.h>

typedef struct {
    char estado[50];
    char codigocard[50];
    char cidade[50];
    int populacao;
    float area;
    float pib;
    int pontos_turistico;
    float densidade_populacional;
    float pib_per_capita;
} Carta;

int main () {
    int n;
    printf("Quantas cartas deseja cadastrar? ");
    scanf("%d", &n);
    getchar(); // Limpa o buffer do teclado

    Carta cartas[n];

    // Cadastro das cartas
    for (int i = 0; i < n; i++) {
        printf("\n--- Carta %d ---\n", i+1);

        printf("Digite o estado: \n");
        fgets(cartas[i].estado, sizeof(cartas[i].estado), stdin);
        cartas[i].estado[strcspn(cartas[i].estado, "\n")] = 0;

        printf("Digite o codigo da carta: \n");
        fgets(cartas[i].codigocard, sizeof(cartas[i].codigocard), stdin);
        cartas[i].codigocard[strcspn(cartas[i].codigocard, "\n")] = 0;

        printf("Digite o nome da cidade: \n");
        fgets(cartas[i].cidade, sizeof(cartas[i].cidade), stdin);
        cartas[i].cidade[strcspn(cartas[i].cidade, "\n")] = 0;

        printf("Digite a população: \n");
        scanf("%d", &cartas[i].populacao);

        printf("Digite a área: \n");
        scanf("%f", &cartas[i].area);

        printf("Digite o PIB: \n");
        scanf("%f", &cartas[i].pib);

        printf("Digite o número de pontos turísticos: \n");
        scanf("%d", &cartas[i].pontos_turistico);

        cartas[i].densidade_populacional = (float)cartas[i].populacao / cartas[i].area;
        cartas[i].pib_per_capita = (float)cartas[i].pib * 1000000000.0 / cartas[i].populacao;

        getchar(); // Limpa o buffer para a próxima carta
    }

    // Impressão das cartas cadastradas
    printf("\n=== Fichas das Cartas ===\n");
    for (int i = 0; i < n; i++) {
        printf("\nCarta %d:\n", i+1);
        printf("Estado: %s\n", cartas[i].estado);
        printf("Código: %s\n", cartas[i].codigocard);
        printf("Cidade: %s\n", cartas[i].cidade);
        printf("População: %d\n", cartas[i].populacao);
        printf("Área: %.2f km²\n", cartas[i].area);
        printf("PIB: %.2f bilhões de reais\n", cartas[i].pib);
        printf("Número de pontos turísticos: %d\n", cartas[i].pontos_turistico);
        printf("Densidade populacional: %.2f hab/km²\n", cartas[i].densidade_populacional);
        printf("PIB per Capita: %.2f reais\n", cartas[i].pib_per_capita);
    }

    return 0;
}