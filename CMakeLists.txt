cmake_minimum_required(VERSION 3.29)
project(ece361f24_homework5_release_r1_0 C)

set(CMAKE_C_STANDARD 99)

add_executable(ece361f24_homework5_release_r1_0
        starters/iom361_r2/iom361_r2.h
        starters/iom361_r2/iom361_r2.c
        starters/iom361_r2/test_iom361_r2.c
        starters/karumanchi_bst/BinarySearchTree.c
        starters/karumanchi_bst/BinaryTree.c
        starters/random_float_generator/float_rndm.h
        starters/random_float_generator/float_rndm.c
        starters/random_float_generator/test_float_rndm.c
        starters/roy_files/tempHumidtree.h
)