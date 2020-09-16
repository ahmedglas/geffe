#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

// #define IS_TAP(x)	((x==31)||(x==6)||(x==4)||(x==2)||(x==1)||(x==0))

static unsigned char mode;


void printBin(int C)
{
	int i = 0;
	for(i=8*sizeof(C)-1;i>=0;i--)
	{
        if(IS_TAP(i) && (i!=0))
			 printf("(%d)",(C>>i)&1);
		else if (!IS_TAP(i))
			 printf("%d",(C>>i)&1);
		else
			 printf("%d",(C>>i)&1);
	}
	puts("");
}


void printOut(int C)
{
	printf("%d",(C>>0)&1);

}


int LFSR() {
	static unsigned int ShiftRegister1  = 147;
	static unsigned int ShiftRegister2  = 2179;
	static unsigned int ShiftRegister3 = 45;
	/*Anything but 0*/
	if(mode=='S' || mode == 's')
		printBin(ShiftRegister);
	else
		printOut(ShiftRegister);



    ShiftRegister1 = ((((ShiftRegister1 >> 7)
				^ (ShiftRegister1 >> 4)
				^ (ShiftRegister1 >> 1)
				^ (ShiftRegister1 >> 0)
				^ (ShiftRegister1))
				& 0x00000001)
				<< 15)
			    | (ShiftRegister3 >> 1);  

	ShiftRegister2 = ((((ShiftRegister2 >> 0)
				^ (ShiftRegister2 >> 1)
				^ (ShiftRegister2 >> 7)
				^ (ShiftRegister2 >> 11)
				^ (ShiftRegister2))
				& 0x00000001)
				<< 15)
			    | (ShiftRegister1 >> 1);

    ShiftRegister3 = ((((ShiftRegister3 >> 0)
				^ (ShiftRegister3 >> 2)
				^ (ShiftRegister3 >> 3)
				^ (ShiftRegister3 >> 5)
				^ (ShiftRegister3))
				& 0x00000001)
				<< 15)
			    | (ShiftRegister2 >> 1);
       
                
	return ShiftRegister1 & 0x00000001;

    
}

void usage(){
	puts("/-------------/");
	printf("First argument determines how many random bits you want.\n");
	printf("Second argument is either nothing or slow mode 'S'.\n");
	printf("In slow mode the numbers inside the parenthesis are registers (taps).\n");
    	printf("In slow mode the last number in every line is the output.\n");
	printf("Example: lfsr.exe 500 S \n");
	puts("/-------------/");
}

int main(int argc,char* argv[])
{
	//assert(argc>1);
    	usage();

	int i;
	int limit = atoi("16");
	//S 83 s 115
	if(argc==3)
		mode = *argv[2];
	for(i = 0; i < limit; i++)
		LFSR();

	puts("");
}