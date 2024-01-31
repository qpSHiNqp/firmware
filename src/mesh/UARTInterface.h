#pragma once

#include "RadioLibInterface.h"

/**
 * \brief Adapter for radio with UART Interface (especially E220-900T22S(JP)). Implements common logic for child classes.
 * \tparam T RadioLib module type for SX128x: SX1280.
 */
class UARTInterface : public RadioLibInterface
{
    RadioLibUART *lora = NULL;

  public:
    UARTInterface(RADIOLIB_PIN_TYPE tx, RADIOLIB_PIN_TYPE rx, RADIOLIB_PIN_TYPE aux, RADIOLIB_PIN_TYPE m0, RADIOLIB_PIN_TYPE m1);

    virtual bool init() override;
    virtual bool reconfigure() override;

    /// Prepare hardware for sleep.  Call this _only_ for deep sleep, not needed for light sleep.
    virtual bool sleep() override;

    // virtual bool RadioInterface::wideLora() override { return false; };
    // uint32_t RadioInterface::getPacketTime(<various types>)
    // uint32_t RadioInterface::getRetransmissionMsec(const meshtastic_MeshPacket *p)
    // meshtastic_QueueStatus RadioLibInterface::getQueueStatus()
    // virtual bool RadioLibInterface::cancelSending(NodeNum from, PacketId id) override; // no override maybe
    // ErrorCode RadioLibInterface::send(meshtastic_MeshPacket *p)

  protected:
    virtual void disableInterrupt() override;
    virtual void enableInterrupt(void (*callback)()) { lora.setDio1Action(callback); }
    virtual bool isChannelActive() override;

    /** are we actively receiving a packet (only called during receiving state) */
    virtual bool isActivelyReceiving() override;
    virtual void startReceive() override;
    virtual void addReceiveMetadata(meshtastic_MeshPacket *mp) override;
    virtual void configHardwareForSend() override;

  private:
    uint32_t activeReceiveStart = 0;
};