//
// Created by jhonconal on 2019/5/9.
//

#ifndef HELLOCPLUS_ABSTRACTTHREAD_H
#define HELLOCPLUS_ABSTRACTTHREAD_H
#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
using namespace std;

class AbstractThread {
private:
    pthread_attr_t m_attr;
    pthread_t m_pthreadId;
    string    m_threadName;
private:
    static void *Startup(void *arg);//静态成员函数

protected:

public:
    AbstractThread();
    ~AbstractThread();
    bool Start(bool thread_deteach);
    virtual void  run()=0;//基类中的虚函数要么实现，要么是纯虚函数（绝对不允许声明不实现，也不纯虚）

    void  join(void);
    bool  detach(pthread_t id);

    const string getThreadName();
    void  setThreadName(const string name);

    pthread_t  getThreadId();
};


#endif //HELLOCPLUS_ABSTRACTTHREAD_H
