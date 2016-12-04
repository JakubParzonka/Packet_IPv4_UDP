/*
 * linked_list.c
 *
 *  Created on: Oct 29, 2016
 *      Author: root
 */
#include <stdio.h>
#include <stdlib.h>
#include "struktury.h"
#include "display.h"

void add_to_list(el_listy *list, struct eth_ipv4_udp *pakiet) {
	el_listy *wsk, *nowy;
	wsk = list;
	printf("Adress elementu pierwszego -> %x\n", wsk);

	//display_structure_from_struct(pakiet);
	while (wsk->next != NULL) {
		wsk = wsk->next;
		printf("Adress elementu aktualnego -> %x\n", wsk);

		/* przesuwamy wsk az znajdziemy ostatni element */
	}
	nowy = (el_listy*) malloc(sizeof(el_listy));
	nowy->pakiet = pakiet;
	nowy->next = NULL;
	wsk->next = nowy;
	printf("Adress elementu nastepnego -> %x\n", wsk->next);

	//printf("Dodane \n");
	/* podczepiamy nowy element do ostatniego z listy */
}

void print_list(el_listy *list) {
	el_listy *wsk = list;
	//printf("Przed wyswietleniem");
	while (wsk != NULL) {
		//printf("IPv4 VER %x", list->pakiet->ipv4.version);
		printf("\n\n|*******************************************|");
		display_structure(wsk);
		wsk = wsk->next;
	}
}
