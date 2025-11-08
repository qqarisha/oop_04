#ifndef POINT_H
#define POINT_H

#include <concepts>
#include <memory>
#include <cmath>
#include <iostream>

template<typename T>
concept Scalar = std::is_scalar_v<T>;

template<Scalar T>
class Point {
private:
    T x_, y_;

public:
    Point() : x_(0), y_(0) {}
    Point(T x, T y) : x_(x), y_(y) {}
    
    Point(const Point& other) : x_(other.x_), y_(other.y_) {}
    Point& operator=(const Point& other) {
        if (this != &other) {
            x_ = other.x_;
            y_ = other.y_;
        }
        return *this;
    }
    
    T x() const { return x_; }
    T y() const { return y_; }
    
    void setX(T x) { x_ = x; }
    void setY(T y) { y_ = y; }
    
    double distanceTo(const Point& other) const {
        return std::sqrt(std::pow(x_ - other.x_, 2) + std::pow(y_ - other.y_, 2));
    }
    
    bool operator==(const Point& other) const {
        return x_ == other.x_ && y_ == other.y_;
    }
    
    bool operator!=(const Point& other) const {
        return !(*this == other);
    }
    
    friend std::ostream& operator<<(std::ostream& os, const Point& point) {
        os << "(" << point.x_ << ", " << point.y_ << ")";
        return os;
    }
};

#endif