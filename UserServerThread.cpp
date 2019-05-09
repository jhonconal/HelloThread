//
// Created by jhonconal on 2019/5/9.
//

#include "UserServerThread.h"
UserServerThread::UserServerThread()
{
    m_threadRunning = true;
}

UserServerThread::~UserServerThread()
{
    m_threadRunning = false;
}

void UserServerThread::run()
{
    while (m_threadRunning) {
        cout <<endl<<"+++++User server thread running..." << endl;
        sleep(1);
    }
    //退出后资源回收TODO
}
bool UserServerThread::getThreadStatus()
{
    return  m_threadRunning;
}

void UserServerThread::setThreadStatus(bool status)
{
    this->m_threadRunning = status;
}