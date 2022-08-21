#ifndef VAL_H_
#define VAL_H_

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

/* Validacion de enteros y flotantes usando como base los programas del
   profesor. */

bool es_int(char *entero);
bool es_float(char *entero);

bool es_int(char *entero) {
  int len = strlen(entero);
  if (len == 0)
    return false;

  for (int i = 0; i < len; i++) {
    if (!isdigit(entero[i]))
      return false;
  }

  return true;
}

bool es_float(char *flotante) {
  int len = strlen(flotante);
  if (len == 0)
    return false;

  int canPunto = 0;
  int canGuiones = 0;

  for (int i = 0; i < len; i++) {
    if (isdigit(flotante[i]) || flotante[i] == '.' || flotante[i] == '-') {
      if (flotante[i] == 46)
        canPunto++; // 46 == '.'
      if (flotante[i] == '-')
        canGuiones++;
    } else
      return false;
  }

  if (canPunto > 1 || canGuiones > 1)
    return false;

  // Solo permitir signo negativo al inicio
  if(canGuiones == 1 && flotante[0] != '-')
    return false;

  return true;
}

#endif // VAL_H_
