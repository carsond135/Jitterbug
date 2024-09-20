//
// Copyright © 2021 osy. All rights reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface JBApp : NSObject

@property (nonatomic) NSString *bundleName;
@property (nonatomic) NSString *bundleIdentifier;
@property (nonatomic) NSString *bundleExecutable;
@property (nonatomic) NSString *container;
@property (nonatomic) NSString *path;
@property (nonatomic) NSData *icon;
@property (nonatomic, readonly) NSString *executablePath;

@end

NS_ASSUME_NONNULL_END
