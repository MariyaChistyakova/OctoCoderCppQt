#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QPushButton>
#include "thread.h"

class ThreadForm : public QWidget
{
  Q_OBJECT
public:
  ThreadForm();


private slots:
  void startOrStopThreadA();
  void startOrStopThreadB();

private:
  Thread threadA;
  Thread threadB;
  QPushButton *threadAButton;
  QPushButton *threadBButton;
  QPushButton *quitButton;
};


#endif // MAINWINDOW_H

