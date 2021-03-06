#include "about.h"
#include "globals.h"
#include "ui_about.h"

#include <QDesktopServices>
#include <QDate>
#include <QDebug>
#include <QUrl>


About::About(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::About)
{
    ui->setupUi(this);

    QString versionBuilder = QString("Version ") + SW_VERSION;
    ui->buidDateLabel->setText(versionBuilder);

    QIcon mIcon(":pslogo.png");
    setWindowTitle("About Packet Sender");
    setWindowIcon(mIcon);

    setWindowFlags(this->windowFlags() & ~Qt::WindowContextHelpButtonHint);


    ui->psLinkButton->setStyleSheet(HYPERLINKSTYLE);
    ui->psLinkButton->setIcon(QIcon(":pslogo.png"));
    ui->psLinkButton->setFlat(true);
    ui->psLinkButton->setCursor(Qt::PointingHandCursor);
    connect(ui->psLinkButton, SIGNAL(clicked()),
            this, SLOT(gotoPacketSenderDotCom()));

}

About::~About()
{
    delete ui;
}

void About::gotoPacketSenderDotCom()
{
    //Open URL in browser
    QDesktopServices::openUrl(QUrl("https://packetsender.com/"));

}

void About::gotoDanNagleDotCom()
{

    //Open URL in browser
    QDesktopServices::openUrl(QUrl("https://dannagle.com/"));

}


void About::gotoDanNaglePayPal()
{

    //Open URL in browser
    QDesktopServices::openUrl(QUrl("http://dannagle.com/paypal"));

}

void About::gotoNagleCode()
{
    //Open URL in browser
    QDesktopServices::openUrl(QUrl("http://twitter.com/NagleCode"));

}
