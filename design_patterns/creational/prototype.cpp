#include <iostream>
#include <memory>
#include <vector>

class Shape {
public:
    virtual ~Shape() = default;
    virtual std::unique_ptr<Shape> clone() const = 0;
};

class Rectangle : public Shape {
private:
    int width;
    int height;

public:
    Rectangle(int w, int h) : width(w), height(h) {}

    int getWidth() const {
        return width;
    }

    int getHeight() const {
        return height;
    }

    std::unique_ptr<Shape> clone() const override {
        return std::make_unique<Rectangle>(*this);
    }
};

class Square : public Shape {
private:
    int length;

public:
    Square(int l) : length(l) {}

    int getLength() const {
        return length;
    }

    std::unique_ptr<Shape> clone() const override {
        return std::make_unique<Square>(*this);
    }
};

class Test {
public:
    std::vector<std::unique_ptr<Shape>> cloneShapes(
        const std::vector<std::unique_ptr<Shape>>& shapes) {
        std::vector<std::unique_ptr<Shape>> clones;
        clones.reserve(shapes.size());

        for (const auto& shape : shapes) {
            clones.push_back(shape->clone());
        }
        return clones;
    }
};

int main() {
    std::vector<std::unique_ptr<Shape>> shapes;
    shapes.push_back(std::make_unique<Rectangle>(10, 5));
    shapes.push_back(std::make_unique<Square>(7));
    shapes.push_back(std::make_unique<Rectangle>(3, 8));

    Test test;
    std::vector<std::unique_ptr<Shape>> clonedShapes = test.cloneShapes(shapes);

    std::cout << "Original shapes:\n";
    for (const auto& shape : shapes) {
        if (const auto* rect = dynamic_cast<const Rectangle*>(shape.get())) {
            std::cout << "Rectangle: width = " << rect->getWidth()
                      << ", height = " << rect->getHeight() << '\n';
        } else if (const auto* sq = dynamic_cast<const Square*>(shape.get())) {
            std::cout << "Square: length = " << sq->getLength() << '\n';
        }
    }

    std::cout << "\nCloned shapes:\n";
    for (const auto& shape : clonedShapes) {
        if (const auto* rect = dynamic_cast<const Rectangle*>(shape.get())) {
            std::cout << "Rectangle: width = " << rect->getWidth()
                      << ", height = " << rect->getHeight() << '\n';
        } else if (const auto* sq = dynamic_cast<const Square*>(shape.get())) {
            std::cout << "Square: length = " << sq->getLength() << '\n';
        }
    }

    return 0;
}