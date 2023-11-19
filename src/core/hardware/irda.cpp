#include "core/hardware/irda.h"

const char *IRDA_TAG = "irda";

IrDA::IrDA(int receiverPin, int senderPin)
    : irrecv(IRrecv(receiverPin)), irsend(IRsend(senderPin)) {}

void IrDA::initialize() {
  irrecv.enableIRIn();
  irsend.begin();
}

IRrecv *IrDA ::getReceiverDriver() { return &irrecv; }

IRsend *IrDA ::getSenderDriver() { return &irsend; }