#ifndef CARD_H
#define CARD_H

#include <string>
#include "characteristic.h"

class Card {
public:
    std::string name;
    std::string description;

    Card(const std::string& name, const std::string& description);
    virtual void play(int& score, const Characteristic& characteristic);
    virtual ~Card() = default;
};

class ConstructionCard : public Card {
public:
    std::string type;
    int scoreChange;

    ConstructionCard(const std::string& type, int scoreChange);
    void play(int& score, const Characteristic& characteristic) override;
};

class EventCard : public Card {
public:
    std::string effect;

    EventCard(const std::string& name, const std::string& description, const std::string& effect);
    void play(int& score, const Characteristic& characteristic) override;
};

class NaturalDisaster : public EventCard {
public:
    std::string type;
    int damage;

    NaturalDisaster(const std::string& type, int damage);
    void trigger(Board& board, int& score, const Characteristic& characteristic, const std::string& playerPrefix);
};

class EconomicEvent : public EventCard {
public:
    std::string type;
    std::string impact;

    EconomicEvent(const std::string& type, const std::string& impact);
    void trigger(int& score, const Characteristic& characteristic);
};

class PoliticalEvent : public EventCard {
public:
    std::string type;
    std::string impact;

    PoliticalEvent(const std::string& type, const std::string& impact);
    void trigger(Board& board, int& score, const Characteristic& characteristic, const std::string& playerPrefix);
};

class BonusCard : public Card {
public:
    std::string bonusType;

    BonusCard(const std::string& name, const std::string& description, const std::string& bonusType);
    void play(int& score, const Characteristic& characteristic) override;
};

class VarEvent : public BonusCard {
public:
    PlayerBase* target;
    int damage;

    VarEvent(const std::string& name, const std::string& description, PlayerBase* target, int damage);
    void trigger();
};

class StealCardEvent : public BonusCard {
public:
    PlayerBase* target;
    Card* stolenCard;

    StealCardEvent(const std::string& name, const std::string& description, PlayerBase* target);
    void trigger(Board& board, PlayerBase* currentPlayer);
};

class TradeEvent : public BonusCard {
public:
    PlayerBase* target;
    std::string resource;

    TradeEvent(const std::string& name, const std::string& description, PlayerBase* target, const std::string& resource);
    void trigger(Board& board);
};

#endif // CARD_H
