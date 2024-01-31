#include "UARTInterface.h"

UARTInterface::UARTInterface(RADIOLIB_PIN_TYPE tx, RADIOLIB_PIN_TYPE rx, RADIOLIB_PIN_TYPE aux, RADIOLIB_PIN_TYPE m0,
                             RADIOLIB_PIN_TYPE m1)
{
    lora = new RadioLibUART(tx, rx, aux, m0, m1);
}

bool UARTInterface::init()
{
    RadioLibInterface::init();

    iface = lora;

    return true;
}

bool UARTInterface::reconfigure()
{
    RadioLibInterface::reconfigure();

    return true;
}

bool UARTInterface::sleep()
{
    RadioLibInterface::sleep();

    return true;
}

void UARTInterface::disableInterrupt()
{
    lora->setDio1Action(NULL);
}

bool UARTInterface::isChannelActive()
{
    return false;
}

bool UARTInterface::isActivelyReceiving()
{
    return false;
}

void UARTInterface::startReceive() {}

void UARTInterface::addReceiveMetadata(meshtastic_MeshPacket *mp)
{
    // LOG_DEBUG("PacketStatus %x\n", lora.getPacketStatus());
    mp->rx_snr = lora.getSNR();
    mp->rx_rssi = lround(lora.getRSSI());
}

void UARTInterface::configHardwareForSend() {}