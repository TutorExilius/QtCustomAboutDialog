#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMap>
#include <QMessageBox>
#include "customaboutdialog.h"

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
    QMap<AboutSection, QString> sectionStrings{
        { AboutSection::LOGO, ":/tutor_exilius_logo_64x64.png" },
        { AboutSection::TITLE, "About CustomAboutDialogDemo" },
        { AboutSection::DATE, "Released: 2019-01-25" },
        { AboutSection::VERSION, "v1.0" },
        { AboutSection::SHORT_INFO, "That's a Tutor Exilius Qt project started 2019-01-24 on "
                                     "<a href=\"https://twitch.tv/tutorexilius\">https://twitch.tv/tutorexilius</a>" },
        { AboutSection::DESCRIPTION, "It's a try to implement a custom about dialog in Qt which can be used in different Qt GUI projects." },
        { AboutSection::AUTHOR, "Tutor Exilius" },
        { AboutSection::CREDITS, "Special thanks to my twitch community which supported in my live stream chat!" },
        { AboutSection::LICENCE, "GPLv3. See Licence.txt" },
        { AboutSection::RESOURCES, "You can download the source code on github: "
                    "<a href=\"https://github.com/tutorexilius/QtCustomAboutDialog\">https://github.com/tutorexilius/QtCustomAboutDialog</a>." }
    };

    CustomAboutDialog::about( this, sectionStrings );
}

void MainWindow::onAboutQt_triggered()
{
    QMessageBox::aboutQt( this );
}
