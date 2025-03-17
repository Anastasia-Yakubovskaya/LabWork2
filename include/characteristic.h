#ifndef CHARACTERISTIC_H
#define CHARACTERISTIC_H

#include <string>

class Characteristic {
public:
    std::string type;
    Characteristic(const std::string& type);
    void applyEffect(int& score, int change) const;
};

#endif // CHARACTERISTIC_H
