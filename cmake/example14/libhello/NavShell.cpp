/*
 * CommonInterface.h
 *
 *  Created on: 2016. 5. 31.
 *      Author: Liu Cheng
 *
 *  2016.May.31: A win32 shell to call interface of LGE
 *
 */

#include "NavShell.h"

void CB_ReceiveMessage(int /* out */ *pStatus, int /* out */ *pnValue, void /* out */ *pData, int nSize_t)
{
    std::cout<<"Enter CB_ReceiveMessage! "<<std::endl;

    std::cout<<"Enter CB_ReceiveMessage! "<< "|" << *pStatus << "|" << *pnValue << "|" << nSize_t << std::endl;
    return;
}

bool setInitializeToShell(TN_Initialize Initialize)
{
	bool ret = false;
	
	if (Initialize) {
		callbackFuncitonsToShell.Initialize = Initialize;
		ret = true;
	}
	
	return ret;
}

bool setUnInitializeToShell(TN_UnInitialize UnInitialize)
{
	bool ret = false;
	
	if (UnInitialize) {
		callbackFuncitonsToShell.UnInitialize = UnInitialize;
		ret = true;
	}
	
	return ret;
}

bool setStartNavigationToShell(TN_StartNavigation StartNavigation)
{
	bool ret = false;
	
	if (StartNavigation) {
		callbackFuncitonsToShell.StartNavigation = StartNavigation;
		ret = true;
	}
	
	return ret;
}

bool setEndNavigationToShell(TN_EndNavigation EndNavigation)
{
	bool ret = false;
	
	if (EndNavigation) {
		callbackFuncitonsToShell.EndNavigation = EndNavigation;
		ret = true;
	}
	
	return ret;
}

bool setShowNavigationToShell(TN_ShowNavigation ShowNavigation)
{
	bool ret = false;
	
	if (ShowNavigation) {
		callbackFuncitonsToShell.ShowNavigation = ShowNavigation;
		ret = true;
	}
	
	return ret;
}

bool setHideNavigationToShell(TN_HideNavigation HideNavigation)
{
	bool ret = false;
	
	if (HideNavigation) {
		callbackFuncitonsToShell.HideNavigation = HideNavigation;
		ret = true;
	}
	
	return ret;
}

bool setSendNavigationInfoToShell(TN_SendNavigationInfo SendNavigationInfo)
{
	bool ret = false;
	
	if (SendNavigationInfo) {
		callbackFuncitonsToShell.SendNavigationInfo = SendNavigationInfo;
		ret = true;
	}
	
	return ret;
}

bool setSetCallBackFunctionToShell(TN_SetCallBackFunction SetCallBackFunction)
{
	bool ret = false;
	
	if (SetCallBackFunction) {
		callbackFuncitonsToShell.SetCallBackFunction = SetCallBackFunction;
		ret = true;
	}
	
	return ret;
}

bool setSetCalibrationDataToShell(TN_SetCalibrationData SetCalibrationData)
{
	bool ret = false;
	
	if (SetCalibrationData) {
		callbackFuncitonsToShell.SetCalibrationData = SetCalibrationData;
		ret = true;
	}
	
	return ret;
}

bool setGetNaviVersionToShell(TN_GetNaviVersion GetNaviVersion)
{
	bool ret = false;
	
	if (GetNaviVersion) {
		callbackFuncitonsToShell.GetNaviVersion = GetNaviVersion;
		ret = true;
	}
	
	return ret;
}

bool setCheckMapUpdateToShell(TN_CheckMapUpdate CheckMapUpdate)
{
	bool ret = false;
	
	if (CheckMapUpdate) {
		callbackFuncitonsToShell.CheckMapUpdate = CheckMapUpdate;
		ret = true;
	}
	
	return ret;
}

bool setStartMapUpdateToShell(TN_StartMapUpdate StartMapUpdate)
{
	bool ret = false;
	
	if (StartMapUpdate) {
		callbackFuncitonsToShell.StartMapUpdate = StartMapUpdate;
		ret = true;
	}
	
	return ret;
}

bool setGetMapDataVersionToShell(TN_GetMapDataVersion GetMapDataVersion)
{
	bool ret = false;
	
	if (GetMapDataVersion) {
		callbackFuncitonsToShell.GetMapDataVersion = GetMapDataVersion;
		ret = true;
	}
	
	return ret;
}

bool setGetModuleVersionToShell(TN_GetModuleVersion GetModuleVersion)
{
	bool ret = false;
	
	if (GetModuleVersion) {
		callbackFuncitonsToShell.GetModuleVersion = GetModuleVersion;
		ret = true;
	}
	
	return ret;
}

int shellStartUp()
{
    std::cout<<"main! "<<std::endl;

    void *pHandle = NULL;
    pHandle = callbackFuncitonsToShell.Initialize();
    if (NULL == pHandle)
    {
        std::cout<<"Initialize Navigation failed! "<<std::endl;

        return 0;
    }

//    callbackFuncitonsToShell.SetCallBackFunction(CB_ReceiveMessage);

    if(callbackFuncitonsToShell.StartNavigation())
    {
        std::cout<<"Start Navigation! "<<std::endl;

//       Sleep(30000);

        callbackFuncitonsToShell.ShowNavigation(0, 0, 0, 0);

        std::cout<<"E_LANGUAGE " << std::endl;

//    callbackFuncitonsToShell.SendNavigationInfo(E_LANGUAGE, 4, NULL, 0);
//        SendNavigationInfo(E_LANGUAGE, 0, NULL, 0);
    }

    // Hang
    std::cout<<"Waiting for result ..... "<<std::endl;

    int opt;
    std::cin>>opt;

    return 0;
}