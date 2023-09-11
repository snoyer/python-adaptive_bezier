from agg_adaptive_bezier import agg_adaptive_bezier  # type: ignore


def adaptive_bezier(
    p1: complex,
    p2: complex,
    p3: complex,
    p4: complex,
    distance_tolerance_square: float,
    *,
    angle_tolerance: float = 0.0,
    cusp_limit: float = 0.0,
    curve_collinearity_epsilon: float = 1e-30,
    curve_angle_tolerance_epsilon: float = 0.01,
    curve_recursion_limit: int = 32,
) -> list[complex]:
    return agg_adaptive_bezier(
        p1,
        p2,
        p3,
        p4,
        distance_tolerance_square,
        angle_tolerance,
        cusp_limit,
        curve_collinearity_epsilon,
        curve_angle_tolerance_epsilon,
        curve_recursion_limit,
    )  # type: ignore
