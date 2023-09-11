from setuptools import Extension, setup

setup(
    name="adaptive_bezier",
    version="0.0.1",
    description=(
        "Adaptive Subdivision of Bezier Curves"
        " by Maxim Shemanarev, "
        " from Anti-Grain Geometry."
    ),
    packages=[
        "adaptive_bezier",
    ],
    python_requires=">=3.9.0",
    ext_modules=[
        Extension(
            "agg_adaptive_bezier",
            [
                "pymodule.cpp",
                "agg/agg_curves.cpp",
            ],
            extra_compile_args=["-Wl,--no-undefined", "-O3"],
        )
    ],
)
