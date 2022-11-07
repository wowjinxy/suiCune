## Common Conversions

| ASM Macros | C Code | Notes
|------------|--------|----
| ```LD_B(45);```| ```REG_B = 45;``` |
| ```LD_A_addr(wVar);```| ```REG_A = gb_read(wVar);``` |
| ```LD_addr_A(wVar);```| ```gb_write(wVar, REG_A);``` |
| ```LD_A_hli;```| ```REG_A = gb_read(REG_HL++);``` |
| ```LDH_addr_A(hVar);```| ```gb_write(hVar, REG_A); ``` |
| ```LDH_A_c;```| ```REG_A = gb_read(0xFF00 + REG_C); ``` |
| ```XOR_A_A;```| ```REG_A = 0;``` | XORing a register with itself is just a fancy way of setting it to zero.
| ```AND_A_A;```| ```carry = 0;```<br/>```zero = (REG_A == 0);``` | ANDing a register with itself doesn't modify the register, but it does modify flags. It's an easy way to set the carry flag to zero and test register a for zero.
| ```CPL;```| ```REG_A ^= 0xFF;```
|```LD_A(CONSTANT);```<br/>```LD_addr_A(wVar);```| ```gb_write(wVar, CONSTANT);``` | In C, we don't need a register middleman to write a constant to memory.
| ```CP_A(X);```<br/>```IF_NC goto label;```| ```carry = (REG_A < X);```<br/>```if(!carry) goto label;``` | Comparing register a with a value will set the carry flag if register a is less than the value. So not carry would be true if register a is greater than or equal to the value.
| ```AND_A_A;```<br/>```IF_Z goto label;```| ```if(REG_A == 0) goto label;```
| ```LD_A_addr(wVar);```<br/>```LD_hli_A;```| ```gb_write(REG_HL++, gb_read(wVar));```
| ```loop:```<br/>```____...```<br/>```____DEC_B;```<br/>```____IF_NZ goto loop;```| ```do { ```<br/>```____...```<br/>```} while(--REG_B != 0);```