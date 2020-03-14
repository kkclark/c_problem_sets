#include <stdio.h>

const int MIN_HEIGHT = 1;
const int MAX_HEIGHT = 8;

int get_height(void);
void print_padding(int height);
void print_row(int height);

int main(void)
{
  int height = get_height();

  for(int i = 1; i < height + 1; i++)
  {
    int padding = height - i;

    print_padding(padding);
    print_row(i);
    printf("  ");
    print_row(i);
    printf("\n");
  }
}

int get_height(void)
{
  int height;

  printf("Height: ");
  while ((scanf("%d", &height) != 1))
    {
      printf("Height: ");
      scanf("%*[^\n]");
    }

  while((height < MIN_HEIGHT || height > MAX_HEIGHT))
  {
    printf("Height: ");
    scanf("%d", &height);
  }

  return height;
}

void print_padding(int padding)
{
  for(int i = 0; i < padding; i++)
  {
    printf(" ");
  }
}

void print_row(int row_l)
{
  for(int i = 0; i < row_l; i++)
  {
    printf("#");
  }
}
