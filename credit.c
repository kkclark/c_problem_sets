#include <stdio.h>
#include <string.h>

const int MIN_CARD_LEN = 13;
const int MAX_CARD_LEN = 16;

int get_card_number(void);
char* get_card_type(int);
int luhn_check(int);

int main(void)
{
  int card_number = get_card_number();

  // get card type ( card number ) -> str card_type
  char* card_type;
  card_type = get_card_type(card_number);

  if (strcmp(card_type, "INVALID") == 0)
  {
    printf("INVALID\n");
    return 0;
  }

  // luhn check (card_number) -> bool
  // return card type
  if (luhn_check(card_number))
  {
    printf("%s\n", card_type);
  }
  else
  {
    printf("INVALID\n");
  }

  return 0;
}

int get_card_number(void)
{
  int card_number;

  printf("card number: ");
  while ((scanf("%d", &card_number) != 1))
    {
      printf("Please enter an integer\n");
      scanf("%*[^\n]");
    }

  while(length_check(card_number))
  {
    printf("valid lengths are between 13 and 16 digits\n");
    scanf("%d", &card_number);
  }

  return card_number;
}
int length_check(int n)
{
  int l;
  for(int i = 0; i < l; i++)
  {
  }

  if (l < MIN_CARD_LEN || l > MAX_CARD_LEN)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

char* get_card_type(int n)
{
  // All American Express numbers start with 34 or 37
  if (n < 13)
  {
    return "AMEX";
  }
  // most MasterCard numbers start with 51, 52, 53, 54, or 55 
  else if(n < 14)
  {
    return "MASTERCARD";
  }
  // visa start with 4
  else if(n < 15)
  {
    return "VISA";
  }
  else
  {
    return "INVALID";
  }
}

int luhn_check(int n)
{
  // Multiply every other digit by 2, starting with the number’s second-to-last digit, and then add those products’ digits together.
  // Add the sum to the sum of the digits that weren’t multiplied by 2.
  // If the total’s last digit is 0 (or, put more formally, if the total modulo 10 is congruent to 0), the number is valid!
  return 1;
}
