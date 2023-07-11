
#include <iostream>
#include "MovingAverageFilter.hpp"


int main(){
    mtrn3100::MovingAverageFilter<float, 3> maf;
    for(float i = 0; i < 1000; i++){
        float input;

        std::cout << "Enter Value: ";
        std::cin >> input;
        maf.sample(input);
        if( i < maf.capacity() ){
        //the filter output won't be valid until the sum buffer is full
            printf("filter not full\n");
        } else {
            const auto value = maf.average();
            printf("Running filter value is %0.3f\n", value);
        }
    }

    return 0;
}

/*
TEST_CASE("Empty buffer") {
    mtrn3100::MovingAverageFilter<int, 10> maf;
    CHECK_EQ(maf.isEmpty(), true);
    CHECK_EQ(maf.isFull(), false);
    CHECK_EQ(maf.size(), 0);
    CHECK_EQ(maf.capacity(), 10);
}

TEST_CASE("Partially-full buffer") {
    mtrn3100::MovingAverageFilter<int, 10> maf;
    maf.sample(3);
    maf.sample(3);
    maf.sample(3);
    CHECK_EQ(maf.isEmpty(), false);
    CHECK_EQ(maf.isFull(), false);
    CHECK_EQ(maf.size(), 3);
    CHECK_EQ(maf.capacity(), 10);
    CHECK_EQ(maf.average(), 3);
}

TEST_CASE("Full buffer") {
    mtrn3100::MovingAverageFilter<float, 3> maf;
    maf.sample(3);
    maf.sample(5);
    maf.sample(6);
    CHECK_EQ(maf.isEmpty(), false);
    CHECK_EQ(maf.isFull(), true);
    CHECK_EQ(maf.size(), 3);
    CHECK_EQ(maf.capacity(), 3);
    CHECK_EQ(maf.average(), doctest::Approx(4.66).epsilon(0.1));
} 

TEST_CASE("Overly-full buffer") {
    mtrn3100::MovingAverageFilter<int, 3> maf;
    maf.sample(3);
    maf.sample(3);
    maf.sample(6);
    maf.sample(6);
    CHECK_EQ(maf.isEmpty(), false);
    CHECK_EQ(maf.isFull(), true);
    CHECK_EQ(maf.size(), 3);
    CHECK_EQ(maf.capacity(), 3);
    CHECK_EQ(maf.average(), 5);
}

TEST_CASE("Cleared buffer") {
    mtrn3100::MovingAverageFilter<int, 3> maf;
    maf.sample(3);
    maf.sample(3);
    maf.sample(6);
    REQUIRE_EQ(maf.isEmpty(), false);
    REQUIRE_EQ(maf.isFull(), true);
    REQUIRE_EQ(maf.size(), 3);
    REQUIRE_EQ(maf.capacity(), 3);
    REQUIRE_EQ(maf.average(), 4);
    maf.clear();
    CHECK_EQ(maf.isEmpty(), true);
    CHECK_EQ(maf.isFull(), false);
    CHECK_EQ(maf.size(), 0);
    CHECK_EQ(maf.capacity(), 3);
    CHECK_EQ(maf.average(), 0);
} */
