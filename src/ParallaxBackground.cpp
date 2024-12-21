#include "ParallaxBackground.hpp"

ParallaxBackground::ParallaxBackground(const std::vector<std::string>& textures, const std::vector<float>& speeds){
        this->m_speeds = speeds;
    
        for (const auto& texturePath : textures) {
            sf::Texture texture;
            texture.loadFromFile(texturePath);
            m_textures.push_back(texture);

            sf::Sprite sprite;
            sprite.setTexture(m_textures.back());
            m_sprites.push_back(sprite);
        }

        // Установка начальных позиций
        for (size_t i = 0; i < m_sprites.size(); ++i) {
            m_sprites[i].setPosition(0, i * 100); // Смещение для разных слоев
        }
}

void ParallaxBackground::update(float offset){
    for (size_t i = 0; i < m_sprites.size(); ++i) {
            // Двигаем спрайт с учетом скорости
            m_sprites[i].move(0, -offset * m_speeds[i]);

            // Если спрайт уходит за границы, возвращаем его
            if (m_sprites[i].getPosition().y <= -m_sprites[i].getGlobalBounds().height+750) {
                m_sprites[i].setPosition(0, i * 100); // Вернуться на начальную позицию
            }
        }

}

void ParallaxBackground::render(sf::RenderWindow *window){
    for (const auto& sprite : m_sprites) {
            window->draw(sprite);
        }
}