#include "bird.h" 
#include "graphicwindow.h" 
#include <QGraphicsPixmapItem> 
#include <QPixmap> 
#include <iostream> 
#include <QtGui/QApplication> 
#include <cstdlib> 
#include <cmath> 
#include "pig.h" 
using namespace std; 
/**
@param pm is the the QPixmap or image that is associated with the Bird 
@param x is the x location of where the Bird is to be created 
@param y is the y location of where the Bird is to be created 
@param h is the graphicwindow that created the specific Bird
@param followx is the x location of the Pig 
@param folowy is the y location of the Pig*/ 
Bird::Bird(QPixmap * pm, int x, int y, GraphicWindow* h, Pig* pig) : Thing(pm, x, y) {
 	piggy_ = pig; 
 	y_ = y; 
 	x_ = x; 	
 	gr = h; 
} 

void Bird::move() {

 	int followy = piggy_->gety(); 
 	int followx = piggy_->getx(); 
 	x_ = x_ -4;

 	if (x_ < followx + 300) {
	 	if (y_ < followy) {
	 		y_ = y_ + 1; 
	 	} 
	 	else if (y_ > followy) {
	 		y_ = y_ -1; 
	 	} 
 	} 
 	QGraphicsPixmapItem::setPos(x_, y_); 

 	if (x_ < -50) {
 		gr->delthing(this); 
 	} 
} 
void Bird::collide() {

	gr->loselife(); 
 		gr->delthing(this); 
 	 
}
/**@return x location of where the Balloon is at */ 
int Bird::getx() {
 	return x_; 
}  
/**@return y location of where the Balloon is at */ 
int Bird::gety() {
 	return y_; 
} 
