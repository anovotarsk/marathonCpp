#pragma once

enum class FoodType {
    ApplePie,
    Sweetroll,
    HoneyNut,
    PoisonedFood,
    Inwalid
};

class FoodItem {
public:
    FoodType type;

    FoodItem(FoodType t) : type(t){}
};

class ApplePie : public FoodItem {
public:
    ApplePie() : FoodItem(FoodType::ApplePie){};
};

class Sweetroll : public FoodItem {
public:
    Sweetroll() : FoodItem(FoodType::Sweetroll){};
};

class HoneyNut : public FoodItem {
public:
    HoneyNut() : FoodItem(FoodType::HoneyNut){};
};

class PoisonedFood : public FoodItem {
public:
    PoisonedFood() : FoodItem(FoodType::PoisonedFood){};
};
