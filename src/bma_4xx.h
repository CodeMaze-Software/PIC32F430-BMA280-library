/* ************************************************************************** */
/** Descriptive File Name

  @Company
    Company Name

  @File Name
    filename.h

  @Summary
    Brief description of the file.

  @Description
    Describe the purpose of this file.
 */
/* ************************************************************************** */

#ifndef BMA_4XX_H    /* Guard against multiple inclusion */
#define BMA_4XX_H

#define CS_SET()               (LATDSET = (1<<4))
#define CS_CLEAR()             (LATDCLR = (1<<4))
#define CS_ENABLE()            (TRISDCLR = (1<<4))
#define READ                           (1)
#define WRITE                          (0) 

/* ************************************************************************** */
/* ************************************************************************** */
/* Section: Included Files                                                    */
/* ************************************************************************** */
/* ************************************************************************** */
#include <stdint.h> 

/**************************************************************************
    LIBRARY CHIP SELECT DEFINITION
***************************************************************************/
#define BMA_423
//#define BMA_456

/**************************************************************************
    LIBRARY VARIABLE DEFINITION
**************************************************************************/
#ifdef BMA_423
enum
{
    BMA_4xx_ID_REG_ADDR         =   (0x00),
    BMA_4xx_X_REG_ADDR          =   (0x13),
    BMA_4xx_Y_REG_ADDR          =   (0x15),
    BMA_4xx_Z_REG_ADDR          =   (0x17),
    BMA_4xx_TEMP_REG_ADDR       =   (0x22),
    BMA_4xx_ACC_CONF_REG_ADDR   =   (0x40), // Acc freq 
    BMA_4xx_RANGE_REG_ADDR      =   (0x41), // 16G, 8G etc : 00,01,10,11
    BMA_4xx_X_OFFSET_REG_ADDR   =   (0x71),
    BMA_4xx_Y_OFFSET_REG_ADDR   =   (0x72),
    BMA_4xx_Z_OFFSET_REG_ADDR   =   (0x73),
    BMA_4xx_PWR_CONF_REG_ADDR   =   (0x7C), // Smart power mode enable = 0x01
    BMA_4xx_PWR_REG_ADDR        =   (0x7D), // REG| = (1 << 2)) ACC enable
    BMA_4xx_RST_REG_ADDR        =   (0x7E), // Soft reset cmd = 0xb6

};
#endif

#ifdef BMA_456
enum
{
    BMA_4xx_ID_REG_ADDR         =   (0x00),
    BMA_4xx_X_REG_ADDR          =   (0x13),
    BMA_4xx_Y_REG_ADDR          =   (0x15),
    BMA_4xx_Z_REG_ADDR          =   (0x17),
    BMA_4xx_TEMP_REG_ADDR       =   (0x22),
    BMA_4xx_ACC_CONF_REG_ADDR   =   (0x40), // Acc freq 
    BMA_4xx_RANGE_REG_ADDR      =   (0x41), // 16G, 8G etc : 00,01,10,11
    BMA_4xx_X_OFFSET_REG_ADDR   =   (0x71),
    BMA_4xx_Y_OFFSET_REG_ADDR   =   (0x72),
    BMA_4xx_Z_OFFSET_REG_ADDR   =   (0x73),
    BMA_4xx_PWR_CONF_REG_ADDR   =   (0x7C), // Smart power mode enable = 0x01
    BMA_4xx_PWR_REG_ADDR        =   (0x7D), // REG| = (1 << 2)) ACC enable
    BMA_4xx_RST_REG_ADDR        =   (0x7E), // Soft reset cmd = 0xb6
};
#endif
/**************************************************************************
    LIBRARY FUNCTION DEFINITION
**************************************************************************/
void bma4xx_init(int8_t x_offset, int8_t y_offset, int8_t z_offset);
    
void register_bma280_callback(void (*pCallback)(uint8_t));    

void register_xyz_tresholds(int8_t x, int8_t y, int8_t z);

void bma280_event(void);

uint8_t read_chip_id(void);

int8_t read_temperature(void);

void read_acc(int8_t *pXVal, int8_t *pYVal, int8_t *pZVal);

void sleep_mode(uint8_t mode);

void soft_reset(void);

uint16_t create_packet(uint8_t addr, uint8_t data, uint8_t mode);

uint16_t spi_transfer16(uint16_t  payload);

void (*acc_callback)(uint8_t);

#endif /* _EXAMPLE_FILE_NAME_H */

/* *****************************************************************************
 End of File
 */
