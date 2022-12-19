#include <stdio.h>
#include "IShape.h"
#include "Circle.h"
#include "Rectangle.h"

int main() {
	IShape* shape;
	
	shape = new Circle(50);
	shape->size();
	shape->Draw();
	delete shape;

	shape = new RectAngle(5, 20);
	shape->size();
	shape->Draw();
	delete shape;
	shape = 0;

	return 0;
}