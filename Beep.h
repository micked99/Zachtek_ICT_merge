/* 
 *  Beep functions and CW
 */

#define DIT_DURATION 50

void beep(int on, int off) {
  // freq = 14096950UL;
  // freq = 18105900UL;
     freq = 24926000UL;
  // freq = 28126015UL;
  
  Si5351a_Write_Reg (18, 128);  // Disable output CLK2
  if (use180deg) Si5351a_Write_Reg (17, 77); // Enable output CLK1 (180° dipole mode only)
  Si5351a_Write_Reg (16, 77);   // Enable output CLK0, set crystal as source and Integer Mode on PLLA
  SetFrequency(freq * 100UL);   // SetFrequency expects centi-Hz (Hz x100)
  delay(off);
  Si5351a_Write_Reg (16, 128);  // Disable output CLK0
  Si5351a_Write_Reg (17, 128);  // Disable output CLK1 (harmless no-op if it was never enabled)

  delay(on);
    
  wdt_reset();
}

void dit() { beep(DIT_DURATION, DIT_DURATION); }

void dah() { beep(DIT_DURATION * 3, DIT_DURATION); }

void sk() { delay(DIT_DURATION * 3 ); }

void cw_a() { dit(); dah();                sk();}
void cw_b() { dah(); dit(); dit(); dit();  sk();}
void cw_c() { dah(); dit(); dah(); dit();  sk();}
void cw_d() { dah(); dit(); dit();         sk();}
void cw_e() { dit();                       sk();}
void cw_f() { dit(); dit(); dah(); dit();  sk();}
void cw_g() { dah(); dah(); dit();         sk();}
void cw_h() { dit(); dit(); dit(); dit();  sk();}
void cw_i() { dit(); dit();                sk();}
void cw_j() { dit(); dah(); dah(); dah();  sk();}
void cw_k() { dah(); dit(); dah();         sk();}
void cw_l() { dit(); dah(); dit(); dit();  sk();}
void cw_m() { dah(); dah();                sk();}
void cw_n() { dah(); dit();                sk();}
void cw_o() { dah(); dah(); dah();         sk();}
void cw_p() { dit(); dah(); dah(); dit();  sk();}
void cw_q() { dah(); dah(); dit(); dah();  sk();}
void cw_r() { dit(); dah(); dit();         sk();}
void cw_s() { dit(); dit(); dit();         sk();}
void cw_t() { dah();                       sk();}
void cw_u() { dit(); dit(); dah();         sk();}
void cw_v() { dit(); dit(); dit(); dah();  sk();}
void cw_w() { dit(); dah(); dah();         sk();}
void cw_x() { dah(); dit(); dit(); dah();  sk();}
void cw_y() { dah(); dit(); dah(); dah();  sk();}
void cw_z() { dah(); dah(); dit(); dit();  sk();}

void cw_1() {dit(); dah(); dah(); dah(); dah(); sk();}
void cw_2() {dit(); dit(); dah(); dah(); dah(); sk();}
void cw_3() {dit(); dit(); dit(); dah(); dah(); sk();}
void cw_4() {dit(); dit(); dit(); dit(); dah(); sk();}
void cw_5() {dit(); dit(); dit(); dit(); dit(); sk();}
void cw_6() {dah(); dit(); dit(); dit(); dit(); sk();}
void cw_7() {dah(); dah(); dit(); dit(); dit(); sk();}
void cw_8() {dah(); dah(); dah(); dit(); dit(); sk();}
void cw_9() {dah(); dah(); dah(); dah(); dit(); sk();}
void cw_0() {dah(); dah(); dah(); dah(); dah(); sk();}
