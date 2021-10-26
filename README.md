#test task:
Write a small service that evaluates the accuracy of your computer's clock.  
The service must synchronize the system time using NTP 
(or wait for it to be executed), turn off synchronization 
(or wait for it to be turned off), wait for a predetermined time 
(second, minute, hour), request the time from NTP, 
and read the discrepancy with the system time accumulated over 
the evaluation period.  
This will also count.

Before starting to use it is necessary to install ntp:
$ sudo apt-get install ntp
