/* Claudio Perez
 * PyG3 - Bindings to core components in the OpenSees framework.
 *
 */

#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>
#include <pybind11/stl.h>

#include "quakeio.hpp"


#include <ArrayOfTaggedObjects.h>
#include <MapOfTaggedObjects.h>

/* Domain 
 *******************************************/
#include <domain/domain/Domain.h>
#include <domain/element/Element.h>
#include <ElementIter.h>
#include <FEM_ObjectBroker.h>
#include <Parameter.h>
#include <Channel.h>
#include <domain/node/Node.h>
#include <SP_Constraint.h>
#include <domain/node/NodalLoad.h>

#include <LoadPattern.h>
#include <EarthquakePattern.h>
#include <GroundMotion.h>
#include <UniformExcitation.h>
#include <TimeSeries.h>
#include <PathTimeSeries.h>
#include <LinearSeries.h>

/* Elements */
#include <ZeroLength.h>

/* Analysis 
 ********************************************/
#include <AnalysisModel.h>
#include <LoadControl.h>
#include <Linear.h>
#include <ConstraintHandler.h>
/* Static */
#include <StaticAnalysis.h>
#include <StaticIntegrator.h>
/* Transient */
#include <TransientAnalysis.h>
#include <TransientIntegrator.h>
#include <DirectIntegrationAnalysis.h>
/* Concrete */
#include <PenaltyConstraintHandler.h>
#include <DOF_Numberer.h>

#include <ConvergenceTest.h>
// #include <CTestNormUnbalance.h>
#include <EquiSolnAlgo.h>

/* Graph */
#include <RCM.h>
// #include <GraphNumberer.h>

/* System of Equations */
#include <SystemOfEqn.h>
#include <LinearSOE.h>
#include <LinearSOESolver.h>
#include <BandSPDLinSolver.h>
#include <BandSPDLinSOE.h>
#include <BandSPDLinLapackSolver.h>

/* Error streams */
#include <handler/OPS_Stream.h>
#include <StandardStream.h>


/* Create global error stream */
StandardStream sserr;
OPS_Stream *opserrPtr = &sserr;

namespace py = pybind11;

void
init_element(py::module &m)
{
    py::class_<Element, std::shared_ptr<Element> >(m, "Element");
    py::class_<ZeroLength, std::shared_ptr<ZeroLength> >(m, "ZeroLength");
}

void
init_analysis(py::module &m)
{
    py::class_<TaggedObjectStorage>(m, "TaggedObjectStorage");
    py::class_<AnalysisModel>(m, "AnalysisModel")
       .def (py::init())
       .def (py::init<int>(), py::arg("classTag"))
       .def (py::init<TaggedObjectStorage&,TaggedObjectStorage&>(), 
            py::arg("theFiniteElements"), py::arg("theDOFs"))
    ;

    py::class_<EquiSolnAlgo>(m, "EquiSolnAlgo");
    py::class_<Linear, EquiSolnAlgo>(m, "Linear")
       /* Constructor */
       .def (py::init())
    ;

    py::class_<StaticIntegrator>(m, "StaticIntegrator");
    py::class_<LoadControl, StaticIntegrator>(m, "LoadControl")
        .def (py::init<float, int, float, float>()
             // ,py::arg("tag"), py::arg("ndof"), py::arg("Crd1"), py::arg("Crd2")
        )
    ;
    py::class_<ConstraintHandler>(m,"ConstraintHandler");
    py::class_<PenaltyConstraintHandler, ConstraintHandler>(m, "PenaltyConstraintHandler")
        .def (py::init<float, float>()
             // ,py::arg("tag"), py::arg("ndof"), py::arg("Crd1"), py::arg("Crd2")
        )
    ;
    py::class_<DOF_Numberer>(m, "DOF_Numberer")
        .def (py::init<GraphNumberer&>())
    ;

    py::class_<StaticAnalysis>(m, "StaticAnalysis")
        .def (py::init< \
                Domain&,
                ConstraintHandler&,
                DOF_Numberer&,
                AnalysisModel&,
                EquiSolnAlgo&,
                LinearSOE&,
                StaticIntegrator&,
                ConvergenceTest*>(),
              py::arg("theDomain"),
              py::arg("theHandler"),
              py::arg("theNumberer"),
              py::arg("theModel"),
              py::arg("theSolnAlgo"),           
              py::arg("theSOE"),
              py::arg("theIntegrator"),
              py::arg("theTest")=0

        )
        .def (py::init([](
             Domain& theDomain,
             ConstraintHandler &theHandler,
             DOF_Numberer &theNumberer,
             AnalysisModel &theModel,
             EquiSolnAlgo &theSolnAlgo,           
             LinearSOE &theSOE,
             StaticIntegrator &theIntegrator
             // ConvergenceTest *theTest = 0
        )->StaticAnalysis{
             // printf("called\n\n\n");
             return StaticAnalysis(
                 theDomain,theHandler,theNumberer,theModel,
                 theSolnAlgo,theSOE,theIntegrator, (ConvergenceTest *)0
        );})
        )
        .def ("analyze", &StaticAnalysis::analyze, py::arg("numSteps"))
    ;
    py::class_<TransientAnalysis>(m, "TransientAnalysis");
    py::class_<DirectIntegrationAnalysis, TransientAnalysis>(m, "DirectIntegrationAnalysis")
        .def (py::init< \
                Domain&,
                ConstraintHandler&,
                DOF_Numberer&,
                AnalysisModel&,
                EquiSolnAlgo&,
                LinearSOE&,
                TransientIntegrator&,
                ConvergenceTest*>(),
              py::arg("domain"),
              py::arg("handler"),
              py::arg("numberer"),
              py::arg("model"),
              py::arg("algo"),           
              py::arg("soe"),
              py::arg("integrator"),
              py::arg("test")=0

        )
        .def (py::init([](
             Domain& theDomain,
             ConstraintHandler &theHandler,
             DOF_Numberer &theNumberer,
             AnalysisModel &theModel,
             EquiSolnAlgo &theSolnAlgo,           
             LinearSOE &theSOE,
             TransientIntegrator &theIntegrator
             // ConvergenceTest *theTest = 0
        )->DirectIntegrationAnalysis{
             return DirectIntegrationAnalysis(
                 theDomain,theHandler,theNumberer,theModel,
                 theSolnAlgo,theSOE,theIntegrator, (ConvergenceTest *)0
        );})
        )
        .def ("analyze", &TransientAnalysis::analyze, 
             py::arg("numSteps"),
             py::arg("dt")
        )
    ;
}

void
init_graph(py::module &m)
{
    py::class_<GraphNumberer>(m, "GraphNumberer");
    py::class_<RCM, GraphNumberer>(m, "RCM")
        .def (py::init())
    ;
}

void
init_sys_of_eqn(py::module &m)
{
    // py::class_<SystemOfEqn>(m, "SystemOfEqn");
    // py::class_<LinearSOESolver>(m, "LinearSOESolver");
    py::class_<BandSPDLinSolver>(m, "BandSPDLinSolver");
    py::class_<BandSPDLinLapackSolver, BandSPDLinSolver>(m, "BandSPDLinLapackSolver")
        .def (py::init())
    ;

    py::class_<LinearSOE>(m, "LinearSOE");
    py::class_<BandSPDLinSOE,LinearSOE>(m, "BandSPDLinSOE")
        .def (py::init<BandSPDLinSolver&>())
    ;
}

void
init_base(py::module &m)
{
    py::class_<Vector, std::unique_ptr<Vector, py::nodelete>>(m, "Vector", py::buffer_protocol())
        .def (py::init([](
             py::array_t<double, py::array::c_style|py::array::forcecast> array
        )->Vector{
             bool verbose = true;
             py::buffer_info info = array.request();
             if (verbose){
                 py::print("ptr\t",info.ptr);
                 py::print("itemsize\t", info.itemsize);
                 py::print("format\t", info.format);
                 py::print("ndim\t", info.ndim);
                 py::print("shape\t", py::cast(info.shape));
                 py::print("strides\t", py::cast(info.strides));
                 py::print("array\t", array);
                 printf("%lf\n", *((double*)info.ptr));
             }
             return Vector(static_cast<double*>(info.ptr),(int)info.shape[0]);

        }))
        /* Allow reference by numpy array; requires access to Vector.theData */
        // .def_buffer([](Vector& v) -> py::buffer_info{
        //       return py::buffer_info(
        //       );
        // })

        /* pyg3.Vector(array:Seq, assert_size:int) */
        .def (py::init([](
             py::array_t<double, py::array::c_style|py::array::forcecast> array,
             int assert_size
        ) -> Vector {
             bool verbose = true;
             py::buffer_info info = array.request();
             if (verbose){
                 py::print("ptr\t",info.ptr);
                 py::print("itemsize\t", info.itemsize);
                 py::print("format\t", info.format);
                 py::print("ndim\t", info.ndim);
                 py::print("shape\t", py::cast(info.shape));
                 py::print("strides\t", py::cast(info.strides));
             }
             if (info.shape[0] != assert_size)
                 throw std::runtime_error("Incompatible buffer dimension.");
             return Vector(
                 static_cast<double*>(info.ptr), 
                 // static_cast<int>(info.itemsize)
                 static_cast<int>(info.shape[0])
             );
        }))
    ;
    
}


PYBIND11_MODULE(_pyg3, m)
{
    // py::implicitly_convertible<py::array_t<double>, Vector>();

    /***************************************
     * Initialize modules 
     ***************************************/
    init_base(m);

    py::module analysis = m.def_submodule("analysis", 
        "Analysis components");
    init_analysis(analysis);


    /* Initialize graph module */ 
    py::module graph_module = m.def_submodule("graph", 
        "Components for modeling graph structures");
    init_graph(graph_module);

    /* Initialize system of equations module (syseqn) */
    py::module sys_of_eqn = m.def_submodule("sys_of_eqn", 
        "Components for constructing systems of equations");
    init_sys_of_eqn(sys_of_eqn);

    py::module domain   = m.def_submodule("domain", 
        "Domain components");
    py::class_<Domain>(domain, "Domain")
        .def (py::init())
        .def ("addNode",    &Domain::addNode)
        .def ("getNode",    &Domain::getNode,    py::arg("tag"))
        .def ("removeNode", &Domain::removeNode, py::arg("tag"))

        /* Element management */
        .def ("addElement",       &Domain::addElement)
        .def ("getElement",       &Domain::getElement)
        .def ("getElements",      &Domain::getElements)
        .def ("removeElement",    &Domain::removeElement)
        .def ("activateElements", &Domain::activateElements)

        /* Parameter management */
        .def ("addParameter",     &Domain::addParameter)
        .def ("getParameter",     &Domain::getParameter)
        .def ("removeParameter",  &Domain::removeParameter)

        /* Loads */ 
        .def ("addNodalLoad",     &Domain::addNodalLoad)
        .def ("addLoadPattern",   &Domain::addLoadPattern)

        .def ("addSP_Constraint", 
             static_cast<bool (Domain::*)(SP_Constraint*)>(&Domain::addSP_Constraint))
        // .def ("addMP_Constraint", &Domain::addMP_Constraint)
    ;

    py::class_<Node, std::shared_ptr<Node> >(domain, "Node")
        .def (py::init<int, int, float, float> (),
             py::arg("tag"),  //"Node tag."), 
             py::arg("ndof"), //"Number of degrees of freedom at node"), 
             py::arg("Crd1"), 
             py::arg("Crd2")
        )
        .def ("getNumberDOF", &Node::getNumberDOF)
        .def ("getDisp",      &Node::getDisp     )
        .def ("sendSelf",     &Node::sendSelf    )
        .def ("recvSelf",     &Node::recvSelf    )
    ;
    /******************************************************
     *|
     ******************************************************/
    py::class_<TimeSeries>(domain, "TimeSeries");
    py::class_<PathTimeSeries>(domain, "PathTimeSeries");
    py::class_<LinearSeries, TimeSeries>(domain, "LinearSeries")
        .def (py::init())
        .def ("getFactor",     &LinearSeries::getFactor)
    ;
    py::class_<LoadPattern>(domain, "LoadPattern",
         "The `LoadPattern` class is a concrete base class. A `LoadPattern "
         "is a container class for `Load` and `SP_Constraint objects."
         )
        .def (py::init<int>())
        .def ("setTimeSeries", &LoadPattern::setTimeSeries)
    ;
    py::class_<EarthquakePattern, LoadPattern>(domain, "EarthquakePattern");

    py::class_<UniformExcitation, EarthquakePattern>(domain, "UniformExcitation")
        .def (py::init< \
                GroundMotion&,
                int,
                int,
                double,
                double>(),
              py::arg("motion"),
              py::arg("dof"),
              py::arg("tag"),
              py::arg("vel") = 0.0,
              py::arg("factor") = 1.0
        )
        .def (py::init([](
             int tag,
             int dof,
             py::array_t<double,py::array::c_style|py::array::forcecast> motion,
             double time_step,
             double vel=0.0,
             double factor=1.0
        ) -> UniformExcitation {
             printf("called\n\n\n");
             GroundMotion *ground_motion = quake2sees_motion(motion, time_step);
             return UniformExcitation(*ground_motion, dof, tag, vel, factor);
        }), 
             py::arg("tag"), py::arg("dof"), py::arg("accel"), py::arg("time_step"),
             py::arg("init_veloc")=0.0, py::arg("factor")=1.0
        )
    ;

    py::class_<NodalLoad>(domain, "NodalLoad", 
        "A class for applying nodal loads to the mode.")
        .def (py::init<int>())
        .def (py::init<int, int, Vector>())
    //    .def (py::init([](int tag, int node, py::array_t<double> array){
    //        return new NodalLoad(tag, node, new Vector(array));
    //    })
    //        // py::arg("tag"), py::arg("node"), py::arg("vector")
    //    )
    ;
    py::class_<SP_Constraint>(domain, "SP_Constraint")
        .def (py::init<int, int, int, double>())
    ;
}

