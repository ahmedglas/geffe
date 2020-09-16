#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define IS_TAP_1(x)	((x==15)||(x==7)||(x==4)||(x==1)||(x==0))
#define IS_TAP_2(x)	((x==15)||(x==11)||(x==7)||(x==1)||(x==0))
#define IS_TAP_3(x)	((x==15)||(x==5)||(x==3)||(x==2)||(x==0))

static unsigned int mode =0 ;
static unsigned int ShiftRegister1  = 147;
static unsigned int ShiftRegister2  = 2179;
static unsigned int ShiftRegister3  = 45;
int limit = 0 ;
 int F[8] ;
 //= {1,0,0,0,1,1,1,0};
int tab [];
 int i = 0;

// fonction print le nombre en binaire  avec couleur 
void printBin(int C)
{
	int i = 0;
	for(i=4*sizeof(C)-1;i>=0;i--)
	{
      // if(IS_TAP(i) /*&& (i!=0)*/)
		//	 printf("(%d)",(C>>i)&1);
	//	else 
			 printf("%d",(C>>i)&1);
		
	}
	puts(" ");
}

// fonction print le nombre en binaire
void printOut(int C)
{
	printf("%d",(C>>0)&1);
	puts("");

}

// le programme 
void pgm()
{
   
    zabourou();
    LFSR1();
    LFSR2();
    LFSR3();


	
}

// fonction du registre L1  (décalage)
int LFSR1() {
	//static unsigned int ShiftRegister  = 147;
	//printBin(ShiftRegister);
	//zabourou(ShiftRegister);

	ShiftRegister1 = (((
				 (ShiftRegister1 >> 7)
				^ (ShiftRegister1 >> 4)
				^ (ShiftRegister1 >> 1)
				^ (ShiftRegister1 >> 0))
				& 0x00000001)
				<< 15)
			    | (ShiftRegister1 >> 1);

	
		return ShiftRegister1 & 0x00000001;
}
// fonction du registre L2 avec décalage 
int LFSR2() {
	
	//printBin(ShiftRegister);
	//zabourou(ShiftRegister);

	ShiftRegister2 = (((
				 (ShiftRegister2 >> 11)
				^ (ShiftRegister2 >> 7)
				^ (ShiftRegister2 >> 1)
				^ (ShiftRegister2 >> 0))
				& 0x00000001)
				<< 15)
			    | (ShiftRegister2 >> 1);

	
		return ShiftRegister2 & 0x00000001;
}
// fonction du registre L3  avec décalage 
int LFSR3() {
	
	//printBin(ShiftRegister);
	//zabourou(ShiftRegister);

	ShiftRegister3 = (((
				 (ShiftRegister3 >> 5)
				^ (ShiftRegister3 >> 3)
				^ (ShiftRegister3 >> 2)
				^ (ShiftRegister3 >> 0))
				& 0x00000001)
				<< 15)
			    | (ShiftRegister3 >> 1);

	
		return ShiftRegister3 & 0x00000001;
}
//fonction qui renvoi la suite chiffrante après test de x0x1x2 
void zabourou( )
{
    
    //printf("%d",((C >> 0) & 1));
    unsigned	int X0 = ((ShiftRegister1 >> 0) & 1);
    unsigned	int X1 = ((ShiftRegister2 >> 0) & 1);
    unsigned	int X2 = ((ShiftRegister3 >> 0) & 1);
    unsigned int res = X0 << 2 | X1 << 1 | X2;
    mode = mode << 1;
    if((X2==1) && (X1==1)&&(X0==1))
    { 
    mode += F[7] ;
    tab[i]=F[7];
    
    
        //strncat(str, &num, 1);
    } else if ((X2==0) && (X1==1) && (X0==1))
    {
    mode += F[3] ;
    
    tab[i]=F[3];
    
    
   
    } else if ((X2==1) && (X1==0) && (X0==1))
    { 
    mode += F[5] ; 
   
    tab[i]=F[5];
   
    
    } else if ((X2==0) && (X1==0) && (X0==1))
    {
    mode += F[1] ;
    
    tab[i]=F[1];
    
    
   
    } else if ((X2==1) && (X1==1) && (X0==0))
    {
    mode += F[6] ;
    
    tab[i]=F[6];
    
    
   
    }else if ((X2==0) && (X1==1) && (X0==0))
    {
    mode += F[2] ;
    
    tab[i]=F[2];
    
    
   
    }
    else if ((X2==1) && (X1==0) && (X0==0))
    {
    mode += F[4] ;
    
    tab[i]=F[4];
    
    
   
    }else if ((X2==0) && (X1==0) && (X0==0))
    {
    mode += F[0] ;
    
    tab[i]=F[0];
    
    
   
    }
    ++i;
   /* printf("hedhyel i %d",i);

    printBin(mode);
    puts(" ");*/
}

//fonction d'initialisation du nombre de bits a générer  et d' initialiser  fonction F 
void usage(){
	puts("/-------------/");
	printf(" how many random bits .\n");
	puts("/-------------/");
    scanf("%d",&limit);
 for( int k=0 ;k<8;k++)
   { printf("donnné F(%d)",k);
    scanf("%d",&F[k]);
   }
}

int main(int argc,char* argv[])
{
	
    usage();
        for(int j=0 ; j <limit;j++)
			{ 
			    pgm();
			}
            printf("suite chiffrante : \n");
		for(int j=limit ; j>=0 ; j--)
			{ //tab[j]=F[j];
			    printf("%d",tab[j]); // tableaux qui contient la suite chiffrante 
			}
		
			

	puts("");
}