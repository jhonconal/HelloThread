//
// Created by jhonconal on 2019/5/9.
//

#ifndef HELLOCPLUS_USERCLIENTTHREAD_H
#define HELLOCPLUS_USERCLIENTTHREAD_H

#include "AbstractThread.h"

class UserClientThread:public  AbstractThread{
private:
    bool m_threadRunning;
protected:

public:
    UserClientThread();
    ~UserClientThread();

    void setThreadStatus(bool status);
    bool getThreadStatus();
    void  run();
};


#endif //HELLOCPLUS_USERCLIENTTHREAD_H
