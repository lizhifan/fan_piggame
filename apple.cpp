#include "apple.h" 
#include "graphicwindow.h" 
#include <QGraphicsPixmapItem> 
#include <QPixmap> 
#include <iostream> 
#include <QtGui/QApplication> 
#include <cstdlib> 
#include <cmath> 
using namespace std; 
/*
@param pm is the the QPixmap or image that is associated with the Apple 
@param x is the x location of where the apple is to be created 
@param y is the y location of where the apple is to be created 
@param h is the graphicwindow that created the specific Apple*/ 
Apple::Apple(QPixmap * pm, int x, int y, GraphicWindow* h) : Thing(pm, x, y) {
 	y_ = y; 
 	x_ = x; 	
 	gr = h; 
} 

void Apple::move() {
 	y_ = y_;
 	x_ = x_-2;  
 	QGraphicsPixmapItem::setPos(x_, y_); 

 	if (x_ < -30) {
 		gr->delthing(this); 
 	} 
} 
void Apple::collide() {
 	gr->addScore(); 
 		gr->delthing(this); 
 	
}
/**@return x location */ 
int Apple::getx() {
 	return x_; 
}  

Apple::~Apple() {
 	delete pixMap; 
} 
/**@return y location */ 
int Apple::gety() {
 	return y_; 
} 
