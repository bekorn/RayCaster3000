cmake_minimum_required(VERSION 3.8)
project(RayCaster3000)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_EXE_LINKER_FLAGS "-static")

if (NOT CMAKE_BUILD_TYPE MATCHES Debug)
    add_definitions(-NDEBUG)
endif()

set(SOURCE_FILES main.cpp
        Primitives/Vector3.h
        Primitives/Color.h
        Primitives/Ray.h
        Primitives/Intersection.h
        Modals/Materials/Material.h
        Modals/Shapes/Shape.h
        Modals/Shapes/Sphere.h
        Modals/Shapes/Plane.h
        Modals/Modal.h
        Lights/Light.h
        Cameras/Camera.h
        Scenes/Scene.cpp
        Scenes/Scene.h
        "File IO/Parser.h"
        "File IO/Composer.h"
        "File IO/Basic_IO.h"
        Primitives/Vector3.cpp
        Primitives/Color.cpp
        Primitives/Ray.cpp
        Primitives/Intersection.cpp
        Modals/Materials/Material.cpp
        Modals/Shapes/Shape.cpp
        Modals/Shapes/Sphere.cpp
        Modals/Shapes/Plane.cpp
        Modals/Modal.cpp
        Lights/Light.cpp
        Cameras/Camera.cpp
        "File IO/Parser.cpp"
        "File IO/Composer.cpp"
        "File IO/Basic_IO.cpp"
        Scenes/Settings.h Lights/AmbientLight.cpp Lights/AmbientLight.h Lights/PointLight.cpp Lights/PointLight.h Modals/Shapes/Disk.cpp Modals/Shapes/Disk.h Debug/LeakCounter.h Scenes/Render.cpp Scenes/Render.h Debug/Config.h Config.h)
add_executable(RayCaster3000 ${SOURCE_FILES})