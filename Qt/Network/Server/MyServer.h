#ifndef _MyServer_h_
#define _MyServer_h_
#include <QWidget>
#include <QTcpSocket>
#include <QTcpServer>
#include <QTextEdit>
#include <QLineEdit>
// ======================================================================
class MyServer : public QWidget {
Q_OBJECT
private:
 QTcpServer* m_ptcpServer;
 QTextEdit* m_ptxt;
 QTextEdit* m_ptxtInfo;
 quint16 m_nNextBlockSize;
private:
 void sendToClient(QTcpSocket* pSocket, const QString& str);
public:
 MyServer(int nPort, QWidget* pwgt = 0);
public slots:
 virtual void slotNewConnection();
 void slotReadClient ();
 void about();
};
#endif //_MyServer_h_
