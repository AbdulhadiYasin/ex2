//
//  Mtmchkin.cpp
//  mtmchkin
//
//  Created by Abdul Hadi Yasin on 04/05/2022.
//

#include "Mtmchkin.h"
#include "Player.h"

Mtmchkin::Mtmchkin(const char* playerName, const Card* cardsArray, int numOfCards) : m_status(GameStatus::MidGame), m_player(playerName), m_numberOfCards(numOfCards), m_cards(new Card[numOfCards]), m_cardIndex(0) {

    for (int i = 0; i < numOfCards; i++) {
        m_cards[i] = cardsArray[i];
    }
}

Mtmchkin::~Mtmchkin() {
    delete[] m_cards;
}

void Mtmchkin::playNextCard() {
    if (m_numberOfCards == 0)
        return;

    if (m_cardIndex >= m_numberOfCards)
        m_cardIndex = 0;

    Card card = m_cards[m_cardIndex];
    m_cardIndex += 1;
    card.printInfo();

    card.applyEncounter(m_player);
    m_player.printInfo();

    if (m_player.getLevel() >= 10)
        m_status = GameStatus::Win;
    else if (m_player.isKnockedOut())
        m_status = GameStatus::Loss;
}

bool Mtmchkin::isOver() const {
    return m_status == GameStatus::Win || m_status == GameStatus::Loss;
}

GameStatus Mtmchkin::getGameStatus() const {
    return m_status;
}
