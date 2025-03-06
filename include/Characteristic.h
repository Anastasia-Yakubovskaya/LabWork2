#ifndef CHARACTERISTIC_H
#define CHARACTERISTIC_H

#include <string>

class Characteristic {
public:
    std::string type; // Тип характеристики

    Characteristic(const std::string& type);
    void applyEffect();
};

#endif
