#include <stdio.h>

// Desafio Super Trunfo - Países
// Tema 2 - Comparação das Cartas
// Este código inicial serve como base para o desenvolvimento do sistema de comparação de cartas de cidades. 
// Siga os comentários para implementar cada parte do desafio.

#include <stdio.h>   // entrada/saída: printf e scanf

int main() {
    // --- Dados da primeira carta
    char estadoA[2];        // letra do estado ex: A
    char codigoA[4];        // código ex: A01
    char nomeA[50];         // nome da cidade
    int populacaoA;         // população
    float areaA;            // área (km²) (casas decimais_
    float pibA;             // PIB em bilhões (decimal)
    int pontosA;            // pontos turísticos

    // --- Dados da segunda carta
    char estadoB[2];
    char codigoB[4];
    char nomeB[50];
    int populacaoB;
    float areaB;
    float pibB;
    int pontosB;

    int opcao; // atributo para comparar

    // ----- Cadastro da carta A -----
    printf("Cadastro da Carta A (Cidade 1):\n");
    printf("Estado (A-H): ");
    scanf(" %1s", estadoA);              // lê 1 caracter (ignora espaços anterior)
    printf("Codigo (ex: A01): ");
    scanf("%3s", codigoA);               // lê no máx 3 caracteres
    printf("Nome da cidade: ");
    scanf(" %49[^\n]", nomeA);           // lê linha, até 49 caracteres
    printf("Populacao (inteiro): ");
    scanf("%d", &populacaoA);
    printf("Area (km2, decimal): ");
    scanf("%f", &areaA);
    printf("PIB (bilhoes, decimal): ");
    scanf("%f", &pibA);
    printf("Pontos turisticos (inteiro): ");
    scanf("%d", &pontosA);

    // ----- Cadastro da carta B -----
    printf("\nCadastro da Carta B (Cidade 2):\n");
    printf("Estado (A-H): ");
    scanf(" %1s", estadoB);
    printf("Codigo (ex: B01): ");
    scanf("%3s", codigoB);
    printf("Nome da cidade: ");
    scanf(" %49[^\n]", nomeB);
    printf("Populacao (inteiro): ");
    scanf("%d", &populacaoB);
    printf("Area (km2, decimal): ");
    scanf("%f", &areaB);
    printf("PIB (bilhoes, decimal): ");
    scanf("%f", &pibB);
    printf("Pontos turisticos (inteiro): ");
    scanf("%d", &pontosB);

    // ----- Dados cadastrados -----
    printf("\n--- Carta A ---\n");
    printf("Estado: %s\nCodigo: %s\nNome: %s\nPopulacao: %d\nArea: %.2f km2\nPIB: %.2f\nPontos: %d\n",
           estadoA, codigoA, nomeA, populacaoA, areaA, pibA, pontosA);

    printf("\n--- Carta B ---\n");
    printf("Estado: %s\nCodigo: %s\nNome: %s\nPopulacao: %d\nArea: %.2f km2\nPIB: %.2f\nPontos: %d\n",
           estadoB, codigoB, nomeB, populacaoB, areaB, pibB, pontosB);

    // ----- Atributo a comparar -----
    printf("\nEscolha o atributo para comparar:\n");
    printf("1 - Populacao (maior vence)\n");
    printf("2 - Area (maior vence)\n");
    printf("3 - PIB (maior vence)\n");
    printf("4 - Pontos turisticos (maior vence)\n");
    printf("5 - Densidade populacional (pop/area) (menor vence)\n");
    printf("Opcao: ");
    scanf("%d", &opcao);

    // ----- Comparações if/else -----
    if (opcao == 1) {
        // População: maior vence
        if (populacaoA > populacaoB) {
            printf("\nVencedora: Carta A (%s) - maior populacao.\n", nomeA);
        } else if (populacaoB > populacaoA) {
            printf("\nVencedora: Carta B (%s) - maior populacao.\n", nomeB);
        } else {
            printf("\nEmpate: mesmas populacoes.\n");
        }
    } else if (opcao == 2) {
        // Área: maior vence
        if (areaA > areaB) {
            printf("\nVencedora: Carta A (%s) - maior area.\n", nomeA);
        } else if (areaB > areaA) {
            printf("\nVencedora: Carta B (%s) - maior area.\n", nomeB);
        } else {
            printf("\nEmpate: mesmas areas.\n");
        }
    } else if (opcao == 3) {
        // PIB: maior vence
        if (pibA > pibB) {
            printf("\nVencedora: Carta A (%s) - maior PIB.\n", nomeA);
        } else if (pibB > pibA) {
            printf("\nVencedora: Carta B (%s) - maior PIB.\n", nomeB);
        } else {
            printf("\nEmpate: mesmos PIBs.\n");
        }
    } else if (opcao == 4) {
        // Pontos turísticos: maior vence
        if (pontosA > pontosB) {
            printf("\nVencedora: Carta A (%s) - mais pontos turisticos.\n", nomeA);
        } else if (pontosB > pontosA) {
            printf("\nVencedora: Carta B (%s) - mais pontos turisticos.\n", nomeB);
        } else {
            printf("\nEmpate: mesmos pontos turisticos.\n");
        }
    } else if (opcao == 5) {
        // Densidade = populacao / area
        if (areaA <= 0.0f || areaB <= 0.0f) {
            printf("\nErro: area invalida (zero ou negativa). Nao e possivel comparar densidade.\n");
        } else {
            float densA = (float)populacaoA / areaA;
            float densB = (float)populacaoB / areaB;
            // Menor densidade vence
            if (densA < densB) {
                printf("\nVencedora: Carta A (%s) - menor densidade (%.2f vs %.2f).\n", nomeA, densA, densB);
            } else if (densB < densA) {
                printf("\nVencedora: Carta B (%s) - menor densidade (%.2f vs %.2f).\n", nomeB, densB, densA);
            } else {
                printf("\nEmpate: mesmas densidades (%.2f).\n", densA);
            }
        }
    } else {
        // Se a opção não for válida
        printf("\nOpcao invalida. Nada a comparar.\n");
    }

    return 0;
}
