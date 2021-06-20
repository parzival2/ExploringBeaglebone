#include <zcm/zcm-cpp.hpp>
#include <thread>
#include "rotation_t.hpp"
#include <iostream>

class Handler
{
public:
    ~Handler()
    {}

    void handleMessage(const zcm::ReceiveBuffer* rBuf,
                      const std::string& channel,
                      const rotation_t* msg)
    {
        std::cout << "Received message on channel : " << channel << std::endl;
        std::cout << "Roll : " << msg->roll << ", Pitch : " << msg->pitch
                  << ", Yaw : " << msg->yaw << std::endl;
    }
};

int main()
{
    zcm::ZCM zcm("inproc");
    zcm::ZCM udpZCM("udpm://239.255.76.67:7667?ttl=1");
    if(!zcm.good())
    {
        return 1;
    }
    rotation_t msg{};
    msg.roll = 0.;
    msg.pitch = 10.;
    msg.yaw = 100.;
    // Subscribe to the message
    Handler handler;
    zcm.subscribe("ROTATION", &Handler::handleMessage, &handler);
    zcm.start();
    // Start a while loop and keep on publishing
    while(true)
    {
        zcm.publish("ROTATION", &msg);
        udpZCM.publish("ROTATION_UDP", &msg);
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    zcm.stop();
    udpZCM.stop();
    return 0;
}
