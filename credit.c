#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

long int get_card_number(void);
char* get_card_type(long int, int);
int luhn_check(long int, int);
int main(void)
{
  long int card_number = get_card_number();
  int card_length = (int) floor(log10(labs(card_number))) + 1;

  char* card_type = get_card_type(card_number, card_length);

  if (strcmp(card_type, "INVALID") == 0)
  {
    printf("INVALID\n");
    return 0;
  }

  if (luhn_check(card_number, card_length))
  {
    printf("%s\n", card_type);
  }
  else
  {
    printf("INVALID\n");
  }
  return 0;
}

long int get_card_number(void)
{
  long int card_number;

  printf("card number: ");
  while ((scanf("%ld", &card_number) != 1))
    {
      printf("Please enter an integer\ncard number: ");
      scanf("%*[^\n]");
    }
  return card_number;
}


char* get_card_type(long int card_number, int card_length)
{
  int first_two = (card_number / (long int) pow (10, card_length-2));

  // All American Express numbers start with 34 or 37 and are 15 digits
  if (first_two == 34 || first_two == 37)
  {
    if (card_length != 15)
    {
      return "INVALID";
    }
    else
    {
      return "AMEX";
    }
  }
  // most MasterCard numbers start with 51, 52, 53, 54, or 55 and are 16 digits
  else if(first_two >= 51 && first_two <= 55)
  {
    if (card_length != 16)
    {
      return "INVALID";
    }
    else
    {
      return "MASTERCARD";
    }
  }
  // visa start with 4 and are 16 or 13 digits
  else if((first_two / 10) == 4)
  {
    if (card_length == 16 || card_length == 13)
    {
      return "VISA";
    }
    else
    {
      return "INVALID";
    }
  }
  else
  {
    return "INVALID";
  }
}

int first_sum(int, long int);
int second_sum(int, long int);
int luhn_check(long int card_number, int card_length)
{
  int f_sum = first_sum(card_length, card_number);
  int s_sum = second_sum(card_length, card_number);

  if((f_sum + s_sum) % 10 == 0)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

int first_sum(int card_length, long int card_number)
{
  int sum = 0;
  for(int i = 1; i < card_length; i += 2)
  {
    int long base = card_number / ((long int) pow(10, i));
    int target_int = base % 10 * 2;

    sum += target_int % 10;
    sum += target_int / 10;
  }
  return sum;
}

int second_sum(int card_length, long int card_number)
{
  int sum = 0;

  for(int i = 0; i < card_length; i += 2)
  {
    if (i == 0)
    {
      sum += card_number % 10;
    }
    else
    {
      long int base = card_number / ((long int) pow(10, i));
      sum += base % 10;
    }
  }
  return sum;
}
