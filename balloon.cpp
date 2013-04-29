#include "balloon.h" 
#include "graphicwindow.h" 
#include <QGraphicsPixmapItem> 
#include <QPixmap> 
#include <iostream> 
#include <QtGui/QApplication> 
#include <cstdlib> 
#include <cmath> 
using namespace std; 
/**
@param pm is the the QPixmap or image that is associated with the Balloon 
@param x is the x location of where the Balloon is to be created 
@param y is the y location of where the Balloon is to be created 
@param h is the graphicwindow that created the specific Balloon*/ 
Balloon::Balloon(QPixmap * pm, int x, int y, GraphicWindow* h) : Thing(pm, x, y) {
 	y_ = y; 
 	x_ = x; 	
 	gr = h; 
} 

void Balloon::move() {
 	x_ = x_ -2;
 	y_ = y_-2;  
 	QGraphicsPixmapItem::setPos(x_, y_); 

 	if (y_ < -100) {
 		gr->delthing(this); 
 	} 
} 
void Balloon::collide() {

	gr->loselife(); 
 		gr->delthing(this); 
 	 
}
/**@return x location of where the Balloon is at */ 
int Balloon::getx() {
 	return x_; 
}  
/**@return y location of where the Balloon is at */ 
int Balloon::gety() {
 	return y_; 
} 
