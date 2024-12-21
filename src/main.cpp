#include "Game.hpp"

int main()
{
    Game game(1000, 1000, "star wars");

    while (game.running())
    {
        game.update();
        game.render();
    }
}