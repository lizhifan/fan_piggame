#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QListWidget> 
#include <QtGui/QApplication>
#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QTimer>
#include <QTimeLine>
#include <QGraphicsItemAnimation>
#include <QPushButton>
#include <QString> 
#include <vector> 
#include <QLineEdit> 
#include <QRadioButton> 
#include <QListView> 
#include <QVBoxLayout> 
#include <QHBoxLayout> 
#include "graphicwindow.h" 

/**this is the mainwindow that holds the GraphicsWindow with the game. It has the buttons to start and stop the game as well 
as the display for username, score, and lives*/ 
class MainWindow : public QGraphicsView {
    Q_OBJECT

public:
 	/**basic constructor
 	@param a is the QApplication that created MainWindow, used so that the quit button can be successful*/ 
    explicit MainWindow(QApplication*);
 	/**show allows the MainWindow and all its elements to be seen*/ 
    void show();

private: 
    QGraphicsScene *scene;
    QGraphicsView *view;
    int WINDOW_MAX_X; 
    int WINDOW_MAX_Y;
    QLineEdit *score; 
    QLineEdit *level; 
    QPushButton* start; 
    QPushButton* stop; 
    QPushButton* pause; 
    QVBoxLayout *vertical; 
    GraphicWindow* game;
    QHBoxLayout* gamerow; 
    QLineEdit *username; 
    QLineEdit *lives; 

protected: 


public slots: 
 	/**connected to the start button that creates the GraphicsWindow*/ 
    void startgame(); 

}; 
#endif
