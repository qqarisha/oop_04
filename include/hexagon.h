#ifndef HEXAGON_H
#define HEXAGON_H

#include "figure.h"
#include <cmath>

template<Scalar T>
class Hexagon : public Figure<T> {
private:
    std::unique_ptr<Point<T>> center_;
    T side_length_;
    
    void calculatePoints(std::vector<std::unique_ptr<Point<T>>>& points) const {
        points.clear();
        for (int i = 0; i < 6; ++i) {
            double angle = 2 * M_PI * i / 6;
            T x = center_->x() + side_length_ * std::cos(angle);
            T y = center_->y() + side_length_ * std::sin(angle);
            points.push_back(std::make_unique<Point<T>>(x, y));
        }
    }

public:
    Hexagon() : center_(std::make_unique<Point<T>>()), side_length_(0) {}
    
    Hexagon(const Point<T>& center, T side_length) 
        : center_(std::make_unique<Point<T>>(center)), side_length_(side_length) {}
    
    Hexagon(const Hexagon& other) 
        : center_(std::make_unique<Point<T>>(*other.center_)), side_length_(other.side_length_) {}
    
    Hexagon& operator=(const Hexagon& other) {
        if (this != &other) {
            center_ = std::make_unique<Point<T>>(*other.center_);
            side_length_ = other.side_length_;
        }
        return *this;
    }
    
    bool operator==(const Figure<T>& other) const override {
        const Hexagon* otherHex = dynamic_cast<const Hexagon*>(&other);
        if (!otherHex) return false;
        return *center_ == *otherHex->center_ && side_length_ == otherHex->side_length_;
    }
    
    Figure<T>& operator=(const Figure<T>& other) override {
        const Hexagon* otherHex = dynamic_cast<const Hexagon*>(&other);
        if (otherHex) {
            *this = *otherHex;
        }
        return *this;
    }
    
    Point<T> geometricCenter() const override {
        return *center_;
    }
    
    double area() const override {
        return (3 * std::sqrt(3) * side_length_ * side_length_) / 2.0;
    }
    
    void printPoints(std::ostream& os) const override {
        auto points = getPoints();
        os << "\nHexagon points: ";
        for (const auto& point : points) {
            os << *point << " ";
        }
    }
    
    std::vector<std::unique_ptr<Point<T>>> getPoints() const override {
        std::vector<std::unique_ptr<Point<T>>> points;
        calculatePoints(points);
        return points;
    }
    
    T getSideLength() const { return side_length_; }
    Point<T> getCenter() const { return *center_; }
};

#endif