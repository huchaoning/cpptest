#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>
#include <Eigen/Dense>

namespace py = pybind11;

py::array_t<double> inverse(py::array_t<double> input) {
    auto buf = input.request();
    // 零拷贝把 NumPy 映射给 Eigen
    Eigen::Map<Eigen::MatrixXd> mat(static_cast<double*>(buf.ptr), buf.shape[0], buf.shape[1]);
    Eigen::MatrixXd inv = mat.inverse();

    return py::array_t<double>({inv.rows(), inv.cols()}, {sizeof(double)*inv.rows(), sizeof(double)}, inv.data());
}

PYBIND11_MODULE(my_math, m) {
    m.def("inverse", &inverse);
}
