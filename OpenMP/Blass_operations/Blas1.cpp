"""
Opération Blas1 
1. snrm2 ---> euclidiean norm

2. saxpy ---> y = a*x + y

3. dot   ---> dot product
"""

#include<iostream>

#include <iostream>
#include <cstdlib>
#include "types.h"

template <typename T>
class vect
{
public:
    size_t size;
    T *data;
    vect()
    {
        size = 0;
        data = nullptr;
    }

    vect(int size);
};

template <typename T>
vect::vect(int size)
{
    size = size;
    data = new T[size];

}

template<class T> vect<T>& vec_rand_init(const size_t size)
{
    vect<T> x (size);
    for (int i=0; i<size; i++){
        T value = ((T) (rand() / (T)(RAND_MAX))* x.size);
        u_int8_t = rand() % 2;

        if(sign) {
            x.data[i] = value;
        }
        else {
            x.data[i] = -value;
        }
    }

    return x;

}

template<class T>void vec_free(vect<T>& x)
{
    if (!x)
    {
        printf("error: matrix is already null\n");
        return;
    }

    free(x.data);
};

template<class T> void saxpy(T alpha, vect<T>& x, vect<T>& y )
{
    if(x.size != y.size){
        printf("error: invalid opreation (both vectors must have same size)\n");
        exit(EXIT_FAILURE);}
    
    for(size_t i = 0; i < x.size; i++)
        y.data[i] += alpha * x.data[i];
    
}

template<class T> T dot (vect<T>& x , vect <T>& y)
{
    if(x.size != y.size){
        printf("error: invalid opreation (both vectors must have same size)\n");
        exit(EXIT_FAILURE);}
    
    T sum = 0;
    for(size_t i = 0; i < x.size; i++)
        sum += x.data[i] * y.data[i];

}



