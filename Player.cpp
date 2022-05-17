//
//  Player.cpp
//  mtmchkin
//
//  Created by Abdul Hadi Yasin on 04/05/2022.
//

#include "utilities.h"
#include "Player.h"

#define MAX_LEVEL 10

Player::Player(const std::string name, int maxHp, int force) : m_name(name), m_maxHp(maxHp), m_health(maxHp), m_force(force), m_coins(0), m_level(1) {
}

void Player::addCoins(int amount) {
    m_coins += amount;
}

bool Player::pay(int price) {
    if (m_coins < price)
        return false;

    m_coins -= price;
    return true;
}

void Player::heal(int hp) {
    if (hp <= 0)
        // Increasing health by zero, or a negative hp isn't allowed.
        return;

    if (m_health + hp >= m_maxHp)
        // Adding hp points, will exceed maxmimum hp, add only up to max.
        m_health = m_maxHp;
    else
        m_health += hp;
}

void Player::damage(int hp) {
    if (hp <= 0)
        // Decreasing health by zero, or a negative hp isn't allowed.
        return;

    if (m_health <= hp)
        m_health = 0;
    else
        m_health -= hp;
}

void Player::buff(int force) {
    m_force += force;
}

int Player::getAttackStrength() const {
    return m_force + m_level;
}

bool Player::isKnockedOut() const {
    return m_health <= 0;
}

void Player::levelUp() {
    if (m_level >= MAX_LEVEL)
        // Level is already at maximum.
        return;
    m_level += 1;
}

int Player::getLevel() const {
    return m_level;
}

void Player::printInfo() const {
    printPlayerInfo(m_name.c_str(), m_level, m_force, m_health, m_coins);
}
