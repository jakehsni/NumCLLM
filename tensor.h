#include <stdlib.h>
#include <stdio.h>

#include <stdio.h>
#include <stdlib.h>

#define Tensor_malloc malloc
#define PyArray_free free







enum TYPES{
    TSHORT, TINT, TLONG, TFLOAT, TDOUBLE
};

typedef  struct{

    /* Pointer to the raw data buffer */
char * data;
    /* The size in each dimension, also called 'shape' */
int* dimension;

 /*
     * Number of bytes to jump to get to the
     * next element in each dimension
     */

int* strides;
int ndim;
int size;
        /* element size (itemsize) for this type */
int elementsize;
        /* alignment needed for this type */
int alignment;


} tensor;


void load_file(char * path);

tensor* create_teanor(char * buffer);





