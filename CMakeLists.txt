cmake_minimum_required(VERSION 3.17)
project(labo3)

set(CMAKE_CXX_STANDARD 11)

add_executable(labo3 main.cpp Containers/Container.h Containers/Bank.cpp Containers/Bank.h Containers/Boat.cpp Containers/Boat.h Actors/Person.h Actors/Policeman.cpp Actors/Policeman.h Actors/Thief.cpp Actors/Thief.h Controller.cpp Controller.h Actors/Child.cpp Actors/Child.h Actors/Parent.cpp Actors/Parent.h Actors/Behaviors/ICanDrive.cpp Actors/Behaviors/ICanDrive.h Actors/Behaviors/ICannotDrive.cpp Actors/Behaviors/ICannotDrive.h Actors/Behaviors/IFamilyMember.cpp Actors/Behaviors/IFamilyMember.h Actors/Behaviors/INotFamilyMember.cpp Actors/Behaviors/INotFamilyMember.h Actors/Person.cpp)