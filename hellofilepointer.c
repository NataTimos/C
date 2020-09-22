#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(void) {

  char* hello = "Hello, world";

  FILE* file = fopen("hellofilepointer", "a"); //Відкриваємо файл

  if (file != NULL) //Якщо файл відкрито
  {
    for (int i =0, n = strlen(hello); i< n+1; i++)
    {
      fputc(hello[i], file); //Записуємо дані
    }

    fclose(file); //Закриваємо файл
  }
}
