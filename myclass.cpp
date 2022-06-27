#include "myclass.h"

MyClass::MyClass(QObject *parent)
    : QObject{parent}, m_bReadOnly{false}
{

}

void MyClass::setReadOnly(bool bReadOnly)
{
    m_bReadOnly = bReadOnly;
    emit readOnlyStateChanged();
}

bool MyClass::isReadOnly() const
{
    return m_bReadOnly;
}
