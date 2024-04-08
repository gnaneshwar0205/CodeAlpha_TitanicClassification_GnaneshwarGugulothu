#include <iostream>
#include <cmath>
using namespace std;
#define NUM_SAMPLES 5
#define NUM_FEATURES 3

// Sample data (economic status, age, gender)
float data[NUM_SAMPLES][NUM_FEATURES] = {
    {0.8, 35, 1},  // Economic status: 0.8, Age: 35, Gender: Male
    {0.6, 45, 0},  // Economic status: 0.6, Age: 45, Gender: Female
    {0.3, 28, 1},  // Economic status: 0.3, Age: 28, Gender: Male
    {0.9, 55, 0},  // Economic status: 0.9, Age: 55, Gender: Female
    {0.5, 40, 0}   // Economic status: 0.5, Age: 40, Gender: Female
};

// Target variable (1 if saved from sinking, 0 otherwise)
int target[NUM_SAMPLES] = {1, 0, 1, 0, 0};

// Logistic regression coefficients
float coefficients[NUM_FEATURES] = {0.5, -0.01, 0.3};

// Sigmoid function
float sigmoid(float x) {
    return 1 / (1 + exp(-x));
}

// Predict function
int predict(float features[NUM_FEATURES]) {
    float z = 0;
    for (int i = 0; i < NUM_FEATURES; i++) {
        z += coefficients[i] * features[i];
    }
    float probability = sigmoid(z);
    return (probability >= 0.5) ? 1 : 0;
}

int main() {
    // Predict for each sample
    for (int i = 0; i < NUM_SAMPLES; i++) {
        int prediction = predict(data[i]);
        cout<<"Sample "<<i+1<<": Predicted="<<prediction<<", Actual="<<target[i]<<endl;
    }
    return 0;
}


