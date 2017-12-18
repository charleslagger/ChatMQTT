// ./pub -c <client name> -i <ip address> -p <port> -t <topic> -n <loop count>
// ./pub -i 127.0.0.1 -p 1883 -t google/gmail -c client -n 5
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "mqtt.h"

#include <unistd.h> // for sleep function

const char *client_name = "default_pub"; 	// -c
const char *ip_addr = "127.0.0.1";		// -i
uint32_t port = 1883;			// -p
const char *topic = "google/gmail";	// -t //xac nhan ben nhan thong tin, co cau truc phan tang
uint32_t count = 10;			// -n

void parse_options(int argc, char** argv);

int main(int argc, char** argv) {
	puts("MQTT PUB Test Code");

	mqtt_broker_handle_t *broker = mqtt_connect(client_name, ip_addr, port);

	if (broker == 0) {
		puts("Failed to connect");
		exit(1);
	}
	
	char msg[128];

	for (int i = 1; i <= count; ++i) {
		scanf("%s", msg);
		// sprintf(msg, "Message number %d", i);
		if (mqtt_publish(broker, topic, msg, QoS1) == -1) {
			printf("publish failed\n");
		} else {
			//Do nothing
		}
		sleep(1);
	}
	mqtt_disconnect(broker);
}

void parse_options(int argc, char** argv) {
	for (int i = 1; i < argc; ++i) {
		if (strcmp("-c", argv[i]) == 0) {
			printf("client:%s ", argv[++i]);
			client_name = argv[i];
		}
		if (strcmp("-i", argv[i]) == 0) {
			printf("ip:%s ", argv[++i]);
			ip_addr = argv[i];
		}
		if (strcmp("-p", argv[i]) == 0) {
			printf("port:%s ", argv[++i]);
			port = atoi(argv[i]);
		}
		if (strcmp("-t", argv[i]) == 0) {
			printf("topic:%s ", argv[++i]);
			topic = argv[i];
		}
		if (strcmp("-n", argv[i]) == 0) {
			printf("count:%s ", argv[++i]);
			count = atoi(argv[i]);
		}
	}
	puts("");
}

