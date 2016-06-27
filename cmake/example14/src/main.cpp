#include "CommonInterface.h"
#include "NavShell.h"
#include <stdio.h>

int main()
{
    Initialize();
    
	setInitializeToShell(Initialize);
	setStartNavigationToShell(StartNavigation);
	setShowNavigationToShell(ShowNavigation);
	

	setUnInitializeToShell(UnInitialize);
	setEndNavigationToShell(EndNavigation);
	setHideNavigationToShell(HideNavigation);
	setSendNavigationInfoToShell(SendNavigationInfo);
	setSetCallBackFunctionToShell(SetCallBackFunction);
	setSetCalibrationDataToShell(SetCalibrationData);
	setGetNaviVersionToShell(GetNaviVersion);
	setCheckMapUpdateToShell(CheckMapUpdate);
	setStartMapUpdateToShell(StartMapUpdate);
	setGetMapDataVersionToShell(GetMapDataVersion);
	setGetModuleVersionToShell(GetModuleVersion);
	
	shellStartUp();
	
	return 0;
}