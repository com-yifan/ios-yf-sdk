//
//  YFAdInteractionType.h
//  YFAdsSDK
//
//  Created by aiken on 2023/5/9.
//

typedef NS_ENUM(NSInteger, YFAdInteractionType) {
    YFAdInteractionType_Unknown,        //unknown type
    YFAdInteractionType_App,            //open downlaod page in app
    YFAdInteractionType_Web,            //open webpage in app
    YFAdInteractionType_DeepLink,       //open deeplink
    YFAdInteractionType_AppStore,       //open appstore
};

typedef NS_ENUM(NSInteger, YFAdMaterialType) {
    YFAdMaterialTypeUnkown      =       0,      // unknown
    YFAdMaterialTypeVideo       =       1,      // video
    YFAdMaterialTypeSingle      =       2,      // single image
    YFAdMaterialTypeAtlas       =       5,      // multiple image
};



