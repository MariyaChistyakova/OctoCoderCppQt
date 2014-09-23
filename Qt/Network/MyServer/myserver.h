#ifndef MYSERVER_H
#define MYSERVER_H

#include <QMainWindow>
#include <QTcpServer>
#include <QTcpSocket>
#include <QTextEdit>
#include <QWidget>


class MyServer : public QWidget
{
    Q_OBJECT
private:
    QTcpServer* m_ptcpServer;
    QTextEdit* m_ptxt;
    quint16 m_nNextBlockSize;
private:
 void sendToClient(QTcpSocket* pSocket, const QString& str);
public:
 MyServer(int nPort, QWidget* pwgt = 0);
public slots:
 void about();
 virtual void slotNewConnection();
 void slotConnection();
 void slotReadClient();
 //void slotWriteClient();
};

#endif // MYSERVER_H
