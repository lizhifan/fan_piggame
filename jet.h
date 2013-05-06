#ifndef JET_H
#define JET_H
#include <QGraphicsPixmapItem> 
#include <QPixmap> 
#include "thing.h"
#include "pig.h" 

/**class that inherits from Thing to model the Jet in the game*/  
class Jet : public QObject, public Thing {
 	Q_OBJECT
    public:  
 	/**basic constructor that creates the Jet at a given location*/ 
 	Jet(QPixmap*, int, int, GraphicWindow*);  
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
 	/**handles how the Bird moves after it is created*/ 
        void move(); 

};  
#endif 

