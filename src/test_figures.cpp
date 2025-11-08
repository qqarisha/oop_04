#include <gtest/gtest.h>
#include <memory>
#include "point.h"
#include "hexagon.h"
#include "octagon.h"
#include "triangle.h"

TEST(PointTest, BasicOperations) {
    Point<int> p1(1, 2);
    Point<int> p2(1, 2);
    Point<int> p3(3, 4);
    
    EXPECT_EQ(p1, p2);
    EXPECT_NE(p1, p3);
    EXPECT_EQ(p1.x(), 1);
    EXPECT_EQ(p1.y(), 2);
}

TEST(HexagonTest, AreaCalculation) {
    Point<double> center(0, 0);
    Hexagon<double> hex(center, 1.0);
    
    EXPECT_NEAR(hex.area(), 2.598, 0.001);
    EXPECT_EQ(hex.geometricCenter(), center);
}

TEST(OctagonTest, AreaCalculation) {
    Point<double> center(0, 0);
    Octagon<double> oct(center, 1.0);
    
    EXPECT_NEAR(oct.area(), 4.828, 0.001);
    EXPECT_EQ(oct.geometricCenter(), center);
}

TEST(TriangleTest, AreaCalculation) {
    Point<double> center(0, 0);
    Triangle<double> tri(center, 1.0);
    
    EXPECT_NEAR(tri.area(), 0.433, 0.001);
    EXPECT_EQ(tri.geometricCenter(), center);
}

TEST(FigureTest, DoubleConversion) {
    Triangle<double> tri(Point<double>(0, 0), 2.0);
    double area = static_cast<double>(tri);
    EXPECT_NEAR(area, 1.732, 0.001);
}