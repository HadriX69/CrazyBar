cmake_minimum_required(VERSION 4.2)
project(CrazyBar CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "bin")

add_executable(${PROJECT_NAME} "src/main.cpp"
        src/RenderWindow.cpp
        src/LoadRessource.cpp
        src/Tray.cpp
        src/Box2D_Init.cpp)

target_compile_options(${PROJECT_NAME} PRIVATE -Wall -m64)

FetchContent_Declare(
        box2d
        GIT_REPOSITORY https://github.com/erincatto/box2d.git
        GIT_TAG v2.4.1
)
FetchContent_MakeAvailable(box2d)


target_include_directories(${PROJECT_NAME} PRIVATE "C:/SDL2-w64/include")
target_link_directories(${PROJECT_NAME} PRIVATE "C:/SDL2-w64/lib")
target_include_directories(${PROJECT_NAME} PRIVATE "C:/box2d-2.4.1/include")



target_link_libraries(${PROJECT_NAME} PRIVATE mingw32 SDL2main SDL2 SDL2_image SDL2_ttf SDL2_mixer box2d)