#ifndef _MyClient_h_
#define _MyClient_h_
#include <QWidget>
#include <QTcpSocket>
#include <QTextEdit>
#include <QLineEdit>
#include <QVBoxLayout>
// ======================================================================
class MyClient : public QWidget {
Q_OBJECT
private:
 QTcpSocket* m_pTcpSocket;
 QTextEdit* m_ptxtInfo;
 QLineEdit* m_ptxtInput;
 quint16 m_nNextBlockSize;
public:
 MyClient(const QString& strHost, int nPort, QWidget* pwgt = 0) ;
private slots:
 void slotReadyRead ( );
 void slotError (QAbstractSocket::SocketError);
 void slotSendToServer( );
 void slotConnected ( );
 void about();
};
#endif //_MyClient_h_
