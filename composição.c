#include <stdio.h>


int id_exists(int id_array[], int size, int id) {
    for (int i = 0; i < size; i++) {
        if (id_array[i] == id) {
            return 1;
        }
    }
    return 0;
}

int main() {
    int qtd_produtos;

    printf("\nInforme a quantidade de itens que deseja inserir: ");
    scanf("%i", &qtd_produtos);

    char nome[qtd_produtos][20];
    int id[qtd_produtos], qtde[qtd_produtos];
    float unit[qtd_produtos], total[qtd_produtos];

    for (int i = 0; i < qtd_produtos; i++) {
        do {
            printf("Insira o ID do %dº produto: ", i + 1);
            scanf("%d", &id[i]);

            if (id[i] == 0) {
                printf("ID não pode ser 0! Por favor, insira um ID válido.\n");
            } else if (id_exists(id, i, id[i])) {
                printf("ID já existe! Por favor, insira um ID único.\n");
            }
        } while (id[i] == 0 || id_exists(id, i, id[i]));

        printf("Informe o nome do produto %d: ", i + 1);
        scanf("%s", nome[i]);

        printf("Informe a quantidade do produto %d: ", i + 1);
        scanf("%d", &qtde[i]);

        printf("Informe o preço unitário do produto %d: ", i + 1);
        scanf("%f", &unit[i]);

        total[i] = qtde[i] * unit[i];
    }
    
    float totalFinal = 0;

   printf("\n%-10s %-20s %-6s %-7s %-7s\n", "CODIGO", "NOME", "QTDE", "UNIT", "TOTAL");
    printf("-------------------------------------------------------------\n");

    for(int i = 0; i < qtd_produtos; i++){
        printf("%-10d %-20s %-6d %-7.2f %-7.2f\n", id[i], nome[i], qtde[i], unit[i], total[i]);
        totalFinal += total[i];
    }

    printf("-------------------------------------------------------------\n");
    printf("%51s %.2f\n", "TOTAL FINAL", totalFinal);

    return 0;
}
