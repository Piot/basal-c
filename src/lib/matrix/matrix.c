/*---------------------------------------------------------------------------------------------
 *  Copyright (c) Peter Bjorklund. All rights reserved.
 *  Licensed under the MIT License. See LICENSE in the project root for license information.
 *--------------------------------------------------------------------------------------------*/
#include <basal/matrix.h>
#include <clog/clog.h>
#include <tiny-libc/tiny_libc.h>

void blMatrixDebug(const BlMatrix* self, const char* debug_string)
{
#if defined CONFIGURATION_DEBUG
    CLOG_INFO("matrix:'%s'", debug_string)
#else
    (void) debug_string;
#endif
    const float* m = blMatrixRaw(self);
    for (int i = 0; i < 4; i++) {
        char line[128];
        line[0] = 0;
        for (int j = 0; j < 4; j++) {
            tc_snprintf(line, 128, "%s %f ", line, m[j * 4 + i]);
        }
        CLOG_INFO("%s", line)
    }

    CLOG_INFO("x:%f", m[12])
    CLOG_INFO("y:%f", m[13])
    CLOG_INFO("z:%f", m[14])
}
