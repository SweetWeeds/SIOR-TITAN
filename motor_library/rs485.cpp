#include "rs485.h"

RS485::RS485(const char* dev, speed_t baudrate) {
    this->init(dev, baudrate);
}

RS485::~RS485() {
    this->Close();
}

void RS485::init(const char* dev, speed_t baudrate) {
    // Get serial port
    this->serial_port = open(dev, O_RDWR);

    // Read in existing settings, and handle any error
    if(tcgetattr(this->serial_port, &tty) != 0) {
        printf("Error %i from tcgetattr: %s\n", errno, strerror(errno));
    }
    tty.c_cflag &= ~PARENB; // Clear parity bit, disabling parity (most common)
    tty.c_cflag &= ~CSTOPB; // Clear stop field, only one stop bit used in communication (most common)
    tty.c_cflag |= CS8; // 8 bits per byte (most common)
    tty.c_cflag &= ~CRTSCTS; // Disable RTS/CTS hardware flow control (most common)
    tty.c_cflag |= CREAD | CLOCAL; // Turn on READ & ignore ctrl lines (CLOCAL = 1)
    tty.c_lflag &= ~ICANON;
    tty.c_lflag &= ~ECHO; // Disable echo
    tty.c_lflag &= ~ECHOE; // Disable erasure
    tty.c_lflag &= ~ECHONL; // Disable new-line echo
    tty.c_lflag &= ~ISIG; // Disable interpretation of INTR, QUIT and SUSP
    tty.c_iflag &= ~(IXON | IXOFF | IXANY); // Turn off s/w flow ctrl
    tty.c_iflag &= ~(IGNBRK|BRKINT|PARMRK|ISTRIP|INLCR|IGNCR|ICRNL); // Disable any special handling of received bytes
    tty.c_oflag &= ~OPOST; // Prevent special interpretation of output bytes (e.g. newline chars)
    tty.c_oflag &= ~ONLCR; // Prevent conversion of newline to carriage return/line feed
    // tty.c_oflag &= ~OXTABS; // Prevent conversion of tabs to spaces (NOT PRESENT ON LINUX)
    // tty.c_oflag &= ~ONOEOT; // Prevent removal of C-d chars (0x004) in output (NOT PRESENT ON LINUX)
    tty.c_cc[VTIME] = 10;    // Wait for up to 1s (10 deciseconds), returning as soon as any data is received.
    tty.c_cc[VMIN] = 0;
    // Set in/out baud rate to be 1.5Mbps
    cfsetispeed(&tty, BAUD_RATE);
    cfsetospeed(&tty, BAUD_RATE);
    // Save tty settings, also checking for error
    if (tcsetattr(serial_port, TCSANOW, &tty) != 0) {
        printf("Error %i from tcsetattr: %s\n", errno, strerror(errno));
    }
}

void RS485::Write(u8 data, size_t size) {
    write(this->serial_port, &data, size);
}

void RS485::Read(u8 *read_buf) {
    memset(read_buf, '\0', sizeof(*read_buf));
    int num_bytes = read(this->serial_port, read_buf, sizeof(*read_buf));
    if (num_bytes < 0) {
        printf("[ERROR] Reading: %s\n", strerror(errno));
    }
}

void RS485::Read(u8 *read_buf, int buf_size, int timeout_ms) {
    int rx_len = 0;
    struct timeval timeout;
    fd_set readFds;

    // recive time out config
    // Set 1ms timeout counter
    timeout.tv_sec  = 0;
    timeout.tv_usec = timeout_ms*1000;   

    FD_ZERO(&readFds);
    FD_SET(this->serial_port, &readFds);
    select((this->serial_port)+1, &readFds, NULL, NULL, &timeout);

    if(FD_ISSET(this->serial_port, &readFds))
    {
        rx_len = read(this->serial_port, read_buf, buf_size);		
    }
}

void RS485::Close() {
    close(this->serial_port);
}