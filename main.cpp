#include "PMInitController.h"
#include <QApplication>

#include "PMSettingsAccess.h"
#include "PMExplorerWidget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // get settings file URL
    QString settingsFile = "settings.pm";
    if ( argc == 2 ){
        settingsFile = QString(argv[ 1 ]);
    }

    // settings singleton
    PMSettings *settings = PMSettingsAccess::instance()->getSettings();
    settings->setFileUrl(settingsFile);
    settings->load();

    // widget
    PMInitController w;

    //PMExplorerWidget w;
    //w.setRootPath("/Users/sprigent/Desktop/server/admin");
    //w.show();

    QString styleFile = "/Users/sprigent/code/PMTansfert2/stylesheet.css";
    a.setStyleSheet("file:///" + styleFile);
    return a.exec();
}
