#include <fcntl.h>
#include <linux/i2c.h>
#include <linux/i2c-dev.h>
#include <sys/ioctl.h>
#include <iostream>
#include <string>
#include <stdio.h>
#include <cstring>
#include <unistd.h>

#include <bitset>

int main()
{
    uint8_t AS5600_ADDRESS = 0x36;
    uint8_t AS5600_STATE = 0x0b;
    // I2C device file that will be used for communications
    const std::string I2CDEVICE = "/dev/i2c-2";
    // We first open the I2C device
    int fileDescriptor = open(I2CDEVICE.c_str(), O_RDWR);
    if(fileDescriptor == -1)
    {
        std::cout << "Error in opening the device!" << std::endl;
        return 1;
    }
    else
    {
        std::cout << "The device has been successfully opened." << std::endl;
    }
    // We try it with the i2c_rwdr struct
    struct i2c_rdwr_ioctl_data ioctl_data;
    struct i2c_msg ioctl_msg[2];
    uint8_t returnData = 0;
    // Set all of them to be zero
    memset(ioctl_msg, 0, sizeof(ioctl_msg));
    memset(&ioctl_data, 0, sizeof(ioctl_data));
    // The first message is the write message
    ioctl_msg[0].addr = AS5600_ADDRESS;
    ioctl_msg[0].flags = 0;
    ioctl_msg[0].len = sizeof(AS5600_STATE);
    ioctl_msg[0].buf = &AS5600_STATE;
    // The next message is the read message
    ioctl_msg[1].addr = AS5600_ADDRESS;
    ioctl_msg[1].flags = I2C_M_RD;
    ioctl_msg[1].len = sizeof(returnData);
    ioctl_msg[1].buf = &returnData;
    // Set the messages to be delivered
    ioctl_data.msgs = ioctl_msg;
    ioctl_data.nmsgs = 2;
    // Perform the transfer
    int result = ioctl(fileDescriptor, I2C_RDWR, &ioctl_data);
    if(result < 0)
    {
        printf("ioctl error %s\n", strerror(errno));
    }
    std::cout << "Returned data : 0x" << std::hex << static_cast<uint32_t>(returnData) << std::endl;
    std::cout << "Returned data in binary : " << std::bitset<8>(returnData) << std::endl;
    close(fileDescriptor);
    return 0;
}
