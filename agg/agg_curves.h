#include <vector>

namespace agg {

/* from agg_math.h */
const double pi = 3.14159265358979323846;
inline double calc_sq_distance(double x1, double y1, double x2, double y2) {
  double dx = x2 - x1;
  double dy = y2 - y1;
  return dx * dx + dy * dy;
}

/* from agg_basics.h */
template <class T> struct point_base {
  typedef T value_type;
  T x, y;
  point_base() {}
  point_base(T x_, T y_) : x(x_), y(y_) {}
};
typedef point_base<double> point_d; //-----point_d


/* custom sub-classable point adder */
class point_adder {
public:
  virtual void add(const point_d& p) = 0;
};

/* minimal stand-in for original `pod_bvector<point_d> m_points` member */
class mock_points {
  point_adder *adder;
public:
  mock_points(point_adder *adder) : adder(adder) {}
  inline void add(const point_d& p) { adder->add(p); };
};

/* minimal `curve4_div` stand-in */
class curve4_div {
public:
  double m_approximation_scale = 1.0;
  double m_distance_tolerance_square = 1.0;
  double m_angle_tolerance = 0.0;
  double m_cusp_limit = 0.0;
  double curve_collinearity_epsilon = 1e-30; //used to be a constant
  double curve_angle_tolerance_epsilon = 0.01; //used to be a constant
  unsigned curve_recursion_limit = 32; //used to be a constant
  mock_points m_points;

  /* custom constructor accepting a user-defined point adder */
  curve4_div(point_adder *adder) : m_points(mock_points(adder)) {}

  void bezier(double x1, double y1, double x2, double y2, double x3, double y3,
              double x4, double y4);
  void recursive_bezier(double x1, double y1, double x2, double y2, double x3,
                        double y3, double x4, double y4, unsigned level);
};

} // namespace agg