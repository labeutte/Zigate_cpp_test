/* 
 * File:  main.cpp
 * Author: Aucaigne
 * Version ci-dessous
 */
#define Debug 1
#define VERSION "21-05-2021" 

#include <stdio.h>
#include <iostream>
#include <pthread.h>
//#include <mosquitto.h>
#include "zigate.h"

using namespace std;

zigate maZig;
string comZig = "/dev/ttyUSB0";

void *serie (void * arg)
{
	printf("serie lancé\n");
        int p = maZig.ouvertureSerie(comZig);
	pthread_exit(0);
}

void *parser (void * arg)
{
	printf("serie lancé\n");
	pthread_exit(0);
}

/*** main ***/
int main(){
	pthread_t th_serie, th_parser;

	if(pthread_create(&th_serie, NULL, serie, "1") < 0)
		{fprintf(stderr, "pthread_create error for thread 1\n"); exit(1);
		}
	else
		{printf("Création thread serie réussie\n");
		}
	if(pthread_create(&th_parser, NULL, parser, "2") < 0)
		{fprintf(stderr, "pthread_create error for thread 2\n"); exit(1);
		}
	else
		{printf("Création thread 2 réussie\n");
		}


	return(1);
}