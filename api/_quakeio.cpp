#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>

#include <Vector.h>
#include <UniformExcitation.h>
#include <PathSeries.h>
#include <GroundMotion.h>

#define ARRAY_FLAGS py::array::c_style|py::array::forcecast

namespace py = pybind11;

//TimeSeries*
GroundMotion*
quake2sees_motion(
    py::array_t<double,ARRAY_FLAGS> quake_array, 
    double time_step, 
    double time_start = 0.0, 
    double cfactor = 1.0,
    int tag = 110
)
{
    Vector *accel;
    TimeSeries *accelSeries;
    GroundMotion *groundMotion;
    /* quake -> {Vector} */
    py::buffer_info info = quake_array.request();
    double* accel_array = static_cast<double*>(info.ptr);
    int array_size = static_cast<int>(info.shape[0]);
    accel = new Vector(accel_array,array_size);

    /* {Vector} -> {TimeSeries:PathTimeSeries} */
    accelSeries = new PathSeries(tag, *accel, time_step, cfactor, false, time_start);

    groundMotion = new GroundMotion(0, 0, accelSeries, 0);
    return groundMotion;
    /* TimeSeries -> Pattern:UniformExcitation */

}

GroundMotion*
ground_motion(
    double* accel_array, 
    int array_size,
    double time_step, 
    double time_start = 0.0, 
    double cfactor = 1.0,
    int tag = 110
)
{
    Vector *accel;
    TimeSeries *accelSeries;
    GroundMotion *groundMotion;
    /* quake -> {Vector} */
    accel = new Vector(accel_array,array_size);

    /* {Vector} -> {TimeSeries:PathTimeSeries} */
    accelSeries = new PathSeries(tag, *accel, time_step, cfactor, false, time_start);

    groundMotion = new GroundMotion(0, 0, accelSeries, 0);
    return groundMotion;
    /* TimeSeries -> Pattern:UniformExcitation */

}
