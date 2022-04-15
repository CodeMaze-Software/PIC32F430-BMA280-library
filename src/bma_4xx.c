/* ************************************************************************** */
/** Descriptive File Name

  @Company
    Company Name

  @File Name
    filename.c

  @Summary
    Brief description of the file.

  @Description
    Describe the purpose of this file.
 */
/* ************************************************************************** */

/* ************************************************************************** */
/* ************************************************************************** */
/* Section: Included Files                                                    */
/* ************************************************************************** */
/* ************************************************************************** */

#include "bma_4xx.h"
#include "definitions.h" 

typedef struct Threshold{
   
    int8_t max_x_axis_value;
    int8_t max_y_axis_value;
    int8_t max_z_axis_value;
    
}threshold;

//Threshold threshold;

void bma4xx_init(int8_t x_offset, int8_t y_offset, int8_t z_offset)
{
   CS_ENABLE();
   CS_SET();
   
   /***/
}
    
void register_bma280_callback(void (*pCallback)(uint8_t))
{
    
}

void register_xyz_tresholds(int8_t x, int8_t y, int8_t z)
{
    
}

void bma280_event(void)
{
    
}

uint8_t read_chip_id(void)
{
    uint8_t ret_val = spi_transfer16(create_packet(BMA_4xx_ID_REG_ADDR, 0, READ));
    
    return ret_val;
}

int8_t read_temperature(void)
{
    
}

void read_acc(int8_t *pXVal, int8_t *pYVal, int8_t *pZVal)
{
    *pXVal = spi_transfer16(create_packet(BMA_4xx_X_REG_ADDR, 0, READ));
    *pYVal = spi_transfer16(create_packet(BMA_4xx_Y_REG_ADDR, 0, READ));
    *pZVal = spi_transfer16(create_packet(BMA_4xx_Z_REG_ADDR, 0, READ));    
}

void sleep_mode(uint8_t mode){
    
}

void soft_reset(void)
{
    spi_transfer16(create_packet(BMA_4xx_RST_REG_ADDR, 0xb6, WRITE));    
}

uint16_t create_packet(uint8_t addr, uint8_t data, uint8_t mode)
{
    uint16_t packet = 0;

    packet|= (mode << 15);
    packet|= (addr << 8);
    packet|= data; 

    return packet;
}

uint16_t spi_transfer16(uint16_t  payload)
{   
    int16_t ret_value = 0;
    
    CS_CLEAR();
    
    SPI1_WriteRead(&payload, sizeof(uint16_t), &ret_value, sizeof(uint16_t));
    
    CS_SET();
    
    return ret_value;
}



/* *****************************************************************************
 End of File
 */
