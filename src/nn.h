#ifndef NN_
#define NN_

typedef struct {
    float** weights;
    float* bias;
} Layer;

typedef struct {
    int arr_num;
    int* layer_arr;
} NeuralNetwork;




#endif
