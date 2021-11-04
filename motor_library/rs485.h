#ifndef RS_485_H
#define RS_485_H

// C library headers
#include <stdio.h>
#include <string.h>

// Linux headers
#include <fcntl.h> // Contains file controls like O_RDWR
#include <errno.h> // Error integer and strerror() function
#include <termios.h> // Contains POSIX terminal control definitions
#include <unistd.h> // write(), read(), close()

#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <sys/select.h>

#define BAUD_RATE B1500000

/*--------------------data definition ------------------------------------------------------------------------------------------------*/
typedef signed long s32; // 4 byte
typedef signed short s16; // 2 byte
typedef signed char s8; // 1 byte
typedef unsigned long u32; // 4 byte
typedef unsigned short u16; // 2 byte
typedef unsigned char u8; // 1 byte

class RS485 {
    private:
        struct termios tty;
        //int serial_port = open("/dev/ttyUSB1", O_RDWR);
        int serial_port;
        char read_buf[1];
    public:
        RS485(const char* dev, speed_t baudrate);
        ~RS485();
        void init(const char* dev, speed_t baudrate);
        void Write(u8 data, size_t size);
        void Read(u8 *buf);
        void Read(u8 *read_buf, int buf_size, int timeout_ms);
        void Close();
};

#endif