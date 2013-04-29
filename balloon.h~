#ifndef BALLOON_H
#define BALLOON_H
#include <QGraphicsPixmapItem> 
#include <QPixmap> 
#include "thing.h"

/**class that inherits from Thing to model the Balloon in the game*/  
class Balloon : public QObject, public Thing {
 	Q_OBJECT
    public:  
 	/**basic constructor that creates the balloon at a given location*/ 
 	Balloon(QPixmap*, int, int, GraphicWindow*);  
 	/**handles the collision between the main character(Pig) and the balloon*/ 
  	void collide(); 
 	/**accessor function for the current x location*/ 
 	int getx(); 
 	/**accessor function for the current y location*/ 
 	int gety(); 
    private: 
 	GraphicWindow * gr; 
 	int x_; 
 	int y_; 

    public slots: 
 	/**handles how the Balloon moves after it is created*/ 
        void move(); 

};  
#endif 

