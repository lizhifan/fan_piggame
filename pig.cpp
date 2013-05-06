#include "pig.h" 
#include <QGraphicsPixmapItem> 
#include <QPixmap> 
#include <QWidget> 
#include <QObject> 
#include <iostream> 
#include <QtGui/QApplication> 
#include <QTimer> 
#include <QWidget> 
#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QTimeLine>
#include <QGraphicsItemAnimation>
#include <QPushButton>
#include <QMouseEvent> 
#include <vector> 
#include <QTimer> 
#include <iostream> 
#include <QGraphicsSimpleTextItem> 
#include <QLineEdit> 
#include "graphicwindow.h" 
using namespace std; 

Pig::Pig(QPixmap* pm, int x, int y, GraphicWindow* h) : Thing(pm, x, y) {
 	x_ = x;
 	interval = 50; 
 	gr = h;
 	y_=y; 
 	pixMap = pm; 
	up = false; 
 	timer = new QTimer(this);
    timer->setInterval(interval);
    timer->start();  
 	//if up is false, need to move up, if up is true, already moving up need to move down
} 

void Pig::speedpig() {
    if (interval > 20) {
 	interval = interval - 7; 
 	timer->setInterval(interval); } 
  	
} 

Pig::~Pig() {
 	delete timer; 
 	delete pixMap; 
 
} 

void Pig::move() {

 	if (!up) {
 		up = true;
 	    disconnect(timer, 0, 0, 0); 
	    connect(timer, SIGNAL(timeout()), this, SLOT(moveup()));

 
 	} 
 	else if (up) { 
 		up = false; 
 	    disconnect(timer, 0, 0, 0); 
	    connect(timer, SIGNAL(timeout()), this, SLOT(movedown()));
 	} 

}

void Pig::mousePressEvent(QGraphicsSceneMouseEvent* event) {
 	event = event; 
 	move(); 
} 
 
void Pig::moveup() {

 	if (y_ > 20) {
	 	y_ = y_ -2 ;  
 	 	QGraphicsPixmapItem::setPos(x_, y_); 
 		} 
} 

int Pig::getx() {
 	return x_; 
} 

int Pig::gety() {
 	return y_; 
} 


void Pig::movedown() {

 	if (y_ < 450) {
 		y_ = y_ +2 ;  
 	 	QGraphicsPixmapItem::setPos(x_, y_); 
 		 } 
} 

void Pig::collide() {
} 

void Pig::pause() {
 	timer->stop(); 
} 
