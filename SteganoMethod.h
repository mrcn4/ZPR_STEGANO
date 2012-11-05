#pragma once
#include <qobject.h>
#include <QSharedPointer>
#include <QImage>
	typedef QSharedPointer<QString> PString;
	typedef QSharedPointer<QByteArray> PByteArray;
	typedef QList<QVariant> ArgsList;
	typedef QSharedPointer<ArgsList> PArgsList;
	typedef QSharedPointer<QImage> PImage;
class CSteganoMethod: public QObject
{
	Q_OBJECT
public:
	CSteganoMethod(void);
	virtual void encrypt(PString, PString,PByteArray, PArgsList)=0;
	virtual void decrypt(PString, PString,PByteArray, PArgsList)=0;
	virtual void makePreview(PString, PString,PByteArray, PArgsList)=0;
	virtual ~CSteganoMethod(void);
signals:
	void previewFinished(PImage);
	void encryptFinished(void);
	void decryptFinished(void);
	void progressChanged(int);
};
