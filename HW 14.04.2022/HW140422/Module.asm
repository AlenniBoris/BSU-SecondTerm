.586




.model flat
.data
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
	fadd st(0), st(3)
ret
task_1 endp



end