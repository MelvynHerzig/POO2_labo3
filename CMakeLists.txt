cmake_minimum_required(VERSION 3.17)
project(labo3)

set(CMAKE_CXX_STANDARD 11)

add_executable(labo3 main.cpp Containers/Container.h Containers/Bank.cpp Containers/Bank.h Containers/Boat.cpp Containers/Boat.h Actors/Person.h Controller.cpp Controller.h  Actors/Person.cpp Containers/Container.cpp Actors/IndependentPerson.cpp Actors/IndependentPerson.h Actors/DependentPerson.cpp Actors/DependentPerson.h Actors/Child.cpp Actors/Child.h Actors/Thief.cpp Actors/Thief.h)