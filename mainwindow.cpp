#include "mainwindow.h"
#include <QMainWindow>
#include <QPushButton> 
#include <QApplication> 
#include <iostream>
#include <QFormLayout> 
#include <QVBoxLayout> 
#include <QHBoxLayout>  
#include <QLineEdit> 
#include <QLabel> 
#include <QGridLayout> 
#include <QRadioButton> 
#include "graphicwindow.h" 
#include <QListView> 
#include <QtGui/QApplication>
#include <QListWidget>
#include <QtGui/QApplication> 
#include "pig.h" 

using namespace std; 


MainWindow::MainWindow(QApplication* a) { 
    setFocus(); 
    WINDOW_MAX_X = 730; 
    WINDOW_MAX_Y = 530; 
    game = NULL; 
    scene = new QGraphicsScene();

    vertical = new QVBoxLayout;

//creates first row with the start, stop, pause buttons and connects each to their respective slots
    QHBoxLayout *row1 = new QHBoxLayout; 
    start = new QPushButton("start"); 
    connect(start, SIGNAL(clicked()), this, SLOT(startgame()));  
    stop = new QPushButton("stop"); 
    connect(stop, SIGNAL(clicked()), a, SLOT(quit()));  
    pause = new QPushButton("pause"); 
    row1->addWidget(start); 
    row1->addWidget(pause); 
    row1->addWidget(stop); 
    vertical->addLayout(row1); 

//creates second and third rows with the boxes for score, usernames, and lives      
    score = new QLineEdit; 
    username = new QLineEdit; 
    lives = new QLineEdit; 
    level = new QLineEdit; 
    QLabel *sizeLabel = new QLabel(tr("Username:")); 
    sizeLabel->setBuddy(username); 
    QLabel *moveLabel = new QLabel(tr("Score:"));
    moveLabel->setBuddy(score);  
    QLabel *seedLabel = new QLabel(tr("Lives:"));  	
    seedLabel->setBuddy(lives); 
    QLabel *levelLabel = new QLabel(tr("Level:"));  	
    seedLabel->setBuddy(level);
    QHBoxLayout* row2 = new QHBoxLayout; 
    row2->addWidget(sizeLabel); 
    row2->addWidget(username);  
    vertical->addLayout(row2); 
    QHBoxLayout* row3 = new QHBoxLayout; 
    row3->addWidget(moveLabel); 
    row3->addWidget(score); 
    row3->addWidget(seedLabel); 
    row3->addWidget(lives); 
    row3->addWidget(levelLabel); 
    row3->addWidget(level); 
    vertical->addLayout(row3); 

//creates a row that is empty until start game is pressed at which point it creates the game in that area
    gamerow = new QHBoxLayout; 
    vertical->addLayout(gamerow);
 
    view = new QGraphicsView( scene ); 
    view->setLayout(vertical);  
}


void MainWindow::show() {
    view->show(); 
} 

 
void MainWindow::startgame() {
    QString multitext; 
    multitext = username->displayText();
    string user_;  
    user_ = multitext.toStdString();  
//checks to make sure there is a username before starting the game
    if (user_.empty()) {
 	 cout << "please write a user" << endl; 
    } 
    else {
//the game!=NULL checks to make sure that there is not currently a game
//if there is a game, then the program deletes the previous game and disconnects the pause button
    if (game != NULL) {
 	disconnect(pause, 0,0,0); 
 	gamerow->removeWidget(game);
 	delete game; 
 	}  

    game = new GraphicWindow(score, lives, level); 
    gamerow->addWidget(game); 
    connect(pause, SIGNAL(clicked()), game, SLOT(pausegame()));  
    } 

} 

