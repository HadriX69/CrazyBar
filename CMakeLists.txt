cmake_minimum_required(VERSION 4.2)
project(CrazyBar CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 1. On regroupe les sources communes aux deux versions
set(SOURCES
        src/main.cpp
        src/RenderWindow.cpp
        src/LoadRessource.cpp
        src/Tray.cpp
        src/Box2D_Init.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})

# ---------------------------------------------------------
# CIBLE 3DS (Le toolchain devkitPro crée la variable "3DS")
# ---------------------------------------------------------
if(3DS)
    message(STATUS "Nintendo 3DS Configuration detected !")

    # On utilise find_package pour trouver les portlibs 3DS (SDL2, etc.)
    find_package(SDL2 REQUIRED)

    # On lie les librairies 3DS (ctru est vitale pour la console)
    target_link_libraries(${PROJECT_NAME} PRIVATE ctru SDL2::SDL2 box2d)

    # On génère le fichier .3dsx
    if(COMMAND add_3dsx_target)
        add_3dsx_target(${PROJECT_NAME})
    endif()

    # ---------------------------------------------------------
    # CIBLE PC (Windows 64-bits)
    # ---------------------------------------------------------
else()
    message(STATUS "Windows Configuration detected !")

    target_compile_options(${PROJECT_NAME} PRIVATE -Wall -m64)

    # FetchContent pour Box2D version PC
    include(FetchContent)
    FetchContent_Declare(
            box2d
            GIT_REPOSITORY https://github.com/erincatto/box2d.git
            GIT_TAG v2.4.1
    )
    FetchContent_MakeAvailable(box2d)

    # Chemins en dur uniquement pour le PC
    target_include_directories(${PROJECT_NAME} PRIVATE "C:/SDL2-w64/include")
    target_link_directories(${PROJECT_NAME} PRIVATE "C:/SDL2-w64/lib")
    target_include_directories(${PROJECT_NAME} PRIVATE "C:/box2d-2.4.1/include")

    # Librairies spécifiques à Windows
    target_link_libraries(${PROJECT_NAME} PRIVATE mingw32 SDL2main SDL2 SDL2_image SDL2_ttf SDL2_mixer box2d)
endif()