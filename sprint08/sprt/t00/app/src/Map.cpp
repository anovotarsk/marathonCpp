#include "Map.h"
#include "MoveManager.h"
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <memory>



Map::Map(size_t width, size_t height, std::shared_ptr<Player>& player) : m_width(width), m_height(height) {
    m_player = player;
    generateMap();
}

void Map::generateMap() {
    int rnd = rand() % 90;
    m_map = std::move(std::make_unique<char[]>(m_width * m_height));

    for (size_t i = 0; i < m_width * m_height; i++) {
        rnd = rand() % 100;
        if (rnd < 30)
            m_map[i] = '.';
        else {
            if (rnd < 60)
                m_map[i] = 'T';
            else
                m_map[i] = '@';
        }
    }
}

void Map::outputMap() const {
    size_t outed = 0;

    for (int i = 0; i < m_height; i++) {
        for (int j = 0; j < m_width; j++) {
            if (i == m_player->posY() && j == m_player->posX())
                std::cout << m_player->getIdentifier();
            else
                std::cout << m_map[outed + j];
            if (j != m_width - 1)
                std::cout << " ";
        }
        outed += m_width;
        std::cout << std::endl; 
    }
}

size_t Map::width() const {
    return m_width;
}

size_t Map::height() const {
    return m_height;
}
