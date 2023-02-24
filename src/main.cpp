#include <QCoreApplication>
#include <QLoggingCategory>

#include "main_app.h"

int main(int argc, char *argv[]) {
    QCoreApplication app(argc, argv);

#ifdef DEBUG
    QLoggingCategory::defaultCategory()->setEnabled(QtDebugMsg, true);
    qSetMessagePattern("%{time [yyyy.MM.dd hh:mm:ss.zzz]} [%{type}] %{message}");
#else
    QLoggingCategory::defaultCategory()->setEnabled(QtInfoMsg, true);
    qSetMessagePattern("[%{type}] %{message}");
#endif

    MainApp main_app;

    return app.exec();
}
