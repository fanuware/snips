#ifndef SNIPS_SRC_CONSUMER_H
#define SNIPS_SRC_CONSUMER_H

#include <stdlib.h>

#include <QDebug>
#include <QObject>
#include <QRandomGenerator>
#include <QThread>

class Consumer : public QObject {
    Q_OBJECT

 public:
    Consumer(QObject* parent = nullptr) : QObject(parent) {}
    virtual ~Consumer() = default;

public slots:
    void OnUpdate(int count) {
        int sleep_for = 1000 + ((rand() % 11) - 5) * 100;
        qDebug() << "Consumer::OnUpdate: Count" << count <<
            "(sleep for:" << sleep_for << "ms)";
        QThread::msleep(sleep_for);
    }
};

#endif  // SNIPS_SRC_CONSUMER_H
