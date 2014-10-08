    global main
    extern scanf
    extern printf

segment .data
    prompt db 'What is your name? %s', 0h
    msg db 'Hello, %s', 0Ah, 0h

segment .text
main:
    sub rsp, 40h
    mov rsi, rsp
    mov rdi, prompt
    mov eax, 0
    call scanf
    mov rsi, rsp
    mov rdi, msg
    mov eax, 0
    call printf
    ret
