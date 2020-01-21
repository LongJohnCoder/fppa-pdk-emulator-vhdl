__sfr __at(0x03) clkmd;
__sfr __at(0x04) inten;
__sfr __at(0x05) intrq;
__sfr __at(0x06) t16m;
__sfr __at(0x0b) ihrcr;
__sfr __at(0x0c) integs;     /* 12 */
__sfr __at(0x0d) padier;     /* 13 */
__sfr __at(0x0e) pbdier;     /* 14 */
__sfr __at(0x10) pa;         /* 16 */
__sfr __at(0x11) pac;        /* 17 */
__sfr __at(0x12) paph;       /* 18 */
__sfr __at(0x14) pb;         /* 20 */
__sfr __at(0x15) pbc;        /* 21 */
__sfr __at(0x16) pbph;       /* 22 */
__sfr __at(0x1c) tm2c;
__sfr __at(0x17) tm2s;
__sfr __at(0x09) tm2b;
__sfr16 t16cnt;


unsigned char _sdcc_external_startup(void)
{
    ihrcr = 0x81;
    clkmd = 0x30;
    return 0;
}

int main()
{
    pa = 0;
    pb = 0;
    pac = (1<<4); // PA4 as output

    tm2c = 0x1A; // PWM output on PA3, IHRC source, prescaler 1, scaler 0 (1)
    tm2b = 0x7F;
    tm2s = 0x0;

    while (1) {
        pa |= (1<<4);
        pa &= ~(1<<4);
    }
}
