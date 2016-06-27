/*
 * TeleNaviAppAPI.cpp
 * Created on: 2015. 10. 9
 * Author    : Liang Jian
 * 
 */

#include "CommonInterface.h"
#include <stdio.h>
#include <string.h>

CallbackFunction mcb;

/* implementation interface(API) */
void *Initialize(void)
{
    // initialize TeleNav module(s)..., and return instance
	printf("Initialize\n");
    return "abc";
}

void UnInitialize(/* in */ void *pData)
{
	// Uninitialized TeleNav module(s)..., pData is returned instance
	printf("UnInitialize\n");
}

bool StartNavigation(void)
{
	// Start TeleNav Navigation, but not show Navigation screen
	bool ret = false;
	printf("UnInitialize\n");
	return true;
}

bool EndNavigation(void)
{
	// End TeleNav Navigation, but not unInitialize TeleNav module(s)
	bool ret = false;
	printf("EndNavigation\n");
	return ret;
}

bool ShowNavigation(int nLanguage, int nTimeFormat, int nDateFormat, int nEntryType)
{
	// Show the navigation screen, but not initialize and start TeleNav module(s)
	bool ret = false;
	printf("ShowNavigation\n");
	return ret;
}
 
bool HideNavigation(void)
{
	// Hide the navigation screen, but not uninitialized and exit TeleNav module(s)
	bool ret = false;
	printf("HideNavigation\n");
	return ret;
}

bool SendNavigationInfo(E_DATA_TYPE eType, int nValue, void *pData, int nSizeOfData)
{
    // Send data to TeleNav Navigation
	printf("SendNavigationInfo\n");
	
	mcb((int *)&eType, &nValue, pData, nSizeOfData);

    return true;
}

bool SetCallBackFunction(CallbackFunction f)
{
    printf("SetCallBackFunction\n");
    mcb = f;
    return true;
}

bool SetCalibrationData (TN_CAL_DATA_LIST_T* ptCalData)
{
	printf("SetCalibrationData\n");
	
	return true;
}

bool CheckMapUpdate(char *strUrl)
{
	bool ret = false;
	printf("CheckMapUpdate\n");
	return ret;
}

bool StartMapUpdate(char *strUrl)
{
	bool ret = false;
	printf("StartMapUpdate\n");
	return ret;
}

bool GetMapDataVersion(char *strUrl, char *strVersion)
{
	bool ret = false;
	printf("GetMapDataVersion\n");
	return ret;
}

bool GetModuleVersion(char *strVersion)
{
	bool ret = false;
	printf("GetModuleVersion\n");
	return ret;
}

void* getCallBackFunction()
{
	void *ret = 0;
	printf("getCallBackFunction\n");
	return ret;
}

bool GetNaviVersion(char **version)
{
	printf("GetNaviVersion\n");
    return true;
}

//------------------------------------------------------------------------------------------------
// Telenav debug interface
//------------------------------------------------------------------------------------------------

/*
 * Post a command to HMI
 */