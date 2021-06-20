#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>

#include <GroundMotion.h>

GroundMotion*
quake2sees_motion(
    pybind11::array_t<double,pybind11::array::c_style|pybind11::array::forcecast>, 
    double time_step,
    double time_start = 0.0,
    double cfactor = 1.0,
    int tag = 0
);

