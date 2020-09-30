#pragma once

#include <string>
#include <iostream>

class Player;
class Map;

class MoveManager final {
public:
    enum class Direction {Up, Down, Left, Right};
    
    MoveManager(std::shared_ptr<Player>& player, std::shared_ptr<Map>& map);
    ~MoveManager() = default;
    
    void processInputAndMove(const std::string& inputStr);
    
private:
    bool checkMove(Direction dir) const;
    
    std::shared_ptr<Map> m_map;
    std::shared_ptr<Player> m_player;
};

class Player final {
public:
    Player() = default;
    ~Player() = default;
    
    void movePlayer(MoveManager::Direction dir);
    char getIdentifier() const;
    size_t posX() const;
    size_t posY() const;

private:
    size_t m_posX{0};
    size_t m_posY{0};
};

#include "Map.h"