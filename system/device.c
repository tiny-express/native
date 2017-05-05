/**
 * Copyright (c) 2016 Food Tiny Project. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * Redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer.
 * Redistributions in binary form must reproduce the above
 * copyright notice, this list of conditions and the following disclaimer
 * in the documentation and/or other materials provided with the
 * distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "../system.h"
#ifdef __linux__
#include <sys/sysinfo.h>
#endif
#ifdef __APPLE__
#include <sys/sysctl.h>
#endif
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "../string.h"

#define BUF_MAX 1024

int read_cpu_fields(FILE *fp, unsigned long long int *fields)
{
    int return_value;
    char buffer[BUF_MAX];

    if (!fgets (buffer, BUF_MAX, fp)) {
        return 0;
    }
    return_value = sscanf (buffer, "cpu %Lu %Lu %Lu %Lu %Lu %Lu %Lu %Lu %Lu %Lu",
                     &fields[0],
                     &fields[1],
                     &fields[2],
                     &fields[3],
                     &fields[4],
                     &fields[5],
                     &fields[6],
                     &fields[7],
                     &fields[8],
                     &fields[9]);
    if (return_value < 4) {
        return 0;
    }
    return 1;
}

float get_cpu_usage() {
	#ifdef __APPLE__
		return 1.0L;
	#endif
	
    FILE *fp;
    unsigned long long int fields[10], total_tick, total_tick_old, idle, idle_old, delta_total_tick, delta_idle;
    int i;
    float percent_usage;

    fp = fopen ("/proc/stat", "r");
    if (fp == NULL) {
        return 0;
    }

    if (!read_cpu_fields(fp, fields)) {
        return 0;
    }

    for (i=0, total_tick = 0; i<10; i++) {
        total_tick += fields[i];
    }
    idle = fields[3];

    sleep (1);

    total_tick_old = total_tick;
    idle_old = idle;

    fseek (fp, 0, SEEK_SET);
    fflush (fp);
    if (!read_cpu_fields (fp, fields)) {
        return 0;
    }

    for (i=0, total_tick = 0; i<10; i++) {
        total_tick += fields[i];
    }
    idle = fields[3];

    delta_total_tick = total_tick - total_tick_old;
    delta_idle = idle - idle_old;

    percent_usage = ((delta_total_tick - delta_idle) / (double) delta_total_tick) * 100;

    fclose (fp);
    return percent_usage;
}

float get_ram_usage() {
	#ifdef __APPLE__
		return 1.0L;
	#endif
	#ifdef __linux__
	    struct sysinfo memory_info;
	    sysinfo(&memory_info);
	    return (1 - ((float) memory_info.freeram / memory_info.totalram)) * 100;
	#endif
}

float get_disk_available() {
	#ifdef __APPLE__
		return 1.0L;
	#endif
    return 1.0L;
    /*
    FILE *in;
    char buffer[BUF_MAX];
    
    if (!(in = popen("df -h | grep /dev/", "r"))) {
        return 0;
    }

    char *ptr;
    long value;
    int percent_usage = 0;
    while(fgets(buffer, BUF_MAX, in) != NULL) {
        char **tmp = string_split(buffer, " ");
        value = strtol(tmp[1], &ptr, 10);
        percent_usage += value;
        free(tmp);
    }

    pclose(in);
    return (100 - percent_usage);
    */
}

