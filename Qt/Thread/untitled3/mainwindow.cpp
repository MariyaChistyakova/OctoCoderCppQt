#include "mainwindow.h"
#include <QDialog>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QApplication>


ThreadForm::ThreadForm()
{

  threadA.messageStr = "A";
  threadB.messageStr = "B";

  threadAButton = new QPushButton("Start A");
  threadBButton = new QPushButton("Start B");
  quitButton = new QPushButton("Quit");
  quitButton->setDefault(true);

  QHBoxLayout* phbxLayout = new QHBoxLayout;
  QVBoxLayout* pvbxLayout = new QVBoxLayout;

  phbxLayout->addWidget(threadAButton);
  phbxLayout->addWidget(threadBButton);
  phbxLayout->addWidget(quitButton);
  pvbxLayout->addWidget(new QLabel("<H1>Threads</H1>"));
  pvbxLayout->addLayout(phbxLayout);
  setLayout(pvbxLayout);

  connect(threadAButton, SIGNAL(clicked()), SLOT(startOrStopThreadA()));
  connect(threadBButton, SIGNAL(clicked()), SLOT(startOrStopThreadB()));
  connect(quitButton, SIGNAL(clicked()),qApp, SLOT(quit()));
}
void ThreadForm::startOrStopThreadA()
{
    if (threadA.isRunning()) {
        threadA.stop();
        threadAButton->setText(tr("Start A"));
    } else {
        threadA.start();
        threadAButton->setText(tr("Stop A"));
    }
}

void ThreadForm::startOrStopThreadB()
{
  if (threadB.isRunning()) {
    threadB.stop();
    threadBButton->setText(tr("Start B"));
  } else {
    threadB.start();
    threadBButton->setText(tr("Stop B"));
  }
}


