#include "MoveManager.h"

MoveManager::MoveManager(std::shared_ptr<Player>& player, std::shared_ptr<Map>& map) {
    m_player = player;
    m_map = map;
}

bool MoveManager::checkMove(Direction dir) const {
    if (dir == Direction::Down && m_player->posY() < m_map->height() - 1)
        return true;
    if (dir == Direction::Up && m_player->posY() > 0)
        return true;
    if (dir == Direction::Right && m_player->posX() < m_map->width() - 1)
        return true;
    if (dir == Direction::Left && m_player->posX() > 0)
        return true;
    return false;
}

void MoveManager::processInputAndMove(const std::string& inputStr) {
    if (inputStr == static_cast<std::string>("u")) {
        if (checkMove(Direction::Up))
            m_player->movePlayer(Direction::Up);
        else
            std::cout << "Invalid direction\n";
        m_map->outputMap();
        return;
    }
    if (inputStr == static_cast<std::string>("d")) {
        if (checkMove(Direction::Down))
            m_player->movePlayer(Direction::Down);
        else
            std::cout << "Invalid direction\n";
        m_map->outputMap();
        return;
    }
    if (inputStr == static_cast<std::string>("l")) {
        if (checkMove(Direction::Left))
            m_player->movePlayer(Direction::Left);
        else
            std::cout << "Invalid direction\n";
        m_map->outputMap();
        return;
    }
    if (inputStr == static_cast<std::string>("r")) {
        if (checkMove(Direction::Right))
            m_player->movePlayer(Direction::Right);
        else
            std::cout << "Invalid direction\n";
        m_map->outputMap();
        return;
    }
    std::cout << "Invalid input\n";
    m_map->outputMap();
}
