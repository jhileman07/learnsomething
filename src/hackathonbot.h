//
// Created by Ethan on 9/13/2023.
//

#include <vector>
#include "action.h"

#ifndef LEARNSOMETHING_HACKATHONBOT_H
#define LEARNSOMETHING_HACKATHONBOT_H

class HackathonBot {
public:
    HackathonBot();
    void takeAction(float price);
    double getBalance();
    bool isHolding();
private:
    double balance;
    bool holding=0;
    int upStreak=0;
    int downStreak=0;
    void buy();
    void sell();
    std::vector<float> q;
};

#endif //LEARNSOMETHING_HACKATHONBOT_H
