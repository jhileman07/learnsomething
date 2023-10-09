#include "pricingutil.h"

PricingUtil::PricingUtil() : val(0.0) {};

float PricingUtil::calcVal(float prevPrice, float interest, float oleoConstant) {
  this->val = (prevPrice * (0.9f + interest) * oleoConstant);
  return this->val;
};

float PricingUtil::getVal() {
  return this->val;
};
