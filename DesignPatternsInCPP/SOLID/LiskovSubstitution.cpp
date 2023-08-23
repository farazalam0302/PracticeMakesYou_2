#include <bits/stdc++.h>
using namespace std;

class Rectangle {
protected:
  int width, height;

public:
  Rectangle(int width, int height) : width(width), height(height) {}
  int getWidth() const { return width; }
  int getHeight() const { return height; }
  virtual void setWidth(int w) { Rectangle::width = w; }
  virtual void setHeight(int h) { Rectangle::height = h; }
  int area() const { return (width * height); }
};

class Square : public Rectangle {

public:
  Square(int size) : Rectangle(size, size) {}
  void setWidth(int width) override {
    this->width = width;
    this->height = width;
  }
  void setHeight(int height) override {
    this->width = height;
    this->height = height;
  }
};

void process(Rectangle &r) {
  int w = r.getWidth();
  r.setHeight(10);
  cout << "Expected Area = " << (w * 10) << " , got " << r.area() << endl;
}


/*
struct RectangleFactory{
    static Rectangle createRectangle(int w, int h);
    static Rectangle createSquare(int size);
}
*/

int main(int argc, char const *argv[]) {
  /* code */
  Rectangle r{3, 4};
  process(r);
  Square s{5};
  process(s);

  return 0;
}
