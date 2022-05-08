#ifndef EX2_Card_H
#define EX2_Card_H

#include <string>
#include "Player.h"
#include "utilities.h"

Card::Card(CardType type, const CardStats& stats){
    this->m_effect = type;
    this->m_stats = stats;
    m_effect = type;
    m_stats = stats;
}


void applyEncounter(Player& player) const {


}


void printInfo() const {

}
