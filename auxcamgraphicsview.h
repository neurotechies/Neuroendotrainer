#ifndef AUXCAMGRAPHICSVIEW_H
#define AUXCAMGRAPHICSVIEW_H

#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QObject>
#include <QDebug>
#include <QGraphicsSceneMouseEvent>
#include <QMessageBox>
#include <QMouseEvent>
#include <string>
#include <vector>

using namespace std;

class auxcamgraphicsview : public QGraphicsView
{
    Q_OBJECT
public:
    explicit auxcamgraphicsview(QWidget *parent = 0);
    //void setScene(QGraphicsScene * scene);
    //void show();
    ~auxcamgraphicsview();

public slots:
    void mouseMoveEvent(QMouseEvent *e);
    void mousePressEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);


signals:
    void sendMouseClickEvent(string &clk, vector<int> &data);
    void sendMouseMoveData(vector<int> &data);
     void sendMouseReleaseEvent(vector<int> &data);
private:
    //QGraphicsScene *s;
};

#endif // AUXCAMGRAPHICSVIEW_H
