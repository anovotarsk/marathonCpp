#include "FoodItem.h"
#include "MightyWizard.h"

MightyWizard::MightyWizard(std::string name) {
    m_name = name;
}

AbstractWizard::AbstractWizard(){}

void MightyWizard::checkFood(FoodItem* food) {
    if (food == nullptr) {
        std::cout << "<wtf>. Ugh, not again!\n";
        return;
    }
    std::string type = deductFoodType(*food);
    if (type == "Sweetroll. " || type == "Honey nut. ")
        std::cout << type << "Mmm, tasty!\n";
    else
        std::cout << type << "Ugh, not again!\n";
}

void MightyWizard::checkFood(FoodItem& food) {
    std::string type = deductFoodType(food);
    if (type == "Sweetroll. " || type == "Honey nut. ")
        std::cout << type << "Mmm, tasty!\n";
    else
        std::cout << type << "Ugh, not again!\n";
}
