#include <stdio.h>
#include "struktury.h"
#include <string.h>
#include <unistd.h> // dodane

#include <stdio.h>
#include <stdlib.h>

#include <sys/socket.h>
#include <linux/if_packet.h>
#include <linux/if_ether.h>
#include <linux/if_arp.h>
#include <sys/ioctl.h>

#define INTERFACE	"eth0"
int wysylanie(unsigned char *buffer, int l) {
	puts("Wysłanie ramki przez NIC");

	//definicja zmiennych
	int s_out; /*deskryptor gniazda*/
	int j;

	//bufor dla ramek z Ethernetu
	//void* buffer = (void*)malloc(ETH_FRAME_LEN);  moj koment
	//wskaxnik do naglowka Eth
	unsigned char* etherhead = buffer;
	//wskaznik do miejsca rozpoczecia danych
	unsigned char* data = buffer + 14;

	//inny wskaznik do naglowka Eth
	struct ethhdr *eh = (struct ethhdr *) etherhead;
	//adres docelowy
	struct sockaddr_ll socket_address;
	int send_result = 0;
	struct ifreq if_idx;
	int ifindex = 0;

	/*	printf("Argumanty funkcji main:\n----------------\n");
	 while(argc--)
	 printf("%s\n", *argv++);

	 printf("----------------\n");
	 */ //moja blokada!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//przygotowanie danych do wyslania
	/*socket_address.sll_family   = PF_PACKET;
	 //numer protokolu warstwy wyzszej <w tej chwili dowolny>
	 socket_address.sll_protocol = htons(ETH_P_IP);
	 //index urzadzenia siecowego pobrany dalej
	 //socket_address.sll_ifindex  = 2;
	 //protokol warswy wyzszej
	 //socket_address.sll_hatype   = 0x0800; //IP
	 //celem jest inny host
	 socket_address.sll_pkttype  = PACKET_OTHERHOST; */
	//dlugosc adresu Eth
	socket_address.sll_halen = ETH_ALEN;
	//MAC - poczatek
	/*socket_address.sll_addr[0]  = 0x00;
	 socket_address.sll_addr[1]  = 0xaa;
	 socket_address.sll_addr[2]  = 0xbb;
	 socket_address.sll_addr[3]  = 0xcc;
	 socket_address.sll_addr[4]  = 0xdd;
	 socket_address.sll_addr[5]  = 0xee;*/
	//MAC - koniec
	//socket_address.sll_addr[6]  = 0x00;/*nie uzywane*/
	//socket_address.sll_addr[7]  = 0x00;/*nie uzywane*/
	/*
	 ///////////////////Ustaw naglowek ramki///////////////////////////////////////
	 //Adres zrodlowy Eth
	 unsigned char src_mac[6] = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05};
	 //Adres docelowy Eth
	 unsigned char dest_mac[6] = {0x00, 0xaa, 0xbb, 0xcc, 0xdd, 0xee};
	 memcpy((void*)buffer, (void*)dest_mac, ETH_ALEN);
	 memcpy((void*)(buffer+ETH_ALEN), (void*)src_mac, ETH_ALEN);
	 eh->h_proto = htons (0x0800); //Protokol warstwy wyzszej: 0x0800 - pakiet IPv4
	 //////////////////////////////////////////////////////////////////////////////

	 /////////////////wylosuj lub ustaw dane dane do pola danych///////////////////////////////
	 //UWAGA! BUFOR DANYCH RAMKI JEST NASTEPUJACY: data[]
	 for (j = 0; j < 1500; j++) {
	 //data[j] = (unsigned char)((int) (255.0*rand()/(RAND_MAX+1.0)));
	 data[j] = 0xaa;
	 }
	 ////////////////////////////////////////////////////////////////////////////
	 */// kolejna blokada!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!1
	 //**************************wyslij ramke***********************************
#if 1 //tu mozna zablokowac wysylanie
	s_out = socket(AF_PACKET, SOCK_RAW, ETH_P_ALL);
	if (s_out == -1) {
		printf("Nie moge otworzyc gniazda s_out\n");
	}

	memset(&if_idx, 0, sizeof(struct ifreq));
	strncpy(if_idx.ifr_name, "eth0", IFNAMSIZ - 1);
	if (ioctl(s_out, SIOCGIFINDEX, &if_idx) < 0) {
		perror("SIOCGIFINDEX");
		exit(1);
	}
	ifindex = if_idx.ifr_ifindex;
	printf("Pobrano indeks karty NIC: %i\n", ifindex);
	//usatwiono index urzadzenia siecowego
	socket_address.sll_ifindex = ifindex;

	send_result = sendto(s_out, buffer, l, 0,
			(struct sockaddr*) &socket_address, sizeof(socket_address));
	if (send_result == -1) {
		printf("Nie moge wyslac danych! \n");
	} else {
		printf("Wyslalem dane do intefejsu: %s \n", INTERFACE);
		printf("Ilosc wyslanych znakow: %d \n", send_result);

	}

	//=======wypisz zawartosc bufora do wyslania===========
#if 1
	printf("Dane do wyslania: \n");
	for (j = 0; j < send_result; j++) {
		printf("%02x ", *(etherhead + j));
	}
	printf("\n*******************************************\n");
#endif
	//========koniec wypisywania===========================

#endif //konic blokady wysylania
	//*******************************************************************************

	return EXIT_SUCCESS;
}
