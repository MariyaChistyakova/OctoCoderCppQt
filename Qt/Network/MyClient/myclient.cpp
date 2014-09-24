#include "MyClient.h"
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>
#include <QTime>
 #include <QApplication>
#include <QMessageBox>

MyClient::MyClient(const QString& strHost, int nPort, QWidget* pwgt /*=0*/) : QWidget(pwgt)
 , m_nNextBlockSize(0)
{
 m_pTcpSocket = new QTcpSocket(this);
 m_pTcpSocket->connectToHost(strHost, nPort);

 QPushButton* about = new QPushButton("About");
 QPushButton* close = new QPushButton("Close");
 QVBoxLayout* pvbxLayout = new QVBoxLayout;
 QHBoxLayout* phbxLayout = new QHBoxLayout;

 connect(m_pTcpSocket, SIGNAL(connected()), SLOT(slotSendToServer()));
 connect(m_pTcpSocket, SIGNAL(readyRead()), SLOT(slotReadyRead()));

 connect(about, SIGNAL(clicked()), SLOT(about()));
 connect(close, SIGNAL(clicked()),qApp, SLOT(quit()));

  m_ptxtInfo = new QTextEdit;
  m_ptxtInfo->setReadOnly(true);

  phbxLayout->addWidget(m_ptxtInfo);
  phbxLayout->addWidget(about);
  phbxLayout->addWidget(close);
  pvbxLayout->addWidget(new QLabel("<H1>Client</H1>"));
  pvbxLayout->addLayout(phbxLayout);
  setLayout(pvbxLayout);
 }

void MyClient::slotReadyRead()
{
 QDataStream in(m_pTcpSocket);
 in.setVersion(QDataStream::Qt_4_5);
 for (;;) {
 if (!m_nNextBlockSize) {

     if (m_pTcpSocket->bytesAvailable() < sizeof(quint16)) {
      break;
      }
      in >> m_nNextBlockSize;
      }
      if (m_pTcpSocket->bytesAvailable() < m_nNextBlockSize) {
      break;
      }
      QTime time;
      QString str;
      in >> time >> str;
      m_ptxtInfo->append(time.toString() + "Server has sent " + str);
      m_nNextBlockSize = 0;
      }
 }

void MyClient:: slotSendToServer()
{
    QByteArray arrBlock;
    QDataStream out(&arrBlock, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_5);
    out << quint16(0) << QTime::currentTime() << "Привет!";
    out.device()->seek(0);
    out << quint16(arrBlock.size()-sizeof(quint16));
    m_pTcpSocket->write(arrBlock);
}


void MyClient::about()
{
QLabel*  lbl = new QLabel("Приложение клиент");
lbl->show();
}

void MyClient::timer()
{

    QMessageBox* pmbx =
    new QMessageBox(QMessageBox::Question,
    "Exit",
    "Program will be close",
    QMessageBox::Yes |
    QMessageBox::Cancel
    );
    pmbx->setModal(true);
    int n = pmbx->exec();
    delete pmbx;
    if (n == QMessageBox::Yes) {
    qApp->quit();
    }
}
