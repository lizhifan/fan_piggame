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
    level_ = level; 
    level_->clear(); 
    level_->insert("1"); 

    numero = 0; 

    numscore = 0; 
    numlives = 3; 

    timerinterval = 50; 
    geninterval = 2500; 
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,700,500);

   speedtimer = new QTimer(this);
    speedtimer->setInterval(50000);
    speedtimer->start(); 
    connect(speedtimer, SIGNAL(timeout()), this, SLOT(speedup()));



    back = new Background(700,0, this); 
    QPixmap pm("backgroundcloud.png"); 
    back->setPixmap(pm); 
    scene->addItem(back); 
 
    backtimer = new QTimer(this);
    backtimer->setInterval(timerinterval);
    backtimer->start(); 
    connect(backtimer, SIGNAL(timeout()), back, SLOT(move()));

    gentimer = new QTimer(this);
    gentimer->setInterval(geninterval);
    gentimer->start(); 
    connect(gentimer, SIGNAL(timeout()), this, SLOT(randomgenerate()));

    connect(gentimer, SIGNAL(timeout()), this, SLOT(handlebuilding()));

    newback = new Background(0,0, this); 
    QPixmap pm3("backgroundcloud.png"); 
    newback->setPixmap(pm3); 
    scene->addItem(newback);
    connect(backtimer, SIGNAL(timeout()), newback, SLOT(move()));
    
    QPixmap* pm2 = new QPixmap("piggy.png");
    piggy = new Pig(pm2, 100,200, this); 
    scene->addItem(piggy); 
    myThings.push_back(piggy); 

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
    //  delete speedtimer;
 	for (unsigned int i=1; i<myThings.size();i++) {
 		delete myThings[i]; 
 	}  
 	delete scene; 

} 



void GraphicWindow::randomgenerate() {
     		QPixmap* pm2;
 	int rando = rand() % 10; 
 	switch (rando) 
 	{
 	    case 0: 
 		{
 		break;}  
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
 			pm2 = new QPixmap("bird.png");
    		 	Bird* bir = new Bird(pm2,700, rand()%300+20, this,piggy); 
    			scene->addItem(bir); 
    			connect(backtimer, SIGNAL(timeout()), bir, SLOT(move()));
    			myThings.push_back(bir); 
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
 		pm2 = new QPixmap("jet.png");
    		Jet* je = new Jet(pm2,700, piggy->gety(), this); 
    		scene->addItem(je); 
    		connect(backtimer, SIGNAL(timeout()), je, SLOT(move()));
    		myThings.push_back(je);  
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
 		{
 		break; 
 		} 
 	case 9: {break; 
 		} 
 	
 	} 

}  

void GraphicWindow::handlecollide() {
 	
 	Thing* itemA = myThings[0]; 
 	Thing* itemB; 
 	for (unsigned int i=1; i<myThings.size(); i++) {
 	    itemB = myThings[i]; 
 	    if (itemA->collidesWithItem(itemB)) {
 		itemB->collide(); 
 	    } 
 	} 

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
 	Thing* a = NULL; 
 	vector<Thing*>::iterator it = myThings.begin(); 
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
 		break;} 
 	   case 1: {
 		pm = new QPixmap("building2.png"); 
 	l = new Building(pm, 700,rand()%50 + 330, this); 
 	scene->addItem(l); 
 	connect(backtimer, SIGNAL(timeout()), l, SLOT(move()));
 	myThings.push_back(l); 
 		break; 		 
 		}  
 	    case 2: {
 		break; 
 		} 
 	} 

} 

void GraphicWindow::pausegame() {
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
 	timerinterval = timerinterval - 10; 
 	if (timerinterval > 10) {
  	backtimer->setInterval(timerinterval); 
 	piggy->speedpig(); 
 	} 
 	
 
	geninterval = geninterval - 500; 
 	if (geninterval > 500) {
	gentimer->setInterval(geninterval); }
 	
} 

void GraphicWindow::loselife() {
 	numlives = numlives - 1; 

 	if (numlives == 0) {
 		pausegame(); 
 	} 

} 
