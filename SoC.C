// Macro definition for bit setting 
#define Set(reg,bit) reg=(1<<bit)|reg 
// Macro definition for Bit Clear operation 
#define BIC(reg,bit) reg= reg&~(1<<bit) 
// Macro definition for checking the bit status whether set or not 
#define check(reg,bit)  (reg&(1<<bit)) 

int main(void)
{
    // Set PB1 in PORTB as output (for the third column of the keypad)
    DDRB &= ~(0b00000010);

    // Set the 7-segment pins as outputs
    DDRD |= 0b01111111;

    // Set the lower 4 bits of DDRC as output for the rows of the keypad (pull-up)
    DDRC |= 0x0F;

    // Enable internal pull-up resistor for PB1
    PORTB = 0b00000010;

    // Set the lower 7 bits of PORTC as high (pull-up)
    PORTC = 0b01111111;

while(1)
{
for (int i=0;i<4;i++) // Loop on the rows; this step is extra for better functionality.
{  
if(i==0)
{
       // Checking for button press on row A
       BIC(PORTC, PC0); // Set row A to low
       for(int j=0;j<5000;j++) // Delay for 5ms
       if (!check(PINC, PC4)) // Checking if button at column 1 is pressed
       {
           PORTD = 0x06; // Display '1' on the 7-segment
       }
       else if (!check(PINC, PC5)) // Checking if button at column 2 is pressed
       {
           PORTD = 0x5B; // Display '2' on the 7-segment
       }
       else if (!check(PINB, PB1)) // Checking if button at column 3 is pressed
       {
           PORTD = 0x4F; // Display '3' on the 7-segment
       }
       // Reset PORTC
       PORTC=0b01111111;
}

if(i==1)
{                  
        // Checking for button press on row B
        BIC(PORTC, PC1); // Set row B to low
        for(int j=0;j<5000;j++) // Delay 5ms
        if (!check(PINC, PC4)) // Checking if button at column 1 is pressed
        {
            PORTD = 0x66; // Display '4' on the 7-segment
        }
        else if (!check(PINC, PC5)) // Checking if button at column 2 is pressed
        {
            PORTD = 0x6D; // Display '5' on the 7-segment
        }
        else if (!check(PINB, PB1)) // Checking if button at column 3 is pressed
        {
            PORTD = 0x7D; // Display '6' on the 7-segment
        }

        // Reset PORTC
        PORTC = 0b01111111;
}
if(i==2)
{                  
        // Checking for button press on row C
        BIC(PORTC, PC2); // Set row C to low
        for(int j=0;j<5000;j++) // Delay 5ms
        if (!check(PINC, PC4)) // Checking if button at column 1 is pressed
        {
            PORTD = 0x07; // Display '7' on the 7-segment
        }
        else if (!check(PINC, PC5)) // Checking if button at column 2 is pressed
        {
            PORTD = 0xFF; // Display '8' on the 7-segment
        }
        else if (!check(PINB, PB1)) // Checking if button at column 3 is pressed
        {
            PORTD = 0x6F; // Display '9' on the 7-segment
        }

        //Reset PORTC
        PORTC=0b01111111;
}
if(i==3)
{                  
        // Checking for button press on row D
        BIC(PORTC,PC3); // Set row D to low
        for(int j=0;j<5000;j++) // Delay 5ms
        if(!check(PINC,PC4)) // Checking if button at column 1 is pressed
        {
           PORTD=0x00;  // Display nothing when star is pressed
        }
        else if(!check(PINC,PC5)) // Checking if button at column 2 is pressed
        {
           PORTD=0x3F; // Display '0' on the 7-segment
        }
        else if(!check(PINB,PB1)) // Checking if button at column 3 is pressed
        {
           PORTD=0x00; // Display nothing when hash is pressed
        } 
        //Reset PORTC
        PORTC=0b01111111;
}}}}