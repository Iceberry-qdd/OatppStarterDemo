cmake_minimum_required(VERSION 3.1)

set(project_name OatppServerDemo)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_HOME_DIRECTORY}/bin)

# set your oatpp lib absolute path on your computer
set(OATPP_PATH "../oatpp-X.X.X")

project(${project_name})

set(CMAKE_CXX_STANDARD 11)
set(oatpp_DIR ${OATPP_PATH})

add_library(${project_name}-lib
    src/AppComponent.hpp
    src/controller/MyController.cpp
    src/controller/MyController.hpp
    src/dto/DTOs.hpp
)

find_package(oatpp 1.3.0 REQUIRED)
include_directories("${OATPP_PATH}/oatpp")

target_link_libraries(${project_name}-lib
        PUBLIC oatpp::oatpp
        PUBLIC oatpp::oatpp-test
)

target_include_directories(${project_name}-lib PUBLIC src)

add_executable(${project_name}-exe
    src/App.cpp
    test/app/MyApiTestClient.hpp
)

target_link_libraries(${project_name}-exe ${project_name}-lib)
add_dependencies(${project_name}-exe ${project_name}-lib)

add_executable(${project_name}-test
    test/tests.cpp
    test/app/TestComponent.hpp
    test/app/MyApiTestClient.hpp
    test/MyControllerTest.cpp
    test/MyControllerTest.hpp
)

target_link_libraries(${project_name}-test ${project_name}-lib)
add_dependencies(${project_name}-test ${project_name}-lib)

set_target_properties(${project_name}-lib ${project_name}-exe ${project_name}-test PROPERTIES
    CXX_STANDARD 11
    CXX_EXTENSIONS OFF
    CXX_STANDARD_REQUIRED ON
)

enable_testing()
add_test(project-tests ${project_name}-test)