#ifndef SOMMET_H
#define SOMMET_H

#include <QtGui>
#include "WGraphe.h"
#include <QGraphicsLineItem>

//sommet du graphe
class sommet : public QGraphicsEllipseItem
{
    friend class arc ;
public :
    //creation d'un sommet
    sommet(QWidget *parent, int num, double x, double y) ;
    virtual ~sommet() ;

    void mousePressEvent(QGraphicsSceneMouseEvent *event) ;

    int getNum() const { return d_num ; }
    QString info() const { return d_info ; }
    void setInfo(QString info) { d_info = info ; setToolTip(info) ; }

signals:
    void suppr(int) ;

private:
    //numero du sommet
    int d_num ;
    //pointeur sur WGraphe
    QWidget *d_parent ;
    //information complexe associee au sommet
    QString d_info ;
    //taille duQGraphicsEllispseItem
    static const int WIDTH = 20, HEIGHT = 20 ;
};

#endif
