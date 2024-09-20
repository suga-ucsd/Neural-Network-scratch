#include <stdio.h>
#include <stdlib.h>
#include "nn.h"
#include "utils.h"
#include <time.h>


Layer* init_layer(size_t in_size, size_t out_size) {
    srand(time(NULL));

    Layer* l = malloc(sizeof(Layer));
        
    l->weights = malloc(in_size * sizeof(float));
    if (l->weights == NULL) {
        fprintf(stderr, "Failed to allocate l");
        free(l);
        exit(0);
    }
    
    for(size_t i=0; i < in_size; i++) {

        l->weights[i] = malloc(out_size * sizeof(float));

        if (l->weights[i] == NULL) {
            fprintf(stderr, "Failed to allocate l weights i");
            
            for (size_t j=0; j< i ; j++) {
                free(l->weights[j]);   
            }
             
            free(l->weights);
            free(l);
            exit(0);
        }

        for(size_t j=0; j < out_size; j++) {
            srand(rand());
            l->weights[i][j] = random_float();
        }
    }
    
    
    l->bias = malloc(out_size * sizeof(float));
    
    if (l->bias == NULL) {
        free(l);
        exit(0);
    }

    for(size_t i=0; i < out_size; i++) {
        l->bias[i] = random_float();
    }

    return l;
}



float** forward(NeuralNetwork* nn, float* input) {
    
    size_t arr_len = nn->arr_num;
    
    float** outputs;

    outputs = malloc(arr_len * sizeof(float));
    int max_len = max_num(nn->layer_arr, arr_len);
    outputs[0] = malloc(max_len * sizeof(float));

    for (size_t i=0; i < arr_len - 1; i++) {

        size_t inp = nn->layer_arr[i];
        size_t out = nn->layer_arr[i+1];
        Layer* l = init_layer(inp, out);
        outputs[i + 1] = malloc(max_len * sizeof(float));
    
        if ( i == 0 ) {
            for (size_t br = 0; br < inp; br++) {
                outputs[i][br] = input[br];
            }
        }
        
        for (size_t j = 0; j < out; j++) {
            for (size_t k = 0; k < inp; k++) {
                outputs[i+1][j] += outputs[i][k] * l->weights[k][j];
            }
        }
        for (size_t j = 0; j < out; j++) {
            outputs[i+1][j] += l->bias[j];
        }
    } 
    return outputs;
}



int main(int argc, char **argv) {

    NeuralNetwork* nn = malloc(sizeof(NeuralNetwork));
    nn->arr_num = 3;
    int layers[3] = {3, 2, 2};
    nn->layer_arr = malloc(nn->arr_num * sizeof(int));
    nn->layer_arr = layers;
        
    float inp[3] = {1.0, 2.0, 3.0};
    float** outputs = forward(nn, inp);
    
    
    print_mat(outputs, 3, 3);

    
    
    return 0;
}



