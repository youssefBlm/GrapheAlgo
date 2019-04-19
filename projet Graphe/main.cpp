#include "MainWin.h"
#include "graphe.h"
#include <QApplication>
int main(int argc, char *argv[])
{
    QApplication app(argc,argv) ;

    Mainwin f ;
    f.show() ;

    return app.exec() ;
}
