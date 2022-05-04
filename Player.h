//
//  Player.h
//  mtmchkin
//
//  Created by Abdul Hadi Yasin on 04/05/2022.
//

#ifndef Player_h
#define Player_h

#include <string>
#include "utilities.h"

class Player {
public:
    /*
     * C'tor of Player class
     *
     * @param name - The name of the player.
     * @param maxHp - The maximum HP of the player, The default HP is 100.
     * @param force - The initial force of the player, The default force is 5 Points.
     * @return
     *      A new instance of Player.
    */
    Player(std::string name, int maxHp = 100, int force = 5);
    
    /*
     * Adds the said amount of coins to the receiver's `fortune`.
     *
     * @param amount - The amount of coins to add to player's fortune.
     * @return
     *      void
     */
    void addCoins(int amount);
    
    /*
     * deducts the said amount of coins out of the receiver's `fortune` if the
     * player can afford the transaction, othwerise does nothing.
     *
     * @param price - The amount (price) to deduct out of the player's fortune.
     * return
     *      `true` if transaction is valid the amount was deducted, otherwise `false`.
     */
    bool pay(int price);
    
    /*
     * Adds the said amount of health points to the receiver's `health` (hp).
     *
     * @param hp - The amount of health points to add to player's health (hp).
     * @return
     *      void
     */
    void heal(int hp);
    
    /*
     * deducts the said amount of health points out of the receiver's `health`
     * (hp).
     *
     * @param hp - The amount of health points to add to player's health (hp).
     * @return
     *      void
     */
    void damage(int hp);
    
    /*
     * Adds the said amount of force points to the receiver's `force`.
     *
     * @param force - The amount of force points to add to player's force.
     * @return
     *      void
     */
    void buff(int force);
    
    /*
     * Increases the receiver's (player) level by the one level, up to a maximum
     * level of level-10.
     *
     * @return
     *      void
     */
    void levelUp();
    
    /*
     * Returns current level of the receiver (player).
     *
     * @return
     *      The current level of the player.
     */
    int getLevel() const;
    
    /*
     * Returns attack strength of the receiver (player).
     *
     * @return
     *      The attack strength of the player.
     */
    int getAttackStrength() const;
    
    /*
     * Returns whether the receiver (player) is knocked out or not.
     *
     * @return
     *      `true` if player has been knocked out, otherwise `false`.
     */
    bool isKnockedOut() const;
    
    /*
     * Prints the player info:
     *
     * @return
     *      void
    */
    void printInfo() const;
private:
    std::string name;
    const int maxHp;
    int health;
    int force;
    int coins;
};

#endif /* Player_h */
