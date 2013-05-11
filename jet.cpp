#include "jet.h" 
#include "graphicwindow.h" 
#include <QGraphicsPixmapItem> 
#include <QPixmap> 
#include <iostream> 
#include <QtGui/QApplication> 
#include <cstdlib> 
#include <cmath> 
using namespace std; 
/**
@param pm is the the QPixmap or image that is associated with the Jet 
@param x is the x location of where the Jet is to be created 
@param y is the y location of where the Jet is to be created 
@param h is the graphicwindow that created the specific Jet*/
Jet::Jet(QPixmap * pm, int x, int y, GraphicWindow* h) : Thing(pm, x, y) {
 	y_ = y; 
 	x_ = x; 	
 	gr = h; 
} 

void Jet::move() {

 	x_ = x_ - 9;
 	QGraphicsPixmapItem::setPos(x_, y_); 

 	if (x_ < -50) {
 	     gr->delthing(this); 
 	} 
} 
void Jet::collide() {

	gr->loselife(); 
 	gr->delthing(this); 
 	 
}
/**@return x location of where the Balloon is at */ 
int Jet::getx() {
 	return x_; 
}  
/**@return y location of where the Balloon is at */ 
int Jet::gety() {
 	return y_; 
} 
