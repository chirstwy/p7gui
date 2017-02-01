#include "copyFileAsync.h"

copyFileAsync::copyFileAsync(QObject *parent): QThread (parent)
{

}

void copyFileAsync::copyFile(p7_handle_t *handle, QString memory, QString dir, QString filename, QString newDir, QString newFilename)
{
    QMutexLocker locker(&_mutex);
    _handle = handle;
    _mem = memory;
    _dir = dir;
    _filename = filename;
    _newDir = newDir;
    _newFilename = newFilename;
}

void copyFileAsync::run()
{
    _mutex.lock();
    int err = p7_copyfile(_handle, _dir.toStdString().c_str(), _filename.toStdString().c_str(),
                          _newDir.toStdString().c_str(), _newFilename.toStdString().c_str(),
                         _mem.toStdString().c_str());
    _mutex.unlock();
    emit copied(err);
}
