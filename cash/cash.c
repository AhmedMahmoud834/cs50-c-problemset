#include <cs50.h>
#include <stdio.h>

int calc_quarters(int cents);
int calc_nickel(int cents);
int calc_dimes(int cents);


int main(void)
{
  int cents;
  do
  {
    cents = get_int("Change: ");
  }
  while(cents < 0);

  int quarters = calc_quarters(cents);
  cents -= quarters * 25;

  int nickel = calc_nickel(cents);
  cents -= nickel * 10;

  int dimes = calc_dimes(cents);
  cents -= dimes * 5;

  printf("Quarters: %i\n", quarters);
  printf("Dimes: %i\n", dimes);
  printf("Nickel: %i\n", nickel);
  printf("Pennies: %i\n", cents);
}

int calc_quarters(int cents)
{
  int count = 0;
  while(cents >= 25)
  {
    count += 1;
    cents -= 25;
  }
  return count;
}
int calc_nickel(int cents)
{
  int count = 0;
  while(cents >= 10)
  {
    count += 1;
    cents -= 10;
  }
  return count;
}
int calc_dimes(int cents)
{
  int count = 0;
  while(cents >= 5)
  {
    count += 1;
    cents -= 5;
  }
  return count;
}
