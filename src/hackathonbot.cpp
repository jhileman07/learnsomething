//
// Created by Ethan on 9/13/2023.
//

#include "hackathonbot.h"

HackathonBot::HackathonBot() {};

double HackathonBot::getBalance() {
  return this->balance;
};

bool HackathonBot::isHolding() {
  return this->holding;
};

void HackathonBot::buy() {
  this->holding = true;
}

void HackathonBot::sell() {
  this->q.clear();
  this->holding = false;
  this->upStreak=0;
  this->downStreak=0;
}


void HackathonBot::takeAction(float price) {
  // update up and down streaks 
  if (this->q.size() > 0) {
    // down streak
    if (price < this->q.back()) {
      this->downStreak++;
      this->upStreak=0;
    }
    // up streak
    else if (price > this->q.back()) {
      this->upStreak++;
      this->downStreak=0;
    }
  }
  // adding a new price to the queue
  this->q.push_back(price);

  // check streaks and price
  // selling
  if (this->upStreak >= 52 || this->downStreak >= 47) {
    this->sell();
    return;
  }
  // buying
  else if (!(this->isHolding())) {
    if (price < 52 || this->downStreak >= 5) {
      this->buy();
    }
    return;
  } 

  // checking percentages
  float percentage = price / this->q.front();
  if (percentage > 1.89 || percentage < 0.38) {
    this->sell();
    return;
  }

  // 10 series window
  if (this->q.size() > 10) {
    for (int i=0;i<11;i++) {
      float delta = this->q[i] / this->q.front();
      if (delta<0.95 || delta>1.05) {
        return;
      }
    }
    this->sell();
  }

  // 3 series window
  if (this->q.size() >= 3) {
    int length = this->q.size();

    float price1 = this->q[length-4];
    float price2 = this->q[length-3];
    float price3 = this->q[length-2];
    float delta1 = price2/price1;
    float delta2 = price3/price2;
    float delta3 = price/price3;
    float threeDelta = price/price1;
    float overallDelta = price/this->q.front();
    if (delta1>=1.2 && delta2>=0.85 && delta3>=1.3 && threeDelta>=1.5) {
      this->sell();
      return;
    }
    if (delta1>=0.85 && delta2>=1.15 && delta3<=0.75 && overallDelta<=0.55) {
      this->sell();
      return;
    }
  }
};
