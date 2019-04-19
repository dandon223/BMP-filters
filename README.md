# BMP

Program wczytuje obraz BMP i dokonuje na nim roznych zmian poprzez zastosowanie filtrow.
Przykladowe wywolanie (w terminalu) :     obrazek.bmp  obrazek2.bmp min 15
W tym przypadku program wczyta obrazek.bmp , zastosuje na nim filtr minimalny  o szerokosci maski 15 pixeli oraz wynik zapisze w 
nowo stworzonym obrazku

inne filtry to med (medianowy), ave (usredniajacy), max (maksymalny), grey (czarno_bialy) , neg (negatyw)
Format BMP mozr miec bits_per_pixel 24, 32, 16 lub 8 , z tym ze dla 16 przyjmuje tylko postac R5G5B5A0X1
