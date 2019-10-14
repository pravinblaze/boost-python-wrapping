
#include "Apply.hpp"

Apply::Apply(std::vector<float> list, AddOperation& operation): operation(operation) {
    this->list = list;
}

std::vector<float> Apply::GetResult() {

    std::vector<float> results;

    for (unsigned int i = 0u; i < list.size(); ++i) {
        results.push_back(operation.Add(list.at(i), list.at((i+1)%list.size())));
    }

    return results;
}
