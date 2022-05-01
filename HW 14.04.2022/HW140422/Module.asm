.586

.model flat
.data

	fir_board real4 -15.0
	sec_board real4 15.0

	fir_mean real4 0.0
	sec_mean real4 0.0

.const
	twelve real4 12.0;
	two real4 2.0

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

task_3 proc C, epsilon:DWORD 
			   LOCAL n:DWORD, znak:DWORD, calc_mean:DWORD, calc_p:DWORD

finit
fld1
fstp n
fld1
fstp znak
fldz
fstp calc_mean


_start: 
	fld1
	fld n
	fdivp
	fld n
	fdivp
	fld znak
	fmulp
	fst calc_p ; calc_p == (-1)^n+1 / n^2
	fld calc_mean
	faddp
	fstp calc_mean ; +=
	fld calc_p
	fabs
	fld epsilon
	; to compare

	fcompp
	fstsw ax
	test ax, 4500h
	jz _finish

		fld znak
		fchs; to change znak
		fstp znak
		
		fld n
		fld1
		faddp
		fstp n ; inc n

		jmp _start

_finish:

fld calc_mean
fild twelve
fmulp
fsqrt

ret 4
task_3 endp

task_2 proc C, f_coef:REAL8, s_coef:REAL8, th_coef:REAL8
finit 

fld sec_board ; max
fmul s_coef ; max * B
fld sec_board ; max, max * B
fmul sec_board ; max^2, max * B
fmul f_coef ; max^2 * A, max * B
fld sec_board ; max, max^2 * A, max * B
fmul sec_board 
fmul sec_board ; max^3, max^2 * A, max * B
fadd th_coef ; max^3 + C, max^2 * A, max * B
faddp st(1), st(0) ; 
faddp st(1), st(0) ; max^3 + C + max^2 * A + max * B
fstp sec_mean ; sec_mean <-- f(max)

fld fir_board
fmul s_coef 
fld fir_board 
fmul fir_board 
fmul f_coef 
fld fir_board
fmul fir_board 
fmul fir_board 
fadd th_coef 
faddp st(1), st(0)
faddp st(1), st(0)
fstp fir_mean ; fir_mean <-- f(min)

fld fir_mean
fld sec_mean
fmul


mov eax, 0
ftst
fstsw ax
test ax, 4500h
jz _out 

faddp st(0), st(0)
fld sec_board ; max
fld fir_board ; min, max

_start:
	fadd 
	fdiv two
	fld two ; 2, (min+max)/2
	fld sec_board
	fxch st(2)
	fst st(1)
	fst st(2)

	fmul st(1), st(0)
	fmul st(2), st(0)
	fmul st(2), st(0) ; (min+max)/2 , ((min+max)/2)^2, ((min+max)/2)^3

	; (min+max)/2 == t


	fmul s_coef
	fxch st(1)
	fmul f_coef
	fadd th_coef ; A * t^2 + C , B * t, t^3
	fadd st(0), st(1)
	fadd st(0), st(2) ; A * t^2 + C + B * t + t^3

	mov eax, 0
	ftst
	fstsw ax
	test ax, 4000h
	jnz _out 

	fmul fir_mean ; f(min)*( A * t^2 + C + B * t + t^3 )
	mov eax, 0
	ftst
	fstsw ax
	test ax, 0100h
	jnz _neg

	fdiv fir_mean
	fst fir_mean

	faddp st(0), st(0) ; B * (min + max) / 2, ((min + max) / 2) ^ 3
	faddp st(0), st(0)
	faddp st(0), st(0)

	fld sec_board
	fld fir_board
	fadd sec_board
	fdiv two
	fst fir_board
	jmp _start

	_neg: 
		fdiv fir_mean
		fst sec_mean

		faddp st(0), st(0) ; B * (min + max) / 2, ((min + max) / 2) ^ 3
		faddp st(0), st(0)
		faddp st(0), st(0)

		fld fir_board
		fld sec_board
		fadd fir_board
		fdiv two
		fst sec_board
		jmp _start

	_out:
		faddp st(0), st(0) ; B * (min + max) / 2, ((min + max) / 2) ^ 3
		fxch st(1) ; swapaem mestami 
		faddp st(0), st(0) ; B * (min + max) / 2
		fdiv s_coef
ret
task_2 endp




end