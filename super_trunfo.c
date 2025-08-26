#include <stdio.h>
#include <string.h>

typedef struct {
    char estado[50];
    char codigocard[50];
    char cidade[50];
    unsigned long int populacao;
    float area;
    float pib;
    int pontos_turistico;
    float densidade_populacional;
    float pib_per_capita;
    float super_poder;
} Carta;

void comparar_atributo(const char* nome, float valor1, float valor2, int menor_vence) {
    printf("%s: ", nome);
    if (valor1 == valor2) {
        printf("Empate (%.2f vs %.2f)\n", valor1, valor2);
    } else if ((menor_vence && valor1 < valor2) || (!menor_vence && valor1 > valor2)) {
        printf("Carta 1 vence (%.2f vs %.2f)\n", valor1, valor2);
    } else {
        printf("Carta 2 vence (%.2f vs %.2f)\n", valor1, valor2);
    }
}

int main () {
    const int n = 2;
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
        scanf("%lu", &cartas[i].populacao);

        printf("Digite a área: \n");
        scanf("%f", &cartas[i].area);

        printf("Digite o PIB: \n");
        scanf("%f", &cartas[i].pib);

        printf("Digite o número de pontos turísticos: \n");
        scanf("%d", &cartas[i].pontos_turistico);

        cartas[i].densidade_populacional = (float)cartas[i].populacao / cartas[i].area;
        cartas[i].pib_per_capita = (float)cartas[i].pib * 1000000000.0 / cartas[i].populacao;

        float inverso_densidade = (cartas[i].densidade_populacional > 0) ? 1.0/cartas[i].densidade_populacional : 0;
        cartas[i].super_poder = cartas[i].populacao + cartas[i].area + cartas[i].pib + cartas[i].pontos_turistico +
                               cartas[i].pib_per_capita + inverso_densidade;

        getchar(); // Limpa o buffer para a próxima carta
    }

    // Impressão das cartas cadastradas
    printf("\n=== Fichas das Cartas ===\n");
    for (int i = 0; i < n; i++) {
        printf("\nCarta %d:\n", i+1);
        printf("Estado: %s\n", cartas[i].estado);
        printf("Código: %s\n", cartas[i].codigocard);
        printf("Cidade: %s\n", cartas[i].cidade);
        printf("População: %lu\n", cartas[i].populacao);
        printf("Área: %.2f km²\n", cartas[i].area);
        printf("PIB: %.2f bilhões de reais\n", cartas[i].pib);
        printf("Número de pontos turísticos: %d\n", cartas[i].pontos_turistico);
        printf("Densidade populacional: %.2f hab/km²\n", cartas[i].densidade_populacional);
        printf("PIB per Capita: %.2f reais\n", cartas[i].pib_per_capita);
        printf("Super Poder: %.2f\n", cartas[i].super_poder);
    }

    // Comparação dos atributos
    printf("\n=== Comparação das Cartas ===\n");
    comparar_atributo("População", (float)cartas[0].populacao, (float)cartas[1].populacao, 0);
    comparar_atributo("Área", cartas[0].area, cartas[1].area, 0);
    comparar_atributo("PIB", cartas[0].pib, cartas[1].pib, 0);
    comparar_atributo("Pontos Turísticos", (float)cartas[0].pontos_turistico, (float)cartas[1].pontos_turistico, 0);
    comparar_atributo("PIB per Capita", cartas[0].pib_per_capita, cartas[1].pib_per_capita, 0);
    comparar_atributo("Densidade Populacional", cartas[0].densidade_populacional, cartas[1].densidade_populacional, 1);
    comparar_atributo("Super Poder", cartas[0].super_poder, cartas[1].super_poder, 0);

    return 0;
}
