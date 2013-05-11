#ifndef THING_H
#define THING_H
#include <QPixmap> 
#include <QGraphicsPixmapItem> 
class GraphicWindow; 

/**abstract class of Things*/ 
class Thing: public QGraphicsPixmapItem {
public: 
 	/**constructor function that sets the Pixmap and setsPos at the given location 
 	@param pm is the the QPixmap or image that is associated with the Thing 
	@param x is the x location of where the thing is to be created 
	@param y is the y location of where the thing is to be created */
       Thing (QPixmap *pm, int nx, int ny); 
	/**virtual move function so that every inherited class must be able to handle moves*/ 
 	virtual void move() = 0;
 	/**virtual collide function so that every inherited class must be able to handle collisions*/ 
 	virtual void collide() = 0;  

private : 
 	int x; 
 	int y; 
 	int vX; 
 	int vY; 
protected :
 	QPixmap *pixMap; 
}; 
#endif
