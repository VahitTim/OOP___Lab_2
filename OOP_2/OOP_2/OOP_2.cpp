#include <iostream>
#include <conio.h>

using namespace std;

class Point {

protected:
    int x, y;

public:        
    Point() {
        printf("Point()\n");
        x = 0;
        y = 0;
    }

    Point(int x, int y) {
        printf("Point(int x, int y)\n");
        this->x = x;
        this->y = y;
    }

    Point(const Point &p) {
        printf("Point(const Point &p)\n");
        x = p.x;
        y = p.y;
    }

    ~Point() {
        printf("%d, %d\n", x, y);
        printf("~Point()\n");
    }

    void move(int dx, int dy) {
        x += dx;
        y += dy;
    }

    void reset();
};

void Point::reset() {
    x = 0;
    y = 0;
}

class ColoredPoint: public Point {

protected:
    int color;

public:
    ColoredPoint() : Point() {
        printf("ColoredPoint()\n");
        color = 0;
    }

    ColoredPoint(int x, int y, int color) : Point(x,y) {
        printf("ColoredPoint(int x, int y)\n");
        this->color = color;     
    }

    ColoredPoint(const ColoredPoint &p) {
        printf("ColoredPoint(const Point &p)\n");
        x = p.x;
        y = p.y;
        color = p.color;
    }

    ~ColoredPoint() {
        printf("%d, %d, color = %d\n", x, y, color);
        printf("~ColoredPoint()\n");
    }

    void change_color(int new_color) {
        color = new_color;
    }
};

class SpatialPoint {
protected:
    int x, y, z;

public:
    SpatialPoint() : x{ 0 }, y{ 0 }, z{ 0 } {
        printf("SpatialPoint()\n");
    }

    SpatialPoint(int m_x, int m_y, int m_z) : x{ m_x }, y{ m_y }, z{ m_z } {
        printf("SpatialPoint(int x, int y, int z)\n");     
    }

    SpatialPoint(const SpatialPoint& p) {
        printf("SpatialPoint(const SpatialPoint &p)\n");
        x = p.x;
        y = p.y;
        z = p.z;
    }

    ~SpatialPoint() {
        printf("%d, %d, %d\n", x, y, z);
        printf("~SpatialPoint()\n");
    }
};

class Section {

protected:
    Point* p1;
    Point* p2;

public:
    Section() {
        printf("Section()\n");
        p1 = new Point;
        p2 = new Point;
    }

    Section(int x1, int y1, int x2, int y2) {
        printf("Section(int x1, int y1, int x2, int y2)\n");
        p1 = new Point(x1, y1);
        p2 = new Point(x2, y2);
    }

    Section(const Section& s) {
        printf("Section(const Section &s)\n");
        p1 = new Point(*s.p1);
        p2 = new Point(*s.p2);
        //p1 = s.p1;
        //p2 = s.p2;
    }

    ~Section() {
        delete p1;
        delete p2;
        printf("~Section()\n");
    }
};

class DopSection {

protected:
    Point p1;
    Point p2;

public:
    DopSection() : p1{}, p2{} {
        printf("DopSection()\n");     
    }

    DopSection(int x1, int y1, int x2, int y2) : p1{x1, y1 }, p2{x2, y2} {
        printf("DopSection(int x1, int y1, int x2, int y2)\n");
;    }

    DopSection(const DopSection& s) {
        printf("DopSection(const DopSection &s)\n");
        p1 = s.p1;
        p2 = s.p2;
    }

    ~DopSection() {
        printf("~DopSection()\n");
    }
};

int main()
{
    DopSection* s1 = new DopSection;
    DopSection* s2 = new DopSection(1,2,3,4);
    DopSection* s3 = new DopSection(*s2);

    delete s1;
    delete s2;
    delete s3;

    _getch();
}
