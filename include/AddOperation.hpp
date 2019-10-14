#pragma once

#include <vector>

class AddOperation {

private:

    float param_a;
    float param_b;

public:

    AddOperation (std::vector<float> parameters);

    float Add (float a, float b);

};
