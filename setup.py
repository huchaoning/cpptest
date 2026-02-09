from setuptools import setup
from pybind11.setup_helpers import Pybind11Extension, build_ext

ext_modules = [
    Pybind11Extension(
        "my_math",
        ["src/main.cpp"],
        include_dirs=["Eigen"], # 告诉编译器去哪里找 Eigen 头文件
    ),
]

setup(name="my_math", ext_modules=ext_modules, cmdclass={"build_ext": build_ext})
