#ifndef UTILS
#define UTILS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>



void print_mat(float** mat, size_t row, size_t col) {

    for (size_t i=0; i<col; i++) {
        for (size_t j=0; j<row; j++) {
            printf("%f ", mat[i][j]);
        }
        printf("\n");
    }


}





void print_arr(float* arr, size_t size) {
    
    for(size_t i = 0; i < size; i++) {
        printf("%f ", arr[i]);
    }

}

float random_float() {
    float r = (float)rand()/(float)RAND_MAX;
    // printf("%f", r);
    return r;
}

int max_num(int* arr, size_t len) {
    // int len = sizeof(arr)/sizeof(arr[0]);
    int br = arr[0];
    for (size_t i=0; i < len; i++) {
        if (br < arr[i]) {
            br = arr[i];
        }
    }
    return br;
}


#endif
