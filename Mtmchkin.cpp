
#include "Player.h"
#include "Mtmchkin.h"

Mtmchkin::Mtmchkin(const char* playerName, const Card* cardsArray, int numOfCards) : m_player(playerName) {
	m_cards = cardsArray;
	m_numberOfCards = numOfCards;
	m_cardIndex = 0;
	m_status = GameStatus::MidGame;
}


void Mtmchkin::playNextCard() {
	if (m_numberOfCards == 0)
		return;

	if (m_cardIndex >= m_numberOfCards)
		m_cardIndex = 0;

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

bool Mtmchkin::isOver() {
	if (m_status == GameStatus::Win || m_status == GameStatus::Loss)
		return true;
	return false;
}

GameStatus Mtmchkin::getGameStatus() const {
	return m_status;
}
