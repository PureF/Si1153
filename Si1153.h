#ifndef SI1153_H
#define SI1153_H

#include <Wire.h>

class Si1153
{
	public:

		Si1153();
		void config_channel(uint8_t index, uint8_t *conf);
		void write_data(uint8_t addr, uint8_t *data, int len);
		int read_register(uint8_t addr, uint8_t reg, int bytesOfData);
		void param_set(uint8_t loc, uint8_t val);
		int param_query(uint8_t loc);
		void send_command(uint8_t code);
		int get_int_from_bytes(uint8_t *data, size_t len);
		
		typedef enum {
			
			I2C_ADDRESS = 0x53			

		} UnitAddress;

		typedef enum {
		
			RESET_CMD_CTR = 0x00,
			RESET_SW = 0x01,
			FORCE = 0x11,
			PAUSE = 0x12,
			START = 0x13

		} CommandCodes;
		
		typedef enum {
			
			HOSTIN_0 = 0x0A,
			COMMAND = 0x0B,
			RESPONSE_0 = 0x11,
			RESPONSE_1 = 0x10,
			HOSTOUT_0 = 0x13,
			HOSTOUT_1 = 0x14,
			HOSTOUT_2 = 0x15
	
		} RegisterAddress;

		typedef enum {		
	
			CHAN_LIST = 0x01,
			ADCCONFIG_0 = 0x02,
			ADCSENS_0 = 0x03,
			ADCPOST_0 = 0x04,
			MEASCONFIG_0 = 0x05,
			MEASRATE_H = 0x1A,
			MEASRATE_L = 0x1B,
			MEASCOUNT_0 = 0x1C,
			MEASCOUNT_1 = 0x1D,
			MEASCOUNT_2 = 0x1E
			
		} ParameterAddress;


};

#endif
