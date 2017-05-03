//
//  main.c
//  jwrig_program5
//
//  Created by Jeremiah Wright on 10/30/14.
//  Copyright (c) 2014 Jeremiah Wright. All rights reserved.
//

#include <stdio.h>
#include "Books.h"

const string mainm_opts[] = { "Add New Book", "Edit Book",
    "Delete Book", "Inventory List", "Reports"
    "Exit" };

const string submainm_opts[] = { "Price Range Products",
    "Author Reports", "Search ISBN", "Back"};

// This function displays the menu
void displayMenu();
void displaySubMenu();

// This function process the chosen menu
// option using a switch-case block
void processOption(mainm_t menuOption, stream out, book_t* bookArray);

void processSubOption(submainm_t submenuOption);


void addBook();

void editBook();

void deleteBook();

void inventoryList();

void reports(book_t* bookArray);

void exit();

int main()
{
    //int bookKeeper = 0;
    book_t bookArray[BOOKCOUNT];
    
    for(int k = 0; k<BOOKCOUNT; k++)
    {
        bookArray[k].ISBN=0;
    }
    
    mainm_t menuOption;
    for(;;)
    {
        displayMenu();
        scanf("%d", &menuOption);
        if (menuOption < AddNewBook || menuOption > Exit)
        {
            printf("Invalid option, try again!\n");
            continue; // jumping to the starting point of the loop
        }
        if (menuOption == Exit)
        {
            printf("See you next time\n");
            break;
        }
        processOption(menuOption, stdout, bookArray);
    }
    
    
    submainm_t submenuOption;
    for(;;)
    {
        reports(bookArray);
        scanf("%d", &submenuOption);
        if (submenuOption < PriceRangeProducts || submenuOption > Back)
        {
            printf("Invalid option, try again!\n");
            continue; // jumping to the starting point of the loop
        }
        if (submenuOption == Back)
        {
            printf("See you next time\n");
            break;
        }
      //  processSubOption(submenuOption);
    }
    
    stream out = fopen(FILENAME, "a");
    fclose(out);
    scanBooks(bookArray);

    return 0;
}

void displayMenu()
{
    int i = 0;
    printf("Main Menu\n========================\n");
    for (;i < Exit; i++)
    {
        printf("\t%d) %s\n", i, mainm_opts[i]);
    }
    printf("Please enter the option number: ");
}

void displaySubMenu()
{
    
}

void processOption(mainm_t menuOption, stream out, book_t* bookArray)
{
    switch (menuOption)
    {
        case AddNewBook:
            addBook(bookArray);
            break;
            
            
        case EditBook:
            editBook(bookArray);//book_t* bt, int bookKeeper);
            break;
            
        case DeleteBook:
            deleteBook(bookArray);
            break;
            
        case InventoryList:
            inventoryList(out, bookArray);
            break;
            
        case Reports:
            reports(bookArray);
            break;
            
        case Exit:
            exit(menuOption==Exit);
            break;
    }
}

void addBook(book_t* bookArray)
{
    int k=0;
    printf("\nEnter the new book information\n");
    printf("=================================\n");
    
    for(; k<BOOKCOUNT; k++)
    {
        if (bookArray[k].ISBN == 0)
            break;
        
    }
    
    scanBooks(&bookArray[k]);
    
    printf("\nNew Book\n");
    printf("===========\n");
    printBooks(&bookArray[k]);
    printf("=================================\n\n");
    stream out = fopen(FILENAME, "w");
    fclose(out);

}

void editBook(book_t* bt){
    
    int k=0;
    int isbn_n;
    
    printf("\nPlease enter the information for book to edit\n");
    printf("=================================\n");
    
    printf("Enter the ISBN number for book to search\n");
    scanf("%d", &isbn_n);
   
    
    for (; k<BOOKCOUNT; k++)
    {
        if(isbn_n == bt[k].ISBN)
        {
           scanBooks(&bt[k]);
            break;
        }
        
        
    }
    
    if(k==BOOKCOUNT)
    {
        printf("This Book does not exist");
    }
    
}


void deleteBook(book_t* bt){
    
    int k=0;
    int isbn_n;
    
    printf("\nEnter the ISBN for the book to delete\n");
    printf("=================================\n");
    
    printf("\nEnter ISBN for the book which you want to delete : ");
    scanf("%d", &isbn_n);
    
    
    for (; k<BOOKCOUNT; k++)
    {
        if(isbn_n == bt[k].ISBN)
        {
            bt[k].ISBN=0;
        }
        
    }

    
}

void inventoryList(stream out, book_t* bookArray){
 
    int k = 0;
    for (k = 0; k < BOOKCOUNT; k++)
    {
        if (bookArray[k].ISBN != 0)
        printBooks(&bookArray[k]);
    }
    
}

void reports(book_t* bookArray){
    
    int i = 0;
    int k = 0;
    int search;
    submainm_t submenuOption;
    int high;
    int low;
    printf("Main Menu\n========================\n");
    
    for (;i < Back; i++)
    {
        printf("\t%d) %s\n", i, submainm_opts[i]);
    }
    
    printf("Please enter the option number: ");
    scanf("%d", &submenuOption);
  
    
    switch (submenuOption)
    {
        case PriceRangeProducts:
            printf("Please enter a price range:");
            scanf("%d High:", &high);
            scanf("%d Low:", &low);
            for(; i<BOOKCOUNT; i++)
            if(bookArray[i].ISBN != 0 && (bookArray[i].price >= low || bookArray [i].price <= high))
            {
                 printBooks(&bookArray[i]);
            }
            break;
            
            
        case AuthorReport:
            
            break;
            
        case SearchISBN:
      printf("Please enter a price range:");
            scanf("%d", &search);
           for(; k<BOOKCOUNT; k++)
               if(bookArray[k].ISBN != 0 && (search=bookArray[k].ISBN));
                {
                    printBooks(&bookArray[k]);

                }
            break;
            
        case Back:
            displayMenu();
            break;
    }

    
    
}
