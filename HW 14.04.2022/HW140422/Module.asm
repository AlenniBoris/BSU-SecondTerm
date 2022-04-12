.586




.model flat
.const

	A_n real4 5.0
	B_n real4 12.0
	C_n real4 13.0

.code

task_1 proc C, x:QWORD, y:QWORD
finit
	fld y
	fld x
	fdiv st(0), st(1)
	fptan 
	fld x
	fmul st(0), st(0)
	fmul st(0), st(2); tg*x^2 --> st(0)
	fld y
	fld x
	fdiv st(0), st(1)
	fptan 
	fdiv st(0), st(1)
	fld y
	fmul st(0), st(0)
	fmul st(0), st(1); cot*y^2 --> st(0)
	fadd st(0), st(4)
ret
task_1 endp



task_3 proc C, epsilon:QWORD, fir_board:QWORD, sec_board:QWORD

finit

fld epsilon

ret
task_3 endp




Eq_form proc C, x:QWORD 

finit
fld x
fmul st(0),st(0)
fld x
fmul st(0), st(1) ; x^3
fld x
fmul st(0), st(0)
fmul A_n ; A*x^2
fadd st(0), st(1) ; A*x^2 + x^3 - st(0)
fld x
fmul B_n
fadd st(0), st(1) ; B*x + A*x^2 + x^3 - st(0)
fadd C_n ; C + B*x + A*x^2 + x^3 - st(0)

ret
Eq_form endp


task_2 proc C, epsilon:QWORD, fir_board:QWORD, sec_board:QWORD

fld fir_board
call Eq_form


ret
task_2 endp




end