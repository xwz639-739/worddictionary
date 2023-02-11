#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#define word_length 25
#define init_cap 3
#define add_cap 2

typedef struct word
{
	char character[word_length];
	char kana[word_length];
	char chinese[word_length];
}word;

typedef struct wordlist
{
	word* list;
	int size;//记录目前的单词数量
	int cap;//记录目前的单词表最大数量
}wordlist;

enum
{
	EXIT,
	ADD,
	SEARCH,
	DEL,
	SHOW,
	RECITE,
	SAVE
};

void menu1();
void InitList(wordlist* ps);
void AddWord(wordlist* ps);
void ShowList(wordlist* ps);
void SearchWord(wordlist* ps);
void DelWord(wordlist* ps);
void ReciteWord(wordlist* ps);
void SaveList(wordlist* ps);