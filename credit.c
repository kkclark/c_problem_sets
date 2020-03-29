#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

const int MIN_CARD_LEN = 13;
const int MAX_CARD_LEN = 16;

long int get_card_number(void);
int get_card_length(long int);
char* get_card_type(long int, int);
int luhn_check(int);
int main(void)
{
  long int card_number = get_card_number();
  int card_length = get_card_length(card_number);

  // get card type ( card number ) -> str card_type
  char* card_type = get_card_type(card_number, card_length);

  if (strcmp(card_type, "INVALID") == 0)
  {
    printf("FROM CARD TYPE\n");
    printf("INVALID\n");
    return 0;
  }

  // luhn check (card_number) -> bool
  //if (luhn_check(card_number))
  if (1)
  {
    printf("%s\n", card_type);
  }
  else
  {
    printf("INVALID\n");
  }

  return 0;
}

int get_card_length(long int num)
{
  return (int) floor(log10(labs(num))) + 1;
}


int length_check(long int);
long int get_card_number(void)
{
  long int card_number;

  printf("card number: ");
  while ((scanf("%ld", &card_number) != 1))
    {
      printf("Please enter an integer\ncard number: ");
      scanf("%*[^\n]");
    }

  while(!length_check(card_number))
  {
    printf("valid lengths are between 13 and 16 digits\ncard number: ");
    scanf("%ld", &card_number);
  }

  return card_number;
}

int length_check(long int n)
{
  int l = get_card_length(n);

  if (l >= MIN_CARD_LEN && l <= MAX_CARD_LEN)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

int get_first_two(long int, int);
char* get_card_type(long int n, int l)
{
  int first_two = get_first_two(n, l);
  // All American Express numbers start with 34 or 37
  if (first_two == 34 || first_two == 37)
  {
    return "AMEX";
  }
  // most MasterCard numbers start with 51, 52, 53, 54, or 55 
  else if(first_two >= 51 && first_two <= 55)
  {
    return "MASTERCARD";
  }
  // visa start with 4
  else if((first_two / 10) == 4)
  {
    return "VISA";
  }
  else
  {
    return "INVALID";
  }
}

int get_first_two(long int n, int l)
{
  return (int) (n / (long int) pow (10, l-2));
}

int luhn_check(int n)
{
  // Multiply every other digit by 2, starting with the number’s second-to-last digit, and then add those products’ digits together.
  // Add the sum to the sum of the digits that weren’t multiplied by 2.
  // If the total’s last digit is 0 (or, put more formally, if the total modulo 10 is congruent to 0), the number is valid!


  return 1;
}
