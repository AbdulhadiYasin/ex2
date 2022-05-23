//
//  HealthPoints.hpp
//  mtmchkin
//
//  Created by Abdul Hadi Yasin on 18/05/2022.
//

#ifndef HealthPoints_hpp
#define HealthPoints_hpp

#define DEFAULT_MAX_HEALTH 100

#include <stdio.h>
#include <iostream>
using namespace std;

class HealthPoints {
public:
    HealthPoints(int maxHealth = DEFAULT_MAX_HEALTH);
    HealthPoints& operator+=(const int rhs);
    bool operator==(const HealthPoints& rhs);
    bool operator!=(const HealthPoints& rhs);
    bool operator<(const HealthPoints& rhs);
    bool operator<=(const HealthPoints& rhs);
    bool operator>(const HealthPoints& rhs);
    bool operator>=(const HealthPoints& rhs);
    friend ostream& operator<<(ostream& os, const HealthPoints& dt);
private:
    int m_value = DEFAULT_MAX_HEALTH;
    int m_maxValue = DEFAULT_MAX_HEALTH;

};

HealthPoints operator+(HealthPoints& lhs, const int rhs);
HealthPoints operator+(const int lhs, HealthPoints& rhs);
HealthPoints operator-(HealthPoints& lhs, const int rhs);
HealthPoints& operator-=(HealthPoints& lhs, const int rhs);

ostream& operator<<(ostream& os, const HealthPoints& hp){
    os << hp.m_value << '(' << hp.m_maxValue << ')';
    return os;
}

#endif /* HealthPoints_hpp */
