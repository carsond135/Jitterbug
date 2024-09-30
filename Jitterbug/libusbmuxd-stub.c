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

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif
#include <stdint.h>
#include <stdlib.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <arpa/inet.h>

#define USBMUXD_API __attribute__((visibility("default")))

// usbmuxd public interface
#include "usbmuxd.h"
// usbmuxd protocol
#include "usbmuxd-proto.h"
// custom functions
#include "common/userpref.h"
#include "CacheStorage.h"
#include "Jitterbug.h"

#pragma mark - Device listing


