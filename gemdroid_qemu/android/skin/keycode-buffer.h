/* Copyright (C) 2010 The Android Open Source Project
**
** This software is licensed under the terms of the GNU General Public
** License version 2, as published by the Free Software Foundation, and
** may be copied, distributed, and modified under those terms.
**
** This program is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
** GNU General Public License for more details.
*/
#ifndef QEMU_ANDROID_KEYCODE_BUFFER_H
#define QEMU_ANDROID_KEYCODE_BUFFER_H

/* Contains declarations for routines that manage keycode sequence that needs
 * to be transferred to the emulator core for further processing.
 */

/* Maximum number of keycodes kept in the array. */
#define  MAX_KEYCODES   256*2

// Type of a function used to flush buffered codes
typedef void (*SkinKeyCodeFlushFunc)(int* codes, int count);

/* Describes array of keycodes collected for transferring to the core. */
typedef struct SkinKeycodeBuffer {
    SkinKeyCodeFlushFunc keycode_flush;
    int keycode_count;
    int keycodes[MAX_KEYCODES];
} SkinKeycodeBuffer;

void skin_keycodes_buffer_init(SkinKeycodeBuffer* buffer,
                               SkinKeyCodeFlushFunc flush_func);

/* Adds a key event to the array of keycodes. */
void skin_keycodes_buffer_add(SkinKeycodeBuffer* buffer,
                              unsigned code,
                              unsigned down);

/* Flushes (transfers) collected keycodes to the core. */
void skin_keycodes_buffer_flush(SkinKeycodeBuffer* buffer);

#endif /* QEMU_ANDROID_KEYCODE_BUFFER_H */
