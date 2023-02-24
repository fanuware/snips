#ifndef SNIPS_SRC_PRODUCER_H
#define SNIPS_SRC_PRODUCER_H

#include <QDebug>
#include <QObject>
#include <QTimer>

class Producer : public QObject {
    Q_OBJECT

public:
    Producer(QObject* parent = nullptr) : QObject(parent), produce_timer_(this) {
        produce_timer_.setSingleShot(true);
        connect(&produce_timer_, &QTimer::timeout,
                this, &Producer::OnTimeout);
    }
    virtual ~Producer() = default;

public slots:
    void OnStart() {
        produce_timer_.start(0);
    }

signals:
    void Update(int count);

private slots:
    void OnTimeout() {
        qDebug() << "Producer::OnTimeout: Count " << count_;
        emit Update(count_++);
        produce_timer_.start(1000);
    }

private:
    QTimer produce_timer_;
    int count_ = 0;
};

#endif  // SNIPS_SRC_PRODUCER_H
