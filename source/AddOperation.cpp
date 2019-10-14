
#include "AddOperation.hpp"

AddOperation::AddOperation(std::vector<float> parameters) {
    param_a = parameters.at(0);
    param_b = parameters.at(1);
}

float AddOperation::Add(float a, float b) {
    return param_a * (a + b) + param_b;
}
