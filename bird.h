#ifndef BIRD_H
#define BIRD_H
#include <QGraphicsPixmapItem> 
#include <QPixmap> 
#include "thing.h"
#include "pig.h" 

/**class that inherits from Thing to model the Bird in the game*/  
class Bird : public QObject, public Thing {
 	Q_OBJECT
    public:  
 	/**basic constructor that creates the bird at a given location and gives location of Pig so that the Bird can follow*/ 
 	Bird(QPixmap*, int, int, GraphicWindow*, Pig* pig);  
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
 	Pig* piggy_; 

    public slots: 
 	/**handles how the Bird moves after it is created*/ 
        void move(); 

};  
#endif 

