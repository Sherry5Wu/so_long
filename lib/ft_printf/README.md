# ft_printf

This project is pretty straightforward, you have to recode printf. You will learn what is and how to implement variadic functions. Once you validate it, you will reuse this function in your future projects.

For the mandatory part, the function has to handle the following conversions: cspdiuxX%.

You have to implement the following conversions:

• %c Prints a single character.

• %s Prints a string (as defined by the common C convention).

• %p The void * pointer argument has to be printed in hexadecimal format. 

• %d Prints a decimal (base 10) number.

• %i Prints an integer in base 10.

• %u Prints an unsigned decimal (base 10) number.

• %x Prints a number in hexadecimal (base 16) lowercase format.

• %X Prints a number in hexadecimal (base 16) uppercase format.

• %% Prints a percent sign.


# Notes

-- When I tested my code on Mac OS, without including <stdint.h> library(which is for 'uintprt_t' type), the code still can compile and execute correctly. I don't know the reason. maybe it is because the Compiler predefinitions, or the C standard library implementation on macOS might automatically include the contents of <stdint.h> in certain cases, or its system headers may handle these standard types to ensure they are available. But for making the code more robust and portable, I still added <stdint.h> here.

-- When you wrtie test cases, always remember to test the boundary values and sepcial conditions, such as minimum value, maximum value, 0, NULL etc.


# Test tools

https://github.com/xicodomingues/francinette

https://github.com/Tripouille/printfTester


# My Result

<img width="825" alt="Screen Shot 2024-05-30 at 8 01 45 AM" src="https://github.com/Sherry5Wu/ft_printf/assets/132613292/18af792e-cd44-45fd-8bd5-2a4fdc88c488">
