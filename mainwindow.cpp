#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QObject::connect( this->ui->action_About_App, &QAction::triggered,
                      this, &MainWindow::onAppAbout_triggered,
                      Qt::UniqueConnection );


    QObject::connect( this->ui->actionAbout_Qt, &QAction::triggered,
                      this, &MainWindow::onAboutQt_triggered,
                      Qt::UniqueConnection );
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onAppAbout_triggered()
{
    QVector<QPair<DialogSection, QString>> sectionStrings{
        { DialogSection::ICON, ":/tutor_exilius_logo.png" },
        { DialogSection::TITLE, "About CustomAboutDialogDemo" },
        { DialogSection::RELEASE_DATE, "Released: 2019-01-25" },
        { DialogSection::VERSION, "v1.0" },
        { DialogSection::SHORT_INFO, "That's a Tutor Exilius Qt project started 2019-01-24 on "
                                     "<a href=\"https://twitch.tv/tutorexilius\">https://twitch.tv/tutorexilius</a>" },
        { DialogSection::DESCRIPTION, "It's a try to implement a custom about dialog in Qt which can be used in different Qt GUI projects." },
        { DialogSection::AUTHOR, "Tutor Exilius" },
        { DialogSection::CREDITS, "Special thanks to my twitch community which supported in my live stream chat!" },
        { DialogSection::LICENCE, "GPLv3. See Licence.txt" },
        { DialogSection::RESOURCES, "You can download the source code on github: "
                    "<a href=\"https://github.com/tutorexilius/QtCustomAboutDialog\">https://github.com/tutorexilius/QtCustomAboutDialog</a>." }
    };

    CustomAboutDialog *about = new CustomAboutDialog{ this, sectionStrings };

    about->show();
}

void MainWindow::onAboutQt_triggered()
{
    QMessageBox::aboutQt( this );
}
