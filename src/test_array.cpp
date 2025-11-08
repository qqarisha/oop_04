#include <gtest/gtest.h>
#include <memory>
#include "array.h"
#include "triangle.h"

TEST(ArrayTest, BasicOperations) {
    Array<int> arr;
    
    EXPECT_TRUE(arr.empty());
    EXPECT_EQ(arr.size(), 0);
    
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);
    
    EXPECT_EQ(arr.size(), 3);
    EXPECT_EQ(arr[0], 1);
    EXPECT_EQ(arr[1], 2);
    EXPECT_EQ(arr[2], 3);
}

TEST(ArrayTest, RemoveOperation) {
    Array<int> arr;
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);
    
    arr.remove(1);
    EXPECT_EQ(arr.size(), 2);
    EXPECT_EQ(arr[0], 1);
    EXPECT_EQ(arr[1], 3);
}

TEST(ArrayTest, FigureStorage) {
    Array<std::shared_ptr<Figure<double>>> figures;
    
    auto tri1 = std::make_shared<Triangle<double>>(Point<double>(0, 0), 2.0);
    auto tri2 = std::make_shared<Triangle<double>>(Point<double>(1, 1), 3.0);
    
    figures.push_back(tri1);
    figures.push_back(tri2);
    
    EXPECT_EQ(figures.size(), 2);
    EXPECT_EQ(figures[0]->geometricCenter(), Point<double>(0, 0));
    EXPECT_EQ(figures[1]->geometricCenter(), Point<double>(1, 1));
}

TEST(ArrayTest, MoveSemantics) {
    Array<int> arr1;
    arr1.push_back(1);
    arr1.push_back(2);
    
    Array<int> arr2 = std::move(arr1);
    EXPECT_EQ(arr1.size(), 0);
    EXPECT_EQ(arr2.size(), 2);
    EXPECT_EQ(arr2[0], 1);
    EXPECT_EQ(arr2[1], 2);
}