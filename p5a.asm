dosseg
.model tiny

.code
public  _pokeW
public  _putchar
public  _pokeB

_pokeB proc
  push bp
  mov bp,sp

  push ds
  push dx
  push bx
  push ax

  mov word ptr dx,[bp+4]      ;Segmento
  mov word ptr bx,[bp+6]      ;Offset
  mov byte ptr ah,[bp+8]      ;dato

  mov ds,dx
  mov[bx],ah

  pop ax
  pop bx
  pop dx
  pop ds
  pop bp
  ret
_pokeB endp

_pokeW proc
  push bp
  mov bp,sp

  push ds
  push dx
  push bx
  push ax

  mov word ptr dx,[bp+4]      ;Segmento
  mov word ptr bx,[bp+6]      ;Offset
  mov word ptr ax,[bp+8]      ;dato

  mov ds,dx
  mov[bx],ax

  pop ax
  pop bx
  pop dx
  pop ds
  pop bp
  ret
_pokeW endp

_putchar proc
  push bp
  mov bp,sp
  push dx
  push ax

  mov dl,[bp+4]
  mov ah,2
  int 21h

  pop ax
  pop dx
  pop bp
  ret
_putchar endp
end
