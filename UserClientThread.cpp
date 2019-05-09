//
// Created by jhonconal on 2019/5/9.
//

#include "UserClientThread.h"

UserClientThread::UserClientThread()
{
    m_threadRunning = true;
}

UserClientThread::~UserClientThread()
{
    m_threadRunning = false;
}

void UserClientThread::run()
{
    while (m_threadRunning)
    {
        cout<<endl<<">>>>>User client thread running..."<<endl;
        sleep(1);
    }
    //退出后资源回收TODO
}

bool UserClientThread::getThreadStatus()
{
    return  m_threadRunning;
}
void UserClientThread::setThreadStatus(bool status)
{
    this->m_threadRunning = status;
}