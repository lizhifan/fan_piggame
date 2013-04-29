#ifndef BUILDING_H
#define BUILDING_H
#include <QGraphicsPixmapItem> 
#include <QPixmap> 
#include "thing.h" 

/**class that inherits from Thing and models a Building in the game*/ 
class Building : public QObject, public Thing {
 	Q_OBJECT
    public:  
 	/**constructor that creates the Building at the given location with the given QPixmap*/ 
 	Building(QPixmap*, int, int, GraphicWindow*); 
 	/**basic destructor*/ 
 	~Building(); 
 	/**function that handles what happens when there is a collision*/ 
  	void collide(); 
 	/**accessor function of the current x location*/ 
 	int getx(); 
 	/**accessor function of the current y location*/ 
 	int gety(); 
    private: 
 	GraphicWindow * gr; 
 	int x_; 
 	int y_; 

    public slots: 
 	/**handles the movement of the Building*/ 
        void move(); 

};  
#endif 

