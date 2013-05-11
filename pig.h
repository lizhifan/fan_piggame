#ifndef PIG_H
#define PIG_H
#include <QGraphicsPixmapItem> 
#include <QPixmap> 
#include "thing.h"
#include <QTimer> 
class GraphicWindow;  
/**Pig class which models the flying Pig in the game*/ 
class Pig : public QObject, public Thing {
    Q_OBJECT
    public:  
 	/**constructor that creates the Pig with the QPixmap at given location 
 	@param pm is the the QPixmap or image that is associated with the Pig 
	@param x is the x location of where the Pig is to be created 
 	@param y is the y location of where the Pig is to be created 
	@param h is the graphicwindow that created the specific Pig*/
 	Pig(QPixmap*, int, int, GraphicWindow *); 
 	/**destructor*/ 
 	~Pig(); 
 	/**handles the movement of the pig, not connected to QGraphicWindow's timer, but to a timer inside Pig class*/ 
 	void move(); 
 	/**created only because Pig inherits from Thing which needs a collide function*/ 
 	void collide(); 
 	/**accessor function that returns x position 
 	@return x position of current location*/ 
 	int getx(); 
 	/**accessor function that returns y position 
 	@return y position of current location*/ 
 	int gety(); 
 	/**since Pig is not connected to the timer in GraphicWindow, it needs it's own separate pause function that can be called*/ 
 	void pause();
 	/**increases the speed of the pig*/ 
 	void speedpig();  
    private: 
 	int x_; 
 	int y_; 
 	int vX_; 
 	int vY_; 
 	int interval; 
        QTimer* timer; 
 	QPixmap *pixMap; 
 	GraphicWindow *gr; 
 	/**this is the mousePressEvent that allows the Pig to change direction upon mouse Click*/ 
        void mousePressEvent(QGraphicsSceneMouseEvent*); 
 	bool up; 
    public slots: 
 	/**function that makes the pig move up*/ 
     	void moveup(); 
 	/**function that makes the pig move down*/ 
	void movedown(); 
};  
#endif 

