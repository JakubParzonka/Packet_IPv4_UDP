#include <stdio.h>
#include <stdlib.h>
#include "struktury.h"

void copy_eth(struct eth *eth, unsigned char *bufor) {
	short int a;
	memcpy(eth->destination_mac_address, bufor, 6);
	memcpy(eth->source_mac_address, bufor + 6, 6);
	memcpy(&a, bufor + 12, 2);
	eth->ethertype = ((a >> 8) & 0xff) | ((a << 8) & 0xff00);
}

void copy_ipv4(struct ipv4 *ipv4, unsigned char *bufor) {
	unsigned char a;
	int b;
	unsigned short c;
	unsigned short d;
	unsigned short e;
	memcpy(&a, bufor + 14, 1);
	ipv4->version = a & 4;
	ipv4->header_lenght = a;
	memcpy(&ipv4->tos, bufor + 15, 1);
	memcpy(&c, bufor + 16, 2);
	ipv4->total_lenght = ((c >> 8) & 0xff) | ((c << 8) & 0xff00);
	memcpy(&d, bufor + 18, 2);
	ipv4->identification = ((d >> 8) & 0xff) | ((d << 8) & 0xff00);
	memcpy(&b, bufor + 20, 2);
	b = ((b >> 8) & 0xff) | ((b << 8) & 0xff00);
	ipv4->flag = b >> 12;
	ipv4->fragoffs = b;
	memcpy(&ipv4->time_to_live, bufor + 22, 1);
	memcpy(&ipv4->protocol, bufor + 23, 1);
	memcpy(&e, bufor + 24, 2);
	ipv4->headerchecksum = ((e >> 8) & 0xff) | ((e << 8) & 0xff00);
	memcpy(ipv4->source_address, bufor + 26, 4);
	memcpy(ipv4->destination_address, bufor + 30, 4);
}

void copy_udp(struct udp *udp, unsigned char *bufor) {
	short int a;
	short int b;
	short int c;
	short int d;

	memcpy(&a, bufor + 34, 2);
	udp->source_port = ((a >> 8) & 0xff) | ((a << 8) & 0xff00);
	memcpy(&b, bufor + 36, 2);
	udp->destination_port = ((b >> 8) & 0xff) | ((b << 8) & 0xff00);
	memcpy(&c, bufor + 38, 2);
	udp->length = ((c >> 8) & 0xff) | ((c << 8) & 0xff00);
	memcpy(&d, bufor + 40, 2);
	udp->checksum = ((d >> 8) & 0xff) | ((d << 8) & 0xff00);
}

void copy_pakiet(struct data *data, unsigned char *bufor, int length) {
	int l = length - 42;
	memcpy(data->bufor_danych, bufor + 42, l);

}

void copy_pak(struct eth_ipv4_udp *pakiet, struct eth *eth, struct ipv4 *ipv4,
		struct udp *udp, struct data *data) {

	pakiet->eth = *eth;
	pakiet->ipv4 = *ipv4;
	pakiet->udp = *udp;
	pakiet->data = *data;

}

void copy_eth2(struct eth *eth, unsigned char *buffer) {
	short int a;
	memcpy(buffer, eth->destination_mac_address, 6);
	memcpy(buffer + 6, eth->source_mac_address, 6);
	memcpy(&a, &eth->ethertype, 2);
	*(buffer + 12) = ((a >> 8) & 0xff) | ((a << 8) & 0xff00);
}

void copy_ipv42(struct ipv4 *ipv4, unsigned char *buffer) {
	unsigned char a;
	unsigned char a1;
	unsigned short b, b1;
	unsigned short c;
	unsigned short d;
	unsigned short e;
	a = ipv4->version;
	a1 = a << 4 | ipv4->header_lenght;
	memcpy(buffer + 14, &a1, 1);
	memcpy(buffer + 15, &ipv4->tos, 1);
	c = ipv4->total_lenght;
	c = ((c >> 8) & 0xff) | ((c << 8) & 0xff00);
	memcpy(buffer + 16, &c, 2);
	d = ipv4->identification;
	d = ((d >> 8) & 0xff) | ((d << 8) & 0xff00);
	memcpy(buffer + 18, &d, 2);
	b = ipv4->flag;
	b1 = b << 12 | ipv4->fragoffs;
	b1 = ((b1 >> 8) & 0xff) | ((b1 << 8) & 0xff00);
	memcpy(buffer + 20, &b1, 2);
	memcpy(buffer + 22, &ipv4->time_to_live, 1);
	memcpy(buffer + 23, &ipv4->protocol, 1);
	e = ipv4->headerchecksum;
	e = ((e >> 8) & 0xff) | ((e << 8) & 0xff00);
	memcpy(buffer + 24, &e, 2);
	memcpy(buffer + 26, ipv4->source_address, 4);
	memcpy(buffer + 30, ipv4->destination_address, 4);

}

void copy_udp2(struct udp *udp, unsigned char *buffer) {
	short int a;
	short int b;
	short int c;
	short int d;

	a = udp->source_port;
	a = ((a >> 8) & 0xff) | ((a << 8) & 0xff00);
	memcpy(buffer + 34, &a, 2);
	b = udp->destination_port;
	b = ((b >> 8) & 0xff) | ((b << 8) & 0xff00);
	memcpy(buffer + 36, &b, 2);
	c = udp->length;
	c = ((c >> 8) & 0xff) | ((c << 8) & 0xff00);
	memcpy(buffer + 38, &c, 2);
	d = udp->checksum;
	d = ((d >> 8) & 0xff) | ((d << 8) & 0xff00);
	memcpy(buffer + 40, &d, 2);
}

void copy_pakiet2(struct data *data, unsigned char *buffer) {
	int l = sizeof(data->bufor_danych);

	memcpy(buffer + 42, data->bufor_danych, l);
}

