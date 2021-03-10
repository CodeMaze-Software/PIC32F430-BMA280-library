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
#include <stdlib.h>
#include "bma_280.h"
#include "definitions.h" 


typedef struct {
   
    int8_t max_x_axis_value;
    int8_t max_y_axis_value;
    int8_t max_z_axis_value;
    
}Threshold;

Threshold threshold;


void bma280_init(int8_t x_offset, int8_t y_offset, int8_t z_offset)
{
   CS_ENABLE();
   CS_SET();
    
   spi_transfer16(create_packet(BMA280_REG_ACCEL_G_RANGE, BMA280_REG_ACCEL_G_RANGE_16G, WRITE));
   spi_transfer16(create_packet(BMA280_REG_ACCEL_BANDWIDTH, BMA280_REG_ACCEL_BANDWIDTH_BW_250HZ, WRITE));
   
   spi_transfer16(create_packet(BMA280_REG_ACCEL_FILTER_COMPENSATION_X, x_offset, WRITE));
   spi_transfer16(create_packet(BMA280_REG_ACCEL_FILTER_COMPENSATION_Y, y_offset, WRITE));
   spi_transfer16(create_packet(BMA280_REG_ACCEL_FILTER_COMPENSATION_Z, z_offset, WRITE));
}

void register_bma280_callback(void (*pCallback)(uint8_t))
{
    acc_callback = pCallback;
}

void register_xyz_tresholds(int8_t x, int8_t y, int8_t z)
{
    threshold.max_x_axis_value = x;
    threshold.max_y_axis_value = y;
    threshold.max_z_axis_value = z;
}

void bma280_event(void)
{
    int8_t temp_x, temp_y, temp_z;
    static int8_t last_x, last_y, last_z;
    
    read_acc(&temp_x, &temp_y, &temp_z);
    
    if(temp_x <= 1 && temp_y <= 1)
    {
        if(acc_callback != NULL)
            acc_callback(BMA280_FLAT_EVENT);        
    }
    
    if(temp_x != last_x || temp_y != last_y || temp_z != last_z)
    {
        if(acc_callback != NULL)
            acc_callback(BMA280_ANY_MOTION_EVENT);  
    }
   
     
    if(abs(temp_x) > threshold.max_x_axis_value )
    {
        if(acc_callback != NULL)
            acc_callback(BMA280_X_AXIS_EVENT);
    }
    
    if(abs(temp_y) > threshold.max_y_axis_value )
    {    
        if(acc_callback != NULL)
            acc_callback(BMA280_Y_AXIS_EVENT);
    }
    
    if(abs(temp_z) > threshold.max_z_axis_value )
    {   
        if(acc_callback != NULL)
            acc_callback(BMA280_Z_AXIS_EVENT);
    }
    
    last_x = temp_x;
    last_y = temp_y;
    last_z = temp_z;
 
}

uint8_t read_chip_id(void)
{
    uint8_t ret_val = spi_transfer16(create_packet(BMA280_REG_ACCEL_CHIP_ID, 0, READ));
    
    return ret_val;
}

int8_t read_temperature(void)
{
    int8_t temperature = 23;
    int8_t value = spi_transfer16(create_packet(BMA280_REG_ACCEL_TEMP, 0, READ));
    
    temperature += (value / 2);
    
    return temperature;
}

void read_acc(int8_t *pXVal, int8_t *pYVal, int8_t *pZVal)
{   
    *pXVal = spi_transfer16(create_packet(BMA280_REG_ACCEL_ACCEL_X_MSB, 0, READ));
    *pYVal = spi_transfer16(create_packet(BMA280_REG_ACCEL_ACCEL_Y_MSB, 0, READ));
    *pZVal = spi_transfer16(create_packet(BMA280_REG_ACCEL_ACCEL_Z_MSB, 0, READ));
}

void sleep_mode(uint8_t mode)
{
    switch(mode)
    {
        case BMA280_REG_ACCEL_PM_SUSP:  
            spi_transfer16(create_packet(BMA280_REG_ACCEL_POWER, BMA280_REG_ACCEL_PM_SUSP, WRITE));    
            break;
        
        case BMA280_REG_ACCEL_PM_LP: 
            spi_transfer16(create_packet(BMA280_REG_ACCEL_PMU_POWER, BMA280_REG_ACCEL_PM_LP, WRITE));
            spi_transfer16(create_packet(BMA280_REG_ACCEL_POWER, BMA280_REG_ACCEL_PM_SUSP, WRITE));    
            break;  
            
        case BMA280_REG_ACCEL_LP_DISABLE: 
            spi_transfer16(create_packet(BMA280_REG_ACCEL_PMU_POWER, BMA280_REG_ACCEL_LP_DISABLE, WRITE));
            spi_transfer16(create_packet(BMA280_REG_ACCEL_POWER, BMA280_REG_ACCEL_LP_DISABLE, WRITE));    
            break;    
           
        default:
            /**/
            break;
    }
    
}

void soft_reset(void)
{
   spi_transfer16(create_packet(BMA280_REG_ACCEL_SOFTRESET, BMA280_REG_ACCEL_SOFTRESET_EN, WRITE)); 
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
