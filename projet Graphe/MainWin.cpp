#include <QtGui>
#include <fstream>
#include "MainWin.h"
#include<QMenuBar>
#include<QDockWidget>
#include<QMessageBox>
#include<QFileDialog>
#include<QInputDialog>
#include "qstyle.h"

Mainwin::Mainwin() : QMainWindow(), fichier(NULL), graph(NULL),ajoutsom(new QPushButton("Ajouter un sommet")),
    supprsom(new QPushButton("Supprimer un sommet")),	ajoutarc(new QPushButton("Ajouter un  arc")),
    supprarc(new QPushButton("Supprimer un arc")),enregistrement(new QPushButton("Enregistrer")),
    value(new QCheckBox("Value")), oriente(new QCheckBox("Oriente")),
     quitter(NULL)
{
    wid = new WGraphe(this) ;
    this->resize(HAUT,LARG) ;
    this->setWindowTitle("Algorithme des graphes ") ;
    wid->setStyleSheet("background-color: rgb(166,179,242)");

    setCentralWidget(wid) ;
    this->menuBar()->setStyleSheet("background-color: rgb(66,138,189)");
   // fichier->setStyleSheet("background-color: rgb(66,138,189)");
    fichier = menuBar()->addMenu("&Fichier") ;
    graph = menuBar()->addMenu("&Graphe") ;
    nveau = fichier->addAction("&Nouveau") ;
    charger = fichier->addAction("&Charger") ;
    sauvegarder = fichier->addAction("&Sauvegarder") ;
    fichier->addSeparator() ;
    quitter = fichier->addAction("&Quitter") ;
    dist = graph->addAction("&Calcul distances") ;
    graph->addSeparator() ;
    rg = graph->addAction("&Calcul du rang") ;
    graph->addSeparator() ;
    ordo = graph->addAction("&Ordonnancement") ;
     graph->addSeparator() ;
    Dijkstra = graph->addAction("&Dijkstra") ;
    dantzig = graph->addAction("&Dantzig") ;
    graph->addSeparator() ;
    kruskal = graph->addAction("&Kruskal") ;
    graph->addSeparator() ;
    prufer = graph->addAction("&Coder Prufer") ;
     graph->addSeparator() ;
     color=graph->addAction("&coloration");
     graph->addSeparator() ;
     dessiner = graph->addAction("&Redessiner graphe") ;


    QObject::connect(quitter, SIGNAL(triggered()),qApp, SLOT(quit())) ;
    QObject::connect(charger, SIGNAL(triggered()), this, SLOT(chargerGraphe())) ;
    QObject::connect(sauvegarder, SIGNAL(triggered()), this, SLOT(sauvegarderGraphe())) ;
    QObject::connect(nveau, SIGNAL(triggered()), this, SLOT(nouveauGraphe())) ;

    ajoutsom->setCheckable(true) ;
    supprsom->setCheckable(true) ;
    ajoutarc->setCheckable(true) ;
    supprarc->setCheckable(true) ;
    enregistrement->setCheckable(true) ;
    value->setDisabled(true) ;
    oriente->setDisabled(true) ;

    QObject::connect(Dijkstra, SIGNAL(triggered()),this,SLOT(dessinerDijkstra())) ;
    QObject::connect(dessiner,SIGNAL(triggered()), this, SLOT(redessinerGraphe())) ;
 //   QObject::connect(matrice, SIGNAL(triggered()), this,SLOT(afficherMatriceAdj())) ;
   // QObject::connect(couts, SIGNAL(triggered()), this, SLOT(afficherMatriceCouts())) ;
    QObject::connect(rg, SIGNAL(triggered()), this, SLOT(rang())) ;
  //  QObject::connect(Bellman, SIGNAL(triggered()), this, SLOT(dessinerBellman())) ;
    QObject::connect(dist, SIGNAL(triggered()), this, SLOT(distances())) ;
    QObject::connect(prufer, SIGNAL(triggered()), this, SLOT(coderPrufer())) ;
    QObject::connect(kruskal, SIGNAL(triggered()), this, SLOT(dessinerKruskal())) ;
    //QObject::connect(decoderprufer, SIGNAL(triggered()), wid, SLOT(lirePrufer())) ;
    QObject::connect(dantzig, SIGNAL(triggered()), this, SLOT(afficherDantzig())) ;
    QObject::connect(ordo, SIGNAL(triggered()), wid, SLOT(ordonnancement())) ;

    dock = new QDockWidget("Outils",this) ;
    dock->setFloating(true) ;
    dock->setFeatures(QDockWidget::NoDockWidgetFeatures|QDockWidget::DockWidgetFloatable) ;
    addDockWidget(Qt::RightDockWidgetArea, dock) ;
    dockwid = new QWidget ;
    //dockwid->setStyle(new );
    dock->setWidget(dockwid) ;
    dockLayout = new QVBoxLayout ;
    dockLayout->addWidget(value) ;
    dockLayout->addWidget(oriente) ;
    dockLayout->addWidget(ajoutsom) ;
    dockLayout->addWidget(supprsom) ;
    dockLayout->addWidget(ajoutarc) ;
    dockLayout->addWidget(supprarc) ;
    dockLayout->insertSpacing(6,20) ;
    dockLayout->addWidget(enregistrement) ;

    dockwid->setLayout(dockLayout) ;


    QObject::connect(ajoutsom, SIGNAL(clicked()), this, SLOT(setAjoutSom())) ;
    QObject::connect(supprsom, SIGNAL(clicked()), this, SLOT(setSupprSom())) ;
    QObject::connect(ajoutarc, SIGNAL(clicked()), this, SLOT(setAjoutArc())) ;
    QObject::connect(supprarc, SIGNAL(clicked()), this, SLOT(setSupprArc())) ;
    QObject::connect(enregistrement, SIGNAL(clicked()), this, SLOT(setEnregistrement())) ;

    QPalette p ;
    p.setColor(QPalette::Background, Qt::red) ;

    setPalette(p);

}

Mainwin::~Mainwin()
{

    delete wid ;
    delete ajoutsom;
    delete supprsom ;
    delete ajoutarc ;
    delete supprarc ;
    delete value ;
    delete oriente ;
    delete dockLayout ;
    delete dockwid ;
    delete dock ;
    delete fichier ;
    delete graph ;

}

void Mainwin::afficherTab(int *d)
{
    w = new QWidget() ;
    QVBoxLayout *l = new QVBoxLayout ;
    w->setWindowTitle("Distances") ;
    table = new QTableWidget(w) ;

    int n = d[0] ;

    table->setRowCount(1) ;
    table->setColumnCount(n) ;
    table->resize(110*n,50) ;
    for(int i=1 ; i<=n ; ++i)
        table->setItem(0,i-1,new QTableWidgetItem(QString::number(d[i]))) ;


    w->setLayout(l) ;
    l->addWidget(table) ;
    w->show() ;
}

void Mainwin::chargerGraphe()
{

    if(wid->gcourant != NULL)
    {
        int rep = QMessageBox::warning(this, "Charger un graphe", "Supprimmer le graphe courant ?",QMessageBox::Yes|QMessageBox::No) ;

        if( rep == QMessageBox::No)
            return ;
    }
    delete wid->gcourant ;
    wid->gcourant = NULL ;
    QString f = QFileDialog::getOpenFileName(this, "Graphe a ouvrir") ;
    ifstream is(f.toStdString().c_str()) ;
    graphe *gcourant = graphe::lire(is) ;
    wid->setGraphe(gcourant) ;

    ifstream is2((f.toStdString()+"complexe").c_str()) ;
    int n ;
    is2 >> n ;
    wid->complexe.resize(n) ;
    string tmp ;
    for(int i=0 ; i<n ; ++i)
    {
        is2 >> tmp ;
        wid->complexe[i] = tmp.c_str() ;
    }

    grapheOV *gOV = dynamic_cast<grapheOV *>(gcourant) ;
    if(gOV != NULL)
    {
        value->setCheckState(Qt::Checked) ;
        oriente->setCheckState(Qt::Checked) ;
    }

    grapheNONV *gNONV = dynamic_cast<grapheNONV *>(gcourant) ;
    if(gNONV != NULL)
    {
        value->setCheckState(Qt::Unchecked) ;
        oriente->setCheckState(Qt::Unchecked) ;
    }
    grapheNOV *gNOV = dynamic_cast<grapheNOV *>(gcourant) ;
    if(gNOV != NULL)
    {
        value->setCheckState(Qt::Checked) ;
        oriente->setCheckState(Qt::Unchecked) ;
    }
    grapheONV *gONV = dynamic_cast<grapheONV *>(gcourant) ;
    if(gONV != NULL)
    {
        value->setCheckState(Qt::Unchecked) ;
        oriente->setCheckState(Qt::Checked) ;
    }
    wid->value = value->isChecked() ;
    wid->oriente = oriente->isChecked() ;

    wid->dessiner() ;
}

void Mainwin::sauvegarderGraphe()
{

    if(wid->gcourant == NULL)
    {
        //QMessageBox(QMessageBox::Information,"Sauvegarder un graphe", "Impossible de sauvegarder un graphe vide",QMessageBox::Ok) ;
        QMessageBox::information(this, "Sauvegarder un graphe", "Impossible de sauvegarder un graphe vide", QMessageBox::Ok) ;
        return ;
    }

    QString f = QFileDialog::getSaveFileName(this,"Sauvegarder un graphe", "graphe.g") ;
    ofstream os(f.toStdString().c_str()) ;
    graphe::ecrire(*(wid->gcourant), os) ;
    os.close() ;

    ofstream os2((f.toStdString()+"complexe").c_str()) ;
    int n = wid->gcourant->nbSommet() ;
    os2 << n << std::endl ;

    for(int i=0 ; i<(wid->item).size() ; ++i)
        os2 << ((wid->item[i])->info()).toStdString() << " " ;
    os2.close() ;

}

void Mainwin::nouveauGraphe()
{
    int rep = QMessageBox::warning(this, "nouveau graphe", "Supprimer le graphe courant ?",QMessageBox::Yes|QMessageBox::No) ;

    if( rep == QMessageBox::No)
        return ;

    bool ok ;
    QStringList items ;
    items << tr("OV") << tr("ONV") << tr("NOV") << tr("NONV") ;
    QString item = QInputDialog::getItem(this, tr("QInputDialog::getItem()"),tr("Type de graphe"),items, 0,false,&ok) ;

    if(!ok)
        return ;

    delete wid->gcourant ;

    if(item == "OV")
    {
        wid->gcourant = new grapheOV() ;
        value->setCheckState(Qt::Checked) ;
        wid->value = true ;
        oriente->setCheckState(Qt::Checked) ;
        wid->oriente = true ;
    }
    else if (item == "ONV")
    {
        wid->gcourant = new grapheONV() ;
        value->setCheckState(Qt::Unchecked) ;
        oriente->setCheckState(Qt::Checked) ;
        wid->value = false ;
        wid->oriente = true ;

    }
    else if(item == "NOV")
    {
        wid->gcourant = new grapheNOV() ;
        value->setCheckState(Qt::Checked) ;
        oriente->setCheckState(Qt::Unchecked) ;
        wid->value = true ;
        wid->oriente = false ;
    }
    else
    {
        wid->gcourant = new grapheNONV() ;
        value->setCheckState(Qt::Unchecked) ;
        oriente->setCheckState(Qt::Unchecked) ;
        wid->value = false ;
        wid->oriente = false ;
    }

    wid->aa = false ;
    ajoutarc->setChecked(false) ;
    wid->as = false ;
    ajoutsom->setChecked(false) ;
    wid->ss = false ;
    supprsom->setChecked(false) ;
    wid->sa = false ;
    supprarc->setChecked(false) ;

    wid->complexe.resize(0) ;
    wid->dessiner() ;
}

void Mainwin::setAjoutSom()
{
    if(ajoutsom->isChecked())
    {
        wid->as = true ;
        wid->aa = false ;
        wid->ss = false ;
        wid->sa = false ;
        wid->e = false ;
        supprsom->setChecked(false) ;
        supprarc->setChecked(false) ;
        ajoutarc->setChecked(false) ;
        enregistrement->setChecked(false) ;
    }
    else
        wid->as = false ;

}

void Mainwin::setSupprSom()
{
    if(supprsom->isChecked())
    {
        wid->as = false ;
        wid->aa = false ;
        wid->ss = true ; ;
        wid->sa = false ;
        ajoutsom->setChecked(false) ;
        supprarc->setChecked(false) ;
        ajoutarc->setChecked(false) ;
        wid->e = false ;
        enregistrement->setChecked(false) ;
        wid->dep = wid->arr = 0 ;
    }
    else
        wid->ss = false ;
}
void Mainwin::setAjoutArc()
{
    if(ajoutarc->isChecked())
    {
        wid->as = false ;
        wid->aa = true ;
        wid->ss = false ;
        wid->sa = false ;
        supprsom->setChecked(false) ;
        supprarc->setChecked(false) ;
        ajoutsom->setChecked(false) ;
        wid->e = false ;
        enregistrement->setChecked(false) ;
        wid->dep = wid->arr = 0 ;
    }
    else
        wid->aa = false ;
}
void Mainwin::setSupprArc()
{
    if(supprarc->isChecked())
    {
        wid->as = false ;
        wid->aa = false ;
        wid->ss = false ;
        wid->sa = true ;
        supprsom->setChecked(false) ;
        ajoutsom->setChecked(false) ;
        ajoutarc->setChecked(false) ;
        wid->e = false ;
        enregistrement->setChecked(false) ;
        wid->dep = wid->arr = 0 ;
    }
    else
        wid->sa = false ;
}

void Mainwin::setEnregistrement()
{
    if(enregistrement->isChecked())
    {
        wid->as = false ;
        wid->aa = false ;
        wid->ss = false ;
        wid->sa = false ;
        supprsom->setChecked(false) ;
        supprarc->setChecked(false) ;
        ajoutarc->setChecked(false) ;
        ajoutsom->setChecked(false) ;
        wid->e = true ;
        wid->dep = wid->arr = 0 ;
    }
    else
        wid->e = false ;
}

void Mainwin::dessinerDijkstra()
{
    wid->dessiner() ;

    grapheOV *gOV = NULL ;
    grapheNOV *gNOV = NULL ;
    gOV = dynamic_cast<grapheOV *>(wid->gcourant) ;
    gNOV = dynamic_cast<grapheNOV *>(wid->gcourant) ;

    if(gOV == NULL && gNOV == NULL)
    {
        QMessageBox::information(this, "Algorithme de Dijkstra","L' algo de Dyjksta ne s'execute que sur un graphe valu�",QMessageBox::Ok) ;
        return ;
    }

    bool ok ;
    int rep = QInputDialog::getInt(NULL, QString("Dijkstra"), QString("Sommet de depart ? :"),1,1,wid->gcourant->nbSommet(),1,&ok) ;
    int *d = NULL, *pere = NULL ;
    if(gOV != NULL)
        gOV->Dijkstra(rep,d,pere);
    else
        if(gNOV != NULL)
            gNOV->Dijkstra(rep,d,pere);

    int n = pere[0] ;
    for(int i=1 ; i<=n ; ++i)
    {
        if(pere[i] != 0)
        {
            wid->colorierArc(pere[i],i,QColor(Qt::red)) ;
        }
    }
    afficherTab(d) ;
}

void Mainwin::redessinerGraphe()
{
    wid->dessiner() ;
}

void Mainwin::rang()
{
    if(wid->gcourant == NULL)
        return ;

    grapheOV *gOV = dynamic_cast<grapheOV *>(wid->gcourant) ;
    grapheONV *gONV = dynamic_cast<grapheONV *>(wid->gcourant) ;

    if(gOV == NULL && gONV == NULL)
    {
        QMessageBox::information(this, "Algorithme du rang","L'algorithme du rang ne s'execute que sur un graphe orient�",QMessageBox::Ok) ;
        return ;
    }

    int *rg = NULL, *pilch, *prem ;

    if(gOV !=NULL)
        rg = gOV->rang(pilch,prem) ;
    else
        rg = gONV->rang(pilch,prem) ;

    if(rg == NULL)
        return ;

    int n = rg[0] ;
    QWidget *w = new QWidget() ;
    w->setWindowTitle("rang des sommets du graphe") ;
    QTableWidget *table = new QTableWidget(w) ;
    table->setRowCount(1) ;
    table->setColumnCount(n) ;
    table->resize(110*n,50) ;
    for(int i=1 ; i<=n ; ++i)
        table->setItem(0,i-1,new QTableWidgetItem(QString::number(rg[i]))) ;
    w->show() ;
}

void Mainwin::distances()
{
    if(wid->gcourant == NULL)
        return ;

    grapheOV *gOV = dynamic_cast<grapheOV *>(wid->gcourant) ;
    grapheONV *gONV = dynamic_cast<grapheONV *>(wid->gcourant) ;
    //grapheNOV *gNOV = dynamic_cast<grapheNOV *>(wid->gcourant) ;

    if(gOV == NULL && gONV == NULL /*&& gNOV == NULL*/)
    {
        QMessageBox::information(this, "Calcul des distances","On ne peut calculer les distances que sur un graphe orient�",QMessageBox::Ok) ;
        return ;
    }
    int *dist = NULL ;
    int n = wid->gcourant->nbSommet() ;
    bool ok ;
    int rep = rep = QInputDialog::getInt(NULL, QString("Distances"), QString("Calcul des distances pour le sommet ? :"),1,1,n,1,&ok) ;

    if(!ok)
        return ;

    if(gOV !=NULL)
        dist = gOV->dist(rep) ;
    else if(gONV != NULL)
        dist = gONV->dist(rep) ;
    /*
    else
        dist = gNOV->dist(rep) ;
        */
    if(dist == NULL)
        return ;

    QWidget *w = new QWidget() ;
    QVBoxLayout *l = new QVBoxLayout();
    w->setWindowTitle("Distance du sommet" + QString::number(rep)) ;
    w->setLayout(l) ;
    QTableWidget *table = new QTableWidget(w) ;
    //l->setWidget(w);
    table->setRowCount(1) ;
    table->setColumnCount(n) ;
    table->resize(110*n,50) ;
    for(int i=1 ; i<=n ; ++i)
        table->setItem(0,i-1,new QTableWidgetItem(QString::number(dist[i]))) ;
    l->addWidget(table) ;
    w->setLayout(l) ;
    w->show() ;
}

void Mainwin::coderPrufer()
{
    if(wid->gcourant == NULL)
        return ;

    grapheNONV *gNONV = NULL ;
    gNONV = dynamic_cast<grapheNONV *>(wid->gcourant) ;

    if(gNONV == NULL)
    {
        QMessageBox::information(this, "Codagede Pr�fer","Le codage de Pr�fer ne s'execute que sur un graphe non-orient� et non-valu�",QMessageBox::Ok) ;
        return ;
    }
    int *d = NULL ;
    if(!gNONV->est_arbre(d))
    {
        QMessageBox::information(this, "Codage de Pr�fer","Le graphe n'est pas un arbre",QMessageBox::Ok) ;
        return ;
    }
    if(d == NULL)
        return ;

    int n = d[0] ;

    QWidget *w = new QWidget() ;
    w->setWindowTitle("Codage de Pr�fer") ;
    QTableWidget *table = new QTableWidget(w) ;
    table->setRowCount(1) ;
    table->setColumnCount(n) ;
    table->resize(110*n,50) ;
    for(int i=1 ; i<=n ; ++i)
        table->setItem(0,i-1,new QTableWidgetItem(QString::number(d[i]))) ;
    w->show() ;
}



void Mainwin::dessinerKruskal()
{
    wid->dessiner() ;

    if(wid->gcourant == NULL)
        return ;

    int **arete = NULL ;
    grapheNOV * gNOV = dynamic_cast<grapheNOV *>(wid->gcourant) ;
    if(gNOV == NULL)
    {
        QMessageBox::information(this, "Algorithme de Kruskal","L' algo de Kruskal ne s'execute que sur un graphe non-orient� et valu�",QMessageBox::Ok) ;
        return ;
    }
    gNOV->Kruskal(arete) ;

    if(arete == NULL)
        return ;

    int n = wid->gcourant->nbSommet() ;

    for(int i=1 ; i<=n ; ++i)
    {
        for(int j=1 ; j<=n ; ++j)
            if(arete[i][j] == 1)
                wid->colorierArc(i,j,QColor(Qt::yellow)) ;

    }

}

void Mainwin::afficherDantzig()
{
    if(wid->gcourant== NULL)
        return ;

    int **dantzig = NULL ;
    grapheOV *gOV = dynamic_cast<grapheOV *>(wid->gcourant) ;
    if(gOV == NULL)
    {
        QMessageBox::information(this, "Algorithme de Dantzig","L' algo de Dantzig ne s'execute que sur un graphe orient� et valu�",QMessageBox::Ok) ;
        return ;
    }
    dantzig = gOV->Dantzig() ;
    if(dantzig == NULL)
        return ;

    int n = dantzig[0][0] ;
    QWidget *w = new QWidget() ;
    w->setWindowTitle("Dantzig") ;
    QTableWidget *table = new QTableWidget(w) ;
    table->setRowCount(n) ;
    table->setColumnCount(n) ;
    table->resize(110*n,50*n) ;
    for(int i=1 ; i<=n ; ++i)
        for(int j=1 ; j<=n ; ++j)
            table->setItem(j-1,i-1,new QTableWidgetItem(QString::number(dantzig[i][j]))) ;
    w->show() ;
}


