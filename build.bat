zcc +msx -create-app -O3 -lm -subtype=msxdos dda.c -bn DDA.COM
del DDA.img
move /y DDA.COM bin
cd bin
START /WAIT DISKMGR.exe -A -F -C DDA.DSK DDA.COM
cd ../
