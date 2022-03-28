.386

PUBLIC @IntToHex@8
PUBLIC @IntToOct@8
PUBLIC @IntToDec@8


.model flat
.data
	abc db "0123456789ABCDEF"
.code

@IntToHex@8 proc
	xor bl,bl
	mov [edx][8],bl
	mov eax, 8
	beg1:
		cmp eax, 0
		jle end1
			mov ebx, ecx
			and ebx, 0000000Fh
			mov bl, abc[ebx]
			mov [edx][eax-1], bl
			shr ecx, 4
			dec eax
			jmp beg1
	end1:
ret
@IntToHex@8 endp

@IntToOct@8 proc
	xor bl,bl
	mov [edx][10],bl
	mov eax, 10
	beg1:
		cmp eax, 0
		jle end1
			mov ebx, ecx
			and ebx, 7
			mov bl, abc[ebx]
			mov [edx][eax-1], bl
			shr ecx, 3
			dec eax
			jmp beg1
	end1:
ret
@IntToOct@8 endp

@IntToDec@8 proc
	xor bl,bl
	mov [edx][32],bl
	mov eax, 32
	beg1:
		cmp eax, 0
		jle end1
			mov ebx, ecx
			and ebx, 1
			mov bl, abc[ebx]
			mov [edx][eax-1], bl
			shr ecx, 1
			dec eax
			jmp beg1
	end1:
ret
@IntToDec@8 endp


@Max@8 proc
	; ecx - int**
	; edx - int
	mov ebx, 4[ecx]
	mov eax, 8[ebx]
ret
@Max@8 endp

end