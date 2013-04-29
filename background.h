#ifndef BACKGROUND_H
#define BACKGROUND_H
#include <QGraphicsPixmapItem> 
#include <QPixmap> 
class GraphicWindow; 

/**this class models the movement of the background so that a sidescrolling game can be created*/ 
class Background : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
    public:  
 	/**basic constructor that creates the background at the specific place*/ 
 	Background(int, int, GraphicWindow*); 
 	/**a function that allows the background to be moved to a different location*/ 
 	void changepos(int, int); 

    private: 
  	int x_; 
 	int y_; 
 	GraphicWindow* wind; 
    public slots: 
 	/**public slot that when connected to a QTimer lets the background move*/ 
 	void move(); 
 	/**when the background goes out of the screen, this function calls on GraphicWindow to reposition it at a more useful location*/ 
 	void createnew(); 
    signals: 
 	/**signal emitted when a new background is needed*/ 
 	void newbackground(); 
};  
#endif 

