#include <string.h>
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

#include "cryptoauthlib.h"
#include "hal/hal_linux_i2c_userspace.h"

#include "host/atca_host.h"


void get_atecc608cfg(ATCAIfaceCfg *cfg)
{
//	config for Jetson Nano
		cfg->iface_type             = ATCA_I2C_IFACE;
                cfg->devtype                = ATECC608A;
                cfg->atcai2c.slave_address  = 0XC0;
                cfg->atcai2c.bus            = 1;
                cfg->atcai2c.baud           = 1000000;
                cfg->wake_delay             = 1500;
                cfg->rx_retries             = 20;

return;
}

int main(int argc, char *argv[])
{

    ATCAIfaceCfg cfg;

    get_atecc608cfg(&cfg);

    ATCA_STATUS status = atcab_init(&cfg);
	
    if (status != ATCA_SUCCESS) {
        fprintf(stderr, "atcab_init() failed with ret=0x%08d\n", status);
        exit(1);
    }
	


uint8_t encryptkey[] = {
    0x77 , 0x72 , 0x69 , 0x74 , 0x69 , 0x6e , 0x67 , 0x20 , 0x70 , 0x75 , 0x62 , 0x20 , 0x6b , 0x65 , 0x79 , 0x20 , 
    0x62 , 0x79 , 0x20 , 0x75 , 0x73 , 0x69 , 0x6e , 0x67 , 0x20 , 0x65 , 0x6e , 0x63 , 0x72 , 0x79 , 0x70 , 0x74 ,
    };


    if (ATCA_SUCCESS != (status = atcab_write_zone(ATCA_ZONE_DATA, 6,  0, 0,  encryptkey, ATCA_KEY_SIZE)))
    {
        fprintf(stderr, "writing IO Protection Key by using atcab_write_zone() on slot 6 failed: %x\r\n", status);
        exit(1);
    }
    
    atcab_release();
    status = atcab_init(&cfg);
	
    if (status != ATCA_SUCCESS) {
        fprintf(stderr, "atcab_init() failed with ret=0x%08d\n", status);
        exit(1);
    }

//key read function
    uint8_t keyread[32];

    if (ATCA_SUCCESS != (status = atcab_read_enc(4,  0, keyread , encryptkey, 6)))
    {
        printf("atcab_read_enc(4,  0, keyread, encryptkey, 6) on slot 4 failed: %x\r\n", status);
    }

    // write to stdout
    fwrite(keyread , sizeof(uint8_t) , 32, stdout);
    fflush(stdout);

	atcab_release();

    return (0);
}



