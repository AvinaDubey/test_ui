#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QIcon>
#include <QAction>
#include <QCheckBox>
#include <QHBoxLayout>
#include <QPushButton>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QRadioButton>
#include <QColorDialog>
#include <QLabel>
#include <QScrollArea>
#include <QScrollBar>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);

    void setuiforgroupbox1();
    void setuiforgroupbox2();
    void setuiforgroupbox3();
    void setuiforgroupbox4();
    void setuiforgroupbox5();

    QIcon newIcon;
    QIcon openIcon;
    QIcon cutIcon;
    QIcon copyIcon;
    QIcon pasteIcon;

    QIcon redoIcon,undoIcon,exportpdfIcon,printfileIcon,zoominIcon,zoomoutIcon;

    QIcon boldIcon ,italicIcon, underlineIcon;


    //creating actions:
    //QAction *newFile;
   // QAction *openFile;

    //push buttons for actions:
    QPushButton *newFile;
    QPushButton *openFile;
    QPushButton *cut;
    QPushButton *copy;
    QPushButton *paste;

    QPushButton *redoAction, *undoAction, *exportpdfAction, *printAction;

    QPushButton *boldAction, *italicAction, *underlineAction, *testButton;

    QRadioButton *zoominAction, *zoomoutAction;
    QLabel *label1,label2;
    QColorDialog *colorPalette;
    QScrollArea *scrollArea;
    QScrollBar *scrollBar;
    QWidget *scrollAreaWidgetContents;

    ~MainWindow();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
