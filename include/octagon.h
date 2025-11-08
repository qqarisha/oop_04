#ifndef OCTAGON_H
#define OCTAGON_H

#include "figure.h"
#include <cmath>

template<Scalar T>
class Octagon : public Figure<T> {
private:
    std::unique_ptr<Point<T>> center_;
    T side_length_;
    
    void calculatePoints(std::vector<std::unique_ptr<Point<T>>>& points) const {
        points.clear();
        for (int i = 0; i < 8; ++i) {
            double angle = 2 * M_PI * i / 8;
            T x = center_->x() + side_length_ * std::cos(angle);
            T y = center_->y() + side_length_ * std::sin(angle);
            points.push_back(std::make_unique<Point<T>>(x, y));
        }
    }

public:
    Octagon() : center_(std::make_unique<Point<T>>()), side_length_(0) {}
    
    Octagon(const Point<T>& center, T side_length) 
        : center_(std::make_unique<Point<T>>(center)), side_length_(side_length) {}
    
    Octagon(const Octagon& other) 
        : center_(std::make_unique<Point<T>>(*other.center_)), side_length_(other.side_length_) {}
    
    Octagon& operator=(const Octagon& other) {
        if (this != &other) {
            center_ = std::make_unique<Point<T>>(*other.center_);
            side_length_ = other.side_length_;
        }
        return *this;
    }
    
    bool operator==(const Figure<T>& other) const override {
        const Octagon* otherOct = dynamic_cast<const Octagon*>(&other);
        if (!otherOct) return false;
        return *center_ == *otherOct->center_ && side_length_ == otherOct->side_length_;
    }
    
    Figure<T>& operator=(const Figure<T>& other) override {
        const Octagon* otherOct = dynamic_cast<const Octagon*>(&other);
        if (otherOct) {
            *this = *otherOct;
        }
        return *this;
    }
    
    Point<T> geometricCenter() const override {
        return *center_;
    }
    
    double area() const override {
        return 2 * (1 + std::sqrt(2)) * side_length_ * side_length_;
    }
    
    void printPoints(std::ostream& os) const override {
        auto points = getPoints();
        os << "\nOctagon points: ";
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