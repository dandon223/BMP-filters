# BMP
//ENG
My first programming project. You can load BMP with 32, 24, 16 or 8(only R5G5B5A0X1) bits pre pixel image and change its properties.
My program can use minimum, maximum, median, average and negative filter. It can also make grey copy of the image.
You give commands to the program in terminal. Example: source.bmp newImage.bmp neg 15
In this example source.bmp will be loaded and on its copy negative filter would be applied with filter mask 15x15 pixels.
Note that you can choose the area of the mask. The mask have to be square and its side has to be odd number.

Examples:

basic image:

![alt text](https://github.com/dandon223/BMP-filters/blob/master/images/hwa.bmp?raw=true)

average filter:

![alt text](https://github.com/dandon223/BMP-filters/blob/master/images/hwa_ave5.bmp?raw=true)

grey filter:

![alt text](https://github.com/dandon223/BMP-filters/blob/master/images/hwa_grey5.bmp?raw=true)

median filter:

![alt text](https://github.com/dandon223/BMP-filters/blob/master/images/hwa_med5.bmp?raw=true)

minimal filter:

![alt text](https://github.com/dandon223/BMP-filters/blob/master/images/hwa_min5.bmp?raw=true)

negativ filter:

![alt text](https://github.com/dandon223/BMP-filters/blob/master/images/hwa_neg5.bmp?raw=true)

