#pragma once

#include <iostream>
#include <string>
#include "FoodItem.h"

class AbstractWizard {
public:
    AbstractWizard();
    virtual std::string deductFoodType() {return "";}
};

class MightyWizard : public AbstractWizard {
public:
    MightyWizard(std::string name);

    void checkFood(FoodItem* food);
    void checkFood(FoodItem& food);

private:
    std::string deductFoodType(FoodItem item) {
        if (item.type == FoodType::ApplePie)
            return "Apple pie. ";
        if (item.type == FoodType::Sweetroll)
            return "Sweetroll. ";
        if (item.type == FoodType::HoneyNut)
            return "Honey nut. ";
        if (item.type == FoodType::PoisonedFood)
            return "Poison. ";
        return "<wtf>. ";
    }
    std::string m_name;
};

