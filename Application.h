#pragma once
#include "zpr_stegano.h"
#include "SteganoExecutor.h"
#include <QApplication>

class CApplication : public QApplication
{
    Q_OBJECT
public:
    explicit CApplication(int & argc, char ** argv);
signals:

public slots:
    void onEncryptButtonClicked();
    void onDecryptButtonClicked();
    void onProposeButtonClicked();
    void onPreviewButtonClicked();
    void onSteganoMethodChoosen(int Id);
    void onEncryptFinished(bool IsSuccess);
    void onDecryptFinished(bool IsSuccess);
    void onDecryptFinished(bool IsSuccess, QString DecryptedData);
    void onProposed(PArgsList args);
private:
    void configureWindow();
    void configureExecutor();

    ZPR_STEGANO m_Window;
    CSteganoExecutor m_Executor;
    PByteArray m_DecryptedData;
    bool m_WasDataToSaveAFile;
    int m_ChoosenMethodId;
};
