#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "tensor.h"

void test_zeros_data() {
  Tensor t = CGTensorZeros(2, 2, 3);

  assert(t.shape != NULL);
  assert(t.shape[0] == 2);
  assert(t.shape[1] == 3);

  assert(t.data != NULL);
  for (int i = 0; i < 6; i++) {
    assert(t.data[i] == 0.0);
  }

  printf("<shape={%d,%d},all data == 0.0>\n",t.shape[0], t.shape[1]);

  free(t.shape);
  free(t.data);
}

int main(void) {
  test_zeros_data();
  return 0;
}