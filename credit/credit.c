#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

void invalid(void);
int checkCardType(long cardNumber);
bool validNumber(long cardNumber);


int main(void)
{
  int type = 0;
  long cardNumber = get_long("Card Number: "); // 454546464646464
  // check length 15 -> amex | 16 -> mastercard | 16,13 -> visa
  // type 0 -> invalid | 1 -> amex | 2 -> mastercard | 3 -> visa
  type = checkCardType(cardNumber);
  if (type == 0)
  {
    invalid();
    return 1;
  }


  bool isValid = validNumber(cardNumber);

  if(!isValid)
  {
    invalid();
    return 1;
  }
  else
  {
    printf("Valid\n");
  }
  if(type == 1)
  {
    printf("AMEX\n");
  }
  else if(type == 2)
  {
    printf("MASTERCARD\n");
  }
  else if(type == 3)
  {
    printf("VISA\n");
  }
}

void invalid(void)
{
  printf("Invalid\n");
}


int checkCardType(long cardNumber)
{
    if((int)(cardNumber / 1000000000000L) == 34 || (int)(cardNumber / 10000000000000L) == 37 )
  {
    return 1;
  }
  else if((int)(cardNumber / 10000000000000L) >= 51 && (int)(cardNumber / 10000000000000L) <= 55)
  {
    return 2;
  }
  else if((int)(cardNumber / 100000000000000L) == 4 || (int)(cardNumber / 1000000000000000L) == 4)
  {
    return 3;
  }
  else
  {
    return 0;
  }
}

bool validNumber(long cardNumber)
{
  int pos = 0;
  int total = 0;
  while(cardNumber > 0)
  {
    if(pos % 2 == 0)
    {
      total += cardNumber % 10;
    }
    else if (pos % 2 == 1)
    {
      int tempNumber = (cardNumber % 10) * 2;
      if(tempNumber < 10)
      {
        total += tempNumber;
      }
      else
      {
        while(tempNumber != 0)
        {
          total += tempNumber % 10;
          tempNumber = tempNumber / 10;
        }
      }
    }
    pos++;
    cardNumber /= 10;
  }
  return total % 10 == 0;
}
