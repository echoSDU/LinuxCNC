/*    This is a component of LinuxCNC
 *    Copyright 2013,2014 Michael Geszkiewicz <micges@wp.pl>,
 *    Jeff Epler <jepler@unpythonic.net>
 *
 *    This program is free software; you can redistribute it and/or modify
 *    it under the terms of the GNU General Public License as published by
 *    the Free Software Foundation; either version 2 of the License, or
 *    (at your option) any later version.
 *
 *    This program is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    GNU General Public License for more details.
 *
 *    You should have received a copy of the GNU General Public License
 *    along with this program; if not, write to the Free Software
 *    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#ifndef __INCLUDE_HM2_ETH_H
#define __INCLUDE_HM2_ETH_H

#include "lbp16.h"

#define MAX_ETH_BOARDS 4

#define HM2_ETH_VERSION "0.2"
#define HM2_LLIO_NAME "hm2_eth"

#define MAX_ETH_READS 64

typedef struct {
    void *buffer;
    int size;
    int from;
} hm2_read_queue_entry_t;

typedef struct {
    hm2_lowlevel_io_t llio;

    int sockfd;
    struct sockaddr_in local_addr;
    struct sockaddr_in server_addr;

    hm2_read_queue_entry_t queue_reads[MAX_ETH_READS];
    lbp16_cmd_addr queue_packets[MAX_ETH_READS];
    int queue_reads_count;
    int queue_buff_size;

    rtapi_u8 write_packet[1400];
    void *write_packet_ptr;
    int write_packet_size;
    int read_cnt;
    int write_cnt;

    struct arpreq req;
} hm2_eth_t;

#endif
