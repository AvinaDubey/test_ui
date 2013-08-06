#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QGLWidget>
#include <QtOpenGL/QGLWidget>
#include <QPoint>

class glwidget : public QGLWidget
{
    Q_OBJECT
public:
    glwidget(QWidget *parent = 0);
    float angle;
    ~glwidget();


protected:
     void initializeGL();
     void resizeGL(int w, int h);
     void paintGL();
     void mousePressEvent(QMouseEvent *event);
     void mouseMoveEvent(QMouseEvent *event);
     virtual void keyPressEvent(QKeyEvent *event);

private:
     QPoint lastPos;
     int xRot;
     int yRot;
     int zRot;
     int spin;

     int dx;
     int dy;

     int sides;
     double radius;

public slots:
    void setXRotation(int angle);
    void setYRotation(int angle);
    void setZRotation(int angle);


};

#endif // GLWIDGET_H


