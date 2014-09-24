#ifndef _MyClient_h_
#define _MyClient_h_

#include <QWidget>
#include <QTcpSocket>
#include <QTextEdit>
#include <QLineEdit>
#include <QVBoxLayout>

class MyClient : public QWidget {
Q_OBJECT
private:
 QTcpSocket* m_pTcpSocket;
 QTextEdit* m_ptxtInfo;
 quint16 m_nNextBlockSize;
public:
 MyClient(const QString& strHost, int nPort, QWidget* pwgt = 0) ;
public slots:
 void slotReadyRead ( );
 void slotSendToServer( );
 void about();
 void timer();
};
#endif //_MyClient_h_
