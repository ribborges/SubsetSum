/*
    Pontificia universidade católica de minas gerais
    Projeto e Analise de Algoritmos

    Richard de Carvalho Borges

    Solucao recursiva
*/

#include <stdio.h>
 
// Retorna 1 se existe um subset
int isSubsetSum(int set[], int n, int sum){
    if (sum == 0)
        return 1;
    if (n == 0)
        return 0;
 
    // Ultimo elemento > sum
    if (set[n - 1] > sum)
        return isSubsetSum(set, n - 1, sum);
 
    return isSubsetSum(set, n - 1, sum) || isSubsetSum(set, n - 1, sum - set[n - 1]);
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