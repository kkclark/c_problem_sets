#include<stdio.h>
#include<string.h>
#include<cs50.h>
#include <ctype.h>

const int MIN_UPPERCASE = 65; // A
const int MAX_UPPERCASE = 90; // Z
const int MIN_UNDERCASE = 97; // a
const int MAX_UNDERCASE = 122; // z
const int CASE_DIFFERENCE = MAX_UNDERCASE - MAX_UPPERCASE;

int validate_key(char*);
int index_of(char*, char);
int main(int argc, string argv[])
{
  if(argc != 2)
  {
    printf("Usage: ./substitution key\n");
    return 1;
  }

  // take a key as a command line argument
  string key = argv[1];

  if(validate_key(key) != 0)
  {
    return 1;
  }

  char ALPHA_UNDERS[] = "abcdefghijklmnopqrstuvwxyz";
  char ALPHA_UPPERS[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

  int index, alpha_index, plain_text_length;
  char plain;

  // get plain text from user and initialize a char array for cipher text
  string plain_text = get_string("plain text: ");
  plain_text_length = strlen(plain_text) + 1;

  char cipher_text[plain_text_length];

  for(index = 0; index < plain_text_length; index++)
  {
    plain = plain_text[index];

    // if plain text is a lower case character...
    if(plain >= MIN_UNDERCASE && plain <= MAX_UNDERCASE)
    {
      alpha_index = index_of(ALPHA_UNDERS, plain);
      cipher_text[index] = tolower(key[alpha_index]);
    }
    // if plain text is an upper case character...
    else if(plain >= MIN_UPPERCASE && plain <= MAX_UPPERCASE)
    {
      alpha_index = index_of(ALPHA_UPPERS, plain);
      cipher_text[index] = toupper(key[alpha_index]);
    }
    else
    {
      cipher_text[index] = plain;
    }
  }

  printf("ciphertext: ");
  for(index = 0; index < strlen(cipher_text); index++)
  {
    printf("%c", cipher_text[index]);
  }

  printf("\n");
  return 0;
}

// given a string find the first index what contains value char
int index_of(char* str, char chr)
{
  for(int i = 0; i < strlen(str); i++)
  {
    if(str[i] == chr)
    {
      return i;
    }
  }

  return 1;
}

int validate_key(char* str)
{
  int index;
  char character;
  char counter[26] = {0};
  int length = strlen(str);

  if(length != 26)
  {
    printf("Key must contain 26 characters.\n");
    return 1;
  }

  // if any non-alphabetical
  for(index = 0; index < length; index++)
  {
    character = str[index];
    if(!((character >= MIN_UNDERCASE && character <= MAX_UNDERCASE) || (character >= MIN_UPPERCASE && character <= MAX_UPPERCASE)))
    {
      printf("non-alphabetical character\n");
      return 1;
    }
    // downcase before counting
    // 'a' is 97 in ascii, this makes the counter start at 0
    counter[tolower(character) - 97]++;
  }

  // duplicate check. validated all characters are alphabetical and the length is 36
  for(index = 0; index < 26; index++)
  {
    if(counter[index] != 1)
    {
      printf("duplicate character\n");
      return 1;
    }
  }
  return 0;
}
