#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

int main() {
	
	
	unsigned char shellcode[] = 
		"\x31\xd2\xb2\x30\x64\x8b\x12\x8b\x52\x0c\x8b\x52\x1c\x8b\x42"
		"\x08\x8b\x72\x20\x8b\x12\x80\x7e\x0c\x33\x75\xf2\x89\xc7\x03"
		"\x78\x3c\x8b\x57\x78\x01\xc2\x8b\x7a\x20\x01\xc7\x31\xed\x8b"
		"\x34\xaf\x01\xc6\x45\x81\x3e\x46\x61\x74\x61\x75\xf2\x81\x7e"
		"\x08\x45\x78\x69\x74\x75\xe9\x8b\x7a\x24\x01\xc7\x66\x8b\x2c"
		"\x6f\x8b\x7a\x1c\x01\xc7\x8b\x7c\xaf\xfc\x01\xc7\x68\x67\x20"
		"\x20\x01\x68\x65\x72\x44\x62\x68\x20\x48\x79\x70\x89\xe1\xfe"
		"\x49\x0b\x31\xc0\x51\x50\xff\xd7";


	 PVOID Memory = VirtualAlloc(0, sizeof(shellcode), MEM_COMMIT, PAGE_EXECUTE_READWRITE);
	// PVOID Memory = VirtualAlloc(0, sizeof(shellcode), MEM_COMMIT, PAGE_READWRITE);
	memcpy(Memory, shellcode, sizeof(shellcode));

	printf("Address of allocated buffer: %x | Process Id: %x\n", Memory, GetCurrentProcessId());
	printf("Press any key to run shellcode!\n");

	_getch();

	((void(*)())Memory)();

    VirtualFree(Memory, 0, MEM_RELEASE);
	printf("The program executed successfully!\n");

	_getch();

    return 0;
}