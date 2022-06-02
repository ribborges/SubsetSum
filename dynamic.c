/*
    Pontificia universidade católica de minas gerais
    Projeto e Analise de Algoritmos

    Richard de Carvalho Borges

    Solucao programacao dinamica
*/
#include <stdio.h>
 
// Retorna 1 se existe um subset
int isSubsetSum(int set[], int n, int sum){
    int subset[n + 1][sum + 1];
 
    // sum igual a 0 - verdadeiro (1)
    for (int i = 0; i <= n; i++)
        subset[i][0] = 1;
 
    // sum diferente de 0 - set vazio - falso (0)
    for (int i = 1; i <= sum; i++)
        subset[0][i] = 0;

    // Preenche tabela subset com bottom-up
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++){
            if (j < set[i - 1])
                subset[i][j] = subset[i - 1][j];
            if (j >= set[i - 1])
                subset[i][j] = subset[i - 1][j] || subset[i - 1][j - set[i - 1]];
        }
    }
 
    // Printa tabela
    for (int i = 0; i <= n; i++){
        for (int j = 0; j <= sum; j++){
            printf ("%4d \n", subset[i][j]);
        }
    }
 
    return subset[n][sum];
}

int main(){
    int sum = 0;
    int index;

    printf("Digite a quantidade de index para o set: ");
    scanf("%d", &index);

    int set[index];

    for(int i = 0; i < index; i++){
        printf("Digite o valor para o indice %d do set: ", i);
        scanf("%d", &set[i]);
    }

    int n = sizeof(set) / sizeof(set[0]);

    printf("Digite o sum: ");
    scanf("%d", &sum);

    if (isSubsetSum(set, n, sum) == 1)
        printf("Encontrado");

    else
        printf("Nao encontrado");

    return 0;
}