#ifndef ANALISISDIR_H
#define ANALISISDIR_H

#include <QStringList>
#include <QDateTime>
#include <QString>
#include <QDir>



class AnalisisDir
{
private:
    QDir m_base;
    QDir m_direc;
    QStringList m_contenido;
    QStringList m_propiedades;
public:
    AnalisisDir();
    explicit AnalisisDir(QDir base);
    void setDirec(QDir direc);
    void setBase(QDir base);
    QString base();
    QStringList contenido();
    QString propiedades();

};

#endif // ANALISISDIR_H
