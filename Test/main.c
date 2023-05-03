#include <stdio.h>
#include <stdlib.h>

typedef struct Point {
    int x;
    int y;
    void (*setX)(struct Point*, int);
    void (*setY)(struct Point*, int);
} Point;

void setX(Point* this, int x) {
    this->x = x;
}

void setY(Point* this, int y) {
    this->y = y;
}

void constructor(Point* this, int x, int y) {
    this->x = x;
    this->y = y;
    this->setX = setX;
    this->setY = setY;
}

void destructor(Point* this) {
    
    // free(this);
}

void destructor2(Point* this){
    free(this);
}


int main() {
    Point p;
    constructor(&p, 5, 10);

    Point* p2 = (Point*)malloc(sizeof(Point));
    constructor(p2,3,3);

    printf("(%d, %d)\n", p.x, p.y); // prints (5, 10)

    destructor(&p);
    destructor2(p2);

    return 0;
}
