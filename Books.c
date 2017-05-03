//
//  Books.c
//  jwrig_program5
//
//  Created by Jeremiah Wright on 10/30/14.
//  Copyright (c) 2014 Jeremiah Wright. All rights reserved.
//

#include "Books.h"


// ----------------------------------------------------------------
// genreArray initialization should be done in source code file



const string genreArray[] = {"Education", "Business", "Novel"};






// ----------------------------------------------------------------
void printBooks(book_t* bo)
{
    printf("%11s: %d\n"	 ,  "ISBN",         bo->ISBN);
    printf("%11s: %s\n"	 ,	"Title",        bo->Title);
    printf("%11s: %s\n",	"Author",       bo->Author);
    printf("%11s: %.2f\n",	"Price",        bo->price);
    printf("%11s: %d\n",	"Quantity",     bo->Quantity);
    printf("%11s: %s\n"	 ,	"Genre"	,       genreArray[bo->genre_t]);
}

 
 // ----------------------------------------------------------------
int scanBooks(book_t* bo)
{
 int bookKeeper=0;
    
    for(;;){
    printf("Book ISBN: ");
        scanf("%d", &bo[bookKeeper].ISBN);
        if ( bo[bookKeeper].ISBN < ISBNLEN)
        {
            printf("ISBN is too long, try again!\n");
            continue; // jumping to the starting point of the loop
        }
    printf("Title: ");
        scanf("%s", bo[bookKeeper].Title);
        if (sizeof(bo[bookKeeper].Title) < TITLELEN)
        {
            printf("Title is too long, try again!\n");
            continue; // jumping to the starting point of the loop
        }
    printf("Author: ");
        scanf("%s", bo[bookKeeper].Author);
        if(sizeof(bo[bookKeeper].Author) < AUTHORLEN)
        {
        printf("Author is too long, try again!\n");
        continue; // jumping to the starting point of the loop
        }
    printf("Price: ");
        scanf("%f", &bo[bookKeeper].price);
        if (bo[bookKeeper].price < MINPRICE || bo[bookKeeper].price > MAXPRICE)
        {
            printf("Price is too high or too low, try again!\n");
            continue; // jumping to the starting point of the loop
        }
    printf("Quantity: ");
        scanf("%d", &bo[bookKeeper].Quantity);
        if (bo[bookKeeper].Quantity < MINQUAN || bo->Quantity > MAXQUAN)
        {
            printf("Quantity is not in range, try again!\n");
            continue; // jumping to the starting point of the loop
        }
        
    printf("Gender (0: Education, 1: Business, 2: Novel): ");
        scanf("%d", &bo[bookKeeper].genre_t);
        if (bo[bookKeeper].genre_t < Education || bo->genre_t > Novel)
        {
            printf("Invalid option, try again!\n");
            continue; // jumping to the starting point of the loop
        }
        break;
 
    }
    bookKeeper++;
    
    return bookKeeper;
}


void scanBookBK(stream in, book_t* Book)
{
    fscanf(in, "%d, %[^\n]\n, %[^\n]\n, %f, %d, %d", &Book->ISBN, Book->Title, Book->Author, &Book->price, &Book->Quantity, &Book->genre_t);
}


void printBookBK(stream out, book_t* Book)
{
    fprintf(out, "%d, %[^\n]\n, %[^\n]\n, %f, %d, %d", Book->ISBN, Book->Title, Book->Author, Book->price, Book->Quantity, Book->genre_t);
}
