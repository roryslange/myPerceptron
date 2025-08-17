# Parent project does not export its library target, so this CML implicitly
# depends on being added from it, i.e. the testing is done only from the build
# tree and is not feasible from an install location

project(perceptronTests LANGUAGES CXX)

# ---- Tests ----

add_executable(perceptron_test source/perceptron_test.cpp)
target_link_libraries(perceptron_test PRIVATE perceptron_lib)
target_compile_features(perceptron_test PRIVATE cxx_std_17)

add_test(NAME perceptron_test COMMAND perceptron_test)

# ---- End-of-file commands ----

add_folders(Test)
