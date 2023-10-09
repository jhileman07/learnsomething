#include <gtest/gtest.h>
#include "pricingutil.h"


TEST(sampleTest, sample) {
    EXPECT_EQ(4, 4);
}

TEST(basicTest, basicSample) {
    PricingUtil pricingUtil;
    float prevPrice = 2;
    float interest = 0.1;
    float oleoConstant = 3;
    float ans = pricingUtil.calcVal(prevPrice, interest, oleoConstant);
    EXPECT_EQ(ans, 6);
}

TEST(basicTest, basicSample2) {
    PricingUtil pricingUtil;
    EXPECT_NEAR(pricingUtil.calcVal(4, 0.03, 5), 18.6, 1e-4);
}

TEST(basicTest, basicSample3) {
    PricingUtil pricingUtil;
    pricingUtil.calcVal(18.04, 0.1, 1);
    EXPECT_NEAR(pricingUtil.getVal(), 18.04, 1e-4);
}

TEST(edgeCases, zeroInterest) {
    PricingUtil pricingUtil;
    EXPECT_NEAR(pricingUtil.calcVal(4, 0, 2), 7.2, 1e-4);
}

TEST(edgeCases, negPrevPrice) {
    PricingUtil pricingUtil;
    EXPECT_NEAR(pricingUtil.calcVal(-2, 0.1, 1), -2, 1e-4);
}