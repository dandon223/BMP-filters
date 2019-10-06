# BMP
//ENG
My first programming project. You can load BMP with 32, 24, 16 or 8(only R5G5B5A0X1) bits pre pixel image and change its properties.
My program can use minimum, maximum, median, average and negative filter. It can also make grey copy of the image.
You give commands to the program in terminal. Example: source.bmp newImage.bmp neg 15
In this example source.bmp will be loaded and on its copy negative filter would be applied with filter mask 15x15 pixels.
Note that you can choose the area of the mask. The mask have to be square and its side has to be odd number.

=====================================================================================================================================



//PLN
Program wczytuje obraz BMP i dokonuje na nim roznych zmian poprzez zastosowanie filtrow.
Przykladowe wywolanie (w terminalu) :     obrazek.bmp  obrazek2.bmp min 15
W tym przypadku program wczyta obrazek.bmp , zastosuje na nim filtr minimalny  o szerokosci maski 15 pixeli oraz wynik zapisze w 
nowo stworzonym obrazku

inne filtry to med (medianowy), ave (usredniajacy), max (maksymalny), grey (czarno_bialy) , neg (negatyw)
Format BMP mozr miec bits_per_pixel 24, 32, 16 lub 8 , z tym ze dla 16 przyjmuje tylko postac R5G5B5A0X1
