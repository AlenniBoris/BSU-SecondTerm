.386

PUBLIC @IntToHex@8
PUBLIC @IntToOct@8
PUBLIC @IntToDec@8
PUBLIC @StrToInt32@4
PUBLIC @CharByIndex@8
PUBLIC @StrCompare@8
PUBLIC @StrChar@8

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

@StrToInt32@4 proc
	xor ebx, ebx
	xor esi, esi
	xor edx, edx
	beg1:
		mov dl, [ecx][esi]
		cmp dl,0
		je end1
			mov al,dl
			imul ebx, 10
			sub dl, '0'
			add ebx, edx
			inc esi
			jmp beg1
	end1:
		mov eax, ebx
ret
@StrToInt32@4 endp

@CharByIndex@8 proc
    xor esi,esi
    xor ebx,ebx

    cmp edx, 0
    jge JGE_
		mov al, 0
		jmp pr_end
    JGE_:
		beg1:
			mov bl, [ecx][esi]
			cmp bl, 0
			je end1
			inc esi
			jmp beg1
		end1:
 
    cmp esi, edx
    jge JGE1_
		mov al, 0
		jmp end_
    JGE1_:
		mov al, [ecx][edx]
		end_:
    pr_end:
ret
@CharByIndex@8 endp

@StrCompare@8 proc
;ecx- str1
;edx - str2
	
	xor eax,eax
	xor esi, esi

	beg1:
		mov al, [ecx][esi]
		cmp al, '0'
		je end1
			inc esi
			jmp beg1
	end1:

	xor edi, edi
	xor eax, eax

	beg2:
		mov al, [edx][edi]
		cmp al, '0'
		je end2
			inc edi
			jmp beg2
	end2:

	cmp esi, edi
	jge JGE_
		mov eax, -1
		jmp end_pr
	JGE_:
		cmp esi,edi
		jle JLE_
			mov eax, 1
			jmp end_pr
		JLE_:
			xor eax,eax
			xor esi,esi

			beg3:
				mov al, [ecx][esi]
				mov bl, [edx][esi]
				cmp al,0
				je end3
				cmp bl,0
				je end3
				cmp al, bl
				jne jne1
					inc esi
					jmp beg3
				jne1:
					cmp al,bl
					jl jl1
					mov eax, 1
					jmp endofif
				jl1:
					mov eax, -1
				endofif:

			end3:

	end_pr:
      
ret
@StrCompare@8 endp

@StrChar@8 proc

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


@Max@8 proc
	; ecx - int**
	; edx - int
	
	 xor esi,esi
		xor edi,edi
        xor ebp,ebp

		beg1:
			xor edi,edi
			cmp esi,edx
			je end1
				mov eax, [ecx][esi * 4]
				beg2:
				cmp edi,edx
				je end2
					mov ebx, [eax][edi * 4]
					cmp ebp,ebx
					jge jge1
						mov ebp, ebx
					jge1:
						inc edi
						jmp beg2
				end2:
			inc esi
			jmp beg1
		end1:
        
        mov eax, ebp


ret
@Max@8 endp

end