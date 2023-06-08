cmake_minimum_required(VERSION 3.0.0)
project(cnn VERSION 0.1.0 LANGUAGES C)

include(CTest)
enable_testing()

add_executable(cnn main.c ./images/image.c ./matrix/matrix.c ./matrix/operations.c ./network/activations.c ./network/nn.c)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
