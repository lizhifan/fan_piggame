#ifndef AIRPLANE_H
#define AIRPLANE_H
#include <QGraphicsPixmapItem> 
#include <QPixmap> 
#include "thing.h" 
/**This is a class that inherits from the class Thing which models an Airplane in my game*/ 

class Airplane : public QObject, public Thing {
 	Q_OBJECT
    public:  
 	/**constructor which takes in a QPixmap, the x and y coordinates, as well as the GraphicWindow*/ 
 	Airplane(QPixmap*, int, int, GraphicWindow*); 
 	/**destructor*/ 
 	~Airplane(); 
 	/**this function lets QGraphicWindow know how to handle a collision with an Airplane*/ 
  	void collide(); 
 	/**accessor function for the x coordinate of the Airplane*/ 
 	int getx(); 
 	/**accessor function for the y coordinate of the Airplane*/
 	int gety(); 
    private: 
 	GraphicWindow * gr; 
 	int x_; 
 	int y_; 
 	bool collided; 

    public slots: 
 	/**public slot that is responsible for the movement of the Airplane. Called by a QTimer in the GraphicWindow*/
        void move(); 

};  
#endif 

