#ifndef MBED_F413ZH_SD_BLOCK_DEVICE_H
#define MBED_F413ZH_SD_BLOCK_DEVICE_H

#include "BlockDevice.h"

class F413ZH_SD_BlockDevice : public BlockDevice {
  public:
  int init();
  int deinit();
  int program(const void *buffer, bd_addr_t addr, bd_size_t size);
  int read(void *buffer, bd_addr_t addr, bd_size_t size);
  int erase(bd_addr_t addr, bd_size_t size);
  bd_size_t get_program_size();
  bd_size_t get_read_size();
};

#endif