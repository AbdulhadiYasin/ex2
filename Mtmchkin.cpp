#ifndef EX2_GAME_H
#define EX2_GAME_H
#include "Card.h"
#include <iostream>
#include "Mtmchkin.h"
#include "Player.h"


Mtmchkin::Mtmchkin(const char* playerName, const Card* cardsArray, int numOfCards){
	m_player = playerName;
	m_cards = cardsArray;
	m_numberOfCards = numOfCards;
	m_cardIndex = 0;
	m_status = GameStatus::MidGame;
}


void playNextCard() {
	if (m_numberOfCards == 0)
		return;

	if (m_cardIndex >= m_numberOfCards)
		m_cardInndex = 0;

	Card temp = m_cards[m_cardIndex];
	temp.printInfo();
	m_cardIndex += 1;


	temp.applyEncounter(m_player);
	m_player.printInfo();


	if (m_player.getLevel() >= 10)
		m_status = GameStatus::Win;

	if (m_player.isKnockedOut())
		m_status = GameStatus::Loss;


}

bool isOver() {
	if (m_status == Win || m_status == Loss)
		return true;
	return false;
}

GameStatus getGameStatus() const {
	return m_status;
}
