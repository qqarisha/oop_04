#include <iostream>
#include <memory>
#include <limits>
#include "../include/point.h"
#include "../include/figure.h"
#include "../include/hexagon.h"
#include "../include/octagon.h"
#include "../include/triangle.h"
#include "../include/array.h"

template<Scalar T>
void printFiguresInfo(const Array<std::shared_ptr<Figure<T>>>& figures) {
    std::cout << "\n Figures Information " << std::endl;
    double total_area = 0.0;
    
    for (size_t i = 0; i < figures.size(); ++i) {
        std::cout << "Figure " << i + 1 << ": " << *figures[i] << std::endl;
        total_area += figures[i]->area();
    }
    
    std::cout << "Total area: " << total_area << std::endl;
}

template<Scalar T>
void addHexagon(Array<std::shared_ptr<Figure<T>>>& figures) {
    T x, y, side;
    std::cout << "Enter center coordinates (x y): ";
    std::cin >> x >> y;
    std::cout << "Enter side length: ";
    std::cin >> side;
    
    Point<T> center(x, y);
    auto hexagon = std::make_shared<Hexagon<T>>(center, side);
    figures.push_back(hexagon);
    std::cout << "Hexagon added successfully!" << std::endl;
}

template<Scalar T>
void addOctagon(Array<std::shared_ptr<Figure<T>>>& figures) {
    T x, y, side;
    std::cout << "Enter center coordinates (x y): ";
    std::cin >> x >> y;
    std::cout << "Enter side length: ";
    std::cin >> side;
    
    Point<T> center(x, y);
    auto octagon = std::make_shared<Octagon<T>>(center, side);
    figures.push_back(octagon);
    std::cout << "Octagon added successfully!" << std::endl;
}

template<Scalar T>
void addTriangle(Array<std::shared_ptr<Figure<T>>>& figures) {
    T x, y, side;
    std::cout << "Enter center coordinates (x y): ";
    std::cin >> x >> y;
    std::cout << "Enter side length: ";
    std::cin >> side;
    
    Point<T> center(x, y);
    auto triangle = std::make_shared<Triangle<T>>(center, side);
    figures.push_back(triangle);
    std::cout << "Triangle added successfully!" << std::endl;
}

template<Scalar T>
void removeFigure(Array<std::shared_ptr<Figure<T>>>& figures) {
    if (figures.empty()) {
        std::cout << "No figures to remove!" << std::endl;
        return;
    }
    
    size_t index;
    std::cout << "Enter figure index to remove (1-" << figures.size() << "): ";
    std::cin >> index;
    
    if (index < 1 || index > figures.size()) {
        std::cout << "Incorrect index!" << std::endl;
        return;
    }
    
    figures.remove(index - 1);
    std::cout << "Figure removed successfully!" << std::endl;
}

void quickTemplateDemo() {
    std::cout << "\n Template Quick Demo " << std::endl;
    
    Array<Hexagon<double>> hexagons;
    hexagons.push_back(Hexagon<double>(Point<double>(0,0), 5.0));
    std::cout << "Created Array<Hexagon> with " << hexagons.size() << " elements" << std::endl;
    
    Array<Figure<double>*> fig_pointers;
    std::cout << "Created Array<Figure*> with " << fig_pointers.size() << " elements" << std::endl;
}

int main() {
    quickTemplateDemo();

    Array<std::shared_ptr<Figure<double>>> figures;
    
    std::cout << " Figure Management System " << std::endl;
    
    while (true) {
        std::cout << "\nMenu:" << std::endl;
        std::cout << "1. Add Hexagon" << std::endl;
        std::cout << "2. Add Octagon" << std::endl;
        std::cout << "3. Add Triangle" << std::endl;
        std::cout << "4. Show all figures" << std::endl;
        std::cout << "5. Remove figure" << std::endl;
        std::cout << "6. Exit" << std::endl;
        std::cout << "Choose option: ";
        
        int choice;
        std::cin >> choice;
        
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Incorrect input! Please enter a number." << std::endl;
            continue;
        }
        
        switch (choice) {
            case 1:
                addHexagon(figures);
                break;
            case 2:
                addOctagon(figures);
                break;
            case 3:
                addTriangle(figures);
                break;
            case 4:
                printFiguresInfo(figures);
                break;
            case 5:
                removeFigure(figures);
                break;
            case 6:
                std::cout << "bye bye!" << std::endl;
                return 0;
            default:
                std::cout << "Incorrect choice! Please try again." << std::endl;
        }
    }
    
    return 0;
}

