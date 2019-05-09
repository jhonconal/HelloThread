//
// Created by jhonconal on 2019/5/9.
//

#ifndef HELLOCPLUS_USERSERVERTHREAD_H
#define HELLOCPLUS_USERSERVERTHREAD_H

#include "AbstractThread.h"

class UserServerThread:public AbstractThread{
private:
    bool m_threadRunning;
protected:

public:
    UserServerThread();
    ~UserServerThread();
    void setThreadStatus(bool status);
    bool getThreadStatus();
    void run();
};


#endif //HELLOCPLUS_USERSERVERTHREAD_H
