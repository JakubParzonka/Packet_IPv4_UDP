/*
 ============================================================================
 Name        : Lab_0.c
 Author      : krygier
 Version     : v1
 Copyright   : krygier
 Description : Lab_0
 ============================================================================
 */

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/socket.h>
#include <string.h>
#include <linux/if_packet.h>
#include <linux/if_ether.h>
#include <linux/if_arp.h>
#include <netinet/in.h>
#include <netdb.h>

#include "struktury.h"
#include "display.h"
#include "copy.h"
#include "linked_list.h"
#include "send.h"

#define INTERFACE	"wlan0"

el_listy *first;
struct eth eth;
struct ipv4 ipv4;
struct udp udp;
struct data data;

void change_eth_address_and_udp_port(el_listy *list) {
	el_listy *wsk = list;

	puts("\nLet's change some stuff");
	while (wsk != NULL) {
		wsk->pakiet->eth.destination_mac_address[0] = 0xaa;
		wsk->pakiet->eth.destination_mac_address[1] = 0xbb;
		wsk->pakiet->eth.destination_mac_address[2] = 0xcc;
		wsk->pakiet->eth.destination_mac_address[3] = 0xdd;
		wsk->pakiet->eth.destination_mac_address[4] = 0xee;
		wsk->pakiet->eth.destination_mac_address[5] = 0xab;
		wsk->pakiet->udp.destination_port = 25000;
		wsk = wsk->next;

	}
}

int main(void) {
	//definicja zmiennych
	int s; /*deskryptor gniazda*/
	int j = 0;
	int length = 0;

	//bufor dla ramek z Ethernetu
	void* buffer = (void*) malloc(ETH_FRAME_LEN);
	//wskaznik do naglowka Eth
	unsigned char* etherhead = buffer;

	printf("Program do odbierania ramek Ethernet z NIC!\n");
	//otworz gniazdo
	s = socket(AF_INET, SOCK_PACKET, htons(ETH_P_ALL));
	if (s == -1) {
		printf("Error creating socket");
	} else {
		printf("Socket otwarty!\n");
		first = (el_listy*) malloc(sizeof(el_listy));
		first->next = NULL;

		length = recvfrom(s, buffer, ETH_FRAME_LEN, 0, NULL, NULL);
		struct eth_ipv4_udp *pakiet = malloc(sizeof(struct eth_ipv4_udp));
		copy_eth(&eth, buffer);
		copy_ipv4(&ipv4, buffer);
		copy_udp(&udp, buffer);
		copy_pakiet(&data, buffer, length);
		copy_pak(pakiet, &eth, &ipv4, &udp, &data);

		first->pakiet = pakiet;
		while (j < 3) {
			//odbierz ramke Eth
			length = recvfrom(s, buffer, ETH_FRAME_LEN, 0, NULL, NULL);
			if (length == -1) {
				printf("Problem z odbiorem ramki");
			} else {
				printf("\nRamka: %d, dlugosc: %d [B]", j + 1, length);
				//12 i 13
				if (*(etherhead + 12) == 0x08 && *(etherhead + 13) == 0x00
						&& *(etherhead + 23) == 0x11) {

					printf("\nIPv4/UDP protocol\n");
					/***********************************/
					struct eth_ipv4_udp *super_pakiet = malloc(
							sizeof(struct eth_ipv4_udp));

					copy_eth(&eth, buffer);
					copy_ipv4(&ipv4, buffer);
					copy_udp(&udp, buffer);
					copy_pakiet(&data, buffer, length);
					copy_pak(super_pakiet, &eth, &ipv4, &udp, &data);
					//display_structure_from_struct(super_pakiet);
					add_to_list(first, super_pakiet);
					super_pakiet = 0;
					j++;
					/***********************************/
				} else {
					//printf("\nCos innego\n");
				}
			}
		}
		printf("\nPakiety rzekomo dodane do listy wiazanej\n");

	}

	print_list(first);
	change_eth_address_and_udp_port(first);
	printf("\nPO ZMIANIE\n");
	print_list(first);
	int l;
	el_listy *wsk = first;

	printf(
			"\n\n***********************************\nWysylanie do karty siecowej\n***********************************\n\n");
	while (wsk != NULL) {
		memset(buffer, 0, sizeof(buffer));

		printf("Dlugosc ipv4 = %d\n", wsk->pakiet->ipv4.total_lenght);

		l = 0;
		l = wsk->pakiet->ipv4.total_lenght + 16;

		copy_eth2(&wsk->pakiet->eth, buffer);
		copy_ipv42(&wsk->pakiet->ipv4, buffer);
		copy_udp2(&wsk->pakiet->udp, buffer);
		copy_pakiet2(&wsk->pakiet->data, buffer);
		printf("Dodane \n");

		/*unsigned char* etherhead = buffer;

		 for (i = 0; i < sizeof(etherhead) - 1; i++) {
		 printf("%02x:", *etherhead + 1);
		 }
		 */
		//displayCharArray("BUFOR: ", sizeof(buffer), buffer);
		wsk = wsk->next;
		//unsigned char* etherhead = buffer;
		//int i;
		wysylanie(buffer, l);
	}

	printf("\n\n\n  ***** Koniec programu *****");
	return EXIT_SUCCESS;
}

