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

#include "AddressUtils.h"
#include <arpa/inet.h>

BOOL addressIsLoopback(NSData * _Nonnull data) {
    struct sockaddr_storage address = {0};
    struct sockaddr_in *ipv4_addr = (struct sockaddr_in *)&address;
    struct sockaddr_in6 *ipv6_addr = (struct sockaddr_in6 *)&address;

    [data getBytes:&address length:(data.length > sizeof(address) ? sizeof(address) : data.length)];
    if (address.ss_family == PF_INET) {
        return ipv4_addr->sin_addr.s_addr == htonl(INADDR_LOOPBACK);
    } else if (address.ss_family == PF_INET6) {
        return IN6_IS_ADDR_LOOPBACK(&ipv6_addr->sin6_addr);
    } else {
        return NO;
    }
}

NSData * _Nonnull addressIPv4StringToData(NSString * _Nonnull ascii) {
    struct sockaddr_in addr = {0};
    addr.sin_len = sizeof(addr);
    addr.sin_family = AF_INET;
    inet_aton(ascii.UTF8String, &addr.sin_addr);
    return [NSData dataWithBytes:&addr length:sizeof(addr)];
}


