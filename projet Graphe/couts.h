#ifndef COUT_H
#define COUT_H

#include <QtGui>
#include "graphe.h"
#include "grapheOV.h"
#include "grapheNOV.h"
#include "grapheONV.h"
#include "grapheNONV.h"
#include<QGraphicsTextItem>

class WGraphe ;


class couts : public QGraphicsTextItem
{
public :

    couts(WGraphe *parent, int c, int s1, int s2) ;
    virtual ~couts() ;

    void mousePressEvent(QGraphicsSceneMouseEvent *e) ;

private:
    int d_cout ;
    WGraphe *d_parent ;

    int sdep, sarr ;
};
#endif
