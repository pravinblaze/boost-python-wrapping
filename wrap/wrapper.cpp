
#include "boost/python.hpp"
#include "boost/python/suite/indexing/vector_indexing_suite.hpp"

#include "AddOperation.hpp"
#include "Apply.hpp"

namespace bp = boost::python;
using FloatVec = std::vector<float>;

BOOST_PYTHON_MODULE(pylib) {

    bp::class_<FloatVec>("float_vec")
        .def(bp::vector_indexing_suite<FloatVec>());

    bp::class_<AddOperation, boost::noncopyable>("add_operation", bp::init<FloatVec>())
        .def("add", &AddOperation::Add);

    bp::class_<Apply, boost::noncopyable>("apply", bp::init<FloatVec, AddOperation&>())
        .def("get_result", &Apply::GetResult);
}
