/* @Decription ͨ������ʵ���̰߳�ȫѭ������
* �䱾������һ��T���͵����� ����CHdata����һ��unsigned char���͵�����
* */
#pragma once
#include<stdlib.h>
#include<stdio.h>
#include<iostream>

using namespace std;

template<typename T>
class CirQueue
{

public:
    CirQueue();
    CirQueue(unsigned long maxlen);
    ~CirQueue();
public:
    void setMaxLen(unsigned long maxlen);
    bool isEmpty();
    bool isFull();

    void push(T element);
    T pop();
    T front();
    T back();
    T* begin();
    T* end();
    void clear();
    unsigned long writePos();
    unsigned long readPos();
    unsigned long MaxLength();
    unsigned long size();
     unsigned long M_LEN;


private:
    T *m_data = NULL;
    unsigned long m_front;
    unsigned long m_rear;

    unsigned long M_wrpos;//��ǰд��λ��
    unsigned long M_rdpos;//��ǰ��ȡλ��
public:

};

#include "CirQueue.h"

template<typename T>
CirQueue<T>::CirQueue()
{
    m_data = NULL;
    m_front = 0;
    m_rear = 0;
    M_LEN = 0;
    M_wrpos = 0;
    M_rdpos = 0;
}
/**
 * @brief ͨ��Ԥ����������Ŀռ��С������У����̶߳���������ڴ��������
 */
template<typename T>
CirQueue<T>::CirQueue(unsigned long maxlen)
{
    m_front = 0;
    m_rear = 0;
    M_rdpos = 0;
    M_wrpos = 0;
    M_LEN = maxlen;
    m_data = new T[M_LEN]();
}

template<typename T>
CirQueue<T>::~CirQueue()
{
    delete[] m_data;
    m_data = NULL;
}
/**
 * @brief ���·���ѭ�����е��ڴ��С
 */
template<typename T>
void CirQueue<T>::setMaxLen(unsigned long maxlen)
{
    m_front = 0;
    m_rear = 0;
    M_rdpos = 0;
    M_wrpos = 0;
    M_LEN = maxlen;
    if (m_data != NULL)
    {
        delete[] m_data;
    }
    m_data = new T[M_LEN]();
}

template<typename T>
bool CirQueue<T>::isFull()
{
    return m_front == ((m_rear + 1) % M_LEN);
}

template<typename T>
bool CirQueue<T>::isEmpty()
{
    return m_front == m_rear;
}

template<typename T>
void CirQueue<T>::push(T element)
{
    if (isFull())
    {
        printf("The Circle Queue Has  Be FULL yuanshiduilie !!\n");
        return;
    }
    m_data[m_rear] = element;
    M_wrpos = m_rear;
    m_rear = (m_rear + 1) % M_LEN;
}

template<typename T>
T CirQueue<T>::pop()
{
    if (isEmpty())
    {
        printf("The Circle Queue is Empty!!\n");
        return m_data[m_front];
    }
    m_front = (m_front + 1) % M_LEN;
    M_rdpos = m_front - 1;
    return m_data[m_front - 1];
}

template<typename T>
T CirQueue<T>::front()
{
    return m_data[m_front];
}

template<typename T>
T* CirQueue<T>::begin()
{
    return m_data + m_front;
}

template<typename T>
T CirQueue<T>::back()
{
    return m_data[m_rear - 1];
}


template<typename T>
T* CirQueue<T>::end()
{
    return m_data + m_rear - 1;
}

/**
 * @brief ��ȡѭ�����еķ����ڴ��С(��ǰ���Դ洢�Ķ�����󳤶�)
 */
template<typename T>
unsigned long CirQueue<T>::MaxLength()
{
    return M_LEN;
}
/**
 * @brief ��ȡ��ǰ��������Ч���ݵĳ���
 */
template<typename T>
unsigned long CirQueue<T>::size()
{
    return (m_rear - m_front + M_LEN) % M_LEN;
}

/**
 * ��ն���
 */
template<typename T>
void CirQueue<T>::clear()
{
    m_rear = m_front = 0;
}


