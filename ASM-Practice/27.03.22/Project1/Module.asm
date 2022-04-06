.386

PUBLIC @StrChar@8

.model flat
.data
	abc db "0123456789ABCDEF"
.code

@StrChar@8 proc
;ecx- str
;edx - symbol

	xor esi, esi
    
	beg1:
		mov bl, [ecx][esi] 
		cmp bl, '0'
		je end1 
			cmp dl, bl
			jne jne1
				lea eax, [ecx+[esi]]
				jmp end1
			jne1:
			inc esi
			jmp beg1
	end1:
	
      
ret
@StrChar@8 endp

end