#include <stdio.h>
#include "tokenizer.h"
#include "history.h"

int main()
{
   char str [80];

   List* list = init_history();
   char *word = "hello world";
   char **tokens = tokenize(word);

   int quit = 0;
   while(!quit) {
    printf("Tokenizer! Write anything. To look at all your history type !a for all, or !(number) for a specific history item, to Quit enter !q\n");
    fgets(str, 80, stdin);
    printf("%s\n",str);

    tokens = tokenize(str);
    printf("%s\n",tokens[0]);
    print_tokens(tokens);
    
    if (str[0] == '!') {
        if (str[1] == 'q') {
            return 0;
        }

	if (str[1] == 'a') {
	  print_history(list);
	}
	int num = 0;
        num = str[1] - 48;
        if (get_history(list, num) == NULL) {
            printf("History number not found\n");
        } else {	    
	  printf("Item %d: %s\n", num, get_history(list, num));
        }
    } else {
        add_history(list, str);
    }
   }

   return 0;
}
