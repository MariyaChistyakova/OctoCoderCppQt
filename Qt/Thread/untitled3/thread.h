#ifndef THREAD_H
#define THREAD_H

#include <QThread>
#include <QString>
#include <QMutex>


class Thread : public QThread
{
public:
  Thread();
  void run();
  void stop(); //terminate() метод может остановить поток в любой точке его выполнения, наш метод нет.

public:
  QString messageStr;

private:
  volatile bool stopped;//Доступ может осуществляться и из других потоков.
  QMutex mutex;
};


#endif // THREAD_H
