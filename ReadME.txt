Buffer Overflow Attack

The purpose of this assignment is to get the students a first-hand experience on buffer-overflow vulnerability by putting what they have learned about the vulnerability from class into action. This vulnerability arises due to the situation where a program attempts to write data beyond preallocated fixed length buffers in memory. Hence, overflow of data part can affect the control flow of the program which the students will experience through this lab.

Lab Tasks:
The suggested environment to conduct this attack is to use a Kali 32-bit Virtual Machine. The below link can be used to download the Kali VM. But you are allowed to use whatever VM you would like. Please make sure you CLEARLY STATE ALL THE ASSUMPTIONS.

KALI-32bit: https://drive.google.com/file/d/1wDMrx8xK9aZjV41cDocNCe2-4JwVD7EX/view 
Once downloaded you will get a Kali Linux 2018.2 (32bit).vdi file. Then, you can create a new VM in VirtualBox and use the VDI file when you will be asked to create diskspace.

Once the VM is successfully installed in VirtualBox, you have to disable “address space randomization” using the following command. (root> sysctl -w kernel.randomize_va_space=0).

Things to consider:
1. You are allowed to browse external links (I have given some) and find if you can conduct the buffer-overflow attack in your virtual machine.
2. There is no hard requirement that you should be conducting the attack in Kali-32 bit machine. You are allowed to use SEED, UBUNTU, or whatever VM that suits for you.
3. You can certainly follow the lecture slides and conduct the attack in SEED VM. I have tried the link-1 (given below) and succeeded in conducting the attack. I am encouraging students to follow other options to do this attack too.

Task-1: Please layout the stack frame for the following sample function:
int myfunction(char *stringPtr, int x)
{
 char mybuf[50];
 int y = x;
 strcpy(mybuff, stringPtr);
 return 1;
}

Task-2: Please state the memory segment where the variables used in the following code will be located?

int x = 0;
void myfunction(char *stringArg)
{
 char *pointer = malloc(sizeof(int));
 char myBuffer[2048];
 int flag;
 static int z;
}

Task-2: You have to create a vulnerable C-program (LastName_VulnCode.c) that has buffer overflow issue. Then, try to craft a payload that the vulnerable program will take as input and store to the buffer in such a way that the return address will point to a valid instruction (possibly NOP).

Note: Make the output of the program as root-owned SETUID program before you execute.

If you have read the handout provided to you in class on the buffer overflow topic, you can find instructions there on how to execute such attack. Feel free to adopt that if you find interesting.

Otherwise, you are free to follow the instructions from any other link you like. Capture the screenshots of every step of making the attack happen, which you will have to include in the report.

Mention about the link(s) you have followed for doing this lab.
Some recommended links:
1. https://dhavalkapil.com/blogs/Shellcode-Injection/
2. https://gist.github.com/apolloclark/6cffb33f179cc9162d0a
3. https://samsclass.info/127/proj/p3-lbuf1.htm

Task-3: If you succeed in the attack, you will get into shell program with “#>” sign. Check whether it is root or a normal user. If you found the user is normal user and no information on effective id, then try to change the shellcode in such a manner that it will call “/bin/zsh”, instead of /bin/sh. Then, redo the experiment and see if you find any difference. Put your observations and explanations in the report.

Task-4: 
a. Turn on the address randomization. Can you succeed in the attack? Report your observations. If running the vulnerable code once does not get you the root shell, how about running it for many times? (Hint: you may want to run a script that will execute the vulnerable program many times)

b. How about turning the noexecstack option on, can you still get into the shell?
Example: >> gcc -o output -fno-stack-protector -z noexecstack LastName_VulnCode.c

Note: In case you feel difficulty in any parts (either understanding the problem or finding right solutions, please do not hesitate to post in Piazza or stop by my office. Start the lab early so you could finish in time.