#include "tensor.h"
#include <math.h>

void load_file(char * path){

FILE *f;
f = fopen(path);

long size;
fseek(f, 0, SEEK_END); // move file pointer to end of file
size = ftell(f); // get the file size, in bytes
fclose(f);
char * buffer = (char *) malloc(sizeof(char) * size);

printf("size of the file is %lu byte\n", size);

f =fopen(path, "rb");
fread(buffer, sizeof(char), size, f);

}


tensor* create_teanor(char * buffer){

int ndim = *((int*) buffer);
int size = *((int*) (buffer + sizeof(int)));
int elementsize = *((int*) (buffer + 2 *sizeof(int)));

int * dimensions = (buffer + 3 *sizeof(int));
int * strides = (buffer + 3 *sizeof(int) + ndim * sizeof(int));
char * begining_data = (buffer + 3 *sizeof(int) + 2 *ndim * sizeof(int));




char * data = malloc(size * elementsize *sizeof(char));


tensor * array = (tensor *) malloc(sizeof(tensor));

array{}






}
