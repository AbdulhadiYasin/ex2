#include "utilities.h"
#include "Card.h"

Card::Card(CardType type, const CardStats& stats){
    this->m_effect = type;
    this->m_stats = stats;
    m_effect = type;
    m_stats = stats;
}


void Card::applyEncounter(Player& player) const {
    switch (m_effect) {
        case CardType::Battle: {
            if(m_stats.force <= player.getAttackStrength()){
                player.addCoins(m_stats.loot);
                player.levelUp();
                printBattleResult(true);
            }
            else{
                player.damage(m_stats.hpLossOnDefeat);
                printBattleResult(false);
            }
            break;
        }
        case CardType::Treasure:{
            player.addCoins(m_stats.loot);
            break;
        }
        case CardType::Heal:{
            if(player.pay(m_stats.cost))
                player.heal(m_stats.heal);
            break;
        }
        case CardType::Buff:{
            if(player.pay(m_stats.cost))
                player.buff(m_stats.buff);
            break;
        }
        default:
            break;
    }

}


void Card::printInfo() const {
    switch (m_effect) {
        case CardType::Treasure:{
            printTreasureCardInfo(m_stats);
            break;
        }
        case CardType::Battle:{
            printBattleCardInfo(m_stats);
            break;
        }
        case CardType::Heal:{
            printHealCardInfo(m_stats);
            break;
        }
        case CardType::Buff:{
            printBuffCardInfo(m_stats);
            break;
        }
        default:
            break;
    }

}
