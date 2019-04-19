#ifndef ARC_H
#define ARC_H

#include <QtGui>
#include <QGraphicsLineItem>
class sommet ;


class arc : public QGraphicsLineItem
{
    friend class WGraphe ;

public :

    arc(sommet *s1, sommet *s2, bool oriente, QGraphicsScene* parent) ;

private:
    QGraphicsScene *d_parent ;

    static const int TAILLE = 10 ,BLANC = 20 ;

    int sdep, sarr ;
};

#endif
