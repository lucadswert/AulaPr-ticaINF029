#include <stdio.h>

void calcularA(int *base, int altura){
  int area;
  area = *base*altura;
  printf("\nO valor da area é %d\n", area);
} 

int main() {
    
    int base, valor2;
    printf ("Insira o valor da base ");
    scanf("%d", &base);
    printf("Insira o valor da altura ");
    scanf("%d", &valor2);

    calcularA(&base, valor2);

    return 0;
}