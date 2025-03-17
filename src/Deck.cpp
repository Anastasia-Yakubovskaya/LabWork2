#include "deck.h"
#include <random>
#include <algorithm>
#include <iostream>
#include "ConstructionCard.h"  
#include "NaturalDisaster.h"   
#include "EconomicEvent.h"    
#include "PoliticalEvent.h"    
#include "VarEvent.h"          
#include "TradeEvent.h"      
#include "StealCardEvent.h" 

void Deck::addCard(Card* card) {
    if (dynamic_cast<ConstructionCard*>(card)) {
        constructionCards.push_back(card);
    } else if (dynamic_cast<EventCard*>(card)) {
        eventCards.push_back(card);
    } else if (dynamic_cast<BonusCard*>(card)) {
        bonusCards.push_back(card);
    }
}

void Deck::shuffle() {
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(constructionCards.begin(), constructionCards.end(), g);
    std::shuffle(eventCards.begin(), eventCards.end(), g);
    std::shuffle(bonusCards.begin(), bonusCards.end(), g);
    std::cout << "Deck shuffled!\n";
}

Card* Deck::drawConstructionCard() {
    if (constructionCards.empty()) {
        std::cout << "No more construction cards left!\n";
        return nullptr;
    }
    Card* card = constructionCards.back();
    constructionCards.pop_back();
    return card;
}

Card* Deck::drawEventCard() {
    if (eventCards.empty()) {
        std::cout << "No more event cards left!\n";
        return nullptr;
    }
    Card* card = eventCards.back();
    eventCards.pop_back();
    return card;
}

Card* Deck::drawBonusCard() {
    if (bonusCards.empty()) {
        std::cout << "No more bonus cards left!\n";
        return nullptr;
    }
    Card* card = bonusCards.back();
    bonusCards.pop_back();
    return card;
}

size_t Deck::getRemainingCards() const {
    return constructionCards.size() + eventCards.size() + bonusCards.size();
}

bool Deck::isAnyDeckEmpty() const {
    return constructionCards.empty() || eventCards.empty() || bonusCards.empty();
}

Deck::~Deck() {
    for (Card* card : constructionCards) {
        delete card;
    }
    for (Card* card : eventCards) {
        delete card;
    }
    for (Card* card : bonusCards) {
        delete card;
    }
}
