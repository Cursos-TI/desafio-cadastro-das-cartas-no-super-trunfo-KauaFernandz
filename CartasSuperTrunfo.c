#include <stdio.h>
#include <string.h>

int main() {

    char estado[50];
    char codigocard[50];
    char cidade[50];
    int populacao;
    float area;
    float pib;
    int pontos_turistico;


    printf("Digite o estado: \n");
    fgets(estado, sizeof(estado), stdin);
    estado[strcspn(estado, "\n")] = 0;

    printf("Digite o codigo da carta: \n");
    scanf ("%s", codigocard);

    printf("Digite o nome da cidade: \n");
    getchar ();
    fgets(cidade, sizeof(cidade), stdin);
    cidade[strcspn(cidade, "\n")] = 0;

    printf("Digite a população: \n");
    scanf("%d", &populacao);

    printf("Digite a área: \n");
    scanf("%f", &area);

    printf("Digite o PIB: \n");
    scanf("%f", &pib);

    printf("Digite o número de pontos turísticos: \n");
    scanf("%d", &pontos_turistico);

    printf("\n=== Ficha da Carta===\n");
    printf("Estado: %s\n", estado);
    printf("Código: %s\n", codigocard);
    printf("Cidade: %s\n", cidade);
    printf("População: %d\n", populacao);
    printf("Área: %.2f\n", area);
    printf("PIB: %.2f\n", pib);
    printf("Número de pontos turísticos: %d\n", pontos_turistico);



    return 0;
}
