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

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <libimobiledevice-glue/utils.h>
#include "common/userpref.h"

#include <libimobiledevice/libimobiledevice.h>
#include <libimobiledevice/lockdown.h>

#define TOOL_NAME "jitterbugpair"

static void print_error_message(lockdownd_error_t err, const char *udid)
{
    switch (err) {
        case LOCKDOWN_E_PASSWORD_PROTECTED:
            fprintf(stderr, "ERROR: Could not validate with device %s because a passcode is set. Please enter the passcode on the device and retry.\n", udid);
            break;
        case LOCKDOWN_E_INVALID_CONF:
        case LOCKDOWN_E_INVALID_HOST_ID:
            fprintf(stderr, "ERROR: Device %s is not paired with this host\n", udid);
            break;
        case LOCKDOWN_E_PAIRING_DIALOG_RESPONSE_PENDING:
            fprintf(stderr, "ERROR: Please accept the trust dialog on the screen of device %s, then attempt to pair again.\n", udid);
            break;
        case LOCKDOWN_E_USER_DENIED_PAIRING:
            fprintf(stderr, "ERROR: Device %s said that the user denied the trust dialog.\n", udid);
            break;
        default:
            fprintf(stderr, "ERROR: Device %s returned unhandled error code %d\n", udid, err);
            break;
    }
}

int print_udids(void) {
    unsigned int i;
    char **udids = NULL;
    unsigned int count = 0;
    userpref_get_paired_udids(&udids, &count);
    for (i = 0; i < count; i++) {
        printf("%s\n", udids[i]);
        free(udids[i]);
    }
    free(udids);
    return EXIT_SUCCESS;
}