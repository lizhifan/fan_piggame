#include "background.h" 
#include <QGraphicsPixmapItem> 
#include <QPixmap> 
#include <iostream> 
#include <QtGui/QApplication> 
#include "graphicwindow.h" 
using namespace std; 

/**@param x is the x location of where the Background is to be created 
@param y is the y location of where the Background is to be created
@temp is the GraphicWindow that created the specific Background*/
Background::Background(int x, int y, GraphicWindow* temp ) {
 	QGraphicsPixmapItem::setPos(x,y); 
 	x_ = x; 
 	y_ =y; 
 	wind = temp; 
        connect(this, SIGNAL(newbackground()), this, SLOT(createnew()));
} 

void Background::move() {
 	x_ = x_ -2; 
 	QGraphicsPixmapItem::setPos(x_, y_); 
 	if (x_ == -700 && y_ == 0) {
 		emit newbackground(); 
 	} 
} 

void Background::createnew() {
 	wind->createnew(this); 
} 
/**@param x is the x location of where you want to relocate 
@param y is the y location of where you want to relocate*/ 
void Background::changepos(int x, int y) {
 	x_ = x; 
 	y_ = y; 
 	QGraphicsPixmapItem::setPos(x_, y_); 
} 
