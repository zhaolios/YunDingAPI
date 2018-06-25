//
//  YDTypes.h
//  YunDingAPI
//
//  Created by ALIN on 2016/12/23.
//  Copyright © 2016年 DDing. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, YDError) {
    YD_ERROR_SUCCESS = 0,   // 操作成功
    YD_ERROR_PARAM_ERROR = 401, // 参数错误
    YD_ERROR_NOT_SUPPERT = 402, // 不支持该设备
    YD_ERROR_UNKNOWN = 403, // 未知错误
    YD_ERROR_OVER_TIME = 404 // 操作超时
};

// 门锁返回错误
typedef NS_ENUM(NSInteger, YDLockError) {
    YD_LOCK_COMMON_ERROR = 1, // 锁本地错误
    YD_LOCK_SYSTEMTIME_ERROR = 2, // 锁时间错误
    YD_LOCK_TIMESTAMP_ERROR  = 3, // 时间戳不在合法范围
    YD_LOCK_TOKEN_ERROR = 4, // 秘钥错误
    YD_LOCK_UUID_ERROR = 5, // uuid错误
    YD_LOCK_HAS_BEEN_RESET = 6, // 锁被重置
    YD_LOCK_SIGN_ERROR = 50, // 签名错误
    YD_LOCK_ERROR_SIGNAL_WEAK_ERROR = 101 ,// 信号太弱
    YD_LOCK_FINGERPRINT_ERROR
};

// 与蓝牙相关的错误码
typedef NS_ENUM(NSInteger, YDBLEError) {
    YD_BLE_ERROR_OK = 200,
    YD_BLE_UNKNOWN_ERROR = 201, // 蓝牙错误
    YD_BLE_ERROR_BLE_DEVICE_NOT_FOUND = 202, // 未发现蓝牙设备
    YD_BLE_ERROR_UUID_NOT_EXIST = 203, // 没找到uuid对应的设备
    YD_BLE_ERROR_PAIR = 204,    // 配对成功
    YD_BLE_ERROR_PAIR_ERR = 205, // 蓝牙配对失败
    YD_BLE_ERROR_LOCK_OPEN = 206, // 开锁成功
    YD_BLE_ERROR_IN_OPERATION = 207, // 正在操作中
    YD_BLE_ERROR_ALREADY_CONNECTED = 208, // 目标设备已经连上
    YD_BLE_ERROR_DEVICE_OCCUPIED = 209, // 目标设备被占用
    YD_BLE_ERROR_BLE_NOT_OPEN = 210, // 蓝牙未打开
    YD_BLE_ERROR_TOO_FAR = 211, // 距离设备太远
    YD_BLE_ERROR_CONNECT_EROR = 212, // 与设备连接错误
    YD_BLE_ERROR_DISCONNECT_INTENDED = 213, //主动断开
    YD_BLE_ERROR_DISCONNECT_UNEXPECTED = 214,    //被动断开
    YD_BLE_ERROR_SIGN = 215,
    YD_BLE_ERROR_UNKNOWN_MSG = 216,
};

typedef NS_ENUM(NSInteger, YDNetworkError) {
    YD_NETWORK_UNREACHABLE = 301, // 无网络连接
    YD_NETWORK_ERROR = 302, // 网络连接错误
    YD_NETWORK_SERVER_ERROR = 303, //服务器返回错误
    YD_NETWORK_ACCESS_TOKEN_EXPIRED = 304, // Access token 失效
    YD_NETWORK_OTHER_LOGIN = 305, // 他人登陆
    YD_NETWORK_ALREADY_BIND = 306, // 设备已经被绑定
    YD_NETWORK_USER_NOT_EXIST = 307, // 用户不存在
    YD_NETWORK_PASSWORD_NOT_EXIST = 308, // 密码不存在
    YD_NETWORK_SN_ERROR = 309// SN错误
    
};

// 门锁返回错误
typedef NS_ENUM(NSInteger, YDLockType) {
    YDLockTypeDefault , // F2
    YDLockTypeF2C, // F2C
    YDLockTypeF3,  // F3
    YDLockTypeF3S // F3S
};

typedef NS_ENUM(NSInteger, YDInteractionError) {
    YD_INTERACTION_CHECKPWD = 601,//
    YD_INTERACTION_SETPWD // F2C
};

typedef NS_ENUM(NSInteger, YDSmartKeyError) {
    YD_SMARTKEY_ERROR_CHALLENGEKEY = 701,   //请求挑战码错误
    YD_SMARTKEY_ERROR_DEVICEINFO,       //获取sKey设备信息错误
    YD_SMARTKEY_ERROR_CONFIG_SMARTKEY,  //向sKey下发blekey错误
    YD_SMARTKEY_ERROR_REGISTER,     //向服务器注册sKey错误
    YD_SMARTKEY_ERROR_BIND,         //向服务器申请绑定错误
    YD_SMARTKEY_ERROR_CONFIG_LOCK,      //配置门锁（写入blekey）时错误
};
typedef void(^onSuccess)(id data);
typedef void(^onError)(NSError *error);
typedef void(^onStageChange)(int stage, NSString *msg);
typedef void(^onStageAndProgress)(int stage, NSString *msg, NSProgress *progress);



