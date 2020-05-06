#include <stdio.h>
#include <string.h>
// for string type and get_string()
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
  string usr_input = get_string("text:");

  int tls = total_letters(usr_input);
  int tws = total_words(usr_input);
  int tss = total_sentences(usr_input);

  // the average number of letters per 100 words in the text
  float avg_letters = tls / (float) tws * 100;

  // the average number of sentences per 100 words in the text
  float avg_sentences = tss / (float) tws * 100;

  // index = 0.0588 * L - 0.296 * S - 15.8
  float grade = 0.0588 * avg_letters - 0.296 * avg_sentences - 15.8;

  if(grade < 1)
  {
    printf("Before Grade 1\n");
  }
  else if (grade < 16)
  {
    printf("Grade %.f\n", grade);
  }
  else
  {
    printf("Grade 16+\n");
  }
}

int total_letters(char* usr_input)
{
  int total = 0;

  //increment if letter is within asci range
  //A-Z = 65-90 inclusive
  //a-z = 97-122 inclusive
  for(int i = 0; i < strlen(usr_input); i++)
  {
    char character = usr_input[i];

    if((character >= MIN_UNDERCASE && character <= MAX_UNDERCASE) || (character >= MIN_UPPERCASE && character <= MAX_UPPERCASE))
    {
      total++;
    }
  }
  return total;
}

int total_words(char* usr_input)
{
  int total = 0;

  for(int i = 0; i < strlen(usr_input); i++)
  {
    char character = usr_input[i];

    if(character == 32)
    {
      total++;
    }
  }
  // total spaces plus one
  return total + 1;
}

int total_sentences(char* usr_input)
{
  int total = 0;

  for(int i = 0; i < strlen(usr_input); i++)
  {
    char character = usr_input[i];

    if(character == PERIOD || character == QUESTION_MARK || character == EXCLAMATION)
    {
      total++;
    }
  }
  return total;
}
