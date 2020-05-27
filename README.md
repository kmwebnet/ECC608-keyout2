# ECC608-keyout

This gets a random 32byte key from signed HKDF master key which was created [ecc608hkdfcreate](https://github.com/kmwebnet/ECC608-hkdf-create) on Jetson Nano.  

# Requirements

  install "apt install build-essential".  
  prior to use this code, execute [ecc608hkdfcreate](https://github.com/kmwebnet/ECC608-hkdf-create).  

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
