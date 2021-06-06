#include <pybind11/pybind11.h>
#include <domain/domain/Domain.h>
#include <domain/element/Element.h>
#include <ElementIter.h>
#include <FEM_ObjectBroker.h>
#include <Parameter.h>
#include <Channel.h>
#include <domain/node/Node.h>

/* Error streams */
#include <handler/OPS_Stream.h>
#include <StandardStream.h>



/* Create global error stream */
StandardStream sserr;
OPS_Stream *opserrPtr = &sserr;

namespace py = pybind11;

// py::module pyg3_domain = m.def_submodule("domain", "Domain objects");

PYBIND11_MODULE (domain, m)
{
    py::class_ < Domain > (m, "Domain")
        .def (py::init())
        .def ("addNode",    &Domain::addNode)
        .def ("getNode",    &Domain::getNode,    py::arg("tag"))
        .def ("removeNode", &Domain::removeNode, py::arg("tag"))
        /* Element management */
        .def ("addElement",    &Domain::addElement)
        .def ("getElement",    &Domain::getElement)
        .def ("getElements",    &Domain::getElements)
        .def ("removeElement", &Domain::removeElement)
        .def ("activateElements", &Domain::activateElements)

        /* Parameter */
        .def ("addParameter",    &Domain::addParameter)
        .def ("getParameter",    &Domain::getParameter)
        .def ("removeParameter", &Domain::removeParameter)
    ;

    py::class_ < Node > (m, "Node")
        .def (py::init<int, int, float, float> (),
             py::arg("tag"), py::arg("ndof"), py::arg("Crd1"), py::arg("Crd2")
        )
        .def ("getNumberDOF", &Node::getNumberDOF)
        .def ("getDisp", &Node::getDisp)
        .def ("sendSelf", &Node::sendSelf)
        .def ("recvSelf", &Node::recvSelf)
    ;
}
