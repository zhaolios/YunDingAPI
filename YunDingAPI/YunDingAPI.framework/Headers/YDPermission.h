//
//  YDPermission.h
//  FrameworkTest1
//
//  Created by ALIN on 2016/11/21.
//  Copyright © 2016年 DDing. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface YDPermission : NSObject

/// 权限类型，1永久，2临时
@property (nonatomic, assign) int type;

/// 开始时间戳
@property (nonatomic, assign) NSTimeInterval startTime;

/// 结束时间戳
@property (nonatomic, assign) NSTimeInterval endTime;

@end
