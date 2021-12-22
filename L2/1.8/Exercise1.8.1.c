/* Author: YiJia Chen */
#include <stdio.h>
#include <string.h>

struct Article
{
    int articleNumber;
    int quantity;
    char description[20];
};

/* Print members of Article.
This function gets the address of the structure as a parameter. */
void Print(struct Article *p)
{
    printf("%d\n%d\n%s\n",
    p -> articleNumber,
    p -> quantity,
    p -> description);
}

int main()
{
    // initialize an arbitary Article.
    struct Article article;
    article.articleNumber = 1;
    article.quantity = 2;
    strcpy(article.description, "description");

    Print(&article);
}