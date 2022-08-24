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

  if (len == 1)
    return isdigit(entero[0]);

  int i = 0;
  if (entero[0] == '-')
    i++;

  for (; i < len; i++) {
    if (!isdigit(entero[i]))
      return false;
  }

  return true;
}

bool es_float(char *flotante) {
  int len = strlen(flotante);
  if (len == 0)
    return false;

  if (len == 1)
    return isdigit(flotante[0]);

  int i = 0;

  if (flotante[0] == '-')
    i++;

  while (flotante[i] != '.' && i < len) {
    if (!isdigit(flotante[i++]))
      return false;
  }

  for (i++; i < len; i++) {
    if (!isdigit(flotante[i]))
      return false;
  }

  return true;
}

#endif // VAL_H_
