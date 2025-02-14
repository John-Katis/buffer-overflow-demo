# Part I - Stack smasing attack

## Preliminaries

We have a C program that controls a safe, called `withdraw.c`. Our goals are to: 

- Analyze source code to identify a possible buffer overflow. 
- Analyze and explain how stack smashing exploit code works. 
- Describe how a stack smashing buffer overflow attack works. 
- Examine the stack and describe how stack smashing changes the stack.

## Directions

1. Examine the source code file withdraw.c. 

    _1.1._ Describe the withdraw program. What exactly does the program do?

2. Compile the withdraw program without the Stack Smashing Protector and Address Space Layout Randomization: 

    ```bash
    gcc -no-pie -fno-stack-protector -o withdraw withdraw.c
    ```

    (Normally the default setting ‘gcc -o withdraw withdraw.c’ is equivalent to having none of the stated protector)

    _2.1._ Run the program 'withdraw' with
    ```bash
    ./withdraw
    ```

3. Examine the source code file open.c.

    _3.1._ Describe the open program. What exactly does the program do?

4. Compile the open program: 

    ```bash
    gcc -o open open.c 
    ```

5. Run the open command and send the output to the withdraw program:

    ```bash
    ./open | ./withdraw 
    ```

    And observe the stack change with and without sending the output of open to the program.

    _5.1._ Examine the stack, how does it change when the output of open is sent to it?  

    _5.2._ What is the memory location of the ‘open_safe’ function?

6. Change the value of the occurrence of the for loop in the ‘open.c’ program, recompile and rerun the withdraw using the output of open:

    First run
    ```bash
    gcc -o open open.c 
    ```
    Then
    ```bash
    ./open | ./withdraw 
    ```

    _6.1._ At which point does the program cause segmentation fault? 

    _6.2._ What does it mean to have a segmentation fault? What information can we deduct from here?

7. Change the address value in ‘open.c’ into the address of the ‘open_safe’ function. 

8. Add padding by printing extra characters in the ‘open.c’ program before the address. Recompile the ‘open’ program and run it as the input for ‘withdraw’ program

    _8.1._ With how many padding did the safe open?
    _8.2._ What happened?

# Part II - Protection Mechanisms

Having identified the ﬂaw in the code above, you are asked to fix it without changing the source code.

## Learning Objectives

- Using the stack smashing protector to protect the stack and predicting the behavior of a program compiled with it.

- Understand and explain why subtle changes can cause exploit code to fail, but may not fix the vulnerability.

## Directions

1. Recompile the withdraw program using the Stack Smashing Protector:

    ```bash
    gcc -no-pie -fstack-protector -o withdraw withdraw.c 
    ```

    _1.1._ What behavior do you expect from the protected version of the withdraw program? Justify your answer. 

2. Run the withdraw program again using open.c:

    _2.1._ How did the protected version of the withdraw program behave? Were you able to successfully predict this behavior in the previous question? If not, explain the discrepancy. 

3. Recompile the withdraw program using the Stack Smashing Protector:

    ```bash
    gcc -fstack-protector -o withdraw withdraw.c 
    ```

    _3.1._ What behavior do you expect from the protected version of the withdraw program? Justify your answer. 

4. Run the withdraw program again using open.c:

    _4.1._ How did the protected version of the withdraw program behave? Were you able to successfully predict this behavior in the previous question? If not, explain the discrepancy. 