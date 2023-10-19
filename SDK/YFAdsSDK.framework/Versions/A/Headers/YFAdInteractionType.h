//
//  YFAdInteractionType.h
//  YFAdsSDK
//
//  Created by aiken on 2023/5/9.
//

typedef NS_ENUM(NSInteger, YFAdInteractionType) {
    FCAdInteractionType_Unknown,        //unknown type
    FCAdInteractionType_App,            //open downlaod page in app
    FCAdInteractionType_Web,            //open webpage in app
    FCAdInteractionType_DeepLink,       //open deeplink
    FCAdInteractionType_AppStore,       //open appstore
};

typedef NS_ENUM(NSInteger, FCAdMaterialType) {
    FCAdMaterialTypeUnkown      =       0,      // unknown
    FCAdMaterialTypeVideo       =       1,      // video
    FCAdMaterialTypeSingle      =       2,      // single image
    FCAdMaterialTypeAtlas       =       5,      // multiple image
};

