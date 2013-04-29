#include <QtGui/QApplication>
#include <QPushButton> 
#include "graphicwindow.h" 
#include "mainwindow.h" 

int main(int argc, char *argv[])
{
  //  QApplication a(argc, argv);
    QApplication *a = new QApplication(argc,argv); 
    MainWindow w(a); 
    w.show();

 

   // return a.exec();
   return a->exec(); 
}
