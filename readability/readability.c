#include <stdio.h>
#include <string.h>
#include <cs50.h>

const int MIN_UNDERCASE = 65; // a
const int MAX_UNDERCASE = 90; // z
const int MIN_UPPERCASE = 97; // A
const int MAX_UPPERCASE = 122; // Z

const int PERIOD = 46; // .
const int EXCLAMATION = 33; // Z
const int QUESTION_MARK = 63; // Z

int total_letters(char*);
int total_sentences(char*);
int total_words(char*);
int main(void)
{
  string usr_input = get_string("whats your flavor?\n");

  int grade = (0.0588 * total_letters(usr_input)) - (0.296 * total_sentences(usr_input)) - 15.8;

  if(grade > 16)
  {
    printf("ttl_letters: %i\n", total_letters(usr_input));
    printf("ttl_words: %i\n", total_words(usr_input));
    printf("ttl_sentences: %i\n", total_sentences(usr_input));
    printf("Grade: %i\n", grade);
    return 0;
  }
  else
  {
    printf("ttl_letters: %i\n", total_letters(usr_input));
    printf("ttl_words: %i\n", total_words(usr_input));
    printf("ttl_sentences: %i\n", total_sentences(usr_input));
    printf("Grade 16+");
    return 0;
  }
}

int total_letters(char* usr_input)
{
  int ttl = 0;

  //increment if letter is within asci range
  //A-Z = 65-90 inclusive
  //a-z = 97-122 inclusive
  for(int i = 0; i < strlen(usr_input); i++)
  {
    char character = usr_input[i];

    if((character >= MIN_UNDERCASE && character <= MAX_UNDERCASE) || (character >= MIN_UPPERCASE && character <= MAX_UPPERCASE))
    {
      printf("%c is a char\n", character);
      ttl++;
    }
    else if(character == 32)
    {
      printf("space\n");
    }
    else
    {
      printf("%c is not a char\n", character);
    }
  }

  return ttl;
}

int total_words(char* usr_input)
{
  int ttl = 0;

  for(int i = 0; i < strlen(usr_input); i++)
  {
    char character = usr_input[i];

    if(character == 32)
    {
      ttl++;
    }
  }

  // total spaces plus one
  return ttl + 1;
}

int total_sentences(char* usr_input)
{
  int ttl = 0;

  for(int i = 0; i < strlen(usr_input); i++)
  {
    char character = usr_input[i];

    if(character == PERIOD || character == QUESTION_MARK || character == EXCLAMATION)
    {
      ttl++;
    }
  }

  return ttl;
}
