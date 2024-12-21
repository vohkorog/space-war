#pragma once 
#include <SFML/Graphics.hpp>
#include <vector>

class ParallaxBackground {
private:
    std::vector<sf::Texture> m_textures;
    std::vector<sf::Sprite> m_sprites;
    std::vector<float> m_speeds; // Скорости для каждого слоя

public:
    ParallaxBackground(const std::vector<std::string>& textures, const std::vector<float>& speeds);

    void update(float offset);

    void render(sf::RenderWindow *window);
};
