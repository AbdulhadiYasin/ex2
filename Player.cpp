//
//  Player.cpp
//  mtmchkin
//
//  Created by Abdul Hadi Yasin on 04/05/2022.
//

#include <stdio.h>
#include "utilities.h"
#include "Player.h"

#define MAX_LEVEL 10

Player::Player(char* name, int maxHp, int force){
    this->name = name;
    this->maxHp = maxHp;
    this->health = maxHp;
    this->force = force;
    this->coins = 0;
    this->level = 0;
}

void Player::addCoins(int amount){
    this->coins += amount;
}

bool Player::pay(int price){
    if(this->coins < price)
        return false;
    
    this->coins -= price;
    return true;
}

void Player::heal(int hp){
    if(hp <= 0)
        // Increasing health by zero, or a negative hp isn't allowed.
        return;
    
    if(this->health + hp > this->maxHp)
        // Adding hp points, will exceed maxmimum hp, add only up to max.
        this->health = this->maxHp;
    else
        this->health += hp;
}

void Player::damage(int hp){
    if(hp <= 0)
        // Decreasing health by zero, or a negative hp isn't allowed.
        return;
    if(this->health < hp)
        this->health = 0;
    else
        this->health -= hp;
}

void Player::buff(int force){
    this->force += force;
}

int Player::getAttackStrength() const {
    return this->force + this->level;
}

bool Player::isKnockedOut() const {
    return this->health <= 0;
}

void Player::levelUp(){
    if(this->level >= MAX_LEVEL)
        // Level is already at maximum.
        return;
    this->level += 1;
}

int Player::getLevel() const {
    return this->level;
}

void Player::printInfo() const {
    printPlayerInfo(this->name, this->level, this->force, this->health, this->coins);
}
