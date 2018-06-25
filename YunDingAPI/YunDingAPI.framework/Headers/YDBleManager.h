//
//  YDBleManager.h
//  YunDingAPI
//
//  Created by ALIN on 2016/11/15.
//  Copyright © 2016年 DDing. All rights reserved.
//

#import "YDPermission.h"
#import "YDPasswordInfo.h"
#import "YDFingerprintInfo.h"
#import "YDTypes.h"
#import "YDBLEDataManager.h"


@interface YDBleManager : NSObject

+ (instancetype)sharedManager;

/**
 登录成功后调用
 device identifier 由服务器下发，保存在本地
 登录后，先判断本地是否有 device identifier
 如果没有，从服务器拉去后保存到本地，再传回服务器
 如果有，直接传给服务器
 服务器根据 device identifier 判断是否是换手机登录
 */
- (void)checkAndPostDeviceIdentifier;

- (void)setLock:(NSString *)deviceID OTAStatusTo:(int)status;

- (int)getOTAStatusOfLock:(NSString *)deviceID;

/**
 设置当前用户token
 
 @param token 当前登录用户在云盯公司注册的token
 @param success 返回执行成功状态
 @param failure 返回错误码和错误信息
 */
- (void)setAccessToken:(NSString*)token
               success:(onSuccess)success
               failure:(onError)failure;

/**
 设置当前用户token
 
 @param token 当前登录用户在云盯公司注册的token
 @param name 当前登录用户的手机号
 
 */
- (void)setAccessToken:(NSString*)token
              username:(NSString*)name;
/**
 删除当前用户token
 
 @param token 当前登录用户在云盯公司注册的token
 @param success 返回执行成功状态
 @param failure 返回错误码和错误信息
 */
- (void)delAccessToken:(NSString *)token
               success:(onSuccess)success
               failure:(onError)failure;

/**
 退出当前用户
 
 @param username 当前登录用户在云盯公司注册的token

 */

- (void)logoutUser:(NSString*)username;

/**
 绑定一把新锁到当前用户账户
 
 @param progress 返回各个阶段的提示信息
 @param success 返回执行成功状态(boolean)
 @param failure 返回错误码和错误信息
 */
- (void)bindLock2UserWithCenterUUID:(NSString*)uuid
                             lockSN:(NSString*)sn
                               type:(YDLockType)type
                           Progress:(onStageChange)progress
                          success:(onSuccess)success
                          failure:(onError)failure;

/**
 配置需要绑定的sKey
 
 @param lockUUID 门锁唯一识别码
 @param progress 返回各个阶段的提示信息
 @param success 返回执行成功状态, 如果成功则返回smartkey的UUID
 @param failure 返回错误码和错误信息
 */
- (void)configSmartKey2Lock:(NSString*)lockUUID
                   progress:(onStageChange)progress
                  success:(onSuccess)success
                  failure:(onError)failure;


/**
 调用服务器接口已解绑sKey
 
 @param smartKeyUUID sKey唯一识别码
 @param success 返回执行成功状态
 @param failure 返回错误码和错误信息
 */
- (void)unbindOnServer4SmartKey:(NSString*)smartKeyUUID
                  success:(onSuccess)success
                  failure:(onError)failure;

/**
 跟门锁解绑sKey（删除门锁中的BLE KEY）
 
 @param bleKeyId sKeyID,1001...
 @param success 返回执行成功状态
 @param failure 返回错误码和错误信息
 */
- (void)delBleKey:(int)bleKeyId
           onLock:(NSString *)lockUUID
          success:(onSuccess)success
          failure:(onError)failure;

/**
 将配置好的sKey绑定到门锁
 
 @param lockUUID 门锁唯一识别码
 @param smartKeyUUID sKey唯一识别码
 @param userId 用户唯一识别码
 @param progress 返回各个阶段的提示信息
@param success 返回执行成功状态
 @param failure 返回错误码和错误信息
 */
- (void)bindSmartKey2Lock:(NSString*)lockUUID
                 smartKey:(NSString *)smartKeyUUID
                   userId:(NSString*)userId
                 progress:(onStageChange)progress
                  success:(onSuccess)success
                  failure:(onError)failure;

- (void)setAdminPWDDuringBind:(NSString *)adminPwd;
/**
 连接设备
 
 @param uuid 门锁的uuid
 @param success 返回执行成功状态
 @param failure 返回错误码和错误信息
 */
- (void)connect:(NSString *)uuid
        success:(onSuccess)success
        failure:(onError)failure;


/**
 配置一把新锁到当前用户账户，每把锁只需配置一次，第一次配置需要花一些时间，已配置会直接执行success回调
 
 @param uuid 门锁的uuid
 @param progress 返回各个阶段的提示信息(0未配置，1已配置）
 @param success 返回执行成功状态
 @param failure 返回错误码和错误信息
 
 */
- (void)setLock2UserWithUUID:(NSString *)uuid
                    Progress:(onStageChange)progress
                     success:(onSuccess)success
                     failure:(onError)failure;


/**
 生成新蓝牙钥匙，并且授权给其他用户，其他用户将获得开门蓝牙钥匙

 @param phoneNum 用户电话号码
 @param uuid 唯一识别码
 @param keyName 蓝牙钥匙名称
 @param permission 蓝牙钥匙权限属性
 @param success 返回执行成功状态
 @param failure 返回错误码和错误信息
 */
- (void)sendBleKey2User:(NSString *)phoneNum
                   uuid:(NSString *)uuid
                   name:(NSString *)keyName
             permission:(YDPermission *)permission
                success:(onSuccess)success
                failure:(onError)failure;


/**
 将蓝牙钥匙写入门锁

 @param uuid 唯一识别码
 @param success 返回执行成功状态
 @param failure 返回错误码和错误信息
 */
- (void)writeBleKey2Lock:(NSString*)uuid
                 success:(onSuccess)success
                 failure:(onError)failure;

/**
 用蓝牙钥匙开锁

 @param uuid 唯一识别码
 @param gatewayLess 是否是无网关类型，yes是
 @param appVersion 蓝牙版本号
 @param lockType 门锁类型
 @param success 返回执行成功状态
 @param failure 返回错误码和错误信息
 */
- (void)openLock:(NSString *)uuid
            type:(BOOL)gatewayLess
      appVersion:(NSString *)appVersion
        lockType:(YDLockType)lockType
         success:(onSuccess)success
         failure:(onError)failure;


/**
 删除服务端的蓝牙钥匙

 @param uuid 唯一识别码
 @param userName 登陆账号名称（电话号码）
 @param success 返回执行成功状态
 @param failure 返回错误码和错误信息
 */
- (void)delBleKeyFromServerWithUuid:(NSString*)uuid
                               name:(NSString*)userName
                            success:(onSuccess)success
                            failure:(onError)failure;

/**
 从服务器取当前设备的蓝牙钥匙列表

 @param uuid 唯一识别码
 @param success 返回蓝牙钥匙列表
 @param failure 返回错误码和错误信息
 */
- (void)getBleKeyListFromServerOfLock:(NSString*)uuid
                              success:(onSuccess)success
                              failure:(onError)failure;

/**
 重置当前设备蓝牙钥匙

 @param uuid 唯一识别码
 @param success 返回执行成功状态
 @param failure 返回错误码和错误信息
 */
- (void)resetBleKey:(NSString*)uuid
            success:(onSuccess)success
            failure:(onError)failure;

/**
 把开锁密码写入智能锁

 @param uuid 唯一识别码
 @param info 用户设置的开锁密码
 @param success 返回执行成功状态
 @param failure 返回错误码和错误信息
 */
- (void)writePassword2Lock:(NSString*)uuid
                      info:(YDPasswordInfo*)info
                appVersion:(NSString *)appVersion
                  lockType:(YDLockType)lockType
                   success:(onSuccess)success
                   failure:(onError)failure;


/**
 删除智能设备里的开锁密码
 
 @param uuid 唯一识别码
 @param passwordId 用户设置的开锁密码ID
 @param isForce 是否强制删除
 @param success 返回执行成功状态
 @param failure 返回错误码和错误信息
 */
- (void)delPasswordOfLock:(NSString*)uuid
                    pwdId:(int)passwordId
                    force:(BOOL)isForce
               appVersion:(NSString *)appVersion
                 lockType:(YDLockType)lockType
                  success:(onSuccess)success
                  failure:(onError)failure;


/**
 上传门锁中的密码到服务器

 @param uuid 唯一识别码
 @param success 返回执行成功状态
 @param failure 返回错误码和错误信息
 */
- (void)updatePasswordsOfLock:(NSString*)uuid
                      success:(onSuccess)success
                      failure:(onError)failure;

/**
 从服务器上取得智能锁的密码列表

 @param uuid 唯一识别码
 @param success 返回密码列表
 @param failure 返回错误码和错误信息
 */
- (void)getPasswordsFromServer:(NSString*)uuid
                       success:(onSuccess)success
                       failure:(onError)failure;


/**
 发送门锁激活码给用户
 
 @param phoneNum 手机号
 @param pwdName 密码名称
 @param permission 权限信息
 @param success 返回密码列表
 @param failure 返回错误码和错误信息
 */
- (void)sendPassword2User:(NSString *)phoneNum
                     uuid:(NSString *)uuid
                     name:(NSString *)pwdName
                  permission:(YDPermission *)permission
                  success:(onSuccess)success
                  failure:(onError)failure;


/**
 取得智能锁的开门历史记录

 @param uuid 唯一识别码
 @param offset 偏移量
 @param count 数量
 @param endTime 结束时间
 @param success 返回开门记录列表
 @param failure 返回错误码和错误信息
 */
- (void)getOpenDoorHistoryFromServer:(NSString*)uuid
                              offset:(int)offset
                               count:(int)count
                             endTime:(NSTimeInterval)endTime
                             success:(onSuccess)success
                             failure:(onError)failure;

/**
 上传智能锁的开门历史记录

 @param uuid 唯一识别码
 @param success 返回执行成功状态
 @param failure 返回错误码和错误信息
 */
- (void)uploadOpenDoorHistory2Server:(NSString*)uuid
                          appVersion:(NSString *)appVersion
                            lockType:(YDLockType)lockType
                            progress:(onStageChange)progress
                             success:(onSuccess)success
                             failure:(onError)failure;

/**
 同步电量

 @param uuid 门锁的uuid
 @param success 返回执行成功状态
 @param failure 返回错误码和错误信息
 */
- (void)updateBatteryOfLock:(NSString*)uuid
                    success:(onSuccess)success
                    failure:(onError)failure;


/**
 移除当前的连接管理器
 
 @param connection 是否保持连接
 */
- (void)stopOperationWithConnection:(BOOL)connection;

/**
 发送指纹给用户
 
 @param userid 成员
 @param uuid 门锁uuid
 @param progress 指纹录入进度
 @param success 返回密码列表
 @param failure 返回错误码和错误信息
 */
- (void)writeFingerprintToLock:(NSString *)uuid
                          info:(YDFingerprintInfo*)info
                    appVersion:(NSString *)appVersion
                      lockType:(YDLockType)lockType
                      Progress:(onStageChange)progress
                       success:(onSuccess)success
                       failure:(onError)failure;

- (void)setFpnameDuringEnrollment:(NSString *)name isDanger:(BOOL) isDanger;
- (void)setFpnameDuringEnrollment:(NSString *)name isDanger:(BOOL) isDanger phoneNumer:(NSString *)fpIDneNumber;

/**
 删除指纹
 
 @param uuid 门锁uuid
 @param fpID 指纹id
 @param progress 指纹录入进度
 @param success 返回密码列表
 @param failure 返回错误码和错误信息
 */
- (void)delFingerprintToLock:(NSString *)uuid
                        fpID:(int)fpID
                  appVersion:(NSString *)appVersion
                    lockType:(YDLockType)lockType
                    Progress:(onStageChange)progress
                     success:(onSuccess)success
                     failure:(onError)failure;

/**
 删除蓝牙数据
 @param uuid 门锁uuid
 
 */

- (void)removeBleInfoToLock:(NSString *)uuid;
- (int)returnSceneForDeviceID:(NSString *)deviceID;
- (void)exitBLE;

- (void)exitBLESuccess:(onSuccess)success failure:(onError)failure;

- (void)retriveAutoUnlockPeripheralWithUUIDs:(NSArray *)uuids;

/**
 设置门锁语音音量大小
 @param volume 音量值，0~1
 @param uuid 门锁uuid
 @param success 返回设置成功
 @param failure 返回错误码和错误信息
 */
- (void)setAudioVolumeOfLock:(NSString*)uuid
                     toValue:(int)volume
                  appVersion:(NSString *)appVersion
                    lockType:(YDLockType)lockType
                     success:(onSuccess)success
                     failure:(onError)failure;

/**
 获取门锁音量状态
 
 @param uuid 门锁uuid
 @param success 返回设置成功
 @param failure 返回错误码和错误信息
 */
- (void)getLockVolumeOfLock:(NSString*)uuid
                    success:(onSuccess)success
                    failure:(onError)failure;
/**
 设置电子反锁
 
 @param uuid 门锁uuid
 @param isDisable YES:开启反锁 NO:关闭反锁(正常状态)
 @param success 返回设置成功
 @param failure 返回错误码和错误信息
 */
- (void)setEleReverseLock:(NSString*)uuid
                toDisable:(BOOL)isDisable
               appVersion:(NSString *)appVersion
                lockType:(YDLockType)lockType
                  success:(onSuccess)success
                  failure:(onError)failure;
/**
 获取电子反锁状态
 
 @param uuid 门锁uuid
 @param success 返回设置成功
 @param failure 返回错误码和错误信息
 */
- (void)getEleReverseStateOfLock:(NSString*)uuid
                         success:(onSuccess)success
                         failure:(onError)failure;

- (void)startOTA4SmartKeyMac:(NSString *)mac
                firmwarePath:(NSURL *)path
                  onProgress:(onStageAndProgress)progress
                     succeed:(onSuccess)success
                      failed:(onError)failed;
- (void)getLockVersions:(NSString*)uuid
                success:(onSuccess)success
                failure:(onError)failure;

- (void)otaOperationWith:(NSString*)uuid
                 fileURL:(NSString *)url
                  digest:(NSString *)digest
                    sign:(NSString *)sign
                 version:(NSString *)version
                progress:(onStageAndProgress)progress
                 success:(onSuccess)success
                 failure:(onError)failure;

- (void)mainOTAWith:(NSString*)uuid
            fileURL:(NSString *)url
             digest:(NSString *)digest
               sign:(NSString *)sign
            version:(NSString *)version
           progress:(onStageAndProgress)progress
            success:(onSuccess)success
            failure:(onError)failure;

@end
