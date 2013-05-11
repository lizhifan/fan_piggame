#include "graphicwindow.h" 
#include <QWidget> 
#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QTimer>
#include <QTimeLine>
#include <QGraphicsItemAnimation>
#include <QPushButton>
#include <QMouseEvent> 
#include <vector> 
#include <QTimer> 
#include "bird.h" 
#include <QString> 
#include "building.h" 
#include "jet.h" 
#include <iostream> 
#include <QGraphicsSimpleTextItem> 
#include <QLineEdit> 
#include "background.h" 
#include "pig.h"
#include "airplane.h" 
#include "apple.h" 
#include <QGraphicsPixmapItem> 
#include "hotair.h" 
#include "balloon.h" 
#include "thing.h" 
#include <cstdlib> 
using namespace std;  

GraphicWindow::GraphicWindow(QLineEdit* score, QLineEdit* lives, QLineEdit* level) {
    WINDOW_MAX_X = 705; 
    WINDOW_MAX_Y = 505; 
    score_ = score; 
    lives_ = lives;
 
//initializes level at 1 and then puts that level in the level QLineEdit 
    numlevel = 1; 
    level_ = level; 
    level_->clear(); 
    level_->insert("1"); 

//initializes score at 0 and lives at 3
    numero = 0; 
    numscore = 0; 
    numlives = 3; 

//this sets the initial timer intervals 
    timerinterval = 50;  
    geninterval = 2500; 
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,700,500);

//creates the speedtimer which is responsible for changing the level after an allotted time period
    speedtimer = new QTimer(this);
    speedtimer->setInterval(50000);
    speedtimer->start(); 
    connect(speedtimer, SIGNAL(timeout()), this, SLOT(speedup()));

//this is the main timer (back) that is responsible for moving the background, and moving the items
    back = new Background(700,0, this); 
    QPixmap pm("backgroundcloud.png"); 
    back->setPixmap(pm); 
    scene->addItem(back); 
    backtimer = new QTimer(this);
    backtimer->setInterval(timerinterval);
    backtimer->start(); 
    connect(backtimer, SIGNAL(timeout()), back, SLOT(move()));

//the gentimer is responsible for generating buildings and random creatures after certain amounts of time
    gentimer = new QTimer(this);
    gentimer->setInterval(geninterval);
    gentimer->start(); 
    connect(gentimer, SIGNAL(timeout()), this, SLOT(randomgenerate()));
    connect(gentimer, SIGNAL(timeout()), this, SLOT(handlebuilding()));

//this creates the background and makes it scroll by connecting it to backtimer
    newback = new Background(0,0, this); 
    QPixmap pm3("backgroundcloud.png"); 
    newback->setPixmap(pm3); 
    scene->addItem(newback);
    connect(backtimer, SIGNAL(timeout()), newback, SLOT(move()));
    
//this creates the pig and adds it into the vector myThings
    QPixmap* pm2 = new QPixmap("piggy.png");
    piggy = new Pig(pm2, 100,200, this); 
    scene->addItem(piggy); 
    myThings.push_back(piggy); 

//connects the backtimer to the score so that as the timer increases, so too does the score
    connect(backtimer, SIGNAL(timeout()), this, SLOT(scorekeep()));
 
    setFixedSize( WINDOW_MAX_X, WINDOW_MAX_Y );
    connect(backtimer, SIGNAL(timeout()), this, SLOT(handlecollide()));
    setScene(scene); 
} 

void GraphicWindow::createnew(Background* needmove) {
     needmove->changepos(700,0);  
} 

GraphicWindow::~GraphicWindow() {
      delete piggy; 
      delete back; 
      delete newback;
      delete backtimer; 
      delete gentimer; 
      delete speedtimer;
      for (unsigned int i=1; i<myThings.size();i++) {
 		delete myThings[i]; 
 	}  
      delete scene; 
} 


void GraphicWindow::randomgenerate() {

//function that randomly generates each "thing", uses the random function to choose which thing to generate 
//some things can't be generated until later levels, or until numlevel reaches a certain value  
        QPixmap* pm2;
 	int rando = rand() % 10; 
 	switch (rando) 
 	{
 	    case 0: 
 		{break;}  
 	    case 1: 
 		{
     		pm2 = new QPixmap("apple.png");
    		Apple* app = new Apple(pm2,700, rand()%300+20, this); 
    		scene->addItem(app); 
    		connect(backtimer, SIGNAL(timeout()), app, SLOT(move()));
    		myThings.push_back(app);  
 		break;    
 		} 
 	     case 2: {
 		pm2 = new QPixmap("balloon.png");
    	 	Balloon* b = new Balloon(pm2,rand()%400 + 200, 500, this); 
    		scene->addItem(b); 
    		connect(backtimer, SIGNAL(timeout()), b, SLOT(move()));
    		myThings.push_back(b);  
 		break;    
 		} 
 	     case 3: {
  		pm2 = new QPixmap("airplane.png");
     		Airplane* plane = new Airplane(pm2,700, rand() % 350, this); 
    		scene->addItem(plane); 
    		connect(backtimer, SIGNAL(timeout()), plane, SLOT(move()));
    		myThings.push_back(plane); 
 		break; 
 		} 
 	     case 4: {
 		if (numlevel > 1) {
 	 	pm2 = new QPixmap("bird.png");
    		Bird* bir = new Bird(pm2,700, rand()%300+20, this,piggy); 
    		scene->addItem(bir); 
    		connect(backtimer, SIGNAL(timeout()), bir, SLOT(move()));
    		myThings.push_back(bir); } 
 		break;  
 		} 
 	     case 5: {
 		pm2 = new QPixmap("hotair.png"); 
	  	HotAir* h = new HotAir(pm2, rand()%500 + 200, -100, this); 
	 	scene->addItem(h); 
	 	connect(backtimer, SIGNAL(timeout()), h, SLOT(move()));
	 	myThings.push_back(h);
 		break; 
 	        } 
 	  case 6: 
 		{   
 		if (numlevel >2) {
	 		pm2 = new QPixmap("jet.png");
	    		Jet* je = new Jet(pm2,700, piggy->gety(), this); 
	    		scene->addItem(je); 
	    		connect(backtimer, SIGNAL(timeout()), je, SLOT(move()));
	    		myThings.push_back(je); 
 		} 
 		break; } 
     	case 7: 
 		{
     		pm2 = new QPixmap("apple.png");
    		Apple* app = new Apple(pm2,700, rand()%300+20, this); 
    		scene->addItem(app); 
    		connect(backtimer, SIGNAL(timeout()), app, SLOT(move()));
    		myThings.push_back(app);  
 		break;    
 		} 
 	case 8: 
 		{break;} 
 	case 9: {break;} 
 	} 

}  

void GraphicWindow::handlecollide() {	
 	Thing* itemA = myThings[0]; 
 	Thing* itemB;
//this for loop checks to see which item collided with the Pig (since the Pig was created first, we know that it must be at index 0)
//each "Thing" has a collide function that will handle what happens when a collision occurs
 	for (unsigned int i=1; i<myThings.size(); i++) {
 	    itemB = myThings[i]; 
 	    if (itemA->collidesWithItem(itemB)) {
 		itemB->collide(); 
 	    } 
 	} 
//this part updates the score and lives QLineEdit to reflect the new changes after the collision
        QString sco; 
 	sco.setNum(numscore); 
 	QString liv; 
 	liv.setNum(numlives); 

 	score_->clear();
 	lives_->clear(); 
 	score_->insert(sco); 
 	lives_->insert(liv); 
} 

void GraphicWindow::delthing(Thing* t) {
//called within a "Thing" class, when a Thing goes out of the frame, it will be deleted 
 	Thing* a = NULL; 
 	vector<Thing*>::iterator it = myThings.begin(); 
//searches for the Thing in the vector myThings so that it can be erased from the vector 
 	for (unsigned int i=0; i< myThings.size(); i++) {
 		if (i!=0)  
		     ++it; 
 	 	a = myThings[i]; 
  		if (a == t) {
  		     break; }
 	} 
 	myThings.erase(it); 
	delete a; 
}  

void GraphicWindow::handlebuilding() {
//creates buildings based upon the random function
 	QPixmap* pm = NULL; 
 	int rando = rand() % 3; 
 	Building* l; 
 	switch (rando) 
 	{
 	   case 0: {
		pm = new QPixmap("building1.png");
 	 	l = new Building(pm, 700,rand()%50 + 370, this); 
 		scene->addItem(l); 
 		connect(backtimer, SIGNAL(timeout()), l, SLOT(move()));
 		myThings.push_back(l);  
 		break;
 		} 
 	   case 1: {
 		pm = new QPixmap("building2.png"); 
 	 	l = new Building(pm, 700,rand()%50 + 330, this); 
 		scene->addItem(l); 
 		connect(backtimer, SIGNAL(timeout()), l, SLOT(move()));
 		myThings.push_back(l); 
 		break; 		 
 		}  
 	    case 2: {break;} 
 	} 
} 

void GraphicWindow::pausegame() {
//simply pauses all the timers
    backtimer->stop(); 
    gentimer->stop(); 
    piggy->pause(); 
} 

void GraphicWindow::addScore() {
 	numscore= numscore + 100; 
} 

void GraphicWindow::scorekeep() {

 	++numero; 

 	if (numero % 50 == 0) 
 	numscore++; 
} 

void GraphicWindow::speedup() {
//increases the level up to level 3 when called by the speedtimer 
      numlevel++; 

      if (numlevel == 2) {
 	level_->clear(); 
 	level_->insert("2"); 
      } 
      else if (numlevel == 3) {
 	level_->clear(); 
 	level_->insert("3");  
      } 

    if (numlevel < 4) {
 	timerinterval = timerinterval - 10; 
 	if (timerinterval > 10) {
  	    backtimer->setInterval(timerinterval); 
 	    piggy->speedpig(); 
 	} 
 	
 
	geninterval = geninterval - 500; 
 	if (geninterval > 500) {
	     gentimer->setInterval(geninterval); 
             }
 	} 
} 

void GraphicWindow::loselife() {
 	numlives = numlives - 1; 

 	if (numlives == 0) {
 		pausegame(); 
 	} 

} 
