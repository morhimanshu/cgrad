#ifndef TENSOR_H
#define TENSOR_H

typedef struct Tensor {
  int *shape;
  double *data;
} Tensor;

Tensor CGTensorZeros(int count, ...);

#endif /* TENSOR_H */