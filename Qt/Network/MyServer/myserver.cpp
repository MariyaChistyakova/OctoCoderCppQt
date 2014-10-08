#include "myserver.h"
#include <QLabel>
#include <QMessageBox>
#include <QVBoxLayout>
#include <QTime>
#include <QPushButton>
#include <QApplication>

MyServer::MyServer(int nPort, QWidget* pwgt /*=0*/) : QWidget(pwgt)
 , m_nNextBlockSize(0)
{
     m_ptcpServer = new QTcpServer(this);

     if (!m_ptcpServer->listen(QHostAddress::Any, nPort)) {
     QMessageBox::critical(0, "Server Error", "Unable to start the server:" + m_ptcpServer->errorString());
     m_ptcpServer->close();
     return;
     }

     connect(m_ptcpServer, SIGNAL(newConnection()),this, SLOT(slotNewConnection()));

     m_ptxt = new QTextEdit;
     m_ptxt->setReadOnly(true);

     QPushButton* about = new QPushButton("About");
     QPushButton* close = new QPushButton("Close");
     QVBoxLayout* pvbxLayout = new QVBoxLayout;
     QHBoxLayout* phbxLayout = new QHBoxLayout;

     connect(close, SIGNAL(clicked()),qApp, SLOT(quit()));
     connect(about, SIGNAL(clicked()), SLOT(about()));

     phbxLayout->addWidget(m_ptxt);
     phbxLayout->addWidget(about);
     phbxLayout->addWidget(close);
     pvbxLayout->addWidget(new QLabel("<H1>Server</H1>"));
     pvbxLayout->addLayout(phbxLayout);

     setLayout(pvbxLayout);
}

void MyServer::about()
{
    QLabel*  lbl = new QLabel("Приложение сервер");
    lbl->show();
}


void MyServer::sendToClient(QTcpSocket* pSocket, const QString& str)
{
     QByteArray arrBlock;
     QDataStream out(&arrBlock, QIODevice::WriteOnly);//??
     out.setVersion(QDataStream::Qt_4_5);
     out << quint16(0) << QTime::currentTime() << str;//Размер блока заранее не известен, вместо него записываем 0
     out.device()->seek(0);//указатель на начало блока
     out << quint16(arrBlock.size()-sizeof(quint16));
     pSocket->write(arrBlock);//Данные записываются в сокет
}


/*virtual*/ void MyServer::slotNewConnection()
{
 QTcpSocket* pClientSocket = m_ptcpServer->nextPendingConnection();

  connect(pClientSocket, SIGNAL(disconnected()),
  pClientSocket, SLOT(deleteLater())
  );
  connect(pClientSocket, SIGNAL(readyRead()),
  this, SLOT(slotReadClient())
  );

  sendToClient(pClientSocket, "Привет!");
  sendToClient(pClientSocket, "How are you?");
 }


void MyServer::slotReadClient()
{
    QTcpSocket* pClientSocket = (QTcpSocket*)sender(); //sender возвращает указатель на объект, который отправил сигнал
    QDataStream in(pClientSocket);
    in.setVersion(QDataStream::Qt_4_5);
    for (;;) {
    if (!m_nNextBlockSize) {
    if (pClientSocket->bytesAvailable() < sizeof(quint16)) {
    break;
    }
    in >> m_nNextBlockSize;//Переданные данные
    }
    if (pClientSocket->bytesAvailable()/*количество переданных байт*/ < m_nNextBlockSize) {
    break;
    }
    QTime time;
    QString str;
    in >> time >> str;
    QString strMessage =
    time.toString() + " " + "Client has sent — " + str;
    m_ptxt->append(strMessage);
    m_nNextBlockSize = 0;
    sendToClient(pClientSocket, "данные получены");
}
}

