/*
 * CommonInterface.h
 *
 *  Created on: 2015. 8. 26.
 *      Author: hyonghwan.choi
 *
 *  2015.Oct.28: Add TMC station List Struct Field - prepaid
 *
 */

#ifndef COMMONINTERFACE_H_
#define COMMONINTERFACE_H_

#include <string.h>
#define NAVI_APIS_VERSION_STRING         "2.6.1"
#define TMC_DATA_SIZE 8

//PhoneBook
#define TN_BT_PB_MAX_COUNT 5000
#define TN_BT_LENGTH_BT_DEVICE_NAME (248+1)
#define TN_PB_ADR_LENGTH (250+1)

#define TN_PSN_SIZE 8

typedef void (*CallbackFunction)(int *, int *, void *, int);

/*typedef struct _VEHICLE_INFORMATION_DATA_
{
	unsigned int nVehSpdAvgDrvn         : 15;   // 15 bit, E = N * 0.015625, 0 ~ 511.984375 km / h
	int nStrWhAng               		: 14;   // 14 bit, (signed value) E = (N << 2) * 0.0625, -2048 ~ 2047.9375 deg
	unsigned int nSysPwrMd              :  2;   //  2 bit, $0=Off, $1=Accessory, $2=Run, $3=Crank Request
	unsigned int nVehMovState           :  3;   //  3 bit, $0=Parked, $1=Neutral, $2=Forward, $3=Reverse, $4=Invalid
	unsigned int nFlLvlPct              :  8;   //  8 bit, E = N * 0.392157, 0 ~ 100.000035 %
	unsigned int nFuelTotCap            : 12;   // 12 bit, E = N * 0.125,    0 ~ 511.875 liters
	unsigned int nFuelLvlLwIO           :  1;   //  1 bit, $1=True; $0=False
	unsigned int nVehFuelRngCalc        : 17;    // 17 bit, E = N * 0.015625, 0 ~ 2047.984375 km
	bool bDimmingIsNight				: 1; 	//true: Night, false: Day
	unsigned int nUnit					: 2; 	// 2 bit,  $0=MEASUREMENT_METRIC,    $1=MEASUREMENT_IMPRIAL
} VehicleDataSrtuct, *pVehicleDataSrtuct;*/

//TMC
typedef struct _TMC_STATION_ITEM_T  // Renamed from _TMC_STATION_LIST_T 
{
	unsigned char index;
	unsigned char serviceId;
	unsigned short frequency;
	unsigned short PICode; // PI Code
	unsigned char prepaid;
	unsigned char currentlyTuned;//manualTuned->currentlyTuned
} TMC_STATION_ITEM_T;

typedef struct _TMC_STATION_LIST_T  // New Added structure, mentioned in c), used to provide a list of _TMC_STATION_ITEM_T
{
    TMC_STATION_ITEM_T tmcStationList[100];
    unsigned short count;
} TMC_STATION_LIST_T;


typedef struct _TMC_STATION_INFO_T
{
	signed char location_table_number;  //location_table_number_before_decryption
	signed char service_id;
	unsigned short PICode; // PI Code
	unsigned short frequency;
	unsigned char adminGroup;  // Ãß°¡µÊ (0x0, 0x1)
} TMC_STATION_INFO_T;

typedef struct _TMC_DATA_T
{
    unsigned char TmcData[8];
}TMC_DATA_T;


typedef struct _TMC_Station_PSN_T
{
      unsigned short usPICode;
      unsigned short usfrequency;
      unsigned char ucPSN[TN_PSN_SIZE];
} TMC_Station_PSN_T;



//GPS
typedef struct _GPS_DATA_T
{
     char GPSData[1024]	; //NMEA DATA format
} GPS_DATA_T ;

typedef struct _ONSTAR_DESTINATION_INFO_T
{
	unsigned char DestName1[35+2];
	unsigned char DestAddrNum[10+2];
	unsigned char DestStreetPrefix[2+2];	// ex) "NE", "S"
	unsigned char DestStreetName[35+2];
	unsigned char DestStreetType[4+2];	// ex) "St", "Hwy", or "Blvd".
	unsigned char DestStreetSuffix[2+2];	// ex) "NE", "S"
	unsigned char DestCity[35+2];
	unsigned char DestStateProvince[2+2];	// ex) "MX" is used for Mexico.
	unsigned char DestPhoneNum[16+2];
	int Longitude;
	int Latitude;
} ONSTAR_DESTINATION_INFO_T;

//Touch Position
typedef struct _TOUCH_POSITION_INFO_T
{
	unsigned int nPositionX;			// Touch position X
	unsigned int nPositionY;			// Touch position Y
}TOUCH_POSITION_INFO_T;

//Key profile
typedef struct _KEY_PROFILE_T
{
	unsigned char strKeyProfile; // driver id (DRIVER_ID_1(0), DRIVER_ID_2(1), DRIVER_ID_OTHER(2)
}KEY_PROFILE_T;

//Lockout State
typedef struct _LOCKOUT_STATE_T
{
	bool bLockoutState; // true: Lock, false: Unlock
}LOCKOUT_STATE_T;

typedef struct _CALL_POI_T
{
	char* Name; //temporary
	char* PhoneNum; // temporary
} CALL_POI_T;



typedef enum 
{
	TN_L2L_CONTINUE,
	TN_L2L_TURN_SLIGHT_RIGHT,
	TN_L2L_TURN_RIGHT,
	TN_L2L_TURN_HARD_RIGHT,
	TN_L2L_U_TURN,
	TN_L2L_TURN_HARD_LEFT,
	TN_L2L_TURN_LEFT,
	TN_L2L_TURN_SLIGHT_LEFT,
	TN_L2L_HOOK_TURN_RIGHT,
	TN_R2H_ENTER_LEFT,
	TN_R2H_ENTER_RIGHT,
	TN_H2R_EXIT_LEFT,
	TN_H2R_EXIT_RIGHT,
	TN_H2H_MERGE_LEFT,
	TN_H2H_MERGE_RIGHT,
	TN_H2H_MERGE_AHEAD,
	TN_DESTINATION_LEFT,
	TN_DESTINATION_RIGHT,
	TN_DESTINATION_AHEAD,
	TN_ROUNDABOUT_ENTER,
	TN_ROUNDABOUT_EXIT,
	TN_STAY_LEFT,
	TN_STAY_RIGHT,
	TN_STAY_MIDDLE,
	TN_FERRY_ENTER,
	TN_FERRY_EXIT,
	TN_H2H_EXIT_LEFT,
	TN_H2H_EXIT_RIGHT,
	TN_WAYPOINT_LEFT,
	TN_WAYPOINT_RIGHT,
	TN_WAYPOINT_AHEAD,

	TN_MAX_TYPE = 0xFF
} TN_TURN_TYPE_E;

typedef struct _TN_TURN_INDICATOR_T
{
	char* direction;   //Direction icon file string
	char* distance;         //Distance, unit is according to system current unit, here means to select metric system or British standard.
	char* message;           //String that show on the pop up title bar
} TN_TURN_INDICATOR_T;

typedef enum {
	E_TMC_STATION_INFO,
	E_TMC_DATA_ARR,
	E_TMC_STATION_STATUS,
	E_TMC_STATION_PSN,
} E_RECIVED_TMC_DATA;

typedef enum {
	E_VEHICLE_SPEED,
	E_VEHICLE_ANGLE,
	E_VEHICLE_KEY_MODE,
	E_VEHICLE_MOVE_STATE,
	E_VEHICLE_FUEL_LVL_PCT ,
	E_VEHICLE_FUEL_TOT_CAP,
	E_VEHICLE_FUEL_LVL_LWIO ,
	E_VEHICLE_FUEL_RNG_CALC,
	E_VEHICLE_DIMMING_IS_NIGHT,
	E_VEHICLE_NUNIT,
	
	E_MAX_VEHICLE_DATA = 0xFF
} E_VEHICLE_INFORMATION;

//Popup
typedef struct _TN_ICON_ALERT_POPUP_T
{
           char* icon;                      // icon file string
           char * messageLine1;         // first line message string
           char * messageLine2;         // second line message string
} TN_ICON_ALERT_POPUP_T; 


// BT Phonebook

typedef struct TN_BT_PBLIST_T
{
	int count;
	char name[TN_BT_PB_MAX_COUNT][TN_BT_LENGTH_BT_DEVICE_NAME];
	bool SimCard[TN_BT_PB_MAX_COUNT];
	int pb_idx[TN_BT_PB_MAX_COUNT];
	char adr[TN_BT_PB_MAX_COUNT][TN_PB_ADR_LENGTH];

	TN_BT_PBLIST_T()
	{
		count = 0;
		memset(name, 0x00, sizeof(name));
		memset(SimCard, 0x00, sizeof(SimCard));
		memset(pb_idx, 0x00, sizeof(pb_idx));
		memset(adr, 0x00, sizeof(adr));
	}
	void clear()
	{
		count = 0;
		memset(name, 0x00, sizeof(name));
		memset(SimCard, 0x00, sizeof(SimCard));
		memset(pb_idx, 0x00, sizeof(pb_idx));
		memset(adr, 0x00, sizeof(adr));
	}
}TN_BT_PBLIST;

//Calibration
typedef struct _TN_CAL_DATA_LIST_T {
    /*VE_PARAM */
    unsigned char ucSYS_VE_PARAM_VOLUME;        // for VE_PARAM_VOLUME
    unsigned char ucSYS_VE_PARAM_SPEECHRATE;   // for VE_PARAM_SPEECHRATE
    unsigned char ucSYS_VE_PARAM_PITCH;           // for VE_PARAM_PITCH
    unsigned char ucSYS_VE_PARAM_WAITFACTOR;    // Not Use

    /*CarBrand */
    unsigned char ucBRD_GM_VEHICLE_BRAND; // For displaying ordering of dealer locations

    /*POIBrowsingDepthDriverWorkload*/
    unsigned char ucSYS_POI_BROWSING_DEPTH_DWL; //POI Browsing Depth

    /*RecentDestinationListDriverWorkload*/
    unsigned char ucSYS_RECENT_DESTINATION_LIST_DWL; //Recent Destination List

    /*DEFAULT_POI_FUEL_STATION*/
    unsigned char ucSYS_DEFAULT_POI_FUEL_STATION; //Default Fuel type POI search base on vehicle configuration

    /*WARNING_SCREEN_FREQUENCY*/
    unsigned char ucSYS_WCS_WARNING_SCREEN_FREQUENCY; //How many ignition cycles before the display is shown again.  Differs by country.

    /*TRAFFIC_REROUTE_ALERT_DISTANCE_GUIDANCE*/
    /* The information alert will be shown when the user is not under route as well as if they are under route guidance
	  but the system didn't find a route that would save them more than 10 minutes,
	  and would be shown when the incident is 3 km ahead of them on their route. POP UP [Unit: measured in meters]*/
    unsigned char ucSYS_TRAFFIC_REROUTE_ALERT_DISTANCE_GUIDANCE[3];

   /*TRAFFIC_REROUTE_ALERT_TIME_GUIDANCE*/
   /*The information alert will be shown when the user is not under route as well as if they are under route guidance but
	the system didn't find a route that would save them more than 10 minutes, and would be shown when
	the incident is 3 km ahead of them on their route POP UP [Unit: measured in minutes]*/
    unsigned char ucSYS_TRAFFIC_REROUTE_ALERT_TIME_GUIDANCE;

   /* TTS */
   /* TTS languages shall be enabled/disabled via call file each by each. If disabled a ¡®GONG¡¯ shall be played instead*/
   	unsigned char ucSYS_GERMAN_EN; 
	unsigned char ucSYS_ENGLISH_EN;
	unsigned char ucSYS_ITALIAN_EN;
	unsigned char ucSYS_SPANISH_EN;
	unsigned char ucSYS_FRENCH_EN;
	unsigned char ucSYS_RUSSIAN_EN;
	unsigned char ucSYS_DUTCH_EN;
	unsigned char ucSYS_TURKISH_EN;
	unsigned char ucSYS_POLISH_EN; 
	unsigned char ucSYS_POTUGUESE_EN;
	unsigned char ucSYS_GREEK_EN; 
	unsigned char ucSYS_SWEDISH_EN; 
	unsigned char ucSYS_HUNGARIAN_EN;
	unsigned char ucSYS_DANISH_EN;
	unsigned char ucSYS_ROMANIAN_EN;
	unsigned char ucSYS_NORWEGIAN_EN;
	unsigned char ucSYS_FINNISH_EN;
	unsigned char ucSYS_CROATIAN_EN;
	unsigned char ucSYS_SLOVENIAN_EN;
	unsigned char ucSYS_CZECH_EN; 
	unsigned char ucSYS_SLOVAK_EN;
	unsigned char ucSYS_BULGARIAN_EN;
	unsigned char ucSYS_UKRAINIAN_EN; 
	unsigned char ucSYS_SERBIAN;

    /* PayTMC */
    /*Each PayTMC provider shall be enabled/disabled via call file for each country according to the following list*/
    unsigned char ucSYS_TMC_TYPE_BELGIUM;
    unsigned char ucSYS_TMC_TYPE_FINLAND;
    unsigned char ucSYS_TMC_TYPE_FRANCE;
    unsigned char ucSYS_TMC_TYPE_GERMMANY;
    unsigned char ucSYS_TMC_TYPE_LUXEMBOURG;
    unsigned char ucSYS_TMC_TYPE_NETHERLANDS;
    unsigned char ucSYS_TMC_TYPE_SWEDEN;
    unsigned char ucSYS_TMC_TYPE_UK;

    /* Need to add SpeedCam item, TN need to add */
    /* SpeedCams shall be enabled/disabled for each country separate*/

    /* Need to add Keypoards, TN nedd to add */
    /* Set of keyboards to be available for each country that can be chosen in HMI */

    /* Need to add TMC ,  TN need to add */
    unsigned char ucSYS_TMC_STATION_SLEC_INTERVAL; //Manual Selection Station interval
          		   
} TN_CAL_DATA_LIST_T;   //It is possible to add member value


//MgrNavi --> TeleNav
typedef enum
{
	E_VEHICLE_DATA  = 0x1,	/* Vehicle Data */
	E_GPS_DATA,				/* GPS Data */
	E_TMC_DATA,				/* TMC Data */
	E_ONSTAR_DESTINATION,	/* OnStar Destination */
	E_PHONEBOOK_ADDRESS,	/* Phone Book Address */
	E_VEHICLE_BRAND,		/* Vehicle brand */
	E_LANGUAGE,				/* Current Language, index of Language list 0 ~ 34(?) */
	E_TIME_FORMAT,			/* Time Format, hh:mm:ss */
	E_DATE_FORMAT,			/* Date  Format, yy:mm:dd */
	E_VOLUME_LEVEL,			/* Volume Level, 0 ~ 63 */
	/*0x11*/
	E_VOLUME_MUTE,			/* Volume Mute/Unmute, Mute is 0, Unmute is 1 */
	E_NAVIGATION_SETTING,	/* Navigation setting menu, only command */
	E_FACTORY_RESET,		/* Factory Reset, Reset Navigation environment. */
	E_MAP_UPDATE,			/* Map Update - TBD */
	E_HARDKEY,				/*front pannel key*/
	E_SWC_KEY,				/*steering wheel key*/
	E_KEY_PROFILE,			/*key profile ID*/
	E_LOCKOUT_STATE,		/*LockOut State check*/
	E_GUIDANCE_AUDIO_STREAMING_START,	/*ALT SOUND PATH OPENED*/
	E_DIPO_AA_TBT_START, 	/* CarPlay/Android Auto Start */
	/*0x21*/
    E_PHONE_CALL_STATE,
    E_BT_PHONE_STATE,
	E_MAX_DATA = 0xFF
} E_DATA_TYPE;


//TeleNav --> MgrNavi
typedef enum
{
	E_EXIT  = 0x1,				/* Navigation Exit */
	E_GUIDANCE_SOUND,			/* Audio Guidance*/
	E_MAP_UPDATE_R,			/* Map Update - TBD */
	E_POPUP,					/* Show Popup Message */

	E_STATUS_BAR,//0x5			/* Status Bar */
	E_GPS_DR,					/* GPS Map matching(DR) */
	E_TOUCH_EVENT,				/* Touch position feed back (x,y) */
	E_TMC_STATIONLIST,
	E_TURN_INDICATOR_INFO, 	/* Turn indicator Information */
	
	E_GUIDANCE_STATE,//0x10	/* Guidance State of Start/End */
	E_BACK_TO_MENU,			/* Back key in TN(Navigation setting / Factory reset) */
	E_CALL_POI,					/* POI call Information(Name, Phone number) */
	E_SOUND_FEEDBACK,			/* Touch sound feed back (Beep Sound) */
    E_NOW_PLAYING,              /* Touch "Now playing" button*/
    
    E_TMC_STATION_INFORMATION,          
	E_MAX_RECEIVE = 0xFF
} E_RECEIVE_TYPE;

typedef enum
{
	E_NONE_ENTRY  = 0x0,			/* None setting menu entry */
	E_SETTING_MENU,				/* Output Audio */
	E_FACTORY_SETTING,		/* Turn(TBT) Indicator Information */
	E_MAX_ENTRY = 0xFF
} E_ENTRY_TYPE;

typedef enum
{
	E_NONE_HARDKEY  = 0x0,		/* None HARD KEY */
	E_HARDKEY_HOME,				/* home key released */
	E_HARDKEY_VOL_UP,			/* volume up nob rotate*/
	E_HARDKEY_VOL_DOWN,			/* volume down nob rotate */
	E_HARDKEY_PREV,				/* previous key released */
	E_HARDKEY_NEXT,				/* next key released */

	E_MAX_HARDKEY = 0xFF
} E_ENUM_HARDKEY;

typedef enum
{
	E_NONE_SWC_KEY  = 0x0,			/* None SWC KEY */
	E_SWC_PTT,						/* SWC PTT KEY */
	E_SWC_MUTE,
	E_SWC_VOL_UP,
	E_SWC_VOL_DWN,
	E_SWC_SOURCE,
	E_SWC_PREV,
	E_SWC_NEXT,

	E_MAX_SWC_KEY = 0xFF
} E_ENUM_SWC_KEY;

typedef enum
{
	E_NONE_TOUCH_KEY  = 0x0,			/* None Touch */
	E_TOUCH_PRESS,						/* Touch Press */
	E_TOUCH_RELEASE,					/* Touch Release*/
	E_TOUCH_LONG_PRESS,					/* Touch Long Press */
	E_TOUCH_LONG_RELEASE,				/* Touch Long Release */

	E_MAX_TOUCH_KEY = 0xFF
} E_ENUM_TOUCH_EVENT;

typedef enum
{
	E_LANG_ID_AMERICAN_ENGLISH = 0,
	E_LANG_ID_GERMAN,
	E_LANG_ID_ITALIAN,
	E_LANG_ID_SWEDISH,
	E_LANG_ID_FRENCH,
	E_LANG_ID_SPANISH,
	E_LANG_ID_DUTCH,
	E_LANG_ID_PORTUGUESE,
	E_LANG_ID_NORWEGIAN,
	E_LANG_ID_FINNISH,
	E_LANG_ID_DANISH, //10
	E_LANG_ID_GREEK,
	E_LANG_ID_JAPANESE,
	E_LANG_ID_ARABIC,
	E_LANG_ID_STANDARD_CHINESE,
	E_LANG_ID_POLISH,
	E_LANG_ID_TURKISH,
	E_LANG_ID_KOREAN,
	E_LANG_ID_TRADITIONAL_CHINESE,
	E_LANG_ID_UK_ENGLISH,
	E_LANG_ID_HUNGARIAN, //20
	E_LANG_ID_CZECH,
	E_LANG_ID_SLOVAK,
	E_LANG_ID_RUSSIAN,
	E_LANG_ID_BRAZILIAN_PORTUGUESE,
	E_LANG_ID_THAI,
	E_LANG_ID_BULGARIAN,
	E_LANG_ID_ROMANIAN,
	E_LANG_ID_SLOVENIAN,
	E_LANG_ID_CROATIAN,
	E_LANG_ID_UKRAINIAN, //30
	E_LANG_ID_FRENCH_CANADIAN,
	E_LANG_ID_SPANISH_LATIN,
	E_LANG_ID_AU_ENGLISH,
	E_LANG_ID_UZBEK,
	E_LANG_ID_SERBIAN,  //35
	E_LANG_ID_MAX_SIZE
}E_LANGUAGE_ID;


typedef enum
{
	E_BRAND_NONE = 0,
	E_BRAND_BUICK,
 	E_BRAND_CADILLAC,
	E_BRAND_CHEVROLET,
	E_BRAND_DAEWOO,
	E_BRAND_GMC,
	E_BRAND_HOLDEN,
	E_BRAND_HUMMER,
	E_BRAND_ISUZU,
	E_BRAND_OPEL,
	E_BRAND_PONTIAC,
	E_BRAND_SAAB,
	E_BRAND_SATURN,
	E_BRAND_SUZUKI,
	E_BRAND_VAUXHALL,
	E_BRAND_HYBRID,
	E_BRAND_OPC,
	E_BRAND_VXR,
	E_BRAND_SAABVEH,
	E_BRAND_ECO,
	E_BRAND_SAAB_BOSE,
	E_BRAND_SGM_BUICK,
	E_BRAND_GMC_BLUE
}E_V_BRAND_CODE ;

typedef enum {
    E_MEASUREMENT_METRIC,
    E_MEASUREMENT_US,
    E_MEASUREMENT_IMPRIAL,
} E_MEASUREMENT_FORMAT;

typedef enum {
    TN_GUIDANCE_START = 1,
    TN_GUIDANCE_STOP,
} E_GUIDANCE_SOUND_ACTION;

//GSP/Map matching
typedef enum
{
    TN_TYPE_HIGHWAY             = 0 , //
    TN_TYPE_URBAN_HIGHWAY       = 1 , //
    TN_TYPE_NATIONAL_ROAD       = 2,  // Highway class road,  > 91KPH
    TN_TYPE_MAIN_DISTRICT_ROAD  = 3,  // Throughway class road (51-90 KPH)
    TN_TYPE_LOCAL_ROAD          = 4,  // Local road class road (31-50 KPH), i.e. Prefectural road
    TN_TYPE_FRONTAGE            = 5,  // Frontage road
    TN_TYPE_LOW_SPEED_ROAD      = 6,  // Very low speed road ( < 30 KPH)
    TN_TYPE_PRIVATE_ROAD        = 7,  // This attribute identifies Road Elements and Ferry Connections which are both private and do not allow through traffic.
    TN_TYPE_WALKWAY             = 8,  // Pedestrians only
    TN_TYPE_NON_NAVIGABLE       = 9,  // Non-navigable road
    TN_TYPE_SHIP_FERRY          = 10, // Ship Ferry route
    TN_TYPE_TRAIN_FERRY         = 11, // Train Ferry route
    TN_TYPE_PUBLIC_VEHICLE      = 12, // Public vehicle only road
    TN_TYPE_CARPOOL_LANE        = 13, // Carpool lane
    TN_TYPE_LAYOUT              = 14  // Layout lane
}TN_ROAD_TYPE;

typedef enum 
{
    TN_SUB_TYPE_TRAFFIC_CIRCLE           = 0, // Traffic Circle / Roundabout
    TN_SUB_TYPE_MAIN_ROAD_NO_SEP         = 1, // Main road (no separation between two-way traffic) link
    TN_SUB_TYPE_MAIN_ROAD_SEP            = 2, // Main road (separation between two-way traffic) link
    TN_SUB_TYPE_CONNECTION_ROAD          = 3, // Connection road (line between main roads) link
    TN_SUB_TYPE_LINK_WITHIN_INTERSECTION = 4, // Link within the intersection
    TN_SUB_TYPE_RAMP                     = 5, // Ramp
    TN_SUB_TYPE_SERVICE_ROAD             = 6, // Service road running alongside a main road.
    TN_SUB_TYPE_SA_SERVICE_ROAD_LINK     = 7, // SA service road link
    TN_SUB_TYPE_OVER_BRIDGE              = 9, // (Not Bridge)
    TN_SUB_TYPE_UNDERPASS                = 10,// UnderPass
    TN_SUB_TYPE_TUNNEL                   = 11,// Tunnel
    TN_SUB_TYPE_BRIDGE                   = 12 // Bridge
}TN_SUB_ROAD_TYPE;


typedef struct _TN_GNSS_DATA
{
    //UBX-NAV-PVT  message(navigation position velocity time solution)
    unsigned long pvt_iTOW;    //GPS time of week of navigation epoch in milli-second
    int           year;    //Year(UTC)
    int            month;   //month(UTC)
    int            day;     //day of month(UTC)
    unsigned char hour;    //hour of day(UTC)
    unsigned char min;     //minutes of hour(UTC)
    unsigned char sec;     //seconds of minute(UTC) in second
    unsigned char fixType; //GNSS fix type, range 0..5
    unsigned char flags;   //fix status flags
    unsigned char numSV;   //Number of satellites used in Nav Solution
    double        lon;    //longitude in degree
    double        lat;    //latitude in degree
    int           hMSL;    //Height above mean sea level in meter
    double        hAcc;   // Horizontal accuracy estimate in meter
    double        vAcc;   // vertical accuracy estimate in meter
    unsigned char gSpeed;  //ground speed in m/s
    double        headAcc; //heading accuracy estimate in degree
    float         headMot; //heading of motion in degree
    float         pvt_pDOP;    //position DOP
    //UBX-NA-DOP message(Dilution of precision)
    unsigned long dop_iTOW;   //GPS time of week of the navigation epoch
    float         dop_pDOP;   //position DOP
    float         dop_vDOP;   //vertical DOP
    float         dop_hDOP;   //horizontal DOP
}TN_GNSS_DATA;

typedef struct _TN_MAP_MATCHING_FEEDBACK
{
    unsigned long  iTOW;       //GPS millisecond reference time of week
    unsigned short flags;      //flags
    unsigned short headMM;     //heading of motion
    int           latMM;       //latitude
    int           lonMM;       //longitude
    int           altMM;       //alititude or height above mean sea level
    unsigned short posHAccMM;  //horizontal position accuracy
    unsigned short altAccMM;   //altitude accuracy
    unsigned short headAccMM;  //heading accuracy
    unsigned short reserved;   //Reserved
	unsigned short roadType;    //TN_ROAD_TYPE
    unsigned short subRoadType; //TN_SUB_ROAD_TYPE
    short          sMMConfidence; // MM confidence level: range: 0 to 6. 0 is the highest confidence, 6 is the lowest confidence.
    short          sNumOfLane;    // number of lanes of current street in driving direction: 0 if unsure
}TN_MAP_MATCHING_FEEDBACK;


/* defined interface (API)  */
void *Initialize(void);
void UnInitialize(/* in */ void *);
bool StartNavigation(void);
bool EndNavigation(void);

bool ShowNavigation(
		int,		/* input selected Language */
		int,		/* input selected Time display format */
		int,		/* input selected Date display format */
		int			/* input Entry Type */
		);

bool HideNavigation(void);
bool SendNavigationInfo(
		E_DATA_TYPE,	/* input, Data Type */
		int,			/* input, */
		void *,			/* input, actual data */
		int				/* input, size of data(void *) */
		);

bool SetCallBackFunction(CallbackFunction);

bool SetCalibrationData (TN_CAL_DATA_LIST_T* ptCalData);

bool GetNaviVersion(char **version);
bool CheckMapUpdate(char *strUrl);
bool StartMapUpdate(char *strUrl);
bool GetMapDataVersion(char *strUrl, char *strVersion);
bool GetModuleVersion(char *strVersion);

// Test usage by Telenav.
bool SendNaviInfo(int eType, int nValue, void *pData, int nSizeOfData);
//bool GetMapDataVersion(const char *strUrl, char **strVersion) ;
//bool GetMapDataAuth(const char *strUrl, int* errorType);
//bool GetMapDataCheckSum (const char *strUrl, unsigned int* CSum);
//bool GetMapDataSize (const char *strUrl, unsigned int* fSize);
//bool GetMapDataFileName(char **strMapName);
//bool GetMapUpdateMaxTime (int* strMapMaxTime);
//bool GetMapUpdateMNFVersion (const char *strUrl, char **strVersion);
//bool isMapDatacomplelted (const char *strUrl);


#endif /* COMMONINTERFACE_H_ */
