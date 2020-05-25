/*
ruizeZ
5/24/2020
Write a function
void written_amount( unsigned int amount, char *buffer );
that converts the value in amount to words and stores them in the buffer. This
function might be used in a program that prints checks. For example, if value is
16,312, then the string
SIXTEEN THOUSAND THRSE HUNDRED TWELVE
should be stored in the buffer. It is the callerȇs responsibility to make the buffer
large enough.
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_LEN 10000
void written_amount( unsigned int amount, char *buffer );
int main(void)
{
    unsigned int inpoutamount;
    char mainbuffer[MAX_LEN];
    printf("Enter the number: ");
    scanf("%d",&inpoutamount);
    written_amount(inpoutamount, mainbuffer);
    printf("%s\n",mainbuffer);
}
void written_amount(unsigned int amount, char *buffer)
{
    char *single_digits[] = { "", " one", " two",  
                               " three", " four"," five",  
                               " six", " seven", " eight", " nine"};
    char *two_digits[] = {"", " ten", " eleven", " twelve",  
                            " thirteen", " fourteen", 
                            " fifteen", " sixteen",  
                            " seventeen", " eighteen", " nineteen"}; 
    char *tens_multiple[] = {"", "", " twenty", " thirty", " forty", " fifty", 
                        " sixty", " seventy", " eighty", " ninety"}; 
  
    char *tens_power[] = {" hundred", " thousand", " million"}; 
    char amountstr[MAX_LEN];
    int numberposition = -1;
    int istwo_digits = 0;
    char tepmbuffer[MAX_LEN];
    sprintf(amountstr, "%d", amount);
    for (int i = strlen(amountstr); i>0; i--)
    {
        numberposition++;
        if (i == 7)
        {
            if (istwo_digits)
                {
                    strcat(tepmbuffer, two_digits[amountstr[numberposition] - '0'+1]);
                    strcat(tepmbuffer, tens_power[2]);
                    //printf("%s\n",tepmbuffer);
                    istwo_digits = 0;
                    continue;
                }
            strcat(tepmbuffer, single_digits[amountstr[numberposition] - '0']);
            if ((amountstr[numberposition]=='0')&&(amountstr[numberposition-1]=='0')&&((amountstr[numberposition-2]=='0')))
            {
                continue;
            }
            
            strcat(tepmbuffer, tens_power[2]);
            //printf("%s\n",tepmbuffer);
            continue;

        }
        if (i == 4) 
        {
            if (istwo_digits)
                {
                    strcat(tepmbuffer, two_digits[amountstr[numberposition] - '0'+1]);
                    strcat(tepmbuffer, tens_power[1]);
                    //printf("%s\n",tepmbuffer);
                    istwo_digits = 0;
                    continue;
                }
            strcat(tepmbuffer, single_digits[amountstr[numberposition] - '0']);
            if ((amountstr[numberposition]=='0')&&(amountstr[numberposition-1]=='0')&&((amountstr[numberposition-2]=='0')))
            {
                continue;
            }
            
            strcat(tepmbuffer, tens_power[1]);
            //printf("%s\n",tepmbuffer);
            continue;
        }
        
        if (i % 3 != 0)
        {
            if (i % 3 == 2)
            {
                if (amountstr[numberposition]!='1')
                {
                    strcat(tepmbuffer, tens_multiple[amountstr[numberposition] - '0']);
                }
                else if (amountstr[numberposition] == '1')
                {
                    istwo_digits = 1;
                }
            }
            if (i % 3 == 1)
            {
                if (istwo_digits)
                {
                    strcat(tepmbuffer, two_digits[amountstr[numberposition] - '0'+1]);
                    //printf("%s\n",tepmbuffer);
                }
                else
                {
                    strcat(tepmbuffer, single_digits[amountstr[numberposition] - '0']);
                    //printf("%s\n",tepmbuffer);
                }
            } 
        }
        if (i % 3 == 0)
        {
            strcat(tepmbuffer, single_digits[amountstr[numberposition] - '0']);
            if ((amountstr[numberposition]=='0'))
            {
                continue;
            }
            
            strcat(tepmbuffer, tens_power[0]);
            //printf("%s\n",tepmbuffer);
        }
        
    }
    strcpy(buffer, tepmbuffer + 1);
    //printf("%s\n",buffer);
}