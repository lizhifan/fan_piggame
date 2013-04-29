#include "hotair.h" 
#include "graphicwindow.h" 
#include <QGraphicsPixmapItem> 
#include <QPixmap> 
#include <iostream> 
#include <QtGui/QApplication> 
#include <cstdlib> 
#include <cmath> 
using namespace std; 

HotAir::HotAir(QPixmap * pm, int x, int y, GraphicWindow* h) : Thing(pm, x, y) {
 	y_ = y; 
 	x_ = x; 	
 	gr = h; 
} 

void HotAir::move() {


	 	x_ = x_ - 2;
	 	y_ = y_+ 1;
    QGraphicsPixmapItem::setPos(x_, y_); 

    if (y_ > 500 || x_< -100) {
 		gr->delthing(this); 
 	} 
} 
void HotAir::collide() {

	gr->loselife(); 
 		gr->delthing(this); 
 	 
}

int HotAir::getx() {
 	return x_; 
}  

int HotAir::gety() {
 	return y_; 
} 

HotAir::~HotAir() {
 	delete pixMap; 
} 
