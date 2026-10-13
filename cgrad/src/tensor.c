#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include "tensor.h"

Tensor CGTensorZeros(int dim, ...) {
  Tensor t;
  va_list args;
  size_t total = 1;
  int i;

  t.shape = NULL;
  t.data = NULL;

  if (dim <= 0) {
    printf("Please provide the dimension of the tensor.");
    return t;
  }

  t.shape = malloc((size_t)dim * sizeof(int));
  if (t.shape == NULL) {
    return t;
  }

  va_start(args, dim);
  for (i = 0; i < dim; i++) {
    t.shape[i] = va_arg(args, int);
    total *= (size_t)t.shape[i];
  }
  va_end(args);

  t.data = calloc(total, sizeof(double));
  return t;
}
