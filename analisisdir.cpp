#include "analisisdir.h"

AnalisisDir::AnalisisDir()
{

}

AnalisisDir::AnalisisDir(QDir base):m_base(base){
}

void AnalisisDir::setDirec(QDir direc){
    m_direc=direc;
}

void AnalisisDir::setBase(QDir base){
    m_base=base;
}

QString AnalisisDir::base()
{
    return m_base.path();
}

QStringList AnalisisDir::contenido(){
    if (m_base.exists()){
        m_contenido=m_base.entryList();
    }else {
        m_contenido.append("El directorio no existe");
    }
    return m_contenido;
}

QString AnalisisDir::propiedades()
{
    QString str;
    QFileInfo info(m_direc.path());

        str= "Nombre:" + info.fileName()+"\n";
        str += "Es directorio: " + QString(info.isDir() ? "SI":"NO")+"\n";
        str += "Se puede escribir: " + QString(info.isWritable() ? "SI":"NO")+"\n";
        str += "Es un ejecutable: " + QString(info.isExecutable() ? "SI":"NO")+"\n";
        str += "Última de creación: " + info.lastModified().toString()+"\n";
        str += "-------------------";

    return str;
}
