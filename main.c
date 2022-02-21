#include <stdio.h>

void ordem(int a, int b)
{
  if (a > b) {
    printf( "\n%d, %d\n", b, a);
  }
  else {
    printf( "\n%d, %d\n", a, b);
  }
}

int main() {
    int valor1, valor2;
    printf ("Insira o primeiro numero ");
    scanf("%d", &valor1);
    printf("Insira o segundo numero ");
    scanf("%d", &valor2);
    printf("A ordem crescente eh:");
    
    ordem(valor1, valor2);
    return 0;
}