#ifndef GRAPHICWINDOW_H
#define GRAPHICWINDOW_H
#include <QWidget> 
#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QTimer>
#include <QTimeLine>
#include <QGraphicsItemAnimation>
#include <QPushButton>
#include <vector> 
#include <QTimer> 
#include <QGraphicsSimpleTextItem> 
#include <QLineEdit> 
#include <QObject> 
#include <QMouseEvent>  
#include "background.h" 
#include <vector> 
#include "thing.h"
#include <QLineEdit> 
using namespace std;  
class MainWindow; 
class Pig; 

/**this is the main GraphicsView that holds the main game*/ 
class GraphicWindow : public QGraphicsView {
 	Q_OBJECT
 	public: 
 	 	/**constructor that creates the game with all its elements 
 		@param QLineEdit* score that is passed from MainWindow so that the score can be updated 
 		@param QLineEdit* lives that is passed from MainWindow so that the number of lives can be updated*/ 
 	      GraphicWindow(QLineEdit*, QLineEdit*); 
 		/**basic destructor*/ 
 	      ~GraphicWindow(); 
 		MainWindow* w;  
    	 	 Background* back; 
  		  Background* newback; 
 		   QTimer* backtimer; 
  		  QTimer* gentimer; 
  		  QTimer* speedtimer; 
 		   /**this is the function that handles the creating of the background so that it is continuously sidescrolling*/ 
		    void createnew(Background *); 
		    vector<Thing*> myThings; 
		    Pig* piggy; 
 			/**this function is called by each individual Thing when it is out of the range of the window so that it can be deleted*/ 
		    void delthing(Thing*);
 		/**this is for the Apple's collision so that the score can be incremented by 100*/ 
		    void addScore(); 
 		/** this is called after a collision and causes the number of lives to decrement by 1*/ 
 		    void loselife();  

 	private: 
       	      int WINDOW_MAX_X; 
   	       int WINDOW_MAX_Y;
               QGraphicsScene *scene;
 	       QLineEdit* score_; 
   	       QLineEdit* lives_;
 		int numscore; 
 		int numlives; 
 		int timerinterval; 
 		int geninterval; 
 		int numero; 

     	  public slots: 
 		/**function called by a timer that randomly generates different Things*/ 
	 	void randomgenerate(); 
 		/**function that checks and handles collisions*/ 
 		void handlecollide(); 
 		/**function that creates the buildings, created separately from the rest of the things*/ 
 		void handlebuilding(); 
 		/**connected to the pause QPushButton and stops all timers*/ 
 		void pausegame(); 
 		/**handles the incrementing of scores*/ 
		void scorekeep();
 		/**attached to a timer that eventually increases the speed of the game*/  
 		void speedup(); 

}; 
#endif 
