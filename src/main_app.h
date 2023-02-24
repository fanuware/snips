#ifndef SNIPS_SRC_MAIN_APP_H
#define SNIPS_SRC_MAIN_APP_H

#include "consumer.h"
#include "producer.h"

#include <QObject>
#include <QThread>

class MainApp : public QObject {
    Q_OBJECT

 public:
    MainApp(QObject* parent = nullptr);
    virtual ~MainApp() = default;

private:
    Consumer consumer_;
    QThread consumer_thread_;

    Producer producer_;
    QThread producer_thread_;
};

#endif  // SNIPS_SRC_MAIN_APP_H
