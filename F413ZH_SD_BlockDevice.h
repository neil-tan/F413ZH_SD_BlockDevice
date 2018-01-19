#ifndef MBED_F413ZH_SD_BLOCK_DEVICE_H
#define MBED_F413ZH_SD_BLOCK_DEVICE_H

#include <mbed.h>
#include "BlockDevice.h"

class F413ZH_SD_BlockDevice : public BlockDevice {
  public:
  virtual int init();
  virtual int deinit();
  virtual int program(const void *buffer, bd_addr_t addr, bd_size_t size);
  virtual int read(void *buffer, bd_addr_t addr, bd_size_t size);
  // int erase(bd_addr_t addr, bd_size_t size);
  virtual bd_size_t get_program_size() const;
  virtual bd_size_t get_read_size() const;
  virtual bd_size_t size() const;
};

#endif