#include "menu.h"

Menu::Menu(SDL_Texture* texture_title, SDL_Texture* texture_credits, SDL_Texture *texture_start_1_player,
           SDL_Texture *texture_start_2_player, SDL_Texture *texture_start_3_player,
           SDL_Texture *texture_start_4_player, SDL_Texture *texture_hand, SDL_Texture* texture_winner_background) {
    index = 0;

    title = texture_title;
    credits = texture_credits;
    hand = texture_hand;
    start_1_player = texture_start_1_player;
    start_2_player = texture_start_2_player;
    start_3_player = texture_start_3_player;
    start_4_player = texture_start_4_player;
    winner_background = texture_winner_background;

    int w, h;
    SDL_QueryTexture(title, nullptr, nullptr, &w, &h);
    title_rect = {154, 63, w, h};
    SDL_QueryTexture(credits, nullptr, nullptr, &w, &h);
    credits_rect = {266, 324, w, h};
    SDL_QueryTexture(hand, nullptr, nullptr, &w, &h);
    hand_rect = {147, 198, w, h};
    SDL_QueryTexture(start_1_player, nullptr, nullptr, &w, &h);
    start_1_player_rect = {112, 230, w, h};
    SDL_QueryTexture(start_2_player, nullptr, nullptr, &w, &h);
    start_2_player_rect = {224, 230, w, h};
    SDL_QueryTexture(start_3_player, nullptr, nullptr, &w, &h);
    start_3_player_rect = {336, 230, w, h};
    SDL_QueryTexture(start_4_player, nullptr, nullptr, &w, &h);
    start_4_player_rect = {448, 230, w, h};
    SDL_QueryTexture(winner_background, nullptr, nullptr, &w, &h);
    winner_background_rect = {272, 115, w, h};
}

void Menu::Left() {
    if (--index < 0)
        index = 0;
    SetHandPosition(index);
}

void Menu::Right() {
    if (++index >= 4)
        index = 3;
    SetHandPosition(index);
}

int Menu::Select() {
    return index + 1;
}

void Menu::ShowScore(std::vector<SDL_Texture*> texture_bird, std::vector<SDL_Rect*> frame_rect) {
    bird = texture_bird[0];
    bird_rect = frame_rect[0];
    showTitle = false;
}

void Menu::Update() {

}

void Menu::Render(SDL_Renderer *renderer) {
    if (showTitle) {
        SDL_RenderCopy(renderer, title, nullptr, &title_rect);
        SDL_RenderCopy(renderer, credits, nullptr, &credits_rect);
    } else {
        SDL_RenderCopy(renderer, winner_background, nullptr, &winner_background_rect);
    }
    SDL_RenderCopy(renderer, hand, nullptr, &hand_rect);
    SDL_RenderCopy(renderer, start_1_player, nullptr, &start_1_player_rect);
    SDL_RenderCopy(renderer, start_2_player, nullptr, &start_2_player_rect);
    SDL_RenderCopy(renderer, start_3_player, nullptr, &start_3_player_rect);
    SDL_RenderCopy(renderer, start_4_player, nullptr, &start_4_player_rect);
}

void Menu::SetHandPosition(int index) {
    SDL_Rect* button_rect;
    switch (index) {
        case 0:
            button_rect = &start_1_player_rect;
            break;
        case 1:
            button_rect = &start_2_player_rect;
            break;
        case 2:
            button_rect = &start_3_player_rect;
            break;
        default:
            button_rect = &start_4_player_rect;
            break;
    }
    hand_rect.x = button_rect->x + button_rect->w / 2 - hand_rect.w / 2;
}