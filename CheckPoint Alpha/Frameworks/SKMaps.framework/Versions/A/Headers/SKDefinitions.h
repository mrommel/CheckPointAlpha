//
//  SKDefinitions.h
//  SKMaps
//
//  Copyright (c) 2013 Skobbler. All rights reserved.
//

#ifndef SKMaps_SKDefinitions_h
#define SKMaps_SKDefinitions_h

#import <CoreLocation/CLLocation.h>

#pragma mark - General

typedef NS_ENUM(NSInteger,SKConnectivityMode)
{
    SKConnectivityModeOnline,
    SKConnectivityModeOffline
};

typedef NS_ENUM(NSInteger,SKPositionsLoggingType)
{
    SKPositionsLoggingTypeLOG,
    SKPositionsLoggingTypeGPX
};

typedef NS_ENUM(NSInteger,SKGPSAccuracyLevel)
{
    SKGPSAccuracyLevelUnknown = 0,
    SKGPSAccuracyLevelBad = 1,
    SKGPSAccuracyLevelMedium = 2,
    SKGPSAccuracyLevelGood = 3,
};

typedef NS_OPTIONS(NSInteger,SKMetaDataDownloadStatus)
{
    DownloadError = -1,
    NotExist = 0,
    Downloaded = 1,
    DownloadInProgress = 2
};

typedef NS_OPTIONS(NSInteger,SKAddPackageResult)
{
    SKAddPackageResultSuccess           = 0,
    SKAddPackageResultMissingTxgFile    = 1,
    SKAddPackageResultMissingSkmFile    = 1 << 1,
    SKAddPackageResultMissingNgiFile    = 1 << 2,
    SKAddPackageResultMissingNgiDatFile = 1 << 3,
    SKAddPackageResultCannotEraseFile   = 1 << 4
};

typedef struct
{
    double lonX;
    double latY;
    double accuracy;
} SKPosition;

#pragma mark - Map view

typedef NS_ENUM(NSInteger,SKMapViewStyleDetail)
{
    SKMapViewStyleDetailAuto,
    SKMapViewStyleDetailLow,
    SKMapViewStyleDetailMedium,
    SKMapViewStyleDetailHigh,
};

typedef NS_ENUM(NSInteger,SKMapDisplayMode)
{
    SKMapDisplayMode2D,
    SKMapDisplayMode3D
};

typedef NS_ENUM(NSInteger,SKMapStyle)
{
    SKDayStyle = 0,
    SKNightStyle
};

typedef NS_ENUM(NSInteger,SKMapFollowerMode)
{
    SKMapFollowerModeNone,
    SKMapFollowerModePosition,
    SKMapFollowerModePositionPlusHeading,
    SKMapFollowerModeNavigation
};

typedef NS_ENUM(NSInteger,SKOrientationIndicatorType)
{
    SKOrientationIndicatorNone,
    SKOrientationIndicatorDefault,
    SKOrientationIndicatorCustomImage
};

typedef NS_OPTIONS(NSInteger, SKMapDetailLevel)
{
    SKMapDetailLevelFull = 0,
    SKMapDetailLevelLight = 1,
    SKMapDetailLevelTomTom = 2
};

typedef NS_OPTIONS(NSInteger, SKGeocoderType)
{
    SKGeocoderTypeGoogle = 1,
    SKGeocoderTypeMapSearchOSM = 2,
    SKGeocoderTypeMapSearchTomTom = 3
};

typedef struct
{
    CLLocationCoordinate2D center;
    float zoomLevel;
} SKCoordinateRegion;

static const float kMaximumZoomLimit = 19.0f;
static const float kMinimumZoomLimit = 0.0;

typedef struct
{
    float mapZoomLimitMin;
    float mapZoomLimitMax;
} SKMapZoomLimits;

typedef NS_ENUM(NSInteger,SKAnnotationType)
{
    SKAnnotationTypePurple = 32,
    SKAnnotationTypeBlue = 33,
    SKAnnotationTypeGreen = 38,
    SKAnnotationTypeRed = 39,
    SKAnnotationTypeDestinationFlag = 47,
    SKAnnotationTypeMarker = 64,
    SKAnnotationTypeStaticSpeedcam2D = 67,
    SKAnnotationTypeMobileSpeedcam2D = 69,
    SKAnnotationTypeMobileSpeedcam3D = 70,
    SKAnnotationTypeStaticSpeedcam3D = 72,
    SKAnnotationTypeDangerZone2D = 77,
    SKAnnotationTypeDangerZone3D = 78,
    SKAnnotationTypeGPXWaypoint = 87,
    
    //Available only on traffic style:
    SKAnnotationTypeRoadConstruction = 205,
    SKAnnotationTypeRoadEvent = 203,
    SKAnnotationTypeRoadFlow = 204,
    SKAnnotationTypeRoadIncident = 201,
    SKAnnotationTypeRoadPolice = 200,
    
    SKAnnotationTypeHome = 102,
    SKAnnotationTypeWork = 103
};
typedef NS_ENUM(NSInteger, SKIncidentType)
{
    SKIncidentTypeUndefined = 0,
    SKIncidentTypeIncident = 1,
    SKIncidentTypeConstruction = 2,
    SKIncidentTypeEvent = 3,
    SKIncidentTypeFlow = 4,
    SKIncidentTypeWeather = 5,
    SKIncidentTypePolice = 6
};

typedef NS_OPTIONS(NSInteger, SKTrafficMode)
{
    SKTrafficModeDisabled = 0,
    SKTrafficModeIncidentsOnly = 1,
    SKTrafficModeFlowOnly = 2,
    SKTrafficModeTrafficAndIncidents = 3,
    SKTrafficModeExternalSource = 4
};

typedef NS_OPTIONS(NSInteger,SKPOIDisplayingOption)
{
    SKPOIDisplayingOptionNone = 0, // for not displaying POIs
    SKPOIDisplayingOptionCity = 1 << 0, // Refers to : country, state, city, town, village, suburb, hamlet, ocean, sea.
    SKPOIDisplayingOptionGeneral = 1 << 1, // Refers to : general POIs, except the ones mentioned above.
    SKPOIDisplayingOptionImportant = 1 << 2, // Refers to : unique POIs explicitly specified in the style JSON files.
};

#pragma mark - Routing & Navigation

typedef uint32_t SKRouteID;
typedef int SKTrackablePOIType;

typedef NS_ENUM(NSInteger,SKRouteMode)
{
    SKRouteCarShortest = 0,
    SKRouteCarFastest = 1,
    SKRouteCarEfficient = 2,
    SKRoutePedestrian = 3,
    SKRouteBicycleFastest = 4,
    SKRouteBicycleShortest = 5,
    SKRouteBicycleQuietest = 6,
};

typedef  NS_ENUM(NSInteger,SKStreetType)
{
    SKStreetTypeUndefined                         =0,
    SKStreetTypeBridleway                         =1,
    SKStreetTypeConstruction                      =2,
    SKStreetTypeCrossing                          =3,
    SKStreetTypeCycleway                          =4,
    SKStreetTypeFerry                             =5,
    SKStreetTypeFootway                           =6,
    SKStreetTypeFord                              =7,
    SKStreetTypeLiving_street                     =8,
    SKStreetTypeMotorway                          =9,
    SKStreetTypeMotorway_link                     =10,
    SKStreetTypePath                              =11,
    SKStreetTypePedestrian                        =12,
    SKStreetTypePrimary                           =13,
    SKStreetTypePrimary_link                      =14,
    SKStreetTypeResidential                       =15,
    SKStreetTypeRoad                              =16,
    SKStreetTypeSecondary                         =17,
    SKStreetTypeSecondary_link                    =18,
    SKStreetTypeService                           =19,
    SKStreetTypeSteps                             =20,
    SKStreetTypeTertiary                          =21,
    SKStreetTypeTertiary_link                     =22,
    SKStreetTypeTrack                             =23,
    SKStreetTypeTrunk                             =24,
    SKStreetTypeTrunk_link                        =25,
    SKStreetTypeUnclassified                      =26,
    SKStreetTypeFerryPed                          =310,
    SKStreetTypeResidential_limited               =311,
    SKStreetTypeUnpavedTrack                      =377,
    SKStreetTypePermissive                        =378,
    SKStreetTypeDestination                       =379,
    SKStreetTypePier                              =380
};

typedef NS_ENUM(NSInteger,SKTransportMode)
{
    SKTransportPedestrian = 0,
    SKTransportBicycle = 1,
    SKTransportCar = 2,
};

typedef NS_ENUM(NSInteger,SKRouteConnectionMode)
{
    SKRouteConnectionOnline = 0,
    SKRouteConnectionOffline = 1,
    SKRouteConnectionHybrid = 2
};

typedef NS_ENUM(NSInteger,SKNavigationType)
{
    SKNavigationTypeReal, // Real navigation, with real GPS positions from the device.
    SKNavigationTypeSimulation, // Simulate navigation on the current route, for testing/debugging purposes.
    SKNavigationTypeSimulationFromLogFile // Simulate navigation with positions from a log file, for testing/debugging purposes. For adding a positions log file, check the SKPositionerService documentation.
};

typedef NS_ENUM(NSInteger,SKRoutingErrorCode)
{
    SKRoutingErrorCodeNoResultsFound = 601,
    SKRoutingErrorCodeMissingArgument = 610,
    SKRoutingErrorCodeInvalidArgument = 611,
    SKRoutingErrorCodeUnsupportedServerCommand = 621,
    SKRoutingErrorCodeUnsupportedRequestType = 631,
    SKRoutingErrorCodeSameStartAndDestinationCoordinate = 680,
    SKRoutingErrorCodeInvalidStartCoordinate = 681,
    SKRoutingErrorCodeInvalidDestinationCoordinate = 682,
    SKRoutingErrorCodeCannotBeCalculated = 683,
    SKRoutingErrorCodeInvalidViaPoint = 684,
    SKRoutingErrorCodeInternalError = 690,
    SKRoutingErrorCodeExtComputationCanceled =  901,
    SKRoutingErrorCodeRotueCalculationTurnedOffline = 909,//The app was turned to offline mode, during an online routing
    SKRoutingErrorCodeInternetTurnedOff = 910,
};

typedef NS_ENUM(NSInteger,GPSDataFileType)
{
    SKGPXFileType,
    SKKMLFileType
};

typedef NS_ENUM(NSInteger,SKGPXComponentType)
{
    SKGPXRoute,
    SKGPXTrack,
    SKGPXWaypoint
};

#pragma mark - Internationalization

typedef NS_ENUM(NSInteger,SKDistanceFormat)
{
    SKDistanceFormatMetric=0,
    SKDistanceFormatMilesFeet,
    SKDistanceFormatMilesYards
};

typedef NS_ENUM(NSInteger,SKMapLanguage)
{
    SKMapLanguageLOCAL = 0,
    SKMapLanguageEN = 1,
    SKMapLanguageDE = 2,
    SKMapLanguageFR = 3,
    SKMapLanguageIT = 4,
    SKMapLanguageES = 5,
    SKMapLanguageRU = 6,
    SKMapLanguageTR = 7,
};

typedef NS_ENUM(NSInteger,SKRealReachUnit)
{
    SKRealReachUnitSecond = 0,
    SKRealReachUnitMeter = 1,
    SKRealReachUnitMiliAmp = 2,
};

typedef NS_ENUM(NSInteger,SKMapInternationalizationOption)
{
    SKMapInternationalizationOptionNone = 0,
    SKMapInternationalizationOptionLocal = 1,
    SKMapInternationalizationOptionTransliterated = 2,
    SKMapInternationalizationOptionInternational = 3,
};

#pragma mark - Searches

typedef NS_ENUM(NSInteger,SKSearchMode)
{
    SKSearchOnline = 0,
    SKSearchOffline = 1,
    SKSearchHybrid = 2
};

typedef NS_ENUM(NSInteger,SKListLevel)
{
    SKCountryList = 0,
    SKStateList = 1,
    SKCityList = 2,
    SKStreetList = 3,
    SKHouseNumberList = 4,
    SKInvalidListLevel = 5
};

typedef NS_ENUM(NSInteger,SKSearchResultType)
{
    SKSearchResultCountry= 0,
    SKSearchResultState = 1,
    SKSearchResultCity = 3,
    SKSearchResultZipCode = 4,
    SKSearchResultSuburb = 5,
    SKSearchResultNeighbourhood = 6,
    SKSearchResultHamlet = 7,
    SKSearchResultStreet = 8,
    SKSearchResultPOI = 9,
    SKSearchResultHouseNumber = 10,
    SKSearchResultWikiPoi,
    SKSearchResultCountryCode,
    SKSearchResultStateCode
};

typedef NS_ENUM(NSInteger,SKSearchResultSortType)
{
    SKMatchSort,
    SKProximitySort
};

typedef NS_ENUM(uint32_t,SKMapSearchStatus)
{
    SKNoError = 0, ///< no error, everything went fine
    SKNoSearchComponent, ///< search component it is not initialized or doesn't exist
    SKNoMapInformation, ///< no map available in the specified area
    SKMissingSearchFile, ///< no search file exist and the search was not started
    SKMissingSearchTerm, ///< the search string is missing
    SKMissingLanguageCode, ///< no language code is specified
    SKUnknownError ///< an error had occured but wasn't able to determin the exact reason
};

typedef NS_ENUM(NSInteger,SKSearchType)
{
    SKPOI = 0,
    SKStreet = 1,
    SKAll = 2
};

#pragma mark - POIs

typedef NS_ENUM(NSInteger,SKPOIType)
{
    SKCategorySearch = 0,
    SKLocalSearch = 1,
    SKRecents = 2,
    SKTripAdvisor = 3,
    SKFavorite = 4,
    SKFourSquare = 5
};

typedef NS_ENUM(NSInteger,SKPOICategory)
{
    SKPOICategoryAirport = 32,
    SKPOICategoryAerodrome = 348,
    SKPOICategoryFerryTerminal = 97,
    SKPOICategoryCamping = 370,
    SKPOICategoryHelipad = 350,
    SKPOICategoryThemePark = 208,
    SKPOICategoryAmusementPark = 208,
    SKPOICategoryWaterPark = 224,
    SKPOICategoryCampSite = 57,
    SKPOICategoryCampground = 57,
    SKPOICategoryStation = 194,
    SKPOICategoryTrainStation = 194,
    SKPOICategoryStadium = 325,
    SKPOICategoryHospital = 124,
    SKPOICategoryAttraction = 39,
    SKPOICategoryGarden = 109,
    SKPOICategoryGraveYard = 114,
    SKPOICategoryCemetery = 114,
    SKPOICategoryInformation = 128,
    SKPOICategoryMarina = 137,
    SKPOICategoryNatureReserve = 146,
    SKPOICategoryPark = 157,
    SKPOICategoryPrison = 175,
    SKPOICategoryShelter = 185,
    SKPOICategoryStadium2 = 192,
    SKPOICategoryTownhall = 213,
    SKPOICategoryCityHall = 213,
    SKPOICategoryLocalGovernmentOffice = 213,
    SKPOICategoryZoo = 232,
    SKPOICategoryAquarium = 232,
    SKPOICategoryEvCharging = 360,
    SKPOICategoryBusStation = 54,
    SKPOICategoryCarRental = 60,
    SKPOICategoryCarSharing = 62,
    SKPOICategoryCarRental2 = 62,
    SKPOICategoryCinema = 68,
    SKPOICategoryMovieTheater = 68,
    SKPOICategoryCollege = 75,
    SKPOICategoryConcertHall = 77,
    SKPOICategoryEmbassy = 94,
    SKPOICategoryFood = 103,
    SKPOICategoryFountain = 104,
    SKPOICategoryFuel = 105,
    SKPOICategoryHotel = 126,
    SKPOICategoryLibrary = 135,
    SKPOICategoryMall = 136,
    SKPOICategoryShoppingMall = 136,
    SKPOICategoryMuseum = 144,
    SKPOICategoryParking = 158,
    SKPOICategoryRvPark = 158,
    SKPOICategoryPharmacy = 165,
    SKPOICategoryPicnicSite = 168,
    SKPOICategoryPlaceOfWorship = 170,
    SKPOICategoryChurch = 170,
    SKPOICategoryHinduTemple = 170,
    SKPOICategoryMosqueplaceOfWorship = 170,
    SKPOICategorySynagogue = 170,
    SKPOICategoryPolice = 172,
    SKPOICategoryPostOffice = 174,
    SKPOICategorySportsCentre = 191,
    SKPOICategorySupermarket = 199,
    SKPOICategoryGroceryOrSupermarket = 199,
    SKPOICategoryTaxi = 203,
    SKPOICategoryTaxiStand = 203,
    SKPOICategoryTheatre = 207,
    SKPOICategoryTownSquare = 212,
    SKPOICategoryTrack = 215,
    SKPOICategoryTramStop = 216,
    SKPOICategoryUniversity = 218,
    SKPOICategoryViewpoint = 222,
    SKPOICategoryTerminal = 351,
    SKPOICategoryGolfCourse = 353,
    SKPOICategoryFishing = 354,
    SKPOICategoryIceRink = 355,
    SKPOICategoryDance = 356,
    SKPOICategorySwimmingPool = 357,
    SKPOICategoryBbq = 359,
    SKPOICategoryAdministrative = 368,
    SKPOICategoryVeterinary = 220,
    SKPOICategoryVeterinaryCare = 220,
    SKPOICategoryVideo = 221,
    SKPOICategoryMovieRental = 221,
    SKPOICategoryWine = 231,
    SKPOICategoryTobacco = 209,
    SKPOICategoryToys = 214,
    SKPOICategoryTravelAgency = 217,
    SKPOICategoryGate = 349,
    SKPOICategoryArchitect = 369,
    SKPOICategoryNursingHome = 361,
    SKPOICategoryCommunityCenter = 362,
    SKPOICategorySocialCenter = 363,
    SKPOICategoryStripclub = 364,
    SKPOICategoryBoutique = 372,
    SKPOICategoryCarParts = 373,
    SKPOICategoryCharity = 375,
    SKPOICategoryBicycleParking = 392,
    SKPOICategoryAccessoires = 30,
    SKPOICategoryAdult = 31,
    SKPOICategoryAlcohol = 33,
    SKPOICategoryLiquorStore = 33,
    SKPOICategoryAntiques = 34,
    SKPOICategoryArt = 35,
    SKPOICategoryArtsCentre = 36,
    SKPOICategoryArtwork = 37,
    SKPOICategoryBaby = 40,
    SKPOICategoryBakery = 41,
    SKPOICategoryBank = 42,
    SKPOICategoryBar = 43,
    SKPOICategoryBeauty = 44,
    SKPOICategoryBeds = 45,
    SKPOICategoryBeverages = 46,
    SKPOICategoryBicycle = 47,
    SKPOICategoryBicycleRental = 48,
    SKPOICategoryBiergarten = 49,
    SKPOICategoryBoatRental = 50,
    SKPOICategoryBooks = 51,
    SKPOICategoryBrothel = 52,
    SKPOICategoryBureauDeChange = 53,
    SKPOICategoryButcher = 55,
    SKPOICategoryCafe = 56,
    SKPOICategoryCandy = 58,
    SKPOICategoryCar = 59,
    SKPOICategoryCarDealer = 59,
    SKPOICategoryCarRepair = 61,
    SKPOICategoryCarWash = 63,
    SKPOICategoryCasino = 64,
    SKPOICategoryCeramics = 65,
    SKPOICategoryChemist = 66,
    SKPOICategoryChurch2 = 67,
    SKPOICategoryClock = 70,
    SKPOICategoryClocks = 71,
    SKPOICategoryClothes = 72,
    SKPOICategoryClothingStore = 72,
    SKPOICategoryClub = 73,
    SKPOICategoryCoffee = 74,
    SKPOICategoryComputer = 76,
    SKPOICategoryConfectionary = 78,
    SKPOICategoryConfectionery = 79,
    SKPOICategoryConvenience = 80,
    SKPOICategoryCopyshop = 81,
    SKPOICategoryCourthouse = 83,
    SKPOICategoryCoworkingSpace = 84,
    SKPOICategoryDeli = 85,
    SKPOICategoryDentist = 86,
    SKPOICategoryDepartmentStore = 87,
    SKPOICategoryDoctors = 88,
    SKPOICategoryDoctor = 88,
    SKPOICategoryDoityourself = 89,
    SKPOICategoryDrugstore = 91,
    SKPOICategoryDryCleaning = 92,
    SKPOICategoryElectronics = 93,
    SKPOICategoryElectronicsStore = 93,
    SKPOICategoryFashion = 95,
    SKPOICategoryFastFood = 96,
    SKPOICategoryFireStation = 98,
    SKPOICategoryFish = 99,
    SKPOICategoryFitnessCentre = 100,
    SKPOICategoryFlorist = 101,
    SKPOICategoryFlowers = 102,
    SKPOICategoryFurniture = 106,
    SKPOICategoryGallery = 107,
    SKPOICategoryArtGallery = 107,
    SKPOICategoryGames = 108,
    SKPOICategoryGardenCentre = 110,
    SKPOICategoryGeneral = 111,
    SKPOICategoryGift = 112,
    SKPOICategoryGifts = 113,
    SKPOICategoryGreengrocer = 115,
    SKPOICategoryGroceries = 116,
    SKPOICategoryGuestHouse = 117,
    SKPOICategoryHairdresser = 118,
    SKPOICategoryBeautySalon = 118,
    SKPOICategoryHairCare = 118,
    SKPOICategoryHealth = 118,
    SKPOICategoryPhysiotherapist = 118,
    SKPOICategoryHalt = 119,
    SKPOICategoryHardware = 121,
    SKPOICategoryFurnitureStore = 121,
    SKPOICategoryHardwareStore = 121,
    SKPOICategoryHomeGoodsStore = 121,
    SKPOICategoryHearingAids = 122,
    SKPOICategoryHifi = 123,
    SKPOICategoryHostel = 125,
    SKPOICategoryIceCream = 127,
    SKPOICategoryInsurance = 129,
    SKPOICategoryJewelry = 130,
    SKPOICategoryKindergarten = 131,
    SKPOICategoryKiosk = 132,
    SKPOICategoryKitchen = 133,
    SKPOICategoryLaundry = 134,
    SKPOICategoryMassage = 138,
    SKPOICategoryMiniatureGolf = 139,
    SKPOICategoryMobilePhone = 140,
    SKPOICategoryMotel = 141,
    SKPOICategoryLodging = 141,
    SKPOICategoryMotorcycle = 142,
    SKPOICategoryMotorcycleRepair = 143,
    SKPOICategoryMusic = 145,
    SKPOICategoryNewsagent = 147,
    SKPOICategoryNightclub = 148,
    SKPOICategoryNightClub = 148,
    SKPOICategoryOffice = 149,
    SKPOICategoryOfficeSupplies = 150,
    SKPOICategoryOptician = 151,
    SKPOICategoryOrganic = 152,
    SKPOICategoryOrthopedics = 153,
    SKPOICategoryOutdoor = 154,
    SKPOICategoryParfume = 156,
    SKPOICategoryParquet = 159,
    SKPOICategoryPerfumery = 160,
    SKPOICategoryPet = 161,
    SKPOICategoryPetShop = 162,
    SKPOICategoryPetStore = 162,
    SKPOICategoryPetSupply = 163,
    SKPOICategoryPetshop = 164,
    SKPOICategoryPhone = 166,
    SKPOICategoryPhoto = 167,
    SKPOICategoryPitch = 169,
    SKPOICategoryPlayground = 171,
    SKPOICategoryPostBox = 173,
    SKPOICategoryPub = 176,
    SKPOICategoryPublicBuilding = 177,
    SKPOICategoryRestaurant = 179,
    SKPOICategoryFood2 = 179,
    SKPOICategoryMealDelivery = 179,
    SKPOICategoryMealTakeaway = 179,
    SKPOICategorySauna = 180,
    SKPOICategorySpa = 180,
    SKPOICategorySchool = 181,
    SKPOICategoryScubaDiving = 182,
    SKPOICategorySecondHand = 183,
    SKPOICategoryShoemaker = 186,
    SKPOICategoryShoes = 187,
    SKPOICategoryShoeStore = 187,
    SKPOICategoryShop = 188,
    SKPOICategorySlipway = 189,
    SKPOICategorySports = 190,
    SKPOICategoryBowlingAlley = 190,
    SKPOICategoryGym = 190,
    SKPOICategoryStationery = 195,
    SKPOICategoryStudio = 196,
    SKPOICategorySubwayEntrance = 198,
    SKPOICategorySubwayStation = 198,
    SKPOICategoryTailoring = 200,
    SKPOICategoryTanning = 201,
    SKPOICategoryTattoo = 202,
    SKPOICategoryTea = 204,
    SKPOICategoryTelecommunication = 205,
    SKPOICategoryBuilding = 393,
    SKPOICategoryHouseno = 313,
    SKPOICategoryAtm = 38,
    SKPOICategoryDrinkingWater = 90,
    SKPOICategoryParcelBox = 155,
    SKPOICategoryRecycling = 178,
    SKPOICategoryService = 184,
    SKPOICategoryTelephone = 206,
    SKPOICategoryToilets = 210,
    SKPOICategoryVendingMachine = 219,
    SKPOICategoryBusStop = 395,
    SKPOICategoryVarietyStore = 396,
    SKPOICategoryTyres = 398,
    SKPOICategoryEstateAgent = 399,
    SKPOICategoryFuneralDirectors = 400,
    SKPOICategoryChalet = 401,
    SKPOICategoryCaravanSite = 402,
    SKPOICategoryAlpineHut = 403,
    SKPOICategorySocialFacility = 407,
    SKPOICategoryEmergencyPhone = 408,
    SKPOICategoryMarketplace = 409,
    SKPOICategoryParkingEntrance = 410,
    SKPOICategoryDrivingSchool = 411,
    SKPOICategoryHorseRiding = 412,
    SKPOICategoryPeak = 413,
    SKPOICategoryContinent = 415
};

typedef NS_ENUM(NSInteger,SKPOIMainCategory)
{
    SKPOIMainCategoryFood = 1,
    SKPOIMainCategoryHealth = 2,
    SKPOIMainCategoryLeisure = 3,
    SKPOIMainCategoryNightlife = 4,
    SKPOIMainCategoryPublic = 5,
    SKPOIMainCategoryServices = 6,
    SKPOIMainCategoryShopping = 7,
    SKPOIMainCategoryAccomodation = 8,
    SKPOIMainCategoryTransport = 9
};

#pragma mark - Tile access

typedef NS_ENUM(uint32_t,SKTileType)
{
    SKPOITile = 1,
    SKRoadTile = 2,
    SKShapeTile = 4,
    SKTextTile = 8,
    SKAllTiles = SKPOITile + SKRoadTile + SKShapeTile + SKTextTile
};

typedef NS_ENUM(NSInteger,SKOperationType)
{
    SKOpEnumerate = 0,
    SKOpEnumerateAndDownload = 1,
    SKOpExist = 2,
    SKOpNotExist = 3
};

#pragma mark - 3rd parties
typedef NS_ENUM(NSInteger,SKWikiArticleDownloadStatus)
{
    SKMissingArticle = 0,          //the article is not downloaded
    SKMissingArticleImages = 1,    //the article is downloaded, but some of the article images is not downloaded
    SKCompleteArticle = 2,         //the article and the article images are downloaded
};

typedef NS_ENUM(uint32_t,SKWikiTravelSearchMode)
{
    /**
     * This is the most flexible. If an article name match with parts of
     * the search term it will be mark as result.
     * e.g.: searchTerm="Ber", possible results: "ber", "Berlin", "berg",
     * "BERN", "bÈrn", "mitte_berlin", "Aeroport Berlin"
     */
    SKProximityMatch,
    
    /**
     * This is less flexible. When it is used the article name or word from name
     * has to fully match the search term but case insensitive
     * e.g.: searchTerm="Ber", results: "ber", "Bèr", "BER", "bËr", "M ber"
     * e.g.: searchTerm="Berlin_mite", results:"berlin_mitte", "Berlin mitte",
     * "Berlin/mitte"
     */
    SKCIWordMatch,
    
    /**
     * In this case the search is the most restrictive. The passed search
     * term must be exactlly with article name and it is case sensitive.
     * Use this only when you know the exact article that you must get
     * e.g. searchTerm="Ber", possible results: "Ber"
     * e.g. searchTerm="ber", possible results: "ber"
     * e.g. searchTerm="Bër", possible results: "Bër"
     * e.g. searchTerm="Berlin_mite", results:"Berlin_mitte"
     */
    SKFullyMatch
};

typedef NS_ENUM(NSInteger,SKWikiTravelArticleImageSize)
{
    SKWikiImages960x640 = 0
};

typedef NS_ENUM(NSInteger,SKWikiTravelChildren)
{
    SKDirectChildren = 0,
    SKTotalChildren
};

typedef NS_ENUM(NSInteger,SKArticleSearchType)
{
    /**
     * The search is made in all the articles installed and not installed
     */
    SKAllArticles = 0,
    
    /**
     * The search is made only between the articles that are installed
     * locally. An article is installed if his or one of his parents article
     * package was downloaded and saved locally
     * e.g.: Berlin package is installed, possible results: Berlin, Mitte
     * (because Berlin package is installed and Mitte is child) ...
     */
    SKInstalledArticles,
    
    /**
     * The search is made only between the articles that are instaleed and
     * only on those that have their own a package installed not the parents
     * e.g. Berlin package installed, possible results only Berlin.
     */
    SKTopInstalledArticles
    
};

typedef NS_ENUM(NSInteger,SKTripAdvisorPOIType)
{
    Hotel = 0,
    Restaurant = 1,
    ThingsToDo = 2
};

typedef NS_ENUM(NSInteger,SKFoursquareSortOrder)
{
    FoursquareSortOrderRelevance = 0,
    FoursquareSortOrderDistance = 1
};

typedef NS_ENUM(NSInteger,SKTripAdvisorSortOrder)
{
    Distance = 0,
    Popularity = 1
};
typedef NS_ENUM(NSInteger, SKAttributionPosition)
{
    SKAttributionPositionNone = 0,
    SKAttributionPositionTopLeft = 1,
    SKAttributionPositionTopMiddle = 2,
    SKAttributionPositionTopRight = 3,
    SKAttributionPositionBottomLeft = 4,
    SKAttributionPositionBottomMiddle = 5,
    SKAttributionPositionBottomRight = 6,
};

typedef NS_ENUM(NSInteger, SKDrawingOrderType)
{
    SKAnnotationsOverDrawableObjects = 0,
    SKDrawableObjectsOverAnnotations = 1,
};

#endif
