
#include "mcc_generated_files/system/system.h" 


const unsigned char coduri_hex[16] = {
    0x7E, // 0
    0x0A, // 1
    0xB6, // 2
    0x9E, // 3
    0xCA, // 4
    0xDC, // 5
    0xFC, // 6
    0x0E, // 7
    0xFE, // 8
    0xDE, // 9
    0xEE, // A
    0xF8, // b
    0x74, // C
    0xBA, // d
    0xF4, // E
    0xE4,  // F
};

int main(void)
{
    
    SYSTEM_Initialize(); 
    
   
    TRISDbits.TRISD4 = 1; 
    TRISDbits.TRISD1 = 1; 
    TRISDbits.TRISD2 = 1; 
    TRISDbits.TRISD3 = 1; 
    
   
    ANSELDbits.ANSD4 = 0;
    ANSELDbits.ANSD1 = 0;
    ANSELDbits.ANSD2 = 0;
    ANSELDbits.ANSD3 = 0;
    
    
    WPUDbits.WPUD4 = 1;
    WPUDbits.WPUD1 = 1;
    WPUDbits.WPUD2 = 1;
    WPUDbits.WPUD3 = 1;

    unsigned char b1, b2, b3, b4;
    unsigned char valoare_binara = 0;
    unsigned char masca_segmente = 0;
    int dummy = 0; 
    
   
    SPI1_Open(HOST_CONFIG); 

    while(1)
    {
        
        b1 = !PORTDbits.RD4; 
        b2 = !PORTDbits.RD1; 
        b3 = !PORTDbits.RD2; 
        b4 = !PORTDbits.RD3; 

  
        valoare_binara = (b1 << 3) | (b2 << 2) | (b3 << 1) | b4;

       
        masca_segmente = coduri_hex[valoare_binara];

      
        IO_RA3_SetLow();
        
        dummy = SPI1_ByteExchange(masca_segmente); 
        dummy = SPI1_ByteExchange(masca_segmente); 
        
        IO_RA3_SetHigh();

        __delay_ms(50); 
    }
    
    return 0;
}