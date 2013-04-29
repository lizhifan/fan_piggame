#ifndef HOTAIR_H
#define HOTAIR_H
#include <QGraphicsPixmapItem> 
#include <QPixmap> 
#include "thing.h" 

/**class that models a Hot Air Balloon in the game*/ 
class HotAir : public QObject, public Thing {
 	Q_OBJECT
    public:  
 	/**basic constructor 
@param pm is the the QPixmap or image that is associated with the HotAir 
@param x is the x location of where the HotAir Balloon is to be created 
@param y is the y location of where the HotAir Balloon is to be created 
@param h is the graphicwindow that created the specific HotAir*/ 
 	HotAir(QPixmap*, int, int, GraphicWindow*); 
 	/**basic destructor*/ 
 	~HotAir(); 
 	/**handles the collisions*/ 
  	void collide(); 
 	/**accessor function of current x value 
 	   @return x value of current location*/ 
 	int getx(); 
 	/**accessor function of current y value 
 	   @return y value of current location*/ 
 	int gety(); 
    private: 
 	GraphicWindow * gr; 
 	int x_; 
 	int y_; 

    public slots: 
 	/**handles the movement of the HotAir Balloon and is connected to a timer in GraphicWindow*/ 
        void move(); 

};  
#endif 

