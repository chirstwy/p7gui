#ifndef COPYFILEASYNC_H
#define COPYFILEASYNC_H

#include <QThread>
#include <QMutex>
#include <libp7.h>

class copyfileAsync : public QThread
{
    Q_OBJECT
public:
    copyfileAsync(QObject *parent = NULL);

    void copyFile(p7_handle_t *handle, QString memory, QString dir, QString filename, QString newDir, QString newFilename);

signals:
    void deleted(FileInfoList lst, int err);

protected:
    void run();

private:
    QMutex _mutex;
    p7_handle_t* _handle;
    QString _mem;
    QString _dir;
    QString _filename;
    QString _newDir;
    QString _newFilename;
};

#endif // COPYFILEASYNC_H
