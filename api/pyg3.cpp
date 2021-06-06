#include <pybind11/pybind11.h>
#include <domain/domain/Domain.h>
#include <domain/node/Node.h>

/* Error streams */
#include <handler/OPS_Stream.h>
#include <StandardStream.h>

/* Create global error stream */
StandardStream sserr;
OPS_Stream *opserrPtr = &sserr;

namespace py = pybind11;

PYBIND11_MODULE (pyg3, m)
{
    py::class_ < Domain > (m, "Domain")
        .def (py::init ())
        .def ("addNode", &Domain::addNode)
        .def ("getNode", &Domain::getNode)
    ;

    py::class_ < Node > (m, "Node")
        .def (py::init<int, int, float, float> ())
    ;
}
