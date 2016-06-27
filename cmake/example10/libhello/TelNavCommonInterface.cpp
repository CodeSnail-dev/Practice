/*
 * CommonInterface.h
 *
 *  Created on: 2015. 8. 26.
 *      Author: hyonghwan.choi
 *
 *  2015.Oct.28: Add TMC station List Struct Field - prepaid
 *
 */
#include <stdio.h>
#include "TelNavCommonInterface.h"

/* defined interface (API)  */
DllExport void *Initialize(void)
{
	printf("TelNavCommonInterface: %s()\n", __FUNCTION__);
	return NULL;
}
DllExport void UnInitialize(/* in */ void *)
{
	printf("TelNavCommonInterface: %s()\n", __FUNCTION__);	
}

DllExport bool StartNavigation(void)
{
	printf("TelNavCommonInterface: %s()\n", __FUNCTION__);	
	return true;
}

DllExport bool EndNavigation(void)
{
	printf("TelNavCommonInterface: %s()\n", __FUNCTION__);
	return true;
}

DllExport bool ShowNavigation(
		int,		/* input selected Language */
		int,		/* input selected Time display format */
		int,		/* input selected Date display format */
		int			/* input Entry Type */
		)
{
	printf("TelNavCommonInterface: %s()\n", __FUNCTION__);
	return true;
}

DllExport bool HideNavigation(void)
{
	printf("TelNavCommonInterface: %s()\n", __FUNCTION__);
	return true;
}
DllExport bool SendNavigationInfo(
		E_DATA_TYPE,	/* input, Data Type */
		int,			/* input, */
		void *,			/* input, actual data */
		int				/* input, size of data(void *) */
		)
{
	printf("TelNavCommonInterface: %s()\n", __FUNCTION__);
	return true;
}

DllExport bool SetCallBackFunction(CallbackFunction)
{
	printf("TelNavCommonInterface: %s()\n", __FUNCTION__);
	return true;
}

DllExport bool SetCalibrationData (TN_CAL_DATA_LIST_T* ptCalData)
{
	printf("TelNavCommonInterface: %s()\n", __FUNCTION__);
	return true;
}

DllExport bool GetNaviVersion(char **version)
{
	printf("TelNavCommonInterface: %s()\n", __FUNCTION__);
	return true;
}

DllExport bool CheckMapUpdate(char *strUrl)
{
	printf("TelNavCommonInterface: %s()\n", __FUNCTION__);
	return true;
}
DllExport bool StartMapUpdate(char *strUrl)
{
	printf("TelNavCommonInterface: %s()\n", __FUNCTION__);
	return true;
}

DllExport bool GetMapDataVersion(char *strUrl, char *strVersion)
{
	printf("TelNavCommonInterface: %s()\n", __FUNCTION__);
	return true;
}

DllExport bool GetModuleVersion(char *strVersion)
{
	printf("TelNavCommonInterface: %s()\n", __FUNCTION__);
	return true;
}

// Test usage by Telenav.
DllExport bool SendNaviInfo(int eType, int nValue, void *pData, int nSizeOfData)
{
	printf("TelNavCommonInterface: %s()\n", __FUNCTION__);
	return true;
}
//bool GetMapDataVersion(const char *strUrl, char **strVersion) ;
//bool GetMapDataAuth(const char *strUrl, int* errorType);
//bool GetMapDataCheckSum (const char *strUrl, unsigned int* CSum);
//bool GetMapDataSize (const char *strUrl, unsigned int* fSize);
//bool GetMapDataFileName(char **strMapName);
//bool GetMapUpdateMaxTime (int* strMapMaxTime);
//bool GetMapUpdateMNFVersion (const char *strUrl, char **strVersion);
//bool isMapDatacomplelted (const char *strUrl);
