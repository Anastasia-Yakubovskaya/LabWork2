#include <gtest/gtest.h>
#include "cell.h"

TEST(CellTest, PlaceObject) {
    Cell cell;
    cell.place("House1", 30);
    EXPECT_TRUE(cell.isOccupied);
    EXPECT_EQ(cell.content, "House1");
    EXPECT_EQ(cell.health, 30);
}

TEST(CellTest, TakeDamage) {
    Cell cell;
    cell.place("House1", 30);
    cell.takeDamage(10);
    EXPECT_EQ(cell.health, 20);
    cell.takeDamage(20);
    EXPECT_FALSE(cell.isOccupied);
    EXPECT_EQ(cell.content, "*");
}
