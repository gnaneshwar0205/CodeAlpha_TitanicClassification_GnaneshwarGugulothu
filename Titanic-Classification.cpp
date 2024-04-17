#include <iostream>
#include <cmath>
using namespace std;
#define NUM_SAMPLES 5
#define NUM_FEATURES 3
float data[NUM_SAMPLES][NUM_FEATURES] = {
    {0.8, 35, 1}, 
    {0.6, 45, 0},  
    {0.3, 28, 1},  
    {0.9, 55, 0}, 
    {0.5, 40, 0}   
};
int target[NUM_SAMPLES] = {1, 0, 1, 0, 0};
float coefficients[NUM_FEATURES] = {0.5, -0.01, 0.3};
float sigmoid(float x) {
    return 1 / (1 + exp(-x));
}
int predict(float features[NUM_FEATURES]) {
    float z = 0;
    for (int i = 0; i < NUM_FEATURES; i++) {
        z += coefficients[i] * features[i];
    }
    float probability = sigmoid(z);
    return (probability >= 0.5) ? 1 : 0;
}

int main() {
    for (int i = 0; i < NUM_SAMPLES; i++) {
        int prediction = predict(data[i]);
        cout<<"Sample "<<i+1<<": Predicted="<<prediction<<", Actual="<<target[i]<<endl;
    }
    return 0;
}


