cmake_minimum_required(VERSION 3.25)
project(DataStructure)

set(CMAKE_CXX_STANDARD 14)

include_directories(Find)
include_directories(Graph)
include_directories(Liner)
include_directories(String)
include_directories(Tree)


add_executable(BST Tree/BST.cpp)
add_executable(Huffman Tree/Huffman.cpp)
add_executable(Heap Tree/Heap.cpp)

add_executable(List Liner/LinkedList.cpp)

add_executable(Hash Find/Hash.cpp)
add_executable(Bfind Find/Bfind.cpp)