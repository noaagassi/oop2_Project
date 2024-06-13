#include <string>
#include <SFML/Graphics.hpp>

enum class TextureID {
    NewGame,
    Exit,
    Help,
    Player
};
const std::string NAME_OF_PNG_FILES[] = {
    "new_game.png", // TextureID::NewGame
    "exit.png",     // TextureID::Exit
    "help.png",     // TextureID::Help
    "player.png"
};

const int NUM_OF_TEXTURES = sizeof(NAME_OF_PNG_FILES) / sizeof(NAME_OF_PNG_FILES[0]);

const sf::Vector2f textureSize(200.0f, 100.0f);