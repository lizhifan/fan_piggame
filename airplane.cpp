#include "airplane.h" 
#include "graphicwindow.h" 
#include <QGraphicsPixmapItem> 
#include <QPixmap> 
#include <iostream> 
#include <QtGui/QApplication> 
#include <cstdlib> 
#include <cmath> 
using namespace std; 

/**
@param pm is the the QPixmap or image that is associated with the Airplane 
@param x is the x location of where the airplane is to be created 
@param y is the y location of where the airplane is to be created 
@param h is the graphicwindow that created the specific Airplane*/ 
Airplane::Airplane(QPixmap * pm, int x, int y, GraphicWindow* h) : Thing(pm, x, y) {
 	y_ = y; 
 	x_ = x; 	
 	gr = h; 
} 

void Airplane::move() {
 	x_ = x_-5;  
 	QGraphicsPixmapItem::setPos(x_, y_); 

 	if (x_ < -300) {
 		gr->delthing(this); 
 	} 
} 

void Airplane::collide() {
	gr->loselife(); 
 		gr->delthing(this); 
}

/**@return the x value of where the Airplane currently is*/
int Airplane::getx() {
 	return x_; 
}  

/**@return the y value of where the Airplane currently is*/
int Airplane::gety() {
 	return y_; 
} 

Airplane::~Airplane() {
 	delete pixMap; 
} 
