#include "glwidget.h"
#include <QtGui/QMouseEvent>
#include<QKeyEvent>
#include <math.h>
#include<gl/GLU.h>

#ifndef GL_MULTISAMPLE
#define GL_MULTISAMPLE  0x809D
#endif

#define maxpts  5
int pointarray[maxpts][2];
int copypointarray[maxpts][2];
int click = 0;

glwidget::glwidget(QWidget *parent)
{
    setMouseTracking(true);
    setFocusPolicy(Qt::ClickFocus);//to enable keypressevent.

    xRot = 0;
    yRot = 0;
    zRot = 0;
    spin = 0;

}

void glwidget::initializeGL()
{


    dx = 50;
    dy = 100;
    //glDisable(GL_TEXTURE_2D);
    //glDisable(GL_COLOR_MATERIAL);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);
    glEnable(GL_LINE_STRIP);
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
    glClearColor(1,1,1,0);
    glEnable(GL_MULTISAMPLE);
}

void glwidget::resizeGL(int w, int h)
{

     glViewport( 0, 0 ,  w, h);
     glMatrixMode(GL_PROJECTION);
     glLoadIdentity();
     glOrtho(0, w, 0, h, -1.0l, 1.0l); // set origin to bottom left corner
     glMatrixMode(GL_MODELVIEW);
     glLoadIdentity();
 }

void glwidget::paintGL()
{
     glClear(GL_COLOR_BUFFER_BIT |  GL_DEPTH_BUFFER_BIT );
     glLoadIdentity();

     glPointSize(5.0);

     if (click == 0)
     {
         glBegin(GL_POINTS);
         glColor3f(1.0,0,0);
         glVertex2d(pointarray[0][0],pointarray[0][1]);
     }
     else
     {
        glBegin(GL_LINE_STRIP);
        glColor3f(1.0,0,0);
        for(int a = 0; a < click ; a++)
        {
             glVertex2d(pointarray[a-1][0],pointarray[a-1][1]);
            glVertex2d(pointarray[a][0],pointarray[a][1]);
        }
     glEnd();
     }

 }

void glwidget::mousePressEvent(QMouseEvent *event)
{
    //lastPos = event->pos();
    printf("inside mouse press event\n%d, %d\n", event->x(), event->y());

    if(event->buttons() & Qt::LeftButton)
    {
        if(click < maxpts)
        {
            //copying points vertices:
            /*if(click != 0)
            {
                copypointarray[click-1][0] = pointarray[click-1][0];
                copypointarray[click-1][1] = pointarray[click-1][1];
            }*/

            pointarray[click][0] = event->x();
            pointarray[click][1] = event->y();


        }
        click++;

    }
    updateGL();

}

void glwidget::mouseMoveEvent(QMouseEvent *event)
{
     //printf("%d, %d\n", event->x(), event->y());
     /*dx = event->x() - lastPos.x();
     dy = event->y() - lastPos.y();*/

    /*if(event->buttons() & Qt::LeftButton)
    {
        setXRotation(xRot + 8 * dy);
        setYRotation(yRot + 8 * dx);
    }
    else if (event->buttons() & Qt::RightButton)
    {
        setXRotation(xRot + 8 * dy);
        setZRotation(zRot + 8 * dx);
    }
    updateGL();
    lastPos = event->pos();*/

}

void glwidget::keyPressEvent(QKeyEvent* event)
{
     switch(event->key())
     {
     case Qt::Key_Escape:
         glClear(GL_COLOR_BUFFER_BIT);
         glClearColor(1,0,1,0);
         printf("\n Inside key press event ");
         //close();
         break;
     default:
        // event->ignore();
         break;
     }
}

static void qNormalizeAngle(int &angle)
{
    while (angle < 0)
        angle += 360 * 16;
    while (angle > 360 * 16)
        angle -= 360 * 16;
}

void glwidget::setXRotation(int angle)
{
    qNormalizeAngle(angle);
    if (angle != xRot)
        xRot = angle;
}

void glwidget::setYRotation(int angle)
{
    qNormalizeAngle(angle);
    if (angle != yRot)
        yRot = angle;
}

void glwidget::setZRotation(int angle)
{
    qNormalizeAngle(angle);
    if (angle != zRot)
        zRot = angle;
}


glwidget::~glwidget()
{

}

//Tried different shapes :

//glTranslatef(0.0f,0.0f,-3.0f);
//tried lines :
/* glColor3f(1.0,0.0,0.0);
glBegin(GL_LINES);
glVertex2f(25,40);
glVertex2f(dx,dy);
printf("/n inside paintGL :%d, %d\n " ,dx,dy);
glEnd();*/
//glRotatef(spin,0,0,1);
//glBegin(GL_LINE_LOOP);
/*glBegin(GL_POLYGON);
glColor3f(1.0,0.0,0.0);
glVertex2f(0,0);
glColor3f(0.0,1.0,0.0);
glVertex2f(50,100);
glColor3f(0.0,0.0,1.0);
glVertex2f(100,0);
     glEnd();*/

/*glVertex2f(0,0);
glVertex2f(100,300);
glVertex2f(300,100);*/
