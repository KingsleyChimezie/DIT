<FOR LIVE CODE PREVIEW: http://tmpvar.com/markdown.html>

#    C14468272 - Kingsley Chimezie  
DT211C/4 - Dublin Institute of Technology  
Systems Integration - Assignment 1  
25 October 2017  

## FIRST TIME SETUP

### STEP 1: Log on to a terminal account 
Use a test account (sudo adduser "username")


### STEP 2: Download assignment script, copy and paste code to terminal:
cd  
wget -O C14468272.sh https://goo.gl/s6w1sN   
cd  
nano .bashrc  

### STEP 3: add the following code to the top of the .bashrc file, save and exit:
clear  
cd  
alias pw='pwd -LP'  
alias ifc='ifconfig -a eth0'  
alias dt='now="$(date +%Y%m%d%H%M%S)" printf "%s\n" "$now"'  
alias ud='INODE="$(ls -id -i /home)" echo "$UID,$(id -g),$USER,$(id -g -n),${INODE//[!0-9]/}"'  
sed -i -e 's/\r$//' C14468272.sh  
chmod +x C14468272.sh  
./C14468272.sh  

### STEP 5: Re-login 
su $USER