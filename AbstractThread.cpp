//
// Created by jhonconal on 2019/5/9.
//

#include "AbstractThread.h"

AbstractThread::AbstractThread()
{

}
AbstractThread::~AbstractThread()
{

}

bool AbstractThread::Start(bool thread_deteach)
{
    if(thread_deteach){
        pthread_attr_init(&m_attr);
        pthread_attr_setdetachstate(&m_attr,PTHREAD_CREATE_DETACHED);
        if (pthread_create(&m_pthreadId, &m_attr, Startup, (void *) this) != 0) {
            return false;
        }
    }
    else{
        if (pthread_create(&m_pthreadId, NULL, Startup, (void *) this) != 0) {
            return false;
        }
    }
    return true;
}

void* AbstractThread::Startup(void *arg)
{
    AbstractThread *thread = (AbstractThread*)arg;
    thread->run();//实体
}

void AbstractThread::join()
{
    cout<<"thread join..."<<endl;
    pthread_join(this->m_pthreadId,NULL);
}

pthread_t AbstractThread::getThreadId()
{
    return  this->m_pthreadId;
}
void AbstractThread::setThreadName(const string name)
{
    this->m_threadName = name;
}

const string AbstractThread::getThreadName()
{
    return  this->m_threadName;
}

bool AbstractThread::detach(pthread_t id)
{
    bool status = pthread_detach(id);
    return  status;
}