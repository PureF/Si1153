
/**
 * param query as shown in the datasheet
 */
int Si1153::param_query(uint8_t loc){

    int result = -1;
    uint8_t packet[2];

    while(1){
  
        int cmmnd_ctr = Si1153::read_register(Si1153::I2C_ADDRESS, Si1153::RESPONSE_0, 1);
      
        packet[0] = Si1153::COMMAND;
        packet[1] = loc | (0B01 << 6);
        Si1153::write_data(Si1153::I2C_ADDRESS, packet, sizeof(packet));
      
        int r = Si1153::read_register(Si1153::I2C_ADDRESS, Si1153::RESPONSE_0, 1);
      
        if(r > cmmnd_ctr){

            result = Si1153::read_register(Si1153::I2C_ADDRESS, Si1153::RESPONSE_1, 1);
            break;
          
        }
  
    }

    return result;
  
}

/**
 * Sends command to the command register
 */
void Si1153::send_command(uint8_t code){

    uint8_t packet[2];

    while(1){
  
        int cmmnd_ctr = Si1153::read_register(Si1153::I2C_ADDRESS, Si1153::RESPONSE_0, 1);
      
        packet[0] = Si1153::COMMAND;
        packet[1] = code;
        Si1153::write_data(Si1153::I2C_ADDRESS, packet, sizeof(packet));
      
        int r = Si1153::read_register(Si1153::I2C_ADDRESS, Si1153::RESPONSE_0, 1);
    
        if(r > cmmnd_ctr){

            break;
             
        }
        
    }
    
}

/**
 * Returns int given a byte array
 */
int Si1153::get_int_from_bytes(uint8_t *data, size_t len){

  int result = 0;
  int shift = 8 * len;

  for(int i = 0; i < len; i++){
    
    shift -= 8;
    result |= ((data[i] << shift) & (0xFF << shift));
    
  }

  return result;
  
}
