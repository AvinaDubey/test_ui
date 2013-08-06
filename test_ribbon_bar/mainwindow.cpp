#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "glwidget.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Test project");
    this->setWindowIcon(QIcon(":new/images/office_btn.png"));

    setuiforgroupbox1();
    setuiforgroupbox2();
    setuiforgroupbox3();
    setuiforgroupbox4();
    setuiforgroupbox5();

   // QGLWidget *glWidget = new QGLWidget;
    glwidget *scene = new glwidget;
    QVBoxLayout *glLayout = new QVBoxLayout;
    glLayout->addWidget(scene);

    ui->widget->setLayout(glLayout);


}

void MainWindow::setuiforgroupbox1()
{
    newIcon  = QIcon::fromTheme("New", QIcon(":/new/images/filenew.png"));
    openIcon = QIcon::fromTheme("Open",QIcon(":/new/images/fileopen.png"));
    cutIcon  = QIcon::fromTheme("Cut",QIcon(":/new/images/editcut.png"));
    copyIcon = QIcon::fromTheme("Copy",QIcon(":/new/images/editcopy.png"));
    pasteIcon= QIcon::fromTheme("Paste",QIcon(":/new/images/editpaste.png"));


    newFile     = new QPushButton(newIcon,tr("New"),0);
    openFile    = new QPushButton(openIcon,tr("Open"),0);
    cut         = new QPushButton(cutIcon,tr("Cut"),0);
    copy        = new QPushButton(copyIcon,tr("Copy"),0);
    paste       = new QPushButton(pasteIcon,tr("Paste"),0);

    newFile->setFlat(true);
    openFile->setFlat(true);
    cut->setFlat(true);
    copy->setFlat(true);
    paste->setFlat(true);

    QGridLayout *gLayout = new QGridLayout;

    gLayout->addWidget(newFile,0,0,0);
    gLayout->addWidget(openFile,1,0,0);
    gLayout->addWidget(cut,0,1,0);
    gLayout->addWidget(copy,1,1,0);
    gLayout->addWidget(paste,2,0,0);


    ui->groupBox->setLayout(gLayout);
}

void MainWindow::setuiforgroupbox2()
{
    //redoIcon        = QIcon::fromTheme("Redo", QIcon(":/new/images/editredo.png"));
   // undoIcon        = QIcon::fromTheme("Undo", QIcon(":/new/images/editundo.png"));
    exportpdfIcon   = QIcon::fromTheme("Export Pdf", QIcon(":/new/images/exportpdf.png"));
    printfileIcon   = QIcon::fromTheme("Print", QIcon(":/new/images/fileprint.png"));
    zoominIcon      = QIcon::fromTheme("Zoom In", QIcon(":/new/images/zoomin.png"));
    zoomoutIcon     = QIcon::fromTheme("Zoom Out", QIcon(":/new/images/zoomout.png"));

   // redoAction      =   new QPushButton(redoIcon,tr("ReDo"),0);
   // undoAction      =   new QPushButton(undoIcon,tr("UnDo"),0);
    exportpdfAction =   new QPushButton(exportpdfIcon, tr("Export Pdf"),0);
    printAction   =   new QPushButton(printfileIcon, tr("Print Pdf"),0);
    zoominAction    =   new QRadioButton(tr("Zoom In"),0);
    zoomoutAction   =   new QRadioButton(tr("Zoom Out"),0);

    exportpdfAction->setFlat(true);
    printAction->setFlat(true);

   /* QHBoxLayout *h1 =   new QHBoxLayout;
    h1->addWidget(redoAction,0,0);
    h1->addWidget(undoAction,0,0);*/

    QHBoxLayout *h2 =   new QHBoxLayout;
    h2->addWidget(zoominAction,0,0);
    h2->addWidget(zoomoutAction,0,0);

    QHBoxLayout *h3 =   new QHBoxLayout;
    h3->addWidget(exportpdfAction,0,0);

    QHBoxLayout *h4 =   new QHBoxLayout;
    h4->addWidget(printAction);

    QVBoxLayout *mainLayout = new QVBoxLayout;
   // mainLayout->addLayout(h1);
    mainLayout->addLayout(h2);
    mainLayout->addLayout(h3);
    mainLayout->addLayout(h4);

    ui->groupBox_2->setLayout(mainLayout);
}

void MainWindow::setuiforgroupbox3()
{
   /* boldIcon    = QIcon::fromTheme("Bold", QIcon(":/new/images/textbold.png"));
    italicIcon  = QIcon::fromTheme("Italic", QIcon(":/new/images/textitalic.png"));
    underlineIcon=QIcon::fromTheme("Redo", QIcon(":/new/images/textunder.png"));

    boldAction      = new QPushButton(boldIcon, "" , 0);
    italicAction    = new QPushButton(italicIcon,"",0);
    underlineAction = new QPushButton(underlineIcon,"",0);

    QHBoxLayout *h31 = new QHBoxLayout;
    h31->addWidget(boldAction);
    h31->addWidget(italicAction);
    h31->addWidget(underlineAction);

   /* QHBoxLayout *h32 = new QHBoxLayout;
    h32->addWidget();*/



}

void MainWindow::setuiforgroupbox4()
{

}

void MainWindow::setuiforgroupbox5()
{
    ui->groupBox_5->setTitle("Color");

   /* colorPalette = new QColorDialog;
    scrollAreaWidgetContents = new QWidget(ui->groupBox_5,0);
    QVBoxLayout *layout = new QVBoxLayout;

    scrollArea = new QScrollArea(scrollAreaWidgetContents);
    scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);

    scrollAreaWidgetContents->setLayout(layout);
    layout->addWidget(colorPalette);


   // ui->groupBox_5->setLayout(layout);

    /*
    scrollBar = new QScrollBar;

    QGridLayout *ui5layout = new QGridLayout;
    ui5layout->addWidget(colorPalette);

    scrollAreaWidgetContents->setLayout(ui5layout);
    scrollArea->setWidget(scrollAreaWidgetContents);*/



}

MainWindow::~MainWindow()
{
    delete ui;
}
