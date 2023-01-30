#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
//头文件区
#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include<assert.h>
#include<time.h>

//数据区
#define LENGTH 45//单词的长度
//#define MAX 1000

enum fun {
	EXIT,
	ADD,
	SEARCH,
	RECITE,
	SHOW,
	SAVE
};

typedef struct words 
{
	char word[LENGTH];
	char kana[LENGTH];
	char Chinese[LENGTH];
}words;         //单词的属性
typedef struct word_info
{
	words* sigle_word;
	int num;//记录目前已有的容量
	int cap;//记录目前最大的容量
}word_info;

//函数区
void menu0();
void LoadWordlist(word_info* ps);
void InitWord_list(word_info* ps);
void AddWords(word_info* ps);
void ShowWordlist(const word_info* ps);
void SearchWord(const word_info* ps);
void ReciteWords(const word_info* ps);
void Destroy(word_info* ps);
void SaveWordlist(word_info* ps);