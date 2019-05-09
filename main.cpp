#include <iostream>
#include "UserClientThread.h"
#include "UserServerThread.h"
int main() {
    std::cout << "Hello, World!" << std::endl;
    UserServerThread *mServer = new UserServerThread();
    UserClientThread *mClient = new UserClientThread();
    mServer->setThreadName(string("mServerThread"));
    mClient->setThreadName(string("mClientThread"));
    mServer->Start(true);
//    mClient->join();//等待进程结束
    mServer->detach(mServer->getThreadId());//线程分离 由系统回收资源
    mClient->Start(true);
    mClient->detach(mClient->getThreadId());//线程分离
//    mServer->join();//等待进程结束

    while (1)
    {
        cout<<endl<<"=====Main Thread running..."<<endl;
        sleep(1);
    }
    return 0;
}