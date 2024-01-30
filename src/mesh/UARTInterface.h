#pragma once

#include "RadioLibInterface.h"

/**
 * \brief Adapter for SX128x radio family. Implements common logic for child classes.
 * \tparam T RadioLib module type for SX128x: SX1280.
 */
class UARTInterface : public RadioLibInterface
{
    RadioLibUART *lora = NULL;

  public:
    UARTInterface(RADIOLIB_PIN_TYPE tx, RADIOLIB_PIN_TYPE rx, RADIOLIB_PIN_TYPE aux,
                    RADIOLIB_PIN_TYPE m0, RADIOLIB_PIN_TYPE m1);
    
    bool isIRQPending() override { return lora.getIrqStatus() != 0; }

    /// Initialise the Driver transport hardware and software.
    /// Make sure the Driver is properly configured before calling init().
    /// \return true if initialisation succeeded.
    virtual bool init() override;

    /// Apply any radio provisioning changes
    /// Make sure the Driver is properly configured before calling init().
    /// \return true if initialisation succeeded.
    virtual bool reconfigure() override;

    /// Prepare hardware for sleep.  Call this _only_ for deep sleep, not needed for light sleep.
    virtual bool sleep() override;

    //virtual bool wideLora() override;

  protected:

    /**
     * Glue functions called from ISR land
     */
    virtual void disableInterrupt() override;

    /**
     * Enable a particular ISR callback glue function
     */
    virtual void enableInterrupt(void (*callback)()) { lora.setDio1Action(callback); }

    /** can we detect a LoRa preamble on the current channel? */
    virtual bool isChannelActive() override;

    /** are we actively receiving a packet (only called during receiving state) */
    virtual bool isActivelyReceiving() override;

    /**
     * Start waiting to receive a message
     */
    virtual void startReceive() override;

    /**
     * Add SNR data to received messages
     */
    virtual void addReceiveMetadata(meshtastic_MeshPacket *mp) override;

    virtual void setStandby() override;

    /**
     *  We override to turn on transmitter power as needed.
     */
    virtual void configHardwareForSend() override;

  private:
    uint32_t activeReceiveStart = 0;
};
