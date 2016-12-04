/*
 * struktury.h
 *
 *  Created on: 16 maj 2016
 *      Author: root
 */

#ifndef STRUKTURY_H_
#define STRUKTURY_H_

struct eth {
	unsigned char destination_mac_address[6];	// 6 bajtow
	unsigned char source_mac_address[6];		// 6 bajtów
	unsigned short int ethertype;				// 2 bajtów
//unsigned int crc;							// 4 bajtów
};
//suma ---->  		// 14 bajtów

struct ipv4 {									 // bajty
	unsigned char version :4,	 // 0.5
			header_lenght :4;	 // 0.5
	unsigned char tos; 							 // 1
	unsigned short int total_lenght; 			 // 2
	unsigned short int identification;			 // 2
	unsigned short int flag :4, fragoffs :12;
	unsigned char time_to_live; 				 // 1
	unsigned char protocol;  				     // 1
	unsigned short int headerchecksum; 			 // 2
	unsigned int source_address[4];				 // 4
	unsigned int destination_address[4];			 // 4
};
//suma ---->  		// 20 bajtów

struct udp {
	unsigned short int source_port;			// 2
	unsigned short int destination_port;		// 2
	unsigned short int checksum;				// 2
	unsigned short int length;					// 2
};
//suma ---->  		// 12 bajtów
struct data {
	unsigned char bufor_danych[1472];
};

struct eth_ipv4_udp {
	struct eth eth;
	struct ipv4 ipv4;
	struct udp udp;
	struct data data;
};

typedef struct list {   			// struktura w³asciwa z do utworzenia listy
	struct list *next; 	     		// wskaznik do nastepnego elementu
	struct eth_ipv4_udp *pakiet;     	// dane w strukturze typu eth_ip_udp
} el_listy;

#endif /* STRUKTURY_H_ */
