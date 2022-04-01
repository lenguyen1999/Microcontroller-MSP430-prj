#include "msp430fg4618.h"
#include "intrinsics.h"


//---------------------ctrinh con dk motor buoc-----------------------------
void dkmoto(unsigned char key) {
	unsigned CODE[] = { 0x01,0x02,0x04,0x08 };
	unsigned char i, j = 0;
	for (i = key; i > 0; i--) {//quay so buoc bang gia tri cua key
		if (j == 4);//neu het chu ky thi
		j = 0;//nap lai gia tri 0x01
		P4OUT = CODE[j];
		__delay_cycles(500000);//delay 0,5s
		j++;
	}
	P4OUT = 0x00;//dung motor
}
//---------------------ctrinh chinh--------------------------------
void main() {
	WDTCTL = WDTPW + WDTHOLD;
	unsigned char key;
	P4DIR = 0xFF;//MOTOR BUOC
	P7DIR = 0x0F;//PHIM HEX KTRA CAC PHIM TREN TUNG COT _ _ _ 
	//                                                  1 2 3
	//                                                  4 5 6
	//                                                  7 8 9
	//                                                  A 0 B
	while (1)
	{
		//ktra cac phim o cot 1
		P7OUT = 0xfe; //1110
		if (!(P7IN & BIT4)) {//phim 1
			key = 1;
			goto dkmoto;
		}
		else if (!(P7IN & BIT5)) {//phim 4
			key = 4;
			goto dkmoto;
		}
		else if (!(P7IN & BIT6)) {//phim 7
			key = 7;
			goto dkmoto;
		}
		else if (!(P7IN & BIT7)) {//phim A
			key = 10;
			goto dkmoto;
		}
		//ktra cac phim o cot 2
		P7OUT=0xfd //1101
			//....
		P7OUT=0xfb//1011
			//...

			dkmotor:
		switch (key)
		{//neu key=x-->quay x buoc sau do gan key=0 de dung motor
			case 0: break;//neu key =0, ko quay
			case 1: {dkmoto(key); key = 0; break; }
			//case 2:.....
				  //...

		}


	}

}
