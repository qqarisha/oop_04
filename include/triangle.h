#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "figure.h"
#include <cmath>

template<Scalar T>
class Triangle : public Figure<T> {
private:
    std::unique_ptr<Point<T>> center_;
    T side_length_;
    
    void calculatePoints(std::vector<std::unique_ptr<Point<T>>>& points) const {
        points.clear();
        for (int i = 0; i < 3; ++i) {
            double angle = 2 * M_PI * i / 3;
            T x = center_->x() + side_length_ * std::cos(angle);
            T y = center_->y() + side_length_ * std::sin(angle);
            points.push_back(std::make_unique<Point<T>>(x, y));
        }
    }

public:
    Triangle() : center_(std::make_unique<Point<T>>()), side_length_(0) {}
    
    Triangle(const Point<T>& center, T side_length) 
        : center_(std::make_unique<Point<T>>(center)), side_length_(side_length) {}
    
    Triangle(const Triangle& other) 
        : center_(std::make_unique<Point<T>>(*other.center_)), side_length_(other.side_length_) {}
    
    Triangle& operator=(const Triangle& other) {
        if (this != &other) {
            center_ = std::make_unique<Point<T>>(*other.center_);
            side_length_ = other.side_length_;
        }
        return *this;
    }
    
    bool operator==(const Figure<T>& other) const override {
        const Triangle* otherTri = dynamic_cast<const Triangle*>(&other);
        if (!otherTri) return false;
        return *center_ == *otherTri->center_ && side_length_ == otherTri->side_length_;
    }
    
    Figure<T>& operator=(const Figure<T>& other) override {
        const Triangle* otherTri = dynamic_cast<const Triangle*>(&other);
        if (otherTri) {
            *this = *otherTri;
        }
        return *this;
    }
    
    Point<T> geometricCenter() const override {
        return *center_;
    }
    
    double area() const override {
        return (std::sqrt(3) * side_length_ * side_length_) / 4.0;
    }
    
    void printPoints(std::ostream& os) const override {
        auto points = getPoints();
        os << "\nTriangle points: ";
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