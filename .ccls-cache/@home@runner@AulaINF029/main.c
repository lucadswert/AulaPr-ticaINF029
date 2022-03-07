#include <stdio.h>

void calcuarA(int *base, int altura){
  int area = *base * *altura;
    printf("\nO valor da area é %d\n", area);
}

void alturaR (int *valor2){
    printf("O valor da altura é %d\n", *valor2);
}  
int main() {
  void baseR( );
  void alturaR( );
  void calcular;
  
    int valor1, valor2, area;
    printf ("Insira o valor da base ");
    scanf("%d", &valor1);
    printf("Insira o valor da altura ");
    scanf("%d", &valor2);

  calcuarA(&valor1);
   calcuarA(valor2);
  printf("A área é %d", area);  
    
  
    return 0;
}