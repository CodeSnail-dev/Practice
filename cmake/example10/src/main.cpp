#include "TelNavCommonInterface.h"
#include <iostream>

void CB_ReceiveMessage(int /* out */ *pStatus, int /* out */ *pnValue, void /* out */ *pData, int nSize_t)
{
    std::cout<<"Enter CB_ReceiveMessage! "<<std::endl;

    std::cout<<"Enter CB_ReceiveMessage! "<< "|" << *pStatus << "|" << *pnValue << "|" << nSize_t << std::endl;
    return;
}


int main(int argc, char *argv[])
{
    std::cout<<"main! "<<std::endl;

    void *pHandle = NULL;
    pHandle = Initialize();
    if (NULL == pHandle)
    {
        std::cout<<"Initialize Navigation failed! "<<std::endl;

        return 0;
    }

    SetCallBackFunction(CB_ReceiveMessage);

    if(StartNavigation())
    {
        std::cout<<"Start Navigation! "<<std::endl;

//        sleep(30);

        ShowNavigation(0, 0, 0, 0);

        std::cout<<"E_LANGUAGE " << std::endl;

        SendNavigationInfo(E_LANGUAGE, 4, NULL, 0);
        SendNavigationInfo(E_LANGUAGE, 0, NULL, 0);
    }





    // Hang
    std::cout<<"Waiting for result ..... "<<std::endl;

    int opt;
    std::cin>>opt;

    return 0;
}