/*
 * copy.h
 *
 *  Created on: Oct 29, 2016
 *      Author: root
 */

#ifndef COPY_H_
#define COPY_H_

void copy_eth(struct eth *eth, unsigned char *buffer);
void copy_ipv4(struct ipv4 *ipv4, unsigned char *buffer);
void copy_udp(struct udp *udp, unsigned char *buffer);
void copy_pakiet(struct data *data, unsigned char *buffer, int length);
void copy_pak(struct eth_ipv4_udp *pakiet, struct eth *eth, struct ipv4 *ipv4,
		struct udp *udp, struct data *data);
void copy_eth2(struct eth *eth, unsigned char *buffer);
void copy_ipv42(struct ipv4 *ipv4, unsigned char *buffer);
void copy_udp2(struct udp *udp, unsigned char *buffer);
void copy_pakiet2(struct data *data, unsigned char *buffer);
void copy_pak2(struct eth_ipv4_udp *pakiet, struct eth *eth, struct ipv4 *ipv4,
		struct udp *udp, struct data *data);
#endif /* COPY_H_ */
