#include "stm32f413h_discovery.h"
#include "stm32f413h_discovery_sd.h"
#include "F413ZH_SD_BlockDevice.h"

int F413ZH_SD_BlockDevice::init() {
  if(BSP_SD_Init() == MSD_OK) {
    return BD_ERROR_OK;
  }
    //no SD detected
    return BD_ERROR_DEVICE_ERROR;
}

int F413ZH_SD_BlockDevice::deinit() {
  if(BSP_SD_DeInit() == MSD_OK) {
    return BD_ERROR_OK;
  }
    //no SD detected
    return BD_ERROR_DEVICE_ERROR;
}

int F413ZH_SD_BlockDevice::program(const void *buffer, bd_addr_t addr, bd_size_t size) {
  int nBlocks = size / get_program_size();
  uint32_t *data_ptr = (uint32_t *) buffer;
  if (BSP_SD_WriteBlocks(data_ptr, addr / get_program_size(), nBlocks, SD_DATATIMEOUT) == MSD_OK) {
    //SD write OK
      return BD_ERROR_OK;
  } else {
    //Write failed
    return BD_ERROR_DEVICE_ERROR;
  }
}

int F413ZH_SD_BlockDevice::read(void *buffer, bd_addr_t addr, bd_size_t size) {
  int nBlocks = size / get_program_size();
  uint32_t *data_ptr = (uint32_t *) buffer;
  if (BSP_SD_ReadBlocks(data_ptr, addr / get_program_size(), nBlocks, SD_DATATIMEOUT) == MSD_OK) {
    //SD read OK
    return BD_ERROR_OK;
  } else {
    //read failed
    return BD_ERROR_DEVICE_ERROR;
  }
}

// int F413ZH_SD_BlockDevice::erase(bd_addr_t addr, bd_size_t size) {
//   if(BSP_SD_Erase(addr, size) == MSD_OK) {
//         return BD_ERROR_OK;
//     } else {
//         return BD_ERROR_DEVICE_ERROR;
//     }
// }

bd_size_t F413ZH_SD_BlockDevice::get_program_size() const {
  HAL_SD_CardInfoTypeDef CardInfo;
  BSP_SD_GetCardInfo(&CardInfo);
  return CardInfo.BlockSize;
}

bd_size_t F413ZH_SD_BlockDevice::get_read_size() const {
  HAL_SD_CardInfoTypeDef CardInfo;
  BSP_SD_GetCardInfo(&CardInfo);
  return CardInfo.BlockSize;
}

bd_size_t F413ZH_SD_BlockDevice::size() const {
  HAL_SD_CardInfoTypeDef CardInfo;
  BSP_SD_GetCardInfo(&CardInfo);
  return (bd_size_t)CardInfo.BlockNbr * (bd_size_t)CardInfo.BlockSize;
}
