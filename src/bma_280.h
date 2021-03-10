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

#ifndef _EXAMPLE_FILE_NAME_H    /* Guard against multiple inclusion */
#define _EXAMPLE_FILE_NAME_H

/* ************************************************************************** */
/* ************************************************************************** */
/* Section: Included Files                                                    */
/* ************************************************************************** */
/* ************************************************************************** */
#include <stdint.h> 

/* This section lists the other files that are included in this file.
 */
/* Provide C++ Compatibility */
#ifdef __cplusplus
extern "C" {
#endif
    
#define CS_SET()               (LATDSET = (1<<4))
#define CS_CLEAR()             (LATDCLR = (1<<4))
#define CS_ENABLE()            (TRISDCLR = (1<<4))
#define READ                           (1)
#define WRITE                          (0) 
    
#define BMA280_CHIP_ID                                      (0xFB)      // Factory chip id : 1111'1011b    
#define BMA280_REG_ACCEL_CHIP_ID                            (0x00)      // Chip Identification Number Register
#define BMA280_REG_ACCEL_ACCEL_X_LSB                        (0x02)      // X-Axis Accelerometer Low Data Register
#define BMA280_REG_ACCEL_ACCEL_X_MSB                        (0x03)      // X-Axis Accelerometer High Data Register
#define BMA280_REG_ACCEL_ACCEL_Y_LSB                        (0x04)      // Y-Axis Accelerometer Low Data Register
#define BMA280_REG_ACCEL_ACCEL_Y_MSB                        (0x05)      // Y-Axis Accelerometer High Data Register
#define BMA280_REG_ACCEL_ACCEL_Z_LSB                        (0x06)      // Z-Axis Accelerometer Low Data Register
#define BMA280_REG_ACCEL_ACCEL_Z_MSB                        (0x07)      // Z-Axis Accelerometer High Data Register
#define BMA280_REG_ACCEL_TEMP                               (0x08)      // Temperature Data Register
#define BMA280_REG_ACCEL_INTR_STATUS                        (0x09)      // Interrupt Status Register
#define BMA280_REG_ACCEL_NEW_STATUS                         (0x0A)      // New Data Status Register
#define BMA280_REG_ACCEL_TAP_SLOPE_STATUS                   (0x0B)      // Tap and Slope Interrupt Status Register
#define BMA280_REG_ACCEL_FLAT_ORIENT_STATUS                 (0x0C)      // Flat and Orientation Status Register
#define BMA280_REG_ACCEL_G_RANGE                            (0x0F)      // G-Range Selection Register
#define BMA280_REG_ACCEL_BANDWIDTH                          (0x10)      // Selection of the Bandwidth for the Acceleration Data Register
#define BMA280_REG_ACCEL_POWER                              (0x11)      // Configuration of the Power Modes Register
#define BMA280_REG_ACCEL_PMU_POWER                          (0x12)      // Configuration of the Power Modes Register(PMU))
#define BMA280_REG_ACCEL_SPECIAL_CNTL                       (0x13)      // Selection of the Acceleration Data Acquisition and Data Output Format Register
#define BMA280_REG_ACCEL_SOFTRESET                          (0x14)      // SoftReset Register
#define BMA280_REG_ACCEL_INTERRUPT_SETTING1                 (0x16)      // Interrupt Settings Register
#define BMA280_REG_ACCEL_INTERRUPT_SETTING2                 (0x17)      // Interrupt Settings Register
#define BMA280_REG_ACCEL_INTERRUPT_MAPPING1                 (0x19)      // Interrupt Mapping Register
#define BMA280_REG_ACCEL_INTERRUPT_MAPPING2                 (0x1A)      // Interrupt Mapping Register
#define BMA280_REG_ACCEL_INTERRUPT_MAPPING3                 (0x1B)      // Interrupt Mapping Register
#define BMA280_REG_ACCEL_INTERRUPT_DATA_SRC                 (0x1E)      // Interrupt Data Source Definition Register
#define BMA280_REG_ACCEL_INTERRUPT_ELEC_BEHAVE              (0x20)      // Interrupt Pin Electrical Behaviour Register
#define BMA280_REG_ACCEL_INTERRUPT_RESET_MODE               (0x21)      // Interrupt Reset and Mode Selection Register
#define BMA280_REG_ACCEL_INTERRUPT_DELAY_TIME_L             (0x22)      // Low-g Interrupt Delay Time Definition Register
#define BMA280_REG_ACCEL_INTERRUPT_THRESHOLD_L              (0x23)      // Low-g Interrupt Threshold Definition Register
#define BMA280_REG_ACCEL_INTERRUPT_HYSTERESIS               (0x24)      // Low-g Interrupt Hysteresis Definition Register
#define BMA280_REG_ACCEL_INTERRUPT_DELAY_TIME_H             (0x25)      // High-g Interrupt Delay Time Definition Register
#define BMA280_REG_ACCEL_INTERRUPT_THRESHOLD_H              (0x26)      // High-g Interrupt Threshold Definition Register
#define BMA280_REG_ACCEL_INTERRUPT_SAMPLE_NUMBER            (0x27)      // Slope Interrupt Samples Number Definition Register
#define BMA280_REG_ACCEL_INTERRUPT_THRESHOLD                (0x28)      // Slope Interrupt Threshold Definition Register
#define BMA280_REG_ACCEL_TAP_QUIET_SHOCK_DUR                (0x2A)      // Tap Quiet Duration and Tap Shock Duration Register
#define BMA280_REG_ACCEL_INTERRUPT_SAMPLE_NUMBER1           (0x2B)      // Wake-Up and Threshold Interrupt Samples Number Register
#define BMA280_REG_ACCEL_INTERRUPT_HYSTERESIS_ORIENT        (0x2C)      // Hysteresis, Blocking for Orientation Interrupt Register
#define BMA280_REG_ACCEL_THETA_BLOCK_ANGLE                  (0x2D)      // Theta Blocking Angle Register
#define BMA280_REG_ACCEL_FLAT_THRESHOLD_ANGLE               (0x2E)      // Flat Threshold Angle Register
#define BMA280_REG_ACCEL_SENSOR_SELF_TEST                   (0x32)      // Sensor Self-Test Activation Settings Register
#define BMA280_REG_ACCEL_EEPROM_CONTROL                     (0x33)      // EEPROM Control Settings Register
#define BMA280_REG_ACCEL_DIGITAL_INTERFACE                  (0x34)      // Digital Interface Settings Register
#define BMA280_REG_ACCEL_OFFSET_COMPENSATION_FAST           (0x36)      // Fast Offset Compensation Settings Register
#define BMA280_REG_ACCEL_OFFSET_COMPENSATION_SLOW           (0x37)      // Slow Offset Compensation Settings Register
#define BMA280_REG_ACCEL_FILTER_COMPENSATION_X              (0x38)      // Filtered Data Compensation Settings for X-Axis Register
#define BMA280_REG_ACCEL_FILTER_COMPENSATION_Y              (0x39)      // Filtered Data Compensation Settings for Y-Axis Register
#define BMA280_REG_ACCEL_FILTER_COMPENSATION_Z              (0x3A)      // Filtered Data Compensation Settings for Z-Axis Register
#define BMA280_REG_ACCEL_UNFILTER_COMPENSATION_X            (0x3B)      // Unfiltered Data Compensation Settings for X-Axis Register
#define BMA280_REG_ACCEL_UNFILTER_COMPENSATION_Y            (0x3C)      // Unfiltered Data Compensation Settings for Y-Axis Register
#define BMA280_REG_ACCEL_UNFILTER_COMPENSATION_Z            (0x3D)      // Unfiltered Data Compensation Settings for Z-Axis Register
#define BMA280_REG_ACCEL_SOFTRESET_EN                       (0xB6)
/**************************************************************************
    ACCELEROMETER G-RANGE SELCTION REGISTER DESCRIPTION
**************************************************************************/
#define BMA280_REG_ACCEL_G_RANGE_MASK                       (0x0F)      // Selection of the g-Range
#define BMA280_REG_ACCEL_G_RANGE_2G                         (0x03)      // g-Range: ± 2g
#define BMA280_REG_ACCEL_G_RANGE_4G                         (0x05)      // g-Range: ± 4g
#define BMA280_REG_ACCEL_G_RANGE_8G                         (0x08)      // g-Range: ± 8g
#define BMA280_REG_ACCEL_G_RANGE_16G                        (0x0C)      // g-Range: ± 16g

/**************************************************************************
    ACCELEROMETER BANDWIDTH REGISTER DESCRIPTION
**************************************************************************/
#define BMA280_REG_ACCEL_BANDWIDTH_BW_MASK                  (0x1F)      // Selection of the Bandwidth for the Acceleration Data
#define BMA280_REG_ACCEL_BANDWIDTH_BW_7_81HZ                (0x08)      // Bandwidth: 7.81 Hz
#define BMA280_REG_ACCEL_BANDWIDTH_BW_15_63HZ               (0x09)      // Bandwidth: 15.63 Hz
#define BMA280_REG_ACCEL_BANDWIDTH_BW_31_25HZ               (0x0A)      // Bandwidth: 31.25 Hz
#define BMA280_REG_ACCEL_BANDWIDTH_BW_62_5HZ                (0x0B)      // Bandwidth: 62.5 Hz
#define BMA280_REG_ACCEL_BANDWIDTH_BW_125HZ                 (0x0C)      // Bandwidth: 125 Hz
#define BMA280_REG_ACCEL_BANDWIDTH_BW_250HZ                 (0x0D)      // Bandwidth: 250 Hz
#define BMA280_REG_ACCEL_BANDWIDTH_BW_500HZ                 (0x0E)      // Bandwidth: 500 Hz
#define BMA280_REG_ACCEL_BANDWIDTH_BW_1000HZ                (0x0F)      // Bandwidth: 1000 Hz
   
/**************************************************************************
    ACCELEROMETER LOW POWER MODES
**************************************************************************/    
#define BMA280_REG_ACCEL_PM_SUSP                            (0x80)    // Power mode register (0x11), bit 7
#define BMA280_REG_ACCEL_PM_LP                              (0x40)    // Low power mode    
#define BMA280_REG_ACCEL_LP_DISABLE                         (0x00)
    
/**************************************************************************
    ACCELEROMETER CALLBACK SOURCES
**************************************************************************/    
#define BMA280_X_AXIS_EVENT     (1)
#define BMA280_Y_AXIS_EVENT     (2) 
#define BMA280_Z_AXIS_EVENT     (3) 
#define BMA280_ANY_MOTION_EVENT (4)
#define BMA280_FLAT_EVENT       (5)    
   
   
/**************************************************************************
    LIBRARY FUNCTION DEFINITION
**************************************************************************/
void bma280_init(int8_t x_offset, int8_t y_offset, int8_t z_offset);
    
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


    /* Provide C++ Compatibility */
#ifdef __cplusplus
}
#endif

#endif /* _EXAMPLE_FILE_NAME_H */

/* *****************************************************************************
 End of File
 */
