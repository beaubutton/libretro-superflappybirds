#ifndef LR_SUPERFLAPPYBIRD_TEXTURES_H
#define LR_SUPERFLAPPYBIRD_TEXTURES_H

#include <SDL_render.h>
#include <vector>
#include "engine/texture.hpp"
#include "engine/rect.hpp"
#include "engine/image.hpp"

class Assets {
public:
    Texture* buildings;
    Texture* ground;
    Texture* pipe_top;
    Texture* pipe_bottom;
    Texture* bird;
    Texture* bird2;
    Texture* bird3;
    Texture* bird4;
    Texture* numbers;
    Texture* score_background;
    Texture* start_1_player;
    Texture* start_2_player;
    Texture* start_3_player;
    Texture* start_4_player;
    Texture* hand;
    Texture* title;
    Texture* credits;
    Texture* winner_background;

    std::vector<Rect> bird_frames;
    std::vector<Rect> numbers_frames;

    Assets(std::string core_folder_path) {
        SDL_Surface *pipe_top = SDL_LoadBMP("resources/pipe_top.bmp");
        SDL_Surface *pipe_bottom = SDL_LoadBMP("resources/pipe_bottom.bmp");
        SDL_Surface *bird = SDL_LoadBMP("resources/bird.bmp");
        SDL_Surface *bird2 = SDL_LoadBMP("resources/bird2.bmp");
        SDL_Surface *bird3 = SDL_LoadBMP("resources/bird3.bmp");
        SDL_Surface *bird4 = SDL_LoadBMP("resources/bird4.bmp");
        SDL_Surface *numbers = SDL_LoadBMP("resources/numbers.bmp");
        SDL_Surface *hand = SDL_LoadBMP("resources/hand.bmp");
        SDL_Surface *title = SDL_LoadBMP("resources/title.bmp");

        this->buildings = Image::LoadPNM(core_folder_path + "resources/buildings.pnm");
        this->ground = Image::LoadPNM(core_folder_path + "resources/ground.bmp");
        this->pipe_top = surface_to_texture(pipe_top);
        this->pipe_bottom = surface_to_texture(pipe_bottom);
        this->bird = surface_to_texture(bird);
        this->bird2 = surface_to_texture(bird2);
        this->bird3 = surface_to_texture(bird3);
        this->bird4 = surface_to_texture(bird4);
        this->numbers = surface_to_texture(numbers);
        this->score_background = Image::LoadPNM(core_folder_path + "resources/score_background.bmp");
        this->start_1_player = Image::LoadPNM(core_folder_path + "resources/start_1_player.bmp");
        this->start_2_player = Image::LoadPNM(core_folder_path + "resources/start_2_player.bmp");
        this->start_3_player = Image::LoadPNM(core_folder_path + "resources/start_3_player.bmp");
        this->start_4_player = Image::LoadPNM(core_folder_path + "resources/start_4_player.bmp");
        this->hand = surface_to_texture(hand);
        this->title = surface_to_texture(title);
        this->credits = Image::LoadPNM(core_folder_path + "resources/credits.bmp");
        this->winner_background = Image::LoadPNM(core_folder_path + "resources/winner_background.bmp");

        SDL_FreeSurface(pipe_top);
        SDL_FreeSurface(pipe_bottom);
        SDL_FreeSurface(bird);
        SDL_FreeSurface(bird2);
        SDL_FreeSurface(bird3);
        SDL_FreeSurface(bird4);
        SDL_FreeSurface(numbers);
        SDL_FreeSurface(hand);
        SDL_FreeSurface(title);

        bird_frames.push_back({0, 0, 17, 12});
        bird_frames.push_back({17, 0, 17, 12});
        bird_frames.push_back({34, 0, 17, 12});
        bird_frames.push_back({51, 0, 17, 12});

        numbers_frames.push_back({0,   0, 14, 20});
        numbers_frames.push_back({14,  0, 10, 20});
        numbers_frames.push_back({24,  0, 14, 20});
        numbers_frames.push_back({38,  0, 14, 20});
        numbers_frames.push_back({52,  0, 14, 20});
        numbers_frames.push_back({66,  0, 14, 20});
        numbers_frames.push_back({80,  0, 14, 20});
        numbers_frames.push_back({94,  0, 14, 20});
        numbers_frames.push_back({108, 0, 14, 20});
        numbers_frames.push_back({122, 0, 14, 20});
    }

private:
    static Texture* surface_to_texture(SDL_Surface *surface) {
        auto buffer = new uint32_t[surface->w * surface->h];
        int bpp = surface->format->BytesPerPixel;
        for (int x = 0; x < surface->w; ++x) {
            for (int y = 0; y < surface->h; ++y) {
                Uint8 *p = (Uint8 *)surface->pixels + y * surface->pitch + x * bpp;
#if (SDL_BYTEORDER == SDL_BIG_ENDIAN)
                buffer[y * surface->w + x] = p[0] << 16 | p[1] << 8 | p[2];
#else
                buffer[y * surface->w + x] = p[0] | p[1] << 8 | p[2] << 16 | p[3] << 24;
#endif
            }
        }

        return new Texture(buffer, surface->w, surface->h);
    }
};

#endif //LR_SUPERFLAPPYBIRD_TEXTURES_H
