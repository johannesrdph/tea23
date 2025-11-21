readelf -S exercise-004
Im .rodata Teil [17] kann die Bytelänge des Segments gesehen werden. 
Diese verändert sich nicht durch die image.h (sollte eigentlich die 3145728 Bytes des Arrays beinhalten)

objdump -C -t build/bin/exercise-004 | grep image 
Sucht nach dem image symbol 