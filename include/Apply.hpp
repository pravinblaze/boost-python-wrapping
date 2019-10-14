#pragma once

#include <vector>
#include "AddOperation.hpp"

class Apply {

private:

    std::vector<float> list;
    AddOperation& operation;

public:

    Apply (std::vector<float> list, AddOperation& operation);

    std::vector<float> GetResult();

};
