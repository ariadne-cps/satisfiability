include_directories(${Python3_INCLUDE_DIRS})

get_target_property(PYTHON_COMMON_SOURCE_DIR pyariadne-python-common SOURCE_DIR)

add_library(pyariadne-satisfiability-submodule-obj OBJECT
    satisfiability_submodule.cpp
)

target_include_directories(pyariadne-satisfiability-submodule-obj PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}"
    "${PYTHON_COMMON_SOURCE_DIR}/include"
    $<TARGET_PROPERTY:pyariadne-symbolic,INTERFACE_INCLUDE_DIRECTORIES>
)
target_link_libraries(pyariadne-satisfiability-submodule-obj PRIVATE
    pyariadne-python-common
    pybind11::module
    satisfiability
)
set_target_properties(pyariadne-satisfiability-submodule-obj PROPERTIES POSITION_INDEPENDENT_CODE ON)

add_library(pyariadne-satisfiability INTERFACE)
target_sources(pyariadne-satisfiability INTERFACE
    $<TARGET_OBJECTS:pyariadne-satisfiability-submodule-obj>
)
target_include_directories(pyariadne-satisfiability INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    $<TARGET_PROPERTY:pyariadne-symbolic,INTERFACE_INCLUDE_DIRECTORIES>
)
target_link_libraries(pyariadne-satisfiability INTERFACE pyariadne-symbolic)

ariadne_add_python_module(
    NAME satisfiability
    MODULE_SOURCE satisfiability_module.cpp
)
