#include "core/hardware/irda.h"

const char *IRDA_TAG = "irda";

IrDA::IrDA(int receiverPin) : irrecv(IRrecv(receiverPin)) {}

void IrDA::initialize() { irrecv.enableIRIn(); }

IRrecv *IrDA ::getReceiverDriver() { return &irrecv; }