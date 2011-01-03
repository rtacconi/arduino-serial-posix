/*
 * Arduino-serial
 * --------------
 *
 * A simple command-line example program showing how a computer can
 * communicate with an Arduino board. Works on any POSIX system (Mac/Unix/PC)
 *
 * Code modified from the example of  Tod E. Kurt, tod@todbot.com
 * http://todbot.com/blog/
 *
 */


#include "arduinoserialposix.h"

int main(int argc, char *argv[]) {
    int fd = 0;
    char serialport[256];
    int baudrate = B9600;  // default
    char buf[256];
    int rc,n;

    fd = serialport_init("/dev/tty.usbserial-A70062k8", baudrate);
    if(fd==-1) return -1;
    delay(2000);
    //rc = serialport_write(fd, "1");
    //if(rc==-1) return -1;
    //delay(7000);
    while(1) {
        serialport_read_until(fd, buf, '\n');
        printf("read: %s",buf);
    }

    exit(EXIT_SUCCESS);
} // end main