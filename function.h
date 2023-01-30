#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
//ͷ�ļ���
#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include<assert.h>
#include<time.h>

//������
#define LENGTH 45//���ʵĳ���
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
}words;         //���ʵ�����
typedef struct word_info
{
	words* sigle_word;
	int num;//��¼Ŀǰ���е�����
	int cap;//��¼Ŀǰ��������
}word_info;

//������
void menu0();
void LoadWordlist(word_info* ps);
void InitWord_list(word_info* ps);
void AddWords(word_info* ps);
void ShowWordlist(const word_info* ps);
void SearchWord(const word_info* ps);
void ReciteWords(const word_info* ps);
void Destroy(word_info* ps);
void SaveWordlist(word_info* ps);