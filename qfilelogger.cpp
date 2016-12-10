#include <QDebug>
#include <QTextStream>

#include "qfilelogger.h"

using namespace logger;

static QFileLogger* instance;

QFileLogger::QFileLogger(QString filepath, LogLevel level) : filepath(filepath), file(filepath), level(level) {
    if(!file.open(QIODevice::WriteOnly | QIODevice::Append)) {
        qDebug() << "[QFileLogger] :: failed to open log file";
    }
}

QFileLogger* QFileLogger::Instance() {
    return instance;
}

QFileLogger* QFileLogger::CreateLogger(QString filepath, LogLevel level) {
    if(!instance) {
        instance = new QFileLogger(filepath, level);
    }

    return instance;
}

void QFileLogger::AddLog(const char* msg) {

    QTextStream out(&file);
    out << msg << "\r\n";
}


void QFileLogger::Debug(const char* msg) {
    if(level <= DEBUG) {
         AddLog(msg);
    }
}

void QFileLogger::Info(const char* msg) {
    if(level <= INFO) {
         AddLog(msg);
    }
}

void QFileLogger::Warning(const char* msg) {
    if(level <= WARNING) {
         AddLog(msg);
    }
}

void QFileLogger::Critical(const char* msg) {
    if(level <= CRITICAL) {
         AddLog(msg);
    }
}

void QFileLogger::Error(const char* msg) {
    if(level <= ERROR) {
         AddLog(msg);
    }
}
