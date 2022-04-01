
//CODE-MSP430-GPIO: UNG DUNG DIEU KHIEN 8 LED DON



#include "msp430g2553.h"

//ctrinh con

//chuong trinh con dieu khien 74hc595

void taoXungClock();
void taoXungChot();

void taoXungClock1();
void taoXungChot1();

//chuong trinh con dieu khien LED

void sangDanThuan();
void tatDanThuan();
void sangDanNghich();
void tatDanNghich();
void dichThuan1LED();
void dichThuan2LED();
void dichNghich1LED();
void dichNghich2LED();

//chuong trinh main

void main( void )
{
// Stop watchdog timer to prevent time out reset
WDTCTL = WDTPW + WDTHOLD;

P1DIR |= BIT0 + BIT1 + BIT2;//BIT0 , BIT1, BIT2 cua PORT1 la ngo ra dieu khien 74hc595.

while(1)
{

sangDanThuan();
tatDanThuan();
dichThuan1LED();
dichThuan2LED();
sangDanNghich();
tatDanNghich();
dichNghich1LED();
dichNghich2LED();
}
}

//cau truc cua cac chuong trinh con

//khoi tao chuc nang dieu khien 74hc595

/*xung dich thuan*/
//tao xung clock tac dong vao ic 74hc595
void taoXungClock()
{
//mo phong nen chon khoang thoi gian 4ms, thuc te chon 70ms
P1OUT |= 0x04;
__delay_cycles(2000);
P1OUT &=~ 0x04;
__delay_cycles(2000);
}
//tao xung chot tac dong vao ic 74hc595
void taoXungChot()
{
//mo phong nen chon khoang thoi gian 4ms, thuc te chon 70ms
P1OUT |= 0x02;
__delay_cycles(2000);
P1OUT &=~ 0x02;
__delay_cycles(2000);
}

/*xung dich nghich*/
//tao xung clock tac dong vao ic 74hc595
void taoXungClock1()
{
//mo phong nen chon khoang thoi gian 1ms, thuc te chon 15ms
P1OUT |= 0x04;
__delay_cycles(15000);
P1OUT &=~ 0x04;
__delay_cycles(15000);
}
//tao xung chot tac dong vao ic 74hc595
void taoXungChot1()
{
//mo phong nen chon khoang thoi gian 1ms, thuc te chon 15ms
P1OUT |= 0x02;
__delay_cycles(15000);
P1OUT &=~ 0x02;
__delay_cycles(15000);
}

/*---------------8 hieu ung cua 8 LED don-----------*/

//hieu ung 1: LED sang dan thuan
void sangDanThuan()
{
//LED on dan thuan
for(int i = 0; i <= 47; i++)
{
taoXungClock();//sau moi xung clock
P1OUT |= 0x01;//thi du lieu 1 se duoc dua vao IC 74hc595
taoXungChot();//sau moi xung "chot" thi du lieu 1 se duoc dua ra ngo ra cua IC 74hc595
}
}
//hieu ung 2: LED tat dan thuan
void tatDanThuan()
{
//LED off dan thuan
for(int i = 0; i <= 48; i++)
{
taoXungClock();//sau moi xung clock
P1OUT &=~ 0x01;//thi du lieu 0 se duoc dua vao IC 74hc595
taoXungChot();//sau moi xung "chot" thi du lieu 0 se duoc dua ra ngo ra cua IC 74hc595
}
}
//hieu ung 3: LED sang dan nghich
void sangDanNghich()
{
//LED on dan nguoc
for(int i = 0; i <= 47; i++)//moi lan thi xuat du lieu ra
{
for(int j = 0; j <= 48; j++)//sau 8 xung se xuat du lieu ra 74hc595
{
if(((i == 0) && (j == 0)) || ((i == 1) && ((j == 0) || (j == 1))) || ((i == 2) && ((j == 0) || (j == 1) || (j == 2))) || ((i == 3) && ((j == 0) || (j == 1) || (j == 2) || (j == 3))) || ((i == 4) && ((j == 0) || (j == 1) || (j == 2) || (j == 3) || (j == 4))) || ((i == 5) && ((j == 0) || (j == 1) || (j == 2) || (j == 3) || (j == 4) || (j == 5))) || ((i == 6) && ((j == 0) || (j == 1) || (j == 2) || (j == 3) || (j == 4) || (j == 5) || (j == 6))) || ((i == 7) && ((j == 0) || (j == 1) || (j == 2) || (j == 3) || (j == 4) || (j == 5) || (j == 6) || (j == 7))) )
{
taoXungClock1();
P1OUT |= 0x01;
}
else
{
taoXungClock1();
P1OUT &=~ 0x01;
}
}
taoXungChot1();
}
}
//hieu ung 4: LED tat dan nghich
void tatDanNghich()
{
//LED off dan nghich
for(int i = 0; i <= 47; i++)//xuat du lieu ra moi lan
{
for(int j = 0; j <= 48; j++)//sau 8 xung se xuat du lieu ra
{
if(((i == 0) && (j == 0)) || ((i == 1) && ((j == 0) || (j == 1))) || ((i == 2) && ((j == 0) || (j == 1) || (j == 2))) || ((i == 3) && ((j == 0) || (j == 1) || (j == 2) || (j == 3))) || ((i == 4) && ((j == 0) || (j == 1) || (j == 2) || (j == 3) || (j == 4))) || ((i == 5) && ((j == 0) || (j == 1) || (j == 2) || (j == 3) || (j == 4) || (j == 5))) || ((i == 6) && ((j == 0) || (j == 1) || (j == 2) || (j == 3) || (j == 4) || (j == 5) || (j == 6))) || ((i == 7) && ((j == 0) || (j == 1) || (j == 2) || (j == 3) || (j == 4) || (j == 5) || (j == 6) || (j == 7))&& ((j == 0) || (j == 1) || (j == 2) || (j == 3) || (j == 4) || (j == 5) || (j == 6) || (j == 7)||(j==8))
{
taoXungClock1();
P1OUT &=~ 0x01;
}
else
{
taoXungClock1();
P1OUT |= 0x01;
}
}
taoXungChot1();
}
P1OUT &=~ 0x01;
}
//hieu ung 5: dich thuan 1 LED
void dichThuan1LED()
{
//1 LED dich thuan
for(int i = 0; i <= 7; i++)
{
if((i == 0))//cho du lieu dau tien la 1
{
taoXungClock();
P1OUT |= 0x01;
taoXungChot();
}
else
{
taoXungClock();
P1OUT &=~ 0x01;
taoXungChot();
}

}
}
//hieu ung 6: dich thuan 2 LED
void dichThuan2LED()
{
//2 LED dich thuan
for(int i = 0; i <= 9; i++)
{
if((i == 0)||(i == 1))//cho 2 du lieu dau tien la 1
{
taoXungClock();
P1OUT |= 0x01;
taoXungChot();
}
else
{
taoXungClock();
P1OUT &=~ 0x01;
taoXungChot();
}
}
}
//hieu ung 7: dich nghich 1 LED
void dichNghich1LED()
{
//1 LED dich nguoc
for(int j = 0; j <= 7; j++)//xuat du lieu 8 lan
{
for(int i = 0; i <= 8; i++)// moi lan xuat chot de dua du lieu ra ngo ra
{
if(((j == 0)&&(i == 0)) || ((j == 1)&&(i == 1)) || ((j == 2)&&(i == 2)) || ((j == 3)&&(i == 3)) || ((j == 4)&&(i == 4)) || ((j == 5)&&(i == 5)) || ((j == 6)&&(i == 6)) || ((j == 7)&&(i == 7)))//xuat du lieu tu duoi->len
{
taoXungClock1();
P1OUT |= 0x01;
}
else
{
taoXungClock1();
P1OUT &=~ 0x01;
}
}
taoXungChot1();
}
}
//hieu ung 8: dich nghich 2 LED
void dichNghich2LED()
{
//2 LED dich nguoc
for(int j = 0; j <= 7; j++)//xuat du lieu 8 lan
{
for(int i = 0; i <= 8; i++)// moi lan xuat chot de dua du lieu ra ngo ra
{
if((((j == 0)&&(i == 0))||((j == 0)&&(i == 1))) || (((j == 1)&&(i == 1))||((j == 1)&&(i == 2))) || (((j == 2)&&(i == 2))||((j == 2)&&(i == 3))) || (((j == 3)&&(i == 3))||((j == 3)&&(i == 4))) || (((j == 4)&&(i == 4))||((j == 4)&&(i == 5))) || (((j == 5)&&(i == 5))||((j == 5)&&(i == 6))) || (((j == 6)&&(i == 6))||((j == 6)&&(i == 7))) || (((j == 7)&&(i == 7))||((j == 7)&&(i == 8))))//xuat du lieu tu duoi->len
{
taoXungClock1();
P1OUT |= 0x01;
}
else
{
taoXungClock1();
P1OUT &=~ 0x01;
}
}
taoXungChot1();
}
}