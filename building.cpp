#include "building.h" 
#include "graphicwindow.h" 
#include <QGraphicsPixmapItem> 
#include <QPixmap> 
#include <iostream> 
#include <QtGui/QApplication> 
#include <cstdlib> 
#include <cmath> 
using namespace std; 

/**
@param pm is the the QPixmap or image that is associated with the Building 
@param x is the x location of where the building is to be created 
@param y is the y location of where the building is to be created 
@param h is the graphicwindow that created the specific Building*/ 
Building::Building(QPixmap * pm, int x, int y, GraphicWindow* h) : Thing(pm, x, y) {
 	y_ = y; 
 	x_ = x; 	
 	gr = h; 
} 

void Building::move() {
 	x_ = x_-2;  
 	QGraphicsPixmapItem::setPos(x_, y_); 

 	if (x_ < -300) {
 		gr->delthing(this); 
 	} 
} 
void Building::collide() {
	gr->loselife(); 
 	gr->delthing(this); 
}

/**@return x location of where the Building is at*/ 
int Building::getx() {
 	return x_; 
}  

/**@return y location of where the Building is at*/ 
int Building::gety() {
 	return y_; 
} 

Building::~Building() {
 	delete pixMap;  
} 
