//
//  Books.h
//  jwrig_program5
//
//  Created by Jeremiah Wright on 10/30/14.
//  Copyright (c) 2014 Jeremiah Wright. All rights reserved.
//

#ifndef __jwrig_program5__Books__
#define __jwrig_program5__Books__

#include <stdio.h>

#endif /* defined(__jwrig_program5__Books__) */

#pragma once

#include <stdio.h>

typedef char* string;

// Constant Definition

#define ISBNLEN 6
#define TITLELEN 20
#define AUTHORLEN 20
#define MINPRICE 5.00
#define MAXPRICE 500.00
#define MINQUAN 0
#define MAXQUAN 100
#define BOOKCOUNT 8
#define MENUOPTCOUNT 6
typedef FILE* stream;
#define FILENAME "inventory.txt"



//#define MAXGRADE 100

// This enumeration type represents the
// numerical values of menu options
typedef enum MenuOptions { AddNewBook, EditBook,
    DeleteBook, InventoryList, Reports,
    Exit } mainm_t;

typedef enum SubMenuOptions {PriceRangeProducts,
    AuthorReport, SearchISBN,
    Back} submainm_t;
// Enumeration definition
typedef enum Genre { Education, Business, Novel } genre;



// String Array, initialization must
// be done in source code file
//const string genreArray[]= {"Education", "Business", "Novel"};


// User-defined type
typedef struct Book
{
    int         ISBN;
    char		Title[50];
    char		Author[30];
    float      price;
    int         Quantity;
    genre       genre_t;
} book_t;



// Displays the given book information on the screen
void printBooks(book_t* bo);

// Prompts the user to enter a new book's information
int scanBooks(book_t* bo);

void scanBookBK(stream in, book_t* Book);


void printBookBK(stream out, book_t* Book);

