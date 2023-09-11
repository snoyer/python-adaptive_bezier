# Python `adaptive_bezier`

A python interface to [_Adaptive Subdivision of Bezier Curves_](https://agg.sourceforge.net/antigrain.com/research/adaptive_bezier/)
by Maxim Shemanarev
from Anti-Grain Geometry.

This implementation uses the `curve4_div::recursive_bezier` and `curve4_div::bezier` functions unmodified
from the original [`agg_curves.cpp`](https://agg.sourceforge.net/antigrain.com/__code/src/agg_curves.cpp.html)
and minimal boilerplate to make it usable as a [Python extension](https://docs.python.org/3/extending/extending.html):

- constants have been changed to class members to be modifiable at runtime
- the original vector of points used to build the output is replaced with a mock object to add the points directly to a python list

The user-facing Python interface uses the `complex` type for points:

```py
>>> from adaptive_bezier import adaptive_bezier
>>> print(adaptive_bezier(0j, 10 + 5j, 8 + 2j, 1 + 1j, 1e-2))
[0j, (1.78125+0.875j), (4.447265625+2.05859375j), (6.111328125+2.66796875j), (6.724365234375+2.80712890625j), (6.8818359375+2.791015625j), (6.76171875+2.6328125j), (5.912109375+2.22265625j), (4.388671875+1.70703125j), (2.2734375+1.203125j), (1+1j)]
```
