cmake_minimum_required(VERSION 3.15)
project(ThreeCategoryAbstractFactory)

set(CMAKE_CXX_STANDARD 17)

add_executable(ThreeCategoryAbstractFactory main.cpp NullType.h AbstractFactoryGenerator.h EmptyType.h LinearHierarchyGenerator.h Product.h TypeUtils.h TypeList.h ScatterHierarchyGenerator.h)