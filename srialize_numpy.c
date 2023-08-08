#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>  
#include <numpy/arrayobject.h>
#include <stdio.h>


static PyObject *get_layout(PyObject * self, PyObject * args){
    PyArrayObject *arr;
    PyArg_ParseTuple(args, "O", &arr);
    if(PyErr_Occurred()){
        return NULL;
    }

  char * data = (char *)PyArray_DATA(arr);
  int ndim = PyArray_NDIM(arr);
  npy_intp* sizes = PyArray_DIMS(arr);
  npy_intp* strides = PyArray_STRIDES(arr);


double total = 0;



printf("size 1 is %ld \n", sizes[1]);
return PyFloat_FromDouble(total);

}

static PyObject *_save(PyObject * self, PyObject * args){
    PyArrayObject *arr;
    PyArg_ParseTuple(args, "O", &arr);
    if(PyErr_Occurred()){
        return NULL;
    }
double *data = PyArray_DATA(arr);
int64_t size = PyArray_SIZE(arr);
FILE *ptr;
ptr =fopen("string.bin", "wb");
fwrite(data, sizeof(double), size, ptr);
fclose(ptr);
double total = 0;



return PyFloat_FromDouble(total);

}

static PyMethodDef method_my[] = {
    {"save", _save, METH_VARARGS, "this fuction save underlying data of array to file"},
        {"get_layout", get_layout, METH_VARARGS, "this fuction save underlying data of array to file"},

    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef kamal = {   

PyModuleDef_HEAD_INIT,
"serialize",
"doc is my",
-1,
method_my
};

PyMODINIT_FUNC PyInit_serialize(){     

PyObject* module  =  PyModule_Create(&kamal) ;   
import_array();

return module;
}  



                                                  
