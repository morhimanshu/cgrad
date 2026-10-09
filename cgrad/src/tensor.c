#include <stdio.h>
#include <stdarg.h>

typedef struct tensor{
    int size;
    double* data;

    Tensor *(*add)(Tensor *self, const Tensor *other, ...);
} Tensor;

Tensor *add(int count, Tensor *self, const Tensor *other, ...) {
    /*
    Need to pass the count of numbers to add. TODO: hack this
    */

    if (self->size != other->size){
        return NULL;
 
    int result; 

    va_list argv;
    va_start(argv, count);

    int argc = va_arg(argv, int);
    for(int i = 0; i < argc; i++){
        result += va_arg(argv, double);
    }

    vs_end(argv);

    if (self->size != other->size){
        return NULL;
    }

    return self;
}
