#ifndef APPLE_H
#define APPLE_H
#include <QGraphicsPixmapItem> 
#include <QPixmap> 
#include "thing.h" 

/**class that models an Apple, which, upon collision, gives 100 extra points added to the score*/ 
class Apple : public QObject, public Thing {
 	Q_OBJECT
    public:  
 	/**basic constructor that creates the Apple with the passed in QPixmap at the given coordinates*/ 
 	Apple(QPixmap*, int, int, GraphicWindow*); 
 	/**basic destructor*/ 
 	~Apple(); 
 	/**collide function lets the GraphicWindow know how to handle a collision*/ 
  	void collide(); 
 	/**acccessor function for the current x coordinate*/ 
 	int getx(); 
 	/**acccessor function for the current x coordinate*/ 
 	int gety(); 
    private: 
 	GraphicWindow * gr; 
 	int x_; 
 	int y_; 
 	bool collided; 

    public slots: 
 	/**responsible for allowing the apple to move, connected to a QTimer in GraphicWindow*/ 
        void move(); 

};  
#endif 

