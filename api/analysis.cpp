//#include "ops_stream.h"
#include <OPS_Stream.h>
#include <StaticAnalysis.h>
#include <AnalysisModel.h>
#include <Linear.h>
#include <PenaltyConstraintHandler.h>
#include <RCM.h>

#include <pybind11/pybind11.h>
namespace py = pybind11;

extern OPS_Stream *opserrPtr;


void init_analysis(py::module &m){
     py::class_ <AnalysisModel>(m, "AnalysisModel")
       .def (py::init()); 
}




