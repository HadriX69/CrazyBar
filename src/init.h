#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class RenderWindow
{
    public:
    RenderWindow(const char* p_title, int p_x, int p_y, int p_w, int p_h, Uint32 flags);
    void GetWindow();

    private:
    SDL_Window* window;
    SDL_Renderer* renderer;
};
