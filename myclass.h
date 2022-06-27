#ifndef MYCLASS_H
#define MYCLASS_H

#include <QObject>

class MyClass : public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool readOnly WRITE setReadOnly READ isReadOnly)

private:
    bool m_bReadOnly;

public:
    explicit MyClass(QObject *parent = nullptr);

public slots:
    void setReadOnly(bool bReadOnly);
    bool isReadOnly() const;

signals:
    void readOnlyStateChanged();

};

//==============================================================================

class NonQtClass {

private:
    bool m_bReadOnly;

public:
    NonQtClass() : m_bReadOnly(false)
    { }

    void setReadOnly(bool bReadOnly)
    {
        m_bReadOnly = bReadOnly;
    }

    bool isReadOnly() const
    {
        return m_bReadOnly;
    }
};

class MyWrapper : public QObject {
Q_OBJECT
Q_PROPERTY(bool readOnly WRITE setReadOnly READ isReadOnly)

private:
    NonQtClass m_nonQtObject;

public:
    MyWrapper(QObject* pobj = 0) : QObject(pobj) {}

public slots:
    void setReadOnly(bool bReadOnly)
    {
        m_nonQtObject.setReadOnly(bReadOnly);
        emit readOnlyStateChanged();
    }

    bool isReadOnly() const
    {
        return m_nonQtObject.isReadOnly();
    }

signals:
    void readOnlyStateChanged();

};


#endif // MYCLASS_H
