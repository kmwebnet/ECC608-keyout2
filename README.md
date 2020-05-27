# ECC608-keyout

This gets a key from master key which was stored ATECC608A slot 4 on Jetson Nano.  

# Requirements

  install "apt install build-essential".  
  ATECC608A slot4 key preparation.  

# Environment reference
  
  Jetson Nano   
  this project initializes I2C 1 port.  
  pin assined as below:  


      I2C 1 SDA pin3   
      I2C 1 SCL pin5  
          
  Microchip ATECC608(on I2C port 1)  

# Usage

"git clone --recursive <this pages URL>" on your target directory and make -j4.  

# Run this project

execute "./keyout <target filename>" on termial.  
random 32byte key which uses with cryptsetup will emit to stdout.   

# License

This software is released under the MIT License, see LICENSE.
