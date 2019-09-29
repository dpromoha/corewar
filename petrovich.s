.name "Petrovich"
.comment "Agregat is my best friend!"

loop:	live %0
	zjmp %8

smth:
	sti r1, %:live0, %1
	fork %233
	and r1, %0, r1

mess:
	ld 0, r1
	st r1, 321
	live %1

live0:
	live %2
	fork %233
	ld %45, r2
	sti r2, %123, %0
