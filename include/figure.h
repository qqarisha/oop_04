#ifndef FIGURE_H
#define FIGURE_H

#include "point.h"
#include <memory>
#include <vector>
#include <iostream>

template<Scalar T>
class Figure {
public:
    virtual ~Figure() = default;
    
    virtual Point<T> geometricCenter() const = 0;
    virtual double area() const = 0;
    virtual operator double() const { return area(); }
    
    virtual bool operator==(const Figure& other) const = 0;
    virtual Figure& operator=(const Figure& other) = 0;
    
    virtual void printPoints(std::ostream& os) const = 0;
    virtual std::vector<std::unique_ptr<Point<T>>> getPoints() const = 0;
    
    friend std::ostream& operator<<(std::ostream& os, const Figure& fig) {
        os << "Geometric center: " << fig.geometricCenter() << ", Area: " << fig.area();
        fig.printPoints(os);
        return os;
    }
};

#endif