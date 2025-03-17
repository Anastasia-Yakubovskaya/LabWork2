#include "playerbase.h"

PlayerBase::PlayerBase(const std::string& name, const Characteristic& characteristic)
    : name(name), score(0), characteristic(characteristic) {}
