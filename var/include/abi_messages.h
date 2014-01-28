/* Automatically generated from /Users/tony-yi/git/paparazzi_local/conf/messages.xml */
/* Please DO NOT EDIT */

/* Onboard middleware library ABI
 * send and receive messages of class airborne
 */

#ifndef ABI_MESSAGES_H
#define ABI_MESSAGES_H

#include "subsystems/abi_common.h"

/* Messages IDs */
#define ABI_TEST_ABI_ID 0

/* Array and linked list structure */
#define ABI_MESSAGE_NB 1

EXTERN abi_event* abi_queues[ABI_MESSAGE_NB];

/* Callbacks */
typedef void (*abi_callbackTEST_ABI)(const int8_t value, const struct abi_boo boo, const struct Int32Vect3 * vect);

/* Bind and Send functions */

static inline void AbiBindMsgTEST_ABI(uint8_t sender_id, abi_event * ev, abi_callbackTEST_ABI cb) {
  ev->id = sender_id;
  ev->cb = (abi_callback)cb;
  ABI_PREPEND(abi_queues[ABI_TEST_ABI_ID],ev);
}

static inline void AbiSendMsgTEST_ABI(uint8_t sender_id, const int8_t value, const struct abi_boo boo, const struct Int32Vect3 * vect) {
  abi_event* e;
  ABI_FOREACH(abi_queues[ABI_TEST_ABI_ID],e) {
    if (e->id == ABI_BROADCAST || e->id == sender_id) {
      abi_callbackTEST_ABI cb = (abi_callbackTEST_ABI)(e->cb);
      cb(value, boo, vect);
    };
  };
};

#endif // ABI_MESSAGES_H
