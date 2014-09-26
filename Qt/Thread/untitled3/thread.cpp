#include "thread.h"
#include <QString>
#include <iostream>
#include <QMutex>

using namespace std;

Thread::Thread()
{
    stopped = false;
}

void Thread::run()
{
    //Без использования mutex
//  while (!stopped)
//    cout << messageStr.toStdString();
//  stopped = false;
//  cout << endl;

  // С использованием  mutex (работает быстрее)

    for (;;) {
      mutex.lock();
      if (stopped) {
        stopped = false;
        mutex.unlock();
        break;
      }
      mutex.unlock();

      cerr << messageStr.toStdString();
    }
    cerr << endl;
}

void Thread::stop()
{
 //Без использования mutex
    //stopped = true;

  // С использованием  mutex (работает быстрее)
  mutex.lock();
  stopped = true;
  mutex.unlock();

  //Вариант с  QMutexLocker
//  QMutexLocker locker(&mutex);
//  stopped = true;

}
