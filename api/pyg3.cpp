#include <pybind11/pybind11.h>
#include <domain/domain/Domain.h>

namespace py = pybind11;

PYBIND11_MODULE (pyg3, m)
{
    py::class_ < Domain > (m, "Domain").def (py::init ());
}
