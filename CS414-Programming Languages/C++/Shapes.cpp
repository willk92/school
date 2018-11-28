#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class ShapeImp {
  public:
    ShapeImp(int height, int width) {
        height_ = height;
        width_ = width;
    }
    virtual void tell() {
        cout << "Area is " << setw(2) << setfill(48) << height_ << width_ << endl;
    }
  protected:
    int height_, width_;
};

class SquareShapeImp: public ShapeImp {
  public:
    SquareShapeImp(int height, int width): ShapeImp(height, width) {

    }

    /* virtual */
    void tell() {
        cout << "time is " << height_ << ":" << width_ << endl;
    }
};

class TriangleShapeImp: public ShapeImp {
  public:
    TriangleShapeImp(int height, int width): ShapeImp(height, width) {

    }

    /* virtual */
    void tell() {
        cout << "time is " << height_ << width_  << endl;
    }
};

class CircleShapeImp: public ShapeImp {
  public:
    CircleShapeImp(int height, int width): ShapeImp(height, width) {

    }

    /* virtual */
    void tell() {
        cout << "time is " << height_ << width_ << endl;
    }
};

class Shape {
  public:
    Shape(){}
    Shape(int height, int width) {
        imp_ = new ShapeImp(height, width);
    }
    virtual void tell() {
        imp_->tell();
    }
  protected:
    ShapeImp *imp_;
};

class Square: public Shape {
  public:
    Square(int height, int width) {
        imp_ = new SquareShapeImp(height, width);
    }
};

class Triangle: public Shape {
  public:
    Triangle(int height, int width) {
        imp_ = new TriangleShapeImp(height, width);
    }
};

class Circle: public Shape {
  public:
    Circle(int height, int width) {
        imp_ = new CircleShapeImp(height, width);
    }
}

int main() {
  Shape *times[4];
  times[0] = new Shape(14, 30);
  times[1] = new SquareShape(2, 30);
  times[2] = new Triangle(14, 30);
  times[3] = new Circle(14, 20);
  for (int i = 0; i < 4; i++)
    times[i]->tell();
}