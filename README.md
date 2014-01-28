I have modified some files of paparazzi UAS to meet our FYP's GOAL!






This file is used for record some solutions when you face ERROR.

1.When you click the "Execute" button of "Paparazzi Center", if it return this message:
  Failure("Error opening modem serial device : fd < 0 (/dev/ttyUSB0)")
  It means that something is wrong with the "datalink" configuration.

  For OSX:
  Since Paparazzi is currently configured to use /dev/ttyUSB0 it's easiest to just create a link to the required device.
  Remove all USB devices from the computer and run the command ls -l /dev/*usb* /dev/*USB* hopefully this will not list anything
  Plug in your radio and repeat the command ls -l /dev/*usb* /dev/*USB* this should now list the serial port that the radio has been connected to. In my case I get
    
    ls -l /dev/*usb* /dev/*USB*
  
  crw-rw-rw- 1 root wheel 11, 27 20 Jan 14:38 /dev/cu.usbserial-000013FD
  crw-rw-rw- 1 root wheel 11, 26 20 Jan 14:38 /dev/tty.usbserial-000013FD

  Next we need to create a symbolic link to the tty.usbserial device listed to /dev/ttyUSB0 in my case the command is sudo ln -s /dev/tty.usbserial-000013FD /dev/ttyUSB0
  To check that everything is correct run the first command again ls -l /dev/*usb* /dev/*USB* and you should get something like this
   
    ls -l /dev/*usb* /dev/*USB*

  crw-rw-rw- 1 root wheel 11, 27 20 Jan 14:38 /dev/cu.usbserial-000013FD
  crw-rw-rw- 1 root wheel 11, 26 20 Jan 14:38 /dev/tty.usbserial-000013FD
  lrwxr-xr-x 1 root wheel 0 20 Jan 14:42 /dev/ttyUSB0 -> /dev/tty.usbserial-000013FD
  
  ***It looks like there are some problems using the method mentioned above. So, just replace ...../dev/ttyUSB0 in the paparazzi center with your serial usb port identifier.

2.When you 'make' under /paparazzi directory and it shows such error:
  ERROR: make[1]: no rule for 'lib'
  It means it can't connect to the repository(git) of some external librany files.
  In order to solve this problem, using 'git' method instead of 'download zip file' method.