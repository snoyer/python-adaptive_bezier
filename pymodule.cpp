#include "agg/agg_curves.h"
#include <Python.h>

class py_point_list : public agg::point_adder {
  PyObject *py_list;

public:
  py_point_list(PyObject *py_list) : py_list(py_list) {}
  inline void add(const agg::point_d &p) {
    PyList_Append(py_list, PyComplex_FromDoubles(p.x, p.y));
  }
};

static PyObject *method_agg_adaptive_bezier(PyObject *self, PyObject *args) {
  Py_complex p1, p2, p3, p4;
  PyObject *py_list = PyList_New(0);
  py_point_list py_points(py_list);

  agg::curve4_div div(&py_points);

  if (!PyArg_ParseTuple(args, "DDDDdddddi",                 //
                        &p1, &p2, &p3, &p4,                 //
                        &div.m_distance_tolerance_square,   //
                        &div.m_angle_tolerance,             //
                        &div.m_cusp_limit,                  //
                        &div.curve_collinearity_epsilon,    //
                        &div.curve_angle_tolerance_epsilon, //
                        &div.curve_recursion_limit          //
                        ))
    return NULL;

  div.bezier(p1.real, p1.imag, //
             p2.real, p2.imag, //
             p3.real, p3.imag, //
             p4.real, p4.imag);

  return py_list;
}

static PyMethodDef agg_adaptive_bezier_methods[] = {
    {"agg_adaptive_bezier", method_agg_adaptive_bezier, METH_VARARGS, "..."},
    {NULL, NULL, 0, NULL},
};

static struct PyModuleDef agg_adaptive_bezier_module = {
    PyModuleDef_HEAD_INIT, "agg_adaptive_bezier", "...", -1,
    agg_adaptive_bezier_methods};

PyMODINIT_FUNC PyInit_agg_adaptive_bezier(void) {
  return PyModule_Create(&agg_adaptive_bezier_module);
}
