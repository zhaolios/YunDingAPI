//
//  YDPasswordInfo.h
//  FrameworkTest1
//
//  Created by ALIN on 2016/11/22.
//  Copyright © 2016年 DDing. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface YDPasswordInfo : NSObject

/// 是否默认密码
@property (nonatomic, assign) BOOL isDefault;

/// 权限状态 1永久 2临时
@property (nonatomic, assign) int permissionStatus;

/// 开始时间
@property (nonatomic, assign) NSTimeInterval startTime;

/// 结束时间
@property (nonatomic, assign) NSTimeInterval endTime;

/// 密码名称
@property (nonatomic, copy) NSString *pwdName;

/// 密码值
@property (nonatomic, copy) NSString *pwdValue;

///指定的成员
@property (nonatomic, copy) NSString *userid;

/// 要发送的手机号
@property (nonatomic, copy) NSString *phone;


@end
