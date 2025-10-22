//Main stack pointer initialized at the end of SRAM

/* SRAM 1, includes DTCM */
#define SRAM1_START (0x20000000U)
#define SRAM1_SIZE  (496U * 1024U)
#define SRAM1_END (SRAM1_START + SRAM1_SIZE)

/* SRAM 2 */
#define SRAM2_START (0x2007C000U)
#define SRAM2_SIZE (16U * 1024U)
#define SRAM2_END (SRAM2_START + SRAM2_SIZE)

/* Initialize SP after SRAM2 */
#define STACK_POINTER_INIT_ADDRESS (SRAM2_END)