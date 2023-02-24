#include "main_app.h"

MainApp::MainApp(QObject* parent)
    : QObject(parent) {
    connect(&producer_, &Producer::Update,
            &consumer_, &Consumer::OnUpdate);

    consumer_.moveToThread(&consumer_thread_);
    consumer_thread_.start();

    producer_.moveToThread(&producer_thread_);
    producer_thread_.start();

    // Everything is ready, let's start the production
    QMetaObject::invokeMethod(&producer_, "OnStart");
}
