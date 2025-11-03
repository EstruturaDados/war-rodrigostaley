// ============================================================================
//         PROJETO WAR ESTRUTURADO - DESAFIO DE CÓDIGO
// ============================================================================
//        
// ============================================================================
//
// OBJETIVOS:
// - Modularizar completamente o código em funções especializadas.
// - Implementar um sistema de missões para um jogador.
// - Criar uma função para verificar se a missão foi cumprida.
// - Utilizar passagem por referência (ponteiros) para modificar dados e
//   passagem por valor/referência constante (const) para apenas ler.
// - Foco em: Design de software, modularização, const correctness, lógica de jogo.
//
// ============================================================================

// Inclusão das bibliotecas padrão necessárias para entrada/saída, alocação de memória, manipulação de strings e tempo.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <locale.h>  // Para usar acentuação


// --- Constantes Globais ---
// Definem valores fixos para o número de territórios, missões e tamanho máximo de strings, facilitando a manutenção.
#define NUM_TERRITORIOS 5

// Definição da Estrutura (Struct)
// Requisitos funcional => Criação da struct: definir uma struct chamada Territorio com os campos char nome[30], char cor[10] e int tropas.
struct Territorio{
    char nome[30];
    char cor[10];
    int tropas;
};
// Cadastro dos territórios
// Requisitos funcional => O sistema deve permitir que o usuário cadastre cinco territórios informando o nome, cor do exército e o número de tropas de cada um.

int main() {
    
    setlocale(LC_ALL, "Portuguese");  // Configura acentuação para Português
    struct Territorio territorios[NUM_TERRITORIOS]; //Declaração de vetor de struct Territorio

    printf("-------------------------------------------------\n");
    printf(" <+> Cadastro Inicial de 5 Territórios - War  <+> \n");
    printf("-------------------------------------------------\n\n");

    // Cadastro dos territórios
    for (int i = 0; i < NUM_TERRITORIOS; i++) {
        printf("Cadastro do Território %d:\n", i + 1);

        printf("Nome do Território: ");
        fgets(territorios[i].nome, sizeof(territorios[i].nome), stdin);
        territorios[i].nome[strcspn(territorios[i].nome, "\n")] = 0; // Remove o newline

        printf("Cor do Exército: ");
        fgets(territorios[i].cor, sizeof(territorios[i].cor), stdin);
        territorios[i].cor[strcspn(territorios[i].cor, "\n")] = 0; // Remove o newline

        printf("Número de Tropas: ");
        scanf("%d", &territorios[i].tropas);
        while(getchar() != '\n'); // Limpa o buffer de entrada

        printf("\n");
    }

    // Exibição dos territórios cadastrados
    // Requisito funcional => Exibir as informações de todos os territórios cadastrados.
    // Requisito técnico => O sistema deve apresentar os dados logo após o cadastro.
    printf("===================================\n");
    printf(" <++> Territórios Cadastrados <++> \n");
    printf("===================================\n\n");

    for (int i = 0; i < NUM_TERRITORIOS; i++) {
        printf("Território %d:\n", i + 1);
        printf("  > Nome: %s\n", territorios[i].nome);
        printf("  > Cor: %s\n", territorios[i].cor);
        printf("  > Tropas: %d\n\n", territorios[i].tropas);
    }

    return 0;
}

