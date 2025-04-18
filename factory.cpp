#include <iostream>
#include <memory>
#include <string>
using namespace std;

// Step 1: Create an abstract base class (interface)
class Shape {
public:
    virtual void draw() = 0; // Pure virtual function
    virtual ~Shape() {}
};

// Step 2: Create concrete classes
class Circle : public Shape {
public:
    void draw() override {
        cout << "Drawing a Circle!" << endl;
    }
};

class Square : public Shape {
public:
    void draw() override {
        cout << "Drawing a Square!" << endl;
    }
};

class Rectangle : public Shape {
public:
    void draw() override {
        cout << "Drawing a Rectangle!" << endl;
    }
};

// Step 3: Create the Factory class
class ShapeFactory {
public:
    // Static method that returns a pointer to a Shape based on input
    static shared_ptr<Shape> createShape(const string& type) {
        if (type == "circle") {
            return make_shared<Circle>();
        } else if (type == "square") {
            return make_shared<Square>();
        } else if (type == "rectangle") {
            return make_shared<Rectangle>();
        } else {
            return nullptr;
        }
    }
};

// Step 4: Client code
int main() {
    shared_ptr<Shape> shape1 = ShapeFactory::createShape("circle");
    shared_ptr<Shape> shape2 = ShapeFactory::createShape("square");
    shared_ptr<Shape> shape3 = ShapeFactory::createShape("rectangle");
    shared_ptr<Shape> shape4 = ShapeFactory::createShape("triangle"); // Invalid

    if (shape1) shape1->draw();
    if (shape2) shape2->draw();
    if (shape3) shape3->draw();
    if (!shape4) cout << "Shape type not recognized!" << endl;

    return 0;
}
