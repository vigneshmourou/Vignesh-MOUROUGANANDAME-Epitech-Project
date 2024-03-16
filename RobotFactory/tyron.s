	.name "Tyron"
	.comment "Just a basic pompes, traction program"

	sti r3, %:hi, %1

hi:	live %234
	ld %0, r3
	zjmp %:hi
