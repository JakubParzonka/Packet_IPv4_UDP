/*
 * funkcje.c
 *
 *  Created on: 16 maj 2016
 *      Author: root
 */
#include <stdio.h>
#include <stdlib.h>
#include "struktury.h"

void displayCharArray(char title[], int size, unsigned char value[]) {
	int i;
	printf("\n%s: ", title);

	for (i = 0; i < size - 1; i++) {
		printf("%02x:", value[i]);
	}
	printf("%02x", value[size]);

}
void displayCharTTL(char title[], int size, unsigned char value) {
	printf("\n%s: %d", title, value);
}

void displayChar(char title[], int size, unsigned char value) {
	printf("\n%s: %x", title, value);
}

void displayEthertype(char title[], int size, unsigned short int value) {
	printf("\n%s: %s%x", title, "0x0", value);
}

void displayShortInt(char title[], int size, unsigned short int value) {
	printf("\n%s: %x", title, value);
}

void displayShortIntTTL(char title[], int size, unsigned short int value) {
	printf("\n%s: %x", title, value);
}

void displayUDPLength(char title[], int size, unsigned short int value) {
	printf("\n%s: %d", title, value);
}

void displayInt(char title[], int size, unsigned int value) {
	printf("\n%s: %x", title, value);
}

void displayIntAddress(char title[], int size, unsigned int value) {
	printf("\n%s: %x", title, value);
}

void displayIntPort(char title[], int size, unsigned int value) {
	printf("\n%s: %d", title, value);
}
void displayV4Protocol(char title[], int size, unsigned char value) {
	printf("\n%s: %s%x", title, "0x", value);
}

void displayAddress(char title[], int size, unsigned char value[]) {

	int i;
	printf("\n%s: ", title);

	for (i = 0; i < size - 1; i++) {
		printf("%d.", value[i]);
	}
	printf("%d", value[size]);

}
void display_structure(el_listy *list) {
	//naglowek_eth.destination_mac_address
	displayCharArray("ETH DST_MAC",
			sizeof(list->pakiet->eth.destination_mac_address),
			list->pakiet->eth.destination_mac_address);

	//naglowek_eth.source_mac_address
	displayCharArray("ETH SRC_MAC",
			sizeof(list->pakiet->eth.source_mac_address),
			list->pakiet->eth.source_mac_address);

	//naglowek_eth.ethertype
	displayEthertype("ETH ETHERTYPE", sizeof(list->pakiet->eth.ethertype),
			list->pakiet->eth.ethertype);
	printf("\n");
	printf("\n");

	printf("IPv4 VER %x", list->pakiet->ipv4.version);
	printf("\n");
	printf("IPv4 HdL %x", list->pakiet->ipv4.header_lenght);

	//naglowek_ipv4.tos
	displayChar("IPv4 TOS", sizeof(list->pakiet->ipv4.tos),
			list->pakiet->ipv4.tos);

	//naglowek_ipv4.total_lenght
	displayShortIntTTL("IPv4 TOTAL_LENGHT",
			sizeof(list->pakiet->ipv4.total_lenght),
			list->pakiet->ipv4.total_lenght);

	//naglowek_ipv4.identification
	displayShortInt("IPv4 IDENTIFICATION",
			sizeof(list->pakiet->ipv4.identification),
			list->pakiet->ipv4.identification);

	//naglowek_ipv4.flags_fragment_offset
	printf("\nIPv4 FLAGS %x", list->pakiet->ipv4.flag);

	//naglowek_ipv4.flags_fragment_offset
	printf("\nIPv4 FRAGMENT_OFFSET %x", list->pakiet->ipv4.fragoffs);

	//naglowek_ipv4.time_to_live
	displayCharTTL("IPv4 TIME_TO_LIVE", sizeof(list->pakiet->ipv4.time_to_live),
			list->pakiet->ipv4.time_to_live);

	//naglowek_ipv4.protocol
	displayV4Protocol("IPv4 PROTOCOL", sizeof(list->pakiet->ipv4.protocol),
			list->pakiet->ipv4.protocol);

	//naglowek_ipv4.headerchecksum
	displayShortInt("IPv4 HEADERCHECKSUM",
			sizeof(list->pakiet->ipv4.headerchecksum),
			list->pakiet->ipv4.headerchecksum);

	//naglowek_ipv4.source_address
	displayAddress("IPv4 SOURCE_ADDRESS",
			sizeof(list->pakiet->ipv4.source_address),
			list->pakiet->ipv4.source_address);

	//naglowek_ipv4.destination_address
	displayAddress("IPv4 DESTINATION_ADDRESS",
			sizeof(list->pakiet->ipv4.destination_address),
			list->pakiet->ipv4.destination_address);

	printf("\n");

	//naglowek_udp.source_address
	displayIntPort("UDP PORT_SOURCE", sizeof(list->pakiet->udp.source_port),
			list->pakiet->udp.source_port);

	//naglowek_udp.destination_address
	displayIntPort("UDP PORT_DEST", sizeof(list->pakiet->udp.destination_port),
			list->pakiet->udp.destination_port);

	//naglowek_udp.length
	displayUDPLength("UDP LENGTH", sizeof(list->pakiet->udp.length),
			list->pakiet->udp.length);

	//naglowek_udp.checksum
	displayShortInt("UDP CHECKSUM", sizeof(list->pakiet->udp.checksum),
			list->pakiet->udp.checksum);

	//pakiet_udp.bufor_danych
	printf("\n");
	printf("\nDATA: ");
	printf("%s ", list->pakiet->data.bufor_danych);
}

void display_structure_from_struct(struct eth_ipv4_udp *pakiet) {
	//naglowek_eth.destination_mac_address
	displayCharArray("ETH DST_MAC", sizeof(pakiet->eth.destination_mac_address),
			pakiet->eth.destination_mac_address);

	//naglowek_eth.source_mac_address
	displayCharArray("ETH SRC_MAC", sizeof(pakiet->eth.source_mac_address),
			pakiet->eth.source_mac_address);

	//naglowek_eth.ethertype
	displayEthertype("ETH ETHERTYPE", sizeof(pakiet->eth.ethertype),
			pakiet->eth.ethertype);
	printf("\n");
	printf("\n");

	printf("IPv4 VER %x", pakiet->ipv4.version);
	printf("\n");
	printf("IPv4 HdL %x", pakiet->ipv4.header_lenght);

//naglowek_ipv4.tos
	displayChar("IPv4 TOS", sizeof(pakiet->ipv4.tos), pakiet->ipv4.tos);

//naglowek_ipv4.total_lenght
	displayShortIntTTL("IPv4 TOTAL_LENGHT", sizeof(pakiet->ipv4.total_lenght),
			pakiet->ipv4.total_lenght);

//naglowek_ipv4.identification
	displayShortInt("IPv4 IDENTIFICATION", sizeof(pakiet->ipv4.identification),
			pakiet->ipv4.identification);

//naglowek_ipv4.flags_fragment_offset
	printf("\nIPv4 FLAGS %x", pakiet->ipv4.flag);

//naglowek_ipv4.flags_fragment_offset
	printf("\nIPv4 FRAGMENT_OFFSET %x", pakiet->ipv4.fragoffs);

//naglowek_ipv4.time_to_live
	displayCharTTL("IPv4 TIME_TO_LIVE", sizeof(pakiet->ipv4.time_to_live),
			pakiet->ipv4.time_to_live);

//naglowek_ipv4.protocol
	displayV4Protocol("IPv4 PROTOCOL", sizeof(pakiet->ipv4.protocol),
			pakiet->ipv4.protocol);

//naglowek_ipv4.headerchecksum
	displayShortInt("IPv4 HEADERCHECKSUM", sizeof(pakiet->ipv4.headerchecksum),
			pakiet->ipv4.headerchecksum);

//naglowek_ipv4.source_address
	displayAddress("IPv4 SOURCE_ADDRESS", sizeof(pakiet->ipv4.source_address),
			pakiet->ipv4.source_address);

//naglowek_ipv4.destination_address
	displayAddress("IPv4 DESTINATION_ADDRESS",
			sizeof(pakiet->ipv4.destination_address),
			pakiet->ipv4.destination_address);

	printf("\n");

//naglowek_udp.source_address
	displayIntPort("UDP PORT_SOURCE", sizeof(pakiet->udp.source_port),
			pakiet->udp.source_port);

//naglowek_udp.destination_address
	displayIntPort("UDP PORT_DEST", sizeof(pakiet->udp.destination_port),
			pakiet->udp.destination_port);

//naglowek_udp.length
	displayUDPLength("UDP LENGTH", sizeof(pakiet->udp.length),
			pakiet->udp.length);

//naglowek_udp.checksum
	displayShortInt("UDP CHECKSUM", sizeof(pakiet->udp.checksum),
			pakiet->udp.checksum);

//pakiet_udp.bufor_danych
	printf("\n");
	printf("\nDATA: ");
	printf("%s ", pakiet->data.bufor_danych);
}

