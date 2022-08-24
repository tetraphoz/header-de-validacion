#include "val.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  char flotante[20] = {};
  int continuar = 0;

  do {
    printf("Ingresa un float para validar: ");

    // Usamos fgets porque gets es obsolescente
    fgets(flotante, 20, stdin); 
    // fgets a diferencia de gets incluye un '\n' al final de la linea 
    flotante[strcspn(flotante, "\r\n")] = 0; // Sustituimos el '\n' por un '\0'

    if(es_float(flotante)){
      char *end;
      // strtof es una funcion estandard para convertir cadenas a floats
      printf("El valor convertido a float es: %f\n", strtof(flotante, &end));
    } else {
        printf("No se puede convertir a float.\n");
    }

    printf("Desea continuar? (0=no/1=si): ");
    scanf("%d", &continuar);
    int c;
    // Descartamos valores que scanf deja como sobrante
    while ((c = getchar()) != EOF && c != '\n')
      ; 
  } while (continuar);

  return 0;
}
